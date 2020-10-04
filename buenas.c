char * consultar(char * str){
  char resultado[1000] = "";
  char * resul = resultado;
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
     
      while ((row = mysql_fetch_row(res)) != NULL){
      for(int i = 0 ; i<x;i++){
        strcat(resultado, row[i]);
        strcat(resultado, " ");
      }    
    }
      return resul;
      //cerrar la conexion 
      mysql_free_result(res);
      mysql_close(conn);
  }