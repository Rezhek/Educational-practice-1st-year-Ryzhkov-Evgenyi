#include <iostream>
#include <cstdint>

int main() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr);

   int t = 0;
   std::cin >> t;
   while (t--) {
      int64_t a = 0;
      int64_t b = 0;
      int64_t x = 0;
      int64_t y = 0;
      std::cin >> a >> b >> x >> y;
      
      int64_t sum = 0;
      if (a >= y) {
         sum += y;
         a -= y;
      } else {
         sum += a;
         a = 0;
      }

      if (b >= x) {
         sum += x;
      } else {
         sum += b;
         x -= b;
      }

      if (a >= x) {
         sum += x;
      } else {
         sum += a;
      }
      std::cout << sum << ' ';
   }
}