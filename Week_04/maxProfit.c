int max(int a, int b) {
    return a > b ? a : b;
}
int maxProfit(int* prices, int pricesSize){
    int** dp = (int**)malloc(sizeof(int*) * pricesSize);
    int i;
    for (i = 0; i < pricesSize; i++) {
        dp[i] = (int*)malloc(sizeof(int)*2);
    }
    //dp[i][0] 代表 i有. dp[i][1] 代表 i无
    //dp[i][1] = max(dp[i-1][0] + prices[i],dp[i][1]);
    //dp[i][0] = max(dp[i-1][1] - prices[i], dp[i-1][0]);
    dp[0][0] = - prices[0];
    dp[0][1] = 0;
    for (i = 1; i < pricesSize; i++) {
        dp[i][1] = max(dp[i-1][0] + prices[i], dp[i - 1][1]);
        dp[i][0] = max(dp[i-1][1] - prices[i], dp[i - 1][0]);
    }

    return dp[pricesSize - 1][1];
}