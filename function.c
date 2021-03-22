#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

char* concat(const char *s1, const char *s2){
	if (s1 == NULL){
		abort();
	} else if (s2 == NULL) {
		abort();
	} else {
		char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
		strcpy(result, s1);
		strcat(result, s2);
		return result;
	}
}



/*
** Given substr(buffer, sizeof(buffer), "string", len), then the output
** in buffer for different values of len is:
** For positive values of len:
** 0    ""
** 1    "s"
** 2    "st"
** ...
** 6    "string"
** 7    "string"
** ...
** For negative values of len:
** -1   "g"
** -2   "ng"
** ...
** -6   "string"
** -7   "string"
** ...
** Subject to buffer being long enough.
** If buffer is too short, the empty string is set (unless buflen is 0,
** in which case, everything is left untouched).
*/
void substr(char *buffer, size_t buflen, char const *source, int len)
{
    size_t srclen = strlen(source);
    size_t nbytes = 0;
    size_t offset = 0;
    size_t sublen;

    if (buflen == 0)    /* Can't write anything anywhere */
        return;
    if (len > 0)
    {
        sublen = len;
        nbytes = (sublen > srclen) ? srclen : sublen;
        offset = 0;
    }
    else if (len < 0)
    {
        sublen = -len;
        nbytes = (sublen > srclen) ? srclen : sublen;
        offset = srclen - nbytes;
    }
    if (nbytes >= buflen)
        nbytes = 0;
    if (nbytes > 0)
        memmove(buffer, source + offset, nbytes);
    buffer[nbytes] = '\0';
}
