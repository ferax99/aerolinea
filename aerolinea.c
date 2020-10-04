#include "aerolinea.h"

int main(){
	/*int camb;
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
	printf("Se saldra del programa");*/
	//char * loca;
	//loca = consultar("select * from Avion");
	//printf("%s\n", loca);
	//crear_doc();
	//consultar_r("jdsflkaS");
	//fecha();
	//imprime_asientos("95475");
	valida_asiento(2,3,1,"95475");
	//guarda_asiento(2,"95475");
	//int i;
	//i = edad("2000-11-08");
	//printf("%i\n", i);
	//char *ss;
	//ss = get_dato("select count(fila) from Asiento inner join Vuelo on idVuelo = Vuelo_idVuelo and codigo = '95475';");
	//printf("Esta prueba es: %s\n", ss);
	//ss = tipo_asiento(4,3);
	//printf("%s\n", ss);
	//consultar_doc(0, "jdsflkaS");
	//char a[100];
	//snprintf(a, sizeof(a), "Player %s has lost %s hitpoints \n", "pene", "peque");
    //printf("%s",a);
	return 0;
}
