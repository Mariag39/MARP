#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string>
#include <queue>
using namespace std;
//O(Nlog N + K log N), donde N es el número de
//usuarios y K el número de consultas
struct usuario {
	int id;
	int frec;
	int momento;
};

bool operator<(usuario const& a, usuario const& b) {
	return a.momento > b.momento ||
		(a.momento == b.momento && a.id > b.id);
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int casos;
	cin >> casos;
	if (casos == 0) {
		cout << "---" << endl;
		return false;
	}
	
		priority_queue<usuario> cola;
		for (int i = 0; i < casos; ++i) {
			int id;
			int frec;
			cin >> id >> frec;
			cola.push({ id,frec,frec});

		}
		int llama;
		cin >> llama;
		while(llama--) {
			usuario p = cola.top();
			cola.pop();
			cout << p.id << endl;
			p.momento += p.frec;
			cola.push(p);
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


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}