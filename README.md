# Parcial 02

- [Parcial 02](#parcial-02)
  - [Instrucciones](#instrucciones)
  - [Introducción](#introducción)
  - [Ejercicio 1 (20 puntos)](#ejercicio-1-20-puntos)
    - [Ejemplo 1.1](#ejemplo-11)
  - [Ejemplo 1.2](#ejemplo-12)
  - [Ejemplo 1.3](#ejemplo-13)
    - [Restricciones](#restricciones)
  - [Ejercicio 2 (25 puntos)](#ejercicio-2-25-puntos)
    - [Ejemplo 2.1](#ejemplo-21)
  - [Ejemplo 2.2](#ejemplo-22)
    - [Restricciones](#restricciones-1)
  - [Ejercicio 3 (40 puntos)](#ejercicio-3-40-puntos)
    - [Ejemplo 3.1](#ejemplo-31)

## Instrucciones

1. Para iniciar, debe crear un *Fork* del repositorio:

![fork button](images/fork.png)

2. Vaya la pestaña de **actions** de su repositorio. Si ve un botón verde, haga clic en él para poder ejecutar las pruebas en el futuro.

![actions tab](images/actions.png)

3. Clone el nuevo repositorio en su computadora y ábralo en Visual Studio.

4. En el menú de Visual Studio, en la sección de *Build* o *Compilar*, construya la solución.

5. En el menú de Visual Studio, en la sección de Tests, seleccione *Run All Tests*

6. La mayoría de las pruebas deberían fallar.

## Introducción

- Todos los ejercicios deben compilar para poder ser probados. Si por lo menos uno de los ejercicios no compila, la nota será cero.
- Si el código original de un ejercicio no se modifica o la intención de su resolución no es clara, la nota del ejercicicio será de cero puntos, aún si hay pruebas que sí pasen para dicho ejercicio.
- NO agregue nuevos métodos `main()`, de lo contrario ninguna prueba podrá ejecutarse.
- NO cambie la firma de los métodos existentes (no agrege más parámetros ni cambie el nombre), estos son utilizados para probar su código.
- NO haga cambios en las pruebas, esto resulta en un 0 inmediato.
- Para este examen parcial está prohibido utilizar librerías de estructuras de datos lineales como `stack`, `queue`, `list`, etc. Usted debe implementar sus propias estructuras de datos.
- Puede agregar nuevas clases y/o archivos, como sea necesario.
- Las definiciones de funciones y atributos de las clases se encuentran en archivos `.h`, pero debe implementar las funciones dentro de los `.cpp` equivalentes.
- A continuación encontrará los enunciados de cada uno de los ejercicios. Su nota en cada uno de los ejercicios será la relación entre la cantidad de pruebas que sí pasen sobre la cantidad total de pruebas para ese ejercicio.
- En la pestaña de **Actions** podrá ver como las pruebas se ejecutan con su código implementado (si hace `git push` previamente). En los últimos pasos, puede ver los resultados y su nota:

![results step](images/results.png)
___

## Ejercicio 1 (20 puntos)

Dado el nodo `head` de una lista simplemente enlazada que se encuentra **ordenada**, *elimine todos los elementos duplicados de la lista*, de tal manera que cada valor aparezca una y solo una vez. Retorne la lista actualizada y ordenada de igual manera.

En la lista, primero se encuentran los nodos con valores entre `'A'` y `'Z'`, si existen, y luego los nodos con valores entre `'a'` y `'z'`.

### Ejemplo 1.1

![example 1.1](images/example1_1.jpeg)

    head = [A -> A -> b]
    resultado = [A -> b]

___

## Ejemplo 1.2

![example 1.2](images/example1_2.jpeg)

    head = [A -> A -> Z -> b -> b]
    resultado = [A -> Z -> b]
___

## Ejemplo 1.3

    head = [H -> H -> H -> g -> g -> g -> g]
    resultado = [H -> g]
___

### Restricciones

- La cantidad de nodos se encuentra entre **0** y **300**
- `'A'` <= `Node.value` <= `'Z'` || `'a'` <= `Node.value` <= `'z'`

___

## Ejercicio 2 (25 puntos)

La cafetería de la universidad ofrece sandwiches redondos (R), cuadrados (C) y vegetarianos (V). Todos los estudiantes permanecen en una cola. Cada estudiante tiene una preferencia en cuanto al tipo de sandwich: cuadrado, redondo o vegetariano.

La cantidad de sandwiches es igual a la cantidad de estudiantes.

- Cada vez que un estudiante sale de la cola, tomará el siguiente sandwich si y solo si es del tipo que prefiere.
- Si el sandwich no es de su tipo, lo dejará ahí y tendrá que hacer la cola nuevamente.

Esto continúa hasta que ninguno de los estudiantes quiere el siguiente sandwich y, por lo tanto, nadie más podrá comer.

A usted se le dan dos arreglos de de `char`, `students` y `sandwiches`, donde `sandwiches[i]` es el tipo del **i-ésimo** sandwich (`i=0` es el primer sandwich disponible) y `students[j]` es la preferencia j-ésimo estudiante en la cola de estudiantes (`j=0` representa el primer estudiante en cola).

**Retorne la cantidad de estudiantes que no podrán comer sandwich.**

Para resolver este problema, debe implementar una estructura de datos lineal y de tamaño dinámico. No puede utilizar `stack`, `list`, `queue`, ni ninguna librería con estructuras de datos lineales. Usted debe implementar su propia estructura.

### Ejemplo 2.1

![example 1.1](images/example1_1.jpeg)

    students = [V,R,V,C,C,C,V,V,V,V,V]
    sandwiches = [R,C,R,V,R,C,R,V,C,R,C]
    resultado = 9

**Explicación:**

- El primer estudiante prefiere sandwich Vegetariano, pero el primer sandwich es Redondo. Así que regresa al final de la cola
  - students = [R,V,C,C,C,V,V,V,V,V,V]
  - sandwiches = [R,C,R,V,R,C,R,V,C,R,C]
- El siguiente estudiante prefiere un sandwich redondo, que es del mismo tipo que el siguiente sandwich. El estudiante toma el sandwich y se sale de la cola.
  - students = [V,C,C,C,V,V,V,V,V,V]
  - sandwiches = [C,R,V,R,C,R,V,C,R,C]
- El siguiente estudiante prefiere un estudiante vegano, por lo tanto deja el sandwich y regresa a la cola.
  - students = [C,C,C,V,V,V,V,V,V,V]
  - sandwiches = [C,R,V,R,C,R,V,C,R,C]
- El siguiente estudiante en la cola prefiere un sandwich cuadrado, por lo cual toma el sandwich y se sale de la cola.
  - students = [C,C,V,V,V,V,V,V,V]
  - sandwiches = [R,V,R,C,R,V,C,R,C]
- El siguiente sandwich es Redondo, pero ninguno de los estudiantes de la cola prefiere ese tipo de sandwich, por lo cual, todos los estudiantes restantes se quedarán sin poder comer sandwich.

___

## Ejemplo 2.2

    students = [C,V,C,V,R,R]
    sandwiches = [R,C,V,R,C,V]
    resultado = 0
___

### Restricciones

- `1 <= students.size(), sandwiches.size() <= 100`
- `students.size(), sandwiches.size()`
- `students[i]` es `'C'`, `'R'` o `'V'`
- `sandwiches[i]` es `'C'`, `'R'` o `'V'`

___

## Ejercicio 3 (40 puntos)

Diseñe una pila (stack) en la que se pueda hacer push, pop, top y encontrar el menor elemento en **tiempo constante**.

Implemente la clase `MinStack` que se encuentra en `Ejercicio03.h` y `Ejercicio03.cpp` con las siguientes funcionalidades:

- `MinStack()` crea e instancia un objeto de MinStack.
- `void push(int value)` agrega el elemento **value** a la pila.
- `void pop()` elimina el último elemento en ser agregado a la pila.
- `int top()` retorna el último elemento en ser agregado a la pila (sin eliminarlo).
- `int getMin()` retorna el menor elemento en la pila.

Su solución debe resolver cada función con complejidad de tiempo `O(1)`.

Para resolver este problema, debe implementar una estructura de datos lineal y de tamaño dinámico. No puede utilizar `stack`, `list`, `queue`, ni ninguna librería con estructuras de datos lineales. Usted debe implementar su propia estructura.

### Ejemplo 3.1

```C++
    MinStack* minStack = new MinStack(); // []
    minStack->push(-2); // [-2]
    minStack->push(0); // [0, -2]
    minStack->push(-3); // [-3, 0, -2]
    minStack->getMin(); // return -3
    minStack->pop(); // elimina (-3) -> [0, -2]
    minStack->top();    // return 0
    minStack->getMin(); // return -2
```

___
