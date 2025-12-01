#include <stdio.h>
#include <string.h>
#include <math.h>

/*
    d = Number of characters in input alphabet (Digits hai toh 10)
    q = A prime number for modulo (Question mein 11 diya hai)
*/
#define d 10

void search(char pat[], char txt[], int q) {
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    
    int p = 0; // Pattern ka Hash value
    int t = 0; // Text ki current window ka Hash value
    int h = 1; // Ye calculate karega: pow(d, M-1) % q
    
    int spurious_hits = 0; // Fake matches count karne ke liye

    // Step 1: 'h' calculate karo. 
    // Agar pattern length 2 hai, toh h = 10^(2-1) % 11 = 10
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
    // h = (d ^ M-1) % q;
    // Step 2: Pattern aur pehle window ka hash calculate karo
    for (i = 0; i < M; i++) {
        // (txt[i] - '0') isliye kar rahe taaki character '3' integer 3 ban jaye
        p = (d * p + (pat[i] - '0')) % q;
        t = (d * t + (txt[i] - '0')) % q;
    }
    

    printf("Pattern Hash (p) is: %d\n", p);
    printf("Processing Windows...\n");

    // Step 3: Rolling Hash Loop
    for (i = 0; i <= N - M; i++) {
        
        // --- CHECKING FOR MATCH ---
        // Sabse pehle Hash check karo
        if (p == t) {
            // Agar Hash same hai, toh characters check karo
            int match_found = 1;
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    match_found = 0;
                    break;
                }
            }

            if (match_found) {
                printf("  -> VALID HIT at index %d (Value: %.2s)\n", i, &txt[i]);
            } else {
                // Agar Hash same tha par characters alag nikle = SPURIOUS HIT
                spurious_hits++;
                printf("  -> SPURIOUS HIT at index %d (Value: %.2s, Hash: %d)\n", i, &txt[i], t);
            }
        }

        // --- ROLLING HASH FORMULA ---
        // Agle window ke liye hash calculate karo
        if (i < N - M) {
            // Formula: t = (d * (t - txt[i]*h) + txt[i+M]) % q
            // 1. Remove leading digit
            // 2. Multiply by d (shift left)
            // 3. Add new trailing digit
            t = (d * (t - (txt[i] - '0') * h) + (txt[i + M] - '0')) % q;

            // C mein negative modulo handle karne ke liye:
            if (t < 0)
                t = (t + q);
        }
    }
    
    printf("------------------------------------------------\n");
    printf("Total Spurious Hits: %d\n", spurious_hits);
}

int main() {
    char txt[] = "3141592653589793";
    char pat[] = "26";
    
    // Question mein diya gaya Modulo 'q' = 11
    int q = 11;
    
    search(pat, txt, q);
    
    return 0;
}