// Stack operations and queue implementation using two stacks

struct Stack {
    int size;
    int top;
    int* buffer;
}

void stack_init(struct Stack* stack, int size) {
    stack->buffer = malloc(sizeof(int)*size);
    stack->top = -1;
    stack->size = size;
}

void push(struct Stack* stack, int new) {
    if (stack->top == stack->size - 1) return;
    stack->top++;
    stack->buffer[stack->top] = new;
}

int pop(struct Stack* stack) {
    if (stack->top == -1) {
        return -1;
    }
    int top_elem = stack->buffer[stack->top];
    stack->top --;
    return top_elem;
}

struct QueueStacks {
    struct Stack* s1;
    struct Stack* s2;
}

void stack_init(struct QueueStacks* qs, int size) {
    qs->s1 = malloc(sizeof(struct Stack));
    qs->s2 = malloc(sizeof(struct Stack));
    qs->s1->buffer = malloc(sizeof(int)*size);
    qs->s2->buffer = malloc(sizeof(int)*size);
    qs->s1->size = size;
    qs->s2->size = size;
    qs->s1->top = -1;
    qs->s2->top = -1;
}

void enqueue(struct QueueStacks* qs, int new) {
    if (qs->s1->top == qs->s1->size - 1) return;
    qs->s1->top ++;
    qs->s1->buffer[qs->s1->top] = new;
}

int dequeue(struct QueueStacks* qs) {
    if (qs->s2->top == -1) {
    while (qs->s1->top != -1) {
        int popped = pop(qs->s1);
        push(qs->s2, popped);
    }
}
    return pop(qs->s2);
}
