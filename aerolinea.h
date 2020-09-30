#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <setjmp.h>
#include "hpdf.h"
#include "grid_sheet.h"

jmp_buf env;

void show_desciption(HPDF_Page page, HPDF_REAL x, HPDF_REAL y, const char *text);
int crear_doc();
void borrar(char *str);
void consultar(char * str);
