#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int a, b, c;
const double eps=1e-8;

double calc(double t){
  return (double)a*t+b*sin(c*t*M_PI);
}

int main(){
  scanf(" %d %d %d", &a, &b, &c);

  double left=0.0, right=(double)1+(100+b)/a;
  double mid, oldmid=0;

  while(1){
    mid = (left+right)/2.0;

    if(calc(mid)-100 < 0) left=mid;
    else if(calc(mid)-100 > 0) right=mid;
    else break;

    if(fabs(oldmid - mid) < eps && fabs(100-calc(mid)) < 1e-6) break;
    oldmid = mid;
  }

  printf("%.10lf\n", mid);
  //printf("f=%lf\n", calc(mid));
}
