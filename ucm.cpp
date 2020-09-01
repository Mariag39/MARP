﻿// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

using namespace std;

struct ucm {
	int periodo;
	int usuario;
	int cola;
};


bool operator<(ucm const& a, ucm const& b) {
	return (a.cola > b.cola || a.cola == b.cola && a.usuario > b.usuario);
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num = 0;
	cin >> num;
	if (!std::cin || num == 0)
		return false;
	priority_queue<ucm> unidad;
	int id;
	int per;
	for (int i = 0; i < num; i++) {
		cin >> id;
		cin >> per;
		unidad.push({per,id,per});
	}

	int consultas;
	cin >> consultas;

	while (consultas--) {
		ucm u = unidad.top(); unidad.pop();
		cout << u.usuario << '\n';
		u.cola += u.periodo;
		unidad.push(u);
	}

	

	cout << "----" << '\n';
	




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