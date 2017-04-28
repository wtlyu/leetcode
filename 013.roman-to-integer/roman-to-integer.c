int romanToInt(char* s) {
    int i = 0, cache = 0, presym = 0, sym = 0;
    while (s[i] != '\0') {
        switch(s[i]) {
            case 'I': sym = 1; break;
            case 'V': sym = 5; break;
            case 'X': sym = 10; break;
            case 'L': sym = 50; break;
            case 'C': sym = 100; break;
            case 'D': sym = 500; break;
            case 'M': sym = 1000; break;
        }
        if (sym > presym) 
            cache = cache - presym + sym - presym;
        else
            cache = cache + sym;
        presym = sym;
        i++;
    }
    return cache;
}