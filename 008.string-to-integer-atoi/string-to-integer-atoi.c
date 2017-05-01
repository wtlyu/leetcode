int myAtoi(char* str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        switch (str[i]) {
            case ' ':
            case '\n':
            case '\r':
            case '\t':
                continue;
            default:
                break;
        }
        break;
    }
    if (i == len) return 0; // no number founded;
    bool sign = true;
    if ((str[i] == '-') || (str[i] == '+')) {
        sign = (str[i] == '+');
        i++;
    }
    long long ret = 0, pos = i;
    for (int i = pos; i < len; i++)  {
        if ((str[i] >= 48) && (str[i] <= 57)) {
            ret *= 10;
            ret += str[i] - 48;
        } else break;
        if (sign && (ret>INT_MAX)) return INT_MAX;
        if (!sign && (-ret<INT_MIN)) return INT_MIN;
    }
    return sign?ret:-ret;
}