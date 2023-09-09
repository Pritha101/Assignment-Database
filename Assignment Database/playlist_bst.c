#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"  // include the header file

// Function to create a new playlist node
PlaylistNode* newPlaylistNode(char* playlist_name) {
    PlaylistNode* new_node = (PlaylistNode*)malloc(sizeof(PlaylistNode));
    strcpy_s(new_node->playlist, playlist_name);
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->songs = NULL; // Initialize with an empty list
    return new_node;
}

// Function to add a song to a playlist (linked list part)
void addSongToPlaylist(PlaylistNode* playlist, char* song_name) {
    if (playlist == NULL) {
        printf_s("Playlist does not exist.\n");
        return;
    }

    SongNode* new_song = (SongNode*)malloc(sizeof(SongNode));
    if (new_song == NULL) {
        printf_s("Memory allocation failed.\n");
        return;
    }
    strcpy_s(new_song->song_name, song_name, 99);
    new_song->song_name[99] = '\0'; 
    new_song->next = NULL;

    // If this is the first song in the playlist
    if (playlist->songs == NULL) {
        playlist->songs = new_song;
    }
    else {
        // Otherwise, append it to the end of the list
        SongNode* current = playlist->songs;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_song;
    }
}

// Function to add a playlist to the BST
PlaylistNode* addPlaylistToBST(PlaylistNode* root, char* playlist_name) {
    if (root == NULL) {
        return newPlaylistNode(playlist_name);
    }

    if (strcmp(playlist_name, root->playlist) < 0) {
        root->left = addPlaylistToBST(root->left, playlist_name);
    }
    else if (strcmp(playlist_name, root->playlist) > 0) {
        root->right = addPlaylistToBST(root->right, playlist_name);
    }
    // Equal strings are not added again

    return root;
}

// Function to find a playlist in the BST
PlaylistNode* findPlaylistInBST(PlaylistNode* root, char* playlist_name) {
    if (root == NULL) {
        return NULL;
    }

    if (strcmp(playlist_name, root->playlist) == 0) {
        return root;
    }
    else if (strcmp(playlist_name, root->playlist) < 0) {
        return findPlaylistInBST(root->left, playlist_name);
    }
    else {
        return findPlaylistInBST(root->right, playlist_name);
    }
}

// Function to remove a song from a playlist (linked list part)
void removeSongFromPlaylist(PlaylistNode* playlist, char* song_name) {
    if (playlist == NULL) {
        printf_s("Playlist does not exist.\n");
        return;
    }

    if (playlist->songs == NULL) {
        printf_s("Playlist is empty.\n");
        return;
    }

    SongNode* current = playlist->songs;
    SongNode* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->song_name, song_name) == 0) {
            // If the song to be deleted is the first song in the list
            if (prev == NULL) {
                playlist->songs = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            printf_s("Song removed from playlist.\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf_s("Song not found in playlist.\n");
}




