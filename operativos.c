#include "aerolinea.h"

void submenu_op(){
    int camb;
	do {
	    printf("--------Opciones Operativas--------\n");
	    printf("1 - Informacion de la Aerolinea");
		printf("2 - Registro de Aviones\n");
		printf("3 - Carga Usuarios\n");
		printf("4 - Estado de Vuelo\n");
		printf("5 - Estadisticas\n");
		printf("6 - Regresar\n");
		printf("Elija una opcion: ");
		scanf("%i",&camb);
		switch(camb) {
		    case 1:
		        system("clear");
				printf("\n");
				printf("Informacion de la aerolinea\n");
				printf("\n");
				break;
			case 2: 
				system("clear");
				printf("\n");
				printf("Se registrara un avion\n");
				printf("\n");
				break;
			case 3: 
				system("clear");
				printf("\n");
				printf("Se cargaran los usuarios\n");
				printf("\n");
				break;
			case 4: 
			    system("clear");
				printf("\n");
				printf("Se mostrara el estado del vuelo\n");
				printf("\n");
				break;
			case 5:
			    system("clear");
				printf("\n");
				printf("Se mostraran las estadisticas\n");
				printf("\n");
				break;
			case 6:
			    break;
			default:
				printf("Error\n");
		}
	} while(camb != 6) ;
}

void registro(){
	int camb;
	do {
	    printf("--------Opciones Operativas--------\n");
	    printf("1 - Ingresar Avion");
		printf("2 - Eliminar Avion\n");
		printf("3 - Mostrar Aviones\n");
		printf("4 - Regresar\n");
		printf("Elija una opcion: ");
		scanf("%i",&camb);
		switch(camb) {
		    case 1:
		        system("clear");
				printf("\n");
				printf("Se agregara un avion\n");
				printf("\n");
				break;
			case 2: 
				system("clear");
				printf("\n");
				printf("Se eliminara un avion\n");
				printf("\n");
				break;
			case 3: 
				system("clear");
				printf("\n");
				printf("Se mostraran los aviones\n");
				printf("\n");
				break;
			case 4:
			    break;
			default:
				printf("Error\n");
		}
	} while(camb != 4) ;
}