#include <iostream>
#include <algorithm>
using namespace std;

bool comp(char& a, char& b){
  return a > b;
}

int main(){
  string n;
  cin >> n;
  sort(n.begin(), n.end(), comp);
  cout << n << '\n';
  return 0;
}
