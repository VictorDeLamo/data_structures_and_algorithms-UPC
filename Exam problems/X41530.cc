#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matriz;

Matriz leer_matriz (int nodes, int arestes) {
    Matriz mat(nodes);
    for (int i = 0; i < arestes; ++i) {
        int x, y;
        cin >> x >> y;
        mat[x].push_back(y);
        mat[y].push_back(x);

    }
    return mat;
}
void dfs (Matriz const& mat, vector<bool> &visitados, int anterior, int actual,bool& ciclo) {
    if (visitados[actual]) {
        ciclo = true;
        return;
    }
    else {
        visitados[actual] = true;
        for (int i = 0; i < mat[actual].size() and not ciclo;++i) {
            if (mat[actual][i] != anterior) {
                dfs(mat, visitados,actual,mat[actual][i],ciclo);
                
            }
        }
    }

}
int main (){
    int nodes, arestes;
    while (cin >> nodes >> arestes) {
        Matriz  mat = leer_matriz(nodes, arestes);
        vector<bool> visitados (nodes,false);
        bool ciclo = false;
        int na = 0;
        for (int i = 0; i < nodes and !ciclo; ++i) {
            if (!visitados[i]) {
                dfs(mat,visitados,i,i,ciclo);
                ++na;

            }
        }
        if (ciclo) cout <<"no" << endl;
        else cout << na << endl;
    }
}


