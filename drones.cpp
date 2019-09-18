// Maria Garcia
// MARP17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;



bool resuelveCaso() {
	int n, a, b;
	cin >> n >> a >> b;
	if (!cin || n < 1 || a < 1 || b < 1) {
		return false;
	}
	else {
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
		vector<int> res, v9, v1;
		int primn, primuno;
		int i = 0;

		while (nueve.size() > 0 && uno_medio.size() > 0) {
			int minimo = 0;
			for (int i = 0; i < n; i++) {
				primn = nueve.top(); nueve.pop();
				primuno = uno_medio.top(); uno_medio.pop();

				minimo += min(primn, primuno);

				if (primn < primuno) {
					primuno -= primn;
					v1.push_back(primuno);
					//uno_medio.push(primuno);
				}
				else if (primn > primuno) {
					primn -= primuno;
					v9.push_back(primn);
					//nueve.push(primn);
				}
				if (nueve.size() == 0 || uno_medio.size() == 0) break;
			}
			for (unsigned int i = 0; i < v1.size(); i++) uno_medio.push(v1[i]);
			for (unsigned int i = 0; i < v9.size(); i++) nueve.push(v9[i]);
			v1.clear(); v9.clear();
			res.push_back(minimo);

		}

		for (unsigned int i = 0; i < res.size(); i++) {
			if (i == 0) cout << res[i];
			else {
				cout << " ";
				cout << res[i];
			}
		}
		cout << '\n';
	}
	return true;
	

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef domjudge
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso()) {}
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
