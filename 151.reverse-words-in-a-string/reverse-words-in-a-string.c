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
    
    int start = 0, end = -1;
    for (int i = 0; i < len; i++)
        if (s[i] != ' ') {start = i;break;}
    for (int i = len - 1; i >= 0; i--)
        if (s[i] != ' ') {end = i;break;}
    
    pre = 0;
    for (int i = start; i <= end; i++) {
        if ((i > 0) && (s[i] == ' ') && (s[i - 1] == ' ')) continue;
        s[pre] = s[i]; pre++;
    }
    
    s[pre] = '\0';
}