#pragma once

#include "lib.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

extern vector<position> posPipe;

class pipe :LTexture
{
private:
    const short int randMin = -373 + 30;
    const short int randMax = SCREEN_HEIGHT - LAND_HEIGHT - 373 - PIPE_DISTANCE - 30;   
    string saved_path;
public:
    bool init();

    void Free();

    void render();

    void update();

    short int width() { return getWidth(); }

    short int height() { return getHeight(); }
};