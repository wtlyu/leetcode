int titleToNumber(char* s) {
    int ans = 0;
    for (int i = 0; i < strlen(s); i++) {
        ans *= 26;
        ans += s[i] - 64;
    }
    return ans;
}