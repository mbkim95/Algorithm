#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	if(n==0){
		cout << 1 << endl;
		return 0;
	}
	switch(n%4){
		case 1:
			cout << 8 << endl;
			break;
		case 2 :
			cout << 4 << endl;
			break;
		case 3 :
			cout << 2 << endl;
			break;
		case 0 :
			cout << 6 << endl;
			break;
	}
}