#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, l;
vector<int> L;

int main(){
	scanf("%d %d", &n, &l);
	int t;
	for(int i=0; i<n; i++){
		scanf("%d", &t);
		L.push_back(t);
	}
	sort(L.begin(), L.end());
	float m = L[0] > l-L[n-1] ? L[0] : l-L[n-1];
	for(int i=0; i<n-1; i++){
		if(m < (float)(L[i+1] - L[i])/2)
			m = (float)(L[i+1] - L[i])/2;
	}

	printf("%lf\n", m);
}