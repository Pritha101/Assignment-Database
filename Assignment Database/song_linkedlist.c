#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"  // include the header file for common structures and function prototypes



// Function to create a new song node
SongNode* newSongNode(char* song_name) {
    SongNode* new_node = (SongNode*)malloc(sizeof(SongNode));
    strcpy_s (new_node->song, song_name);
    new_node->next = NULL;
    return new_node;
}

// Function to add a song to a playlist (assumes playlist is not NULL)
void addSongToPlaylist(SongNode** song_list, char* song_name) {
    SongNode* new_node = newSongNode(song_name);
    SongNode* current = *song_list;
    SongNode* previous = NULL;

    // Insert in sorted order
    while (current != NULL && strcmp(current->song, song_name) < 0) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) { // Insert at beginning
        new_node->next = *song_list;
        *song_list = new_node;
    }
    else { // Insert at appropriate position
        new_node->next = current;
        previous->next = new_node;
    }
}

// Function to remove a song from a playlist (assumes playlist is not NULL and song exists)
void removeSongFromPlaylist(SongNode** song_list, char* song_name) {
    SongNode* current = *song_list;
    SongNode* previous = NULL;

    // Search for the song
    while (current != NULL && strcmp(current->song, song_name) != 0) {
        previous = current;
        current = current->next;
    }

    // Remove the song
    if (previous == NULL) { // Remove from the beginning
        *song_list = current->next;
    }
    else { // Remove from somewhere else
        previous->next = current->next;
    }
    free(current);
}

// Function to print songs in a playlist in alphabetical order
void printSongsInPlaylist(SongNode* song_list) {
    SongNode* current = song_list;
    while (current != NULL) {
        printf_s("%s\n", current->song);
        current = current->next;
    }
}

