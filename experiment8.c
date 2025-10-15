#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack for operators
char stack[MAX];
int top = -1;

// Push and pop for operator stack
void push(char c) {
    if (top < MAX - 1) stack[++top] = c;
}

char pop() {
    if (top >= 0) return stack[top--];
    return '\0';
}

char peek() {
    if (top >= 0) return stack[top];
    return '\0';
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

int precedence(char c) {
    switch(c) {
        case '^': return 3;
        case '*': case '/': case '%': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

// '^' is right associative; others are left associative
int isRightAssociative(char c) {
    return (c == '^');
}

void infixToPostfix(const char *infix, char *postfix) {
    int i, k = 0;
    int len = strlen(infix);
    for (i = 0; i < len; i++) {
        char token = infix[i];

        if (token == ' ' || token == '\t') continue; // skip spaces

        // If operand, add to postfix
        if (isalnum((unsigned char)token)) {
            postfix[k++] = token;
        }
        // If '(', push to stack
        else if (token == '(') {
            push(token);
        }
        // If ')', pop until '('
        else if (token == ')') {
            while (top != -1 && peek() != '(')
                postfix[k++] = pop();
            if (peek() == '(') pop(); // discard '('
        }
        // If operator
        else if (isOperator(token)) {
            while (top != -1 && isOperator(peek())) {
                int p1 = precedence(peek());
                int p2 = precedence(token);
                if ((p1 > p2) || (p1 == p2 && !isRightAssociative(token))) {
                    postfix[k++] = pop();
                } else break;
            }
            push(token);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        if (peek() == '(' || peek() == ')') { pop(); continue; }
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int main() {
    char infix[100], postfix[100];
    printf("Enter an infix expression (operators + - * / %% ^, operands alphanumeric):\n");
    fgets(infix, sizeof(infix), stdin);
    size_t ln = strlen(infix) - 1;
    if (infix[ln] == '\n') infix[ln] = '\0';

    top = -1;
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
