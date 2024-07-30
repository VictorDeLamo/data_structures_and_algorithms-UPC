#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> Fila;
typedef vector<Fila> Matriz;
typedef vector <vector <bool>> Matriz_bool;

Matriz leer_matriz (int f, int c) {
    Matriz mat (f,vector<char>(c));
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> mat[i][j];
        }
    }
    return mat;

}
bool posible_mov (int x, int y, Matriz const& mapa, Matriz_bool& mat_bool) {
    if (x < 0 or y < 0 or x > mapa.size() - 1 or y > mapa[0].size() - 1) return false;
    if (mapa[x][y] == 'X') return false;
    if (mat_bool[x][y]) return false;
    else return true;

}

int busca (int x, int y, Matriz const& mapa, Matriz_bool& mat_bool) {
    //cout << "miro: " << x << " , " << y << endl;
    int actual = 0;
    if (mapa[x][y] == 't') ++actual;
    mat_bool[x][y] = true;
    vector<int> movimientos(4,0);
    if (posible_mov(x + 1, y, mapa, mat_bool)) {
        //cout << "a" << endl;
        movimientos[0] = busca(x + 1, y, mapa, mat_bool);
    } 
    if (posible_mov(x - 1, y, mapa, mat_bool)){
        //cout << "b" << endl;
        movimientos[1] = busca(x - 1, y, mapa, mat_bool);
    } 
    if (posible_mov(x, y + 1, mapa, mat_bool)) {
        //cout << "c" << endl;
        movimientos[2] = busca(x, y +1, mapa, mat_bool);
    } 
    if (posible_mov(x, y - 1, mapa, mat_bool)) {
        //cout << "d" << endl;
        movimientos[3] = busca(x, y - 1, mapa, mat_bool);
    } 
    return (actual+ movimientos[0] + movimientos[1] + movimientos[2] + movimientos[3]);


    
}

int main () {
    int f, c; 
    cin >> f; 
    cin >> c;

    Matriz mapa = leer_matriz(f,c);
    int xini, yini;
    cin >> xini;
    cin >> yini;

    Matriz_bool mat_bool (f,vector<bool>(c,false));
    
    cout << busca(xini -1, yini -1, mapa, mat_bool) << endl;

}