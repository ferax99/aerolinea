compilar:
	gcc $(mysql_config --cflags) conexion.c aerolinea.c operativos.c generales.c crear_pdf.c $(mysql_config --libs) -lhpdf -lpng -lz -lm -o prueba

limpiar:
	re -f prueba
