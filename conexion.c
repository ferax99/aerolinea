
#include "aerolinea.h"
  MYSQL *conn;
      MYSQL_RES *res;
      MYSQL_ROW row;
      //Datos de Mysql
      char *server = "localhost";
      char *user = "fred";
      //set the password for mysql server here
      char *password = ""; /* set me first */
      char *database = "Vuelos";
/*
Funcion que ejecuta un query en la base
E: char * str, query de mysql
S: Void
*/
void alterar(char *str){
  
   conn = mysql_init(NULL);

      // Conectarse a la base de datos 
      if (!mysql_real_connect(conn, server,
            user, password, database, 0, NULL, 0)) {
          fprintf(stderr, "%s\n", mysql_error(conn));
          exit(1);
      }

      //Mandar el query a Mysql
      if (mysql_query(conn, str)) {
          fprintf(stderr, "%s\n", mysql_error(conn));
          exit(1);
      }
      mysql_close(conn);
  
  }  
/*
Funcion para consultar en la base y retornar todos los datos obtenidos por "|"
E: char *str, query de mysql
S: char * resul, que apunta al arreglo resultado, que contiene todos los datos obtenidos
*/
char * consultar(char * str){
  char resultado[1000]= "";
  char * resul = resultado;
   conn = mysql_init(NULL);
      // Conectarse a la base de datos 
      if (!mysql_real_connect(conn, server,
            user, password, database, 0, NULL, 0)) {
          fprintf(stderr, "%s\n", mysql_error(conn));
          exit(1);
      }

      //Mandar el query a Mysql
      if (mysql_query(conn, str)) {
          fprintf(stderr, "%s\n", mysql_error(conn));
          exit(1);
      }

      res = mysql_use_result(conn);
      //imprimir la columna 
     int x = mysql_num_fields(res);
     strcat(resultado,"|");
      while ((row = mysql_fetch_row(res)) != NULL){
      for(int i = 0 ; i<x;i++){
        strcat(resultado, row[i]);
        strcat(resultado, "|");
      }
      strcat(resultado,"  |");    
    }
      resultado[strlen(resultado)-1] = '\0';
      return resul;
      //cerrar la conexion 
      mysql_free_result(res);
      mysql_close(conn);
  }
/*
Funcion que consulta varios datos en la base y los va imprimiendo 
E: char *str, query de mysql
S: char * resul, que apunta al arreglo resultado, que contiene todos los datos obtenidos
*/
char * consultar_p(char * str){
  char resultado[1000]= "";
  char * resul = resultado;
   conn = mysql_init(NULL);
      if (!mysql_real_connect(conn, server,
            user, password, database, 0, NULL, 0)) {
          fprintf(stderr, "%s\n", mysql_error(conn));
          exit(1);
      }

      //Mandar el query a Mysql
      if (mysql_query(conn, str)) {
          fprintf(stderr, "%s\n", mysql_error(conn));
          exit(1);
      }

      res = mysql_use_result(conn);
      //imprimir la columna 
     int x = mysql_num_fields(res);
      while ((row = mysql_fetch_row(res)) != NULL){
      for(int i = 0 ; i<x;i++){
        strcat(resultado, row[i]);
        strcat(resultado, " | ");
      }
      strcat(resultado,"\n");
    }
      resultado[strlen(resultado)-1] = '\0';
       mysql_free_result(res);
      mysql_close(conn);
      printf("%s\n",resul);
      return resul;
      //cerrar la conexion 
  }
