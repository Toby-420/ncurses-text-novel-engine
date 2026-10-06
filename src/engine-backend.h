/*
    Load in the master story file. Returns true
    if found and false if not.
*/
bool loadMasterStory();

/*
    Load the game data in the first line of master story file.
    Returns true if found and false if not.
*/
bool loadGameData();

/*
    Load the line of a provided file
    Returns 1 if it worked, 0 if it didn't, and 2 if game ends
*/
int loadLine(void);

/*
    Shows a different screen with information.
    Options are in constants.h under the enum SCREENS
*/
bool showScreen(int screenToShow);
