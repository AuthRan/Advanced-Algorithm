#include <stdio.h>
#include <string.h>

// Step 1: Yeh function LPS table banata hai (Secret Weapon)
// Yeh batata hai ki pattern khud mein kitna repeat ho raha hai.
void computeLPSArray(char* pat, int M, int* lps) {
    int length = 0; // Pichle sabse lambe prefix ki length
    int i = 1;

    lps[0] = 0; // Pehle character ka lps hamesha 0 hota hai

    // Loop pattern ke end tak chalega
    while (i < M) {
        if (pat[i] == pat[length]) {
            // Agar character match hua (Example: A...A)
            length++;
            lps[i] = length;
            i++;
        } else {
            // Agar match nahi hua
            if (length != 0) {
                // Agar length 0 nahi hai, toh hum piche wale match par jump karenge
                // Yeh tricky part hai: Hum i ko aage nahi badhate, bas length kam karte hain
                length = lps[length - 1];
            } else {
                // Agar length 0 hai, matlab kuch match nahi hua
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Step 2: Main KMP Search Function
void KMPSearch(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    // LPS array create karo
    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]

    while (i < N) {
        if (pat[j] == txt[i]) {
            // Agar character match ho raha hai, dono aage badhao
            j++;
            i++;
        }

        if (j == M) {
            // Agar j pattern ki length tak pahunch gaya, matlab Pattern Mil Gaya!
            printf("Pattern found at index %d \n", i - j);
            
            // Ab agla dhoondne ke liye wapas mat jao, smart jump karo
            j = lps[j - 1]; 
        }

        // Mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Agar match fail hua...
            
            if (j != 0) {
                // YAHAN MAGIC HOTA HAI
                // Hum i ko wapas piche nahi le jate (Naive ki tarah)
                // Hum sirf j ko LPS table ki madad se piche shift karte hain
                j = lps[j - 1];
            } else {
                // Agar j 0 par hai aur match nahi hua, toh text aage badhao
                i = i + 1;
            }
        }
    }
}

int main() {
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    
    printf("Text: %s\n", txt);
    printf("Pattern: %s\n", pat);
    printf("--------------------------\n");
    
    KMPSearch(pat, txt);
    
    return 0;
}