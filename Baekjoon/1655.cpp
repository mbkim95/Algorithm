#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> max_heap, min_heap;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++){
    int tmp;
    cin >> tmp;
    if(max_heap.size() <= min_heap.size()) max_heap.push(tmp);
    else min_heap.push(-tmp);

    if(!max_heap.empty() && !min_heap.empty()){
      if(max_heap.top() > -min_heap.top()){
        max_heap.push(-min_heap.top());
        min_heap.pop();
        min_heap.push(-max_heap.top());
        max_heap.pop();
      }
    }
    cout << max_heap.top() << '\n';
  }
  return 0;
}