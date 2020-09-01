// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int first,duo = 0;
	cin >> first >> duo;
	if (!std::cin || first == 0 && duo == 0) {
		cout << 0 << " " << 0 << '\n';
		return false;
	}
	priority_queue<int,vector<int>,greater<int>> mayores;
	priority_queue<int> menores;
	int a, b;
	for (int i = 0; i < duo; i++) {
		cin >> a >> b;
		if (first > a) menores.push(a);
		else mayores.push(a);
		if (first > b) menores.push(b);
		else mayores.push(b);

		if (mayores.size() > menores.size()) {
			int n = mayores.top(); mayores.pop();
			menores.push(first);
			first = n;
		}else if (mayores.size() < menores.size()) {
			int n = menores.top(); menores.pop();
			mayores.push(first);
			first = n;
		}

		cout << first << " ";
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


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}