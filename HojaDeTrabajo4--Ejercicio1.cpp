#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <string>

using namespace std;

void menu();
void escribir();
void leer();

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
				leer();
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
void escribir(){
	int hecta[10000], monto, tipo[1000];
	int contMalaHier = 0, contLang = 0, contGus = 0, contTodo = 0;
	int sumMalaHier = 0, sumLang = 0, sumGus = 0, sumTodo = 0;
	int n, mayor = 0;

	ofstream archivo;
	archivo.open("Empresa_Fumigadora.txt", ios::app);

	if (archivo.fail()) {
		cout << "FALLO EN EL ARCHIVO" << endl;
		exit(1);
	}

	cout << "Ingrese Cantidad De Fumigaciones: "; cin >> n;
	cout << "TIPO    -    SERVICIO          -     COSTO X HECTAREA" << endl;
	cout << " 1      -    MALA HIERBA       -     10.00" << endl;
	cout << " 2      -    LANGOSTAS         -     20.00" << endl;
	cout << " 3      -    GUSANOS           -     30.00" << endl;
	cout << " 4      -    TODO LO ANTERIOR  -     50.00" << endl;
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "Fumigacion[" << i + 1 << "] Ingrese Que Tipo De Servicio Desea: "; cin >> tipo[i];
		cout << "Fumigacion[" << i + 1 << "] Ingrese El Numero De Hectareas: "; cin >> hecta[i];

		archivo << "Fumigacion[" << i + 1 << "]" << endl;
		archivo << "TIPO DE SERVICIO: " << tipo[i] << endl;
		archivo << "NUMERO DE HECTAREAS: " << hecta[i] << endl;

		if (tipo[i] == 1) {
			contMalaHier++;
			if (hecta[i] <= 500) {
				monto = (10 * hecta[i]);
			}
			if (hecta[i] > 500) {
				monto = (10 * hecta[i]) - (10 * hecta[i] * 0.05);
			}
			if (monto > 1500) {
				monto = (monto)-(monto * 0.10);
			}
			sumMalaHier += monto;
		}
		if (tipo[i] == 2) {
			contLang++;
			if (hecta[i] <= 500) {
				monto = (20 * hecta[i]);
			}
			if (hecta[i] > 500) {
				monto = (20 * hecta[i]) - (20 * hecta[i] * 0.05);
			}
			if (monto > 1500) {
				monto = (monto)-(monto * 0.10);
			}
			sumLang += monto;
		}
		if (tipo[i] == 3) {
			contGus++;
			if (hecta[i] <= 500) {
				monto = (30 * hecta[i]);
			}
			if (hecta[i] > 500) {
				monto = (30 * hecta[i]) - (30 * hecta[i] * 0.05);
			}
			if (monto > 1500) {
				monto = (monto)-(monto * 0.10);
			}
			sumGus += monto;
		}
		if (tipo[i] == 4) {
			contTodo;
			if (hecta[i] <= 500) {
				monto = (50 * hecta[i]);
			}
			if (hecta[i] > 500) {
				monto = (50 * hecta[i]) - (50 * hecta[i] * 0.05);
			}
			if (monto > 1500) {
				monto = (monto)-(monto * 0.10);
			}
			sumTodo += monto;
		}
		if (mayor > tipo[i]) {
			mayor = tipo[i];
		}
		archivo << "Monto FUMIGACION[" << i + 1 << "]:" << monto << endl;
		archivo << endl;
		archivo << "Cantidad de Servicios MALA HIERBA: " << contMalaHier << endl;
		archivo << "Cantidad de Servicios LANGOSTAS: " << contLang << endl;
		archivo << "Cantidad de Servicios GUSANOS: " << contGus << endl;
		archivo << "Cantidad de Servicios TODO LO ANTERIOR: " << contTodo << endl;
		archivo << "El tipo con mayor demanda es: " << mayor << endl;
		archivo << "El Monto total es: " << sumMalaHier + sumLang + sumGus + sumTodo << endl;
		archivo << endl << endl;
		cout << "Monto FUMIGACION[" << i + 1 << "]:" << monto << endl;
		cout << endl;
	}
}
void leer() {
	cout << "---DATOS DEL ARCHIVO---" << endl;
	ifstream archivo;
	string aux;

	archivo.open("Empresa_Fumigadora.txt", ios::in);

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
