#include "Ejercicio03.h"

MinStack::MinStack() {}

void MinStack::push(int value) {
    mainStack.push_back(value);
    // Si el valor es menor o igual al elemento superior de minStack o si minStack está vacío
    if (minStack.empty() || value <= minStack.back()) {
        minStack.push_back(value);
    }
}

void MinStack::pop() {
    if (mainStack.empty()) return;

    // Si el valor a eliminar es igual al elemento superior de minStack, eliminar de ambos
    if (mainStack.back() == minStack.back()) {
        minStack.pop_back();
    }
    mainStack.pop_back();
}

int MinStack::top() {
    if (!mainStack.empty()) {
        return mainStack.back();
    }
    return -1; 
}

int MinStack::getMin() {
    if (!minStack.empty()) {
        return minStack.back();
    }
    return -1;  
}
