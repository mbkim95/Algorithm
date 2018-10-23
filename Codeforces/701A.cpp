#include <iostream>
using namespace std;

int n, c[101];

int main(){
	cin >> n;
	int avg = 0;
	for(int i=1; i<=n; i++){
		cin >> c[i];
		avg += c[i];		
	}
	avg = avg/(n/2);

	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(c[i] + c[j] == avg && c[i] != -1 && c[j] != -1){ 
				cout << i << " " << j << endl;
				c[i] = -1;
				c[j] = -1;
			}
		}
	}
}
