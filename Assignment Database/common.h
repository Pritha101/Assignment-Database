#pragma once

#ifndef COMMON_H
#define COMMON_H
#define TABLE_SIZE 100


typedef struct SongNode {
    char song[100];
    char song_name[100];
    struct SongNode* next;
} SongNode;

typedef struct PlaylistNode {
    char playlist[100];
    SongNode* songs;
    struct PlaylistNode* left;
    struct PlaylistNode* right;
} PlaylistNode;



typedef struct HashNode {
    char playlist[100];
    SongNode* songs;
    struct HashNode* next;
} HashNode;

HashNode* hashTable[TABLE_SIZE];

// Function prototypes
PlaylistNode* newPlaylistNode(char* playlist_name);

void addSongToPlaylist(PlaylistNode* playlist, char* song_name);

PlaylistNode* addPlaylistToBST(PlaylistNode* root, char* playlist_name);

PlaylistNode* findPlaylistInBST(PlaylistNode* root, char* playlist_name);

void removeSongFromPlaylist(PlaylistNode* playlist, char* song_name);

// Function prototypes for song_linkedlist.c
SongNode* newSongNode(char* song_name);

void addSongToPlaylist(SongNode** song_list, char* song_name);

void removeSongFromPlaylist(SongNode** song_list, char* song_name);

void printSongsInPlaylist(SongNode* song_list);

//Function for playlilst_hash.c
unsigned int hash(char* str);

void addPlaylistToHash(char* playlist_name);

HashNode* findPlaylistInHash(char* playlist_name);

void addSongToPlaylistHash(HashNode* playlist, char* song_name);

void removeSongFromPlaylistHash(HashNode* playlist, char* song_name);

#endif

