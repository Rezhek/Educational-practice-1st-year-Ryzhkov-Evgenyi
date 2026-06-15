#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> arr(n);
    
    std::vector<int> result;
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            int x;
            std::cin >> x;
            arr[i].push_back(x);
        }
    }
    
    int sum = arr[0][0];
    int j = 0;
    int min_id;
    result.push_back(arr[0][0]);
    for (int i = 0; i < n - 1; ++i) {
        int min = 1e9;
        if (j - 1 >= 0) {
            if (arr[i + 1][j - 1] < arr[i + 1][j]) {
                min = arr[i + 1][j - 1];
                min_id = j - 1;
            } else {
                min = arr[i + 1][j];
                min_id = j;
            }
        }
        if (j + 1 < arr[i].size()) {
            if (arr[i + 1][j + 1] < min) {
                min = arr[i + 1][j + 1];
                min_id = j + 1;
            }
        }  
        if (arr[i + 1][j] < min) {
            min = arr[i + 1][j];
            min_id = j;
        }
        j = min_id;
        sum += min;
        result.push_back(min);
    }
    std::cout << sum << std::endl;
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << ' ';
    }
}
