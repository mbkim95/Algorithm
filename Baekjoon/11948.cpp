#include <iostream>
#include <algorithm>
using namespace std;

int science[4], etc[2];

int main(){
    for(int i=0; i<4; i++)
        cin >> science[i];
    for(int i=0; i<2; i++)
        cin >> etc[i];
    sort(science, science+4);
    sort(etc, etc+2);
    int sum = etc[1];
    for(int i=1; i<=4; i++) sum += science[i];
    cout << sum << '\n';
    return 0;
}