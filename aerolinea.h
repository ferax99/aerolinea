#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <setjmp.h>
#include "hpdf.h"
jmp_buf env;

/*struct tags{
	char tags[10][40];

}etiq;

struct etiq tag;
etiq.tag[0] = "Identificador";
tag[1] = "Fecha Y Hora de Reservacion";
tag[2] = "Informacion de la Aerolinea";
tag[3] = "Codigo de Vuelo";
tag[4] = "Lugar y Fecha de salida";
tag[5] = "Lugar y Fecha de arribo";
tag[6] = "Numero de asientos de la reservacion";
tag[7] = "Personas de la reservacion"; 
tag[8] = "Monto de la reservacion";*/




void submenu_op();
void submenu_gen();
void registro();
char * fecha();
void print_grid  (HPDF_Doc pdf, HPDF_Page page);
void error_handler (HPDF_STATUS   error_no, HPDF_STATUS   detail_no, void *user_data);
void show_desciption(HPDF_Page page, HPDF_REAL x, HPDF_REAL y, const char *text);
int crear_doc();
void valida_asiento(int fila, int columna, int cantidad, char * codigo_vuelo);
void insertar_reserva(char * codigo_vuelo);
char * consultar_doc(int seleccion, char * codigo);
char * tipo_asiento(int fila, int columna);
void eliminar_r(char *codigo);
void imprime_asientos(char * codigo_vuelo);
int edad(char * palabra);
int guarda_asiento(int cantidad, char * codigo_vuelo);
void alterar(char *str);
char * get_dato(char * str);
void consultar_r(char * codigo);
char * consultar(char * str);
void estadisticas();
void estado_vuelo();
int insertar_personas();
void submenu_avion();
int borrar_avion();
void agregar_avion();
int editar_Avion();
void consultar_avion();
//Si se quiere con cuadriculado
//gcc $(mysql_config --cflags) conexion.c aerolinea.c operativos.c generales.c crear_pdf.c grid_sheet.c $(mysql_config --libs) -lhpdf -lpng -lz -lm -o prueba
//Si no
//gcc $(mysql_config --cflags) conexion.c aerolinea.c operativos.c generales.c crear_pdf.c $(mysql_config --libs) -lhpdf -lpng -lz -lm -o prueba
//arc_demo.c no es necesario