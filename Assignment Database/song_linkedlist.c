#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_linkedlist.h"

// Function to create a new song node
SongNode* createSongNode(char* song_name) {
    SongNode* newNode = (SongNode*)malloc(sizeof(SongNode));
    newNode->song_name = _strdup(song_name);
    newNode->next = NULL;
    return newNode;
}

// Function to add a song to the linked list
SongNode* addSong(SongNode* head, char* song_name) {
    SongNode* newNode = createSongNode(song_name);

    if (head == NULL) {
        return newNode;
    }

    SongNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

// Function to remove a song from the linked list
SongNode* removeSong(SongNode* head, char* song_name) {
    SongNode* temp = head, * prev;

    if (temp != NULL && strcmp(temp->song_name, song_name) == 0) {
        head = temp->next;
        free(temp->song_name);
        free(temp);
        return head;
    }

    while (temp != NULL && strcmp(temp->song_name, song_name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return head;

    prev->next = temp->next;
    free(temp->song_name);
    free(temp);

    return head;
}

// Function to print all songs in the linked list
void printSongs(SongNode* head) {
    SongNode* temp = head;
    while (temp != NULL) {
        printf_s("    Song: %s\n", temp->song_name);
        temp = temp->next;
    }
}

