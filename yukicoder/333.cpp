#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  long a,b;
  cin >>a >>b;

  long l=1, r=2*1e9;
  long ans=0;

  if(a<b){ //bが2番目に来てはいけない->最大
    ans=b-l-1;
  }
  else{ //bが2番目に来てはいけない->最小
    ans=r-b-1;
  }

  printf("%ld\n", ans);
  return 0;
}
