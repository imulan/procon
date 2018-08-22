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

const int INF = 1000010000;
using pi = pair<int,int>;

int main(){
    int n,q;
    scanf(" %d %d", &n, &q);

    int ans = n;
    set<pi> s;
    rep(i,q){
        int l,r,k;
        scanf(" %d %d %d", &l, &r, &k);
        ++r;

        if(k==1){
            int L=l, R=r;

            auto il = s.lower_bound({l,INF});
            if(il != s.begin()) --il;

            if(il != s.end()){
                pi t = *il;
                if(l <= t.se) L = min(L,t.fi);
            }

            auto ir = s.lower_bound({r,INF});
            if(ir != s.begin()) --ir;

            if(ir != s.end()){
                pi t = *ir;
                if(t.fi <= r) R = max(R,t.se);
            }

            int sub = R-L;
            auto itr = s.lower_bound({l,INF});
            if(itr != s.begin()) --itr;
            while(itr != s.end()){
                pi t = *itr;
                if(r < t.fi) break;

                if(t.se < l){
                    ++itr;
                }
                else{
                    itr = s.erase(itr);
                    sub -= t.se-t.fi;
                }
            }

            ans -= sub;
            s.insert({L,R});
        }
        else{
            int add = 0;
            vector<pi> add_r;

            auto itr = s.lower_bound({l,INF});
            if(itr != s.begin()) --itr;
            while(itr != s.end()){
                pi t = *itr;
                if(r < t.fi) break;

                if(t.se < l){
                    ++itr;
                    continue;
                }

                add += t.se-t.fi;
                itr = s.erase(itr);

                if(l<=t.se){
                    if(t.fi < l){
                        add_r.pb({t.fi, l});
                        add -= l - t.fi;
                    }
                    if(r < t.se){
                        add_r.pb({r, t.se});
                        add -= t.se - r;
                    }
                }
            }

            ans += add;
            for(const auto &p:add_r) s.insert(p);
        }

        // printf("---NOW \n");
        // for(const auto &p:s) dbg(p);

        printf("%d\n", ans);
    }
    return 0;
}
