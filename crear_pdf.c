#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <setjmp.h>
#include "hpdf.h"
#include "aerolinea.h"

jmp_buf env;

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

    HPDF_Doc  pdf;
    HPDF_Font font;
    HPDF_Page page;
    char fname[256] = "Comprobante";
    float tw;
    float fsize = 12;
    int i;
    int len;
    float angle1;
    float angle2;
    float rad1;
    float rad2;
    float ypos = 760;

    //strcpy (fname, argv[0])
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

    // set compression mode
    HPDF_SetCompressionMode (pdf, HPDF_COMP_ALL);

    // create default-font
    font = HPDF_GetFont (pdf, "Helvetica", NULL);

    // add a new page object.
    page = HPDF_AddPage (pdf);

    // draw grid to the page
    print_grid  (pdf, page);

    // print the title of the page (with positioning center).
    HPDF_Page_SetFontAndSize (page, font, 18);
    tw = HPDF_Page_TextWidth (page, page_title);
    HPDF_Page_BeginText (page);
    HPDF_Page_TextOut (page, (HPDF_Page_GetWidth(page) - tw) / 2, HPDF_Page_GetHeight (page) - 50, page_title);
    HPDF_Page_EndText (page);
    HPDF_Page_BeginText (page);
    HPDF_Page_MoveTextPos (page, 60, HPDF_Page_GetHeight(page) - 60);
    HPDF_Page_EndText (page);

    // Font rendering mode
    HPDF_Page_SetFontAndSize(page, font, fsize);
    HPDF_Page_SetLineWidth (page, 2);

     // PDF_FILL
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
    HPDF_Page_SetLineWidth (page, 2);
    HPDF_SaveToFile (pdf, fname);

    /* clean up */
    HPDF_Free (pdf);

    return 0;
}
