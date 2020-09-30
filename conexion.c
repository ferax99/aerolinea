
#include "aerolinea.h"
  MYSQL *conn;
      MYSQL_RES *res;
      MYSQL_ROW row;

      char *server = "localhost";
      char *user = "ferax";
      //set the password for mysql server here
      char *password = "binda99"; /* set me first */
      char *database = "ruvilo";
 
 
      
void borrar(char *str){
	
	 conn = mysql_init(NULL);

      /* Connect to database */
      if (!mysql_real_connect(conn, server,
            user, password, database, 0, NULL, 0)) {
          fprintf(stderr, "%s\n", mysql_error(conn));
          exit(1);
      }

      /* send SQL query */
      if (mysql_query(conn, str)) {
          fprintf(stderr, "%s\n", mysql_error(conn));
          exit(1);
      }
       mysql_free_result(res);
      mysql_close(conn);
	
	}  
void consultar(char * str){
	
	 conn = mysql_init(NULL);
	
      /* Connect to database */
      if (!mysql_real_connect(conn, server,
            user, password, database, 0, NULL, 0)) {
          fprintf(stderr, "%s\n", mysql_error(conn));
          exit(1);
      }

      /* send SQL query */
      if (mysql_query(conn, str)) {
          fprintf(stderr, "%s\n", mysql_error(conn));
          exit(1);
      }

      res = mysql_use_result(conn);
      //imprimir la columna 
     int x = mysql_num_fields(res);
     
      printf("-------------------%i--------", x);
      while ((row = mysql_fetch_row(res)) != NULL){
		 printf("-------------------");
		  for(int i = 0 ; i<x;i++){
          printf("\ncolumna: %i      valor:%s \n",i, row[i]);}
           printf("-------------------");
          
	  
	  }
	   

      //cerrar la conexion 
      mysql_free_result(res);
      mysql_close(conn);
	}
      

// para compilar usar el comando: gcc $(mysql_config --cflags) conexion.c aerolinea.c $(mysql_config --libs)
// para ejecutar utilizar ./a.out
