#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"


extern HashNode* hashTable[];  // To get access to the hash table from playlist_hash.c


int main() {
    int option;
    char playlist_name[100], song_name[100];
    HashNode* foundPlaylist;

    memset(hashTable, 0, sizeof(HashNode*) * TABLE_SIZE);  // Initialize the hash table to NULLs

    while (1) {
        printf_s("Choose an operation:\n");
        printf_s("1. Add a song to a playlist\n");
        printf_s("2. Remove a song from a playlist\n");
        printf_s("3. Print the songs in a playlist\n");
        printf_s("4. Print the number of playlists a song appears in\n");
        printf_s("5. Find the most similar playlist\n");
        printf_s("0. Exit\n");

        scanf_s("%d", &option);

        switch (option) {
        case 1:
            printf_s("Enter playlist name: ");
            scanf_s("%s", playlist_name);
            printf_s("Enter song name: ");
            scanf_s("%s", song_name);

            foundPlaylist = findPlaylistInHash(playlist_name);
            if (foundPlaylist == NULL) {
                addPlaylistToHash(playlist_name);
                foundPlaylist = findPlaylistInHash(playlist_name);
            }
            addSongToPlaylist(&(foundPlaylist->songs), song_name);
            break;

        case 2:
            printf_s("Enter playlist name: ");
            scanf_s( "%s", playlist_name);
            printf_s("Enter song name: ");
            scanf_s( "%s", song_name);

            foundPlaylist = findPlaylistInHash(playlist_name);
            if (foundPlaylist != NULL) {
                removeSongFromPlaylist(&(foundPlaylist->songs), song_name);
            }
            break;

        case 3:
            printf_s("Enter playlist name: ");
            scanf_s( "%s", playlist_name);

            foundPlaylist = findPlaylistInHash(playlist_name);
            if (foundPlaylist != NULL) {
                printSongsInPlaylist(foundPlaylist->songs);
            }
            break;


        case 0:
            printf_s("Exiting the program.\n");
            return 0;

        default:
            printf_s("Invalid option. Try again.\n");
        }
    }

    return 0;
}
