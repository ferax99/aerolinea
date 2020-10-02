#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <setjmp.h>
#include "hpdf.h"
jmp_buf env;

#ifndef __GRID_SHEET_H
#define __GRID_SHEET_H

void print_grid  (HPDF_Doc pdf, HPDF_Page page);
void error_handler (HPDF_STATUS   error_no, HPDF_STATUS   detail_no, void *user_data);
void show_desciption(HPDF_Page page, HPDF_REAL x, HPDF_REAL y, const char *text);
int crear_doc();
void borrar(char *str);
void consultar(char * str);
void submenu_op();
void submenu_gen();
void registro();