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
    struct song_node* sn5 = rand_song(sl);
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

    printf("\nMUSIC LIBRARY TESTS\n\n");
    struct song_library *library;
    library = new_lib();

    library = lib_place_song(library, "Money Trees", "Kendrick Lamar");
    library = lib_place_song(library, "Heard 'em Say" , "Kanye West");
    library = lib_place_song(library, "Rich and Sad", "Post Malone");
    library = lib_place_song(library, "Heart Mind", "Kodak Black");
    library = lib_place_song(library, "Stay", "Post Malone");
    library = lib_place_song(library, "Star67", "Drake");
    

    printf("********************************************\n");

    printf("\nTesting print_letter\n");
    printf("p list:\n");
    lib_list_print(library, 'P');
    printf("\nk list:\n");
    lib_list_print(library, 'K');
    printf("********************************************\n");

    printf("\nTesting find_artist\n");
    struct song_node *node;
    node = lib_find_artist(library, "Drake");
    printf("looking for [Drake]\n");
    if (node)
    {
      printf("Artist found! [Drake]\n");
    }
    else
    {
      printf("Artist not found.\n");
    }

    node = lib_find_artist(library, "Jeff Jones");
    printf("looking for [Jeff Jones]\n");
    if (node)
    {
      printf("Artist found! [Jeff Jones]\n");
    }
    else
    {
      printf("Artist not found.\n");
    }

    printf("********************************************\n");
    printf("\nTesting find_song\n");
    node = lib_find_song(library, "Star67", "Drake");
    printf("looking for [Drake: Star67]\n");
    if (node)
    {
      printf("Song found! [Drake: Star67]\n");
    }
    else
    {
      printf("Song not found.\n");
    }

    node = lib_find_song(library, "Duckworth", "Kendrick Lamar");
    printf("looking for [Kendrick Lamar: Duckworth]\n");
    if (node)
    {
      printf("Song found! [Kendrick Lamar: Duckworth]\n");
    }
    else
    {
      printf("Song not found.\n");
    }

    printf("********************************************\n");
    printf("\nTesting shuffle\n");
    shuffle(library);

    printf("********************************************\n");
    printf("\nTesting print_library\n");
    lib_print_lib(library);
    printf("********************************************\n");
    printf("\nTesting remove song:\n\n");
    printf("Pre remove:\n");
    lib_list_print(library, 'D');
    library = delete_song(library, "Star67", "Drake");
    printf("Post remove:\n");
    lib_list_print(library, 'D');
    printf("********************************************\n");
    printf("\nTesting clear list:\n\n");
    printf("Library before clear:\n");
    lib_print_lib(library);
    printf("--------- CLEARING ---------\n");
    library = clear_lib(library);
    printf("\nLibrary after clear:\n");
    lib_print_lib(library);

    return 0;
}
