#include "block_factory.h"

void copy_cells(BlockType t, int cells[4][2]) {
    switch(t) {
        case I: memcpy(cells, I_Block, sizeof(I_Block)); break;
        case O: memcpy(cells, O_Block, sizeof(I_Block)); break;
        case T: memcpy(cells, T_Block, sizeof(I_Block)); break;
        case Z: memcpy(cells, Z_Block, sizeof(I_Block)); break;
        case S: memcpy(cells, S_Block, sizeof(I_Block)); break;
        case J: memcpy(cells, J_Block, sizeof(I_Block)); break;
        case L: memcpy(cells, L_Block, sizeof(I_Block)); break;
    }
}

void spawn(State* s) {
    switch(s->next) {
        case I: spawnI(s->block); break;
        case O: spawnO(s->block); break;
        case T: spawnT(s->block); break;
        case Z: spawnZ(s->block); break;
        case S: spawnS(s->block); break;
        case J: spawnJ(s->block); break;
        case L: spawnL(s->block); break;
    }
    s->block->x = SPAWN_X;
    s->block->y = 1;

    if (spawnSpaceAvailable(s)) {
        s->next = rand() % NUM_BLOCKS;
    } else {
        s->running = 0;
    }
}

/*
 * Make sure that all cells occupied by the block are empty.
 * Perform this check immediately after spawning a block so that blocks do not
 * spawn in eachother.
 */
int spawnSpaceAvailable(State* s) {
    for (int i = 0; i < 4; i++) {
        int x = s->block->cells[i][0] + s->block->x;
        int y = s->block->cells[i][1] + s->block->y;

        if (s->grid[x][y] != Empty) {
            return 0;
        }
    }
    return 1;
}

void spawn_I(Block* b) {
    memcpy(b->cells, I_Block, sizeof(I_Block));
    b->color = Cyan;
    b->type = I;
}

void spawn_O(Block* b) {
    memcpy(b->cells, O_Block, sizeof(I_Block));
    b->color = Yellow;
    b->type = O;
}

void spawn_T(Block* b) {
    memcpy(b->cells, T_Block, sizeof(I_Block));
    b->color = Purple;
    b->type = T;
}

void spawn_Z(Block* b) {
    memcpy(b->cells, Z_Block, sizeof(I_Block));
    b->color = Red;
    b->type = Z;
}

void spawn_S(Block* b) {
    memcpy(b->cells, S_Block, sizeof(I_Block));
    b->color = Green;
    b->type = S;
}

void spawn_J(Block* b) {
    memcpy(b->cells, J_Block, sizeof(I_Block));
    b->color = Blue;
    b->type = J;
}

void spawn_L(Block* b) {
    memcpy(b->cells, L_Block, sizeof(I_Block));
    b->color = White;
    b->type = L;
}
