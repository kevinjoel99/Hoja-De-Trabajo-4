#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <string>

using namespace std;

void menu();
void escribir();
void mostrar();

int main() {
	menu();
	system("pause");
}
void menu() {
	int opcion = 0;
	while (opcion != 3) {
		cout << "1 - Ingresar Datos" << endl;
		cout << "2 - Leer y Mostrar Datos" << endl;
		cout << "3 - Salir del Programa" << endl;
		cout << "Ingrese Su Opcion: "; cin >> opcion;
		cout << endl;

		switch (opcion) {
		case 1:
			if (opcion == 1) {
				system("cls");
				escribir();
				system("pause");
			}
		case 2:
			if (opcion == 2) {
				system("cls");
				mostrar();
				system("pause");
			}
		case 3:
			if (opcion == 3) {
				system("cls");
				cout << "Saliendo Del Programa" << endl;
				break;
				system("pause");
			}
		}
	}
}
void escribir() {
	int n, edad[50];
	float ninos = 0, jov = 0, adult = 0, adult_may = 0;
	float porc_ninos = 0, porc_jov = 0, porc_adult = 0, porc_adult_may = 0;
	ofstream archivo;
	archivo.open("Muestreo.txt", ios::out);

	if (archivo.fail()) {
		cout << "FALLO EN EL ARCHIVO" << endl;
		exit(1);
	}
	cout << "Ingrese Cantidad De Datos No MAYOR a 50: "; cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Ingrese Edad Persona[" << i + 1 << "]:"; cin >> edad[i];
		archivo << "Edad Persona[" << i + 1 << "]:" << edad[i] << endl;

		if (edad[i] >= 0 && edad[i] <= 12) {
			ninos++;
		}
		if (edad[i] >= 13 && edad[i] <= 29) {
			jov++;
		}
		if (edad[i] >= 30 && edad[i] <= 59) {
			adult++;
		}
		if (edad[i] >= 60) {
			adult_may++;
		}
	}
	porc_ninos = (100 * ninos) / (n);
	porc_jov = (100 * jov) / (n);
	porc_adult = (100 * adult) / (n);
	porc_adult_may = (100 * adult_may) / (n);
	archivo << "Porcentaje ninos: " << porc_ninos << "%" << endl;
	archivo << "Porcentaje jovenes: " << porc_jov << "%" << endl;
	archivo << "Porcentaje adultos: " << porc_adult << "%" << endl;
	archivo << "Porcentaje aultos mayores: " << porc_adult_may << "%" << endl;
}
void mostrar() {
	float porc_ninos = 0, porc_jov = 0, porc_adult = 0, porc_adult_may = 0;
	cout << "DATOS DEL ARCHIVO" << endl;
	ifstream archivo;
	string aux;
	archivo.open("Muestreo.txt", ios::in);

	if (archivo.fail()) {
		cout << "FALLO EN EL ARCHIVO" << endl;
		exit(1);
	}
	while (!archivo.eof()) {
		getline(archivo, aux);
		cout << aux << endl;
	}
	archivo.close();
}

