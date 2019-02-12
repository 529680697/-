#include <stdio.h>
#include <string.h>

#define MAX_PRIME_LESS_THAN_HASH_LEN 29989

typedef struct hash_node{
    char word[50];
    int time;
    struct hash_node * next;
}hash_node;

FILE * openArticle(const char * article_path){
    FILE * fp;
    if((fp = fopen(article_path, "r")) == NULL){
        printf("Open file error!\n");
        return NULL;
    }
    else
        return fp;
}

unsigned int hash(char *s, int len){
    register unsigned int sum = 0;
    register unsigned int h = 0;
    register char *p = s;

    while(p - s < len)
    {
        register unsigned short a = (unsigned short) *(p++);
        sum ^=  a * (p - s);
        h ^= a / (p - s);
    }
    return ((sum << 16) | h) % MAX_PRIME_LESS_THAN_HASH_LEN;
}


int put_word_to_hash_list(char *word, hash_node *root, unsigned int location){
    if (root[location].time == 0){  //hash表不冲突，即表中location位置处无单词存放
        strcpy(root[location].word, word);
        root[location].time++;
    } else {
        if (root[location].next == NULL && strcmp(root[location].word, word) != 0){  //hash表中location位置处仅有一个单词且不与将要存放的单词相同
            root[location].next = (hash_node *)malloc(sizeof(hash_node));
            if (!root[location].next)
                exit(-1);
            strcpy(root[location].next->word, word);
            root[location].next->time = 1;
            root[location].next->next = NULL;
        } else if (root[location].next == NULL && strcmp(root[location].word, word) == 0){  //hash表中location位置处仅有一个单词且与将要存放的单词相同
            root[location].time++;
        } else{
            if (strcmp(root[location].word, word) == 0){  //hash表中location位置处有多个单词且第一个单词为将要存放的单词
                root[location].time++;
            } else if (strcmp(root[location].next->word, word) == 0){  //hash表中location位置处有多个单词且第二个单词为将要存放的单词
                root[location].next->time++;
            } else{    //hash表中location位置处有多个单词且第一、二个单词不是将要存放的单词
                hash_node *p = root[location].next;
                while (p->next && strcmp(p->next->word, word) != 0){  //寻找将要存放的单词位置
                    p = p->next;
                }
                if (p->next){  //hash表中存在将要存放的单词位置
                    p->next->time++;
                } else{  //hash表中不存在将要存放的单词，在location处链表末尾加入新的结点
                    p->next = (hash_node *)malloc(sizeof(hash_node));
                    if (!p->next)
                         exit(-1);
                    strcpy(p->next->word, word);
                    p->next->next = NULL;
                    p->time = 1;
                }
            }
        }
    }
    return 0;
}

int print_the_times_of_the_words(hash_node *root){
    printf("The times of the words are as follows:\n");
    printf("Word            Times\n");
    for (unsigned int i = 0; i < MAX_PRIME_LESS_THAN_HASH_LEN; ++i) {
        if (root[i].time != 0){  //位置i处存在单词
            if (root[i].next == NULL)  //位置i处仅存在一个单词
                printf("%-20s%d\n", root[i].word, root[i].time);
            else{  //位置i处存在多个单词
                hash_node *p = root[i].next;
                while (p){
                    printf("%-20s%d\n", p->word, p->time);
                    p = p->next;
                }
            }
        }
    }
    return 0;
}
