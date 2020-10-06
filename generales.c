#include "aerolinea.h"
/*
Submenu de funciones generales, se puede llamar a reservar, consultar reserva y eliminar reserva(modificacion directa a la base)
E:Void
S:Void
*/
void submenu_gen(){
    int camb;
    char linea[256];    
	do {
		system("clear");
		printf("--------Opciones Generales--------\n");
		printf("1 - Reservacion de Vuelo\n");
		printf("2 - Consultar Reservas\n");
		printf("3 - Eliminar Reservas\n");
		printf("4 - Regresar\n");
		printf("Elija una opcion: ");
		fgets(linea,sizeof(linea),stdin);
		sscanf(linea,"%i",&camb);
		fflush(stdin);
		switch(camb) {
			case 1: 
				system("clear");
				printf("\n");
				printf("Reservar\n");
				reservar();
				printf("\n");
				break;
			case 2: 
				system("clear");
				printf("\n");
				consultar_r();
				getchar();
				getchar();
				break;
			case 3: 
			    system("clear");
				printf("\n");
				printf("Se eliminara la reserva\n");
				eliminar_r();
				getchar();
				getchar();
				printf("\n");
				break;
			case 4:
			    break;
			    
			default:
				printf("Error\n");
		}
	} while(camb != 4) ;
}
/*
Funcion que se encarga de separar los pasaportes y guardarlos en un arreglo
E: char *pasaportes, input del usuario donde se pusieron todos los pasaportes. 
int cantidad, el cual es la cantidad de asientos que va a tener disponible para reservar(la funcion inical se llama con 0).
S: Void
*/
char * verifica_p(char *pasaportes, int cantidad){
	char guarda_p[100];
	char linea[256];
	Codigo c;
	char pasap[30][100];
	char * codigo;
	int tam = 0;
	strcpy(guarda_p,pasaportes);
	char * pas = strtok(guarda_p,",");
	while( pas != NULL ) {
		strcpy(pasap[tam], pas);
		pas = strtok(NULL, ",");    
		tam++; 
    } 
    cantidad = determina_c(cantidad, pasap,tam);
    codigo = insertar_reserva(pasap,tam);
    c.codigo = malloc(256);
    printf("Ingrese el codigo de vuelo: "); 
    fgets(linea,sizeof(linea),stdin);
    sscanf(linea,"%s",c.codigo);
    guarda_asiento(cantidad, c.codigo);
    crear_doc(codigo);
}
/*
Funcion que consulta en la base los datos de una reserva especifica
E: Void
S: Void
*/
void consultar_r(){
	int cont;
	Codigo c;
	char linea[256];
	char * guarda;
	char mostrar[90];
	c.codigo = malloc(256);
	printf("Ingrese el codigo de la Reserva: "); 
    scanf("%255s",c.codigo);
    fflush(stdin);
	char tags[10][40] = {"Identificador", "Fecha Y Hora de Reservacion", "Informacion de la Aerolinea", 
                    "Codigo de Vuelo", "Lugar y Fecha de salida", "Lugar y Fecha de arribo",
                    "Numero de asientos de la reservacion", "Personas de la reservacion", 
                    "Monto de la reservacion"};
    while(tags[cont][0] != 0){
    	guarda = consultar_doc(cont, c.codigo);
    	strcpy(mostrar,guarda);
    	printf("%s :", tags[cont]);
    	printf("%s\n", mostrar);
    	guarda = NULL;
    	cont += 1;
    }
	
}
/*
Funcion que elimina en la base los datos de una reserva especifica(por codigo)
E: Void
S: Void
*/
void eliminar_r(){
	char consulta[90];
	char linea[256];
	Codigo c;
	c.codigo = malloc(256);
	printf("Ingrese el codigo de la Reserva: "); 
    scanf("%255s",c.codigo);
    fflush(stdin);
	snprintf(consulta, sizeof(consulta), "Delete from Reserva where codigo  = '%s'", c.codigo);
	alterar(consulta);
	printf("Se ha eliminado con exito\n");
}
/*
Funcion que recibe el input del usuario y, con el llama a la funcion verifica_p.
E: Void
S: Void
*/
void reservar(){
	char linea[256];
	char *pasaportes;
	pasaportes = malloc(256);
	printf("Ingrese los pasaportes(Formato: xxxxxxxx,xxxxxxx): ");
	fgets(linea,sizeof(linea),stdin);
	sscanf(linea,"%s",pasaportes);
	verifica_p(pasaportes,0);
}
/*
Funcion que asocia los pasajeros especificados con el codigo de reserva, inserta cada relacion en la base con la fecha actual
E: char pasasportes[30][100], arreglo de pasaportes.
   int tam, 
S: El codio de la reserva
*/
char * insertar_reserva(char pasaportes[30][100], int tam){
	char consulta[90];
	char * id;
	char id_e[9];
	char * codigo;
	codigo = genera_codigo(8);
	for(int i = 0; i < tam; i++){
		id = obtenerId(pasaportes[i]);
		strcpy(id_e,id);
		snprintf(consulta, sizeof(consulta), "insert into Reserva (fecha,codigo,Pasajero_idPasajero) values (NOW(), '%s',%s)", codigo,id_e);
		alterar(consulta);
	}
	return codigo;
}
/*
Obtiene el id de la ultima reserva insertada, y lo retorna
E: Void
S: char * id 
*/
char * obtenerId_R(){
	return get_dato("select max(idReserva) from Reserva;");
}
/*
Obtiene el id de un Pasajero en especifico
E: char pasaporte[], en el que se guarda un pasaporte especifico
S: char * id, donde se guarda el id obtenido
*/
char * obtenerId(char pasaporte[]){
	char * id = malloc(6*sizeof(char));
	char consulta[90];
	snprintf(consulta, sizeof(consulta), "select idPasajero from Pasajero where pasaporte = '%s'", pasaporte);
	id = get_dato(consulta);
	return id;
}
/*
Funcion que valida la edad del pasajero y determina si este ocupa un asiento
E: int cantidad, donde se va guardando la cantidad de asientos que se necesitan
   char pasaportes[30][100] donde se mandan todos los pasaportes
   int tam, el cual incluye el tamano del arreglo
S: cantidad de asientos necesarios
*/
int determina_c(int cantidad, char pasaportes[30][100], int tam){
	char * gua;
	int ed;
	for(int i = 0; i < tam; i++){
		gua = fecha_pas(pasaportes[i]);
		if(gua == NULL){
			printf("Ingreso un pasaporte que no existe\n");
			reservar();
			break;
		}
		ed = edad(gua);
		if(ed > 3){
        	cantidad ++;
        }
	}
	return cantidad;
}
/*
Funcion que devuelve la fecha de nacimineto
E: char pasaporte[], un pasaporte
S: Su fecha de nacimineto
*/
char * fecha_pas(char pasaporte[]){
	char * nac = malloc(6*sizeof(char));
	char consulta[90];
	snprintf(consulta, sizeof(consulta), "select nacimiento from Pasajero where pasaporte = '%s'", pasaporte);
	nac = get_dato(consulta);
	return nac;
}
/*
Funcion que calcula la edad utilizando dos fechas
E: char * palabra, una fecha
S: los annos
*/
int edad(char * palabra){
	time_t t;
  	struct tm *tm;
	char guarda[500];
	char * anno;
	char guarda_a[500];
	int annos;
	int ac;
	t=time(NULL);
  	tm=localtime(&t);
	strcpy(guarda,palabra);
	anno = strtok(guarda,"-");
	strcpy(guarda_a,anno);
	annos = atoi(guarda_a);
	strftime(guarda, 100, "%Y", tm);
	ac = atoi(guarda);
	annos = ac - annos;
	return annos;
}
/*
Funcion que valida si el asiento que se eligio esta libre o ocupado
E: la fila del asiento, la columna del asiento, la cantidad de asientos restantes, y el codigo de vuelo
S: Void
*/
void valida_asiento(int fila, int columna, int cantidad, char * codigo_vuelo){
	char usa_re[30];
	memset(usa_re,'\0',30);
	char *resultado;
	resultado = tipo_asiento(fila,columna);
	if (resultado == NULL){
		printf("El asiento seleccionado no existe\n");
		guarda_asiento(cantidad,codigo_vuelo);
	}
	else{
		strcpy(usa_re, resultado);
		if(usa_re[1] == 'O'){
			printf("El asiento seleccionado ya esta ocupado\n");
			guarda_asiento(cantidad,codigo_vuelo);
		}
		else if(usa_re[1] == 'L'){
			cambia_dis(usa_re[0],fila,columna, 1);
			cantidad -= 1;
			guarda_asiento(cantidad,codigo_vuelo);
		}
		else{
			printf("Error\n");
			guarda_asiento(cantidad,codigo_vuelo);
		}
	}
}
/*
Funcion que cambia la disponibilidad de un asiento en la base
E: El tipo de asiento, la fila, la columna, y que tipo de procedimiento se quiere aplicar, liberar o ocupar
S: Void
*/
void cambia_dis(char tipo, int fila, int columna, int proc){
	char consulta[90];
	char *id;
	char id_res[9];
	memset(consulta,'\0',90);
	id = obtenerId_R();
	strcpy(id_res,id);
	if(proc == 1){
		snprintf(consulta, sizeof(consulta), "update Asiento set tipo = '%cO' where fila = %i and columna = %i;", tipo,fila, columna);
		alterar(consulta);
		snprintf(consulta, sizeof(consulta), "update Asiento set Reserva_idReserva = '%s' where fila = %i and columna = %i;", id_res,fila, columna);
		alterar(consulta);
		printf("Su asiento ha sido reservado\n");
	}
	else{
		snprintf(consulta, sizeof(consulta), "update Asiento set tipo = '%cL' where fila = %i and columna = %i;", tipo,fila, columna);
		alterar(consulta);
		printf("Se libero el asiento\n");
	}
}
/*
Funcion que encuentra el tipo de asiento utilizando una fila y columna
E: la fila y columna
S: char * tipo, guardando el tipo del asiento
*/
char * tipo_asiento(int fila, int columna){
	char consulta[100];
	memset(consulta,'\0',100);
	snprintf(consulta, sizeof(consulta), "select tipo from Asiento where fila = %i and columna = %i;", fila, columna);
	return get_dato(consulta);
}
/*
Funcion que muestra la matriz al usuario y recibe su input
E: la cantidad de asientos disponibles, codigo del vuelo sobre el que se quiere reservar
S: Void
*/
void guarda_asiento(int cantidad, char * codigo_vuelo){
	int fila;
	int columna;
    char camb[9];
	if (cantidad == 0){
		printf("Ya no puede seleccionar mas asientos\n");
	}
	else{
		imprime_asientos(codigo_vuelo);
		printf("Le quedan %i asientos\n", cantidad);
		printf("Seleccione su asiento: \n");
		printf("\n");
		printf("Seleccione la fila de su asiento: ");
		if(scanf(" %i", &fila)!= 1){
			printf("Error\n");
			guarda_asiento(cantidad,codigo_vuelo);
		}
		printf("Seleccione la columna de su asiento: ");
		if(scanf(" %i", &columna)!= 1){
			printf("Error\n");
			guarda_asiento(cantidad,codigo_vuelo);
		}

		valida_asiento(fila, columna,cantidad,codigo_vuelo);
	}
}
/*
Funcion que genera un codigo al azar\
E: tamano del codigo
S: char * codigo, donde se guarda el codigo generado
*/
char *genera_codigo(int tam) {
    static int mySeed = 25011984;
    char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    size_t stringLen = strlen(string);
    char *randomString = NULL;

    srand(time(NULL) * tam + ++mySeed);

    if (tam < 1) {
        tam = 1;
    }

    randomString = malloc(sizeof(char) * (tam +1));

    if (randomString) {
        short key = 0;

        for (int n = 0;n < tam;n++) {
            key = rand() % stringLen;
            randomString[n] = string[key];
        }

        randomString[tam] = '\0';

        return randomString;
    }
    else {
        printf("Sin memoria");
        exit(1);
    }
}
