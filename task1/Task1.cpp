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
    result.push_back(arr[0][0]);
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i + 1][j + 1] < arr[i + 1][j]) {
            sum += arr[i + 1][j + 1];
            result.push_back(arr[i + 1][j + 1]);
            j += 1;
        } else {
            sum += arr[i + 1][j];
            result.push_back(arr[i + 1][j]);
        }
    }
    
    std::cout << sum << std::endl;
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << ' ';
    }
}
