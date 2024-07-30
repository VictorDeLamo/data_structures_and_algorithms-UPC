#include <iostream>
#include <vector>
using namespace std;

int search(double x, const vector<double>& v, int esq, int dre ) {
    if (dre < esq) return -1;
    int m = (dre + esq)/2;
    if(v[m]==x or (v[m-1] == x and m-1 >= esq) or (v[m+1] == x and m+1 <= dre)) return m;
    if (x < v[m])  return search(x,v,esq,m-1);
    else return search(x,v,m+1,dre);
    

}
bool resistant_search(double x, const vector<double>& v) {
    int n = v.size();
    int i = search(x,v,0,n -1);
    if (i == -1) return false;
    else return true;

}
int main () {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << resistant_search(x, V) << endl;
        }
    }
}