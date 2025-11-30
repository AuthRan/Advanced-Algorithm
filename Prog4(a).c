#include <stdio.h>
#include <string.h>

void search(char* pat, char* txt) {
    int M = strlen(pat); // Pattern ki length
    int N = strlen(txt); // Text ki length

    /* Outer Loop: Ye text ke upar slide karega. 
       Hum sirf (N - M) tak jayenge kyunki agar text ka bacha hua hissa 
       pattern se chhota hai, toh check karne ka fayda nahi.
    */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* Inner Loop: Current index 'i' se start karke pattern match karega.
        */
        for (j = 0; j < M; j++) {
            // Check karo ki text ka character aur pattern ka character same hai ya nahi
            if (txt[i + j] != pat[j]) {
                break; // Agar mismatch hua, toh inner loop tod do aur next 'i' pe jao
            }
        }

        // Agar inner loop pura chala (j == M), iska matlab saare characters match ho gaye
        if (j == M) {
            printf("Pattern found at index %d \n", i);
        }
    }
}

int main() {
    char txt[] = "AABAACAADAABAABA";
    char pat[] = "AABA";
    
    printf("Text: %s\n", txt);
    printf("Pattern: %s\n", pat);
    printf("---------------------------\n");
    
    search(pat, txt);
    
    return 0;
}