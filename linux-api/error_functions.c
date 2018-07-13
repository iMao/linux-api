#include <stdarg.h>
#include "error_functions.h"
#include "ename.h"


static void outputError(Boolean useErr, int err, Boolean flushStdout, const char* format, va_list ap)
{
#define BUF_SIZE 500
    char buf[BUF_SIZE];
    char userMsg[BUF_SIZE];
    char errText[BUF_SIZE];

    vsnprintf(userMsg, BUF_SIZE, format, ap);

    if(useErr)
      snprintf(errText, BUF_SIZE, " [%s %s]", (err > 0 && err <= MAX_ENAME)? ename[err] : "?UNKNOWN?", strerror(err));
    else
        snprintf(errText, BUF_SIZE, ":");


    snprintf(buf,BUF_SIZE, "ERROR %s %s\n", errText, userMsg);

    if(flushStdout)
        fflush(stdout);

    fputs(buf,stderr);
    fflush(stderr);
}




void errMsg(const char* format,...)
{
    va_list arg_list;
    int saved_errno = errno;                                //сохраняем код ошибки

    va_start(arg_list,format);
    outputError(TRUE, errno, TRUE, format, arg_list);       //вывод сообщения об ошибке с описанием
    va_end(arg_list);

    errno = saved_errno;                                    //восстанавливаем код ошибки
}
