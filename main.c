#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "lib.h"

int main(int argc, char const *argv[]) {
    struct song_list* sl = new_list();
    insert_song(sl, "Java", "Hello World");
    place_song(sl, "35", "FizzBuzz");
    place_song(sl, "Python", "Hello World");

    place_song(sl, "C", "Hello World");
    place_song(sl, "public static void", "FooBar");

    printf("Testing print_list:\n");
    print_list(sl);

    printf("Testing find_song:\nLooking for [Artist: Hello World Name: Java]\n");
    struct song_node* sn1= find_song(sl, "Java", "Hello World");
    if (sn1) {printf("Song found!\t"); print_song(sn1);}
    else printf("Song not found\n");

    printf("Testing find_artist:\nLooking for [Artist: FizzBuzz]\n");
    struct song_node* sn2= find_artist(sl, "FizzBuzz");
    if (sn2) {printf("Artist found! %s: ", sn2->artist); print_artist_songs(sn1, sn1->artist);}
    else printf("Artist not found\n");

    printf("Testing songcmp (helper function):\n");
    struct song_node* sn3= new_song("Java", "Hello World");
    struct song_node* sn4= new_song("Python", "Hello World");
    printf("Comparing [Hello World: Python] to [Hello World: Java]\n%d", songcmp(sn3,sn4));

    printf("Testing rand_song:\n");
    struct song_node* sn5= rand_song(sl);
    print_song(sn5);

    printf("Testing remove:\nRemoving [Artist: Hello World Name: C]\n");
    struct song_node* sn6= remove_song(sl, "C", "Hello World");
    print_list(sl);

    printf("Testing free_song_list:\n");
    printf("List after free_song_list:\t");
    print_list(sl);

    return 0;
}
