#include "aerolinea.h"
/*
Menu principal con inicio de sesion, se compara la clave "1234" con el input del usuario
Se llaman los otros submenus, segun el input del usuario
Datos de prueba para la reserva: 2385502,1882314,2344905
E: Void
S: Void
*/
int main(){
	char clave[256];
	char pred[5] = "1234";
	char * gg;
	gg = malloc(256);
	printf("Ingrese La Clave: ");
	scanf("%255s",gg);
	fflush(stdin);
	strcpy(clave,gg);
	if(strcmp(clave, pred) != 0){
		printf("Clave Incorrecta\n");
		return 0;
	}
	printf("Inicio de Sesion Exitoso\n");
	getchar();
	getchar();
	char linea[256];
	int camb;
	do {
		system("clear");
		printf("1 - Opciones Operativas\n");
		printf("2 - Opciones Generales\n");
		printf("3 - Salir\n");
		printf("Elija una opcion: ");
		fgets(linea,sizeof(linea),stdin);
		sscanf(linea,"%i",&camb);
		fflush(stdin);
		switch(camb) {
			case 1: 
				system("clear");
				printf("\n");
				submenu_op();
				printf("\n");
				break;
			case 2: 
			    
				system("clear");
				printf("\n");
				submenu_gen();
				printf("\n");
				break;
			case 3: 
				break;
			    
			default:
				printf("Error\n");
		}
	} while(camb != 3) ;
	printf("Se saldra del programa\n");
	return 0;
}