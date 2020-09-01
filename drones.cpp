// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

using namespace std;



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int N, A, B = 0;
	cin >> N >> A >> B;
	if (!std::cin || N < 1 || A < 1 || B < 1)
		return false;
	priority_queue<int> nine;
	priority_queue<int> onehalf;
	vector<int> drones, v9,v1;
	int n, o;
	for (int i = 0; i < A; i++) {
		cin >> n;
		nine.push(n);
	}
	for (int i = 0; i < B; i++) {
		cin >> o;
		onehalf.push(o);
	}
	
	int prim1, prim = 0;
	while (nine.size() > 0 && onehalf.size() > 0) {
		int minimo = 0;
		for (int i = 0; i < N; i++) {
			int a = nine.top(); nine.pop();
			int b = onehalf.top(); onehalf.pop();
			minimo += min(a, b);
			if (a < b) {
				b -= a;
				v1.push_back(b);
			}
			else if (b < a) {
				a -= b;
				v9.push_back(a);
			}

			if (nine.size() == 0 || onehalf.size() == 0) break;
		}

		for (int i = 0; i < v1.size(); i++) onehalf.push(v1[i]);
		for (int i = 0; i < v9.size(); i++) nine.push(v9[i]);
		v1.clear(); v9.clear();
		drones.push_back(minimo);
	}
	
	for (int i = 0; i < drones.size(); i++) {
		if (i == 0) cout << drones[i];
		else {
			cout << " ";
			cout << drones[i];
		}
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