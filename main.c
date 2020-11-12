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
    printf("********************************************\n");


    printf("Testing find_song:\nLooking for [Artist: Hello World Name: Java]\n");
    struct song_node* sn1= find_song(sl, "Java", "Hello World");
    if (sn1) {printf("Song found!\t"); print_song(sn1);}
    else printf("Song not found\n");
    printf("********************************************\n");

    printf("Testing find_artist:\nLooking for [Artist: Hello]\n");
    struct song_node* sn2= find_artist(sl, "Hello");
    if (sn2) {
      printf("Artist found!\n %s:\n", sn2->artist);
      print_artist_songs(sn2, sn2->artist);
    }
    else printf("Artist not found\n");
    printf("********************************************\n");

    printf("Testing songcmp (helper function):\n");
    struct song_node* sn3= new_song("Java", "Hello World");
    struct song_node* sn4= new_song("Python", "Hello World");
    printf("Comparing [Hello World: Python] to [Hello World: Java]\n%d\n", songcmp(sn3,sn4));
    printf("********************************************\n");

    printf("Testing rand_song:\n");
    struct song_node* sn5= rand_song(sl);
    print_song(sn5);
    printf("********************************************\n");

    printf("Testing remove:\nRemoving [Artist: Hello World Name: C]\n");
    struct song_node* sn6= remove_song(sl, "C", "Hello World");
    printf("List after removing:\n");
    print_list(sl);
    printf("********************************************\n");

    printf("Testing free_song_list:\n");
    free_song_list(sl);
    printf("List after free_song_list:\n");
    print_list(sl);
    printf("********************************************\n");

    return 0;
}
