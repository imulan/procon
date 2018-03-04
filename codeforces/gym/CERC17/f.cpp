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

inline ll mod_pow(ll x, ll n, ll p){
    ll ret = 1;
    while(n){
        if(n&1) (ret*=x)%=p;
        (x*=x)%=p;
        n>>=1;
    }
    return ret;
}

inline ll mod_inv(ll x, ll p){
    return mod_pow(x, p-2, p);
}

inline void ans(int x, int y){
    printf("%d %d\n",x,y);
}

inline void solve(){
    ll n,p,r;
    cin >>n >>p >>r;

    if(n>=2*p){
        if(r==0){
            ans(2,1);
            return;
        }

        ans(-1,-1);
        return;
    }

    if(n==2){
        if(r==1){
            ans(2,1);
            return;
        }
        ans(-1,-1);
        return;
    }

    if(p==2){
        if(r==0){
            ans(3,2);
            return;
        }
        else{
            if(n<=3){
                ans(2,1);
                return;
            }
            else{
                ans(-1,-1);
                return;
            }
        }
    }

    if(n>=p){
        if(r==0){
            // dbg("gogo");
            ans(2,1);
            return;
        }

        // pをいじる
        ll f = 1;
        for(int i=1; i<=n; ++i)if(i!=p) (f*=i)%=p;

        for(int i=1; i<p; ++i){
            ll t = (f*i)%p;
            if(t==r){
                ans(p,i);
                return;
            }
        }
    }
    else{
        // n<p
        if(r==0){
            ans(-1,-1);
            return;
        }

        ll f = 1;
        for(int i=1; i<=n; ++i) (f*=i)%=p;
        ll invf = mod_inv(f,p);

        for(int i=1; i<=n; ++i){
            ll val = (r*i)%p;
            (val*=invf)%=p;
            // dbg(val);

            if(1 <= val && val<i){
                ans(i,val);
                return;
            }
        }

    }

    ans(-1,-1);
    return;
}

int main(){
    solve();
    return 0;
}
