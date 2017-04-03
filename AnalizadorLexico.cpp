#include "AnalizadorLexico.h"
#include <fstream>


AnalizadorLexico::AnalizadorLexico(const char * file, list<QString> * warnings, list<QString> * errores, TablaDeSimbolos *ts) {
    lineas=1;
    entrada.clear();
    tokensReconocidos.clear();
    palabrasReservadas.clear();
    tablaDeSimbolos = ts;
    (this->warnings)=warnings;
    (this->errores)=errores;


    /* Se carga el archivo a la lista */
    ifstream arch (file);
    if (!arch.is_open()) {
        error("No se pudo abrir el archivo. Debe pasarse como parametro a la aplicacion.");
    } else {
        char c;
        while (arch.get(c)) {
            entrada.push_back(c);
        }
        arch.close();
    }

    inicializarPR();
    inicializarMatrizAs();

}

int AnalizadorLexico::lineaActual()
{
 return lineas;
}



void AnalizadorLexico::error(string str)
{
    cout << "\n\nERROR: " << str << "\n\n\n" ;
    exit(-1);
}

void AnalizadorLexico::inicializarMatrizAs(){


    /* Fila 0 */
        matrizAS[0][0]=&AnalizadorLexico::accionSA;
        matrizAS[0][1]=&AnalizadorLexico::accionSA;
        matrizAS[0][2]=&AnalizadorLexico::accionSA;
        matrizAS[0][3]=&AnalizadorLexico::accionSA;
        matrizAS[0][4]=&AnalizadorLexico::accionSA;
        matrizAS[0][5]=&AnalizadorLexico::accionSA;
        matrizAS[0][6]=&AnalizadorLexico::accionSA;
        matrizAS[0][7]=&AnalizadorLexico::accionSA;
        matrizAS[0][8]=&AnalizadorLexico::accionSA;
        matrizAS[0][9]=&AnalizadorLexico::accionSA;
        matrizAS[0][10]=&AnalizadorLexico::accionSA;
        matrizAS[0][11]=&AnalizadorLexico::accionSV;
        matrizAS[0][12]=&AnalizadorLexico::accionSL;
        matrizAS[0][13]=&AnalizadorLexico::accionSA;
        matrizAS[0][14]=&AnalizadorLexico::accionSA;
        matrizAS[0][15]=&AnalizadorLexico::accionSTI;
        matrizAS[0][16]=&AnalizadorLexico::accionSA;
        matrizAS[0][17]=&AnalizadorLexico::accionSA;
        matrizAS[0][18]=&AnalizadorLexico::accionSA;
        matrizAS[0][19]=&AnalizadorLexico::accionSV;
        matrizAS[0][20]=&AnalizadorLexico::accionSV;

    /* Fila 1 */
        matrizAS[1][0]=&AnalizadorLexico::accionSEI;
        matrizAS[1][1]=&AnalizadorLexico::accionSA;
        matrizAS[1][2]=&AnalizadorLexico::accionSEI;
        matrizAS[1][3]=&AnalizadorLexico::accionSEI;
        matrizAS[1][4]=&AnalizadorLexico::accionSEI;
        matrizAS[1][5]=&AnalizadorLexico::accionSEI;
        matrizAS[1][6]=&AnalizadorLexico::accionSEI;
        matrizAS[1][7]=&AnalizadorLexico::accionSEI;
        matrizAS[1][8]=&AnalizadorLexico::accionSEI;
        matrizAS[1][9]=&AnalizadorLexico::accionSEI;
        matrizAS[1][10]=&AnalizadorLexico::accionSEI;
        matrizAS[1][11]=&AnalizadorLexico::accionSEI;
        matrizAS[1][12]=&AnalizadorLexico::accionSEI;
        matrizAS[1][13]=&AnalizadorLexico::accionSA;
        matrizAS[1][14]=&AnalizadorLexico::accionSEI;
        matrizAS[1][15]=&AnalizadorLexico::accionSEI;
        matrizAS[1][16]=&AnalizadorLexico::accionSA;
        matrizAS[1][17]=&AnalizadorLexico::accionSEI;
        matrizAS[1][18]=&AnalizadorLexico::accionSEI;
        matrizAS[1][19]=&AnalizadorLexico::accionSEI;
        matrizAS[1][20]=&AnalizadorLexico::accionSEI;

    /* Fila 2 */
        matrizAS[2][0]=&AnalizadorLexico::accionSA;
        matrizAS[2][1]=&AnalizadorLexico::accionSA;
        matrizAS[2][2]=&AnalizadorLexico::accionSA;
        matrizAS[2][3]=&AnalizadorLexico::accionS1;
        matrizAS[2][4]=&AnalizadorLexico::accionS1;
        matrizAS[2][5]=&AnalizadorLexico::accionS1;
        matrizAS[2][6]=&AnalizadorLexico::accionS1;
        matrizAS[2][7]=&AnalizadorLexico::accionS1;
        matrizAS[2][8]=&AnalizadorLexico::accionS1;
        matrizAS[2][9]=&AnalizadorLexico::accionS1;
        matrizAS[2][10]=&AnalizadorLexico::accionS1;
        matrizAS[2][11]=&AnalizadorLexico::accionS1;
        matrizAS[2][12]=&AnalizadorLexico::accionS1;
        matrizAS[2][13]=&AnalizadorLexico::accionSA;
        matrizAS[2][14]=&AnalizadorLexico::accionS1;
        matrizAS[2][15]=&AnalizadorLexico::accionS1;
        matrizAS[2][16]=&AnalizadorLexico::accionSA;
        matrizAS[2][17]=&AnalizadorLexico::accionS1;
        matrizAS[2][18]=&AnalizadorLexico::accionS1;
        matrizAS[2][19]=&AnalizadorLexico::accionS1F;
        matrizAS[2][20]=&AnalizadorLexico::accionS1;

    /* Fila 3 */
        matrizAS[3][0]=&AnalizadorLexico::accionSECTE;
        matrizAS[3][1]=&AnalizadorLexico::accionSECTE;
        matrizAS[3][2]=&AnalizadorLexico::accionSA;
        matrizAS[3][3]=&AnalizadorLexico::accionSECTE;
        matrizAS[3][4]=&AnalizadorLexico::accionSECTE;
        matrizAS[3][5]=&AnalizadorLexico::accionSECTE;
        matrizAS[3][6]=&AnalizadorLexico::accionSECTE;
        matrizAS[3][7]=&AnalizadorLexico::accionSECTE;
        matrizAS[3][8]=&AnalizadorLexico::accionSECTE;
        matrizAS[3][9]=&AnalizadorLexico::accionSECTE;
        matrizAS[3][10]=&AnalizadorLexico::accionSECTE;
        matrizAS[3][11]=&AnalizadorLexico::accionSECTE;
        matrizAS[3][12]=&AnalizadorLexico::accionSECTE;
        matrizAS[3][13]=&AnalizadorLexico::accionSA;
        matrizAS[3][14]=&AnalizadorLexico::accionSA;
        matrizAS[3][15]=&AnalizadorLexico::accionSA;
        matrizAS[3][16]=&AnalizadorLexico::accionSECTE;
        matrizAS[3][17]=&AnalizadorLexico::accionSA;
        matrizAS[3][18]=&AnalizadorLexico::accionSECTE;
        matrizAS[3][19]=&AnalizadorLexico::accionSECTE;
        matrizAS[3][20]=&AnalizadorLexico::accionSECTE;

    /* Fila 4 */
        matrizAS[4][0]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][1]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][2]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][3]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][4]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][5]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][6]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][7]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][8]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][9]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][10]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][11]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][12]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][13]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][14]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][15]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][16]=&AnalizadorLexico::accionS3;
        matrizAS[4][17]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][18]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][19]=&AnalizadorLexico::accionSECTE;
        matrizAS[4][20]=&AnalizadorLexico::accionSECTE;

    /* Fila 5 */
        matrizAS[5][0]=&AnalizadorLexico::accionS2;
        matrizAS[5][1]=&AnalizadorLexico::accionS2;
        matrizAS[5][2]=&AnalizadorLexico::accionS2;
        matrizAS[5][3]=&AnalizadorLexico::accionSA;
        matrizAS[5][4]=&AnalizadorLexico::accionS2;
        matrizAS[5][5]=&AnalizadorLexico::accionS2;
        matrizAS[5][6]=&AnalizadorLexico::accionS2;
        matrizAS[5][7]=&AnalizadorLexico::accionS2;
        matrizAS[5][8]=&AnalizadorLexico::accionS2;
        matrizAS[5][9]=&AnalizadorLexico::accionS2;
        matrizAS[5][10]=&AnalizadorLexico::accionS2;
        matrizAS[5][11]=&AnalizadorLexico::accionS2;
        matrizAS[5][12]=&AnalizadorLexico::accionS2;
        matrizAS[5][13]=&AnalizadorLexico::accionS2;
        matrizAS[5][14]=&AnalizadorLexico::accionSA;
        matrizAS[5][15]=&AnalizadorLexico::accionS2;
        matrizAS[5][16]=&AnalizadorLexico::accionS2;
        matrizAS[5][17]=&AnalizadorLexico::accionS2;
        matrizAS[5][18]=&AnalizadorLexico::accionS2;
        matrizAS[5][19]=&AnalizadorLexico::accionS2F;
        matrizAS[5][20]=&AnalizadorLexico::accionS2;

    /* Fila 6 */
        matrizAS[6][0]=&AnalizadorLexico::accionS5;
        matrizAS[6][1]=&AnalizadorLexico::accionS5;
        matrizAS[6][2]=&AnalizadorLexico::accionS5;
        matrizAS[6][3]=&AnalizadorLexico::accionS5;
        matrizAS[6][4]=&AnalizadorLexico::accionS5;
        matrizAS[6][5]=&AnalizadorLexico::accionS5;
        matrizAS[6][6]=&AnalizadorLexico::accionS5;
        matrizAS[6][7]=&AnalizadorLexico::accionS5;
        matrizAS[6][8]=&AnalizadorLexico::accionS5;
        matrizAS[6][9]=&AnalizadorLexico::accionS5;
        matrizAS[6][10]=&AnalizadorLexico::accionS5;
        matrizAS[6][11]=&AnalizadorLexico::accionS5;
        matrizAS[6][12]=&AnalizadorLexico::accionS5;
        matrizAS[6][13]=&AnalizadorLexico::accionS5;
        matrizAS[6][14]=&AnalizadorLexico::accionS5;
        matrizAS[6][15]=&AnalizadorLexico::accionS5;
        matrizAS[6][16]=&AnalizadorLexico::accionS5;
        matrizAS[6][17]=&AnalizadorLexico::accionS5;
        matrizAS[6][18]=&AnalizadorLexico::accionS5;
        matrizAS[6][19]=&AnalizadorLexico::accionS5F;
        matrizAS[6][20]=&AnalizadorLexico::accionS5;

    /* Fila 7 */
        matrizAS[7][0]=&AnalizadorLexico::accionS5;
        matrizAS[7][1]=&AnalizadorLexico::accionS5;
        matrizAS[7][2]=&AnalizadorLexico::accionS5;
        matrizAS[7][3]=&AnalizadorLexico::accionS5;
        matrizAS[7][4]=&AnalizadorLexico::accionS5;
        matrizAS[7][5]=&AnalizadorLexico::accionS5;
        matrizAS[7][6]=&AnalizadorLexico::accionS4;
        matrizAS[7][7]=&AnalizadorLexico::accionS5;
        matrizAS[7][8]=&AnalizadorLexico::accionS5;
        matrizAS[7][9]=&AnalizadorLexico::accionS5;
        matrizAS[7][10]=&AnalizadorLexico::accionS5;
        matrizAS[7][11]=&AnalizadorLexico::accionS5;
        matrizAS[7][12]=&AnalizadorLexico::accionS5;
        matrizAS[7][13]=&AnalizadorLexico::accionS5;
        matrizAS[7][14]=&AnalizadorLexico::accionS5;
        matrizAS[7][15]=&AnalizadorLexico::accionS5;
        matrizAS[7][16]=&AnalizadorLexico::accionS5;
        matrizAS[7][17]=&AnalizadorLexico::accionS5;
        matrizAS[7][18]=&AnalizadorLexico::accionS5;
        matrizAS[7][19]=&AnalizadorLexico::accionS5F;
        matrizAS[7][20]=&AnalizadorLexico::accionS5;

    /* Fila 8 */
        matrizAS[8][0]=&AnalizadorLexico::accionS5;
        matrizAS[8][1]=&AnalizadorLexico::accionS5;
        matrizAS[8][2]=&AnalizadorLexico::accionS5;
        matrizAS[8][3]=&AnalizadorLexico::accionS5;
        matrizAS[8][4]=&AnalizadorLexico::accionS5;
        matrizAS[8][5]=&AnalizadorLexico::accionS5;
        matrizAS[8][6]=&AnalizadorLexico::accionS4;
        matrizAS[8][7]=&AnalizadorLexico::accionS5;
        matrizAS[8][8]=&AnalizadorLexico::accionS4;
        matrizAS[8][9]=&AnalizadorLexico::accionS5;
        matrizAS[8][10]=&AnalizadorLexico::accionS5;
        matrizAS[8][11]=&AnalizadorLexico::accionS5;
        matrizAS[8][12]=&AnalizadorLexico::accionS5;
        matrizAS[8][13]=&AnalizadorLexico::accionS5;
        matrizAS[8][14]=&AnalizadorLexico::accionS5;
        matrizAS[8][15]=&AnalizadorLexico::accionS5;
        matrizAS[8][16]=&AnalizadorLexico::accionS5;
        matrizAS[8][17]=&AnalizadorLexico::accionS5;
        matrizAS[8][18]=&AnalizadorLexico::accionS5;
        matrizAS[8][19]=&AnalizadorLexico::accionS5F;
        matrizAS[8][20]=&AnalizadorLexico::accionS5;

    /* Fila 9 */
        matrizAS[9][0]=&AnalizadorLexico::accionS5;
        matrizAS[9][1]=&AnalizadorLexico::accionS5;
        matrizAS[9][2]=&AnalizadorLexico::accionS5;
        matrizAS[9][3]=&AnalizadorLexico::accionS5;
        matrizAS[9][4]=&AnalizadorLexico::accionS5;
        matrizAS[9][5]=&AnalizadorLexico::accionS5;
        matrizAS[9][6]=&AnalizadorLexico::accionS4;
        matrizAS[9][7]=&AnalizadorLexico::accionS5;
        matrizAS[9][8]=&AnalizadorLexico::accionS5;
        matrizAS[9][9]=&AnalizadorLexico::accionS5;
        matrizAS[9][10]=&AnalizadorLexico::accionS5;
        matrizAS[9][11]=&AnalizadorLexico::accionS5;
        matrizAS[9][12]=&AnalizadorLexico::accionS5;
        matrizAS[9][13]=&AnalizadorLexico::accionS5;
        matrizAS[9][14]=&AnalizadorLexico::accionS5;
        matrizAS[9][15]=&AnalizadorLexico::accionS5;
        matrizAS[9][16]=&AnalizadorLexico::accionS5;
        matrizAS[9][17]=&AnalizadorLexico::accionS5;
        matrizAS[9][18]=&AnalizadorLexico::accionS5;
        matrizAS[9][19]=&AnalizadorLexico::accionS5F;
        matrizAS[9][20]=&AnalizadorLexico::accionS5;

    /* Fila 10 */
        matrizAS[10][0]=&AnalizadorLexico::accionS5;
        matrizAS[10][1]=&AnalizadorLexico::accionS5;
        matrizAS[10][2]=&AnalizadorLexico::accionS5;
        matrizAS[10][3]=&AnalizadorLexico::accionS5;
        matrizAS[10][4]=&AnalizadorLexico::accionS5;
        matrizAS[10][5]=&AnalizadorLexico::accionS5;
        matrizAS[10][6]=&AnalizadorLexico::accionS5;
        matrizAS[10][7]=&AnalizadorLexico::accionS5;
        matrizAS[10][8]=&AnalizadorLexico::accionS5;
        matrizAS[10][9]=&AnalizadorLexico::accionS5;
        matrizAS[10][10]=&AnalizadorLexico::accionS5;
        matrizAS[10][11]=&AnalizadorLexico::accionS5;
        matrizAS[10][12]=&AnalizadorLexico::accionS5;
        matrizAS[10][13]=&AnalizadorLexico::accionS5;
        matrizAS[10][14]=&AnalizadorLexico::accionS5;
        matrizAS[10][15]=&AnalizadorLexico::accionS5;
        matrizAS[10][16]=&AnalizadorLexico::accionS5;
        matrizAS[10][17]=&AnalizadorLexico::accionS5;
        matrizAS[10][18]=&AnalizadorLexico::accionS5;
        matrizAS[10][19]=&AnalizadorLexico::accionS5F;
        matrizAS[10][20]=&AnalizadorLexico::accionS5;

    /* Fila 11 */
        matrizAS[11][0]=&AnalizadorLexico::accionS5;
        matrizAS[11][1]=&AnalizadorLexico::accionS5;
        matrizAS[11][2]=&AnalizadorLexico::accionS5;
        matrizAS[11][3]=&AnalizadorLexico::accionS5;
        matrizAS[11][4]=&AnalizadorLexico::accionS5;
        matrizAS[11][5]=&AnalizadorLexico::accionS5;
        matrizAS[11][6]=&AnalizadorLexico::accionS5;
        matrizAS[11][7]=&AnalizadorLexico::accionS5;
        matrizAS[11][8]=&AnalizadorLexico::accionS5;
        matrizAS[11][9]=&AnalizadorLexico::accionS5;
        matrizAS[11][10]=&AnalizadorLexico::accionSV;
        matrizAS[11][11]=&AnalizadorLexico::accionS5;
        matrizAS[11][12]=&AnalizadorLexico::accionS5;
        matrizAS[11][13]=&AnalizadorLexico::accionS5;
        matrizAS[11][14]=&AnalizadorLexico::accionS5;
        matrizAS[11][15]=&AnalizadorLexico::accionS5;
        matrizAS[11][16]=&AnalizadorLexico::accionS5;
        matrizAS[11][17]=&AnalizadorLexico::accionS5;
        matrizAS[11][18]=&AnalizadorLexico::accionS5;
        matrizAS[11][19]=&AnalizadorLexico::accionS5F;
        matrizAS[11][20]=&AnalizadorLexico::accionS5;

    /* Fila 12 */
        matrizAS[12][0]=&AnalizadorLexico::accionSV;
        matrizAS[12][1]=&AnalizadorLexico::accionSV;
        matrizAS[12][2]=&AnalizadorLexico::accionSV;
        matrizAS[12][3]=&AnalizadorLexico::accionSV;
        matrizAS[12][4]=&AnalizadorLexico::accionSV;
        matrizAS[12][5]=&AnalizadorLexico::accionSV;
        matrizAS[12][6]=&AnalizadorLexico::accionSV;
        matrizAS[12][7]=&AnalizadorLexico::accionSV;
        matrizAS[12][8]=&AnalizadorLexico::accionSV;
        matrizAS[12][9]=&AnalizadorLexico::accionSV;
        matrizAS[12][10]=&AnalizadorLexico::accionSV;
        matrizAS[12][11]=&AnalizadorLexico::accionSV;
        matrizAS[12][12]=&AnalizadorLexico::accionSL;
        matrizAS[12][13]=&AnalizadorLexico::accionSV;
        matrizAS[12][14]=&AnalizadorLexico::accionSV;
        matrizAS[12][15]=&AnalizadorLexico::accionSV;
        matrizAS[12][16]=&AnalizadorLexico::accionSV;
        matrizAS[12][17]=&AnalizadorLexico::accionSV;
        matrizAS[12][18]=&AnalizadorLexico::accionSV;
        matrizAS[12][19]=&AnalizadorLexico::accionSECOM;
        matrizAS[12][20]=&AnalizadorLexico::accionSV;

    /* Fila 13 */
        matrizAS[13][0]=&AnalizadorLexico::accionSV;
        matrizAS[13][1]=&AnalizadorLexico::accionSV;
        matrizAS[13][2]=&AnalizadorLexico::accionSV;
        matrizAS[13][3]=&AnalizadorLexico::accionSV;
        matrizAS[13][4]=&AnalizadorLexico::accionSV;
        matrizAS[13][5]=&AnalizadorLexico::accionSV;
        matrizAS[13][6]=&AnalizadorLexico::accionSV;
        matrizAS[13][7]=&AnalizadorLexico::accionSV;
        matrizAS[13][8]=&AnalizadorLexico::accionSV;
        matrizAS[13][9]=&AnalizadorLexico::accionSV;
        matrizAS[13][10]=&AnalizadorLexico::accionSV;
        matrizAS[13][11]=&AnalizadorLexico::accionSV;
        matrizAS[13][12]=&AnalizadorLexico::accionSL;
        matrizAS[13][13]=&AnalizadorLexico::accionSV;
        matrizAS[13][14]=&AnalizadorLexico::accionSV;
        matrizAS[13][15]=&AnalizadorLexico::accionSV;
        matrizAS[13][16]=&AnalizadorLexico::accionSV;
        matrizAS[13][17]=&AnalizadorLexico::accionSV;
        matrizAS[13][18]=&AnalizadorLexico::accionSV;
        matrizAS[13][19]=&AnalizadorLexico::accionSECOM;
        matrizAS[13][20]=&AnalizadorLexico::accionSV;

    /* Fila 14 */
        matrizAS[14][0]=&AnalizadorLexico::accionS6;
        matrizAS[14][1]=&AnalizadorLexico::accionS6;
        matrizAS[14][2]=&AnalizadorLexico::accionSA;
        matrizAS[14][3]=&AnalizadorLexico::accionS6;
        matrizAS[14][4]=&AnalizadorLexico::accionS6;
        matrizAS[14][5]=&AnalizadorLexico::accionS6;
        matrizAS[14][6]=&AnalizadorLexico::accionS6;
        matrizAS[14][7]=&AnalizadorLexico::accionS6;
        matrizAS[14][8]=&AnalizadorLexico::accionS6;
        matrizAS[14][9]=&AnalizadorLexico::accionS6;
        matrizAS[14][10]=&AnalizadorLexico::accionS6;
        matrizAS[14][11]=&AnalizadorLexico::accionS6;
        matrizAS[14][12]=&AnalizadorLexico::accionS6;
        matrizAS[14][13]=&AnalizadorLexico::accionSA;
        matrizAS[14][14]=&AnalizadorLexico::accionSA;
        matrizAS[14][15]=&AnalizadorLexico::accionS6;
        matrizAS[14][16]=&AnalizadorLexico::accionS6;
        matrizAS[14][17]=&AnalizadorLexico::accionS6;
        matrizAS[14][18]=&AnalizadorLexico::accionS6;
        matrizAS[14][19]=&AnalizadorLexico::accionS6F;
        matrizAS[14][20]=&AnalizadorLexico::accionS6;

    /* Fila 15 */
        matrizAS[15][0]=&AnalizadorLexico::accionSEF;
        matrizAS[15][1]=&AnalizadorLexico::accionSEF;
        matrizAS[15][2]=&AnalizadorLexico::accionSA;
        matrizAS[15][3]=&AnalizadorLexico::accionSEF;
        matrizAS[15][4]=&AnalizadorLexico::accionSA;
        matrizAS[15][5]=&AnalizadorLexico::accionSEF;
        matrizAS[15][6]=&AnalizadorLexico::accionSEF;
        matrizAS[15][7]=&AnalizadorLexico::accionSEF;
        matrizAS[15][8]=&AnalizadorLexico::accionSEF;
        matrizAS[15][9]=&AnalizadorLexico::accionSEF;
        matrizAS[15][10]=&AnalizadorLexico::accionSEF;
        matrizAS[15][11]=&AnalizadorLexico::accionSEF;
        matrizAS[15][12]=&AnalizadorLexico::accionSEF;
        matrizAS[15][13]=&AnalizadorLexico::accionSEF;
        matrizAS[15][14]=&AnalizadorLexico::accionSEF;
        matrizAS[15][15]=&AnalizadorLexico::accionSEF;
        matrizAS[15][16]=&AnalizadorLexico::accionSEF;
        matrizAS[15][17]=&AnalizadorLexico::accionSEF;
        matrizAS[15][18]=&AnalizadorLexico::accionSEF;
        matrizAS[15][19]=&AnalizadorLexico::accionSEF;
        matrizAS[15][20]=&AnalizadorLexico::accionSEF;

    /* Fila 16 */
        matrizAS[16][0]=&AnalizadorLexico::accionS6;
        matrizAS[16][1]=&AnalizadorLexico::accionS6;
        matrizAS[16][2]=&AnalizadorLexico::accionSA;
        matrizAS[16][3]=&AnalizadorLexico::accionS6;
        matrizAS[16][4]=&AnalizadorLexico::accionS6;
        matrizAS[16][5]=&AnalizadorLexico::accionS6;
        matrizAS[16][6]=&AnalizadorLexico::accionS6;
        matrizAS[16][7]=&AnalizadorLexico::accionS6;
        matrizAS[16][8]=&AnalizadorLexico::accionS6;
        matrizAS[16][9]=&AnalizadorLexico::accionS6;
        matrizAS[16][10]=&AnalizadorLexico::accionS6;
        matrizAS[16][11]=&AnalizadorLexico::accionS6;
        matrizAS[16][12]=&AnalizadorLexico::accionS6;
        matrizAS[16][13]=&AnalizadorLexico::accionS6;
        matrizAS[16][14]=&AnalizadorLexico::accionS6;
        matrizAS[16][15]=&AnalizadorLexico::accionS6;
        matrizAS[16][16]=&AnalizadorLexico::accionS6;
        matrizAS[16][17]=&AnalizadorLexico::accionS6;
        matrizAS[16][18]=&AnalizadorLexico::accionS6;
        matrizAS[16][19]=&AnalizadorLexico::accionS6F;
        matrizAS[16][20]=&AnalizadorLexico::accionS6;

    /* Fila 17 */
        matrizAS[17][0]=&AnalizadorLexico::accionSEF;
        matrizAS[17][1]=&AnalizadorLexico::accionSEF;
        matrizAS[17][2]=&AnalizadorLexico::accionSA;
        matrizAS[17][3]=&AnalizadorLexico::accionSEF;
        matrizAS[17][4]=&AnalizadorLexico::accionSEF;
        matrizAS[17][5]=&AnalizadorLexico::accionSEF;
        matrizAS[17][6]=&AnalizadorLexico::accionSEF;
        matrizAS[17][7]=&AnalizadorLexico::accionSEF;
        matrizAS[17][8]=&AnalizadorLexico::accionSEF;
        matrizAS[17][9]=&AnalizadorLexico::accionSEF;
        matrizAS[17][10]=&AnalizadorLexico::accionSEF;
        matrizAS[17][11]=&AnalizadorLexico::accionSEF;
        matrizAS[17][12]=&AnalizadorLexico::accionSEF;
        matrizAS[17][13]=&AnalizadorLexico::accionSEF;
        matrizAS[17][14]=&AnalizadorLexico::accionSEF;
        matrizAS[17][15]=&AnalizadorLexico::accionSEF;
        matrizAS[17][16]=&AnalizadorLexico::accionSEF;
        matrizAS[17][17]=&AnalizadorLexico::accionSEF;
        matrizAS[17][18]=&AnalizadorLexico::accionSEF;
        matrizAS[17][19]=&AnalizadorLexico::accionSEF;
        matrizAS[17][20]=&AnalizadorLexico::accionSEF;

    /* Fila 18 */
        matrizAS[18][0]=&AnalizadorLexico::accionSA;
        matrizAS[18][1]=&AnalizadorLexico::accionSA;
        matrizAS[18][2]=&AnalizadorLexico::accionSA;
        matrizAS[18][3]=&AnalizadorLexico::accionSA;
        matrizAS[18][4]=&AnalizadorLexico::accionSA;
        matrizAS[18][5]=&AnalizadorLexico::accionSA;
        matrizAS[18][6]=&AnalizadorLexico::accionSA;
        matrizAS[18][7]=&AnalizadorLexico::accionSA;
        matrizAS[18][8]=&AnalizadorLexico::accionSA;
        matrizAS[18][9]=&AnalizadorLexico::accionSA;
        matrizAS[18][10]=&AnalizadorLexico::accionSA;
        matrizAS[18][11]=&AnalizadorLexico::accionSA;
        matrizAS[18][12]=&AnalizadorLexico::accionSEC;
        matrizAS[18][13]=&AnalizadorLexico::accionSA;
        matrizAS[18][14]=&AnalizadorLexico::accionSA;
        matrizAS[18][15]=&AnalizadorLexico::accionSA;
        matrizAS[18][16]=&AnalizadorLexico::accionSA;
        matrizAS[18][17]=&AnalizadorLexico::accionSA;
        matrizAS[18][18]=&AnalizadorLexico::accionS7;
        matrizAS[18][19]=&AnalizadorLexico::accionSEC;
        matrizAS[18][20]=&AnalizadorLexico::accionSA;

    /* Fila 19 */
        matrizAS[19][0]=&AnalizadorLexico::accionSEF;
        matrizAS[19][1]=&AnalizadorLexico::accionSEF;
        matrizAS[19][2]=&AnalizadorLexico::accionSA;
        matrizAS[19][3]=&AnalizadorLexico::accionSEF;
        matrizAS[19][4]=&AnalizadorLexico::accionSEF;
        matrizAS[19][5]=&AnalizadorLexico::accionSEF;
        matrizAS[19][6]=&AnalizadorLexico::accionSEF;
        matrizAS[19][7]=&AnalizadorLexico::accionSEF;
        matrizAS[19][8]=&AnalizadorLexico::accionSEF;
        matrizAS[19][9]=&AnalizadorLexico::accionSEF;
        matrizAS[19][10]=&AnalizadorLexico::accionSEF;
        matrizAS[19][11]=&AnalizadorLexico::accionSEF;
        matrizAS[19][12]=&AnalizadorLexico::accionSEF;
        matrizAS[19][13]=&AnalizadorLexico::accionSA;
        matrizAS[19][14]=&AnalizadorLexico::accionSA;
        matrizAS[19][15]=&AnalizadorLexico::accionSEF;
        matrizAS[19][16]=&AnalizadorLexico::accionSEF;
        matrizAS[19][17]=&AnalizadorLexico::accionSEF;
        matrizAS[19][18]=&AnalizadorLexico::accionSEF;
        matrizAS[19][19]=&AnalizadorLexico::accionSEF;
        matrizAS[19][20]=&AnalizadorLexico::accionSEF;

}

