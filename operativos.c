#include "aerolinea.h"
void consultar_avion(){
	/*
	E:
	S:
	R:
	funcionamiento: sirve para consultar informacion sobre el avion e imprimirla en pantalla
	*/
	system("clear");
	char ** anno = get_columna("select anno from Avion;");
	char ** modelo = get_columna("select modelo from Avion;");
	char ** matricula = get_columna("select matricula from Avion;");
	int con = 0;
	while(*anno!=NULL) {
	printf("-----------%i--------------\n", con);
    printf("modelo    : %s\n", *modelo);
    printf("anno       : %s\n", *anno);
    printf("matricula : %s\n", *matricula);
    anno++;
    modelo++;
    matricula++;
    con++;
  }
  getchar();
  getchar();
	
	}	
int editar_Avion(){
	/*
	E:
	S:
	R:
	funcionamiento: Sirve para editar cualquier dato de un avion
	*/
	Avion a;
	 char query[150];
	 query[0] = '\0';
	 char valida[150];
	 char *seleccion ;
	system("clear");
	printf("Que Avion quieres editar?? \n");
	printf("matricula :\n");
	a.matricula = malloc(256);
	scanf("%255s", a.matricula);
	snprintf(valida, sizeof(valida),"select matricula from Avion where matricula = '%s';",a.matricula);
	if(get_dato( valida)== NULL) {printf("\nentrada invalida\n");getchar();getchar();return 0 ;}
    int camb;
	do {
		system("clear");
		printf("--------Atributos de %s--------\n",a.matricula);
		printf("1 - matricula\n");
		printf("2 - modelo\n");
		printf("3 - anno\n");
		printf("4 - Aerolinea\n");
		printf("Seleccion el atributo a alterar: ");
		scanf("%i",&camb);
		printf("\n");
		printf("seleccione el valor por el que desea cambiarlo: ");
		seleccion = malloc(256);
	scanf("%255s", seleccion);
		switch(camb) {
			case 1: 
				query[0] = '\0';
				snprintf(query, sizeof(query),
			"update Avion set matricula = '%s' where matricula = '%s'", seleccion,a.matricula);
			alterar(query);
			printf("\nDato alterado con exito!");
			getchar();
			getchar();
				return 0;
			case 2: 
				query[0] = '\0';
				snprintf(query, sizeof(query),
				"update Avion set modelo = '%s' where matricula = '%s'", seleccion,a.matricula);
				alterar(query);
				printf("\nDato alterado con exito!");
			getchar();
			getchar();
				return 0;
			case 3: 
				  query[0] = '\0';
				snprintf(query, sizeof(query),
			    "update Avion set anno = '%s' where matricula = '%s'", seleccion,a.matricula);
			    alterar(query);
			    printf("\nDato alterado con exito!");
			getchar();
			getchar();
				return 0;
			case 4:
			   
				break;
			case 5:
			    break;    
			default:
				printf("Error de seleccion\n");
		}
	} while(camb != 5) ;
	return 0 ;
}
void agregar_avion(){
	/*
	E:
	S:
	R:
	funcionamiento: sirve para agregar la informacion de un avion a la base
	*/
	Avion a;
	char linea[256];
	int max = 45;
	 char query[150];
	system("clear");
	printf("hora de agregar Avion:\n");
	printf("matricula :\n");
	a.matricula = malloc(256);
  scanf("%255s", a.matricula);
	printf("modelo  : ");
	a.modelo = malloc(256);
  scanf("%255s", a.modelo);
	printf("anno : ");
	a.anno = malloc(256);
  scanf("%255s", a.anno);
	 snprintf(query, sizeof(query),
    "insert into Avion(matricula,modelo,anno,Aereolinea_idAereolinea) values ('%s','%s','%s',%i)", a.matricula, a.modelo,a.anno, 3);
	alterar(query);
	printf("avion insertado con exito");
	getchar();
	getchar();
	}
int borrar_avion(){
	/*
	E:
	S:
	R:
	funcionamiento: sirve para borrar un avion dependiendo de su numero de matriucla
	*/
	Avion a;
	int max = 45;
	 char query[150];
	 char valida[150];
	system("clear");
	printf("selecciona la matricula del Avion que quieres borrar:\n");
	printf("matricula :\n");
	a.matricula = malloc(256);
	scanf("%255s", a.matricula);
	snprintf(valida, sizeof(valida),"select a.matricula from Vuelo v inner join Avion a on a.idAvion = v.Avion_idAvion where a.matricula = '%s';",a.matricula);
	if(get_dato( valida)!= NULL) {printf("\nError: El avion tiene vuelos registrados\n");getchar();getchar();return 0 ;}
	 snprintf(query, sizeof(query),
    "delete from Avion where matricula = '%s'", a.matricula);
	alterar(query);
	printf("avion borrado con exito");
	getchar();
	getchar();
	return 0;
	}
