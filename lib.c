#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib.h"
#include "node.h"

struct song_library* new_lib(){
    struct song_library* slib = malloc(sizeof(struct song_library));
    int i;
    for(i = 0; i < sizeof(slib->lib)/sizeof(struct song_list); i++){
        (slib->lib)[i] = new_list();
    }
    return slib;
}

struct song_library* lib_place_song(struct song_library* slib, char name[], char artist[]){
    place_song((slib->lib)[lib_index(artist[0])], name, artist);
    return slib;
}

//return first song of artist
struct song_node* lib_find_artist(struct song_library* slib, char artist[]){
    return find_artist((slib->lib)[lib_index(artist[0])], artist);
}

int lib_index(char c){
    if(c > 64 && c < 91) return c - 65;
    else if (c > 96 && c < 123) return c - 97;
    else return 26;
}

void lib_list_print(struct song_library* slib, char c){
    print_list((slib->lib)[lib_index(c)]);
}

void lib_print_artist_songs(struct song_library* slib, char artist[]){
    struct song_node* sn = lib_find_artist(slib, artist);
    print_artist_songs(sn, artist);
}
