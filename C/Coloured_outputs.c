#include "Color_outputs.h"
//https://stackoverflow.com/questions/20639632/how-to-wrap-printf-into-a-function-or-macro
// memcpy(rd,"\033[0;31m",fmt,"\033[0m");
 
void printf_red( char *fmt, ...) {
    va_list args;
    char *af = "\033[0m";
    char *bf = "\033[0;31m";
    int sizeaf= strlen(af);
    int sizebf =strlen(bf);
    int sizefmt =strlen(fmt);
    char * rd =(char*) malloc(sizeaf+sizebf+sizefmt+1) ;
    memcpy( rd,bf, sizebf );
    memcpy( rd+sizebf,fmt,sizefmt);
    memcpy( rd+sizebf+sizefmt,af,sizeaf);
    rd[sizeaf+sizebf+sizefmt] = '\0';
    va_start(args, fmt);
    vprintf(rd, args);
    va_end(args);
    free(rd);
}


