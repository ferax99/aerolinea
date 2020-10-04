#include "aerolinea.h"
/*
i = atoi ("53");
*/
void submenu_gen(){
    int camb;
    char *codigo;
	do {
		printf("--------Opciones Generales--------\n");
		printf("1 - Reservacion de Vuelo\n");
		printf("2 - Consultar Reservas\n");
		printf("3 - Eliminar Reservas\n");
		printf("4 - Regresar\n");
		printf("Elija una opcion: ");
		scanf("%i",&camb);
		switch(camb) {
			case 1: 
				system("clear");
				printf("\n");
				printf("Reservar\n");
				printf("\n");
				break;
			case 2: 
				system("clear");
				printf("\n");
				printf("Cual reserva quiere consultar: ");
				scanf("%s", codigo);
				printf("\n");
				consultar_r(codigo);
				break;
			case 3: 
			    system("clear");
				printf("\n");
				printf("Se eliminara la reserva\n");
				printf("\n");
				break;
			case 4:
			    break;
			    
			default:
				printf("Error\n");
		}
	} while(camb != 4) ;
}

/*void reservar(){

}*/

void consultar_r(char *codigo){
	int cont;
	char * guarda;
	char mostrar[90];
	char tags[10][40] = {"Identificador", "Fecha Y Hora de Reservacion", "Informacion de la Aerolinea", 
                    "Codigo de Vuelo", "Lugar y Fecha de salida", "Lugar y Fecha de arribo",
                    "Numero de asientos de la reservacion", "Personas de la reservacion", 
                    "Monto de la reservacion"};
    while(tags[cont][0] != 0){
    	guarda = consultar_doc(cont, codigo);
    	strcpy(mostrar,guarda);
    	printf("%s :", tags[cont]);
    	printf("%s\n", mostrar);
    	guarda = NULL;
    	cont += 1;
    }
	
}

void eliminar_r(char *codigo){
	char consulta[90];
	snprintf(consulta, sizeof(consulta), "Delete from Reserva where codigo  = '%s'", codigo);
	alterar(consulta);
}

void insertar_reserva(char * codigo_vuelo){
	char *pasaportes;
	printf("Ingrese los pasaportes(Formato: xxxxxxxx,xxxxxxx): ");
	scanf("%s\n", pasaportes);
	//void imprime_asientos();	
}

/*int verifica_edad(char *pasaportes, int cantidad){
	char consulta[90];
	char guarda_p[100];
	int i = 0;
	strcpy(guarda_p,pasaportes);
	snprintf(consulta, sizeof(consulta), "select nacimiento from Pasajero where pasaporte = '%s'", pasaportes);
	//alterar(consulta);
	while( muestra != NULL ) {
		i = edad()
		if 
        strcpy(guarda_p, pasaportes);
        
        muestra = strtok(NULL, " ");
      } 
	return cantidad

}*/
int edad(char * palabra){
	time_t t;
  	struct tm *tm;
	char guarda[90];
	char * anno;
	char guarda_a[80];
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

void valida_asiento(int fila, int columna, int cantidad, char * codigo_vuelo){
	char cambia[90];
	char usa_re[30];
	char *resultado = malloc(6*sizeof(char));
	//memset(cambia,'\0',90);
	//memset(usa_re,'\0',30);
	resultado = tipo_asiento(fila,columna);
	strcpy(usa_re, resultado);
	if (resultado == NULL){
		printf("El asiento seleccionado no existe\n");
		guarda_asiento(cantidad,codigo_vuelo);
	}
	else if(usa_re[1] == 'O'){
		printf("El asiento seleccionado ya esta ocupado\n");
		guarda_asiento(cantidad,codigo_vuelo);
	}
	else if(usa_re[1] == 'L'){
		snprintf(cambia, sizeof(cambia), "update Asiento set tipo = '%cO' where fila = %i and columna = %i;", usa_re[0],fila, columna);
		printf("%s\n", cambia);
		alterar(cambia);
		printf("Su asiento ha sido reservado\n");
		printf("%s\n", codigo_vuelo);
		cantidad -= 1;
		guarda_asiento(cantidad,codigo_vuelo);
	}
	else{
		printf("Error\n");
		guarda_asiento(cantidad,codigo_vuelo);
	}
} 
/*
update Asiento set tipo = 'BO' where fila = 0 and columna = 0;
*/

char * tipo_asiento(int fila, int columna){
	char consulta[100];
	snprintf(consulta, sizeof(consulta), "select tipo from Asiento where fila = %i and columna = %i;", fila, columna);
	return get_dato(consulta);
}

int guarda_asiento(int cantidad, char * codigo_vuelo){
	int fila;
	int columna;
    char camb[9];
	if (cantidad == 0){
		printf("Ya no puede seleccionar mas asientos\n");
		return 0;
	}
	else{
		imprime_asientos(codigo_vuelo);
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

char * fecha(){
  time_t t;
  struct tm *tm;
  char fecha_ac[100];
  char * fecha = fecha_ac;
  t=time(NULL);
  tm=localtime(&t);
  strftime(fecha_ac, 100, "%d/%m/%Y", tm);	
  return fecha;
}
