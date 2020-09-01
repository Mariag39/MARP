// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
#include <queue>
#include <vector>
#include "Grafo.h"
#include <string>
#include "ConjuntosDisjuntos.h"
using namespace std;


using Mapa = vector<vector<char>>;

const vector<pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };

class petroleo {
public:
	petroleo(Mapa & g):marked(g.size(),vector<bool>(g[0].size(),false)), maximo_(0),F(g.size()),
	C(g[0].size()), num_(0), d(F*C){
		for (int i = 0; i < F; i++) {
			for (int j = 0; j < C; j++) {
				if (g[i][j] == '#' && !marked[i][j]) {
					++num_;
					int nuevotam = 0;
					dfs(g, i, j, nuevotam);
					maximo_ = max(maximo_, nuevotam);
				}
			}
		}
	}

	int numero() const { return num_; }
	int maximo() const { return maximo_; }

	void conjunto(int f, int c, Mapa const& m) {
		marked[f][c] = true;
		bool unidos = true;
		int pos = f * C + c;
		for (auto dir : dirs) {
			int ni = f + dir.first;
			int nj = c + dir.second;
			if (correcta(ni, nj) && marked[ni][nj] && m[ni][nj] == '#' ) {
				unidos = false;
				int aUnir = ni * C + nj;
				d.unir(pos, aUnir);
				maximo_ = max(maximo_, d.tam(aUnir));
			}
		}
		if (unidos) {
			maximo_ = max(maximo_, d.tam(pos));
		}
		
		
	}




private:
	int F, C;
	vector<vector<bool>> marked;
	ConjuntosDisjuntos d;
	int num_;
	int maximo_;

	bool correcta(int i, int j) const {
		return 0 <= i && i < F && 0 <= j && j < C;
	}

	void dfs(Mapa const& m, int i, int j, int& tam) {
		marked[i][j] = true;
		++tam;
		int unir = i * C + j;
		for (auto dir : dirs) {
			int ni = i + dir.first;
			int nj = j + dir.second;
			if (correcta(ni, nj) && m[ni][nj] == '#' && !marked[ni][nj]) {
				int posx = ni * C + nj;
				d.unir(unir, posx);
				dfs(m, ni, nj, tam);
			}
		
		}
	}

};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int F, C;
	cin >> F >> C;
	
	
	
	if (!std::cin) {
		return false;
	}
	cin.ignore();

	Mapa m(F, vector<char>(C, 0));
	string linea;
	int columna = 0;
	for (int i = 0; i < F; i++) {
		getline(cin, linea);
		for (char c : linea) {
			m[i][columna++] = c;
		}
		columna = 0;
	}

	petroleo p(m);
	cout << p.maximo() << " ";
	int n; 
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		a--;
		b--;
		m[a][b] = '#';
		p.conjunto(a, b, m);
		cout << p.maximo() << " ";
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
		
	};


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}