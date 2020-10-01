#include <stdio.h>
#include <stdlib.h>

void submenu_op(){
    int camb;
	do {
	    printf("--------Opciones Operativas--------\n");
	    printf("1 - Informacion de la Aerolinea");
		printf("2 - Registro de Aviones\n");
		printf("3 - Carga Usuarios\n");
		printf("4 - Estado de Vuelo\n");
		printf("5 - Estadisticas\n");
		printf("6 - Salir\n");
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

void submenu_gen(){
    int camb;
	do {
		printf("--------Opciones Generales--------\n");
		printf("1 - Reservacion de Vuelo\n");
		printf("2 - Consultar Reservas\n");
		printf("3 - Eliminar Reservas\n");
		printf("4 - Salir\n");
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
				printf("Se consultara la reserva\n");
				printf("\n");
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

void menu(){
	int camb;
	do {
		printf("1 - Opciones Operativas\n");
		printf("2 - Opciones Generales\n");
		printf("3 - Salir\n");
		printf("Elija una opcion: ");
		scanf("%i",&camb);
		switch(camb) {
			case 1: 
				system("clear");
				printf("\n");
				submenu_op();
				exit;
				printf("\n");
				break;
			case 2: 
			    
				system("clear");
				printf("\n");
				submenu_gen();
				exit;
				printf("\n");
				break;
			case 3: 
				break;
			    
			default:
				printf("Error\n");
		}
	} while(camb != 3) ;
	printf("Se saldra del programa");
}