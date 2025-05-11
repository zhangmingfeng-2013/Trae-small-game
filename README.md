# Trae-small-game

# 猜数字游戏 - number.cpp

## 游戏说明
基于C++11标准开发的终端猜数字游戏，玩家需要在有限次数内猜出随机生成的数字。

### 游戏规则
1. 数字范围：MIN_NUMBER ~ MAX_NUMBER（具体值见代码定义）
2. 每次猜测后系统会提示"太大"或"太小"
3. 在MAX_ATTEMPTS次机会内猜中即获胜
4. 机会用尽后显示正确答案

## 技术实现

### 随机数生成
使用现代C++随机数库的组合方案：
```cpp
#include <random>

// 硬件熵源（非确定性随机数）
std::random_device rd;  

// 梅森旋转算法引擎（播种）
std::mt19937 gen(rd()); 

// 均匀分布生成器（范围定义）
std::uniform_int_distribution<> dist(MIN_NUMBER, MAX_NUMBER);

int target_number = dist(gen); // 最终生成目标数字
```
