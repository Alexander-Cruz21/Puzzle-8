#include <iostream>
#include <stdlib.h>
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
    int getValor(int r, int c)const{return matriz[r][c];}
    void setValor(int r, int c, int val){
        matriz[r][c]= val;
        if(val==0){
            filaVacia= r;
            colVacia= c;
        }
    }
    int getfilaVacia(){return filaVacia;}
    int getcolumnaVacia(){return colVacia;}
    bool operator==(const Tablero &x)const{
        for(int i=0; i<3; i++){
            for(int j=0; j<3;j++){
                if(matriz[i][j] != x.matriz[i][j]) return false;  
            } 
        }
        return true;
    }
    
    void buscarFicha(int ficha, int&r, int &c) const {
        for(int i=0; i<3; i++){
            for(int j=0; j<3;j++){
                if(matriz[i][j] == ficha){
                    r = i;
                    c = j;
                    return;
                }
            } 
        }
    }

    bool movValido(int r, int c) const {
        if(r < 0 || r >= 3 || c < 0 || c >= 3) return false;
        int dist =  abs(r - filaVacia) + abs(c - colVacia);
        return (dist == 1);
    }

    bool movPieza(int r, int c){
        if(!movValido(r,c)) return false;
        matriz[filaVacia][colVacia] = matriz[r][c];
        matriz[r][c] = 0;
        filaVacia = r;
        colVacia = c;
        return true;
    }
    void mezclar (int numMovimientos){
        int direcFil[]= {-1,1,0,0};
        int direcCol[]= {0,0, -1, 1};
        int ultimaFila= -1, ultimaColumna= -1;
        for(int i=0; i<numMovimientos; i++){
            vector<pair<int,int>> vecinos; 
            for(int direc=0; direc<4; direc++){
                int numFIL= filaVacia + direcFil[direc];
                int numCOL= colVacia + direcCol[direc];
                if(numFIL >=0 && numFIL <3 && numCOL>=0 && numCOL<3 ){
                    if(numFIL!=ultimaFila|| numCOL !=ultimaColumna){
                        vecinos.push_back({numFIL, numCOL});
                    }
                }
            }
            if(!vecinos.empty()){
                int casillaVec = rand() % vecinos.size();
                ultimaFila= filaVacia;
                ultimaColumna= colVacia;
                movPieza(vecinos[casillaVec].first, vecinos[casillaVec].second);
            }

        }
    }
    
};