#include "node.h"
#ifndef LIB_H
#define LIB_H


struct song_library{
    struct song_list* lib[27];
};

struct song_library* new_lib();
struct song_library* lib_place_song(struct song_library* slib, char name[], char artist[]);
struct song_node* lib_find_artist(struct song_library* slib, char artist[]);
int lib_index(char c);
void lib_list_print(struct song_library* slib, char c);
void lib_print_artist_songs(struct song_library* slib, char artist[]);

#endif
