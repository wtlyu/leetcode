bool isValid(char* s) {
    int len = strlen(s);
    char stack[10000]; int h = 0;
    for (int i = 0; i < len; i++) {
        switch(s[i]) {
            case '(' : 
            case '[' : 
            case '{' : 
                stack[h] = s[i]; 
                h ++;
                break;
            case ')' : 
            case ']' : 
            case '}' : 
                if (h > 0) {
                    char t = stack[h - 1];
                    if (abs(s[i] - t) > 2) return false;
                    h --;
                } else return false;
        }
    }
    return (h == 0);
}