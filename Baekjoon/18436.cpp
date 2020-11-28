#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> num, tree;

// 세그먼트 트리 초기화
int init(int node, int start, int end) {
    if (start == end) return tree[node] = num[end];
    int mid = (start + end) / 2;
    return tree[node] =
               init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

// 값 갱신
void update(int node, int start, int end, int idx, int diff) {
    if (idx < start || end < idx) return;
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(2 * node, start, mid, idx, diff);
        update(2 * node + 1, mid + 1, end, idx, diff);
    }
}

// 짝수 혹은 홀수 갯수 
int query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, left, right) +
           query(2 * node + 1, mid + 1, end, left, right);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    num.resize(n, 0);
    tree.resize(4 * n);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        // 홀수이면 1, 짝수이면 0으로 저장
        if (tmp % 2 == 1) num[i] = 1;
    }
  
    // 세그먼트 트리 생성
    init(1, 0, n - 1);

    cin >> m;
    while (m--) {
        int i, l, r;
        cin >> i >> l >> r;
        if (i == 1) {
            r = r % 2;
            // 이전 숫자와 바꿀 숫자의 홀/짝이 다른 경우
            if (num[l - 1] != r) {
                if (r == 1)
                    update(1, 0, n - 1, l - 1, 1);
                else
                    update(1, 0, n - 1, l - 1, -1);
                num[l - 1] = r;
            }
        } else if (i == 2)
            cout << r - l + 1 - query(1, 0, n - 1, l - 1, r - 1) << '\n';
        else
            cout << query(1, 0, n - 1, l - 1, r - 1) << '\n';
    }
    return 0;
}
