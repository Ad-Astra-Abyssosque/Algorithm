//
// Created by wcx on 2026/4/10.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

const double PI = 3.14159265358979323846;

class SinTable {
public:
    // 构造函数：预计算 [0, 2π] 区间内的 tableSize+1 个正弦值
    SinTable(int tableSize) : m_tableSize(tableSize) {
        m_table.resize(tableSize + 1);
        double step = 2.0 * PI / tableSize;
        for (int i = 0; i <= tableSize; ++i) {
            double rad = i * step;
            m_table[i] = std::sin(rad);
        }
    }

    // 查表并插值计算正弦值，不得调用系统 sin
    float Sin(float angle) {
        // 角度转弧度
        double rad = angle * PI / 180.0;
        // 归一化到 [0, 2π)
        rad = std::fmod(rad, 2.0 * PI);
        if (rad < 0) rad += 2.0 * PI;

        // 计算浮点索引
        double pos = rad / (2.0 * PI) * m_tableSize;
        int idx = static_cast<int>(pos);
        double frac = pos - idx;

        // 处理边界（理论上 rad<2π 时 idx ≤ m_tableSize-1，但防御性处理）
        if (idx >= m_tableSize) {
            idx = m_tableSize - 1;
            frac = 1.0;
        }

        // 线性插值
        double val = m_table[idx] + (m_table[idx + 1] - m_table[idx]) * frac;

        // 修正接近零的浮点误差
        if (std::fabs(val) < 1e-6) val = 0.0;
        return static_cast<float>(val);
    }

private:
    int m_tableSize;
    std::vector<double> m_table;  // 使用 double 保证插值精度
};

int InterpolateSin() {
    const int TABLE_SIZE = 10000;  // 满足 tableSize < 100000 的要求
    SinTable sinTable(TABLE_SIZE);

    double angle;
    std::cin >> angle;

    // LUT 结果
    float lutResult = sinTable.Sin(static_cast<float>(angle));
    // 系统 sin 结果（用于对比）
    double sysResult = std::sin(angle * PI / 180.0);

    // 输出，保留四位小数，处理负零
    std::cout << std::fixed << std::setprecision(4);
    std::cout << (std::fabs(lutResult) < 1e-6 ? 0.0 : lutResult) << std::endl;
    std::cout << (std::fabs(sysResult) < 1e-6 ? 0.0 : sysResult) << std::endl;

    return 0;
}