#include <iostream>
#include <limits>
using namespace std;

// Función recursiva principal
void hanoi(int n, char origen, char auxiliar, char destino, int &contador) {
    if (n == 1) {
        contador++;
        cout << "Movimiento " << contador << ": Mover disco 1 de "
             << origen << " a " << destino << endl;
        return;
    }

    // Mover n-1 discos a torre auxiliar
    hanoi(n - 1, origen, destino, auxiliar, contador);

    // Mover el disco restante
    contador++;
    cout << "Movimiento " << contador << ": Mover disco " << n
         << " de " << origen << " a " << destino << endl;

    // Mover los n-1 discos a torre destino
    hanoi(n - 1, auxiliar, origen, destino, contador);
}

int main() {
    int discos;
    char opcion;
cout <<"----Programa para mostrar las soluciones optimas de las torres hanoi----\n";
    do {
        // Validación de entrada
        do {
            cout << "Ingrese el numero de discos (3 - 7): ";
            cin >> discos;
            if (cin.fail()) {
                cout << "Error: Debes ingresar un numero.\n";

                cin.clear(); // limpia error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia buffer
                continue;
            }
        } while (discos < 3 || discos > 7);

        int movimientos = 0;

        cout << "\nResolviendo Torres de Hanoi con " << discos << " discos:\n" << endl;

        // Llamada a la función recursiva
        hanoi(discos, 'A', 'B', 'C', movimientos);

        // Mostrar total de movimientos
        cout << "\nTotal de movimientos realizados: " << movimientos << endl;
        cout << "Movimientos minimos estandarizados: " << ( (1 << discos) - 1 ) << endl;

        // Preguntar si desea repetir
        cout << "\nDesea intentarlo con otro numero de discos? ([s] = si/[cualquier tecla]= no): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    cout << "Programa finalizado." << endl;

    return 0;
}