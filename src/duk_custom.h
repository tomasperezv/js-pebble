// Do not use file IO, as it's not supported in Pebble.
#undef DUK_USE_FILE_IO

// Remove all time methods.
#undef DUK_USE_DATE_TZO_GMTIME
#undef DUK_USE_DATE_TZO_GMTIME_R
#undef DUK_USE_DATE_NOW_GETTIMEOFDAY
#undef DUK_USE_DATE_PRS_STRPTIME
#undef DUK_USE_DATE_FMT_STRFTIME

// This macros should return the actual time, and the timezone offset.
#define DUK_USE_DATE_GET_NOW(x)             (0)
#define DUK_USE_DATE_GET_LOCAL_TZOFFSET(x)  (0)

// Remove bad definitions.
#undef  DUK_SPRINTF
#undef  DUK_SNPRINTF
#undef  DUK_VSNPRINTF

// Reimplement them (TODO: most of them are wrong).
#define DUK_SPRINTF    my_sprintf
#define DUK_SNPRINTF   snprintf
#define DUK_VSNPRINTF  snprintf


int my_sprintf(char *output, char *format, ...) {
    va_list args;
    int len;

    va_start(args, format);
    len = snprintf(output, 64, format, args);
    va_end(args);

    return len;
}
