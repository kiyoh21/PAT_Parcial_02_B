#include "Ejercicio02.h"
#include <vector>

using std::vector;

// Clase auxiliar para representar una cola (FIFO) básica
class Cola {
private:
    vector<char> elementos;

public:
    void encolar(char elem) {
        elementos.push_back(elem);
    }

    char frente() const {
        if (!elementos.empty()) {
            return elementos.front();
        }
        return '\0';  // retorna un valor nulo si la cola está vacía
    }

    void desencolar() {
        if (!elementos.empty()) {
            elementos.erase(elementos.begin());
        }
    }

    bool estaVacia() const {
        return elementos.empty();
    }

    int size() const {
        return elementos.size();
    }
};

int Ejercicio02::countStudents(vector<char>* students, vector<char>* sandwiches) {
    Cola colaEstudiantes;
    for (char preferencia : *students) {
        colaEstudiantes.encolar(preferencia);
    }

    int sandwichesTomados = 0;
    while (!colaEstudiantes.estaVacia() && sandwichesTomados < sandwiches->size()) {
        char sandwichFrente = (*sandwiches)[sandwichesTomados];
        if (colaEstudiantes.frente() == sandwichFrente) {
            // El estudiante toma el sandwich y sale de la cola
            colaEstudiantes.desencolar();
            sandwichesTomados++;
        }
        else {
            // El estudiante vuelve a la cola y espera su turno
            char estudiante = colaEstudiantes.frente();
            colaEstudiantes.desencolar();
            colaEstudiantes.encolar(estudiante);
            // Si después de una vuelta completa nadie ha tomado el sandwich, termina el proceso
            if (colaEstudiantes.frente() == estudiante) {
                break;
            }
        }
    }

    return colaEstudiantes.size();
}
