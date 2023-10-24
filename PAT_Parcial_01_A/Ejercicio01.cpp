#include "Ejercicio01.h"

Node<char>* Ejercicio01::remove(Node<char>* head) {
    if (head == nullptr) return nullptr;

    // Creamos dos arreglos para almacenar si ya vimos un caracter.
    bool vistoMayuscula[26] = { false };
    bool vistoMinuscula[26] = { false };

    Node<char>* actual = head;
    Node<char>* anterior = nullptr;

    while (actual != nullptr) {
        bool esDuplicado = false;

        // Verificamos si el caracter es mayúscula.
        if (actual->value >= 'A' && actual->value <= 'Z') {
            if (vistoMayuscula[actual->value - 'A']) {
                esDuplicado = true;
            }
            else {
                vistoMayuscula[actual->value - 'A'] = true;
            }
        }

        // Verificamos si el caracter es minúscula.
        if (actual->value >= 'a' && actual->value <= 'z') {
            if (vistoMinuscula[actual->value - 'a']) {
                esDuplicado = true;
            }
            else {
                vistoMinuscula[actual->value - 'a'] = true;
            }
        }

        if (esDuplicado) {
            // Eliminamos el nodo duplicado.
            if (anterior) {
                anterior->next = actual->next;
            }
            else {
                head = actual->next;
            }
            Node<char>* aEliminar = actual;
            actual = actual->next;
            delete aEliminar;
        }
        else {
            anterior = actual;
            actual = actual->next;
        }
    }

    return head;
}

