#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int main() {
    int x, y, n;
    while (cin >> x) {
        cin >> y;
        cin >> n;
        bool trobat = false;
        
        int contador = 0;
        bool bcontador = false;
        set<int> set1;
        set<int> set2;
        set1.insert(n);

        while ( not trobat and n <= pow(10, 8) + 1){
            if (bcontador) ++contador;
        
            if (n % 2 == 0) n = n/2 + x;
            else n = 3*n +y;

            if (set1.find(n) == set1.end())set1.insert(n);
            else if (set2.find(n) == set2.end()){
                set2.insert(n);
                bcontador = true;
            } 
            else trobat = true;
        }
        if (trobat) cout << contador << endl;
        else cout << n << endl;
    }
        
    
}