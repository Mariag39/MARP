// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
#include <queue>
#include <vector>
#include <string>



using namespace std;


int parcheado(vector<int> const & v, int L) {
	int n = v.size();
	int parches = 1;
	int agujero = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i] - agujero > L) {
			parches++;
			
		}
		
			agujero = v[i];
		
	}
	return parches;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int N, L;
	cin >> N >> L;
	if (!std::cin) {
		return false;
	}
	vector<int> agujeros(N);
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		agujeros[i] = a;
	}
	
	int solucion = parcheado(agujeros, L);
	cout << solucion << '\n';
	
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