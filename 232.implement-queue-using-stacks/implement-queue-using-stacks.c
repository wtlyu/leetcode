typedef struct {
    int h;
    int * data;
} stack;

/** Initialize your data structure here. */
stack* myStackCreate(int maxSize) {
    stack* ret = malloc(sizeof(stack));
    ret -> h = 0;
    ret -> data = malloc(sizeof(int) * maxSize);
    return ret;
}

/** Push element x to the back of queue. */
void myStackPush(stack* obj, int x) {
    obj -> data[obj -> h] = x;
    obj -> h ++;
}

/** Removes the element from in front of queue and returns that element. */
int myStackPop(stack* obj) {
    obj -> h--;
    return obj -> data[obj -> h];
}

/** Get the front element. */
int myStackPeek(stack* obj) {
    return obj -> data[obj -> h - 1];
}

/** Returns whether the queue is empty. */
bool myStackEmpty(stack* obj) {
    return (obj -> h == 0);
}

void myStackFree(stack* obj) {
    free(obj -> data);
    free(obj);
}

typedef struct {
    stack * data, * outputCache;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue* ret = malloc(sizeof(MyQueue));
    ret -> data = myStackCreate(maxSize);
    ret -> outputCache = myStackCreate(maxSize);
    return ret;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    myStackPush(obj -> data, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    while (!myStackEmpty(obj -> data)) {
        int t = myStackPop(obj -> data);
        myStackPush(obj -> outputCache, t);
    }
    
    int ret = myStackPop(obj -> outputCache);
    
    while (!myStackEmpty(obj -> outputCache)) {
        int t = myStackPop(obj -> outputCache);
        myStackPush(obj -> data, t);
    }
    
    return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    while (!myStackEmpty(obj -> data)) {
        int t = myStackPop(obj -> data);
        myStackPush(obj -> outputCache, t);
    }
    
    int ret = myStackPeek(obj -> outputCache);
    
    while (!myStackEmpty(obj -> outputCache)) {
        int t = myStackPop(obj -> outputCache);
        myStackPush(obj -> data, t);
    }
    
    return ret;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return myStackEmpty(obj -> data);
}

void myQueueFree(MyQueue* obj) {
    myStackFree(obj -> data);
    myStackFree(obj -> outputCache);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */