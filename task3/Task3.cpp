#include <iostream>
#include <vector>
#include <cstdint>

class FenwickTree {
 private:
   int n_;
   std::vector<int64_t> tree_;

   int64_t Query(int i) {
      int64_t sum = 0;
      while(i > 0) {
         sum += tree_[i];
         i -= i & -i;
      }
      return sum;
   }

 public:
   FenwickTree(int n) : n_(n), tree_(n + 1, 0) {}

   void Add(int i, int64_t x) {
      while(i <= n_) {
         tree_[i] += x;
         i += i & -i;
      }
   }

   int64_t Query(int u, int r) {
      if (u > r) {
         return 0;
      }
      return Query(r) - Query(u - 1); 
   }
};

int main() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr);

   int n = 0;
   int k = 0;
   std::cin >> n >> k;

   FenwickTree ft(n);

   for (int index = 0; index < k; ++index) {
      int type = 0;
      std::cin >> type;
      if (type == 1) {
         int i = 0;
         int64_t x = 0;
         std::cin >> i >> x;
         ft.Add(i, x);
      } else if (type == 2){
         int u = 0;
         int r = 0;
         std::cin >> u >> r;
         std::cout << ft.Query(u, r) << std::endl;
      }
   }
}