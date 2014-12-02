/*
*  Block.h
*/

#define DEF_VAL_SIZE 4 // for GUI development
#define DEF_VAL_VAL 0  // default value is 0

class Block {
private:
  int tile_number;
  int size;        // for GUI development
  void SetSize(int s);
public:
  void SetNumber(int i);
  int GetNumber();
  int GetSize();   // for GUI development
  Block(int s = DEF_VAL_SIZE, int i = DEF_VAL_VAL);
} ;