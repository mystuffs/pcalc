
/* =====[ xxx.c ]=========================================================

   Description:

   Compiled:        MS-C.

   Compiler opt:    ??

   Revisions:

      REV     DATE     BY           DESCRIPTION
      ----  --------  ----------    --------------------------------------
      0.00  xx.xx.94  Peter Glen    Initial version.

   ======================================================================= */

/* -------- System includes:  -------------------------------------------- */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
//include <dos.h>
#include <time.h>
#include <string.h>

/* -------- Includes:  --------------------------------------------------- */

#include "hocdecl.h"
#include "symbol.h"
#include "str.h"

/* -------- Strings: ----------------------------------------------------- */

static char    work_str[2000];

/* -------- Implementation: ---------------------------------------------- */

int     print(long double ee)

{
    printf("val\t%-8.8Lg\t0x%-8llx\n", ee, (long long)ee);
    return(0);
}

int echo(const char *str)
{
    echo_nl(str);
    printf("\n");
    return(0);
}

int echo_nl(const char *str)
{
    if(str)
        {
        str_esc(str, work_str, sizeof(work_str));
        printf("%s", work_str);

        //printf("%s\n", str);
        }
    return(0);
}

int ddate(const char *str)
{
    struct tm *loc_time;
    time_t lt;
    char string[128];

    lt = time(NULL);

    str_esc(str, work_str, sizeof(work_str));
    loc_time = localtime(&lt);
    strftime(string, sizeof(string), work_str, loc_time);

    printf("%s", string);

    return(0);
}
