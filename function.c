#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "../include/function.h"
FILE *his;
//******************************************* */
node* playlist(node *head,char name[]){
    his=fopen("history.txt","a");
    fprintf(his,"see the %s\n",name);
    fclose(his);
    char albname[100]="../src/";
    strcat(albname,name);
    strcat(albname,".csv");
    node* x=head;
    FILE *fp;
    char line[1024];
    fp = fopen(albname, "r");
    if (fp == NULL) {
        perror("Unable to open file");
        return NULL;
    }
    while (fgets(line, sizeof(line), fp)) {
        char arr[3][100];
        line[strcspn(line, "\n")] = '\0';
        node*a=malloc(sizeof(node));
        char *token = strtok(line, ",");
        for (int i=0;token != NULL;i++) {
            strcpy(arr[i],token);
            token;  // print each value
            token = strtok(NULL, ",");
        }
        strcpy(a->sname,arr[0]);
        strcpy(a->singer,arr[1]);
        strcpy(a->time,arr[2]);
        if (head == NULL) {
        head = a;  // Update head if list is empty
        x = head;
        } else {
            x->next = a;
            x = x->next;
        }
        }x->next=NULL;
    fclose(fp);
    node *current = head;
    current->pre=NULL;

    while (current->next!= NULL) {
        current->next->pre= current;        
        current = current->next;    
    }
    return head;
}

//********************************************************** */
void printlist(node* head){
    
    printf("%-30s%-30s%-6s\n","SONG NAME","SINGER NAME","DURATION");
    node*y=head;
    while(y!=NULL){
        printf("%-30s%-30s%-6s",y->sname,y->singer,y->time);
        printf("\n");
        y=y->next;
    }
}
//************************************************************* */


void album(char name[],node *head){
    his=fopen("history.txt","a");
    fprintf(his,"add %s to %s\n",head->sname,name);
    fclose(his);
    char albname[100]="../src/";
    strcat(albname,name);
    strcat(albname,".csv");
    FILE *ptr;
    ptr= fopen(albname, "a");
    if (ptr == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(ptr, "%s,", head->sname);
    fprintf(ptr, "%s,", head->singer);
    fprintf(ptr, "%s\n", head->time);

    fclose(ptr);
}
//*************************************************************** */


void play(node* head,char filename[]){
    his=fopen("history.txt","a");
    fprintf(his,"play the %s\n",filename);
    fclose(his);

    char command[10]="start";
    node *y=head;
    while(y->next!=NULL){
        y=y->next;
    }y->next=head;
    head->pre=y;
    y=y->next;
    while (strcmp(command,"close")!=0){
        printf("%-30s%-30s%-6s\n","SONG NAME","SINGER NAME","DURATION");
        printf("%-30s%-30s%-6s\n",y->sname,y->singer,y->time);
        printf("what you to do next :");
        scanf("%s",command);
        if(strcmp(command,"next")==0){
            y=y->next;
        }else if(strcmp(command,"pre")==0){
            y=y->pre;}
        else if(strcmp(command,"add")==0){
            char albname[100];
            printf("Enter the name of album :");
            scanf("%s",albname);
            album(albname,y);
        }else if(strcmp(command,"delete")==0){
            delete_from_csv(filename,y->sname);
            node *temp=y->next;
            y->pre->next=y->next;
            y->next->pre=y->pre;
            y=temp;
        }
        system("clear");
        
    }
}
/*************************************************** */

void delete_from_csv(char filename[], char song_to_delete[]){
    his=fopen("history.txt","a");
    fprintf(his,"delete %s from %s",song_to_delete,filename);
    fclose(his);
    char albname[100]="../src/";
    strcat(albname,filename);
    strcat(albname,".csv");

    FILE *fp;
    fp= fopen(albname, "r");
    if (fp==NULL) {
        perror("Error opening file");
        return;
    }

    FILE *temp;
    temp= fopen("temp.csv", "w");
    if (!temp) {
        perror("Error opening temp file");
        fclose(fp);
        return;
    }

    char line[1024];

    while (fgets(line, sizeof(line), fp)) {
        char copy[1024];
        strcpy(copy, line);
        char *token = strtok(copy, ",");  
        if (token && strcmp(token, song_to_delete) == 0) {
            // Skip this line (delete it)
            continue;
        }
        fputs(line, temp);
    }
    fclose(fp);
    fclose(temp);
    remove(albname);
    rename("temp.csv", albname);
    printf("Deleted '%s' successfully.\n", song_to_delete);  
}
void histroy(){
    FILE * fPtr;
    fPtr = fopen("histroy.txt", "r");
    if(fPtr == NULL)
    {
        printf("histroy histroy store.\n");
        exit(0);
    }
    char ch;
    do {
        ch = fgetc(fPtr);
        putchar(ch);
    } while(ch != EOF); 
}