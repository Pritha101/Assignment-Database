#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist_bst.h"
#include "song_linkedlist.h"

// Create a new PlaylistNode
PlaylistNode* createPlaylistNode(char* playlist_name) {
    PlaylistNode* newNode = (PlaylistNode*)malloc(sizeof(PlaylistNode));
    newNode->playlist_name = _strdup(playlist_name);
    newNode->songs = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new playlist into the BST
void insertPlaylist(PlaylistNode** root, char* playlist_name) {
    if (*root == NULL) {
        *root = createPlaylistNode(playlist_name);
        return;
    }

    int cmp = strcmp(playlist_name, (*root)->playlist_name);
    if (cmp < 0) {
        insertPlaylist(&((*root)->left), playlist_name);
    }
    else if (cmp > 0) {
        insertPlaylist(&((*root)->right), playlist_name);
    }
    else {
        // Playlist already exists, do nothing
    }
}

// Search for a playlist in the BST
PlaylistNode* searchPlaylist(PlaylistNode* root, char* playlist_name) {
    if (root == NULL) return NULL;

    int cmp = strcmp(playlist_name, root->playlist_name);
    if (cmp < 0) {
        return searchPlaylist(root->left, playlist_name);
    }
    else if (cmp > 0) {
        return searchPlaylist(root->right, playlist_name);
    }
    else {
        return root;
    }
}

// Function to add a song to a playlist
void addSongToPlaylist(PlaylistNode* playlist, char* song_name) {
    insertSong(&(playlist->songs), song_name);
}

// Function to remove a song from a playlist
void removeSongFromPlaylist(PlaylistNode* playlist, char* song_name) {
    deleteSong(&(playlist->songs), song_name);
}

// Helper function to free BST nodes
void freeBST(PlaylistNode* root) {
    if (root == NULL) return;
    freeBST(root->left);
    freeBST(root->right);
    freeSongList(root->songs);
    free(root->playlist_name);
    free(root);
}

// Function to print songs in a playlist
void printSongsInPlaylist(PlaylistNode* playlist) {
    printSongs(playlist->songs);
}

float findMostSimilarPlaylist(PlaylistNode* root, char* target_playlist, char* most_similar_playlist) {
    if (root == NULL) {
        return 0.0f;
    }

    float max_similarity_score = -1.0f;

    // Function to recursively traverse the BST and calculate similarity for each playlist
    // This would be another custom function you define
    calculateSimilarity(root, target_playlist, &max_similarity_score, most_similar_playlist);

    return max_similarity_score;
}




