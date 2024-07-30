#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Matriz;
typedef pair<int,int>Par;


Matriz leer_matriz(int files, int columnes){
    Matriz mat(files, vector<char>(columnes));
    for (int i = 0; i < files; ++i) {
        for(int j = 0; j < columnes; ++j) {
            cin >>mat[i][j];
        }
    }
    return mat;
}
vector<int> vecx = {1, -1, 0, 0};
vector<int> vecy = {0, 0, 1, -1};

bool ok(Matriz const& mapa, vector<vector<bool>>& visitados, int x, int y ) {
    if (x < 0 or x >= mapa.size() or y < 0 or y >= mapa[0].size() or mapa[x][y] == 'X' or visitados[x][y]) return false;
    else return true;
}
// tresor 1 es el més llunya
// tresor 2 es el segon més llunya

void dfs(Matriz const& mapa, vector<vector<bool>>& visitados, int fila, int columna, int& tresor1, int& tresor2 ) {
    
    queue<Par> qfilas;
    queue<int> qcolumnas;
    visitados[fila][columna] = true;
    qfilas.push(Par(fila,0));
    qcolumnas.push(columna);
    while(not qfilas.empty()) {
        int x = qfilas.front().first;
        int distancia = qfilas.front().second; qfilas.pop();
        int y = qcolumnas.front(); qcolumnas.pop();

        if (mapa[x][y] == 't') {
            if (distancia > tresor1) {
                tresor2 = tresor1;
                tresor1 = distancia;
                
            }
            else if (distancia > tresor2) {
                tresor2 = distancia;
            }
        }
        
        for(int i =0; i < 4; ++i) {
            
            if (ok(mapa, visitados, x + vecx[i], y + vecy[i])) {
                
                visitados[x + vecx[i]][y + vecy[i]] = true;
                qfilas.push(Par(x + vecx[i],distancia +1));
                qcolumnas.push(y + vecy[i]);
            }
        
        }

        
    }
    
    
}   
int main () {
    int files, columnes;
    cin>> files >> columnes;
    Matriz mat = leer_matriz(files,columnes);
    int fila_org, columna_org;
    cin >> fila_org >>columna_org;
    vector<vector<bool>> visitados (files,vector<bool>(columnes,false));
    int tresor1 = 0;
    int tresor2 = 0;
    
    dfs(mat,visitados,fila_org -1,columna_org -1,tresor1,tresor2);
    
    if (tresor2 != 0) cout << "segona distancia maxima: " << tresor2 << endl;
    else cout << "no es pot arribar a dos o mes tresors" << endl;
    
    


}