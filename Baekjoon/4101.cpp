#include <iostream>
using namespace std;

int main(){
  while(true){
    int a, b;
    cin >> a >> b;
    if(a == 0 && b == 0) break;
    else if(a > b) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}