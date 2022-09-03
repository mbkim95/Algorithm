#include <iostream>
#include <vector>
using namespace std;

int n, m, answer = 0;
string dna[1001];
const char cand[] = {'A', 'C', 'G', 'T'};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> dna[i];

    int cand_cnt[4] = { 0 };
    for(int j=0; j<m; j++) {
        int max = 0, tmp_cand = 0;
        for(int i=0; i<n; i++) {
            for(int k=0; k<4; k++) {
                if(dna[i][j] == cand[k]) cand_cnt[k]++;
            }
        }
        for(int j=0; j<4; j++) {
            if(max < cand_cnt[j]) {
                max = cand_cnt[j];
                tmp_cand = j;
            }
        }
        cout << cand[tmp_cand];
        answer += (n - cand_cnt[tmp_cand]);
        for(int i=0; i<4; i++) cand_cnt[i] = 0;
    }
    cout << '\n' << answer << '\n';
    return 0;
}