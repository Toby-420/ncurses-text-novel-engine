#include <stdint.h>

/*
    This file contains constants such as file paths and values for parsing.

    Items requiring configuration for making a game are within the following
    section.
*/


// No user-configurable options at this time

/*
    Data past this point doesn't need user configuration. Only edit
    if developing the engine.

        Here be dragons...

                        __        _
                      _/  \    _(\(o
                     /     \  /  _  ^^^o
                    /   !   \/  ! '!!!v'
                   !  !  \ _' ( \____
                   ! . \ _!\   \===^\)
        Art by      \ \_!  / __!
         Gunnar Z.   \!   /    \
               (\_      _/   _\ )
                \ ^^--^^ __-^ /(__
                 ^^----^^    "^--v'
*/

#define MASTER_STORY_PATH "story/master.sty"
#define HELP_FILE_PATH "data/help"

enum SCREENS {
    HELP_SCREEN = 0,
};

typedef struct
{
    FILE *storyFile;
    char *lineContents;
    size_t lineLength;
    size_t lineNumber;
} StoryFile;

typedef struct
{
    char *title;
    char *author;
    char *version;
} GameData;
