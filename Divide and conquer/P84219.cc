#include <iostream>
#include <vector>
using namespace std;
/*
int un_menys(const vector<double>& v, double x, int m) {
    if (m == 0) return m;
    else if(v[m/2] == v[m]) return un_menys(v, x, m/2);
    else return m;
}
*/
int cerca (double x, const vector<double>& v, int esq, int dre ) {
    if (esq > dre) return -1;
   
    int m = (dre + esq)/2;
     if (esq == dre) {
        if (v[dre] == x) return m;
        else return -1;
    }
    if (v[m] < x) return cerca(x, v, m + 1, dre);
    else if (v[m] > x) return cerca (x, v, esq, m - 1);
    else {
        return cerca (x, v, esq, m);
    }
}
int first_occurrence(double x, const vector<double>& v) {
    return cerca(x, v, 0, v.size() - 1);
}

int main () {
    vector<double> v = {1,2,2,3,3};
    double x = 3;
    int m = first_occurrence(x, v);
    cout << m << endl;

}