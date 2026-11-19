#include <iostream>
using namespace std;

class Tablero{
private:
    int matriz[3][3];
    int filaVacia;
    int colVacia;
public:
    Tablero(){
        int cont = 1;
        for(int i=0; i<3; i++){
            for(int j=0; j<3;j++){
                if(i == 2 && j == 2){
                    filaVacia = 2;
                    colVacia = 2;
                    matriz[i][j] =0;
                } else {
                    matriz[i][j] = cont++;
                } 
            }
        }
    }

    Tablero (const int m[3][3]){
        for(int i=0; i<3; i++){
            for(int j=0; j<3;j++){
                    matriz[i][j] = m[i][j];
                    if(matriz[i][j] == 0){
                        filaVacia = i;
                        colVacia = j;
                } 
            }
        }
    }
};