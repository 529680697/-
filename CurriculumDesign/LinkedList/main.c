#include <malloc.h>
#include <time.h>
#include <windows.h>
#include "myFunction.h"

int main()
{
    FILE *fp;
    if((fp = openArticle("1.txt")) != NULL){  //此处输入将要处理的文件路径
        word_node word_chain_list, *head_point = &word_chain_list, *tail_point = head_point;
        word_chain_list.time = 0;
        word_chain_list.next = NULL;
        double start = clock();  //计时开始

        while(!feof(fp)){
            char line[1000], temp_word[50];
            fgets(line, 1000, fp);  //按行读入文本文件
            //printf("%s", line);
            int i = 0;
            while(i < strlen(line)){
                int j = 0;
                while((line[i] <= 'z'&&line[i] >= 'a')||(line[i] <= 'Z'&&line[i] >= 'A')){
                    temp_word[j] = line[i];
                    i++;
                    j++;
                }
                temp_word[j] = '\0';
                if (j != 0){
                    word_node *temp_p = findWord(temp_word, head_point->next);
                    if(temp_p){
                        temp_p->time++;
                    } else{
                        temp_p  = (word_node *)malloc(sizeof(word_node));
                        strcpy(temp_p->word, temp_word);
                        temp_p->time = 1;
                        temp_p->next = NULL;
                        tail_point->next = temp_p;
                        tail_point = temp_p;
                    }
                }
                while(!(line[i] <= 'z'&&line[i] >= 'a') && !(line[i] <= 'Z'&&line[i] >= 'A') && i<strlen(line)){
                    i++;
                }
            }
        }
        fclose(fp);
        double end = clock();  //计时结束
        printf("Time-consuming of this document: %.2lfms!\n", end-start);  //输出用时

        printWordTimes(head_point->next);  //打印每个词语出现次数
        system("pause");  //窗口暂停
    }
    return 0;
}
