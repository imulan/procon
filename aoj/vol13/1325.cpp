#include <cstdio>
#include <iostream>
using namespace std;

int ab(int x){
  return (x>0)?x:-x;
}

int main(){
  int tt;
  cin >> tt;
  for(int times=0; times<tt; ++times){
    int m,n;
    cin >>m >>n;

    int sqsum=m*m+n*n;
    //printf("sqsum=%d\n", sqsum);

    bool prime=true;
    for(int i=-141; i<=141; ++i){
      for(int j=-141; j<=141; ++j){
        if( (i==0&&j==0) || (ab(i)==1&&j==0) || (i==0&&ab(j)==1) || (i==m&&j==n)|| (i==-n&&j==m)|| (i==-m&&j==-n)|| (i==n&&j==-m)  ) continue;

        int tmp=i*i+j*j;

        if(sqsum%(i*i+j*j)==0 && ((i*m+j*n)%tmp==0)&&((i*n-j*m)%tmp==0)){
          prime=false;
          //printf("i=%d, j=%d\n", i, j);
          break;
        }
      }
      if(!prime) break;
    }

    if(prime) printf("P\n");
    else printf("C\n");

  }
}
