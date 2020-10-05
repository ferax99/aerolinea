#include "aerolinea.h"
/*
i = atoi ("53");
*/
void submenu_gen(){
    int camb;
    char linea[256];
    char *codigo = "95475";
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
		switch(camb) {
			case 1: 
				system("clear");
				printf("\n");
				printf("Reservar\n");
				reservar(codigo);
				//submenu_gen();
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
				eliminar_r(codigo);
				printf("\n");
				break;
			case 4:
			    break;
			    
			default:
				printf("Error\n");
		}
	} while(camb != 4) ;
}

char * verifica_p(char *pasaportes, int cantidad, char * codigo_vuelo){
	char guarda_p[100];
	char uno[30];
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
    cantidad = determina_c(cantidad, pasap,tam,codigo_vuelo);
    codigo = insertar_reserva(pasap,tam);
    guarda_asiento(cantidad, codigo_vuelo);
    crear_doc(codigo);
}

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

void reservar(char * codigo_vuelo){
	char linea[256];
	char *pasaportes;
	pasaportes = malloc(256);
	printf("Ingrese los pasaportes(Formato: xxxxxxxx,xxxxxxx): ");
	fgets(linea,sizeof(linea),stdin);
	sscanf(linea,"%s",pasaportes);
	verifica_p(pasaportes,0,codigo_vuelo);
}
char * insertar_reserva(char pasaportes[30][100], int tam){
	char consulta[90];
	char * id;
	char id_e[9];
	char * codigo;
	codigo = genera_codigo(8);
	for(int i = 0; i < tam; i++){
		printf("%i\n", i);
		id = obtenerId(pasaportes[i]);
		strcpy(id_e,id);
		snprintf(consulta, sizeof(consulta), "insert into Reserva (fecha,codigo,Pasajero_idPasajero) values (NOW(), '%s',%s)", codigo,id_e);
		alterar(consulta);
	}
	return codigo;
}

char * obtenerId_R(){
	return get_dato("select max(idReserva) from Reserva;");
}

char * obtenerId(char pasaporte[]){
	char * hola = malloc(6*sizeof(char));
	char consulta[90];
	snprintf(consulta, sizeof(consulta), "select idPasajero from Pasajero where pasaporte = '%s'", pasaporte);
	hola = get_dato(consulta);
	return hola;
}



int determina_c(int cantidad, char pasaportes[30][100], int tam, char * codigo_vuelo){
	char * gua;
	int ed;
	for(int i = 0; i < tam; i++){
		gua = fecha_pas(pasaportes[i]);
		if(gua == NULL){
			printf("Ingreso un pasaporte que no existe\n");
			reservar(codigo_vuelo);
			break;
		}
		ed = edad(gua);
		if(ed > 3){
        	cantidad ++;
        }
	}
	return cantidad;
}

char * fecha_pas(char pasaporte[]){
	char * hola = malloc(6*sizeof(char));
	char consulta[90];
	snprintf(consulta, sizeof(consulta), "select nacimiento from Pasajero where pasaporte = '%s'", pasaporte);
	hola = get_dato(consulta);
	return hola;
}

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

char * tipo_asiento(int fila, int columna){
	char consulta[100];
	memset(consulta,'\0',100);
	snprintf(consulta, sizeof(consulta), "select tipo from Asiento where fila = %i and columna = %i;", fila, columna);
	return get_dato(consulta);
}

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

char *genera_codigo(int length) {
    static int mySeed = 25011984;
    char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    size_t stringLen = strlen(string);
    char *randomString = NULL;

    srand(time(NULL) * length + ++mySeed);

    if (length < 1) {
        length = 1;
    }

    randomString = malloc(sizeof(char) * (length +1));

    if (randomString) {
        short key = 0;

        for (int n = 0;n < length;n++) {
            key = rand() % stringLen;
            randomString[n] = string[key];
        }

        randomString[length] = '\0';

        return randomString;
    }
    else {
        printf("Sin memoria");
        exit(1);
    }
}
