#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_SIZE 100

double stack[STACK_SIZE];
int top = -1;

void push(double value) {
    if (top >= STACK_SIZE - 1) {
        printf("Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}

double pop() {
    if (top < 0) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

int main() {
    char op;
    double value, result;
    double pi = 3.1416;

    while (1) {
        printf("Enter operator or value (q to quit): ");
        scanf(" %c", &op);

        if (op == 'q') {
            break;
        } else if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' ||
                   op == 's' || op == 'c' || op == 't' || op == 'r') {
            if (op == 's' || op == 'c' || op == 't' || op == 'r') {
                if (top < 0) {
                    printf("Error: Not enough operands\n");
                    continue;
                }
                value = pop();
            }

            switch (op) {
                case '+':
                    result = pop() + pop();
                    break;
                case '-':
                    result = -pop() + pop();
                    break;
                case '*':
                    result = pop() * pop();
                    break;
                case '/':
                    result = 1 / pop() * pop();
                    break;
                case '^':
                    value = pop();
                    result = pow(pop(), value);
                    break;
                case 's':
                    result = sin((pi/180) * value);
                    break;
                case 'c':
                    result = cos((pi/180) *value);
                    break;
                case 't':
                    result = tan((pi/180)* value);
                    break;
                case 'r':
                    result = sqrt(value);
                    break;
            }

            push(result);
            printf("Result: %.2f\n", result);
        } else {
            ungetc(op, stdin);
            if (scanf("%lf", &value) != 1) {
                printf("Error: Invalid input\n");
                exit(EXIT_FAILURE);
            }
            push(value);
        }
    }

    printf("Final result: %.2f\n", pop());
    return 0;
}
