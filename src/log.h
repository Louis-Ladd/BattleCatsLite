#ifndef LOG_H_
#define LOG_H_

#define TRACE_LOG(context, fmt, ...)                                           \
	printf("\033[1;31m[%s]\033[0m[%s:%d][%s()] " fmt "\n", context, __FILE__,  \
		   __LINE__, __func__, ##__VA_ARGS__)

#define BASE_LOG(context, fmt, ...)                                            \
	printf("\033[1;31m[%s]\033[0m " fmt "\n", context, ##__VA_ARGS__)

#define LOG(fmt, ...) BASE_LOG("LOG", fmt, ##__VA_ARGS__)

#ifdef DEBUG
#define LOG_DEBUG(fmt, ...) TRACE_LOG("DEBUG", fmt, ##__VA_ARGS__)
#else
#define LOG_DEBUG(fmt, ...)
#endif

#define LOG_WARN(fmt, ...) BASE_LOG("WARN", fmt, ##__VA_ARGS__)

#define LOG_ERROR(fmt, ...) TRACE_LOG("ERROR", fmt, ##__VA_ARGS__)

#endif
