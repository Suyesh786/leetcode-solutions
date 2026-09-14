bool isPowerOfTwo(int n) {
    if(n == 1){
        return true;
    }
    if(n==0){
        return false;
    }
    double val = log2(n);
    if(val == trunc(val)){
        return true;
    }else{
        return false;
    }
}