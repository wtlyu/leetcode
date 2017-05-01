void reverse(char *s, int l, int r) {
    for (int i = l; i <= (l + r) >> 1; i++) {
        char t = s[i];
        s[i] = s[r - i + l];
        s[r - i + l] = t;
    }
}

void reverseWords(char *s) {
    int pre = 0; int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            reverse(s, pre, i - 1);
            pre = i + 1;
        }
    }
    reverse(s, pre, len - 1);
    
    reverse(s, 0, len - 1);
}