void AnalizadorLexico::inicializarPR(){
    palabrasReservadas.insert("IF", IF);
    palabrasReservadas.insert("THEN", THEN);
    palabrasReservadas.insert("ELSE", ELSE);
    palabrasReservadas.insert("ENDIF", ENDIF);
    palabrasReservadas.insert("PRINT", PRINT);
    palabrasReservadas.insert("INT", INT);
    palabrasReservadas.insert("BEGIN", BEGIN);
    palabrasReservadas.insert("END", END);
    palabrasReservadas.insert("FLOAT", FLOAT);
    palabrasReservadas.insert("GLOBAL", GLOBAL);
    palabrasReservadas.insert("LOOP", LOOP);
    palabrasReservadas.insert("UNTIL", UNTIL);
    palabrasReservadas.insert("TOFLOAT", TOFLOAT);

}

int AnalizadorLexico::columna(char c) {
    switch(c) {
        case '@':
            return 0;
        case '+':
            return 4;
        case '-':
            return 4;
        case '*':
            return 5;
        case '=':
            return 6;
        case '<':
            return 7;
        case '>':
            return 8;
        case '{':
            return 9;
        case '}':
            return 9;
        case '(':
            return 9;
        case ')':
            return 9;
        case ',':
            return 9;
        case ';':
            return 9;
        case '/':
            return 10;
        case ' ':
            return 11;
        case '\t':
            return 11;
        case '\n':
            return 12;
        case 'e':
            return 13;
        case 'E':
            return 14;
        case '_':
            return 15;
        case 'i':
            return 16;
        case '.':
            return 17;
        case '\'':
            return 18;
        default:
            if (c >='a' && c <= 'z')
                return 1;
            else if (c >= 'A' && c <= 'Z')
                    return 3;
            else if (c >= '0' && c<= '9')
                    return 2;
            else
                return 20;
        ;
    }
}

