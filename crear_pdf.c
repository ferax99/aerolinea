#include "aerolinea.h"

void error_handler (HPDF_STATUS   error_no,
               HPDF_STATUS   detail_no,
               void         *user_data)
{
    printf ("ERROR: error_no=%04X, detail_no=%u\n", (HPDF_UINT)error_no,
                (HPDF_UINT)detail_no);
    longjmp(env, 1);
}

/*
identificador(auto generado) = int 
fecha y hora de la reservación = string
información de aerolínea = string 
código de vuelo = double
lugar y fecha salida = string
lugary fecha arribo = string
número de asientos de la reservación = string 
personas de la reservación = string 
monto de reservación = float
*/

void show_description (HPDF_Page page, HPDF_REAL x, HPDF_REAL y, const char *text){
    float fsize = HPDF_Page_GetCurrentFontSize (page);
    HPDF_Font font = HPDF_Page_GetCurrentFont (page);
    HPDF_RGBColor c = HPDF_Page_GetRGBFill (page);
    HPDF_Page_BeginText (page);
    HPDF_Page_SetRGBFill (page, 0, 0, 0);
    HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_SetFontAndSize (page, font, 10);
    HPDF_Page_TextOut (page, x, y - 12, text);
    HPDF_Page_EndText (page);
    HPDF_Page_SetFontAndSize (page, font, fsize);
    HPDF_Page_SetRGBFill (page, c.r, c.g, c.b);
}

