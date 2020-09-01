// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
#include <queue>
#include <vector>
#include "Grafo.h"
#include <string>
using namespace std;
#define PARED '#'
#define VIGILADA 'k'
#define ENTRADA 'E'
#define SALIDA 'P'

using Mapa = vector<vector<char>>;

const vector<pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1} };

class ronda {
public:
	ronda(Mapa & g): F(g.size()),C(g[0].size()),marked(F,vector<bool>(C,false)), entrada_c(0),
	entrada_f(0),salida_c(0),salida_f(0),entrada_vigilada(false),salida_vigilada(false),
	distTo(g.size(),vector<int>(g[0].size(),0)){
		sensores(g);
		if (!entrada_vigilada && !salida_vigilada) {
			bfs(entrada_f, entrada_c, g);
		}
	}

	bool path_to_exit() const {
		return marked[salida_f][salida_c];
	}

	int distancia() {
		return distTo[salida_f][salida_c];
	}

private:
	int F, C;
	vector<vector<bool>> marked;
	vector<vector<int>> distTo;
	bool entrada_vigilada;
	bool salida_vigilada;
	int entrada_f;
	int entrada_c;
	int salida_f;
	int salida_c;
	
	bool correcta(int i, int j) const {
		return 0 <= i && i < F && 0 <= j && j < C;
	}
	
	void sensores(Mapa & m) {
		int alcance;
		for (int f = 0; f < m.size(); f++) {
			for (int c = 0; c < m[0].size(); c++) {
				if (isdigit(m[f][c])) {
					alcance = m[f][c] - '0';
					m[f][c] = VIGILADA;
					casilla_vigilada(f, c, m, alcance);
				}
				else if (m[f][c] == ENTRADA) {
					this->entrada_f = f;
					this->entrada_c = c;
				}
				else if (m[f][c] == SALIDA) {
					this->salida_f = f;
					this->salida_c = c;
				}
			}
		}
	}

	void casilla_vigilada(int f, int c, Mapa & m,int alcance) {
		int limitsup = f + alcance;
		int limitinf = f - alcance;
		int limitsup_c = c + alcance;
		int limitinf_c = c - alcance;
		for (auto const& dir : dirs) {
			int fila = f + dir.first;
			int columna = c + dir.second;
			while (correcta(fila, columna) && m[fila][columna] != PARED && fila <= limitsup && fila >= limitinf &&
				columna <= limitsup_c && columna >= limitinf_c) {
				if (m[fila][columna] == ENTRADA)
					entrada_vigilada = true;
				else if (m[fila][columna] == SALIDA)
					salida_vigilada = true;
				else if(!isdigit(m[fila][columna]))
					m[fila][columna] = VIGILADA;
				columna += dir.second;
				fila += dir.first;
			}
			
		}

	}

	void bfs(int fila, int columna, Mapa const& m) {
		queue<pair<int,int>> q;
		
		marked[fila][columna] = true;
		q.push({ fila, columna });
		while (!q.empty() && !path_to_exit()) {
			pair<int, int> v = q.front(); q.pop();
			for (auto dir:dirs){
				int ni = v.first + dir.first;
				int nj = v.second + dir.second;
				if (correcta(ni, nj) && !marked[ni][nj] && m[ni][nj] != PARED && m[ni][nj] != VIGILADA) {
					distTo[ni][nj] = distTo[v.first][v.second] + 1;
					marked[ni][nj] = true;
					q.push({ ni,nj });
				}
			}
		}
	}

};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int V, E;
	cin >> E >> V;
	
	if (!std::cin) {

		return false;
	}
	
	Mapa m(V, vector<char>(E));
	cin.ignore();
	string linea;
	int columna = 0;
	for (int i = 0; i < V; ++i) {
		getline(cin, linea);
		for (char c : linea) {
			m[i][columna++] = c;
		}
		columna = 0;
	}

	ronda r(m);
	if (r.path_to_exit()) {
		cout << r.distancia() << '\n';
	}
	else {
		cout << "NO" << '\n';
	}

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		resuelveCaso();
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}