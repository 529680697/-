#include <malloc.h>
#include <time.h>
#include <windows.h>
#include "myFunction.h"

int main()
{
    FILE *fp;
    if((fp = openArticle("1.txt")) != NULL){
        hash_node hash_list[MAX_PRIME_LESS_THAN_HASH_LEN];
        double start = clock();
        for (int k = 0; k < MAX_PRIME_LESS_THAN_HASH_LEN; ++k) {
            hash_list[k].time = 0;
            hash_list[k].next = NULL;
        }
        while(!feof(fp)){
            char line[1000], temp_word[50];
            fgets(line, 1000, fp);
            int i = 0;
            while(i < strlen(line)){
                int j = 0;
                while((line[i] <= 'z'&&line[i] >= 'a')||(line[i] <= 'Z'&&line[i] >= 'A')){  //获取一行中的单词
                    temp_word[j] = line[i];
                    i++;
                    j++;
                }
                temp_word[j] = '\0';  //temp_p即为一行文字中的一个单词
                if (j != 0){
                    unsigned int location = hash(temp_word, strlen(temp_word));  //找到该单词在hash表中的位置
                    if (put_word_to_hash_list(temp_word, hash_list, location) != 0){  //将该单词放入hash表中
                        printf("Put word to hash list error!\n");
                        return 0;
                    }
                }
                while(!(line[i] <= 'z'&&line[i] >= 'a') && !(line[i] <= 'Z'&&line[i] >= 'A') && i<strlen(line)){
                    i++;
                }
            }
        }
        fclose(fp);

        double end = clock();
        printf("Time-consuming of this document: %.2lfms!\n", end-start);
        print_the_times_of_the_words(hash_list);  //输出各个单词的出现频率
        system("pause");
    }
    return 0;
}
