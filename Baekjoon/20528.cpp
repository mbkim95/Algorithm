#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool is_possible = true;
    for(int i=0; i<n-1; i++){
        string tmp;
        cin >> tmp;
        if(s[0] != tmp[0]){
            is_possible = false;
            break;
        }
    }
    if(is_possible) cout << "1\n";
    else cout << "0\n";
    return 0;
}
