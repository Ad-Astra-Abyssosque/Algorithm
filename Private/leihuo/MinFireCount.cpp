//
// Created by wcx on 2026/4/11.
//

#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

// 向上取整 a / b，要求 a, b > 0
static inline int64 ceil_div(int64 a, int64 b) {
    return (a + b - 1) / b;
}

int MinFireCount() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int64 L, r;
    cin >> n >> L >> r;

    vector<int64> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];

    // 同一坐标的人行为完全一致，压成一组
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());

    int m = (int)x.size();

    // 预处理每组被推出左右边界所需的“净推动次数”
    vector<int64> needLeft(m), needRight(m);
    for (int i = 0; i < m; ++i) {
        needLeft[i]  = ceil_div(x[i], r);       // 推出左边界所需：右侧炮数 - 左侧炮数
        needRight[i] = ceil_div(L - x[i], r);   // 推出右边界所需：左侧炮数 - 右侧炮数
    }

    auto check = [&](int k) -> bool {
        // need = 扫描到当前位置前，至少需要直接打掉多少组
        int need = 0;

        for (int i = 0; i < m; ++i) {
            // 如果当前组不直接打，则必须满足：
            // k - 2*need >= needLeft[i]   或   2*need - k >= needRight[i]
            bool canSkip =
                ((int64)k - 2LL * need >= needLeft[i]) ||
                (2LL * need - (int64)k >= needRight[i]);

            if (!canSkip) {
                ++need;  // 这组必须直接打掉
                if (need > k) return false;
            }
        }
        return true;
    };

    int left = 0, right = m;  // 最多只需要把每个不同坐标打一次
    while (left < right) {
        int mid = (left + right) >> 1;
        if (check(mid)) right = mid;
        else left = mid + 1;
    }

    cout << left << '\n';
    return 0;
}
