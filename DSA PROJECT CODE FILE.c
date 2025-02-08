#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
// Define a structure for a music node 
typedef struct MusicNode { 
    char title[100]; 
    struct MusicNode* next; 
    struct MusicNode* prev; 
} MusicNode; 
 
// Create a global pointer for the current song in the playlist 
MusicNode* currentSong = NULL; 
 
// Function to add a new song to the playlist 
void addSong(MusicNode** playlist, char title[]) { 
    MusicNode* newSong = (MusicNode*)malloc(sizeof(MusicNode)); 
    strncpy(newSong->title, title, 100); 
    newSong->next = NULL; 
    newSong->prev = NULL; 
 
    if (*playlist == NULL) { 
        *playlist = newSong; 
        currentSong = *playlist; 
    } else { 
        MusicNode* current = *playlist; 
        while (current->next != NULL) { 
            current = current->next; 
        } 
        current->next = newSong; 
        newSong->prev = current; 
    } 
} 
 
// Function to display the current song 
void displayCurrentSong() { 
    if (currentSong != NULL) { 
        printf("Current Song: %s\n", currentSong->title); 
    } else { 
        printf("Playlist is empty.\n"); 
    } 
} 
 
// Function to play the next song 
void playNextSong() { 
    if (currentSong != NULL && currentSong->next != NULL) { 
        currentSong = currentSong->next; 
        printf("Playing Next Song: %s\n", currentSong->title); 
    } else { 
        printf("No next song in the playlist.\n"); 
    } 
} 
 
// Function to play the previous song 
void playPreviousSong() { 
    if (currentSong != NULL && currentSong->prev != NULL) { 
        currentSong = currentSong->prev; 
        printf("Playing Previous Song: %s\n", currentSong->title); 
    } else { 
        printf("No previous song in the playlist.\n"); 
    } 
} 
 
// Function to free the memory of the playlist 
void freePlaylist(MusicNode** playlist) { 
    MusicNode* current = *playlist; 
    while (current != NULL) { 
        MusicNode* temp = current; 
        current = current->next; 
        free(temp); 
    } 
    *playlist = NULL; 
} 
 
int main() { 
    MusicNode* playlist = NULL; 
 
    int choice; 
    char title[100]; 
 
    while (1) { 
        printf("\n1. Add a song to the playlist\n"); 
        printf("2. Play current song\n"); 
        printf("3. Play next song\n"); 
        printf("4. Play previous song\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter the song title: "); 
                scanf("%s", title); 
                addSong(&playlist, title); 
                break; 
            case 2: 
                displayCurrentSong(); 
                break; 
            case 3: 
                playNextSong(); 
                break; 
            case 4: 
                playPreviousSong(); 
                break; 
            case 5: 
                freePlaylist(&playlist); 
                exit(0); 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
    return 0; 
} 