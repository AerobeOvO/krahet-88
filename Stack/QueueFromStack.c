typedef struct {
    int val;
    ListNode* next;
}ListNode;

typedef struct {
    ListNode* top;
    int size;
}Stack;

typedef struct {
    Stack* s1;
    Stack* s2;
} MyQueue;


MyQueue* myQueueCreate() {
    
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj->s2.isEmpty()) {
        obj->s1.push(x);
    }
}

int myQueuePop(MyQueue* obj) {
    if(obj->s2.isEmpty()){
        while(!obj->s1.isEmpty()){
            obj->s2.push() = obj->s1.pop();
        }
    }

    int pop = obj->s2.pop();

    while (!obj->s2.isEmpty()){
        obj->s1.push() = obj->s2.pop();
    }

    return pop;
}

int myQueuePeek(MyQueue* obj) {
    if(obj->s2.isEmpty()){
        while(!obj->s1.isEmpty()){
            obj->s2.push() = obj->s1.pop();
        }
    }

    int peek = obj->s2.peek();

    while (!obj->s2.isEmpty()){
        obj->s1.push() = obj->s2.pop();
    }

    return peek;
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->s1.isEmpty());
}

void myQueueFree(MyQueue* obj) {
    free(s1);
    free(s2);
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