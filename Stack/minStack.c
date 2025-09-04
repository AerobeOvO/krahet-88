int MAX_SIZE = 3*10^4;

typedef struct {
    int* data;
    int size1;
    int* min_stack;
    int size2;
} MinStack;


MinStack* minStackCreate() {
    MinStack* stack = malloc(sizeof(MinStack));

    stack -> data = malloc(sizeof(int) * MAX_SIZE);
    stack -> size1 = 0;
    stack -> min_stack = malloc(sizeof(int) * MAX_SIZE);
    stack -> size2 = 0;

    return stack;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->data == NULL){
        obj-> data[obj->size1++] = val;
        obj-> min_stack[obj->size2++] = val;
    }

    else {
        int temp = obj-> size2 -1;
        
        if (val<= obj->min_stack[temp]){
            obj-> data[obj->size1++] = val;
            obj-> min_stack[obj->size2++] = val;
        }
        else {
            obj-> data[obj->size1++] = val;
        }
    }
}

void minStackPop(MinStack* obj) {
    int temp1 = obj->size1 -1;
    int temp2 = obj->size2 -1;

    if (obj-> data[temp1] == obj->min_stack[temp2]){
        obj->size1--;
        obj-> size2--;
    }

    else {
        obj-> size1--;
    }
}

int minStackTop(MinStack* obj) {
    int top = obj->size1 -1;

    return obj-> data[top];
}

int minStackGetMin(MinStack* obj) {
    int temp = obj-> size2-1;

    return obj-> min_stack[temp];
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj-> min_stack);
    free(obj);
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