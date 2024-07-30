#include <iostream>
#include <vector>
using namespace std;

int potencia (int  n, int k, int m) {
    if (k == 0) return 1;
    int y =  potencia(n, k/2, m);
    int res = (y*y)%m;
    if (k%2 == 0) return res;
    else return (res * n)%m;
}
int main () {
    int n, k, m;
    while (cin >> n) {
        cin >> k;
        cin >> m;
         cout << potencia(n, k, m) << endl;
    }
}
