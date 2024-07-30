#include <iostream>
#include <vector>
using namespace std;

void escribir_cadena_visitados (vector<int> cadena, int n, vector<bool> visitados) {
   
        for(int i = 0; i < n -1; ++i) {
            cout << cadena[i] << ' ';
        }
        cout << cadena[n -1];
        cout << endl;
    
    for (int i = 0; i < visitados.size(); ++i) {
        cout << visitados[i] << ' ';
    }
     cout << endl;
}
void cons_cadenas(vector<int> cadena, int n, vector<bool> visitados, int index) {
    if (cadena.size() == index) {
        cout << '(';
        for(int i = 0; i < n -1; ++i) {
            cout << cadena[i] << ',';
        }
        cout << cadena[n -1] << ')';
        cout << endl;
    }
    else {
        for(int i =0; i < n; ++i) {
            if (not visitados[i +1]) {
                
                cadena[index] = i +1;
                visitados[i +1] = true;
                cons_cadenas(cadena,n,visitados,index + 1);
                visitados[i +1] = false;
               // escribir_cadena_visitados(cadena,n,visitados);
            }
        }
        

    }
}
int main () {
    int n;
    cin >> n;
    vector<int> cadena(n);
    vector<bool> visitados(n +1,false);
    cons_cadenas(cadena,n,visitados,0);
}