/*Solo para facilitar la impresion final por pantalla*/

list<QString> AnalizadorLexico::getTokens()
{
  return tokensReconocidos;
}

/*Lo agrega a la lista que luego será impresa por pantalla */
void AnalizadorLexico::imprimirToken(QString *buffer, int devolucion)
{
    QString descripcion="";
    if (devolucion>=257) {
        if (devolucion <= 269)
            descripcion="Palabra reservada ";
        else if (devolucion==ID)
            descripcion="Identificador ";
        else if (devolucion==CTE) {
            EntradaTS * e = tablaDeSimbolos->value(*buffer);
            if (e->tipo=="INT") {
                descripcion="Constante entera ";
                buffer->truncate(buffer->size()-2);
            } else {
                descripcion="Constante flotante ";
            }
        }    
        else if (devolucion==CADENA)
            descripcion="Cadena ";
    }

    descripcion+=*buffer;
    descripcion+="\n";

    tokensReconocidos.push_back(descripcion);
}

AnalizadorLexico::~AnalizadorLexico()
{

}


/* Devuelve el siguiente token */

int AnalizadorLexico::yylex () {

    QString * buffer = new QString;
    int devolucion = TOKEN_INVALIDO;
    char c=0;
    int estado = 0;
    int columna = 0;

    while (estado!=F && columna!=FINARCHIVO) {

        if (entrada.empty()) {
            columna=FINARCHIVO;
        } else {
            c = entrada.front();
            entrada.pop_front();
            columna = this->columna(c);

        }

        //Ejecuta la accion semantica
        devolucion = (this->*matrizAS[estado][columna])(buffer,c);
        //Actualiza el estado actual
        estado = matrizTE [estado][columna];

        if (estado==FST || (estado==F && devolucion==TOKEN_INVALIDO)) {
            estado=0;
            buffer->clear();
        }
    } /*End While. Aca hay dos posibilidades: se llego a estado final con token valido,
       o se llego a fin de archivo*/

    if (estado==F) {
        imprimirToken(buffer, devolucion); //lo agrega a la lista de tokens reconocidos
        return devolucion;
    } else {
        return 0;
    }
}