/*
Funcion que trae todos los datos de una columna
E: char *str, que contiene el query de mysql
S: char **to_be_returned, donde se guardaron todos los datos
*/
char ** get_columna(char * str){
   conn = mysql_init(NULL);
   char *ary[100] ;
   
      if (!mysql_real_connect(conn, server,
            user, password, database, 0, NULL, 0)) {
          fprintf(stderr, "%s\n", mysql_error(conn)); // Conexion con la Base
          exit(1);}
      if (mysql_query(conn, str)) {
          fprintf(stderr, "%s\n", mysql_error(conn)); // Manda el query
          exit(1);}

     res = mysql_use_result(conn);
     int x = mysql_num_fields(res);
     int con = 0;
     char salva[100][45];
      while ((row = mysql_fetch_row(res)) ){
        strcpy(salva[con],row[0]);
        ary[con]= salva[con];
      con++;
      
    }
    ary[con]= NULL;
  char **strings = ary;
  char **to_be_returned = malloc(sizeof(char*) * 60);
  int i = 0;
  while(*strings) {
    to_be_returned[i] = malloc( sizeof(char) * strlen( *strings ) );
    strcpy( to_be_returned[i++], *strings);
    strings++;
  }
 to_be_returned[con]=NULL;
 mysql_free_result(res);
      mysql_close(conn);
  return to_be_returned;}
/*
Funcion que obtiene un solo dato de un query
E: char *str, query mysql
S: char * resultado
*/
char * get_dato(char * str){
     conn = mysql_init(NULL);
      if (!mysql_real_connect(conn, server,
            user, password, database, 0, NULL, 0)) {
          fprintf(stderr, "%s\n", mysql_error(conn)); // Conexion con la Base
          exit(1);}
      if (mysql_query(conn, str)) {
          fprintf(stderr, "%s\n", mysql_error(conn)); // Manda el query
          exit(1);}

     res = mysql_use_result(conn);
     char *dato = NULL;
     int x = mysql_num_fields(res);
     char pba [500];
     memset(pba,'\0',500);
    while ((row = mysql_fetch_row(res)) ){
        strcat(pba, row[0]);
        dato = pba;
        }
    mysql_free_result(res);
    mysql_close(conn);
  return dato;
  }  
