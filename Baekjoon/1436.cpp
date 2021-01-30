#include <iostream>
using namespace std;

int main() {
  int n, cnt = 0;
  cin >> n;

  int s = 665;
  while(cnt < n){
	  s++;
	  string num = to_string(s);
	  if(num.find("666") != string::npos) cnt++;
  }
  cout << s << '\n';
  return 0;
}
