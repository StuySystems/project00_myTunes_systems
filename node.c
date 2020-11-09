#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

struct song_node* new_song(char name[], char artist[]){
    struct song_node* sn = malloc(sizeof(struct song_node));
    strncpy(sn->name, name, sizeof(sn->name));
    strncpy(sn->artist, artist, sizeof(sn->artist));
    sn->next = NULL;
    return sn;
}

struct song_list* new_list(){
    struct song_list* sl = malloc(sizeof(struct song_list));
    sl->head = NULL;
    return sl;
}

struct song_node* insert_song(struct song_list* sl, char name[], char artist[]){
    struct song_node* sn = new_song(name, artist);
    sn->next = sl->head;
    sl->head = sn;
    return sn;
}

struct song_node* place_song(struct song_list* sl, char name[], char artist[]){
    struct song_node* sn = new_song(name, artist);
    struct song_node* track = sl->head;

    if(track == NULL || songcmp(track, sn) > 0) {
        insert_song(sl, name, artist);
        return sn;
    }

    while(songcmp(track->next, sn) < 0){
        if(track->next->next == NULL){
            track->next->next = sn;
            return sn;
        }
        else track = track->next;
    }
    sn->next = track->next;
    track->next = sn;
    return sn;

}

int songcmp(struct song_node* s1, struct song_node* s2){
    if(s1 == NULL) return 1;
    else if(s2 == NULL) return -1;

    int c = strcmp(s1->artist, s2->artist);
    if(c != 0) return c;
    else return strcmp(s1->name, s2->name);
}

void print_song(struct song_node* sn){
    printf("Artist: %s\nName: %s\n", sn->artist, sn->name);
}

void print_list(struct song_list* sl){
    struct song_node* track = sl->head;
    while(track != NULL){
        print_song(track);
        printf("\n");
        track = track->next;
    }
}
