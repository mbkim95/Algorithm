#include <iostream>
using namespace std;

int main() {
  while (true) {
    string num;
    cin >> num;
    if (num == "0") break;

    int s = 0, e = num.length() - 1;
    bool is_palindrome = true;
    while(s < e) {
      if(num[s] != num[e]){
        is_palindrome = false;
        break;
      }
      s++;
      e--;
    }
    if(is_palindrome) cout << "yes\n";
    else cout << "no\n";
  }
  return 0;
}