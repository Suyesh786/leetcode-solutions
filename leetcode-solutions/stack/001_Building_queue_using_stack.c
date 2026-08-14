
typedef struct {
    int Stack1[100];
    int top1;
    int Stack2[100];
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;

    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->Stack1[++obj->top1] = x;
}

int myQueuePop(MyQueue* obj) {
    if(obj->top2 == -1){
        while(obj->top1 != -1){
            obj->Stack2[++obj->top2] = obj->Stack2[obj->top2--];
        }
    }

    return obj->Stack2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->Stack2[++obj->top2] = obj->Stack1[obj->top1--];
        }
    }

    return obj->Stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1==-1 && obj->top2==-2 ;
}