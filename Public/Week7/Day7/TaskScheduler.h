//
// Created by yoimiya on 2026/7/23.
//

#ifndef ALGORITHM_TASKSCHEDULER_H
#define ALGORITHM_TASKSCHEDULER_H
#include "../../../Solution.h"

#include <queue>
#include <unordered_map>

using namespace std;

class TaskScheduler: public Solution {
public:
    unordered_map<char, int> task_map;
    unordered_map<char, int> task_last_time;
    int tick = 0;
    int gap = 0;

    int leastInterval(vector<char>& tasks, int n) {
        gap = n;
        for (const char& task: tasks) {
            task_map[task]++;
        }

        int task_left = tasks.size();
        while (task_left > 0) {
            tick++;
            char next_task = find_task();
            if (next_task >= 'A' && next_task <= 'Z') {
                task_left--;
                task_map[next_task]--;
                task_last_time[next_task] = tick;
            }
        }

        return tick;
    }

    char find_task() {
        char target_task = 0;
        int task_count = 0;
        for (auto& it: task_map) {
            if (task_last_time.find(it.first) == task_last_time.end() || task_last_time[it.first] + gap < tick) {
                if (it.second > task_count) {
                    target_task = it.first;
                    task_count = it.second;
                }
            }
        }
        return target_task;
    }
};

#endif //ALGORITHM_TASKSCHEDULER_H
