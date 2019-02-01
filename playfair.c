#include <stdio.h>
#include <memory.h>

int main() {
    char key[255], str[255], temp, arr[5][5], alpha[30];
    int i, j, k, ct = 0, m = 1, n = 0, ct2 = 0, ct3 = 0;
    long key_len, str_len;

    printf("\n Enter the text");
    fgets(str, sizeof(str), stdin);
    printf("\n Enter the key");
    fgets(key, sizeof(key), stdin);
    key_len = strlen(key);
    str_len = strlen(str);

    for (i = 0; i < key_len; i++) {
        for (j = i + 1; j < key_len; j++) {
            if (key[i] == key[j] || key[j] == ' ') {
                for (k = j; k < key_len; k++) {
                    key[k] = key[k + 1];
                }
            }
        }
    }
    key_len = strlen(key);

    for(i=0;str[i];i++){
        if(str[i] != ' ')
            str[ct2++]=str[i];
    }
    str[ct2]='\0';
    str_len=strlen(str);

    temp = 'z';

    for (i = 0; i < str_len; i++) {
        if (str[i] == str[i + 1]) {
            for (long l = str_len - 1; l > i; l--) {
                str[l] = str[l - 1];
            }
            str[i + 1] = temp;
        }
    }

    for (i = 0; i < strlen(str); i++) {
        ct++;
    }

    if (ct % 2 != 0) {
        str[ct] = temp;
    }

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            arr[i][j]='0';
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; n < key_len-1; j++, n++) {
            if (j == 5) {
                m++;
                break;
            } else {
                arr[i][j] = key[n];
            }
        }
    }
    i = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        ct3 = 0;
        for (j = 0; j < key_len; j++) {
            if (c == key[j]) {
                break;
            } else {
                ct3++;
            }
        }
        if (ct3 == key_len) {
            alpha[i] = c;
            i++;
        }
    }
    long length_alpha = strlen(alpha);
    for(i=0;i<length_alpha;i++){
        if(alpha[i]=='q'){
            for(j=i;j<length_alpha;j++){
                alpha[j]=alpha[j+1];
            }
        }
    }
    k=0;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(arr[i][j] == '0'){
                arr[i][j]=alpha[k];
                k++;
            }
        }
    }
    int c=0,l=0;
    int ai[str_len],aj[str_len];
    for(k=0;k<str_len;k++){
        c=0;
        for(i=0;i<5;i++) {
            for (j = 0; j < 5; j++) {
                if (arr[i][j] == str[k]) {
                    ai[k]=i;
                    aj[k]=j;
                    c++;
                    break;
                }
            }
            if (c > 0) {
                break;
            }
        }

    }
    m=0;
    printf("\n Encrypted Text : ");
    int r1,r2,c1,c2;
    for(k=0;k<str_len;k+=2) {
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (arr[i][j] == str[m]) {
                    r1 = i;
                    c1 = j;
                }
                if (arr[i][j] == str[m + 1]) {
                    r2 = i;
                    c2 = j;
                }
            }

        }

        if (r1 == r2) {
            if (c2 == 4) {
                printf("%c%c", arr[r1][c1 + 1], arr[r1][0]);
            } else {
                printf("%c%c", arr[r1][c1 + 1], arr[r1][c2 + 1]);
            }
        }
        if (c1 == c2) {
            if (r2 == 4) {
                printf("%c%c", arr[r1 + 1][c1], arr[0][c2]);
            } else {
                printf("%c%c", arr[r1 + 1][c1], arr[r2 + 1][c2]);
            }
        }
        if (r1 != r2 && c1 != c2) {
            printf("%c%c", arr[r1][c2], arr[r2][c1]);
        }
        m+=2;
    }
}
