typedef struct ListNode{
    int val;
    ListNode* next;
} ListNode;

typedef struct {
    ListNode* top;
    int size;
} Stack;

typedef struct {
    Stack* stack1;
    Stack* stack2;
} MyQueue;

Stack* stackCreate(){
    Stack* newStack = malloc(sizeof(Stack));

    newStack -> size = 0;
    newStack -> top = NULL;

    return newStack;
}

void stackPush(Stack* stack, int x) {
    ListNode* newNode = malloc(sizeof(ListNode));
    newNode -> val = x;
    newNode -> next = stack-> top;

    stack -> top = newNode;
    stack-> size++;
}

int stackPop(Stack* stack){
    if (Stack-> top == NULL) return -1;

    ListNode* temp = Stack-> top;
    int x = temp-> val;
    Stack-> top = Stack -> top-> next;
    Stack -> size--;
    free(temp);

    return x;
}

int stackPeek(Stack* stack){
    if (Stack-> top ==NULL) return -1;

    return Stack-> top-> val; 
}

bool stackIsEmpty(Stack* stack){
    return stack->top == NULL;
}

void stackFree(Stack* stack){
    while(!stack.stackIsEmpty()){
        stackPop(stack)
    }

    free(stack);
}


MyQueue* myQueueCreate() {
    MyQueue* newQueue = malloc(sizeof(MyQueue));

    newQueue -> stack1 = stackCreate();
    newQueue -> stack2 = stackCreate();

    return newQueue;
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj->stack2.stackIsEmpty()){
        stackPush(obj->stack1,x);
    }
    else{
        while(!obj->stack2.stackIsEmpty()){
            stackPush(obj->stack1,stackPop(obj->stack2));
        }
        stackPush(obj->stack1,x);
    }
}

int myQueuePop(MyQueue* obj) {
    if (obj->stack2.stackIsEmpty()){
        while(!stack1.stackIsEmpty()){
            stackPush(obj->stack2, stackPop(obj->stack1));   
        }
        
        return stackPop(obj->stack2);
    }
}

int myQueuePeek(MyQueue* obj) {
    if (obj->stack2.stackIsEmpty()){
        while(!stack1.stackIsEmpty()){
            stackPush(obj->stack2, stackPop(obj->stack1));   
        }
        
        return stackPeek(obj->stack2);
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->stack1 == NULL && obj->stack2 == NULL;
}

void myQueueFree(MyQueue* obj) {
    stackFree(obj->stack1);
    stackFree(obj->stack2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/


// second solution

typedef struct {
    int* stk;
    int stkSize;
    int stkCapacity;
} Stack;

Stack* stackCreate(int cpacity) {
    Stack* ret = malloc(sizeof(Stack));
    ret->stk = malloc(sizeof(int) * cpacity);
    ret->stkSize = 0;
    ret->stkCapacity = cpacity;
    return ret;
}

void stackPush(Stack* obj, int x) {
    obj->stk[obj->stkSize++] = x;
}

void stackPop(Stack* obj) {
    obj->stkSize--;
}

int stackTop(Stack* obj) {
    return obj->stk[obj->stkSize - 1];
}

bool stackEmpty(Stack* obj) {
    return obj->stkSize == 0;
}

void stackFree(Stack* obj) {
    free(obj->stk);
}

typedef struct {
    Stack* inStack;
    Stack* outStack;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* ret = malloc(sizeof(MyQueue));
    ret->inStack = stackCreate(100);
    ret->outStack = stackCreate(100);
    return ret;
}

void in2out(MyQueue* obj) {
    while (!stackEmpty(obj->inStack)) {
        stackPush(obj->outStack, stackTop(obj->inStack));
        stackPop(obj->inStack);
    }
}

void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->inStack, x);
}

int myQueuePop(MyQueue* obj) {
    if (stackEmpty(obj->outStack)) {
        in2out(obj);
    }
    int x = stackTop(obj->outStack);
    stackPop(obj->outStack);
    return x;
}

int myQueuePeek(MyQueue* obj) {
    if (stackEmpty(obj->outStack)) {
        in2out(obj);
    }
    return stackTop(obj->outStack);
}

bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(obj->inStack) && stackEmpty(obj->outStack);
}

void myQueueFree(MyQueue* obj) {
    stackFree(obj->inStack);
    stackFree(obj->outStack);
}