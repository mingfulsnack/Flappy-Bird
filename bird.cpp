#include "bird.h"
#include <stdio.h>
#include <iostream>

bool birde::init(bool isDark)
{
    string birdname[3] = { "res/image/redbird.png",
                    "res/image/yellowbird.png",
                    "res/image/bluebird.png",
    };
    int random = rand() % 3;
    string fbird_path = birdname[random];
    if (saved_path == fbird_path)
    {
        posBird.getPos(75, SCREEN_HEIGHT / 2 - 10);
        ahead = 0;
        angle = 0;
    }
    if (isNULL() || saved_path != fbird_path)
    {
        saved_path = fbird_path;
        if (Load(fbird_path.c_str(), 1))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    return false;
}

void birde::Free()
{
    free();
}

void birde::render()
{
    Render(posBird.x, posBird.y, angle);
}

void birde::fall()
{
    if (die && posBird.y < SCREEN_HEIGHT - LAND_HEIGHT - FBIRD_HEIGHT - 5)
    {
        if (time == 0)
        {
            x0 = posBird.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            posBird.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }
    }
    else return;
}

void birde::update(short int pipeWidth, short int pipeHeight)
{
    if (!die)
    {
        if (time == 0)
        {
            x0 = posBird.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            posBird.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }

        if ((posBird.x + getWidth() > posPipe[ahead].x + 5) && (posBird.x + 5 < posPipe[ahead].x + pipeWidth) &&
            (posBird.y + 5 < posPipe[ahead].y + pipeHeight || posBird.y + getHeight() > posPipe[ahead].y + pipeHeight + PIPE_SPACE + 5))
        {
            die = true;
        }
        else if (posBird.x > posPipe[ahead].x + pipeWidth)
        {
            ahead = (ahead + 1) % TOTAL_PIPE;
            score++;
        }

        if (posBird.y > SCREEN_HEIGHT - LAND_HEIGHT - FBIRD_HEIGHT - 5 || posBird.y < -10)
        {
            die = true;
        }
    }
}