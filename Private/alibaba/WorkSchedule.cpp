//
// Created by wcx on 2026/4/9.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int workschedule() {
    int n;
    cin >> n;
    vector<int> w(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        total += w[i];
    }

    int target = total / 2;
    int best = 0;
    // 枚举所有子集（位运算）
    for (int mask = 0; mask < (1 << n); ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
                sum += w[i];
            }
        }
        if (sum <= target && sum > best) {
            best = sum;
        }
    }
    int ans = total - 2 * best;
    cout << ans << endl;
    return 0;
}