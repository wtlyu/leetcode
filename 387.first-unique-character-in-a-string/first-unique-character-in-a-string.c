int firstUniqChar(char* s) {
    int count[26];
    for (int i = 0; i < 26; i++) count[i] = 0;
    int i = 0;
    while (s[i] != '\0') {
        count[s[i] - 'a']++;
        i++;
    }
    i = 0;
    while (s[i] != '\0') {
        if (count[s[i] - 'a'] == 1) return i;
        i++;
    }
    return -1;
}