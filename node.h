#ifndef NODE_H
#define NODE_H

struct song_node{
    char name[100];
    char artist[100];
    struct song_node *next;
};

struct song_list{
    struct song_node* head;
};

struct song_node* new_song(char name[], char artist[]);
struct song_node* insert_song(struct song_list* sl, char name[], char artist[]);
struct song_node* place_song(struct song_list* sl, char name[], char artist[]);
struct song_list* new_list();
int songcmp(struct song_node* s1, struct song_node* s2);
void print_song(struct song_node * sn);
void print_list(struct song_list* sl);


#endif
