#include <iostream>
#include <fstream>
#include <time.h>
#include <windows.h>
using namespace std;
int x_axis = 32;
int y_axis = 10;
char maze[24][71] = {{"#####################################################################"},
                     {"||.. .....................................................  ......  ||"},
                     {"||.. %%%%%%%%%%%%%%%%        ...     %%%%%%%%%%%%%%  |%|..   %%%%   ||"},
                     {"||..        |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||"},
                     {"||..        |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||"},
                     {"||..        %%%%%%%%  . . |%|...     %%%%%%%%%%%%%%     ..   %%%%.  ||"},
                     {"||..        |%|       . . |%|...    ............... |%| ..       .  ||"},
                     {"||..        %%%%%%%%%%. . |%|...    %%%%%%%%%%%%    |%| ..   %%%%.  ||"},
                     {"||..               |%|.             |%|......       |%| ..    |%|.  ||"},
                     {"||..     ......... |%|.        P    |%|......|%|        ..    |%|.  ||"},
                     {"||..|%|  |%|%%%|%|.|%|. |%|            ......|%|        ..|%| |%|.  ||"},
                     {"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|         .|%|.      ||"},
                     {"||..|%|  |%|   |%|..           ...|%|     %%%%%%        . |%|.      ||"},
                     {"||..|%|            .           ...|%|               |%| ..|%|.      ||"},
                     {"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
                     {"||...............................................   |%| ..........  ||"},
                     {"||   ............................................          .......  ||"},
                     {"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|    |%| ..|%|.      ||"},
                     {"||..|%|  |%|   |%|..           ...|%|     %%%%%%    |%| ..|%|.      ||"},
                     {"||..|%|            .     G     ...|%|               |%| ..|%|.      ||"},
                     {"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
                     {"||...............................................   |%| ..........  ||"},
                     {"||  .............................................          .......  ||"},
                     {"#####################################################################"}};
void printmaze()
{
    for (int row = 0; row < 24; row++)
    {
        for (int col = 0; col < 71; col++)
        {
            cout << maze[row][col];
        }
        cout << "\n";
    }
}
//  ______________global variables_______________
int pacmanx = 9;
int pacmany = 31;
int score = 0;
int ghostx = 19;
int ghosty = 25;
char previousitem = ' ';
void gotoxy(int x_axis, int y_axis)
{
    COORD coordinates;
    // coordinates is declared as COORD
    coordinates.X = y_axis;
    // defining x-axis
    coordinates.Y = x_axis;
    // defining  y-axis
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
};
void movePacmanLeft()
{
    if (maze[pacmanx][pacmany - 1] != '|' && maze[pacmanx][pacmany - 1] != '%')
    {
        maze[pacmanx][pacmany] = ' ';
        if (maze[pacmanx][pacmany - 1] == '.')
        {
            gotoxy(100, 100);

            score = score + 1;
            cout << score;
            gotoxy(pacmany, pacmanx)(cout << " ";)
        }
        pacmany = pacmany - 1;
        gotoxy(pacmany, pacmanx);
        cout << "p";
        maze[pacmanx][pacmany - 1] = 'p';
    }
}
void movePacmanRight()
{
    if (maze[pacmanx][pacmany + 1] != '|' && maze[pacmanx][pacmany + 1] != '%')
    {
        maze[pacmanx][pacmany] = ' ';
        if (maze[pacmanx][pacmany + 1] == '.')
        {
            score = score + 1;
        }
        maze[pacmanx][pacmany + 1] = 'p';
        pacmany = pacmany + 1;
    }
}
void movePacmanUp()
{
    if (maze[pacmanx - 1][pacmany] != '%' && maze[pacmanx - 1][pacmany] != '#')
    {
        maze[pacmanx][pacmany] = ' ';
        if (maze[pacmanx - 1][pacmany] == '.')
        {
            score = score + 1;
        }
        maze[pacmanx - 1][pacmany] = 'p';

        pacmanx = pacmanx - 1;
    }
}
void movePacmanDown()
{
    if (maze[pacmanx + 1][pacmany] != '%' && maze[pacmanx + 1][pacmany] != '#')
    {
        maze[pacmanx][pacmany] = ' ';
        if (maze[pacmanx + 1][pacmany] == '.')
        {
            score = score + 1;
        }
        maze[pacmanx + 1][pacmany] = 'p';
        pacmanx = pacmanx + 1;
    }
}
void printscore()
{

    cout << "score    " << score << endl;
}
int ghostdirection()
{
    srand(time(0));
    int result = 0;
    result = 1 + (rand() % 4);
    return result;
}
bool ghostmovement()
{
    int value = 0;
    value = ghostdirection();
    if (value == 1)
    {
        if (maze[ghostx][ghosty - 1] == ' ' || maze[ghostx][ghosty - 1] == '.' || maze[ghostx][ghosty - 1] == 'p')
        {
            maze[ghostx][ghosty] = previousitem;
            ghosty = ghosty - 1;
            previousitem = maze[ghostx][ghosty];
            if (previousitem == 'p')
            {
                return 0;
            }
            maze[ghostx][ghosty] = 'G';
        }
    }
    if (value == 2)
    {
        if (maze[ghostx][ghosty + 1] == ' ' || maze[ghostx][ghosty + 1] == '.' || maze[ghostx][ghosty + 1] == 'p')
        {
            maze[ghostx][ghosty] = previousitem;
            ghosty = ghosty + 1;
            previousitem = maze[ghostx][ghosty];
            if (previousitem == 'p')
            {
                return 0;
            }
            maze[ghostx][ghosty] = 'G';
        }
    }
    if (value == 3)
    {
        if (maze[ghostx - 1][ghosty] == ' ' || maze[ghostx - 1][ghosty] == '.' || maze[ghostx - 1][ghosty] == 'p')
        {
            maze[ghostx][ghosty] = previousitem;
            ghostx = ghostx - 1;
            previousitem = maze[ghostx][ghosty];
            if (previousitem == 'p')
            {
                return 0;
            }
            maze[ghostx][ghosty] = 'G';
        }
    }
    if (value == 4)
    {
        if (maze[ghostx + 1][ghosty] == ' ' || maze[ghostx + 1][ghosty] == '.' || maze[ghostx + 1][ghosty] == 'p')
        {
            maze[ghostx][ghosty] = previousitem;
            ghostx = ghostx - 1;
            previousitem = maze[ghostx][ghosty];
            if (previousitem == 'p')
            {
                return 0;
            }
            maze[ghostx][ghosty] = 'G';
        }
    }
    // return 0;
}

main()
{

    system("cls");
    printmaze();

    // gotoxy(x_axis, y_axis);

    bool runninggame(true);
    while (runninggame)
    {
        Sleep(100);

        runninggame = ghostmovement();

        if (GetAsyncKeyState(VK_LEFT))
        {
            movePacmanLeft(); // Function call to move Pacman towards left
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movePacmanRight(); // Function call to move Pacman towards right
        }

        if (GetAsyncKeyState(VK_UP))
        {
            movePacmanUp(); // Function call to move Pacman towards up
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movePacmanDown(); // Function call to move Pacman towards down
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {

            runninggame = false;
            // Stop the game
        }
        // system("cls");
    }
    // fstream pac_man_file;
    // pac_man_file.open("pac_man_file.txt", ios::out);
    // //   pac_man_file>> printmaze();
    // for (int row = 0; row < 24; row++)
    // {
    //     for (int col = 0; col < 71; col++)
    //     {
    //         if (col == 0)
    //         {
    //             cout << "{";
    //             pac_man_file << "{";
    //         }
    //         cout << maze[row][col];
    //         pac_man_file << maze[row][col];
    //         if (col == 70)
    //         {
    //             cout << "}";
    //             pac_man_file << "}";
    //         }
    //     }
    //     cout << endl;
    // }
    // pac_man_file << score;
    // pac_man_file.close();
}