/*
Funcion que consulta en la base y imprime todas las filas y columnas de asientos, formando una matriz
E: codigo de vuelo
S: Void
*/
void imprime_asientos(char * codigo_vuelo){
  char consulta[150];
  char *fis;
  char *guarda;
  char num[4];
  snprintf(consulta, sizeof(consulta), "select max(fila) + 1 from Asiento inner join Vuelo on idVuelo = Vuelo_idVuelo and codigo = '%s';", codigo_vuelo);
  fis = get_dato(consulta);
  strcpy(num, fis);   
  int filas = atoi(num);
  snprintf(consulta, sizeof(consulta), "select max(columna) + 1 from Asiento inner join Vuelo on idVuelo = Vuelo_idVuelo and codigo = '%s';", codigo_vuelo);
  fis = get_dato(consulta);
  strcpy(num,fis);
  int columnas = atoi(num);
  char matriz[columnas][filas][90];
  printf("    ");
  for(int z = 0; z < columnas; z++){
    if(z < 10){
      printf("%i  ", z);
    }
    else if(z == 11){
      printf("%i ", z);
    }
    else{
      printf("%i ",z);
    }
  }
  printf(" ");
  printf("\n");
  for(int i = 0; i < filas; i++){
    if(i < 10){
      printf(" %i",i);
      printf(" |");

    }
    else{
      printf("%i",i);
      printf(" |");
    }
    for(int j = 0; j < columnas; j++){
      guarda = tipo_asiento(i,j);
      strcpy(num, guarda);
      printf("%s|", num);
      guarda = NULL;
    }
    printf("\n");
  }
  printf("\n");
}
/*
Funcion que consulta en la base de datos todos los datos relacionados con una reserva, utilizando un filtro de un numero
E: int seleccion, el cual determina cual consulta va a realizar
   char * codigo, donde se envia el codigo de la reserva 
*/
char * consultar_doc(int seleccion, char * codigo){
  char consulta[500];
  char parte1[50];
  char parte2[50];
  char *resultado = NULL;
  if(seleccion == 0){
    snprintf(consulta, sizeof(consulta), "select idReserva from Reserva where codigo = '%s'", codigo);
    resultado = consultar(consulta);
    return resultado;
  }
  else if(seleccion == 1){
    snprintf(consulta, sizeof(consulta), "select fecha from Reserva where codigo = '%s' limit 1", codigo);
    resultado = consultar(consulta);
    return resultado;
  }
  else if(seleccion == 2){
    snprintf(consulta, sizeof(consulta), "select aero.nombre, aero.hub from ((((Aerolinea as aero inner join Avion on  aero.idAereolinea = Avion.Aereolinea_idAereolinea) inner join Vuelo on Avion.idAvion = Vuelo.Avion_idAvion) inner join Asiento on idVuelo = Vuelo_idVuelo) inner join Reserva on Reserva_idReserva = idReserva and Reserva.codigo = '%s') limit 1", codigo);
    resultado = consultar(consulta);
    return resultado;

  }
  else if(seleccion == 3){
    snprintf(consulta, sizeof(consulta), "select Vuelo.codigo from ((((Aerolinea as aero inner join Avion on  aero.idAereolinea = Avion.Aereolinea_idAereolinea) inner join Vuelo on Avion.idAvion = Vuelo.Avion_idAvion) inner join Asiento on idVuelo = Vuelo_idVuelo) inner join Reserva on Reserva_idReserva = idReserva and Reserva.codigo = '%s') limit 1", codigo);
    resultado = consultar(consulta);
    return resultado;
  }
  else if(seleccion == 4){
    snprintf(consulta, sizeof(consulta), "select Vuelo.origen, Vuelo.salida from ((((Aerolinea as aero inner join Avion on  aero.idAereolinea = Avion.Aereolinea_idAereolinea) inner join Vuelo on Avion.idAvion = Vuelo.Avion_idAvion) inner join Asiento on idVuelo = Vuelo_idVuelo) inner join Reserva on Reserva_idReserva = idReserva and Reserva.codigo = '%s') limit 1", codigo);
    resultado = consultar(consulta);
    return resultado;
  }
  else if(seleccion == 5){
    snprintf(consulta, sizeof(consulta), "select Vuelo.destino, Vuelo.llegada from ((((Aerolinea as aero inner join Avion on  aero.idAereolinea = Avion.Aereolinea_idAereolinea) inner join Vuelo on Avion.idAvion = Vuelo.Avion_idAvion) inner join Asiento on idVuelo = Vuelo_idVuelo) inner join Reserva on Reserva_idReserva = idReserva and Reserva.codigo = '%s') limit 1", codigo);
    resultado = consultar(consulta);
    return resultado;
  }
  else if(seleccion == 6){
    snprintf(consulta, sizeof(consulta), "select Pasajero.nombre, Pasajero.apellido1, Pasajero.apellido2 from Pasajero inner join Reserva on idPasajero = Pasajero_idPasajero and codigo = '%s'", codigo);
    resultado = consultar(consulta);
    return resultado;
  }
  
  else if(seleccion == 7){
    snprintf(consulta, sizeof(consulta), "select count(Reserva.Pasajero_idPasajero) from Reserva where codigo = '%s'", codigo);
    resultado = consultar(consulta);
    return resultado;
  }
  else if(seleccion == 8){
    snprintf(consulta, sizeof(consulta), "select sum(Asiento.costo) from ((((Aerolinea as aero inner join Avion on  aero.idAereolinea = Avion.Aereolinea_idAereolinea) inner join Vuelo on Avion.idAvion = Vuelo.Avion_idAvion) inner join Asiento on idVuelo = Vuelo_idVuelo) inner join Reserva on Reserva_idReserva = idReserva and Reserva.codigo = '%s')", codigo);
    resultado = consultar(consulta);
    return resultado;
  }
}
// para compilar usar el comando: gcc $(mysql_config --cflags) conexion.c aerolinea.c operativos.c generales.c $(mysql_config --libs) -o prueba

// para ejecutar utilizar ./a.out
