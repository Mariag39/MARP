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

class teclado {
public:
	teclado(GrafoDirigidoValorado<int> const& gv,vector<int> pags) : marked(gv.V(), false), disto(gv.V(),INFINITO),
	dest(gv.V() - 1), pq(gv.V()),tam(pags[0]),_pags(pags){
		Dijkstra(gv, 0);
	}

	bool haysolucion() {
		return disto[dest] != INFINITO;
	}

	int solucion() {
		return disto[dest] + _pags[0];
	}

private:
	vector<bool> marked;
	vector<int> disto;
	IndexPQ<int> pq;
	vector<int> _pags;
	int dest;
	int tam;

	void Dijkstra(GrafoDirigidoValorado<int> const& gv, int s) {
		disto[s] = 0;
		pq.push(s, 0);
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
			pq.update(w, disto[w]);
		}
	}

};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int N;
	cin >> N;
	if (!std::cin) {
		return false;
	}
	vector<int> pags(N);
	int p;
	for (int i = 0; i < N; i++) {
		cin >> p;
		pags[i] = p;
	}
	GrafoDirigidoValorado<int> g(N);
	int M;
	cin >> M;
	int v,w,val;
	for (int i = 0; i < M; i++) {
		cin >> v >> w >> val;
		val += pags[w - 1];
		g.ponArista({v-1,w-1,val});
	}

	teclado t(g,pags);

	if (t.haysolucion()) cout << t.solucion() << '\n';
	else cout << "IMPOSIBLE" << '\n';
	


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