#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, b = 1;
    set<int> s;
    cin >> n;
    for(int i=1; i<=n; i++) s.insert(i);

    while(s.size() > 1) {
        auto it = s.begin();

        while(it != s.end()) {
            if(*it % b == 0 && *it % (2*b) != 0) s.erase(it++);
            else it++;
        }
        b *= 2;
    }
    cout << *s.begin() << '\n';
    return 0;
}