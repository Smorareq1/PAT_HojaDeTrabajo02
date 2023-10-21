#include "Ejercicio01.h"
#include "Node.h"

Node<char>* Ejercicio01::rotateRight(Node<char>* head, int k)
{
    

        if (head == nullptr || k == 0) {
            return head;
        } //caso base


        int sz = 1;
        Node<char>* colaAux = head;
        while (colaAux->next != nullptr) {
            colaAux = colaAux->next; //Ultimo nodo
            sz++;
        }

        k = k % sz;
        colaAux->next = head; //Poner la cola en la cabeza

        
        Node<char>* new_tail = head;
        for (int j = 1; j < (sz - k); ++j) {
            new_tail = new_tail->next;
        }

        
        head = new_tail->next;
        new_tail->next = nullptr;

        return head;
}
