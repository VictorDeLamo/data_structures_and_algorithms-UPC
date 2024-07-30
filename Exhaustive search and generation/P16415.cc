#include <iostream>
#include <vector>
using namespace std;


void reines (int n, int filas, vector<bool>& columnas, vector<bool>& diagonales1, vector<bool>& diagonales2, int& contador ) {  
    if (filas == n) ++contador;
    for(int j = 0; j < n; ++j) {
        if (not columnas[j]) {
            if ( not columnas[j] and not diagonales1[n -filas + j] and not diagonales2[filas + j] ) {
                columnas[j] = true;
                diagonales1[n -filas + j] = true;
                diagonales2[filas + j] = true;
                reines(n,filas +1,columnas,diagonales1,diagonales2,contador);
                columnas[j] = false;
                diagonales1[n -filas + j] = false;
                diagonales2[filas + j] = false;
            } 
        }
        
    }
        
    
}

int main () {
    int n;
    cin >>n;
    
    vector<bool> columnas(n,false);
    vector<bool> diagonales1(n*2 -1,false);
    vector<bool> diagonales2(n*2 -1,false);
    int contador = 0;
    reines(n,0,columnas,diagonales1,diagonales2,contador);
    cout << contador << endl;
}