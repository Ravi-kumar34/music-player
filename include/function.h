#ifndef FUNCTION_H
#define FUNCTION_H
typedef struct node{
    char ID[3];
    char sname[100];
    char singer[100];
    char time[10];
    struct node* next;
    struct node* pre;
}node;

node* playlist(node *head,char name[]);
void printlist(node* head);
void album(char name[],node *head);
void play(node* head,char filename[]);
void delete_from_csv(char filename[],char song_to_delete[]);
void histroy();
#endif