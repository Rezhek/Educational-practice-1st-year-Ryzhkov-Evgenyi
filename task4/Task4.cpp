#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

int main() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr);

   int n = 0;
   int64_t k = 0;
   std::cin >> n >> k;

   std::vector<int> p(n);
   for (int i = 0; i < n; ++i) {
      std::cin >> p[i];
      p[i]--;
   }

   std::string word;
   std::cin >> word;

   for (int i = 0; i < k; ++i) {
      std::string next_word = word;
      for (int j = 0; j < n; ++j) {
         next_word[p[j]] = word[j];
      }
      word = next_word;
   }

   std::cout << word << std::endl;
}