typedef struct {
    int* data;
    int size;
} Stack;

Stack* newStack{
    Stack *stack = malloc(sizeof(Stack));
    
    stack->val = malloc(sizeof(INT) * MAX_SIZE);
    stack->size = 0;

    return stack;
}

typedef struct {
    Stack* minStack;
} MinStack;


MinStack* minStackCreate() {
    MinStack *minStack = malloc(sizeof(MinStack));

    return minStack;
}

void minStackPush(MinStack* obj, int val) {
    obj->minStack->data[obj->minStack->size] = val;
    obj->minStack->size++;
}

void minStackPop(MinStack* obj) {
    obj->minStack->size--
}

int minStackTop(MinStack* obj) {
    return obj->minStack->data[obj->minStack->size];
}

int minStackGetMin(MinStack* obj) {
    
}

void minStackFree(MinStack* obj) {
    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/