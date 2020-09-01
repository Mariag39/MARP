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
	int N;
	cin >> N;
	if (!std::cin || N == 0) {
		return false;
	}
	vector<int> alturas(N);
	vector<int> longitudes(N);
	int a, l;
	for (int i = 0; i < N; i++) {
		cin >> a;
		alturas[i] = a;
	}
	for (int i = 0; i < N; i++) {
		cin >> l;
		longitudes[i] = l;
	}

	sort(alturas.begin(),alturas.end(), greater<int>());
	sort(longitudes.begin(), longitudes.end(), greater<int>());

	int suma_diff = 0;
	for (int j = 0; j < N; j++) {
		int aux = longitudes[j] - alturas[j];
		if (aux < 0) aux = -aux;
		suma_diff += aux;
	}
	cout << suma_diff << '\n';
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