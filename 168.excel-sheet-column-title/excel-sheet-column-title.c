char* convertToTitle(int n) {
    char *ans = NULL;
    int len = 0;
    while (1) {
        int digit = n % 26;
        if (digit == 0) digit = 26;
        len++;
        ans = realloc(ans, sizeof(char) * (len + 1));
        ans[len] = '\0';
        ans[len - 1] = digit + 64;
        n = (n - digit) / 26;
        if (n == 0) break;
    }
    for (int i = 0; i < (len >> 1); i++) {
        char t = ans[i];
        ans[i] = ans[len - i - 1];
        ans[len - i - 1] = t;
    }
    return ans;
}