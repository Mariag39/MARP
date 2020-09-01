// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

using namespace std;

struct fila {
	int index;
	int valor;
};

bool operator<(fila const& a, fila const& b) {
	return (a.valor > b.valor || a.valor == b.valor && a.index > b.index);
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int N,C = 0;
	cin >> N >> C;
	if (!std::cin || N == 0 && C == 0)
		return false;
	priority_queue<fila> cajas;
	int p;
	for (int i = 0; i < N; i++) {
		cajas.push({ i,0 });
	}

	for(int i = 0; i < C; i++){
		fila f = cajas.top(); cajas.pop();
		cin >> p;
		f.valor = p;
		cajas.push(f);
	}

	cout << cajas.top().index + 1 << '\n';

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