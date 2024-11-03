#ifndef LOG_H_
#define LOG_H_

#define LOG(fmt, ...)                                                          \
    printf("\033[1;31m[DEBUG]\033[0m[%s:%d][%s()] " fmt "\n", __FILE__,        \
           __LINE__, __func__, ##__VA_ARGS__)

#endif