void submenu_avion(){
	/*
	E:
	S:
	R:
	funcionamiento: menu para llamar funciones operativas de un avion
	*/
    int camb;
	do {
		system("clear");
		printf("--------Menu de aviones--------\n");
		printf("1 - Consultar Aviones\n");
		printf("2 - Agregar Aviones\n");
		printf("3 - Editar Aviones\n");
		printf("4 - Eliminar Aviones\n");
		printf("5 - Regresar\n");
		printf("Elija una opcion: ");
		scanf("%i",&camb);
		printf("\n");
		switch(camb) {
			case 1: 
				consultar_avion();
				break;
			case 2: 
				agregar_avion();
				break;
			case 3: 
			    editar_Avion();
				break;
			case 4:
			    borrar_avion();
				break;
			case 5:
			    break;    
			default:
				printf("Error\n");
		}
	} while(camb != 5) ;
}
int insertar_personas(){
	/*
	E:
	S:
	R:
	funcionamiento: procedimiento para cargar personas a la base apartir de un archivo de texto
	*/
	system("clear");
	printf("Direccion del archivo: ");
	char * direccion;
	 direccion= malloc(256);
  scanf("%255s", direccion);
	char ch, file_name[25];
   FILE *fp;
   fp = fopen(direccion, "r"); // read mode

   if (fp == NULL)
   {
      perror("Error al cargar el archivo.\n");
      exit(EXIT_FAILURE);
   }

	char dato[45] ;
	char arr[180][45] ;
	char query[200];
	memset(dato, 0, sizeof(dato));
	int i = 0 ;
	char pasaporte[200];
   while((ch = fgetc(fp)) != EOF){
		
      if (ch == 44 ){
			strcpy(arr[i],dato);
			//printf("%s\n",arr[i]);
			i++;
		   //printf("%s\n",dato);
		   dato[0] = '\0';
		   memset(dato, 0, sizeof(dato)); 
		   
		  }
		  if (ch == 10){
			  strcpy(arr[i],dato);
			  i++;
			   memset(dato, 0, sizeof(dato));
			   if(i%6!=0){printf("ERROR: debe completar todos los campos para %s\n",arr[i-6]);continue;};
				snprintf(pasaporte, sizeof(pasaporte),
			 "select idPasajero from Pasajero where pasaporte = '%s'", arr[i-6]);
			 if(get_dato(pasaporte)!=NULL){printf("El pasaporte ya se encuentra registrado\n");continue;}
			   if(get_dato(pasaporte)){continue;}
			   if(!(strcmp(arr[i-2],"H")==0 || strcmp(arr[i-2],"M") ==0)) {printf("ERROR AL INSERTAR, %s tiene el genero no valido '%s'     \n",arr[i-5],arr[i-2]);continue ;} 
			snprintf(query, sizeof(query),
			 "insert into Pasajero(pasaporte,nombre,apellido1,apellido2,sexo,nacimiento) values ('%s','%s','%s','%s','%s','%s')", arr[i-6],arr[i-5],arr[i-4],arr[i-3],arr[i-2],arr[i-1]);
			//alterar(query);
			printf("%s insertado con exito...\n",arr[i-5]);
			memset(query, 0, sizeof(query)); 
			memset(pasaporte, 0, sizeof(pasaporte)); 
		}
		if (ch != 44 && ch!= 10){strncat(dato, &ch, 1);}
      
      }

   fclose(fp);
   printf("Proceso terminado! Presione Enter");
   getchar();
   getchar();
	return 0;
	
	}
void estado_vuelo(){
	/*
	E:
	S:
	R:
	funcionamiento: consulta datos especificos sobre la base 
	*/
	char *codigo;
	char query[256];
	char query2[256];
	system("clear");
	printf("codigo de vuelo :\n");
	codigo = malloc(256);
	scanf("%255s", codigo);
	snprintf(query, sizeof(query),"select * from estado where codigo = '%s'",codigo );
	snprintf(query2, sizeof(query2),"select * from estado2 where codigo = '%s'",codigo );
	system("clear");
	printf("codigo | origen     | salida              | destino      | llegada             | SO   | BO   | EO  \n");
	consultar_p(query);
	printf("\n###################\n Personas en el vuelo\n###################\n");
	printf("codigo de vuelo|tipo|nombre|pasaporte|codigo de reserva|numero de Asiento|costo \n");
	consultar_p(query2);
	imprime_asientos(codigo);
	getchar();
	getchar();
	}
void estadisticas(){
	system("clear");
	printf("Top 3 de vuelos de mayor venta (de mayor a menor)\n");
	printf("codigo|total \n");
	consultar("select v.codigo, sum(a.costo) as total from Asiento a inner join Vuelo v on a.Vuelo_idVuelo = v.idVuelo where a.tipo like '%O%' group by v.codigo desc order by total desc limit 3;");
	printf("\n\nTop 3 de vuelos con mayor cantidad de personas (de mayor a menor)\n");
	printf("codigo|personas \n\n");
	consultar("select v.codigo, count(v.codigo)  as personas from Vuelo v inner join Asiento a on v.idVuelo = a.Vuelo_idVuelo where a.tipo like '%O%' group by v.codigo  order by personas desc limit 3;");
	getchar();
	getchar();
	
	}


void submenu_op(){
	/*
	E:
	S:
	R:
	funcionamiento: menu de navegacion
	*/
	char linea[256];
    char camb;
	do {
		system("clear");
	    printf("--------Opciones Operativas--------\n");
	    printf("1 - Informacion de la Aerolinea\n");
		printf("2 - Aviones\n");
		printf("3 - Carga Usuarios\n");
		printf("4 - Estado de Vuelo\n");
		printf("5 - Estadisticas\n");
		printf("6 - Salir\n");
		printf("Elija una opcion: ");
		fgets(linea,sizeof(linea),stdin);
		sscanf(linea,"%c",&camb);
		switch(camb) {
		    case '1':
				printf("nombre            | hub         \n");
		        consultar_p("select nombre,hub from Aerolinea where idAereolinea  = 1;");// la primera porque no hay funcionalidad de seleccion de aerolinea
		        getchar();
		        getchar();
				break;
			case '2': 
				submenu_avion();
				break;
			case '3': 
				insertar_personas();
				break;
			case '4': 
			   estado_vuelo();
				break;
			case '5':
			    estadisticas();
				break;
			case '6':
			    break;
			default:
				printf("Error\n");
		}
	} while(camb != '6') ;
}
