#include <vector>
long long sum(std::vector<int> &a){
    long long ret = 0;
    for(long long num : a) ret += num;
    return ret;
}
