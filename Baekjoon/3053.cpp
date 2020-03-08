#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);

int main() {
	double r;
	scanf("%lf", &r);
	printf("%.6lf\n", r * r * PI);
	printf("%.6lf\n", r * r * 2);
	return 0;
}