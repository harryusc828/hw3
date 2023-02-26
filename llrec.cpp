#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){

    if(head == NULL){
        smaller = nullptr;
        larger = nullptr; 
        return;
    }

    if (head -> val <= pivot){
        smaller = head;
        Node* temp = smaller -> next;
        smaller -> next = NULL; 
        llpivot(temp,smaller -> next, larger, pivot);
    }
    else if (head -> val > pivot){
        larger = head;
        Node* temp = larger -> next; 
        larger -> next = NULL; 
        llpivot(temp, smaller, larger -> next, pivot);
    }

    head = nullptr; 
}

