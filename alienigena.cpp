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

struct alien {
	int c;
	int f;
};

bool operator <(alien const& a, alien const& b) {
	return a.c > b.c;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int C,F,N;
	cin >> C >> F >> N;
	if (!std::cin || N == 0 && C == 0 && F == 0) {
		return false;
	}
	
	int a, b;
	vector<pair<int, int>> trabajos(N);
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		trabajos[i] = make_pair(a, b);
	}

	sort(trabajos.begin(), trabajos.end(), less<pair<int, int>>());
	int trabajo = 0;
	
	int izq = C;
	int der = C;
	int i = 0;
	bool noposible = false;
	bool exito = false;
	if (trabajos[0].first > izq) noposible = true;

	while (der < F && i < N && !noposible) {
		if (trabajos[i].first <= izq) {
			if (trabajos[i].second > der) {
				der = trabajos[i].second;
				exito = true;
			}
			
		}else{
			if (exito) {
				exito = false;
				trabajo++;
				izq = der;
				i--;
				
			}
			else break;
		}
		i++;
	}
	
	if(der < F || noposible) cout << "Imposible" << '\n';
	else if (exito) {
		trabajo++;
		cout << trabajo++ << '\n';
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

	};


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}