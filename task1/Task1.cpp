#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Ускоряем ввод-вывод для больших объемов данных
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    std::cin >> n;

    // Считываем пирамиду
    std::vector<std::vector<int>> pyramid(n);
    for (int i = 0; i < n; ++i) {
        pyramid[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            std::cin >> pyramid[i][j];
        }
    }

    // Создаем таблицу dp (копию пирамиды)
    std::vector<std::vector<int>> dp = pyramid;

    // Заполняем dp снизу вверх, начиная с предпоследней строки
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            // К текущему числу прибавляем минимальный путь из двух возможных вниз
            dp[i][j] += std::min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    // Восстанавливаем путь
    std::vector<int> path;
    int curr_col = 0; // Начинаем с вершины (столбец 0)

    for (int i = 0; i < n; ++i) {
        path.push_back(pyramid[i][curr_col]); // Записываем число из оригинальной пирамиды
        
        if (i < n - 1) {
            // Смотрим, куда ведет минимальный путь: влево (индекс не меняется) или вправо (индекс +1)
            if (dp[i + 1][curr_col] >= dp[i + 1][curr_col + 1]) {
                // Идем вправо
                curr_col++;                
            }
        }
    }

    // Вывод результата
    std::cout << dp[0][0] << std::endl; // Минимальная сумма

    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}