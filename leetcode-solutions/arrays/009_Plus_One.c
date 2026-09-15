#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {

    int* ans = malloc(sizeof(int) * (digitsSize + 1));

    for(int i = 0; i < digitsSize; i++){
        ans[i] = digits[i];
    }

    int i = digitsSize - 1;

    while(i >= 0 && ans[i] == 9){
        ans[i] = 0;
        i--;
    }

    if(i >= 0){
        ans[i]++;
        *returnSize = digitsSize;
        return ans;
    }

    // All digits were 9
    ans[0] = 1;

    for(int j = 1; j <= digitsSize; j++){
        ans[j] = 0;
    }

    *returnSize = digitsSize + 1;

    return ans;
}