#include "Ejercicio02.h"
#include <vector>
#include <queue>

int Ejercicio02::countStudents(std::vector<char*> students, std::vector<char*> sandwiches) {
    std::queue<char*> studentQueue;

    // Llenamos la cola con las preferencias de los estudiantes.
    for (auto preference : students) {
        studentQueue.push(preference);
    }

    int sandwichesIndex = 0;
    int rejectCount = 0; // Para contar cuántos estudiantes consecutivos rechazan el sandwich actual.

    while (!studentQueue.empty()) {
        char* currentStudentPreference = studentQueue.front();

        if (*currentStudentPreference == *sandwiches[sandwichesIndex]) {
            // El estudiante toma el sandwich.
            studentQueue.pop();
            sandwichesIndex++;
            rejectCount = 0; // Reiniciar el contador de rechazos.
        }
        else {
            // El estudiante rechaza el sandwich y va al final de la cola.
            studentQueue.pop();
            studentQueue.push(currentStudentPreference);
            rejectCount++;

            // Si todos los estudiantes restantes han rechazado el sandwich actual.
            if (rejectCount == studentQueue.size()) {
                break; // Salir del bucle.
            }
        }
    }

    // Retorna el número de estudiantes que no pudieron obtener un sandwich.
    return studentQueue.size();
}
