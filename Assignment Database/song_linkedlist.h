#ifndef SONG_LINKEDLIST_H
#define SONG_LINKEDLIST_H

// Struct for a node in the linked list
typedef struct SongNode {
    char* song_name;
    struct SongNode* next;
} SongNode;

// Function to create a new node
SongNode* createSongNode(char* song_name);

// Function to insert a song into a linked list, maintaining alphabetical order
void insertSong(SongNode** head, char* song_name);

// Function to delete a song from a linked list
void deleteSong(SongNode** head, char* song_name);

// Function to search for a song in the linked list
SongNode* searchSong(SongNode* head, char* song_name);

// Function to print all songs in the linked list
void printSongs(SongNode* head);

// Function to free the linked list from memory
void freeSongList(SongNode* head);

#endif // SONG_LINKEDLIST_H
