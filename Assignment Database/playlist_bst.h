#ifndef PLAYLIST_BST_H
#define PLAYLIST_BST_H

#include "song_linkedlist.h" // Including the song_linkedlist header for SongNode

// Struct definition for a node in the binary search tree of playlists
typedef struct PlaylistNode {
    char* playlist_name;
    SongNode* songs; // Linked list of songs
    struct PlaylistNode* next;
    struct PlaylistNode* left;
    struct PlaylistNode* right;
}PlaylistNode;

// Function to create a new node for a playlist
PlaylistNode* createPlaylistNode(char* playlist_name);

// Function to insert a playlist into the BST
PlaylistNode *insertPlaylist(PlaylistNode* root, char* playlist_name);

// Function to delete a playlist from the BST
PlaylistNode* deletePlaylist(PlaylistNode* root, char* playlist_name);

// Function to find a playlist in the BST by name
PlaylistNode* findPlaylist(PlaylistNode* root, char* playlist_name);

// Function to print the playlists in-order (alphabetically)
void printPlaylistsInOrder(PlaylistNode* root);

// Function to add a song to a given playlist
void addSongToPlaylist(PlaylistNode* playlist, char* song_name);

// Function to remove a song from a given playlist
void removeSongFromPlaylist(PlaylistNode* playlist, char* song_name);

// Function to print all songs in a playlist in alphabetical order
void printSongsInPlaylist(PlaylistNode* playlist);

// Function to find the most similar playlist
float findMostSimilarPlaylist(PlaylistNode* root, char* target_playlist, char* most_similar_playlist);

void calculateSimilarity(PlaylistNode* node, char* target_playlist, float* max_similarity_score, char* most_similar_playlist);

#endif // PLAYLIST_BST_H

