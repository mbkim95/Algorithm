#include <iostream>
using namespace std;

int n1, n2, n3, n4, sum;

int get32(){
	if(n1 > 0 && n2 > 0){
		n1--;
		n2--;
		sum += 32;
		return 1;
	}
	return 0;
}

int get256(){
	if(n1 > 0 && n3 > 0 && n4 > 0){
		n1--;
		n3--;
		n4--;
		sum += 256;
		return 1;
	}
	return 0;
}

int main(){
	cin >> n1 >> n2 >> n3 >> n4;
	
	while(get256() != 0){

	}

	while(get32() != 0){

	}

	cout << sum << endl;
}