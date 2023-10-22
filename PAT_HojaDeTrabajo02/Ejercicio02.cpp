#include "Ejercicio02.h"

Node<int>* Ejercicio02::addTwoNumbers(Node<int>* l1, Node<int>* l2)
{
    Node<int>* nodoAux = new Node<int>{ 0 };
    Node<int>* current = nodoAux;
    int carry = 0;

    
    while (l1 != nullptr || l2 != nullptr) {
        int x = 0, y = 0;

        // Si l1 no es nullptr, actualiza x y avanza a l1
        if (l1 != nullptr) {
            x = l1->value;
            l1 = l1->next;
        }

        // Si l2 no es nullptr, actualiza y y avanza a l2
        if (l2 != nullptr) {
            y = l2->value;
            l2 = l2->next;
        }

        int sum = x + y + carry;
        carry = sum / 10;
        current->next = new Node<int>{ sum % 10 };
        current = current->next;
    }

    //Ver si necesita otro digito
    if (carry > 0) {
        current->next = new Node<int>{ carry };
    }

    return nodoAux->next;
}
