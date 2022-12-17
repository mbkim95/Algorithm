#include <iostream>
#include <vector>
using namespace std;

vector<char> dna;

 char change(char prev, char cur) {
    if(prev == 'A') {
        switch(cur) {
            case 'A': return 'A';
            case 'G': return 'C';
            case 'C': return 'A';
            case 'T': return 'G';
        }
    }
    if(prev == 'G') {
        switch(cur) {
            case 'A': return 'C';
            case 'G': return 'G';
            case 'C': return 'T';
            case 'T': return 'A';
        }
    }
    if(prev == 'C') {
        switch(cur) {
            case 'A': return 'A';
            case 'G': return 'T';
            case 'C': return 'C';
            case 'T': return 'G';
        }
    }
    if(prev == 'T') {
        switch(cur) {
            case 'A': return 'G';
            case 'G': return 'A';
            case 'C': return 'G';
            case 'T': return 'T';
        }
    }
    return 'Z';
 }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    dna.resize(n);
    for(int i=0; i<n; i++) cin >> dna[i];

    for(int i=n-1; i>0; i--) dna[i-1] = change(dna[i-1], dna[i]);
    cout << dna[0] << '\n';
    return 0;
}