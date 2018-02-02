#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

void test(ll n, ll m, ll k){
    vector<vector<int>> f(n,vector<int>(m));
    int ct = 0;
    int M = n*m;
    rep(mask,1<<M){
        rep(i,n)rep(j,m){
            int idx = i*m+j;

            f[i][j] = -1;
            if(mask>>idx&1) f[i][j] = 1;
        }

        bool ok = true;
        rep(i,n){
            int mul = 1;
            rep(j,m) mul*=f[i][j];
            ok &= (mul==k);
        }
        rep(i,m){
            int mul = 1;
            rep(j,n) mul*=f[j][i];
            ok &= (mul==k);
        }

        if(ok){
            ++ct;
            // printf("--\n");
            // rep(i,n){
            //     rep(j,m) printf("%2d%c",f[i][j]," \n"[j==m-1]);
            // }
        }
    }
    dbg(ct);
}

const ll mod = 1e9+7;
ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

ll solve(ll n, ll m, ll k){
    if(k == -1 && n%2 + m%2 == 1) return 0;
    ll ret = mod_pow(2,n-1);
    ret = mod_pow(ret,m-1);
    return ret;
}

int main(){
    ll n,m,k;
    cin >>n >>m >>k;

    // test(n,m,k);
    cout << solve(n,m,k) << endl;
    return 0;
}
