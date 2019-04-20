#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct SegTree{
    int n;
    vector<vector<int>> dat;
       
    SegTree(int _n){
        n = 1;
        while(n<_n) n*=2;
        dat = vector<vector<int>>(2*n-1);
    }
    
    void init(const vector<int> &x, const vector<int> &y){
        
    }
    
};

using pi = pair<int,int>;

int main(){
    int n,m;
    ll L;
    scanf(" %d %d %lld", &n, &m, &L);
       
    vector<ll> x(n),y(n);
    
    vector<ll> ADD,SUB;
    rep(i,n){
        scanf(" %lld %lld", &x[i], &y[i]);
        
        if(y[i]<=L){
            ll ad = y[i]+x[i]-L;
            ADD.pb(ad);
            
            ll sb = L-y[i]+x[i];
            SUB.pb(sb);            
        }
    }
    sort(all(ADD));
    sort(all(SUB));
    
    vector<pi> f(m);
    rep(i,m){
        scanf(" %d", &f[i].fi);
        f[i].se = i;
    }
    sort(all(f));
    
    int aidx = 0, sidx = 0;
    int A = ADD.size(), S = SUB.size();
    /*
    rep(i,A) printf( " %lld",ADD[i]);
    puts("");
    rep(i,S) printf( " %lld",SUB[i]);
    puts("");
    */
    
    vector<int> ans(m);
    int ct = 0;
    rep(i,m){
        int a = f[i].fi;
        int idx = f[i].se;
//        printf(" %d, %d\n",a,idx);
        
        while(aidx<A && ADD[aidx]<=a){
            //printf("  + %lld\n",ADD[aidx]);
            ++aidx;
            ++ct;
        }
        while(sidx<S && SUB[sidx]<a){
            //printf("  - %lld\n",SUB[sidx]);
            ++sidx;
            --ct;
        }
        
        ans[idx] = ct;    
    }

    rep(i,m) printf("%d\n", ans[i]);
    return 0;
}
