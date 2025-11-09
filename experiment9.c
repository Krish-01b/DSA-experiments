#include <stdio.h>

#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (front == (rear + 1) % MAX);
}

void enqueue(char ch) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert '%c'.\n", ch);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = ch;
    printf("Inserted: %c\n", ch);
}

char dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to delete.\n");
        return '\0';
    }
    char ch = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("Deleted: %c\n", ch);
    return ch;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents (front -> rear): ");
    int i = front;
    while (1) {
        printf("%c ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void demonstrateOverflowUnderflow() {
    printf("Demonstrating Overflow:\n");
    for (int i = 0; i < MAX + 1; i++) {
        char ch = 'A' + (i % 26);
        enqueue(ch);
    }

    printf("\nDemonstrating Underflow:\n");
    for (int i = 0; i < MAX + 1; i++) {
        dequeue();
    }
}

int main() {
    char choice;
    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("a. Insert an element into Circular QUEUE\n");
        printf("b. Delete an element from Circular QUEUE\n");
        printf("c. Demonstrate Overflow and Underflow\n");
        printf("d. Display the status of Circular QUEUE\n");
        printf("e. Exit\n");
        printf("Enter your choice (a-e): ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a': {
                char ch;
                printf("Enter a character to insert: ");
                scanf(" %c", &ch);
                enqueue(ch);
                break;
            }
            case 'b':
                dequeue();
                break;
            case 'c':
                demonstrateOverflowUnderflow();
                break;
            case 'd':
                display();
                break;
            case 'e':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Enter a-e.\n");
        }
    } while (choice != 'e');

    return 0;
}
