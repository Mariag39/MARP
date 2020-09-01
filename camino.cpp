// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
#include <queue>
#include <vector>
#include <string>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"
using namespace std;
const int INFINITO = 1000000000;
//O(P log P) siendo P el numero de aristas

class camino {
public:
	camino(GrafoDirigidoValorado<int> const& gv, int o, int d) : marked(gv.V(), false), disTo(gv.V(),0),
	disToD(gv.V(),make_pair(INFINITO,0)),pq(gv.V()), destino(d){
		bfs(gv, o);
		dijkstra(gv, o);

	}

	bool haycamino() {
		return disToD[destino].first != INFINITO;
	}

	bool iguales() {
		return disTo[destino] == disToD[destino].second;
	}

	int solucion() {
		return disToD[destino].first;
	}

private:
	vector<bool> marked;
	vector<int> disTo;
	vector<pair<int,int>> disToD;
	IndexPQ<pair<int,int>> pq;
	int destino;

	void bfs(GrafoDirigidoValorado<int> const & g, int s) {
		queue<int> q;
		disTo[s] = 0;
		marked[s] = true;
		q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (auto w : g.ady(v)) {
				if (!marked[w.to()]) {
					disTo[w.to()] = disTo[v] + 1;
					marked[w.to()] = true;
					q.push(w.to());
				}
			}
		}
	}

	void dijkstra(GrafoDirigidoValorado<int> const & g, int s) {
		pq.push(s, { 0,0 });
		disToD[s] = { 0,0 };
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto e : g.ady(v)) {
				relax(e);
			}
		}
	}

	void relax(AristaDirigida<int> e) {
		int v = e.from(), w = e.to();
		if (disToD[w].first > disToD[v].first + e.valor()) {
			disToD[w].first = disToD[v].first + e.valor();
			disToD[w].second = disToD[v].second + 1;
			pq.update(w, disToD[w]);
		}
		else if (disToD[w].first == disToD[v].first + e.valor() && disToD[w].second > disToD[v].second + 1) {
			disToD[w].second = disToD[v].second + 1;
			pq.update(w, disToD[w]);
		}
	}

};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int N, C;
	cin >> N >> C;

	if (!std::cin) {
		return false;
	}

	GrafoDirigidoValorado<int> g(N);

	int v, w, val;
	for (int i = 0; i < C; i++) {
		cin >> v >> w >> val;
		g.ponArista(AristaDirigida<int>(v - 1, w - 1, val));
		g.ponArista(AristaDirigida<int>(w - 1, v - 1, val));
	}
	int consultas;
	int origen, destino;
	cin >> consultas;
	for (int i = 0; i < consultas; i++) {
		cin >> origen >> destino;
		origen--;
		destino--;
		camino c(g, origen, destino);
		
		if (c.haycamino()) {
			cout << c.solucion() << " ";
			if (c.iguales()) {
				cout << "SI" << '\n';
			}
			else cout << "NO" << '\n';
		}
		else cout << "SIN CAMINO" << '\n';
	}

	cout << "---" << '\n';
	

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso()) {

	};


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}