int crear_doc (){
    const char *page_title = "Comprobante";
    char tags[10][40] = {"Identificador", "Fecha Y Hora de Reservacion", "Informacion de la Aerolinea", 
                    "Codigo de Vuelo", "Lugar y Fecha de salida", "Lugar y Fecha de arribo",
                    "Numero de asientos de la reservacion", "Personas de la reservacion", 
                    "Monto de la reservacion"};
    HPDF_Doc  pdf;
    HPDF_Font font;
    HPDF_Page page;
    char fname[256] = "Comprobante";
    float tw;
    float fsize = 12;
    int cont = 0;
<<<<<<< HEAD
    float ypos = 790;
    char * codigo = "jdsflkaS";
    char * guarda;
=======
    int len;
    float angle1;
    float angle2;
    float rad1;
    float rad2;
    float ypos = 790;
    char * codigo = "jdsflkaS";
    char * guarda;

    //strcpy (fname, argv[0])
>>>>>>> 7affd9cf8a84542ea487a4488761d4fe0252459e
    strcat (fname, ".pdf");

    pdf = HPDF_New (error_handler, NULL);
    if (!pdf) {
        printf ("error: cannot create PdfDoc object\n");
        return 1;
    }

    if (setjmp(env)) {
        HPDF_Free (pdf);
        return 1;
    }
<<<<<<< HEAD
=======
    // set compression mode
>>>>>>> 7affd9cf8a84542ea487a4488761d4fe0252459e
    HPDF_SetCompressionMode (pdf, HPDF_COMP_ALL);
    font = HPDF_GetFont (pdf, "Helvetica", NULL);
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetFontAndSize (page, font, 18);
    tw = HPDF_Page_TextWidth (page, page_title);
    HPDF_Page_BeginText (page);
    HPDF_Page_TextOut (page, (HPDF_Page_GetWidth(page) - tw) / 2, HPDF_Page_GetHeight (page) - 50, page_title);
    HPDF_Page_EndText (page);
    HPDF_Page_BeginText (page);
    HPDF_Page_MoveTextPos (page, 60, HPDF_Page_GetHeight(page) - 60);
    HPDF_Page_EndText (page);

<<<<<<< HEAD
    HPDF_Page_SetFontAndSize(page, font, fsize);
    HPDF_Page_SetLineWidth (page, 2);
    while(tags[cont][0] != 0){
        ypos -= 30;
        guarda = consultar_doc(cont, codigo);
        show_description (page,  60, ypos, guarda);
        HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
        HPDF_Page_BeginText (page);
        HPDF_Page_TextOut (page, 60, ypos, tags[cont]);
        HPDF_Page_EndText (page);

        HPDF_Page_SetFontAndSize(page, font, fsize);
        HPDF_Page_SetLineWidth (page, 2);
        cont ++;
    }
=======
    // Font rendering mode
    HPDF_Page_SetFontAndSize(page, font, fsize);
    HPDF_Page_SetLineWidth (page, 2);
    while(tags[cont][0] != 0){
        guarda = consultar_doc(cont, codigo);
        show_description (page,  60, ypos - 30, guarda);
        HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
        HPDF_Page_BeginText (page);
        HPDF_Page_TextOut (page, 60, ypos, tags[cont]);
        HPDF_Page_EndText (page);

        HPDF_Page_SetFontAndSize(page, font, fsize);
        HPDF_Page_SetLineWidth (page, 2);
     // PDF_FILL
    }
    /*
    show_description (page,  60, ypos, "01");
    HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_BeginText (page);
    HPDF_Page_TextOut (page, 60, ypos, "Identificador");
    HPDF_Page_EndText (page);

    HPDF_Page_SetFontAndSize(page, font, fsize);
    HPDF_Page_SetLineWidth (page, 2);


     // PDF_FILL
    show_description (page,  60, ypos - 30, "01/09/2020 12:09:50");
    HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_BeginText (page);
    HPDF_Page_TextOut (page, 60, ypos - 30, "Fecha Y Hora de Reservacion");
    HPDF_Page_EndText (page);
    HPDF_Page_SetFontAndSize(page, font, fsize);
    HPDF_Page_SetLineWidth (page, 2);

    show_description (page,  60, ypos - 60, "Vuelos de Prueba, Central: Hawaii");
    HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_BeginText (page);
    HPDF_Page_TextOut (page, 60, ypos - 60, "Informacion de la Aerolinea");
    HPDF_Page_EndText (page);
    HPDF_Page_SetFontAndSize(page, font, fsize);
    HPDF_Page_SetLineWidth (page, 2);

    show_description (page,  60, ypos - 90, "1CDE87");
    HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_BeginText (page);
    HPDF_Page_TextOut (page, 60, ypos - 90, "Codigo de Vuelo");
    HPDF_Page_EndText (page);
    HPDF_Page_SetFontAndSize(page, font, fsize);
    HPDF_Page_SetLineWidth (page, 2);

    show_description (page,  60, ypos - 120, "Costa Rica, 22/09/2020");
    HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_BeginText (page);
    HPDF_Page_TextOut (page, 60, ypos - 120, "Lugar y Fecha de salida");
    HPDF_Page_EndText (page);
    HPDF_Page_SetFontAndSize(page, font, fsize);
    HPDF_Page_SetLineWidth (page, 2);

    show_description (page,  60, ypos - 150, "Estados Unidos, 23/09/2020");
    HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_BeginText (page);
    HPDF_Page_TextOut (page, 60, ypos - 150, "Lugar y Fecha de arribo");
    HPDF_Page_EndText (page);
    HPDF_Page_SetFontAndSize(page, font, fsize);
    HPDF_Page_SetLineWidth (page, 2);

    show_description (page,  60, ypos - 180, "3E, 3D");
    HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_BeginText (page);
    HPDF_Page_TextOut (page, 60, ypos - 180, "Numero de asientos de la reservacion");
    HPDF_Page_EndText (page);
    HPDF_Page_SetFontAndSize(page, font, fsize);
    HPDF_Page_SetLineWidth (page, 2);

    show_description (page,  60, ypos - 210, "Lupe Verga, Yolando Parada");
    HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_BeginText (page);
    HPDF_Page_TextOut (page, 60, ypos - 210, "Personas de la reservacion");
    HPDF_Page_EndText (page);
    HPDF_Page_SetFontAndSize(page, font, fsize);
    HPDF_Page_SetLineWidth (page, 2);

    show_description (page,  60, ypos - 240, "1200356.56");
    HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_BeginText (page);
    HPDF_Page_TextOut (page, 60, ypos - 240, "Monto de la reservacion");
    HPDF_Page_EndText (page);
    HPDF_Page_SetFontAndSize(page, font, fsize);
    HPDF_Page_SetLineWidth (page, 2);*/
>>>>>>> 7affd9cf8a84542ea487a4488761d4fe0252459e
    HPDF_SaveToFile (pdf, fname);
    HPDF_Free (pdf);
    return 0;
}
