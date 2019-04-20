#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int (i)=a;(i)<(int)b;++(i))
#define rep(i,n) for(int (i)=0;(i)<(int)n;++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x<<"="<<x<<endl

#define mod 1000000007

ll mod_pow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

ll c[70][70];
ll fac[10001],finv[10001];

ll comb(ll n,ll r){
    if(n<0||r<0||n<r)return 0;
    else return (fac[n]*finv[r]%mod)*finv[n-r]%mod;
}

int solve(){
    ll a,b,M;
    cin>>a>>b>>M;

    ll p=1;
    while(p*M<a){
        p*=M;
    }

    ll res=1;
    ll crta=a,crtb=b;
    while(p>0){
        //dbg(p);
        ll k=comb(crta/p,crtb/p);
        //dbg(crta/p); dbg(crtb/p);
        if(crta%M<crtb%M){
            res=0;
            break;
        }else (res*=k)%=mod;
        crta=crta%p;
        crtb=crtb%p;
        p/=M;
    }

    /*
    rep(i,70){
        c[i][0]=1;
        c[i][i]=1;
    }
    repl(i,1,70)repl(j,1,i){
        if((c[i-1][j-1]+c[i-1][j])%M==0){
            c[i][j]=0;
        }else{
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    rep(i,70){
        cout<<i<<" : ";
        rep(j,i+1){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return res;
}

int main(){
    fac[0]=1;
    rep(i,10000)fac[i+1]=fac[i]*(i+1)%mod;
    rep(i,10001)finv[i]=mod_pow(fac[i],mod-2);

    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