extern QString yylval;


/*Acción semantica al reconocer identificador. Devuelve ultimo char y chequea longitud*/
int AnalizadorLexico::accionS1(QString *buffer, char c) {
    entrada.push_front(c); //devuelve el ultimo char
    return this->accionS1F(buffer,c);
}


/*Acción semantica al reconocer identificador sobre FINARCHIVO. No consume ni devuelve char*/
int AnalizadorLexico::accionS1F(QString *buffer, char c) {

    if (buffer->size() > 15) {
        QString msg = "\n Warning: Identificador de longitud mayor a 15. Ha sido truncado. (Linea: ";
        msg.append(QString::number(lineas));
        msg.append(").");
        warnings->push_back(msg);
        buffer->truncate(15);
    }

    /*Chequea si está en TS. Si no, lo da de alta */
    if (!tablaDeSimbolos->contiene(*buffer)) {
        EntradaTS * e = new EntradaTS(*buffer,"ID", ID);
        tablaDeSimbolos->insertar(*buffer, e);
    }

    yylval = tablaDeSimbolos->value(*buffer)->lexema;


    return ID;
}


/*Acción semantica al reconocer palabra reservada */

int AnalizadorLexico::accionS2(QString *buffer, char c) {
     entrada.push_front(c); //devuelve el ultimo char
     return this->accionS2F(buffer,c);
}


