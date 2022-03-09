#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_num_mod70(int lotto_array) {
    lotto_array = rand() % 70;
    while(lotto_array == 0) { 
        lotto_array = rand() % 70;
    } 
    return lotto_array;
}
int rand_num_mod11(int lotto_array) {
    lotto_array = rand() % 11;
    while(lotto_array == 0) { 
        lotto_array = rand() % 11;
    } 
    return lotto_array;
}
int get_rad_num(int lotto_array[7]) {

    for(int j = 0; j < 7; j++) {
        if(j < 6){
            lotto_array[j] = rand_num_mod70(lotto_array[j]);
        } else if (j = 6) {
            lotto_array[6] = rand_num_mod11(lotto_array[6]);
        }
        //check lotto array[i] isn't 0;
    }
    return lotto_array[7];
}
int array_swap(int lotto_array[7]) {
    int tmp = 0;
    for(int j = 0; j < 6 ;j++) {
        for(int arr_lotto = j; arr_lotto < 6; arr_lotto++) {
            if (lotto_array[j] > lotto_array[arr_lotto]) {
                tmp = lotto_array[j];
                lotto_array[j] = lotto_array[arr_lotto];
                lotto_array[arr_lotto] = tmp;
            }
        }
    }
    return lotto_array[7];
}
int array_rerandom(int lotto_array[7]) {
    for (int j = 0; j < 6; j++) {
        for(int z =0 ; z < 6; z++){
            while ((lotto_array[j] == lotto_array[z] && j != z) || 
                    lotto_array[j] == lotto_array[6]) {
                lotto_array[j] = rand_num_mod70(lotto_array[j]);
            }
        }
    }
    return lotto_array[7];
}
int print_array (int lotto_array[7], FILE*fp) {
    for(int j = 0 ; j < 7 ; j++) {
        fprintf(fp, "%.2d ", lotto_array[j]);
    }
    fprintf(fp, "\n");
}
int print_last(int num_row, FILE*fp) {
    for(int i = num_row+1; i < 6; i++) {
        fprintf(fp,"[%d]: " , i);
        for(int j = 0; j < 7; j++) {
            fprintf(fp, "-- ");
            j == 6 ? fprintf(fp,"\n") : 1;
        }
    }
    fprintf(fp, "======== csie@CGU =========\n");
}

int main() {
    FILE* fp;
    FILE* fr;
    int sell_num[1]= {1};
    int sell_numpluse[1]= {1};
        if((fr = fopen("a.bin", "r")) == NULL) {
            fr = fopen("a.bin", "wb");
            fwrite(sell_num, sizeof(int), 1, fr);
        } else {
            fr = fopen("a.bin", "rb");
            fread(sell_num, sizeof(int), 1, fr);
            fseek(fr, 0, SEEK_SET);
            fclose(fr);
            fr = fopen("a.bin", "wb+");
            sell_numpluse[0] = sell_num[0] +1;
            fwrite(sell_numpluse, sizeof(int), 1, fr);
        }
    int n =  snprintf(NULL, 0, "lotto[%05d].txt",sell_numpluse[0]);
    char s1[n+1];
    snprintf(s1, sizeof(s1), "lotto[%05d].txt",sell_numpluse[0]);
    fp = fopen(s1, "w+");
    
    fclose(fr);
    int row_num = sell_numpluse[0];
    time_t curtime;
    time(&curtime);
    fprintf(fp, "======== lotto649 =========\n");
    fprintf(fp, "=======+ No. %05d +=======\n= %.24s=\n",  sell_numpluse[0], ctime(&curtime));
    srand((unsigned) curtime);
    for (int i = 1; i <= row_num; i++) {
        int lotto_array[8] = {0};
        get_rad_num(lotto_array);
        fprintf(fp, "[%d]: ", i);
        lotto_array[8] = array_rerandom(lotto_array);
        lotto_array[8] = array_swap(lotto_array);
        print_array(lotto_array, fp); //fprintf3
    }
    print_last(row_num, fp); //fprintf4
    fclose(fp);
    return 0;
}
