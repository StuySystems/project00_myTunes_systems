#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node* new_song(char name[], char artist[]){
    struct song_node* sn = malloc(sizeof(song_node));
    strncpy(sn->name, name, sizeof(sn->name));
    strncpy(sn->artist), artist, sizeof(sn->artist);
    sn->next = NULL;
    return sn;
}

struct song_node* insert_song(struct song_list*, char name[], char artist[]){

}
