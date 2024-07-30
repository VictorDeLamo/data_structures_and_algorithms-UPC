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
void cons_cadenas(vector<string> cadena, int n, vector<bool> visitados, int index, vector<string> const& palabras) {
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
            if (not visitados[i]) {
                
                cadena[index] = palabras[i];
                visitados[i] = true;
                cons_cadenas(cadena,n,visitados,index + 1, palabras);
                visitados[i] = false;
               // escribir_cadena_visitados(cadena,n,visitados);
            }
        }
        

    }
}
int main () {
    int n;
    
    cin >> n;
    vector<string> palabras(n);
    for(int i = 0; i < n; ++i) {
        cin >> palabras[i];
    }
    vector<string> cadena(n);
    vector<bool> visitados(n,false);
    cons_cadenas(cadena,n,visitados,0,palabras);
}