/*Acción semantica al reconocer palabra reservada sobre FINARCHIVO. */

int AnalizadorLexico::accionS2F(QString *buffer, char c) {
    if (!palabrasReservadas.contains(*buffer)) {
        QString msg = "\nError lexico: Palabra reservada invalida";
        msg.append("'");
        msg.append(*buffer);
        msg.append("'. (Linea: ");
        msg.append(QString::number(lineas));
        msg.append(").");
        errores->push_back(msg);
        return TOKEN_INVALIDO;
    }
    int token_id = palabrasReservadas.value(*buffer);


    return token_id;
}



/*Acción semantica al reconocer constante */

int AnalizadorLexico::accionS3(QString *buffer, char c) {

    buffer->push_back(c); //consume el ultimo char

    int size = (buffer->size())-2;
    QString aux (*buffer);
    aux.truncate(size);
    double value = aux.toDouble();
    if (value > 32768) {
        QString msg = "\nError lexico: Constante entera fuera de rango (Linea: ";
        msg.append(QString::number(lineas));
        msg.append(").");
        errores->push_back(msg);
        return TOKEN_INVALIDO;
    }

    int valor = aux.toInt();

    /*Chequea si está en TS. Si no, lo da de alta */
    if (!tablaDeSimbolos->contiene(*buffer)) {
        EntradaTS * e = new EntradaTS (*buffer, "CTE", CTE);
        e->tipo="INT";
        e->value1=valor;
        tablaDeSimbolos->insertar(*buffer,e);

    }
    yylval = tablaDeSimbolos->value(*buffer)->lexema;

    return CTE;
}


