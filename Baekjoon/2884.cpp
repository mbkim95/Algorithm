#include <iostream>
using namespace std;

int h, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> h >> m;
	bool minus = false;

	if(m < 45){
		m += 60;
		minus = true;
	}
	m -= 45;
	
	if(minus)
		h--;

	if(h < 0)
		h = 23;

	cout << h << ' ' << m << '\n';
	return 0;
}
