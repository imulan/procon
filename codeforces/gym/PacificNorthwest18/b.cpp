#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll mu[10000001];
bool isprime[10000001];

int main(){
    int A,B,C,D;
    scanf("%d%d%d%d",&A,&B,&C,&D);
    A--; C--;
    repl(i,1,10000001){
        mu[i]=1; isprime[i]=true;
    }
    isprime[1]=false;
    ll res=0;
    repl(i,1,10000001){
        if(isprime[i]){
            mu[i]*=-1;
            for(int j=i*2;j<=10000000;j+=i){
                isprime[j]=false; mu[j]*=-1;
            }
            for(ll j=(ll)i*i;j<=10000000;j+=(ll)i*i){
                mu[j]=0;
            }
        }
        ll n1=(B/i)-(A/i);
        ll n2=(D/i)-(C/i);
        res+=mu[i]*n1*n2;
    }

    printf("%lld\n",res);
    
    return 0;
}

