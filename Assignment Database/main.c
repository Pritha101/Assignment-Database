#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist_bst.h"
#include "playlist_hash.h"
#include "song_linkedlist.h"

int main() {
    PlaylistNode* playlist_bst_root = NULL;
    char operation, tmp;
    char playlist_name[100];
    char song_name[100];

    while (1) {
        printf_s("Enter the operation number (1-5) or '0' to quit: ");
        scanf_s("%d", &operation);
        scanf_s("%c", &tmp); // Consume trailing newline

        if (operation == 0) {
            break;
        }

        switch (operation) {
        case 1:
            printf_s("Enter playlist name: ");
            fgets(playlist_name, sizeof(playlist_name), stdin);
            strtok_s(playlist_name, "\n");

            printf_s("Enter song name: ");
            fgets(song_name, sizeof(song_name), stdin);
            strtok_s(song_name, "\n");

            // Assuming the playlist exists, otherwise create new and add
            insertPlaylist(&playlist_bst_root, playlist_name);
            PlaylistNode* playlist = searchPlaylist(playlist_bst_root, playlist_name);
            addSongToPlaylist(playlist, song_name);

            break;

        case 2:
            printf_s("Enter playlist name to remove song from: ");
            fgets(playlist_name, sizeof(playlist_name), stdin);
            strtok_s(playlist_name, "\n");

            printf_s("Enter song name to remove: ");
            fgets(song_name, sizeof(song_name), stdin);
            strtok_s(song_name, "\n");

            // Search for the playlist in the BST
            PlaylistNode* playlists = searchPlaylist(playlist_bst_root, playlist_name);
            if (playlists) {
                // Function in song_linkedlist.c to remove a song from a playlist's song linked list
                removeSongFromPlaylist(playlists, song_name);
            }
            else {
                printf_s("Playlist not found.\n");
            }
            break;

        case 3:
            printf_s("Enter playlist name for displaying songs: ");
            fgets(playlist_name, sizeof(playlist_name), stdin);
            strtok_s(playlist_name, "\n");

            playlist = searchPlaylist(playlist_bst_root, playlist_name);
            printSongsInPlaylist(playlist);
            break;

        case 4:
            printf_s("Enter song name to find the number of playlists it appears in: ");
            fgets(song_name, sizeof(song_name), stdin);
            strtok_s(song_name, "\n");
            int num_playlists = countPlaylistsForSong(playlist_bst_root, song_name);

            if (num_playlists > 0) {
                printf_s("The song %s appears in %d playlist(s).\n", song_name, num_playlists);
            }
            else {
                printf_s("The song %s does not appear in any playlists.\n", song_name);
            }
            break;

        case 5:
            printf_s("Enter playlist name to find the most similar playlist: ");
            fgets(playlist_name, sizeof(playlist_name), stdin);
            strtok_s(playlist_name, "\n");

            char most_similar_playlist[100];
            float similarity_score = findMostSimilarPlaylist(playlist_bst_root, playlist_name, most_similar_playlist);

            if (similarity_score > 0) {
                printf_s("The most similar playlist to %s is %s with a similarity score of %.2f.\n", playlist_name, most_similar_playlist, similarity_score);
            }
            else {
                printf_s("No similar playlists found for %s.\n", playlist_name);
            }
            
            break;

        default:
            printf_s("Invalid option!\n");
            break;
        }
    }

    freeBST(playlist_bst_root);

    return 0;
}

