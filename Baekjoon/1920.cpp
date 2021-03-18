#include <iostream>
#include <algorithm>
using namespace std;

int n, m, num[100001];

int find(int number) {
    int s = 0, e = n-1;
    
    while(s <= e){
        int mid = (s + e) / 2;
        if(num[mid] == number) return 1;
        else if(num[mid] < number) s = mid + 1;
        else e = mid - 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i <n; i++) cin >> num[i];
    cin >> m;
    sort(num, num + n);
    for(int i=0;i <m; i++) {
        int tmp;
        cin >> tmp;
        cout << find(tmp) << '\n';
    }
    return 0;
}
