//         CIRCULAR LINKED LIST AND OPERATION
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* tail = NULL;  

void insert(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    if (tail == NULL) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
   
}

void display() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = tail->next;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

void deleteFromBeginning() {
    if (tail == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    
    Node* head = tail->next;
    if (head == tail) { 
        printf("Deleted %d from beginning\n", head->data);
        free(head);
        tail = NULL;
    } else {
        tail->next = head->next;
        printf("Deleted %d from beginning\n", head->data);
        free(head);
    }
}

void deleteFromEnd() {
    if (tail == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    Node* head = tail->next;
    if (head == tail) { 
        printf("Deleted %d from end\n", tail->data);
        free(tail);
        tail = NULL;
    } else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = tail->next;
        printf("Deleted %d from end\n", tail->data);
        free(tail);
        tail = temp;
    }
}

void deleteElement(int value) {
    if (tail == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    Node* curr = tail->next;
    Node* prev = tail;
    do {
        if (curr->data == value) {
            if (curr == tail && curr == tail->next) { 
                tail = NULL;
            } else {
                prev->next = curr->next;
                if (curr == tail) {
                    tail = prev;
                }
            }
            printf("Deleted element %d\n", value);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);
    printf("Element %d not found in the list.\n", value);
}

int main() {
    
    insert(10);
    insert(4);
    insert(68);
    insert(49);
    insert(34);
    insert(77);
    display();

    
    deleteFromBeginning();
    display();
    deleteFromEnd();
    display();
    deleteElement(49);
    display();

   

    return 0;
}
