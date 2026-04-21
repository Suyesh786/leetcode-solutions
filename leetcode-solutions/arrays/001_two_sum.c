/*
Problem: Two Sum
Platform: LeetCode
Difficulty: Easy
Topic: Arrays
Language: C
*/

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i=0,j;
    int*result = malloc(2*sizeof(int));
    result[0]=-1;
    result[1]=-1;
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if((target-nums[i])==nums[j]){
                result[0] = i;
                result[1] = j;
            }
        }
    }

    return result;
}