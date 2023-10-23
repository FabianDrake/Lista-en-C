#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

void insertarAlFinal(struct Nodo** cabeza, int valor) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        struct Nodo* temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

void mostrarLista(struct Nodo* cabeza) {
    printf("Valores en la lista:\n");
    while (cabeza != NULL) {
        printf("%d -> ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}

void borrarElemento(struct Nodo** cabeza, int valor) {
    if (*cabeza == NULL) {
        printf("La lista está vacía. No se puede borrar.\n");
        return;
    }

    struct Nodo* actual = *cabeza;
    struct Nodo* anterior = NULL;

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("El valor %d no se encontró en la lista.\n", valor);
        return;
    }

    if (anterior == NULL) {
        *cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
    printf("Se ha eliminado el valor %d de la lista.\n");
}

int main() {
    struct Nodo* cabeza = NULL;
    char opcion;

    do {
        int valor;
        printf("Ingrese un valor numerico: ");
        scanf("%d", &valor);

        insertarAlFinal(&cabeza, valor);

        printf("¿Desea ingresar otro valor? (S/N): ");
        scanf(" %c", &opcion);
    } while (opcion == 'S' || opcion == 's');

    mostrarLista(cabeza);

    int valorBorrar;
    printf("Ingrese el valor que desea borrar: ");
    scanf("%d", &valorBorrar);

    borrarElemento(&cabeza, valorBorrar);
    mostrarLista(cabeza);

    while (cabeza != NULL) {
        struct Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }

    return 0;
}