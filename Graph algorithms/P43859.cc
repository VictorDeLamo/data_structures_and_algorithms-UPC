#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> Par;
typedef vector<Par> Vpar;
typedef vector<Vpar> Grafo;
const int INF = 1e9;

Grafo leer_grafo(int nodes,int arestes) {
    Grafo graf (nodes);
    for(int i = 0; i < arestes; ++i) {
        int x, y, pes;
        cin >> x >> y >> pes;
        graf[x].push_back(Par(pes,y));
    }
    return graf;
    //cout << "he acabado de leer" << endl; 
}

int dijkstra(int origen, int final, Grafo const& graf) {

    //cout << "he entrado al dijkstra" << endl; 
    priority_queue <Par, vector<Par>, greater<Par> > pq;
    pq.push(Par(0, origen)); // en la cola guardamos nodos y su peso

    vector<int> dist(graf.size(),INF); // vector donde guardamos la distancia des de el origen a cada nodo
    dist[origen] = 0; // ponemos distancia 0 en el origen

    vector<bool> visitados (graf.size(), false);

    while(!pq.empty()) {
        Par nodo = pq.top();
        pq.pop();
        if (!visitados[nodo.second]) {
            visitados[nodo.second] = true;
            if (nodo.second != final) {
                for(int i = 0; i < graf[nodo.second].size(); ++i ) {
                    int nodo_sig = graf[nodo.second][i].second;
                    int peso_sig = graf[nodo.second][i].first;

                    if (dist[nodo_sig] > peso_sig + dist[nodo.second]) {
                        dist[nodo_sig] = peso_sig + dist[nodo.second];
                        //cout << "he aÃ±adido a " << nodo << endl; 
                        pq.push(Par(dist[nodo_sig], nodo_sig)); 
                    }
                }
            }
            else {
                priority_queue <Par, vector<Par>, greater<Par> > aux;
                pq = aux;  
            }
        }
    }   

    //cout << "he salido del while" << endl; 
    return dist[final];
}

int main () {
    int nodes, arestes;
    while (cin >> nodes >> arestes) {
        Grafo graf = leer_grafo(nodes,arestes);
        int origen, final;
        cin >> origen >> final;
        int res = dijkstra(origen,final, graf);
        if (res != INF) cout << res << endl;
        else cout << "no path from " << origen << " to " << final << endl;
    }
}