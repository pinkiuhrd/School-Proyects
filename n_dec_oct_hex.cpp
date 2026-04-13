#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;
//a menor cantidad de funciones posibles
// Función para validar si el número corresponde a la base que se seleccione
bool esValido(string num, int base) {
    for (char c : num) {
        if (base == 2 && (c != '0' && c != '1')) return false;
        if (base == 8 && (c < '0' || c > '7')) return false;
        if (base == 10 && !isdigit(c)) return false;
        if (base == 16 && !isdigit(c) && (toupper(c) < 'A' || toupper(c) > 'F')) return false;
    }
    return true;
}

// Eta' funcion convierte cualquier base a decimal
int aDecimal(string num, int base) {
    int resultado = 0;
    int potencia = 1;

    for (int i = num.length() - 1; i >= 0; i--) {
        char c = toupper(num[i]);
        int valor;

        if (isdigit(c))
            valor = c - '0';
        else
            valor = c - 'A' + 10;

        resultado += valor * potencia;
        potencia *= base;
    }

    return resultado;
}

// Eta' otra funcion convierte de decimal a cualquier base
string desdeDecimal(int num, int base) {
    if (num == 0) return "0";

    string resultado = "";

    while (num > 0) {
        int residuo = num % base;

        if (residuo < 10)
            resultado += (residuo + '0');
        else
            resultado += (residuo - 10 + 'A');

        num /= base;
    }

    reverse(resultado.begin(), resultado.end());
    return resultado;
}

//funcion para leer las bases que sean validas
int leerBase() {
    int opcion;

    while (true) {
        cout << "1.Binario\n 2.Octal\n 3.Decimal\n 4.Hexadecimal\n";
        cin >> opcion;

        // Verifica si hubo error
        if (cin.fail()) {
            cout << "Error: Debes ingresar un numero.\n";

            cin.clear(); // limpia error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia buffer
            continue;
        }

        // Verifica rango válido
        if (opcion < 1 || opcion > 4) {
            cout << "Error: opcion fuera de rango.\n";
            continue;
        }

        return opcion;
    }
}

// programa principal
int main() {
    int opcion;

    do {
        cout << "\n--- CONVERSOR DE BASES ---\n";
        cout << "Escoja entre las opciones una base numerica de origen para continuar...\n";


        int baseOrigen = leerBase();

        cout << "Ingrese el numero acuerdo a su base: ";
        string numero;
        cin >> numero;

        cout << "Seleccione base de destino: ";
        int baseDestino = leerBase();

        int bases[] = {2, 8, 10, 16};

        if (baseOrigen < 1 || baseOrigen > 4 || baseDestino < 1 || baseDestino > 4) {
            cout << "Error: seleccion de base invalida.\n";
        } else {
            int bOrigen = bases[baseOrigen - 1];
            int bDestino = bases[baseDestino - 1];

            if (!esValido(numero, bOrigen)) {
                cout << "Error: numero invalido para la conversion de base seleccionada.\n";
            } else {
                int decimal = aDecimal(numero, bOrigen);
                string resultado = desdeDecimal(decimal, bDestino);

                cout << "Resultado: " << resultado << endl;
            }
        }

        cout << "\nDesea realizar otra conversion? ([1] = si, [cualquier tecla] = no): ";
        cin >> opcion;
    } while (opcion == 1);



    cout << "Programa finalizado bye.w.\n";
    return 0;
}