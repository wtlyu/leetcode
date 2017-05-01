typedef struct Trie {
    struct Trie *children[26];
    bool val;
} Trie;

/** Initialize your data structure here. */
Trie* trieCreate() {
    Trie * ret = malloc(sizeof(Trie));
    ret -> val = false;
    memset(ret -> children, NULL, sizeof(Trie *) * 26);
    return ret;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char* word) {
    Trie* cur = obj;
    int len = strlen(word);
    int i = len;
    while (i) {
        char ch = word[len - i];
        if (cur -> children[ch - 97] == NULL)
            cur -> children[ch - 97] = trieCreate();
        cur = cur -> children[ch - 97];
        i--;
    }
    cur -> val = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char* word) {
    Trie* cur = obj;
    int len = strlen(word);
    int i = len;
    while (i) {
        char ch = word[len - i];
        if (cur -> children[ch - 97] == NULL)
            return false;
        cur = cur -> children[ch - 97];
        i--;
    }
    return (cur -> val);
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char* prefix) {
    Trie* cur = obj;
    int len = strlen(prefix);
    int i = len;
    while (i) {
        char ch = prefix[len - i];
        if (cur -> children[ch - 97] == NULL)
            return false;
        cur = cur -> children[ch - 97];
        i--;
    }
    return true;
}

void trieFree(Trie* obj) {
    Trie* cur = obj;
    for (int i = 0; i < 26; i++) 
        if (cur -> children[i])
            trieFree(cur -> children[i]);
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * struct Trie* obj = trieCreate();
 * trieInsert(obj, word);
 * bool param_2 = trieSearch(obj, word);
 * bool param_3 = trieStartsWith(obj, prefix);
 * trieFree(obj);
 */