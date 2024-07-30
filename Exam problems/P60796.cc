#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Matriz;
typedef pair<int,int> Par;
typedef pair<Par,int> Coord;
#define inf 0x7fffffff

bool ok (Matriz const& mapa, int fil, int col, vector<vector<bool>> const& visitados) {
    if (fil < 0 or fil >= mapa.size() or col < 0 or col >= mapa[0].size() or mapa[fil][col] == 'X' or visitados[fil][col]) return false;
    else return true;
}

Matriz leer_matriz(int fil, int col) {
    Matriz mat(fil,vector<char>(col));
    for(int i = 0; i < fil; ++i) {
        for(int j = 0; j < col; ++j) {
            cin >> mat[i][j];
        }
    }
    return mat;
}

int bfs (Matriz & mapa, int f, int c) {
    vector<vector<bool>> visitados (mapa.size(), vector<bool>(mapa[0].size(),false));
    queue<Coord> cola;
    cola.push(Coord(Par(f,c),0));
    mapa[f][c] = true;
    int ret = inf;
    while(not cola.empty()) {
        Coord v = cola.front();
        cola.pop();
        int x, y, dist;
        x = v.first.first;
        y = v.first.second;
        dist = v.second;
        //cout << "x: " << x << " y: " << y<< " dist: " << dist << endl;
        
        if (mapa[x][y] == 't') {
            if (ret > dist) ret = dist;
           // cout << "x: " << x << " y: " << y<< "  es este dist: " << dist << endl;
        } 
        mapa[x][y] == 'X';
        if (ok(mapa,x+ 1,y, visitados)) {
            cola.push(Coord(Par(x+1,y),dist + 1));
            visitados[x +1][y] = true;
        } 
        if (ok(mapa,x - 1,y,visitados)) {
            cola.push(Coord(Par(x-1,y),dist + 1)); 
            visitados[x -1][y] = true;
        }
        if (ok(mapa,x,y +1,visitados)) {
            cola.push(Coord(Par(x,y +1),dist + 1)); 
            visitados[x][y +1] = true;
        }
        if (ok(mapa,x,y -1,visitados)){
            cola.push(Coord(Par(x,y -1),dist + 1));
             visitados[x][y -1] = true;
        } 
    }
    return ret;
}

int main (){
    int fil,col;
    cin >> fil >> col;
    Matriz mapa = leer_matriz(fil,col);
    int x, y;
    cin >> x >> y;
    int dist = bfs(mapa,x -1,y -1);
    if (dist != inf ) cout << "distancia minima: " << dist << endl;
    else cout << "no es pot arribar a cap tresor" << endl;
}