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

int calc(const vector<pi> &p, int W){
    int n = p.size();
    int mincost = p[0].fi+p[1].fi;
    if(W < mincost) return 0;

    int ret = 0;

    int idx = 0;
    priority_queue<pi> pq;
    // 1つはp[i]を買う
    for(int i=n-1; i>=0; --i){
        int rW = W - p[i].fi;
        if(rW<=0) continue;

        while(idx<n && p[idx].fi<=rW){
            pq.push({p[idx].se,idx});
            ++idx;
        }

        if(!pq.empty()){
            pi cur = pq.top();
            pq.pop();
            if(cur.se == i){
                if(!pq.empty()){
                    pi nx = pq.top();
                    assert(nx.se != i);
                    ret = max(ret, p[i].se+p[nx.se].se);
                }
            }
            else{
                ret = max(ret, p[i].se+p[cur.se].se);
            }
            pq.push(cur);
        }
    }
    return ret;
}

int main(){
    int n,c,d;
    scanf(" %d %d %d", &n, &c, &d);

    vector<pi> C,D;
    rep(i,n){
        int b,p;
        char TYPE;
        scanf(" %d %d %c", &b, &p, &TYPE);
        if(TYPE == 'C') C.pb({p,b});
        else D.pb({p,b});
    }
    sort(all(C));
    sort(all(D));

    int ans = 0;
    if(C.size()>=1 && D.size()>=1){
        int tc = 0, td = 0;
        rep(i,C.size()){
            if(C[i].fi <= c) tc = max(tc,C[i].se);
        }
        rep(i,D.size()){
            if(D[i].fi <= d) td = max(td,D[i].se);
        }

        if(tc>0 && td>0) ans = max(ans, tc+td);
    }
    if(C.size()>=2) ans = max(ans, calc(C,c));
    if(D.size()>=2) ans = max(ans, calc(D,d));

    cout << ans << endl;
    return 0;
}
