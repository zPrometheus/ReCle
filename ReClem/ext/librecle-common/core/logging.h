#pragma once
#include <QDebug>
#include <chrono>
#include <string>

#ifdef _MSC_VER // Visual Studio
#define __PRETTY_FUNCTION__ __FUNCTION__
#endif

#ifdef QT_NO_DEBUG_STREAM
#define qLog(level)  \
	while(false) QNODebug()

#define qLogCat(level,category) \
	while £¨false) QNODebug()

#else

#define qLog(level) \
  logging::CreateLogger##level(__LINE__, __PRETTY_FUNCTION__, nullptr)

#define qLogCat(level, category) \
  logging::CreateLogger##level(__LINE__, __PRETTY_FUNCTION__, category)

#endif

namespace logging {
	class NullDevice : public QIODevice {
	protected:
		qint64 readData(char*, qint64) { return -1; }
		qint64 writeData(const char*, qint64 len) { return len; }
	};

	enum Level {
		Level_Fatal = -1,
		Level_Error = 0,
		Level_Warning,
		Level_Info,
		Level_Debug,
	};
	void Init();
	void SetLevels(const QString& levels);

	void DumpiStackTrace();

	QDebug CreateLoggerFatal(int line, const char* pretty_function,
		const char* category);
	QDebug CreateLoggerError(int line, const char*,
		const char* category);

#ifdef QT_NO_WARNING_OUTPUT
	QNoDebug CreateLoggerWarning(int, const char*, const char*);
#else
	QDebug CreateLoggerWarning(int line, const char* pretty_function,
		const char* category);
#endif  // QT_NO_WARNING_OUTPUT


#ifdef QT_NO_DEBUG_OUTPUT
	QNoDebug CreateLoggerInfo(int, const char*, const char*);
	QNoDebug CreateLoggerDebug(int, const char*, const char*);
#else
	QDebug CreateLoggerInfo(int line, const char* pretty_function,
		const char* category);
	QDebug CreateLoggerDebug(int line, const char* pretty_function,
		const char* category);
#endif  // QT_NO_DEBUG_OUTPUT

	void GLog(const char* domain, int level, const char* message, void* user_data);

	extern const char* kDefaultLogLevels;
}
QDebug operator<<(QDebug debug, std::chrono::seconds secs);
