// María García Raldúa

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include "PriorityQueue.h"
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int h = 0;
	cin >> h;
	PriorityQueue<int> hangares;
	//PriorityQueue<int> aviones;
	if (!std::cin || h == 0)
		return false;
	int x = 0;
	for (int i = 0; i < h; i++) {
		cin >> x;
		hangares.push(x);
	}
	int av = 0;
	cin >> av;
	int numav = 0;
	for (int i = 0; i < av; i++) {
		cin >> numav;
		int hangar = hangares.top();
		hangares.pop();
		if (hangar >= numav) {
			hangar -= numav;
			if(hangar > 0)
				hangares.push(hangar);
		}
		else {
			cout << "NO" << endl;
		}
	}
	cout << "SI" << endl;



	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}