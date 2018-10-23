#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

void solve(int *arr, int *tmp, int n){
	sort(arr, arr+n);
	sort(tmp, tmp+n-1);
	for(int i=0; i<n; i++){
		if(arr[i] != tmp[i]){
			cout << arr[i] << endl;
			return;
		}
	}
	return;
}

int main(){
	int n;
	cin >> n;
	int *arr = (int *)malloc(sizeof(int)*n);
	int *tmp1 = (int *)malloc(sizeof(int)*(n-1));
	int *tmp2 = (int *)malloc(sizeof(int)*(n-2));

	for(int i=0; i<n; i++)
		cin >> arr[i];
	n--;
	for(int i=0; i<n; i++)
		cin >> tmp1[i];
	solve(arr, tmp1, n+1);
	n--;
	for(int i=0; i<n; i++)
		cin >> tmp2[i];
	solve(tmp1, tmp2, n+1);
}