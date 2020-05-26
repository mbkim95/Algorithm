#include <iostream>
using namespace std;

int main(){
    string dishes;
    cin >> dishes;
    int ans = 0;
    char prev = ' ';
    for(char c : dishes){
        if(prev == c) ans += 5;
        else{
            prev = c;
            ans += 10;
        }
    }
    cout << ans << '\n';
    return 0;
}