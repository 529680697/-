#include <malloc.h>
#include <time.h>
#include <windows.h>
#include "myFunction.h"

int main()
{
    FILE *fp;
    char path[100];
    sat_path(path);
    if((fp = openArticle(path)) != NULL){  //此处输入将要处理的文件路径
        double start = clock();  //计时开始
        word_node word_chain_list, *head_point = &word_chain_list, *tail_point = head_point;
        word_chain_list.time = 0;
        strcpy(word_chain_list.word, "TotalTimes");
        word_chain_list.next = NULL;
        while(!feof(fp)){
            char line[1000], temp_word[50];
            fgets(line, 1000, fp);  //按行读入文本文件
            //printf("%s", line);
            int i = 0;
            while(i < strlen(line)){
                int j = 0;
                while((line[i] <= 'z'&&line[i] >= 'a')||(line[i] <= 'Z'&&line[i] >= 'A')){  //查找形成单词 temp_word
                    temp_word[j] = line[i];
                    i++;
                    j++;
                }
                temp_word[j] = '\0';
                if (j != 0){
                	word_chain_list.time++;  //总单词次数加一
                    word_node *temp_p = findWord(temp_word, head_point->next);
                    if(temp_p){  //以创建的链表中存在该单词，次数加一
                        temp_p->time++;
                    } else{  //未找到，在链表尾部创建新节点
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
        output_count(head_point, start, end);
        printf("Count correctly!\n");
        system("pause");  //窗口暂停
    }
    return 0;
}