#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

int main() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr);

   int h = 0;
   int w = 0;
   std::cin >> h >> w;
   int h1 = h - 1;
   int w1 = w - 1;
   int h2 = 0;
   int w2 = 0;

   std::vector<std::vector<int>> m(h, std::vector<int> (w, 0));
   for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
         std::cin >> m[i][j];
         if(m[i][j] == 1) {
            h1 = std::min(h1, i - 1);
            w1 = std::min(w1, j - 1);
            h2 = std::max(h2, i + 1);
            w2 = std::max(w2, j + 1);
         }
      }
   }
   std::cout << h1 << ' ' << w1 << ' ' << h2 << ' ' << w2 << std::endl;

}