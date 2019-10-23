// María García Raldúa
// MARP17

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Grafo.h"
#include <algorithm>
#include <vector>
#include <istream>
#include <queue>
#include <string>
using namespace std;
using Mapa = vector<string>;


#define PARED '#'
#define ENTRADA 'E'
#define SALIDA 'P'
#define CASILLA_VIGILADA 'k'

struct sim {
	int filita;
	int columni;
};

class camino {
public:
	
	camino(vector<vector<char>> & m):F(m.size()),C(m[0].size()),
	marked(F,vector<bool>(C,false)), minimo(0), entrada_vigilada(false),
	salida_vigilada(false), distTo(m.size(), std::vector<size_t>(m[0].size(), 0)) {
		sensores(m);
		if (!entrada_vigilada && !salida_vigilada) {
			bfs(m, entradaf, entradac);
		}
	
	}
	bool path_to_exit() const{
		return marked[filasalida][colunmasalida];
	}
	
	size_t distance() const{
		return distTo[filasalida][colunmasalida];
	}

private:
	int F, C;
	vector<vector<bool>> marked;
	vector<vector<size_t>> distTo;
	int minimo;
	bool entrada_vigilada;
	bool salida_vigilada;
	int entradaf;
	int entradac;
	int filasalida;
	int colunmasalida;
	bool correcta(int i, int j) const {
		return 0 <= i && i < F && 0 <= j && j < C;
	}
	const vector<pair<int, int>> dirs = { {0,1},{-1,0},{0,-1},{1,0} };
	
	void sensores(vector<vector<char>> & m) {
		int alcance;
		for (int f = 0; f < m.size(); ++f) {
			for (int c = 0; c < m[0].size(); ++c) {
				if (isdigit(m[f][c])) {
					alcance = m[f][c] - '0';
					m[f][c] = CASILLA_VIGILADA;
					casillas_vigiladas(f, c, m, alcance);

				}
				else if (m[f][c] == ENTRADA) {
					this->entradaf = f;
					this->entradac = c;
				}
				else if (m[f][c] == SALIDA) {
					this->filasalida = f;
					this->colunmasalida = c;
				}
			}
		}

	}

	void casillas_vigiladas(int f, int c, vector<vector<char>>& m, int alcance) {
		int limitesup = f + alcance;
		int limiteinf = f - alcance;
		int limsupc = c + alcance;
		int liminfc = c - alcance;
		for (auto const& dir : dirs){
			int fila = f + dir.first;
			int colum = c + dir.second;

			while (correcta(fila, colum) && m[fila][colum] != PARED && fila >= limiteinf && fila <= limitesup &&
				colum >= liminfc && colum <= limsupc) {
				if (m[fila][colum] == ENTRADA) {
					entrada_vigilada = true;
				}
				else if (m[fila][colum] == SALIDA) {
					salida_vigilada = true;
				}
				else if (!isdigit(m[fila][colum])) {
					m[fila][colum] = CASILLA_VIGILADA;
				}
				colum += dir.second;
				fila += dir.first;
			}
			
			
		}
	}

	

	void bfs(vector<vector<char>>& m, int fila, int columna) {
		queue<sim> cola;
		marked[fila][columna] = true;
		cola.push({ fila,columna });
		while (!cola.empty() && !path_to_exit()) {
			sim actual = cola.front(); cola.pop();
			for (auto dir : dirs) {
				int filady = dir.first + actual.filita;
				int colady = dir.second + actual.columni;
				if (correcta(filady, colady) && !marked[filady][colady] && m[filady][colady] != CASILLA_VIGILADA &&
					m[filady][colady] != PARED) {
					marked[filady][colady] = true;
					distTo[filady][colady] = distTo[actual.filita][actual.columni] + 1;
					cola.push({ filady,colady });
				}
			}
		}
	}

};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int alto, ancho;
	cin >> ancho >> alto;
	int columna = 0;
	vector<vector<char>> map(alto,vector<char>(ancho));
	cin.ignore();
	if (!std::cin)
		return false;
	string linea;
	for (int i = 0; i < alto; ++i) {
		getline(cin, linea);
		for (char c : linea) {
			map[i][columna++] = c;
		}
		columna = 0;
	}

	
	camino c(map);

	if (c.path_to_exit()) {
		cout << c.distance() << '\n';
	}
	else {
		cout << "NO" << '\n';
	}


	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
