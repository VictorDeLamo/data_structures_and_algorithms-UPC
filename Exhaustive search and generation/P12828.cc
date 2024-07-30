#include <iostream>
#include <vector>
using namespace std;

void cons_cadenas(vector<int>& cadena, int lon, int index) {
    if (cadena.size() == index) {
        for(int i = 0; i < lon -1; ++i) {
            cout << cadena[i] << ' ';
        }
        cout << cadena[lon -1];
        cout << endl;
    }
    else {
        cadena[index] = 0; cons_cadenas(cadena,lon,index +1);
        cadena[index] = 1; cons_cadenas(cadena,lon,index +1);

    }
}
int main () {
    int lon;
    cin >> lon;
    vector<int> cadena(lon);
    cons_cadenas(cadena,lon,0);
}