#include <iostream>
#include <vector>
using namespace std;

void cons_cadenas(vector<int>& cadena, int lon,int max, int sum, int index) {
    if (cadena.size() == index) {
        for(int i = 0; i < lon -1; ++i) {
            cout << cadena[i] << ' ';
        }
        cout << cadena[lon -1];
        cout << endl;
    }
    else {
        if (sum == max) {
            cadena[index] = 0; 
            cons_cadenas(cadena,lon,max,sum,index +1);
        } 
        else if (lon - index <= max - sum) {
            cadena[index] = 1; 
            cons_cadenas(cadena,lon,max,sum +1,index +1);
        } 
        else if (index == lon -1 and sum< max) {
            cadena[index] = 1; 
            cons_cadenas(cadena,lon,max,sum +1,index +1);
        }
        else {
            cadena[index] = 0; cons_cadenas(cadena,lon,max,sum,index +1);
            cadena[index] = 1; cons_cadenas(cadena,lon,max,sum +1,index +1);
        }
        

    }
}
int main () {
    int lon, max;
    cin >> lon >>max;
    vector<int> cadena(lon);
    cons_cadenas(cadena,lon,max,0,0);
}