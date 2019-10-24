// María García Raldúa
// MARP17

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Grafo.h"
#include <algorithm>
#include <vector>
#include <istream>
#include "ConjuntosDisjuntos.h"
#include <string>

using namespace std;



class Manchas {
public:
	Manchas(vector<vector<char>> const & M, int f, int c) : F(f), C(c),
		marked(F, vector<bool>(C, false)), _maximo(0),set(f * c),map(M) {
		
			for (int i = 0; i < F; ++i) {
				for (int j = 0; j < C; ++j) {
					if (M[i][j] == '#' && !marked[i][j]) {

						int nuevotam = 0;
						dfs(M, i, j, nuevotam);
						_maximo = max(_maximo, nuevotam);
					}
				}
			}
	
	}
	void actualiza(int i, int j) {
		map[i][j] = '#';
		marked[i][j] = true;
		bool unidos = true;
		int posicion = i * C + j;
		for (auto dir : dirs) {
			int ni = i + dir.first;
			int nj = j + dir.second;
			if (correcta(ni, nj) && marked[ni][nj] && map[ni][nj] == '#') {
				unidos = false;
				int aUnir = ni * C + nj;
				set.unir(posicion, aUnir);
				_maximo = max(_maximo, set.tam(aUnir));
			}
		}
		if (unidos) {
			_maximo = max(_maximo, set.tam(posicion));
		}
	}
	int maximo() const { return _maximo; }
private:
	int F, C; 
	vector<vector<char>> map;
	vector<vector<bool>> marked; 
	int _maximo; 
	ConjuntosDisjuntos set;
	bool correcta(int i, int j) const {
		return 0 <= i && i < F && 0 <= j && j < C;
	}
	const vector<pair<int, int>> dirs = { {0,1},{-1,0},{0,-1},{1,0},{1,1},{-1,1},{-1,-1},{1,-1}};
	// recorrido en profundidad de la mancha del vértice <i,j>
	void dfs(vector<vector<char>> const& M, int i, int j, int & tam) {
		marked[i][j] = true;
		++tam;
		int unir = i * C + j;
		for (auto d : dirs) {
			int ni = i + d.first, nj = j + d.second;
			if (correcta(ni, nj) && M[ni][nj] == '#' && !marked[ni][nj]) {
				int posx = ni * C + nj;
				set.unir(unir, posx);
				dfs(M, ni, nj, tam);
				
			}
	
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int F, C;
	cin >> F >> C; // número de filas y columnas
	int columna = 0;
	bool segundo = false;
	if (!cin)
		return false;
	vector<vector<char>> mapa(F, vector<char>(C));
	cin.ignore();
	if (!std::cin)
		return false;
	string linea;
	int enf, enc = 0;
	for (int i = 0; i < F; ++i) {
		getline(cin, linea);
		for (char c : linea) {
			mapa[i][columna++] = c;
		}
		columna = 0;
	}

	// y la analizamos
	Manchas manchas(mapa,F,C);
	cout << manchas.maximo() << " ";
	int n, fila, colum;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> fila >> colum;
		fila--;
		colum--;
		manchas.actualiza(fila, colum);
		
		cout << manchas.maximo() << " ";

		
	}
	cout << '\n';

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

	}
	


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
