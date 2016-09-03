#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

//行列積計算
void sq(long s1[100][100], long s2[100][100], long dst[100][100], long z){
  for(long i=0; i<z; ++i){
    for(long j=0; j<z; ++j){
      dst[i][j]=0;
      for(long k=0; k<z; ++k){
        dst[i][j]^=s1[i][k]&s2[k][j];
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  long k, m;
  cin >>k >>m;

  vector<long> a(k), c(k);
  for(long i=0; i<k; ++i) scanf(" %ld", &a[i]);
  for(long i=0; i<k; ++i) scanf(" %ld", &c[i]);

  long p[31][100][100];
  for(long i=0; i<k; ++i)
  for(long j=0; j<k; ++j)
  p[0][i][j]=0;

  for(long i=0; i<k; ++i) p[0][0][i]=c[i];

  //すべてのビットに1を立てておかねばならないのが、ANDにおける単位元
  for(long i=1; i<k; ++i) p[0][i][i-1]=-1;

  //ダブリング
  for(long i=0; i<30; ++i) sq(p[i],p[i],p[i+1],k);

  long ans=0;
  if(m-k>0){
    long b=m-k;

    long aa[100][100]={0};
    bool yet=true;

    for(long i=0; i<=30; ++i){
      if((b>>i)&1){

        if(yet){
          for(long x=0; x<k; ++x)
          for(long y=0; y<k; ++y)
          aa[x][y]=p[i][x][y];

          yet=false;
        }
        else{
          long old[100][100]={0};
          for(long x=0; x<k; ++x)
          for(long y=0; y<k; ++y)
          old[x][y]=aa[x][y];

          sq(p[i],old,aa,k);
        }
      }
    }

    for(long i=0; i<k; ++i)
      ans = ans^(a[k-i-1]&aa[0][i]);

  }
  else{
    ans=a[m-1];
  }

  printf("%ld\n", ans);

  return 0;
}
