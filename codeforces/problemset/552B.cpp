#include <cstdio>
#include <iostream>
using namespace std;

int main(){
  long n;
  scanf(" %ld", &n);

  long digit=0;
  long d=n;
  while(d>0){
    d/=10;
    digit++;
  }
  //printf("digit=%ld\n", digit);

  long long ans=0;
  long long c=1;
  for(int i=1; i<digit; ++i){
    ans+=c*i*9;
    c*=10;
  }
  ans += (n-c+1)*digit;

  cout << ans <<endl;
}
