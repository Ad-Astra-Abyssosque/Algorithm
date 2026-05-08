//
// Created by wcx on 2026/4/9.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

int FindTreasure() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    // 1-indexed
    vector<vector<int>> a(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<bool>> portal(n + 2, vector<bool>(m + 2, false));
    for (int t = 0; t < k; ++t) {
        int x, y;
        cin >> x >> y;
        portal[x][y] = true;
    }

    // 预处理跳跃信息
    vector<vector<int>> nextX(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> nextY(n + 2, vector<int>(m + 2, 0));
    vector<vector<ll>> sum(n + 2, vector<ll>(m + 2, 0));

    // 从右下角向左上角处理
    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            if (i == n && j == m) {
                // 终点特殊处理，无论是否为传送门都当作普通格子
                nextX[i][j] = i;
                nextY[i][j] = j;
                sum[i][j] = a[i][j];
                continue;
            }

            if (!portal[i][j]) {
                // 普通格子
                nextX[i][j] = i;
                nextY[i][j] = j;
                sum[i][j] = a[i][j];
            } else {
                // 传送门格子
                bool canDown = (i + 1 <= n);
                bool canRight = (j + 1 <= m);
                int ti, tj;
                if (canDown && canRight) {
                    if (a[i + 1][j] > a[i][j + 1]) {
                        ti = i + 1; tj = j;
                    } else {
                        ti = i; tj = j + 1;
                    }
                } else if (canDown) {
                    ti = i + 1; tj = j;
                } else if (canRight) {
                    ti = i; tj = j + 1;
                } else {
                    // 理论上不会到这里（因为已排除终点）
                    ti = i; tj = j;
                }
                // 递归到已经计算过的格子
                nextX[i][j] = nextX[ti][tj];
                nextY[i][j] = nextY[ti][tj];
                sum[i][j] = a[i][j] + sum[ti][tj];
            }
        }
    }

    // DP
    const ll INF = 1e18;
    vector<vector<ll>> dp(n + 2, vector<ll>(m + 2, -INF));
    dp[1][1] = a[1][1];   // 起点

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dp[i][j] == -INF) continue;

            if (portal[i][j] && !(i == n && j == m)) {
                // 传送门格子，只能强制传送
                int ti = nextX[i][j];
                int tj = nextY[i][j];
                // 加上除了起点外的路径部分
                ll new_val = dp[i][j] + (sum[i][j] - a[i][j]);
                if (new_val > dp[ti][tj]) {
                    dp[ti][tj] = new_val;
                }
            } else {
                // 普通格子（或终点）
                // 向右
                if (j + 1 <= m) {
                    int ni = i, nj = j + 1;
                    int ti = nextX[ni][nj];
                    int tj = nextY[ni][nj];
                    ll new_val = dp[i][j] + sum[ni][nj];
                    if (new_val > dp[ti][tj]) {
                        dp[ti][tj] = new_val;
                    }
                }
                // 向下
                if (i + 1 <= n) {
                    int ni = i + 1, nj = j;
                    int ti = nextX[ni][nj];
                    int tj = nextY[ni][nj];
                    ll new_val = dp[i][j] + sum[ni][nj];
                    if (new_val > dp[ti][tj]) {
                        dp[ti][tj] = new_val;
                    }
                }
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}