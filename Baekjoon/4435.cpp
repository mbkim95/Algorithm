#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int c=1; c<=t; c++) {
        int ho, ghu, el, dw, eg, gmg, ok, shu, wf, gb, uh, tr, smg;
        cin >> ho >> ghu >> el >> dw >> eg >> gmg;
        cin >> ok >> shu >> wf >> gb >> uh >> tr >> smg;
        int s1 = ho + 2 * ghu + 3 * el + 3 * dw + 4 * eg + 10 * gmg;
        int s2 = ok + 2 * shu + 2 * wf + 2 * gb + 3 * uh + 5 * tr + 10 * smg;
        cout << "Battle " << c << ": ";
        if(s1 > s2) cout << "Good triumphs over Evil\n";
        else if(s1 < s2) cout << "Evil eradicates all trace of Good\n";
        else cout << "No victor on this battle field\n";
    }
    return 0;
}