/*Acción semantica al reconocer operadores dobles (<>, <=, ==, etc) */

int AnalizadorLexico::accionS4(QString *buffer, char c) {

    buffer->push_back(c); //consume el ultimo char
    int token =-1;

    if(*buffer == ">=")
        token = MAYORIGUAL;
    else if(*buffer == "<=")
        token = MENORIGUAL;
    else if(*buffer == "<>")
        token = DISTINTO;
    else if(*buffer == "==")
        token = IGUALIGUAL;

    return token;
}



/*Acción semantica al reconocer operadores simples (=, +, -, "(", ")", etc) */

int AnalizadorLexico::accionS5(QString *buffer, char c) {
    entrada.push_front(c); //devuelve el ultimo char

    return accionS5F(buffer,c);
}


/*Accion semantica al reconocer operadores simples sobre FINARCHIVO. No consume ni devuelve char*/
int AnalizadorLexico::accionS5F(QString *buffer, char c) {
    int token=TOKEN_INVALIDO;

    if(*buffer == "+")
        token = '+';
    else if(*buffer == "-")
        token = '-';
    else if(*buffer == "*")
        token = '*';
    else if(*buffer == "/")
        token = '/';
    else if(*buffer == "=")
        token = '=';
    else if(*buffer == "(")
        token = '(';
    else if(*buffer == ")")
        token = ')';
    else if(*buffer == ",")
        token = ',';
    else if(*buffer == ";")
        token = ';';
    else if(*buffer == "<")
        token = '<';
    else if(*buffer == ">")
        token = '>';
    else if (*buffer == "{")
        token = '{';
    else if (*buffer == "}")
        token = '}';

    return token;
}




