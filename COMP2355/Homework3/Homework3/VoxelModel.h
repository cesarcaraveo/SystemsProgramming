// function definitions

uint8_t getIndex(int x, int y, int z);
// takes x,y,z coor. (0,1,2,3)
// returns which bit represents that voxel [0,63] range

uint8_t getX(uint8_t index);
uint8_t getY(uint8_t index);
uint8_t getZ(uint8_t index);
// inverse of getIndex

uint64_t emptyModel();
// return model with all bits set to 0

uint64_t fullModel();
// return model with all bits set to 1

bool getBit(uint64_t model, int x, int y, int z);
// return true if bit for x,y,z is one; false if 0

uint64_t setBit(uint64_t model, int x, int y, int z);
// returns model that's same as paramenter, except bit corresponding to x,y,z is set to 1

uint64_t clearBit(uint64_t model, int x, int y, int z);
// same as setBit, but corresponding bit is set to 0

uint64_t toggleBit(uint64_t model, int x, int y, int z);
// same as setBit and clearBit, but corresponding bit should be flipped from model 1->0, 0->1

