#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100  

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    stack->arr[++stack->top] = value;
}

int pop(struct Stack* stack) {
    return stack->arr[stack->top--];
}

int operate(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: return 0;
    }
}

int evaluatePostfix(char* expression) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char token = expression[i];

        if (token == ' ') continue;  

        if (isdigit(token)) {
            int num = 0;
            while (isdigit(expression[i])) {  
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            push(&stack, num);
            i--;  
        }
        else if (strchr("+-*/", token)) {  
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            push(&stack, operate(operand1, operand2, token));
        }
    }

    return pop(&stack);  
}

int main() {
    char expression[MAX];
    printf("Enter a postfix expression: ");
    fgets(expression, MAX, stdin); 

    int result = evaluatePostfix(expression);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
