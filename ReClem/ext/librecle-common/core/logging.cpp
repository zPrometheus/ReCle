#include "logging.h"
// <string.h>
#include <QtGlobal>


//#include <cxxabi.h>
#ifdef Q_OS_UNIX
#include <execinfo.h>
#endif

#include <iostream>
#include <memory>

#include <QBuffer>
#include <QCoreApplication>
#include <QDateTime>
#include <QStringList>
#include <QtMessageHandler>
#include <QTextStream>

#include <glib.h>

namespace logging {
	static Level sDefaultLevel = Level_Debug;
	static QMap<QString, Level>* sClassLevels = nullptr;
	static QIODevice* sNullDevice = nullptr;

	const char* kDefaultLogLevels =
		"GstEnginePipelineCallbacks:2,"
		"NetworkRequests:2,"
		"*:3";
	static const char* kMessageHandlerMagic = "__logging_message__";
	static const int kMessageHandlerLength = strlen(kMessageHandlerMagic);
	static QtMessageHandler sOriginalMessageHandler = nullptr;

	template <class T>
	static T CreateLogger(Level level, const QString& class_name, int line,
		const char* category);

	void GLog(const char* domain, int level, const char* message, void* user_data) {
		switch (level) {
		case G_LOG_FLAG_RECURSION:
		case G_LOG_FLAG_FATAL:
		case G_LOG_LEVEL_ERROR:
		case G_LOG_LEVEL_CRITICAL:
			qLogCat(Error, domain) << message;
			break;
		case G_LOG_LEVEL_WARNING:
			qLogCat(Warning, domain) << message;
			break;
		case G_LOG_LEVEL_MESSAGE:
		case G_LOG_LEVEL_INFO:
			qLogCat(Info, domain) << message;
			break;
		case G_LOG_LEVEL_DEBUG:
		default:
			qLogCat(Debug, domain) << message;
			break;
		}
	}

	template <class T>
	static T CreateLogger(Level level, const QString& class_name, int line,
		const char* category) {
		// Map the level to a string
		const char* level_name = nullptr;
		switch (level) {
		case Level_Debug:
			level_name = " DEBUG ";
			break;
		case Level_Info:
			level_name = " INFO  ";
			break;
		case Level_Warning:
			level_name = " WARN  ";
			break;
		case Level_Error:
			level_name = " ERROR ";
			break;
		case Level_Fatal:
			level_name = " FATAL ";
			break;
		}

		QString filter_category = (category != nullptr) ? category : class_name;
		// Check the settings to see if we're meant to show or hide this message.
		Level threshold_level = sDefaultLevel;
		if (sClassLevels && sClassLevels->contains(filter_category)) {
			threshold_level = sClassLevels->value(filter_category);
		}

		if (level > threshold_level) {
			return T();
		}

		QString function_line = class_name;
		if (line != -1) {
			function_line += ":" + QString::number(line);
		}
		if (category) {
			function_line += "(" + QString(category) + ")";
		}

		QtMsgType type = QtDebugMsg;
		if (level == Level_Fatal) {
			type = QtFatalMsg;
		}

		T ret(type);
		ret.nospace() << QDateTime::currentDateTime()
			.toString("hh:mm:ss.zzz")
			.toLatin1()
			.constData()
			<< level_name
			<< function_line.leftJustified(32).toLatin1().constData();

		return ret.space();
	}

	static QString ParsePrettyFunction(const char* pretty_function) {
		// Get the class name out of the function name.
		QString class_name = pretty_function;
		const int paren = class_name.indexOf('(');
		if (paren != -1) {
			const int colons = class_name.lastIndexOf("::", paren);
			if (colons != -1) {
				class_name = class_name.left(colons);
			}
			else {
				class_name = class_name.left(paren);
			}
		}

		const int space = class_name.lastIndexOf(' ');
		if (space != -1) {
			class_name = class_name.mid(space + 1);
		}

		return class_name;
	}


	template <class T>
	class DebugBase : public QDebug {
	public:
		DebugBase() : QDebug(sNullDevice) {}
		DebugBase(QtMsgType t) : QDebug(t) {}
		T& space() { return static_cast<T&>(QDebug::space()); }
		T& noSpace() { return static_cast<T&>(QDebug::nospace()); }
	};


	// Debug message will be logged immediately.
	class LoggedDebug : public DebugBase<LoggedDebug> {
	public:
		LoggedDebug() : DebugBase() {}
		LoggedDebug(QtMsgType t) : DebugBase(t) { nospace() << kMessageHandlerMagic; }
	};
	// These are the functions that create loggers for the rest of Clementine.
	// It's okay that the LoggedDebug instance is copied to a QDebug in these. It
	// doesn't override any behavior that should be needed after return.
#define qCreateLogger(line, pretty_function, category, level)                \
  logging::CreateLogger<LoggedDebug>(                                        \
      logging::Level_##level, logging::ParsePrettyFunction(pretty_function), \
      line, category)

	QDebug CreateLoggerFatal(int line, const char* pretty_function,
		const char* category) {
		return qCreateLogger(line, pretty_function, category, Fatal);
	}
	QDebug CreateLoggerError(int line, const char* pretty_function,
		const char* category) {
		return qCreateLogger(line, pretty_function, category, Error);
	}

#ifdef QT_NO_WARNING_OUTPUT
	QNoDebug CreateLoggerWarning(int, const char*, const char*) {
		return QNoDebug();
	}
#else
	QDebug CreateLoggerWarning(int line, const char* pretty_function,
		const char* category) {
		return qCreateLogger(line, pretty_function, category, Warning);
	}
#endif  // QT_NO_WARNING_OUTPUT

#ifdef QT_NO_DEBUG_OUTPUT
	QNoDebug CreateLoggerInfo(int, const char*, const char*) { return QNoDebug(); }
	QNoDebug CreateLoggerDebug(int, const char*, const char*) { return QNoDebug(); }
#else
	QDebug CreateLoggerInfo(int line, const char* pretty_function,
		const char* category) {
		return qCreateLogger(line, pretty_function, category, Info);
	}
	QDebug CreateLoggerDebug(int line, const char* pretty_function,
		const char* category) {
		return qCreateLogger(line, pretty_function, category, Debug);
	}
#endif  // QT_NO_DEBUG_OUTPUT

}

