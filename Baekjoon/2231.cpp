#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool find = false;
  for(int i=1; i<=1000000; i++){
	  int tmp = i;
	  int sum = i;
	  while(tmp > 0){
		  sum += tmp % 10;
		  tmp /= 10;
	  }
	  if(sum == n) {
		  cout << i << '\n';
		  find = true;
		  break;
	  }
  }
  if(!find) cout << "0\n";
  return 0;
}
