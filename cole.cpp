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
const int INFINITO = 1000000;
//O(P log P) siendo P el numero de aristas

class cole {
public:
	cole(GrafoDirigidoValorado<int> const& gv) : marked(gv.V(), false), dest(gv.V() - 1),
	disto(gv.V(),INFINITO),pq(gv.V()),edgeto(gv.V()){
		
		dijkstra(gv, 0);
	}

	int solu() {
		return edgeto[edgeto.size() - 1];
	}
	
private:
	vector<bool> marked;
	vector<int> disto;
	vector<int> edgeto;
	IndexPQ<int> pq;
	int dest;
	
	
	void dijkstra(GrafoDirigidoValorado<int> const& gv, int s) {
		disto[s] = 0;
		pq.push(s, 0);
		edgeto[s] = 1;
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto e : gv.ady(v)) {
				relax(e);
			}
		}
	}

	void relax(AristaDirigida<int> e) {
		int v = e.from(), w = e.to();
		if (disto[w] > disto[v] + e.valor()) {
			disto[w] = disto[v] + e.valor();
			edgeto[w] = edgeto[v];
			pq.update(w,disto[w]);
		}
		else if (disto[w] == disto[v] + e.valor()) {
			edgeto[w] += edgeto[v];
		}
	}
	


};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int N,C;
	cin >> N >> C;
	if (!std::cin) {
		return false;
	}
	
	GrafoDirigidoValorado<int> g(N);
	int v, w, val;
	for (int i = 0; i < C; i++) {
		cin >> v >> w >> val;
		g.ponArista({v-1,w-1,val});
		
	}

	cole c(g);
	cout << c.solu() << '\n';
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