#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int result = 1, bird = 1;

    while(true){
	if(n - bird >= 0) n -= bird;
        else{
	    bird = 1;
	    n -= bird;
	}
	if(n == 0) break;

	result++;
	bird++;
    }
    cout << result << '\n';
    return 0;
}
