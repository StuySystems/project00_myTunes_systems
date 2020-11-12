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
struct song_node* find_song(struct song_list* sl, char name[], char artist[]);
struct song_node* find_artist(struct song_list* sl, char artist[]);
struct song_node* rand_song(struct song_list* sl);
int song_list_len(struct song_list* sl);
struct song_node* remove_song(struct song_list *sl, char name[], char artist[]);
struct song_list* free_song_list(struct song_list* sl);
void print_artist_songs(struct song_node* sn, char artist[]);

#endif
