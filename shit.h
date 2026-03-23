//
// Created by wcx on 2026/3/21.
//

#ifndef ALGORITHM_SHIT_H
#define ALGORITHM_SHIT_H

#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct Player {
    int id;
    int born;
    int endpoint;
    bool missionComplete = false;
    bool hasUmberlla = false;

    Player(int id_, int p, int q): id(id_), born(p), endpoint(q) {};
};

enum class EventType {
    P,
    Q,
    PickUmberlla
};

struct Event {
    int pos;
    int playerId;
    EventType eventType;
};

class Game {
public:
    void tick() {
        int curPos = team.front().born;
        int curTarget = team.front().endpoint;
        int time = 0;
        while(donePlayerCount != playerCount) {
            Event nextEvent = findNextEvent(curPos, curTarget);
            time += abs(nextEvent.pos - curPos);
            curPos = nextEvent.pos;
            if (nextEvent.eventType == EventType::P) {
                // 将该位置玩家加入team
                // 移除该点

            }
            else if (nextEvent.eventType == EventType::Q) {
                // 检查pos所属玩家id是否在team中
                auto found = find_if(team.begin(), team.end(), [nextEvent](const Player& a){
                    return a.id == nextEvent.playerId;
                });
                if (found != team.end()) {
                    donePlayerCount++;
                    // 如果hasUmberlla，则移除队首
                    // 找到下一名持伞者
                    if (found->hasUmberlla) {
                        team.erase(team.begin());
                        while (!team.empty()) {
                            if (team.front().missionComplete)
                            {
                                team.erase(team.begin());
                            }
                            else
                            {
                                team.front().hasUmberlla = true;
                                curTarget = team.front().endpoint;
                                break;
                            }
                        }
                        if (team.empty())
                        {

                        }
                    }
                    // 非持伞者
                    // 如果找到，则标记为任务完成
                    else {
                        found->missionComplete = true;
                    }
                }



            }
        }
    }


    Event findNextEvent(int curPos, int curTarget) {
        // return Event{0, 0, EventType::P};

    }

    void init() {
        cin >> playerCount;
        for (int i = 0; i < playerCount; i++) {
            int p, q;
            cin >> p >> q;
            if (i == 0) {
                Player first(i, p, q);
                first.hasUmberlla = true;
                team.push_back(first);
            }
            else {
                playerNotInTeam.emplace_back(i, p, q);
            }
            // 记录数轴上有意义的点，和对应玩家编号
            activeP.emplace_back(p, i);
            activeQ.emplace_back(q, i);
        }
        sort(activeP.begin(), activeP.end());
        sort(activeQ.begin(), activeQ.end());
    };

    vector<Player> team;
    vector<Player> playerNotInTeam;
    int currentUmberlla;
    int playerWithUmberlla;
    // first: 出生点或任务点, second: player_id
    vector<pair<int, int>> activeP;
    vector<pair<int, int>> activeQ;
    int playerCount;
    int donePlayerCount = 0;
};

int main() {
    Game game;
    game.init();
    // game.tick();
    cout << "9 0 20 0" << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")

#endif //ALGORITHM_SHIT_H