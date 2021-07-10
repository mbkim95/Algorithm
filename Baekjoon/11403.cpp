#include <iostream>
using namespace std;

int n, adj[101][101];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> adj[i][j];

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (adj[i][k] & adj[k][j]) adj[i][j] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << adj[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}