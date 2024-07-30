#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<char>> Matriz;

void escribir_matriz(Matriz const& mat) {
    for(int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[0].size(); ++j ) {
            cout << mat[i][j];
        }
        cout << endl;
    } 
    
}
void guardar_fila(Matriz &mat, int fila, int reina) {
    for(int i = 0; i <mat.size(); ++i) {
        if (i == reina) mat[fila][i] = 'Q';
        else mat[fila][i] = '.';
    }
}

void reines (int n, int filas, vector<bool>& columnas, vector<bool>& diagonales1, vector<bool>& diagonales2, Matriz & mat, bool& finish ) {  
    
    if (filas == n) {
        finish = true;
        escribir_matriz(mat);
        
    } 
    if (finish == true)return;
    

    for(int j = 0; j < n; ++j) {
        
        if ( not columnas[j] and not diagonales1[n -filas + j] and not diagonales2[filas + j] ) {
            columnas[j] = true;
            diagonales1[n -filas + j] = true;
            diagonales2[filas + j] = true;
            guardar_fila(mat,filas,j);
            //escribir_matriz(mat);
            reines(n,filas +1,columnas,diagonales1,diagonales2,mat,finish);
            columnas[j] = false;
            diagonales1[n -filas + j] = false;
            diagonales2[filas + j] = false;
            
        } 
        
        
    }
    
    
        
    
}

int main () {
    int n;
    cin >>n;
    
    vector<bool> columnas(n,false);
    vector<bool> diagonales1(n*2 -1,false);
    vector<bool> diagonales2(n*2 -1,false);
    Matriz mat(n,vector<char>(n));
    int contador = 0;
    bool finish = false;
    reines(n,0,columnas,diagonales1,diagonales2,mat,finish);
    if (finish == false) cout << "NO SOLUTION" << endl;
    
}