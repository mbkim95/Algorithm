#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string result;
    cin >> n;
    cin >> result;

    int a = 0, b = 0;
    for(int i=0; i<result.length(); i++){
        char c = result[i];
        if(c == 'A') a++;
	else b++;
    }

    if(a == b) cout << "Tie\n";
    else if(a > b) cout << "A\n";
    else cout << "B\n";
    return 0;
}
