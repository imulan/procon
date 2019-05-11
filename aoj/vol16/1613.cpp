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

vector<set<int>> G;
map<vector<int>,int> h2id;

int tree_hash(int v, int par){
    vector<int> hs;
    for(int ch:G[v])if(ch!=par){
        hs.pb(tree_hash(ch,v));
    }
    sort(all(hs));

    if(!h2id.count(hs)) h2id[hs] = h2id.size();
    return h2id[hs];
}

const int D[2] = {4,8};
const int dx[2][8]={
    {1,0,-1,0},
    {1,0,-1,0,1,-1,-1,1}
};
const int dy[2][8]={
    {0,-1,0,1},
    {0,-1,0,1,-1,-1,1,1}
};

int CALC(int h, int w){
    vector<string> p(h+2, string(w+2,'.'));
    rep(i,h)rep(j,w) cin >>p[i+1][j+1];

    h += 2;
    w += 2;

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    vector<vector<int>> f(h,vector<int>(w,-1));
    int idx = 0;
    rep(i,h)rep(j,w)if(f[i][j] == -1){
        char color = p[i][j];
        int b = color=='#';

        f[i][j] = idx;
        queue<pi> que({{i,j}});
        while(!que.empty()){
            pi now = que.front();
            que.pop();
            rep(d,D[b]){
                int ny = now.fi+dy[b][d], nx = now.se+dx[b][d];
                if(IN(ny,nx) && f[ny][nx]==-1 && p[ny][nx]==color){
                    f[ny][nx] = idx;
                    que.push({ny,nx});
                }
            }
        }

        ++idx;
    }

    G.clear();
    G.resize(idx);
    rep(i,h)rep(j,w){
        rep(d,D[0]){
            int ny = i+dy[0][d], nx = j+dx[0][d];
            if(IN(ny,nx)){
                int u = f[i][j], v = f[ny][nx];
                if(u!=v){
                    G[u].insert(v);
                    G[v].insert(u);
                }
            }
        }
    }

    return tree_hash(0,-1);
}

int main(){
    int h,w;
    while(cin >>h >>w,h){
        h2id.clear();
        int t1 = CALC(h,w);
        cin >>h >>w;
        int t2 = CALC(h,w);
        cout << (t1==t2?"yes":"no") << "\n";
    }
    return 0;
}
