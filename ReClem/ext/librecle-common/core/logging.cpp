#include "logging.h"
// <string.h>
#include <QtGlobal>


#include <cxxabi.h>
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
	static QIODevice* sNnllDevice = nullptr;

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


}