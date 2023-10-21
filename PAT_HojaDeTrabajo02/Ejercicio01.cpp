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
        k = sz - k;
        colaAux->next = head; //Poner la cola en la cabeza

        
        colaAux = head; //Encontrar nueva cola

        int j = 1;
        while (j < k) {
            colaAux = colaAux->next;
            ++j;
        }
        

       
        head = colaAux->next;
        colaAux->next = nullptr; //que deje de ser lista circular

        return head;
}
