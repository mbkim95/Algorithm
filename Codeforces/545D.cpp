#include <iostream>
#include <algorithm>
using namespace std;

int n, ans, t[100000];

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> t[i];
	sort(t, t+n);
	int delay = 0;	
	for(int i=0; i<n; i++){
		if(delay <= t[i]){
			delay += t[i];
			ans++;
		}
	}
	cout << ans << endl;
}