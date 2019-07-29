#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> num;

void plusSet(){
    for(int i=0; i<10; i++)
        num[i]++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    num = vector<int>(10, 1);    
    int ans = 1;
    while(n > 0){
        int tmp = n % 10;
        n /= 10;
        bool flag = 0;
        if(num[tmp] == 0){
            if(tmp == 6 && num[9] != 0){
                num[9]--;
                flag = 1;
            }else if(tmp == 9 && num[6] != 0){
                num[6]--;            
                flag = 1;
            }
            if(!flag){
                plusSet();
                ans++;
            }
        }

        if(!flag)
            num[tmp]--;
    }
    cout << ans << '\n';
    return 0;
}