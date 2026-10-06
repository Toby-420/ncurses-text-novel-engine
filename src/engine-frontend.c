#include <stdio.h>
#include <ncurses.h>
#include <time.h>

#include "utils.h"
#include "engine-backend.h"
#include "constants.h"

FILE *logFile;
time_t currentTime;
struct tm tm;

extern StoryFile MasterStory;
extern GameData Game;

int main(int argc, char *argv[])
{

    // logging setup
    logFile = fopen("log", "a");
    currentTime = time(NULL);
    tm = *localtime(&currentTime);
    append_to_log("Startup", true);
    append_to_log("Logging set up.", false);

    // ncurses setup
    initscr();
    noecho();
    raw();
    keypad(stdscr, true);
    curs_set(2);

    // main program

    // load master story file and read info
    printw("Loading story...");
    if (!loadMasterStory())
    {
        append_to_log("Master story file not found.", false);
        goto SHUTDOWN_SEQUENCE;
    } else
    {
        append_to_log("Master story loaded.", false);
    }

    if (!loadGameData())
    {
        append_to_log("Could not read game data from master story file.",
                      false);
        goto SHUTDOWN_SEQUENCE;
    } else
    {
        append_to_log("Loaded game data.", false);
    }

    clear();
    printw("%s by %s. Version %s.\n", Game.title, Game.author, Game.version);
    printw("Press any key to start.\n");
    getch();
    clear();

    // TODO: read in lines incrementally and use that to check whether to
    // write dialogue as a character, ignored as a comment, branch to other
    // place, or some other logic.

    int ch = 0;
    while (true)
    {
        switch (ch)
        {
            case KEY_F(1):
                showScreen(HELP_SCREEN);
            case KEY_F(10):
                printw("Hit enter to exit game...\n");
                break;
            default:
                loadLine();
                if (MasterStory.lineContents[0] == '!')
                {
                    printw("Game End.\nHit enter to close.\n");
                    getch();
                    goto SHUTDOWN_SEQUENCE;
                }
                printw("%s\n", MasterStory.lineContents);
                ch = getch();

        }

    }


    // tear down ncurses
    SHUTDOWN_SEQUENCE:
        endwin();
        echo();
        curs_set(1);
        append_to_log("Shutdown", true);
        fclose(logFile);
        fclose(MasterStory.storyFile);

    return 0;
}
