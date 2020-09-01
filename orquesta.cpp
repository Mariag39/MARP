// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

//O(plogn)

struct partituras {
	int part;
	int musicos;
	int ini;
};

bool operator <(partituras const& a, partituras const& b) {
	return (a.musicos < b.musicos);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int p,n;
	cin >> p >> n;
	if (!std::cin) {

		return false;
	}
	priority_queue<partituras> atril;
	int ins;
	for (int i = 0; i < n; i++) {
		cin >> ins;
		atril.push({ 2, ins, ins });
	}

	p -= n;

	
	
	while (p--) {
		partituras t = atril.top(); atril.pop();
		if (t.ini % t.part == 0) {
			t.musicos = t.ini / t.part;
			atril.push({t.part++,t.musicos});
		}
		else {
			t.musicos = t.ini % t.part;
			atril.push({t.part++,t.musicos});
		}
	}
	
	
	cout << atril.top().musicos << '\n';
	
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}