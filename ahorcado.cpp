#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para mostrar el estado del ahorcado
void mostrarAhorcado(int intentos) {
    cout << "\nIntentos fallidos: " << intentos << endl;


        switch (intentos){
            case 1:
                cout << "__________\n|         |\n|\n|\n|\n|\n|";
                break;
            case 2:
                cout << "__________\n|         |\n|         0\n|\n|\n|\n|";
                break;
            case 3:
                cout << "__________\n|         |\n|         0\n|         |\n|\n|\n|";
                break;
            case 4:
                cout << "__________\n|         |\n|         0\n|        /|\n|\n|\n|";
                break;
            case 5:
                cout << "__________\n|         |\n|         0\n|        /|\\\n|\n|\n|";
                break;
            case 6:
                cout << "__________\n|         |\n|         0\n|        /|\\\n|        /\n|\n|";
                break;
            case 7:
                cout << "__________\n|         |\n|         0\n|        /|\\\n|        /\\\n|\n|";
                break;
        }
        cout << endl;
    }

// Función para verificar si la letra está en la palabra
bool verificarLetra(string palabra, char letra, string &progreso) {
    bool encontrada = false;

    for (int i = 0; i < palabra.length(); i++) {
        if (palabra[i] == letra) {
            progreso[i] = letra;
            encontrada = true;
        }
    }

    return encontrada;
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    vector<string> palabras = {"computadora", "programacion", "ahorcado", "teclado", "pantalla"};
    char opcion;

    srand(time(0));

    do {
        string palabra;

        int modo;

        cout << "Selecciona modo de juego:\n";
        cout << "1. Palabra aleatoria\n";
        cout << "2. Ingresar palabra\n";
        cout << "Opcion: ";
        cin >> modo;

        if (modo == 1) {
            palabra = palabras[rand() % palabras.size()];
        } else {
            cout << "Ingresa la palabra secreta...: ";
            cin.ignore();
            getline(cin, palabra);

            limpiarPantalla(); // Oculta la palabra
            cout << "Comienza el juego...\n";
        } //para agregar palabra

        string progreso(palabra.length(), '_');

        int intentos = 0;
        const int MAX_INTENTOS = 7;
        vector<char> letrasUsadas;

        cout << "\n=== JUEGO DEL AHORCADO ===\n";

        while (intentos < MAX_INTENTOS && progreso != palabra) {
            cout << "\nPalabra: ";
            for (char c : progreso) {
                cout << c << " ";
            }

            cout << "\nLetras usadas: ";
            for (char l : letrasUsadas) {
                cout << l << " ";
            }

            char letra;
            cout << "\nIngresa una letra: ";
            cin >> letra;

            // Verificar si ya fue usada
            bool repetida = false;
            for (char l : letrasUsadas) {
                if (l == letra) {
                    repetida = true;
                    break;
                }
            }

            if (repetida) {
                cout << "Ya usaste esa letra.\n";
                continue;
            }

            letrasUsadas.push_back(letra);

            if (!verificarLetra(palabra, letra, progreso)) {
                intentos++;
                cout << "Letra incorrecta.\n";
                mostrarAhorcado(intentos);
            } else {
                cout << "¡Bien! Letra correcta.\n";
            }
        }

        if (progreso == palabra) {
            cout << "\n¡Ganaste! La palabra era: " << palabra << endl;
        } else {
            cout << "\nPerdiste. La palabra era: " << palabra << endl;
        }

        cout << "\n¿Deseas jugar de nuevo? (s/n = salir): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    cout << "Gracias por jugar.\n";

    return 0;
}