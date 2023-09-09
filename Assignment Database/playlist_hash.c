#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"  // include the header file for common structures and function prototypes

#define TABLE_SIZE 100


// Hash function to calculate index
unsigned int hash(char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash % TABLE_SIZE;
}

// Create a new HashNode
HashNode* newHashNode(char* playlist_name) {
    HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
    strcpy_s(new_node->playlist, playlist_name);
    new_node->next = NULL;
    new_node->songs = NULL; // Initialize with an empty list
    return new_node;
}

// Add a playlist to the hash table
void addPlaylistToHash(char* playlist_name) {
    unsigned int index = hash(playlist_name);
    HashNode* new_node = newHashNode(playlist_name);
    new_node->next = hashTable[index];
    hashTable[index] = new_node;
}

// Find a playlist in the hash table
HashNode* findPlaylistInHash(char* playlist_name) {
    unsigned int index = hash(playlist_name);
    HashNode* current = hashTable[index];
    while (current != NULL) {
        if (strcmp(current->playlist, playlist_name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Not found
}

// Add a song to a playlist (linked list part)
void addSongToPlaylistHash(HashNode* playlist, char* song_name) {
    addSongToPlaylist(&(playlist->songs), song_name);  // Reuse the linked list function
}

// Remove a song from a playlist (linked list part)
void removeSongFromPlaylistHash(HashNode* playlist, char* song_name) {
    removeSongFromPlaylist(&(playlist->songs), song_name);  // Reuse the linked list function
}

