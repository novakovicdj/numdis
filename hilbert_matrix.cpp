#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	cout << "Unesite dimenziju matrice n: ";
	int n;
	cin >> n;
	bool pom = false;
	double suma = 0;
	int k = 0;
	double* x = new double[n];
	double* xp = new double[n];
	double* b = new double[n];
	double* y = new double[n];
	double** mat = new double* [n];
	double** U = new double* [n];
	double** L = new double* [n];
	for (int i = 0; i < n; i++) {
		mat[i] = new double[n];
		for (int j = 0; j < n; j++) {
			mat[i][j] = 1. / (i + j + 1);
			suma += mat[i][j];
		}
		x[i] = 1;
		b[i] = suma;
		y[i] = 0;
		xp[i] = 0;
		suma = 0;
		U[i] = new double[n];
		L[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		double m = 0;
		for (int p = i; p < n; p++) {
			if (i) {
				m = mat[p][k] / mat[k][k];
				L[p][k] = m;
				for (int j = 0; j < n; j++)
					mat[p][j] -= m * mat[k][j];
				pom = true;
			}
		}
		if (pom) {
			k++;
			pom = false;
		}
		for (int j = 0; j < n; j++) {
			if (i == j) {
				L[i][j] = 1;
				U[i][j] = mat[i][j];
			}
			else if (j > i) {
				L[i][j] = 0;
				U[i][j] = mat[i][j];
			}
			else if (j < i) {
				U[i][j] = 0;
			}
		}
	}
	suma = 0;
	for (int i = 0; i < n; i++) {
		suma = b[i];
		for (int j = 0; j < i; j++) {
			suma -= L[i][j] * y[j];
		}
		y[i] = suma;
		suma = 0;
	}
	suma = 0;
	cout << endl;
	for (int i = n - 1; i >= 0; i--) {
		suma = y[i] / U[i][i];
		for (int j = n - 1; j > i; j--) {
			suma -= (U[i][j] * xp[j] / U[i][i]);
		}
		xp[i] = suma;
		suma = 0;
	}
	for (int i = 0; i < n; i++) {
		cout << setprecision(5) << xp[i] << " ";
	} cout << endl;
	delete[] x;
	delete[] xp;
	delete[] y;
	delete[] b;
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
		delete[] U[i];
		delete[] L[i];
	}
	delete[] mat;
	delete[] U;
	delete[] L;
	return 0;
}