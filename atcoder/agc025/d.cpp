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

const int N = 600*600;
set<int> G[N];

vector<pi> solve(){
    int n,D[2];
    cin >>n;
    rep(i,2) cin >>D[i];

    vector<pi> aa[2];
    rep(i,2*n)rep(j,2*n){
        int dist = i*i + j*j;
        rep(k,2)if(dist == D[k]) aa[k].pb({i,j});
    }

    auto ID = [&](int y, int x){
        return 2*n*y + x;
    };

    auto IN = [&](int y, int x){
        return 0<=y && y<2*n && 0<=x && x<2*n;
    };

    int V = 2*n*2*n;
    vector<int> X(V);

    rep(AA,2){
        rep(i,N) G[i].clear();

        rep(i,2*n)rep(j,2*n){
            for(pi a:aa[AA]){
                for(int p=-1; p<=1; p+=2)for(int q=-1; q<=1; q+=2){
                    int y = i+a.fi*p, x = j+a.se*q;
                    if(IN(x,y)) G[ID(i,j)].insert(ID(y,x));
                }
            }
        }

        const int INF = 19191919;
        vector<int> d(V, INF);
        rep(i,V)if(d[i]==INF){
            vector<int> cc;
            queue<int> que;

            d[i] = 0;
            cc.pb(i);
            que.push(i);
            while(!que.empty()){
                int now = que.front();
                que.pop();
                for(int nx:G[now]){
                    if(d[nx] > d[now]+1){
                        d[nx] = d[now]+1;
                        cc.pb(nx);
                        que.push(nx);
                    }
                }
            }

            for(int j:cc){
                if(d[j]%2==1) X[j] |= (1<<AA);
            }
        }
    }

    int ct[4]={};
    rep(i,V) ++ct[X[i]];

    int idx = -1;
    rep(i,4)if(ct[i]>=n*n) idx = i;
    assert(idx != -1);

    vector<pi> ans;
    rep(i,V) if(X[i]==idx) ans.pb({i/(2*n), i%(2*n)});
    ans.resize(n*n);
    return ans;
}

int main(){
    vector<pi> ans = solve();
    for(const auto &p:ans) printf("%d %d\n", p.fi, p.se);
    return 0;
}
