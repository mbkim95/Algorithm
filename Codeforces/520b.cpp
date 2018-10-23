#include <iostream>
using namespace std;

int main(){
	int n = 0, m = 0, a = 0;

	cin >> n >> m;

	while(n<m){
		m%2 ? m++ : m/=2;
		a++;
	}
	cout << a+n-m << endl;
}