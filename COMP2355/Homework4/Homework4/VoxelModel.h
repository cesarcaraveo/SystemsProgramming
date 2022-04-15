#pragma once

struct VoxelModel {
    int x, y, z = 0;
    int bitmapSize = ((x * y * z) + 7) / 8; // ceiling of x*y*z / 8
    uint8_t *bitmap = new uint8_t[bitmapSize];
};

// function definitions

int getIndex(const VoxelModel &model, int x, int y, int z);
// takes x,y,z coor. (x < model.x, y < model.y, z < model.z)
// returns which bit represents that voxel [0,x*y*z - 1] range
// should work with any size model (not just 4x4x4)

void getXYZ(const VoxelModel &model, int index, int &x, int &y, int &z);
// replace getX, getY, getZ

bool getBit(const VoxelModel &model, int x, int y, int z);
// return true if bit for x,y,z is one; false if 0

void setBit(VoxelModel &model, int x, int y, int z);
// returns model that's same as paramenter, except bit corresponding to x,y,z is set to 1

void clearBit(VoxelModel &model, int x, int y, int z);
// same as setBit, but corresponding bit is set to 0

void toggleBit(VoxelModel &model, int x, int y, int z);
// same as setBit and clearBit, but corresponding bit should be flipped from model 1->0, 0->1

VoxelModel allocateModel(int nx, int ny, int nz);
// create voxelmodel struct and initialize it to appropriate size and empty

void clearModel(VoxelModel &model);
// set all voxels to off (0)

void fillModel(VoxelModel &model);
// set all voxels to on (1)

void deleteModel(VoxelModel &model);
// deallocate all heap memory, set model size to 0, data to null

int getByteNumber(int index);
// returns which byte (uint8_t) contains byte number index

uint8_t getBitNumber(int index);
// returns which bit in the byte corresponds to byte number index

void addSphere(VoxelModel &model, float cx, float cy, float cz, float radius);

void subtractSphere(VoxelModel &model, float cx, float cy, float cz, float radius);

void toggleSphere(VoxelModel &model, float cx, float cy, float cz, float radius);

