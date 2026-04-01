//
// Created by wcx on 2026/3/24.
//

#ifndef ALGORITHM_ACTOR_H
#define ALGORITHM_ACTOR_H


namespace Game
{
    enum EP_TYPE
    {
        MAGIC,
        FURY
    };

    class Actor
    {
    public:
        /*****/
        bool UseSkill();
        void SetEpType(EP_TYPE type);
        void UpdateLogic(int delta);

    private:
        /*****/
        int ep;
        int maxEp;
        int epTime;
        bool bMax;
        EP_TYPE epType;
    };
}

#endif //ALGORITHM_ACTOR_H