// María García		
// MARP17

//O(Nlog N + K log N), donde N es el número de
//pacientes y K el número de eventos
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "PriorityQueue.h"

using namespace std;

struct paciente {
	string nombre;
	long long int prioridad;
	long long int gravedad;
};

bool operator<(const paciente &a, const paciente &b) {
	return (a.gravedad > b.gravedad || (a.gravedad == b.gravedad && a.prioridad < b.prioridad));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	long long int n = 0;
	long long int cont = 0;
	cin >> n;
	PriorityQueue<paciente> p;
	if (!std::cin)
		return false;
	for (long int i = 0; i < n; i++) {
		char x;
		cin >> x;
		if (x == 'I') {
			string nombre;
			cin >> nombre;
			long long int grav;
			cin >> grav;
			cont++;
			p.push({ nombre,cont, grav });
		}
		else if (x == 'A') {
			paciente pac = p.top();
			cout << pac.nombre << endl;
			p.pop();
				
		}
			
	}
	if (n == 0) {
		cout << "---" << endl;
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