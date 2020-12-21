#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    for(int i=0; i<3; i++){
	string num;
	cin >> num;
	int ans = 1, cnt = 1;
	char tmp = num[0];
	for(int j=1; j<num.length(); j++){
	    if(tmp == num[j]) cnt++;
	    else{
		ans = max(ans, cnt);
		cnt = 1;
		tmp = num[j];
	    }
	}
	ans = max(ans, cnt);
	cout << ans << '\n';
    }
    return 0;
}
