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

const ll INF = LLONG_MAX/3;

ll dist;
int n,m;
ll s[5],d[5];

ll ans = INF;

using P = pair<ll,ll>;
using D = pair<ll,P>;

vector<P> v[5];
ll t[5];
void dfs(int mask){
    if(mask == (1<<n)-1){
        bool ok = true;

        // printf("CHECK: t : ");
        // rep(i,n) printf(" %lld", t[i]);
        // printf("\n");

        rep(i,n-1)if(t[i]>=t[i+1]) return;

        vector< vector<D> > pass_b(m+1),pass_a(m+1);

        rep(i,n){
            rep(j,m){
                pass_b[j].pb({ t[i]+d[j]*s[i],{-s[i],i} });
                pass_a[j].pb({ t[i]+d[j]*s[i],{s[i],i} });
            }
            pass_b[m].pb({ t[i]+dist*s[i],{-s[i],i} });
            pass_a[m].pb({ t[i]+dist*s[i],{s[i],i} });
        }

        rep(j,m+1){
            sort(all(pass_b[j]));
            sort(all(pass_a[j]));
        }

        vector<int> now(n);
        rep(i,n) now[i] = i;

        rep(j,m+1){
            // dbg(pass_b[j]);
            if(j<m){
                // 「ゴール地点は十分に広いため、何台の馬車が同時に到着しても構いません。」
                map<ll,int> ct;
                rep(k,n) ct[pass_b[j][k].fi]++;
                for(const auto &p:ct){
                    // 「"すこしひろいところ"がm箇所あり、そこでのみ2台まで並ぶことができ、ある馬車が別の馬車を追い抜くことが可能」
                    if(p.se>=3) ok = false;
                }
                if(!ok) break;
            }

            rep(k,n){
                int idx = pass_b[j][k].se.se;
                if(now[k] != idx) ok = false;
            }
            if(!ok) break;
            rep(k,n){
                int idx = pass_a[j][k].se.se;
                now[k] = idx;
            }
        }

        if(ok){
            ll tmp = 0;
            rep(i,n) tmp = max(tmp, t[i]+dist*s[i]);
            // printf(" !!OK : time %lld\n",tmp);
            ans = min(ans, tmp);
        }
        return;
    }

    for(int i=1; i<n; ++i)if(!(mask>>i&1)){
        for(const auto &p:v[i])if(mask>>p.fi&1){
            t[i] = t[p.fi] + p.se;
            dfs(mask|(1<<i));
            t[i] = -1;
        }
    }
}

int main(){
    cin >>dist;
    cin >>n;
    rep(i,n) cin >>s[i];
    cin >>m;
    rep(i,m) cin >>d[i];
    sort(d,d+m);

    for(int i=1; i<n; ++i){
        rep(j,i){
            if(s[j] <= s[i]){
                v[i].pb({j, i-j});
            }
            else{
                ll S = s[j]-s[i];
                rep(k,m) v[i].pb({j,S*d[k]});
                v[i].pb({j,S*dist});
            }
        }
        for(int j=i+1; j<n; ++j){
            if(s[i] <= s[j]){
                v[i].pb({j, i-j});
            }
            else{
                ll S = s[i]-s[j];
                rep(k,m) v[i].pb({j,-S*d[k]});
                v[i].pb({j,-S*dist});
            }
        }

        // dbg(v[i]);
    }

    rep(i,n) t[i] = -1;
    t[0] = 0;
    dfs(1);

    assert(ans<INF);
    cout << ans << endl;
    return 0;
}
