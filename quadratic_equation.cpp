#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double f(double a) {
	return (pow(a, 2) - 1000 * a + 1);
}
int main() {
	double a = 1;
	double b = -1000;
	double c = 1;
	cout << "Metoda kvadratne formule: " << endl;
	double resenja[2] = { 0 };
	resenja[0] = (-b + sqrt(pow(b, 2) - 4. * a * c)) / (2. * a);
	resenja[1] = (-b - sqrt(pow(b, 2) - 4. * a * c)) / (2. * a);
	if (resenja[0] < resenja[1]) {
		cout << "Manji koren je " << setprecision(10) << resenja[0] << endl;
	}
	else {
		cout << "Manji koren je " << setprecision(10) << resenja[1] << endl;
	}
	cout << "Metod polovljenja intervala: " << endl;
	bool nadjeno = false;
	double pocetak, kraj;
	pocetak = -10;
	kraj = 10;
	int i = 1;
	while (!nadjeno) {
		while (pocetak < kraj) {
			if (f(pocetak) * f(kraj) < 0) {
				nadjeno = true;
				break;
			}
			else {
				pocetak += 1;
				kraj -= 1;
			}
		}
		if (pocetak > kraj) {
			pocetak = -pow(10, ++i);
			kraj = pow(10, i);
		}
	}
	double x = (pocetak + kraj) / 2.;
	i = 0;
	while (pocetak <= kraj) {
		if (f(x) == 0) {
			resenja[i++] = x;
			break;
		}
		else {
			if( f(pocetak) * f(x) < 0) {
				kraj = x;
				x = (pocetak + kraj) / 2.;
			}
			else if (f(x) * f(kraj) < 0) {
				pocetak = x;
				x = (pocetak + kraj) / 2.;
			}
		}
	}
	x = resenja[0] < resenja[1] ? resenja[0] : resenja[1];
	cout << "Manji koren je " << setprecision(10) << x << endl;
	cout << "Metod proste iteracije: " << endl;
	pocetak = -1;
	kraj = 1;
	x = pocetak;
	while (f(x) != 0) {
		x = ((pow(x, 2) + 1) / 1000.);
	}
	cout << "Manji koren je " << setprecision(10) << x << endl;
	cout << "Njutnov metod: " << endl;
	// f(x) = x^2 - 1000x + 1;
	// f'(x) = 2x-1000;
	// x0 =  0.5;
	pocetak = 0;
	kraj = 1;
	x = 0.5; // pocetna vrednost, x0
	while (f(x) != 0) {
		x = x - f(x) / (2 * x - 1000);
	}
	cout << "Manji koren je " << setprecision(10) << x << endl;
	return 0;
}
