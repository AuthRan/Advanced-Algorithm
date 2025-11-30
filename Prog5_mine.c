#include <stdio.h>
#include <string.h>
#include <math.h>

#define d 10

void rabinSearch(char *text, char *pattern, int q) {
    int n = strlen(text);
    int m = strlen(pattern);

    int t = 0;
    int p = 0;
    int h = 1;

    int suprious_hit = 0;

    for(int i =0; i<m-1; i++) {
        h = (h*d) % q;
    }
    // Initial hash
    for (int i=0; i<m; i++) {
        t = (t*d + (text[i] - '0'))%q;
        p = (p*d + (pattern[i] - '0'))%q;  //
    }

    for (int i = 0 ; i<= n-m; i++) {   //
        if (t == p){
            int matched = 1;
            for (int j =0 ; j<m; j++) {
                if(text[i+j] != pattern[j]){
                    matched = 0;
                    break;
                }
            }
            if(matched){
                printf("Pattern found at %d\n", i+1);
            }
            else {
                printf("Suprious hit at %d\n", i+1);
                suprious_hit ++;
            }
        }
        if (i<n-m){
            t = (d * (t - (text[i] - '0') *h) + (text[i+m] - '0'))%  q;   //

            if (t < 0){
                t = t + q;
            }
        }
    }
    printf("-----------------------\n");
    printf("Suprous hits: ", suprious_hit);
}

int main() {
    char txt[] = "3141592653589793";
    char pat[] = "26";
    int q = 11;
    rabinSearch(txt, pat, q);
    return 0;
}