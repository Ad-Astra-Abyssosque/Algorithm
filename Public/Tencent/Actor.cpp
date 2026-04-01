//
// Created by wcx on 2026/3/24.
//

#include "Actor.h"
#include <iostream>

namespace Game
{
    bool Actor::UseSkill()
    {
        if (epType == MAGIC)
        {
            if (ep >= 2)
            {
                ep -= 2;
            }
            else
            {
                return false;
            }
        }
        else if (epType == FURY)
        {
            if (ep < maxEp && !bMax)
            {
                ++ep;
            }
        }

        return true;
    }

    void Actor::SetEpType(EP_TYPE type)
    {
        epType = type;
        if (type == MAGIC)
        {
            maxEp = 10;
        }
        else if (epType == FURY)
        {
            maxEp = 5;
        }
        else
        {
            std::cout << "SetEpType: Invalid EP_TYPE!" << std::endl;
        }

        /*****/
    }

    void Actor::UpdateLogic(int delta)
    {
        epTime += delta;
        if (epTime >= 1000)
        {
            if (epType == MAGIC)
            {
                if (ep < maxEp)
                {
                    ++ep;
                }
            }
            else if (epType == FURY)
            {
                if (bMax)
                {
                    --ep;
                    if (ep == 0)
                    {
                        bMax = false;
                    }
                }
                else
                {
                    if (ep = maxEp)
                    {
                        bMax = true;
                    }
                }
            }
            else
            {
                std::cout << "UpdateLogic: Invalid EP_TYPE!" << std::endl;
            }

            epTime -= 1000;
        }

        /*****/
    }
}