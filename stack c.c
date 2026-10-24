#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initStack(Stack* s) {
        s->top = NULL;

}

int isEmpty(Stack s) {
    if (s.top == NULL){ return 1;}
    else { return 0; }
}

void push(Stack* s, char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

char pop(Stack* s) {
    if (s->top != NULL) {
    Node* temp = s->top;
    char val = temp->data;
    s->top = s->top->next;
    free(temp);

    return val;
    } else { return '/0'; }
}

char peek(Stack s) {
    if (s.top != NULL) {
       return s.top->data;
    }
}

int evalExp (char exp[]){
    Stack s;
    int a, b, result;
    int i = 0;
    char c;

    initStack(&s);

    while (exp[i] != '\0') {
        c = exp[i];
        if (c >= '0' && c <= '9') {
            push(&s, c);
        }
        else {
            b = pop(&s) - '0';
            a = pop(&s) - '0';

            if (c == '+')
              result = a + b;
            else if (c == '-')
              result = a - b;
            else if (c == '*')
              result = a * b;
            else if (c == '/')
              result = a / b;
            else
              return 0;

            push(&s, result + '0');
        }

        i++;
    }

    return pop(&s) - '0';
}

void display(Stack s) {

    Node* current = s.top;

    if (current == NULL) {

        printf("empty stack\n");

        return;

    }

    printf("Top -> ");

    while (current != NULL) {

        printf("%c ", current->data);

        current = current->next;

    }

    printf("\n");

}

void Exit(Stack* s) {

    while (!isEmpty(*s))

        pop(s);
}

int main() {
    Stack s;
    int choice;
    char value;
    char expression[100];

    initStack(&s);

    do {
        printf("\n===== MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Evaluate postfix expression\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter a character: ");
            scanf(" %c", &value);
            push(&s, value);
        }
        else if (choice == 2) {
            if (!isEmpty(s))
                printf("Removed: %c\n", pop(&s));
            else
                printf("Pile vide.\n");
        }
        else if (choice == 3) {
            display(s);
        }
        else if (choice == 4) {
            printf("Enter postfix expression: ");
            scanf(" %99[^\n]", expression);

            printf("Result = %d\n", evalExp(expression));
        }
        else if (choice == 5) {
            printf("Goodbye!\n");
        }
        else {
            printf("Invalid choice.\n");
        }

    } while (choice != 5);

    Exit(&s);

    return 0;
}
