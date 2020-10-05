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

int crear_doc (char * codigo){
    const char *page_title = "Comprobante";
    char tags[10][40] = {"Identificador", "Fecha Y Hora de Reservacion", "Informacion de la Aerolinea", 
                    "Codigo de Vuelo", "Lugar y Fecha de salida", "Lugar y Fecha de arribo",
                    "Numero de asientos de la reservacion", "Personas de la reservacion", 
                    "Monto de la reservacion"};
    HPDF_Doc  pdf;
    HPDF_Font font;
    HPDF_Page page;
    char fname[256];
    float tw;
    float fsize = 12;
    int cont = 0;
    float ypos = 790;
    char * guarda;
    strcat(fname, codigo);
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
    HPDF_SaveToFile (pdf, fname);
    HPDF_Free (pdf);
    return 0;
}
