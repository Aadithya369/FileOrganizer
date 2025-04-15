#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 100000

typedef struct State {
    int len, link;
    int next[128];
} State;

State sa[MAXLEN * 2];
int size, last;
char longest_substring[MAXLEN];

void sa_init() {
    size = last = 0;
    sa[0].len = 0;
    sa[0].link = -1;
    memset(sa[0].next, -1, sizeof(sa[0].next));
    size++;
}

void sa_extend(char c) {
    int cur = size++, p;
    sa[cur].len = sa[last].len + 1;
    memset(sa[cur].next, -1, sizeof(sa[cur].next));
    for (p = last; p != -1 && sa[p].next[(int)c] == -1; p = sa[p].link)
        sa[p].next[(int)c] = cur;
    if (p == -1)
        sa[cur].link = 0;
    else {
        int q = sa[p].next[(int)c];
        if (sa[p].len + 1 == sa[q].len)
            sa[cur].link = q;
        else {
            int clone = size++;
            sa[clone] = sa[q];
            sa[clone].len = sa[p].len + 1;
            for (; p != -1 && sa[p].next[(int)c] == q; p = sa[p].link)
                sa[p].next[(int)c] = clone;
            sa[q].link = sa[cur].link = clone;
        }
    }
    last = cur;
}

int longest_common_substring(char *text) {
    int v = 0, l = 0, best = 0, best_pos = -1;
    for (int i = 0; text[i]; i++) {
        while (v && sa[v].next[(int)text[i]] == -1) {
            v = sa[v].link;
            l = sa[v].len;
        }
        if (sa[v].next[(int)text[i]] != -1) {
            v = sa[v].next[(int)text[i]];
            l++;
        }
        if (l > best) {
            best = l;
            best_pos = i;
        }
    }
    
    if (best_pos != -1) {
        int start_index = best_pos - best + 1;
        strncpy(longest_substring, text + start_index, best);
        longest_substring[best] = '\0';  // Ensure null termination

    } else {
        longest_substring[0] = '\0';
    }
    
    return best;
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

void read_file(const char *filename, char *buffer) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    fread(buffer, 1, MAXLEN - 1, file);
    buffer[MAXLEN - 1] = '\0';
    fclose(file);
    to_lowercase(buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }
    
    char text1[MAXLEN], text2[MAXLEN];
    read_file(argv[1], text1);
    read_file(argv[2], text2);
    
    sa_init();
    for (int i = 0; text1[i]; i++)
        sa_extend(text1[i]);
    
    int lcs_length = longest_common_substring(text2);
    printf("Longest Common Substring Length: %d\n", lcs_length);
    printf("Longest Common Substring: %s\n", longest_substring);
    
    return 0;
}

