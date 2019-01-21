#include <stdio.h>
#include <memory.h>

int main() {
    char key[255], str[255], temp, arr[5][5], alpha[30],str_arr[255];
    int i, j, k, ct = 0, m = 1, n = 0, ct2 = 0, l2, ct3 = 0;
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
    //puts(key);

    for (i = 0; i < str_len; i++) {
        if (str[i] == ' ') {
            for (j = i; j < str_len - 1; j++) {
                str[j] = str[j + 1];
            }
        }
    }
    str_len = strlen(str);

    temp = 'z';
    //printf("%d",ct);
    //printf("%ld",str_len);
    for (i = 0; i < str_len; i++) {
        if (str[i] == str[i + 1]) {
            for (long l = str_len - 1; l > i; l--) {
                str[l] = str[l - 1];
            }
            str[i + 1] = temp;
        }
    }
    //puts(str);
    str_len = strlen(str);
    // printf("%ld",str_len);
    for (i = 0; i < str_len; i++) {
        ct++;
    }
    //printf("%d",ct);
    if (ct % 2 != 0) {
        str[ct] = temp;
    }
    //puts(str);

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            arr[i][j]='0';
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf(" %c ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("%ld \n",key_len);
    for (i = 0; i < m; i++) {
        //n=0;
        for (j = 0; n < key_len-1; j++, n++) {
            if (j == 5) {
                m++;
                break;
            } else {
                arr[i][j] = key[n];
            }

        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf(" %c ", arr[i][j]);
        }
        printf("\n");
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
    puts(str);
    puts(key);
    puts(alpha);
    k=0;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(arr[i][j] == '0'){
                arr[i][j]=alpha[k];
                k++;
            }
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf(" %c ", arr[i][j]);
        }
        printf("\n");
    }
    int pos_i,pos_j,pos_i2,pos_j2;
    for(k=0;k<str_len;k+=2){
        for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                if(str[k]==arr[i][j]){
                    pos_i=i;
                    pos_j=j;
                }
                if(str[k+1]==arr[i][j]){
                    pos_i2=i;
                    pos_j2=j;
                }
                if(pos_i == pos_i2){
                    // Encryption Code
                }
            }

        }
    }

}
