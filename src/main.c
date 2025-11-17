
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/function.h"


int main() {
    system("clear");
    /************************************ */
    node* head=NULL;
    head=playlist(head,"song_list");

//**************variable define************** */
    char ask; // for loop
    node * y=NULL; // node for album
    char song[100]; //name of song
    char singer[100];//name of singer
    char duration[10]; // duration of music
    char cha; //create to handle c bug
    char albname[100]; // name of album
/***************************** */


    printf("----------welcome--------------\n");
    do{
    printf("what you want to try!\n"
    "1.see the playlist\n"
    "2.see the album\n"
    "3.play the song from the playlist\n"
    "4.play the song from album\n"
    "5.delete the song\n"
    "6.add the song in playlist\n"
    "7.add the song in album\n");
    int choice;
    printf("choose what you want to try with serial No.");
    scanf(" %d",&choice);
    scanf("%c",&cha); // to clear the newline character bug
    system("clear");

    // #################################

    
    switch (choice)
    {
    case 1:
        printlist(head);
        break;
    case 2:
    printf("Name of album :");
    scanf("%s",albname);
    y=NULL;
    y=playlist(y,albname);
    printlist(y);
    break;
    case 3:
        play(head,"song_list");
        break;
    case 4:
        printf("name of album you want hear :");
        scanf("%s",albname);
        y=NULL;
        y=playlist(y,albname);
        play(y,albname);
        break;
    case 5:
        printf("Enter the name of song : ");
        fgets(song, sizeof(song), stdin);
        song[strcspn(song, "\n")] = '\0';

        printf("delete from:\n1.playlist\n2.album\n");
        int ch;
        printf("choose the serial No.");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            delete_from_csv("song_list",song);
            break;
            case 2:
            printf("Enter the name of album :");
            scanf("%s",albname);
            delete_from_csv(albname,song);
            break;
        }
        
        break;
    case 6:
        printf("Enter the name of song : ");fgets(song, sizeof(song), stdin);song[strcspn(song, "\n")] = '\0';
        printf("Enter the name of singer :");fgets(singer, sizeof(singer), stdin);singer[strcspn(singer, "\n")] = '\0';
        printf("Enter duration of music :");fgets(duration, sizeof(duration), stdin);duration[strcspn(duration, "\n")] = '\0';
        node *temp=(node*)malloc(sizeof(node));
        strcpy(temp->sname,song);
        strcpy(temp->singer,singer);
        strcpy(temp->time,duration);
        album("song_list",temp);
        free(temp);
        break;
    case 7:
        printf("Enter the name of album :");scanf("%s",albname);
        scanf("%c",&cha);
        printf("Enter the name of song : ");fgets(song, sizeof(song), stdin);song[strcspn(song, "\n")] = '\0';
        printf("Enter the name of singer :");fgets(singer, sizeof(singer), stdin);singer[strcspn(singer, "\n")] = '\0';
        printf("Enter duration of music :");fgets(duration, sizeof(duration), stdin);duration[strcspn(duration, "\n")] = '\0';
        node *temp2=malloc(sizeof(node));
        strcpy(temp2->sname,song);
        strcpy(temp2->singer,singer);
        strcpy(temp2->time,duration);
        album(albname,temp2);
        free(temp2);
        break;
    
    default:
    printf("Input is invalid!\n");
        break;
    }

    printf("type y to continue :");
    scanf(" %c",&ask);
    system("clear");
    }while(ask=='y');

    return 0;
}