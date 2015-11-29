#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


int main(){
  while (1){
    int N,T,L,B;
    cin >>N >>T >>L >>B;
    if(N==0) break;

    vector<bool> lose(N+1);
    vector<bool> back(N+1);
    //初期化
    fill(lose.begin(), lose.end(), false);
    fill(back.begin(), back.end(), false);

    for(int i=0; i<L; ++i){
      int t; cin>>t;
      lose[t]=true;
      if(t>=N-5) lose[2*N-t]=true;
    }
    for(int i=0; i<B; ++i){
      int t; cin>>t;
      back[t]=true;
      if(t>=N-5) back[2*N-t]=true;
    }

    //p[t][n]:tターン後にマスnにいる確率
    double p[101][106];

    //初期状態
    p[0][0]=1.0;
    for(int i=1; i<=105; ++i) p[0][i]=0.0;

    for(int t=1; t<=T; ++t){
      //printf("go %d turn\n", t);

      double suuuu=0.0;

      for(int n=0; n<=N+5; ++n){
        p[t][n]=0.0;

        if(n==N) p[t][n]+=p[t-1][n];

        if(lose[n]){
          int pp=1;
          double tmp=0.0;
          for(int i=t-1; i>=0; --i){
            tmp+=p[i][n]*pp;
            pp*=-1;
          }
          p[t][n] += tmp;
          //printf("%d, %d: tmp=%lf\n ",t, n, tmp);
        }

        for(int k=1; k<=6; ++k){
          if(n-k<0) break;
          if(n-k==N) continue;
          //printf("n: %d, k: %d\n", n,k);

          if(lose[n-k]){
            //printf("  go go n: %d, k: %d   ", n,k);

            int pp=1;
            double tmp2=0.0;
            for(int i=t-2; i>=0; --i){
              tmp2+=p[i][n-k]*pp;
              pp*=-1;
            }
            //printf(" tmp2=%lf\n", tmp2);

            p[t][n] +=tmp2/6.0;
          }
          else p[t][n] += p[t-1][n-k]/6.0;

        }

        //printf("p[%d][%d] = %lf\n",t, n, p[t][n]);
        suuuu += p[t][n];

        if(n>N){
          p[t][N-(n%N)] += p[t][n];
          p[t][n]=0.0;
        }
      }

      //printf("suuuu = %lf\n", suuuu);

      for(int n=1; n<N; ++n){
        if(back[n]){
          //printf("back %d\n", n);
          p[t][0]+=p[t][n];
          p[t][n]=0.0;
        }
      }

      /*
      double checksum=0.0;
      for(int n=0; n<=N; ++n){
        checksum+=p[t][n];
        printf("p[%d][%d] = %.10lf\n", t, n, p[t][n]);
      }
      printf(" ch=%.10lf\n", checksum);
      */
    }

    printf("%.10lf\n", p[T][N]);
  }
}
