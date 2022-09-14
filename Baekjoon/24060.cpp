#include <iostream>
#include <climits>
using namespace std;

int cnt, k;

void merge(int num[], int s, int m, int e)
{
    int temp[e - s + 1];
    int l = s;
    int r = m + 1;

    for (int i = 0; i < e - s + 1; i++) {
        int l_min = l <= m ? num[l] : INT_MAX;
        int r_min = r <= e ? num[r] : INT_MAX;
        int min;

        if (l_min <= r_min) {
            min = l_min;
            l++;
        } else {
            min = r_min;
            r++;
        }

        temp[i] = min;
        cnt++;
        if (cnt == k) cout << min << '\n';
    }

    for (int i = s; i <= e; i++) num[i] = temp[i - s];
}

void merge_sort(int num[], int s, int e) {
    if (s >= e) return;

    int m = (s + e) / 2;
    merge_sort(num, s, m);
    merge_sort(num, m + 1, e);
    merge(num, s, m, e);
}

int main() {
    int n;
    cin >> n >> k;

    int nums[n];
    for (int i = 0; i < n; i++)  cin >> nums[i];

    merge_sort(nums, 0, n - 1);

    if (cnt < k) cout << "-1\n";
    return 0;
}