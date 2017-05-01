char* strcmb(char* str1, char* str2) {
    if ((strlen(str1) > 0) && (strcmp(str2, " ") != 0)) str1 = strcmb(str1, " ");
    char* str = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    strcpy(str, str1);
    strcpy(str + strlen(str1), str2);
    free(str1);
    return str;
}

char* numberToWordsLevel(int num) {
    const char* below_20[] = {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    const char* below_100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    char* ans = malloc(sizeof(char)); ans[0] = '\0';
    
    while (num) {
        if (num < 20) {
            ans = strcmb(ans, below_20[num - 1]);
            num = 0;
        } else if (num < 100) {
            ans = strcmb(ans, below_100[num/10 - 2]);
            num = num % 10;
        } else if (num < 1000) {
            ans = strcmb(ans, below_20[num/100 - 1]);
            ans = strcmb(ans, "Hundred");
            num = num % 100;
        }
    }
    
    return ans;
}


char* numberToWords(int num) {
    char* ans = malloc(sizeof(char)); ans[0] = '\0';
    
    if (num == 0) return "Zero";
    
    while (num) {
        char * temp;
        
        if (num >= 1000 * 1000 * 1000){
            temp = numberToWordsLevel(num / (1000 * 1000 * 1000));
            ans = strcmb(ans, temp); free(temp);ans = strcmb(ans, "Billion");
            num = num % (1000 * 1000 * 1000);
        } else if (num >= 1000 * 1000) {
            temp = numberToWordsLevel(num / (1000 * 1000));
            ans = strcmb(ans, temp); free(temp);ans = strcmb(ans, "Million");
            num = num % (1000 * 1000);
        } else if (num >= 1000) {
            temp = numberToWordsLevel(num / 1000);
            ans = strcmb(ans, temp); free(temp);ans = strcmb(ans, "Thousand");
            num = num % 1000;
        } else {
            temp = numberToWordsLevel(num);
            ans = strcmb(ans, temp); free(temp);
            num = 0;
        }
        
    }
    
    return ans;
}