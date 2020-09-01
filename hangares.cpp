// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

//O(nlogn)

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int H;
	cin >> H;
	if (!std::cin || H < 1) {
		
		return false;
	}
	priority_queue<int> hangares;
	vector<int> aviones;
	int h;
	for (int i = 0; i < H; i++) {
		cin >> h;
		hangares.push(h);
	}
	int N;
	cin >> N;
	if (!std::cin || N < 0) {

		return false;
	}
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		aviones.push_back(a);
	}
	bool nope = false;
	for(int i = 0; i < aviones.size(); i++){
		int hangar = hangares.top(); hangares.pop();
		hangar -= aviones[i];
		if (hangar > 0) {
			hangares.push(hangar);
		}
		else if(hangar < 0) {
			cout << "NO" << '\n';
			nope = true;
			break;
		}
	}
	if(!nope)
		cout << "SI" << '\n';
		

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