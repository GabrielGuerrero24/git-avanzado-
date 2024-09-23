#include <iostream>
using namespace std;

string palabrarandom_nivelfacil()
{
    string palabrasfaciles[5] = {"gato", "perro", "casa", "arbol", "sol"};
    int n;

    cout << "Por favor, ingresa un número entre 0 y 4 para seleccionar una palabra aleatoria: ";
    cin >> n;

    return palabrasfaciles[n];
}

void Status_actual(const string palabra_adivinar, int intentosrest)
{
    cout << "Palabra: " << palabra_adivinar << " | Intentos restantes: " << intentosrest << "\n";
}

int Ahorcado_facil()
{
    string palabra_orig = palabrarandom_nivelfacil();

    string palabra_adivinar(palabra_orig.length(), '_');

    int intenteosrest = 10;

    char intento_partcipante;

    while (intenteosrest > 0 && palabra_adivinar != palabra_orig)
    {
        Status_actual(palabra_adivinar, intenteosrest);
        cout << "Introduce una letra: ";
        cin >> intento_partcipante;77

        bool letra_correcta = false;

        for (int i = 0; i < palabra_orig.length(); i++)
        {
            if (palabra_orig[i] == intento_partcipante)
            {
                palabra_adivinar[i] = intento_partcipante;
                letra_correcta = true;
            }
        }

        if (!letra_correcta)
        {
            intenteosrest--;
        }
    }

    if (palabra_adivinar == palabra_orig)
    {
        cout << "¡Felicidades! Has adivinado la palabra: " << palabra_orig << "\n";
        return 5;
    }
    else
    {
        cout << "Lo siento, te has quedado sin intentos. La palabra era: " << palabra_orig << "\n";
        return 0;
    }
}

int main()
{
    Ahorcado_facil();
    return 0;
}