/*Acción semantica vacia */

int AnalizadorLexico::accionSV(QString *buffer, char c) {
    return TOKEN_INVALIDO;
};


/*Acción semantica que suma lineas */

int AnalizadorLexico::accionSL(QString *buffer, char c) {
    lineas++;
    return TOKEN_INVALIDO;
}


/* Convierte a float un string con parte exponencial */
float AnalizadorLexico::toFloat (QString * buffer) {
    QString aux (*buffer);
    int indiceExp = -1;
    if (aux.contains('e')) {
        indiceExp=aux.indexOf('e');
    } else {
        indiceExp=aux.indexOf('E');
    }

    QString mantisa="";
    for (int i=0; i<indiceExp; i++) {
        mantisa.push_back(buffer->at(i));
    }

    QString exponente="";
    for (int i=indiceExp+1; i<buffer->size(); i++) {
        exponente.push_back(buffer->at(i));
    }

    float devolucion = mantisa.toFloat() * (pow (10, exponente.toFloat()));

    return devolucion;
}



/*Acción semantica que verifica flotante */
int AnalizadorLexico::accionS6(QString *buffer, char c) {
    entrada.push_front(c); //devuelve el ultimo char
    return accionS6F(buffer,c);
}



/*Acción semantica que verifica flotante sobre FINARCHIVO. No consume ni devuelve.*/
int AnalizadorLexico::accionS6F(QString *buffer, char c)
{
    float aux=-1;

    if (buffer->contains('e') || buffer->contains ('E')) {
        aux = this->toFloat(buffer);
    } else {
        aux = buffer->toFloat();
    }

    float limiteSuperior = 3.40282347 * (pow(10,38));
    float limiteInferior = 1.17549435 * (pow(10,-38));
    if (aux > limiteSuperior || aux < limiteInferior) {
        QString msg = "\nError lexico: Constante flotante fuera de rango (Linea: ";
        msg.append(QString::number(lineas));
        msg.append(").");
        errores->push_back(msg);
        return TOKEN_INVALIDO;
    }

    /*Chequea si está en TS. Si no, lo da de alta */
    if (!tablaDeSimbolos->contiene(*buffer)) {
        EntradaTS * e = new EntradaTS(*buffer, "CTE", CTE);
        e->tipo="FLOAT";
        e->value2=aux;
        tablaDeSimbolos->insertar(*buffer,e);
    }

    yylval = tablaDeSimbolos->value(*buffer)->lexema;

    return CTE;
}



