#include <stdio.h>
#include <string.h>

typedef struct word_node{
    char word[50];
    int time;
    struct word_node * next;
}word_node;

FILE * openArticle(const char * article_path){
    FILE * fp;
    if((fp = fopen(article_path, "r")) == NULL){
        printf("Open file error!\n");
        return NULL;
    }
    else
        return fp;
}

word_node * findWord(const char *word, word_node *temp_p){
    while(temp_p){
        if(!strcmp(word, temp_p->word)){
            return temp_p;
        }
        temp_p = temp_p->next;
    }
    return NULL;
}

void printWordTimes(word_node * p){
    printf("The times of the words are as follows:\n");
    printf("Word            Times\n");
    while(p){
        printf("%-20s%d\n", p->word, p->time);
        p = p->next;
    }
}
