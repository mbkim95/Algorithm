#include<iostream>
using namespace std;
long long pair1(long long a)
{
    return ((a*(a-1))/2);
}
int main()
{
    int n,m;
    cin>>n>>m;
    long long min,max,n1,p1,n2,p2;
    n1=n%m;
    n2=m-n1;
    p1=n/m;
    p2=p1+1;
    min=n1*(pair1(p2))+n2*(pair1(p1));
    long long s;
    s=n-(m-1);
    max=pair1(s);
    cout<<min<<" "<<max<<endl;

}
