#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "constants.h"

StoryFile MasterStory;
GameData Game;

bool loadMasterStory()
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

bool loadGameData()
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
