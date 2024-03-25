#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) 
{
    //Open and read file
    std::ifstream levelDungeon;
    levelDungeon.open(fileName);

    if(!levelDungeon.is_open())
    {
        //std::cout << "fileOpen error" << std::endl;
        return nullptr;
    }   

    levelDungeon >> maxRow;
    levelDungeon >> maxCol;
    levelDungeon >> player.row;
    levelDungeon >> player.col;

    if(((2147483647 / double(maxRow)) < maxCol)|| 
    ((2147483647 / double(maxCol)) < maxRow) ||
    (maxRow <= 0) || (maxCol <= 0) || 
    (maxRow > 999999) || (maxCol > 999999) || 
    ((maxRow * maxCol) > 2147483647) ||(maxRow == 0) ||
    (player.row < 0) || (player.row > maxRow) || 
    (player.col < 0 ) || (player.col > maxCol)) 
    {
        levelDungeon.close();
        return nullptr;
    }
    //Load Level
    char** levelMap = createMap(maxRow, maxCol);
    for(size_t row = 0; row < maxRow; row++)
    {
        for(size_t col = 0; col < maxCol; col++)
        {
            // Read character from file
            char tile;
            levelDungeon >> tile;
            //std::cout << "Read tile: " << tile << " at row: " << row << ", col: " << col << std::endl;
            // Check if character is valid
            if(!(tile == TILE_OPEN || tile == TILE_PLAYER ||
                 tile == TILE_TREASURE || tile == TILE_AMULET ||
                 tile == TILE_MONSTER || tile == TILE_PILLAR ||
                 tile == TILE_DOOR || tile == TILE_EXIT))
            {
                // Invalid character
                deleteMap(levelMap, maxRow);
                levelDungeon.close();
                return nullptr;
            }       
            // Assign character to level map
            levelMap[row][col] = tile;
        }
    }
    
    // Set player position
    levelMap[player.row][player.col] = TILE_PLAYER;

    //deleteMap(levelMap, maxRow);
    levelDungeon.close();
    return levelMap;
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) 
{
    //Starting player row and column
    //std::cout << nextRow << std::endl;

    switch(input) {
        case MOVE_UP:
            nextRow -= 1;
            break;

        case MOVE_DOWN:
            nextRow += 1;
            break;

        case MOVE_LEFT:
            nextCol -= 1;
            break;

        case MOVE_RIGHT:
            nextCol += 1;
            break;

        case INPUT_QUIT:
            break;

        default:
            break;
    }
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) 
{
    char** levelMap = new char*[maxRow];
    for(size_t i = 0; i < maxRow; ++i)
    {
        levelMap[i] = new char[maxCol];
        for(size_t j = 0; j < maxCol; ++j)
        {
            levelMap[i][j] = TILE_OPEN;
        }
    }
     
    return levelMap;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
    //Deallocate Memory
    if(map != nullptr)
    {
        for(size_t row = 0; row < maxRow; ++row)
        {
            delete[] map[row];
        }
        delete[] map;
        map = nullptr;
        
    }
    maxRow = 0;
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) 
{
    if (map == nullptr || maxRow <= 0 || maxCol <= 0) {
        return nullptr;
    }

    int doubledRow = maxRow * 2;
    int doubledCol = maxCol * 2;

    //init newMap with doubled size
    char** newMap = new char*[doubledRow] {};
    for(int i = 0; i < doubledCol; ++i)
    {
        newMap[i] = new char[doubledCol] {};        
    }
    //populate newMap array
    for(int j = 0; j < maxRow; ++j) //Sub Array A
    {
        for(int k = 0; k < maxCol; ++k)
        {
            newMap[j][k] = map[j][k];       
        }   
    }
    for (int i = 0; i < maxRow; ++i) //B
    {
        for (int j = maxCol; j < doubledCol; ++j) 
        {
            newMap[i][j] = map[i][j - maxCol];

            if(newMap[i][j] == TILE_PLAYER)
            {
                newMap[i][j] = TILE_OPEN;
            } 
        }
    }
    for (int i = maxRow; i < doubledRow; ++i) //C
    {
        for (int j = 0; j < maxCol; ++j) 
        {
            newMap[i][j] = map[i - maxRow][j];

            if(newMap[i][j] == TILE_PLAYER)
            {
                newMap[i][j] = TILE_OPEN;
            }
        }
    }
    for (int i = maxRow; i < doubledRow; ++i) 
    {
        for (int j = maxCol; j < doubledCol; ++j) 
        {
            newMap[i][j] = newMap[i - maxRow][j - maxCol];

            if(newMap[i][j] == TILE_PLAYER)
            {
                newMap[i][j] = TILE_OPEN;
            }
        }
    }
    deleteMap(map, maxRow); //Delete oldMap
    maxRow = doubledRow;
    maxCol = doubledCol;
    map = newMap; //point map to newMap


    return newMap;
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) 
{
    //Check if player is within boundaries
    if (nextRow < 0 || nextRow >= maxRow || nextCol < 0 || nextCol >= maxCol) 
    {       
        return STATUS_STAY;
    } 
    //Check if player hits pillar or monster (row)
    if((map[nextRow][player.col] == TILE_PILLAR) || (map[nextRow][player.col] == TILE_MONSTER))
    {
        return STATUS_STAY;
    }
    //Check if player hits pillar or monster (col)
    if((map[player.row][nextCol] == TILE_PILLAR) || (map[player.row][nextCol] == TILE_MONSTER))
    {
        return STATUS_STAY;
    }
    //If treasure is next
    if((map[nextRow][player.col] == TILE_TREASURE) || (map[player.row][nextCol] == TILE_TREASURE))
    {
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        player.treasure += 1;

        return STATUS_TREASURE;
    }
    //If amulet is next
    if((map[nextRow][player.col] == TILE_AMULET) || (map[player.row][nextCol] == TILE_AMULET))
    {
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;

        return STATUS_AMULET;
    }
    if((map[nextRow][player.col] == TILE_DOOR) || (map[player.row][nextCol] == TILE_DOOR))
    {
        return STATUS_LEAVE;
    }
    if((map[nextRow][player.col] == TILE_EXIT) || (map[player.row][nextCol] == TILE_EXIT))
    {
        return STATUS_ESCAPE;
    }
    
    //Clear to Move
    map[player.row][player.col] = TILE_OPEN;
    player.row = nextRow;
    player.col = nextCol;
    map[player.row][player.col] = TILE_PLAYER;

    return STATUS_MOVE;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    return false;
}
