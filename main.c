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
    print_list(sl);

    place_song(sl, "C", "Hello World");
    place_song(sl, "public static void", "FooBar");

    print_list(sl);
    return 0;
}
