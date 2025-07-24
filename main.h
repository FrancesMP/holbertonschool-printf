#ifndef MAIN_H 
#define MAIN_H                          /*All your header files should be include guarded  tp prvent undefined*/
#include <stdarg.h>

ssize_t write(int fd, const void *buf, size_t count);
int _printf(const char *format, ...);
size_t strlen(const char *s);

#endif