/*Acción semantica que sólo almacena el char al buffer. Para pasos intermedios */

int AnalizadorLexico::accionSA(QString *buffer, char c) {
    buffer->push_back(c); //consume el último char
    return TOKEN_INVALIDO;
}


/*Acción semantica que verifica cadena. Consume ultimo char y se fija la tabla simbolos */

int AnalizadorLexico::accionS7(QString *buffer, char c) {
    buffer->push_back(c); //consume el último char

    /*Chequea si está en TS. Si no, lo da de alta */
    if (!tablaDeSimbolos->contiene(*buffer)){
        EntradaTS * e = new EntradaTS(*buffer, "CADENA", CADENA);
        e->tipo="CADENA";
        tablaDeSimbolos->insertar(*buffer, e);
    }

    yylval = tablaDeSimbolos->value(*buffer)->lexema;

    return CADENA;
}


/*Accion semántica de error de cadena*/
int AnalizadorLexico::accionSEC(QString *buffer, char c) {
    lineas++;

    QString msg = "\nError lexico: Cadena invalida (Linea: ";
    msg.append(QString::number(lineas));
    msg.append(").");
    errores->push_back(msg);

    return TOKEN_INVALIDO;
}


/*Accion semántica de token invalido */
int AnalizadorLexico::accionSTI(QString *buffer, char c) {
    QString msg = "\nError lexico: Token invalido (Linea: ";
    msg.append(QString::number(lineas));
    msg.append(").");
    errores->push_back(msg);
    return TOKEN_INVALIDO;
}


/*Accion semántica de error de identificador */
int AnalizadorLexico::accionSEI (QString *buffer, char c) {
    QString msg = "\nError lexico: Identificador invalido. Se esperaba una letra minuscula (Linea: ";
    msg.append(QString::number(lineas));
    msg.append(").");
    errores->push_back(msg);
    return TOKEN_INVALIDO;
}


/*Accion semántica de error de constante */
int AnalizadorLexico::accionSECTE (QString *buffer, char c) {
    entrada.push_front(c); //devuelve el ultimo char
    QString msg = "\nError lexico: Constante invalida. Verificar el formato (Linea: ";
    msg.append(QString::number(lineas));
    msg.append(").");
    errores->push_back(msg);
    return TOKEN_INVALIDO;
}


/*Accion semántica de error de numero flotante */
int AnalizadorLexico::accionSEF (QString *buffer, char c) {
    entrada.push_front(c); //devuelve el ultimo char
    QString msg = "\nError lexico: Constante flotante invalida. Verificar el formato (Linea: ";
    msg.append(QString::number(lineas));
    msg.append(").");
    errores->push_back(msg);
    return TOKEN_INVALIDO;
}


/*Accion semantica de error de comentario */
int AnalizadorLexico::accionSECOM(QString *buffer, char c)
{
    QString msg = "\nError lexico: Comentario invalido (Linea: ";
    msg.append(QString::number(lineas));
    msg.append(").");
    errores->push_back(msg);
    return TOKEN_INVALIDO;
}

