#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib.h"
#include "node.h"

struct song_library *new_lib()
{
    struct song_library *slib = malloc(sizeof(struct song_library));
    int i;
    for (i = 0; i < sizeof(slib->lib) / sizeof(struct song_list); i++)
    {
        (slib->lib)[i] = new_list();
    }
    return slib;
}

struct song_library *lib_place_song(struct song_library *slib, char name[], char artist[])
{
    place_song((slib->lib)[lib_index(artist[0])], name, artist);
    return slib;
}

//return first song of artist
struct song_node *lib_find_artist(struct song_library *slib, char artist[])
{
    return find_artist((slib->lib)[lib_index(artist[0])], artist);
}

struct song_node *lib_find_song(struct song_library *lib, char name[], char artist[])
{
    struct song_node *node;
    node = find_song(lib->lib[lib_index(artist[0])], name, artist);
    if(node)
    {
        return node;
    }
    return NULL;
}

int lib_index(char c)
{
    if (c > 64 && c < 91)
        return c - 65;
    else if (c > 96 && c < 123)
        return c - 97;
    else
        return 26;
}

void lib_list_print(struct song_library *slib, char c)
{
    print_list((slib->lib)[lib_index(c)]);
}

void lib_print_artist_songs(struct song_library *slib, char artist[])
{
    struct song_node *sn = lib_find_artist(slib, artist);
    print_artist_songs(sn, artist);
}

void lib_print_lib(struct song_library *lib)
{
    char curr = 'a';
    int i;

    for (i = 0; i < 26; i++)
    {
        lib_list_print(lib, curr);
        curr++;
    }

    lib_list_print(lib, 'z' + sizeof(struct song_list));
}

void shuffle(struct song_library *lib)
{
    srand(time(NULL));

    int i;
    struct song_list *list;
    char index;
    for(i = 0; i < 5; i++)
    {
        index = (rand() % 26) + 65;
        list = lib->lib[lib_index(index)];
        if (song_list_len(list) == 0)
        {
            i--;
        }
        else
        {
            print_song(rand_song(list));
            index = (rand() % 26) + 65;
        }
    }
}


struct song_library *delete_song(struct song_library *lib, char name[], char artist[])
{
    char letter = artist[0];
    struct song_list *list;
    list = lib->lib[lib_index(letter)];

    struct song_node *node;
    node = remove_song(list, name, artist);
    return lib;
}


struct song_library *clear_lib(struct song_library *list)
{
    int i;
    struct song_list *sl;

    for (i = 0; i < 26; i++)
    {
        sl = list->lib[i];
        free_song_list(sl);
    }
    return list;
}


