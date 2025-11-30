#include <stdio.h>
#include <string.h>

void modifiedSearch (char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    // CORRECTION 1: 'i' ko 0 se initialize karna zaroori hai
    int i = 0; 
    
    // CORRECTION 2: Loop condition safe banayi hai (Buffer overflow se bachne ke liye)
    while (i <= n - m) {
        int j;
        for (j = 0; j < m; j++) {
            if(text[i+j] != pattern[j]){
                break;
            }
        }

        // CORRECTION 3: 'else if' ka use karein taaki code clean rahe
        // aur ek baar mein ek hi decision le
        
        if (j == m) {
            // Pattern Found
            printf("Pattern Found at %d\n", i); // Computer index (0-based)
            // Ya agar human readable chahiye toh (i+1)
            
            i += j; // Jump pattern length
        }
        else if (j == 0) {
            // Mismatch at first character
            i += 1;
        }
        else {
            // Partial match (Logic for distinct characters)
            i += j;
        }
    }
}

int main() {
    char txt[] = "ABCDEABCDABC";
    char pat[] = "ABCD";
    printf("Text: %s\n", txt);
    printf("Pattern: %s\n", pat);
    printf("---------------------------\n");
    modifiedSearch(txt, pat);
    return 0;
}