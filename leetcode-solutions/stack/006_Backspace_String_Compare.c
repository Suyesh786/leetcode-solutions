int stack1[10000];
int stack2[10000];

int top1 =-1;
int top2=-1;

void push(char x,int *top,int stack[]){
    if(*top == 9999){
        return;
    }
    stack[++(*top)] = x;
}

void pop(int *top){
    if(*top==-1){
        return;
    }
    --(*top);
}


bool backspaceCompare(char* s, char* t) {
    top1 =-1;
    top2 = -1;
    // Solving s
    for (int i = 0; s[i] != '\0';i++){
        if(s[i] != '#'){
            push(s[i],&top1,stack1);
        }else{
            pop(&top1);
        }
    }

    // Solving t
    for (int i = 0; t[i] != '\0';i++){
        if(t[i] != '#'){
            push(t[i],&top2,stack2);
        }else{
            pop(&top2);
        }
    }

    //Compare s and t

    if(top1 != top2){
        return false;
    }
    int temp = top1;
    while(temp >= 0){
        if(stack1[temp] != stack2[temp]){
            return false;
        }
        temp--;
    }

    return true;
}