#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include <time.h>

//creates a new song node
struct song_node* new_song(char name[], char artist[]){
    struct song_node* sn = malloc(sizeof(struct song_node));
    strncpy(sn->name, name, sizeof(sn->name));
    strncpy(sn->artist, artist, sizeof(sn->artist));
    sn->next = NULL;
    return sn;
}

//creates a new song list
struct song_list* new_list(){
    struct song_list* sl = malloc(sizeof(struct song_list));
    sl->head = NULL;
    return sl;
}

//inserts a song node at the front of the list
struct song_node* insert_song(struct song_list* sl, char name[], char artist[]){
    struct song_node* sn = new_song(name, artist);
    sn->next = sl->head;
    sl->head = sn;
    return sn;
}

//inserts a song node in alphabetical order by artist, then song
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

//compares two string nodes by artist name and song name
int songcmp(struct song_node* s1, struct song_node* s2){
    if(s1 == NULL) return 1;
    else if(s2 == NULL) return -1;

    int c = strcmp(s1->artist, s2->artist);
    if(c != 0) return c;
    else return strcmp(s1->name, s2->name);
}

//prints a song node
void print_song(struct song_node* sn){
    printf("Artist: %s\nName: %s\n", sn->artist, sn->name);
}

//prints the entire list of songs
void print_list(struct song_list* sl){
    struct song_node* track = sl->head;
    while(track != NULL){
        print_song(track);
        printf("\n");
        track = track->next;
    }
}

//returns the song node based on given artist and title
struct song_node* find_song(struct song_list* sl, char name[], char artist[]){
  struct song_node* track= sl-> head;
  while (track){
    if (strcmp(name, track->name)==0 && strcmp(artist, track->artist)==0) return track;
    track= track->next;
  }
  return NULL;
}

//returns the first song of the given artist
struct song_node* find_artist_song(struct song_list* sl, char artist[]){
  struct song_node* track= sl-> head;
  while (track){
    if (strcmp(artist, track->artist)==0) return track;
    track= track->next;
  }
  return NULL;
}

//returns a random song node in the list
struct song_node* rand_song(struct song_list* sl){
  struct song_node* track;
  srand(time(NULL));
  random=rand()%song_list_len(sl);
  while (random){
    track=track->next;
    random--;
  }
  return track;
}

//returns the length of the song list
int song_list_len(struct song_list* sl){
  struct song_node*track= sl->head;
  int len=0;
  while (track){
    len++;
    track=track->next;
  }
  return len;
}

//removes a song node from the song list based on given name and artist
struct song_node* remove_song(struct song_list *sl, char name[], char artist[]){
  struct song_node* track= sl->head;
	struct song_node* previous = NULL;

	while (track){

    if (strcmp(name, track->name)==0 && strcmp(artist, track->artist)==0){
      if (previous){
        previous->next=track->next;
        free(track);
        break;
			}
			else{
        sl->head=track->next;
        break;
      }
		}
    previous=track;
    track=track->next;
	}

	return sl->head;
}

//freeing the song nodes
struct song_node* free_song_list(struct song_list* sl){
	struct song_node* track= sl->head;
  struct song_node* next;
	while (track){
		printf("Freeing node:\n");
    print_song(track);
		next=track->next; //keeping track of the next player
		free(track);
		track=next; //going to next player
	}
	return NULL;
}
