#include <stdio.h>
#include <time.h>

extern FILE *logFile;
extern time_t currentTime;
extern struct tm tm;

void append_to_log(char *text, bool includeTime)
{
    if (includeTime)
    {
        currentTime = time(NULL);
        tm = *localtime(&currentTime);
        fprintf(logFile, "%s: %d-%02d-%02d %02d:%02d:%02d\n", text, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        return;
    }

    fprintf(logFile, "%s\n", text);
    return;

}
