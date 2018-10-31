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
using P = pair<pi,int>;

const int N = 111;
const int INF = 191919;

int n;
int p[N];
vector<int> ch[N];

map<pi,P> dp[N];
P dfs(int v, int a, int b){
    if(dp[v].count({a,b})) return dp[v][{a,b}];

    if(ch[v].size() == 0){
        return {{1,1},p[v]};
    }

    int sz = ch[v].size();
    int res = -INF;
    int mn = N, mx = 0;

    do{
        int ta=a, tb=b;
        int tmn = 0, tmx = 0;
        rep(i,sz){
            P val = dfs(ch[v][i], -tb, -ta);
            int vv = -val.se;
            tmn += val.fi.fi;
            tmx += val.fi.se;
            if(vv >= tb){
                ta = vv;
                break;
            }
            if(vv > ta){
                ta = vv;
            }
        }

        res = max(res,ta);
        mn = min(mn, tmn);
        mx = max(mx, tmx);

    }while(next_permutation(all(ch[v])));

    // printf(" %d %d %d  ->   [%d,%d],  val = %d\n",v,a,b,mn,mx,res);

    P ret = {{mn,mx}, res};
    dp[v][{a,b}] = ret;
    return ret;
}

int main(){
    cin >>n;
    rep(i,n) cin >>p[i];
    rep(i,n){
        int k;
        cin >>k;
        while(k--){
            int t;
            cin >>t;
            --t;
            ch[i].pb(t);
        }
        sort(all(ch[i]));
    }

    pi ans = dfs(0,-INF,INF).fi;
    cout << ans.fi << " " << ans.se << endl;
    return 0;
}
