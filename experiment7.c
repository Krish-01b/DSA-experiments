#include <stdio.h>
#include <string.h> 

#define MAX 5  // Maximum size of the stack

int stack[MAX]; 
int top = -1;    

// Function to push an element onto the stack
void push(int element) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push element %d.\n", element);
    } else {
        stack[++top] = element;
        printf("Pushed: %d\n", element);
    }
}
// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;  
    } else {
        int element = stack[top--];
        printf("Popped: %d\n", element);
        return element;
    }
}
// Function to display  stack
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Function to check if a string is a palindrome using the stack
int isPalindrome(char str[]) {
    int len = strlen(str);
    char reversed[100];  
    
    for (int i = 0; i < len; i++) {
        push((int)str[i]); 
    }
    
   
    for (int i = 0; i < len; i++) {
        reversed[i] = (char)pop(); 
    }
    reversed[len] = '\0'; 
    
    printf("Original: %s\n", str);
    printf("Reversed: %s\n", reversed);
    
    
    if (strcmp(str, reversed) == 0) {
        return 1;  
    } else {
        return 0;  
    }
}
// Function to demonstrate overflow and underflow situations
void demonstrateOverflowUnderflow() {
    printf("Demonstrating Overflow:\n");

    while (top < MAX - 1) {
        push(999);  
    }
    push(999); 
    
    printf("\nDemonstrating Underflow:\n");
    while (top >= 0) {
        pop();  
    }
    pop();  
}

int main() {
    char choice;
    
    do {
        // Display the menu
        printf("\nMenu:\n");
        printf("a. Push an Element on to Stack\n");
        printf("b. Pop an Element from Stack\n");
        printf("c. Demonstrate how Stack can be used to check Palindrome\n");
        printf("d. Demonstrate Overflow and Underflow situations on Stack\n");
        printf("e. Display the status of Stack\n");
        printf("f. Exit\n");
        printf("Enter your choice (a-f): ");
        
        scanf(" %c", &choice);
        switch (choice) {
            case 'a': 
                {
                    int element;
                    printf("Enter an integer to push: ");
                    scanf("%d", &element);
                    push(element);
                }
                break;
            
            case 'b':  // Pop an element
                pop();
                break;
            
            case 'c':  // Check Palindrome
                {
                    char str[100]; 
                    printf("Enter a string to check for palindrome: ");
                    scanf("%s", str);  
                    if (isPalindrome(str)) {
                        printf("The string is a palindrome.\n");
                    } else {
                        printf("The string is not a palindrome.\n");
                    }
                }
                break;
            
            case 'd':   
                demonstrateOverflowUnderflow();
                break;
            
            case 'e':  
                display();
                break;
            
            case 'f':  
                printf("Exiting the program.\n");
                break;
            
            default:
                printf("Invalid choice! Please enter a-f.\n");
        }
    } while (choice != 'f');
    
    return 0;
}
