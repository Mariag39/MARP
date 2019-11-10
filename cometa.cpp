// María García Raldúa
// MARP17

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <istream>
#include <queue>
#include <string>


using namespace std;

#define INF 1e9

bool esPosible(vector<int> const &M, int const &L) { //O(C) en espacio adicional
	int n = M.size();
	vector<bool> posible(L + 1, false);
	posible[0] = true;
	for (int i = 1; i <= n; ++i) {
		for (int j = L; j >= 1; --j) {
			if (M[i - 1] <= j)
				posible[j] = posible[j] || posible[j - M[i - 1]];
		}
	}
	return posible[L];
}


int numFormas(vector<int> const &M, int const &L) { //O(C) en espacio adicional
	int n = M.size();
	vector<int> formas(L + 1, 0);
	formas[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = L; j >= 1; --j) {
			if(M[i - 1] <= j)
				formas[j] = formas[j] + formas[j - M[i - 1]];
		}
	}
	return formas[L];
}

int minPrecio(vector<int> const &M, vector<int> const &p, int const &C){ //O(C) en espacio adicional
	vector<int> precio(C + 1, 1e9);
	precio[0] = 0;

	for (int i = 1; i <= M.size(); ++i) {
		for (int j = C; j >= 1; --j) {
			if (M[i - 1] <= j)
			precio[j] = min(precio[j], precio[j - M[i - 1]] + p[i - 1]);
		}
	}
	return precio[C];
}


int minNum(vector<int> const &M, int const &C) { //Coste: O(nC) en tiempo y O(C) en espacio adicional
	int n = M.size();
	vector<int> cuerdas(C + 1, 1e9);
	cuerdas[0] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = C; j >= 1; --j) {
			if(M[i - 1] <= j)
			cuerdas[j] = min(cuerdas[j], cuerdas[j - M[i - 1]] + 1);
		}
	}
	return cuerdas[C];

}

bool resuelveCaso() {
	int N, L;
	cin >> N;
	cin >> L; 
	
	if (!cin || N < 1 || L < 1)
		return false;
	vector<int> M(N + 1,0);
	vector<int> p(N + 1,0);
	for (size_t i = 1; i < N + 1; ++i) {
		cin >> M[i];
		cin >> p[i];
	}

	if (esPosible(M, L)) {
		cout << "SI " << numFormas(M, L) << " " << minNum(M, L) << " " << minPrecio(M,p, L) << '\n';
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

	while (resuelveCaso()) {

	}



	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
