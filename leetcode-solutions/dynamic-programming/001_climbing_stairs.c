int dp[1000];

int climbStairs(int n) {

    if(n == 0){
        return 1;
    }

    if(n < 0){
        return 0;
    }

    if(dp[n] != 0){
        return dp[n];
    }

    int left = climbStairs(n - 1);
    int right = climbStairs(n - 2);

    dp[n] = left + right;

    return dp[n];
}