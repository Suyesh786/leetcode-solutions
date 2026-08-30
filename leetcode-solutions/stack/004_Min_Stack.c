


typedef struct {
    int top;
    int st[100000];
    int mintop;
    int minst[100000];
} MinStack;


MinStack* minStackCreate() {
    MinStack *obj = (MinStack*)malloc(sizeof(MinStack));
    if (obj != NULL) {
        obj->top = -1;
        obj->mintop = -1;
    }
    return obj;
}

void minStackPush(MinStack* obj, int value) {
    if(obj->top == 99999){
        return ;
    }
    obj->st[++obj->top] = value;
    if(obj->mintop == -1){
        obj->minst[++obj->mintop] = value;
    }else{
        if(obj->minst[obj->mintop] >= value){
            obj->minst[++obj->mintop] = value;
        }
    }

}

void minStackPop(MinStack* obj) {
    if(obj->top == -1){
        return;
    }
    if(obj->st[obj->top] == obj->minst[obj->mintop]){
        obj->mintop--;
    }
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->st[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minst[obj->mintop];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, value);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
