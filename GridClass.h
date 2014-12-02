/*
*   GridClass.h
*/

#define DEF_VAL_GRID  4 
#define BLANK_SPACE   1
#define BLOCK_WIDTH   5
#define BOARD_WIDTH  25
#define SINGLE_DIGIT  2
#define DOUBLE_DIGIT  1
#define TRIPLE_DIGIT  1
#define QUAD_DIGIT    0
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

class Grid {
private:
    vector < vector < Block > > fullGrid;
    int filledSquares;
    int score;
    void SpawnNewTile();
    void ResetGameState();
    void MergeTiles(int *a);
    int TestChange(int *prev1, int *prev2, int *prev3, int *prev4, int *merge1,
        int *merge2, int *merge3, int *merge4);
    void PrintBlankLines();
    string GetNumberColor(int number);
    int CheckGame();
public:
    int UpdateGrid(string dir);
    void PrintGrid();
    int GetScore();
    Grid();
} ;