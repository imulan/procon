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
using P = pair<pi,pi>;
using Q = pair<P,int>;

const int N = 101;
vector<int> sky[N][N];

vector<Q> query[11];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n,q,c;
    cin >>n >>q >>c;
    vector<int> x(n),y(n),s(n);
    rep(i,n){
        cin >>x[i] >>y[i] >>s[i];
        sky[y[i]][x[i]].pb(s[i]);
    }

    rep(i,q){
        int t,lx,ly,rx,ry;
        cin >>t >>lx >>ly >>rx >>ry;

        t %= c+1;
        query[t].pb({{{lx,ly},{rx,ry}}, i});
    }

    vector<int> ans(q);
    rep(T,11){
        int b[N][N]={};
        rep(i,N)rep(j,N){
            for(int k:sky[i][j]) b[i][j]+=k;
        }

        for(const auto &qq:query[T]){
            int qid = qq.se;
            pi L = qq.fi.fi, R = qq.fi.se;

            int tmp = 0;
            for(int yy=L.se; yy<=R.se; ++yy)for(int xx=L.fi; xx<=R.fi; ++xx) tmp += b[yy][xx];
            ans[qid] = tmp;
        }

        rep(i,N)rep(j,N){
            for(int &k:sky[i][j]) k = (k+1)%(c+1);
        }
    }
    rep(i,q) cout << ans[i] << endl;
    return 0;
}
