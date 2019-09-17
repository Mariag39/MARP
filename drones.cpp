// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;



bool resuelveCaso() {
	long int n, a, b;
	cin >> n >> a >> b;
	if (!cin && n == 0 && a == 0 && b == 0) {
		return false;
	}
	priority_queue<int> nueve;
	priority_queue<int> uno_medio;
	for (int i = 0; i < a; i++) {
		int nums;
		cin >> nums;
		nueve.push(nums);
	}
	for (int i = 0; i < b; i++) {
		int nn;
		cin >> nn;
		uno_medio.push(nn);
	}
	vector<int> res;
	int primn, primuno;
	int i = 0;
	int minimo = 0;
	while(!nueve.empty() && !uno_medio.empty()){
		for (int i = 0; i < n; i++) {
			primn = nueve.top();
			primuno = uno_medio.top();
			nueve.pop();
			uno_medio.pop();
			minimo += min(primn, primuno);
			if (primn < primuno) {
				primuno -= primn;
				uno_medio.push(primuno);
			}
			else if (primn > primuno) {
				primn -= primuno;
				nueve.push(primn);
			}
			if (nueve.empty() || uno_medio.empty()) break;
		}
		res.push_back(minimo);
		minimo = 0;
	}
	
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
		cout << " ";
	}
	cout << endl;
	
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 
//
//
	while (resuelveCaso())
		;
//
//
//	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	system("PAUSE");
//#endif

	return 0;
}