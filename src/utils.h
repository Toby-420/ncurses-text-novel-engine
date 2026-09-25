/*
    Append some text to the opened log file.
    takes a string to append, and a bool
    stating whether system time is to be
    included. If time is to be included,
    it is recommended that text is at most
    a short phrase.
*/
void append_to_log(char *text, bool includeTime);
