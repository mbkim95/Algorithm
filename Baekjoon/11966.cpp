#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool is_two = true;
    while(n > 1){
        if(n % 2){
            is_two = false;
            break;
        }
        n /= 2;
    }
    if(is_two) cout << "1\n";
    else cout << "0\n";
    return 0;
}