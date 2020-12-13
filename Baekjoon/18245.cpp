#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 2;
    while(true){
        string str;
        getline(cin, str);

        if(str == "Was it a cat I saw?") break;
        string ans = "";

        for(int i=0; i<str.length(); i+=cnt)
            ans += str[i];
        cout << ans << '\n';
        cnt++;
    }
    return 0;
}
