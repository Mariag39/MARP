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
using Mapa = vector<vector<char>>;
const int INFINITO = 1000000;
#define ARBOL '#'
#define CAPERUCITA 'C'
#define LOBO 'L'
#define IMPOSIBLE 'N'


class caperuza {
public:
	caperuza(Mapa & m) : marked(m.size(),vector<bool>(m[0].size(),false)), F(m.size()),C(m[0].size()), 
		imposibol(false), trampas(0), haytrampa(true){
		alrededor(m, lobo);
		if (!imposibol) {
			
			while (haytrampa) {
				haytrampa = false;
				dfs(m, lobo.first, lobo.second);
				
				
			}
			
		}
		
	}

	int solucion() {
		return trampas;
	}

	bool haysolucion() {
		return imposibol;
	}

private:
	vector<vector<bool>> marked;
	int F, C;
	bool imposibol;
	bool haytrampa;
	pair<int, int> caperucita;
	pair<int, int> lobo;
	int trampas;
	bool correcta(int i, int j) const {
		return 0 <= i && i < F && 0 <= j && j < C;
	}
	const vector<pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1} };

	void alrededor(Mapa& m, pair<int,int>& lobo) {
		for (int i = 0; i < F; i++) {
			for (int j = 0; j < C; j++) {
				if (m[i][j] == LOBO) {
					lobo = make_pair(i, j);
				}
				else if (m[i][j] == CAPERUCITA) {
					caperucita = make_pair(i,j);
					for (auto dir : dirs) {
						int f = i + dir.first;
						int c = j + dir.second;
						if (correcta(f, c) && m[f][c] != ARBOL) {
							if (m[f][c] == LOBO) {
								imposibol = true;
								return;
							}
							m[f][c] = IMPOSIBLE;
						}
						
					}
				}
			}
		}
	}

	void dfs(Mapa const & m, int i, int j) {
		marked[i][j] = true;
		for (auto dir : dirs) {
			int ni = i + dir.first, nj = j + dir.second;
			if (correcta(ni, nj) && m[ni][nj] != ARBOL && !marked[ni][nj]) {
				if (m[ni][nj] == IMPOSIBLE) { 
					m[i][j] == ARBOL;
					haytrampa = true;
					trampas++;
					break;
				}
				dfs(m, ni, nj);
			}
		}
	}



};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int N, M;
	cin >> N >> M;
	if (!std::cin) {
		return false;
	}
	cin.ignore();
	Mapa m(N,vector<char>(M));
	string linea;
	int columna = 0;
	
	for (int i = 0; i < N; ++i) {
		getline(cin, linea);
		for (char c : linea) {
			m[i][columna++] = c;
		}
		columna = 0;
	}

	caperuza c(m);
	if (!c.haysolucion()) cout << c.solucion() << '\n';
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