#include <iostream>
using namespace std;

int n, n1, n2, n3, n4, ans; 

int main(){
	cin >> n;
	int tmp;
	for(int i=0; i<n; i++){
		cin >> tmp;
		if(tmp == 1)
			n1++;
		else if(tmp == 2)
			n2++;
		else if(tmp == 3)
			n3++;
		else
			n4++;
	}
	while(n1 != 0 || n2 != 0 || n3 != 0 || n4 != 0){
		if(n4 > 0){
			ans++;
			n4--;
		}else if(n3 > 0 && n1 > 0){
			n3--;
			n1--;
			ans++;
		}else if(n2 > 1){
			n2 -= 2;
			ans++;
		}else if(n2 > 0 && n1 > 1){
			n2--;
			n1 -= 2;
			ans++;
		}else if(n1 > 3){
			n1 -= 4;
			ans++;
		}else if(n3 > 0){
			n3--;
			ans++;
		}else if(n2 > 0 && n1 > 0){
			n2--;
			n1--;
			ans++;
		}else if(n1 > 2){
			n1 -= 3;
			ans++;
		}else if(n2 > 0){
			n2--;
			ans++;
		}else if(n1 > 1){
			n1 -= 2;
			ans++;
		}else if(n1 > 0){
			n1--;
			ans++;
		}
	}
	cout << ans << endl;
}	