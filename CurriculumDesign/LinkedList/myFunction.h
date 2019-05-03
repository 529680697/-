#include <stdio.h>
#include <string.h>

typedef struct word_node{
    char word[50];  //保存单词
    int time;  //单词出现次数
    struct word_node * next;
}word_node;

void sat_path(char *path){
    printf("Please input the absolute path of the file which you want to count its words' number:\n");
    scanf("%s", path);
}

FILE * openArticle(const char * article_path){  //打开英文文章
    FILE * fp;
    if((fp = fopen(article_path, "r")) == NULL){
        printf("Open file error!\n");
        return NULL;
    }
    else
        return fp;
}

//在已经创建的链表中寻找单词word，若找到，返回指向保存此单词节点的指针，否则返回NULL
word_node * findWord(const char *word, word_node *temp_p){
    while(temp_p){
        if(!strcmp(word, temp_p->word)){
            return temp_p;
        }
        temp_p = temp_p->next;
    }
    return NULL;
}

void output_count(word_node * p, double start, double end){
    FILE * fp;
    if((fp = fopen("wordNumber.res", "w+")) == NULL){
        printf("Open file eror!\n");
        return;
    } else {
        fprintf(fp, "Time-consuming of this document: %.2lfms!\n\n", end-start);  //输出用时
        fprintf(fp, "The times of the words are as follows:\n");
        fprintf(fp, "Word                Times\n");
        while (p)
        {
            fprintf(fp, "%-20s%d\n", p->word, p->time);
            p = p->next;
        }
    }
    fclose(fp);
}