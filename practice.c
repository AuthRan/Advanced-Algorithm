#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPSArray(char *pat, int m, int *lps) {
    int i = 1;
    int length = 0;
    lps[0] = 0;
    while(i<m) {
        if(lps[i] == lps[length]){
            length++;
            lps[i] = length;
            i++;
        }else{
            if(length != 0){
                length = lps[length-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}