#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)n;++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int freq[30];
int cnt[30];

void solve(){
   memset(cnt,0,sizeof(cnt));
   memset(freq,0,sizeof(freq));
   for(int i=0;i<6;i++){
       int a;
       scanf("%d",&a);
       freq[a]++;
   }
   for(int i=1;i<=13;i++){
       cnt[freq[i]]++;
   }
   if(cnt[1]==1 && cnt[2]==1 && cnt[3]==1){
       puts("full house");
   }else if(cnt[4]>=1){
       printf("%s\n",cnt[2]>=1?"tiki pair":"tiki");
   }else if(cnt[3]>=1){
       printf("%s\n",cnt[3]>=2?"two triples":"one triple");
   }else{
       if(cnt[2]==3)puts("three pairs");
       if(cnt[2]==2)puts("two pairs");
       if(cnt[2]==1)puts("one pair");
       if(cnt[2]==0)puts("single");
   }
}

int main(){
    int T;
    cin >>T;
    while(T--)solve();
    return 0;
}
