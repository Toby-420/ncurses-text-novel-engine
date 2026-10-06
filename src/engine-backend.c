#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <curses.h>

#include "constants.h"

StoryFile MasterStory;
GameData Game;

bool loadMasterStory(void)
{
    // Open master story and pre-populate struct
    MasterStory.storyFile = fopen(MASTER_STORY_PATH, "r");
    if (MasterStory.storyFile == NULL) return false;

    MasterStory = (StoryFile){
        MasterStory.storyFile,
        NULL,
        0,
        0
    };

    return true;
}

bool loadGameData(void)
{
    if (getline(&MasterStory.lineContents, &MasterStory.lineLength,
        MasterStory.storyFile) == -1) return false;

    // Remove newline from end of read line
    MasterStory.lineContents[strcspn(MasterStory.lineContents, "\n")] = '\0';

    // Split read line into parts using comma as delimiter and populate struct
    char *saveptr;
    Game = (GameData){
        strtok_r(MasterStory.lineContents, ",", &saveptr),
        strtok_r(NULL, ",", &saveptr),
        strtok_r(NULL, ",", &saveptr)
    };

    return true;
}

int loadLine(void)
{
    MasterStory.lineContents[0] = '#';
    while (MasterStory.lineContents[0] == '#')
    {
        if (getline(&MasterStory.lineContents, &MasterStory.lineLength,
            MasterStory.storyFile) == -1) return false;

        MasterStory.lineContents[strcspn(MasterStory.lineContents, "\n")] = '\0';
    }

    return true;
}

bool showScreen(int screenToShow)
{
    switch (screenToShow)
    {
        case HELP_SCREEN:
            clear();
            printw("Help screen will be shown here.\n");
            getch();
            break;
        default:
            break;
    }
    return true;
}
