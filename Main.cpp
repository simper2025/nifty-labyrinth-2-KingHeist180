#include "MazeGenerator.h"
#include "Labyrinth.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

/* Change this constant to contain your name.
 *
 * WARNING: Once you've set set this constant and started exploring your maze,
 * do NOT edit the value of kYourName. Changing kYourName will change which
 * maze you get back, which might invalidate all your hard work!
 */

string MazeSolver(MazeCell*, string, set<string>, bool, bool, bool);

const std::string kYourName = "Kade Jorgensen";

/* Change these constants to contain the paths out of your mazes. */
const std::string kPathOutOfNormalMaze = "WWWSSSEWNEESENN";
const std::string kPathOutOfTwistyMaze = "SWWNENNWNNSS";

const std::string solverNormal = "";
const std::string solverTwisty = "";

set<string> edges;

int main() {
    /* Generate the maze.
     *
     * Note: Don't set a breakpoint on this line. Otherwise, you'll see startLocation before
     * it's been initialized.
     */
    MazeCell* startLocation = mazeFor(kYourName);
    
    string solverN = MazeSolver(startLocation, solverNormal, edges);

    /* Set a breakpoint here to explore your maze! */
    if (isPathToFreedom(startLocation, kPathOutOfNormalMaze)) {
        std::cout << "Congratulations! You've found a way out of your labyrinth." << std::endl;
    } else {
        std::cout << "Sorry, but you're still stuck in your labyrinth." << std::endl;
    }
    
    if (isPathToFreedom(startLocation, solverN)) {
        std::cout << "Congratulations! I've found a way out of your labyrinth." << std::endl;
    }
    else {
        std::cout << "Sorry, but I'm still stuck in your labyrinth." << std::endl;
    }
    
    /* Generate the twisty maze.
     *
     * Note: Don't set a breakpoint on this line. Otherwise, you'll see twistyStartLocation before
     * it's been initialized.
     */
    MazeCell* twistyStartLocation = twistyMazeFor(kYourName);

    string solverT = MazeSolver(startLocation, solverTwisty, edges);
    
    /* Set a breakpoint here to explore your twisty maze! */
    if (isPathToFreedom(twistyStartLocation, kPathOutOfTwistyMaze)) {
        std::cout << "Congratulations! You've found a way out of your twisty labyrinth." << std::endl;
    } else {
        std::cout << "Sorry, but you're still stuck in your twisty labyrinth." << std::endl;
    }

    if (isPathToFreedom(startLocation, solverT)) {
        std::cout << "Congratulations! I've found a way out of your labyrinth." << std::endl;
    }
    else {
        std::cout << "Sorry, but I'm still stuck in your labyrinth." << std::endl;
    }
}

string MazeSolver(MazeCell* current, string path, set<string> edges, bool pot = false, bool book = false , bool wand = false)
{
    if (current->whatsHere == Item::SPELLBOOK)
        book = true;
    if (current->whatsHere == Item::POTION)
        pot = true;
    if (current->whatsHere == Item::WAND)
        wand = true;
    
    if (wand && book && pot)
        return path;

    string crnt = to_string((int)current);

    //edges.push_back(crnt);

    if (current->north != nullptr)
        return MazeSolver(current->north, path + "N", edges, pot, book, wand);
    if (current->east != nullptr)
        return MazeSolver(current->north, path + "E", edges, pot, book, wand);
    if (current->west != nullptr)
        return MazeSolver(current->north, path + "W", edges, pot, book, wand);
    if (current->south != nullptr)
        return MazeSolver(current->north, path + "S", edges, pot, book, wand);
}
