#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <setjmp.h>
#include "hpdf.h"
jmp_buf env;
/*
Archivo header donde se inicializan todas las funciones
*/
typedef struct Avion{
	char *matricula;	
	char * modelo ;
	char *anno ;
}Avion;

typedef struct Codigo{
	char *codigo;	
}Codigo;

void submenu_op();
void submenu_gen();
void registro();
char * fecha();
void print_grid  (HPDF_Doc pdf, HPDF_Page page);
void error_handler (HPDF_STATUS   error_no, HPDF_STATUS   detail_no, void *user_data);
void show_desciption(HPDF_Page page, HPDF_REAL x, HPDF_REAL y, const char *text);
int crear_doc(char * codigo);
void valida_asiento(int fila, int columna, int cantidad, char * codigo_vuelo);
void reservar();
char * consultar_doc(int seleccion, char * codigo);
char * tipo_asiento(int fila, int columna);
void eliminar_r();
void imprime_asientos(char * codigo_vuelo);
char * consultar_p(char * str);
int edad(char * palabra);
void guarda_asiento(int cantidad, char * codigo_vuelo);
void alterar(char *str);
char ** get_columna(char * str);
char * verifica_p(char *pasaportes, int cantidad);
char * fecha_pas(char pasaporte[]);
char * get_dato(char * str);
void cambia_dis(char tipo, int fila, int columna, int proc);
char * insertar_reserva(char pasaportes[30][100], int tam);
int determina_c(int cantidad, char pasaportes[30][100], int tam);
char * obtenerId(char pasaporte[]);
void consultar_r();
char * consultar(char * str);
char * obtenerId_R();
char *genera_codigo(int tam);
void estadisticas();
void estado_vuelo();
int insertar_personas();
void submenu_avion();
int borrar_avion();
void agregar_avion();
int editar_Avion();
void consultar_avion();
//Comando de Compilacion segun se requiera
//Si se quiere con cuadriculado
//gcc $(mysql_config --cflags) conexion.c aerolinea.c operativos.c generales.c crear_pdf.c grid_sheet.c $(mysql_config --libs) -lhpdf -lpng -lz -lm -o prueba
//Si no
//gcc $(mysql_config --cflags) conexion.c aerolinea.c operativos.c generales.c crear_pdf.c $(mysql_config --libs) -lhpdf -lpng -lz -lm -o prueba
//arc_demo.c no es necesario