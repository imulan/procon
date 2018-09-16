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

using pi = pair<int,int>;

int main(){
    int yyyy;

    int n;
    scanf(" %d %d", &n, &yyyy);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    int m;
    scanf(" %d %d", &m, &yyyy);
    vector<int> b(m);
    rep(i,m) scanf(" %d", &b[i]);

    vector<pi> v;
    rep(i,n) v.pb({a[i],i});
    rep(i,m) v.pb({b[i],n+i});
    sort(all(v));
    int V = v.size();

    unordered_map<int,int> IDA,IDB;
    rep(i,n) IDA[a[i]] = i;
    rep(i,m) IDB[b[i]] = n+i;

    int ans = 2;
    for(int d=1; d<(1<<30); d*=2){
        int mod = 2*d;

        unordered_map<int,int> mod2id;
        int ct = 0;
        rep(i,n)if(!mod2id.count(a[i]%mod)){
            mod2id[a[i]%mod] = ct;
            ++ct;
        }
        rep(i,m)if(!mod2id.count(b[i]%mod)){
            mod2id[b[i]%mod] = ct;
            ++ct;
        }

        vector<vector<int>> aa(ct),bb(ct);
        rep(i,n) aa[ mod2id[a[i]%mod] ].pb(a[i]);
        rep(i,m) bb[ mod2id[b[i]%mod] ].pb(b[i]);

        vector<int> dp(V,1);
        rep(i,V){
            int idx = v[i].se;
            // dbg(idx);

            if(idx<n){
                int key = a[idx]%mod;
                key = mod2id[key];
                auto itr = upper_bound(all(aa[key]), a[idx]);
                if(itr != aa[key].end()){
                    assert(IDA.count(*itr));
                    int nidx = IDA[*itr];
                    dp[nidx] = max(dp[nidx], dp[idx]+1);
                }

                key = (a[idx]+d)%mod;
                if(!mod2id.count(key)) continue;
                key = mod2id[key];
                itr = lower_bound(all(bb[key]), a[idx]+d);
                if(itr != bb[key].end()){
                    assert(IDB.count(*itr));
                    int nidx = IDB[*itr];
                    dp[nidx] = max(dp[nidx], dp[idx]+1);
                }
            }
            else{
                int key = b[idx-n]%mod;
                key = mod2id[key];
                auto itr = upper_bound(all(bb[key]), b[idx-n]);
                if(itr != bb[key].end()){
                    assert(IDB.count(*itr));
                    int nidx = IDB[*itr];
                    dp[nidx] = max(dp[nidx], dp[idx]+1);
                }

                key = (b[idx-n]+d)%mod;
                if(!mod2id.count(key)) continue;
                key = mod2id[key];
                itr = lower_bound(all(aa[key]), b[idx-n]+d);
                if(itr != aa[key].end()){
                    assert(IDA.count(*itr));
                    int nidx = IDA[*itr];
                    dp[nidx] = max(dp[nidx], dp[idx]+1);
                }
            }
        }
        // dbg(dp);
        rep(i,V) ans = max(ans, dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}
