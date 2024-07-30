#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> Matriz;

Matriz leer_grafo(int nodes, int arestes, vector<int>& grados) {
    Matriz mat (nodes) ;
    int x, y;
    for (int i = 0; i < arestes; ++i) {
        cin >> x >> y;
        mat[x].push_back(y);
        mat[y].push_back(x);
        ++grados[y];
    }
    /*
    for (int i = 0; i < nodes; ++i) {
        sort(mat[i].begin(), mat[i].end());
    }
    */
    return mat;
}
void quitar_nodo(Matriz const&mat, int nodo,vector<int> &grados, priority_queue <int, vector<int>, greater<int> >& pila ) {
    for (int i = 0; i < mat[nodo].size(); ++i) {
        if (--grados[mat[nodo][i]] == 0 ) {
            pila.push(mat[nodo][i]);
        }
    }

}
void ordenacion_topologica(Matriz const&mat, int nodes, vector<int>& grados) {
    priority_queue <int, vector<int>, greater<int> > pila;
    for (int i = 0; i < nodes; ++i) {
        if (grados[i] == 0) pila.push(i);
        
    }

    int nodo = pila.top();
    cout << nodo;
    pila.pop();
    quitar_nodo(mat,nodo,grados,pila);
    
    while(not pila.empty()) {
        int nodo = pila.top();
        cout <<' ' << nodo;
        pila.pop();
        quitar_nodo(mat,nodo,grados,pila);
        
    }
}
int main () {
    int nodes, arestes;
    while (cin >> nodes >> arestes) {
        vector<int> grados (nodes);
        Matriz mat = leer_grafo(nodes, arestes,grados);
        /*
        for (int i = 0; i < nodes; ++i) {
            cout << i << " : " << grados[i] << endl;
        }
        cout <<  " ------------------- " << endl;
        */
        ordenacion_topologica(mat,nodes, grados);
        cout << endl;
        /*
        for (int i = 0; i < nodes; ++i) {
            cout << i << " : " << grados[i] << endl;
        }
        */
        
    }
}