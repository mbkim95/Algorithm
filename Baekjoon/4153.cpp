#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  while (true) {
    int tri[3];
    cin >> tri[0] >> tri[1] >> tri[2];
    if(tri[0] == 0 && tri[1] == 0 && tri[2] == 0) break;
    sort(tri, tri + 3);
    if ((tri[0] * tri[0]) + (tri[1] * tri[1]) == (tri[2] * tri[2]))
      cout << "right\n";
    else
      cout << "wrong\n";
  }
  return 0;
}
