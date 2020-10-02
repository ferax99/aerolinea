#include "aerolinea.h"

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