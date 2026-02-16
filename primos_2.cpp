// Created by otam6 on 15/02/2026.
#include <iostream>
#include <cmath>    // P()ara usar sqrt()
using namespace std;

    // Función para verificar si un número es primo
    bool esPrimo(int n) {
        if (n < 2)
            return false;

        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int main() {
        int limite;
        cout << "---Ingresa un numero para encontrar sus numeros primos anteriores y la sumatoria---\n";
        cout << "Ingrese un numero entero positivo:\n";
        cin >> limite;

        while (cin.fail()|| limite < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida, ingrsa un numero entero positivo:\n";
            cin >> limite;
        }//while clear

        int suma = 0;
        cout << "\n---Numeros primos encontrados:---\n";

        bool primero = true;

        for (int i = 2; i <= limite; i++) {
            if (esPrimo(i)) {
                cout << i;
                suma += i;

                if (i < limite) {
                    cout << " + ";
                }
            }
        }

        cout << "\n\n---Resultado final:---\n";
        cout << "Suma total de numeros primos hasta: " << limite << " = " << suma << endl;

        return 0;
    }