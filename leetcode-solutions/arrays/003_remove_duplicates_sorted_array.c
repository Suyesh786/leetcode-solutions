int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0) return 0;

    int k = 0;  // index of last unique element

    for(int i = 1; i < numsSize; i++){
        if(nums[i] != nums[k]){
            k++;
            nums[k] = nums[i];
        }
    }

    return k + 1;
}