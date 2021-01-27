#include <iostream>
#include <algorithm>
using namespace std;

string sum(string& a, string& b){
  string result = "";

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  while(a.length() < b.length()) a+='0';
  while(a.length() > b.length()) b+='0';

  int carry = 0;
  for(int i=0; i<a.length(); i++){
    int sum = (a[i] - '0') + (b[i] - '0') + carry;
    carry = sum / 10;
    result += (char)('0' + (sum % 10));
  }
  if(carry != 0) result += '1';
  reverse(result.begin(), result.end());
  return result;
}

int main(){
  string a, b;
  cin >> a >> b;
  cout << sum(a, b) << '\n';
  return 0;
}
