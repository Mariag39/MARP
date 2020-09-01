// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
#include <queue>
#include <vector>
#include <string>



using namespace std;

//O(nlogn)




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int N,V;
	cin >> N >> V;
	if (!std::cin || N == 0) {
		return false;
	}
	vector<int> coches(N);
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		coches[i] = x;
	}

	sort(coches.begin(),coches.end(), less<int>());

	int ncoches = 0;
	int fin = N - 1;
	int a = 0;
	
	while (a < N) {
		if (coches[a] + coches[fin] >= V) {
			ncoches++;
			a++;
		}
	}

	for (int i = fin; i > a; i--) {
		if (coches[a] + coches[i] >= V) {
			ncoches++;
			a++;
		}
	}

	cout << ncoches << '\n';

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