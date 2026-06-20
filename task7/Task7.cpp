#include <iostream>
#include <string>

int main() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::string a;
   std::cin >> a;

   bool flag = false;
   if ((int)a[0] <= 90 && (int)a[0] >= 65) {
      if ((int)a[1] <= 57 && (int)a[1] >= 48) {
         if ((int)a[2] <= 57 && (int)a[2] >= 48) {
            if ((int)a[3] <= 57 && (int)a[3] >= 48) {
               if ((int)a[4] <= 90 && (int)a[4] >= 65) {
                  if ((int)a[5] <= 90 && (int)a[5] >= 65) {
                     std::cout << "Yes" << std::endl;
                     flag = true;
                  }
               }
            }
         }
      }
   }
   if (!flag) {
      std::cout << "No" << std::endl;
   }
}