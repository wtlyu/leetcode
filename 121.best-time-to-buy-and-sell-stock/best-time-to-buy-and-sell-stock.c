int maxProfit(int* prices, int pricesSize) {
    int min = prices[0], ans = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] - min > ans)
            ans = prices[i] - min;
        if (prices[i] < min)
            min = prices[i];
    }
    return ans;
}