#include <iostream>
using namespace std;

int n, num[1001][10];

int main(){ 
  cin >> n;
  for(int i=0; i<10; i++) num[1][i] = 1;
  for(int i=2; i<=n; i++)
    for(int j=0; j<10; j++)
      for(int k=0; k<=j; k++)
        num[i][j] = (num[i][j] + num[i-1][k])  % 10007;

  int sum = 0;
  for(int i=0; i<10; i++) sum = (sum + num[n][i]) % 10007;
  cout << sum << '\n';
  return 0;
}