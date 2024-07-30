#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Matriz;

Matriz leer_matriz( int f, int c,vector<int>& colores) {
    Matriz mat (f,vector<char> (c));
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >>mat[i][j];
            if (mat[i][j] != '.' and mat[i][j] != '#' ) {
                colores.push_back(i);
                colores.push_back(j);
                //cout << mat[i][j] << endl;
            }
        }
    }
    return mat;
}
void escribir_matriz(int f, int c, Matriz const& mat) {
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << mat[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
bool posible_pos(int fila, int columna, Matriz const& mat) {
    if (fila < 0 or fila > mat.size() or columna < 0 or columna > mat[0].size() or mat[fila][columna] != '.') return false;
    else return true;
}
void bfs(Matriz &mat, int fila, int columna, char letra){
    mat[fila][columna] = letra;
    if (posible_pos(fila +1, columna, mat)) bfs(mat,fila +1, columna, letra);
    if (posible_pos(fila -1, columna, mat)) bfs(mat,fila -1, columna, letra);
    if (posible_pos(fila, columna +1, mat)) bfs(mat,fila , columna +1, letra);
    if (posible_pos(fila , columna -1, mat)) bfs(mat,fila , columna -1, letra);
}
int main () {
    int f,c;
    while (cin >> f >> c) {
        vector<int> colores;
        Matriz mat = leer_matriz(f,c,colores);
        for (int i =0; i < colores.size(); i = i +2) {

            bfs(mat,colores[i],colores[i +1],mat[colores[i]][colores[i+1]]);
        }
        escribir_matriz(f,c,mat);


    }
}