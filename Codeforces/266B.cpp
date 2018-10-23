#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n, t;
	char str[51];
	cin >> n >> t;
	cin >> str;
	
	while(t--){
		for(int i=0; i<strlen(str)-1; i++){
			if(str[i] == 'B' && str[i+1] == 'G'){
					str[i] = 'G';
					str[i+1] = 'B';
					i++;
			}
		}
	}
	cout << str << endl;

}