bool checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    if (len2 < len1) return false;
    
    int count[26];memset(count, 0, sizeof(int) * 26);
    int countStat[26];memset(countStat, 0, sizeof(int) * 26);
    
    for (int i = 0; i < len1; i++) {
        count[s1[i] - 97]++;
        countStat[s2[i] - 97]++;
    }
    
    if (memcmp(count, countStat, sizeof(int) * 26) == 0) return true;
    
    for (int i = len1; i < len2; i++) {
        countStat[s2[i] - 97]++;
        countStat[s2[i - len1] - 97]--;
        if (memcmp(count, countStat, sizeof(int) * 26) == 0) return true;
    }
    
    return false;
}