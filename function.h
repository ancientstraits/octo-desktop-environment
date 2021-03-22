#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <stddef.h>
char* concat(const char *s1, const char *s2);
extern void substr(char *buffer, size_t buflen, char const *source, int len);
#endif