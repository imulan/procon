#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define repl(i,a,b) for(int (i)=a;(i)<(int)(b);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x<<"="<<x<<endl

#define mod 1000000007

vector<int> z_algo(const string& S){
    const int n=S.size();
    vector<int> A(n);
    A[0]=n;
    int i=1,j=0;
    while(i<n){
        while(i+j<n && S[j]==S[i+j]) ++j;
        A[i]=j;
        if(j==0){ ++i; continue; }
        int k=1;
        while(i+k<n && k+A[k]<j) A[i+k]=A[k],++k;
        i+=k; j-=k;
    }
    return A;
}

ll mod_pow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1LL;
    }
    return res;
}

int main(){
    string S;
    int N;
    cin>>S;
    N=S.size();

    vector<int> Z=z_algo(S);
    vector<int> imos(N+1,0);

    repl(i,1,N){
        imos[i]++;
        imos[i+Z[i]]--;
    }
    rep(i,N)imos[i+1]+=imos[i];

    ll res=0;
    rep(i,N){
        if(imos[i]>0)continue;
        (res+=mod_pow(26,N-1-i))%=mod;
    }
    cout<<(mod_pow(26,N)-res+mod)%mod<<endl;
    return 0;
}
