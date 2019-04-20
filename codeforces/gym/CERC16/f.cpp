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

int main(){
    int n;
    cin >>n;
    vector<int> p(n),q(n);
    rep(i,n){
        cin >>p[i];
        --p[i];
    }
    rep(i,n){
        cin >>q[i];
        --q[i];
    }

    auto make_cc = [&](vector<int> v, vector<int> &ch){
        ch = vector<int>(n,-1);
        rep(i,n){
            if(v[i]==-1) continue;
            ch[v[i]] = i;
        }

        vector<vector<int>> cc;
        rep(i,n)if(v[i]==-1){
            vector<int> tmp;
            int now = i;
            while(now != -1){
                tmp.pb(now);
                now = ch[now];
            }
            cc.pb(tmp);
        }
        return cc;
    };

    vector<int> cp,cq;
    vector<vector<int>> p_cc = make_cc(p,cp), q_cc = make_cc(q,cq);

    vector<int> must(n);
    rep(i,n) must[i] |= (p[i]!=q[i]);
    rep(i,n) must[i] |= (cp[i]!=cq[i]);

    int ans = 0;

    int C = p_cc.size();
    rep(i,C){
        vector<int> v = p_cc[i];
        int sz = v.size();

        int dep = -1;
        rep(j,sz){
            if(must[v[j]]) dep = j;
        }
        // dbg(v);
        // dbg(dep);
        rep(j,dep){
            p[v[j+1]] = -1;
            ++ans;
        }
    }

    rep(i,n) ans += (p[i]!=q[i]);
    cout << ans << endl;
    return 0;
}
