#include "aerolinea.h"

int main(){
	/*char clave[256];
	char cla[5] = "1234";
	char * gg;
	printf("Ingrese La Clave: ");
	fgets(clave,sizeof(clave),stdin);
	sscanf(clave,"%s",gg);
	fflush(stdin);
	if(strcmp(gg, cla) != 0){
		printf("Clave Incorrecta\n");
		return 0;
	}*/
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
	consultar_r();
}

//2385502,1882314,2344905
