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

#define double long double

const int MAX_V = 100;
int V; //頂点数
vector<int> G[MAX_V]; //グラフ
int match[MAX_V]; // マッチングのペア
bool used[MAX_V]; // dfsで既に調べたか

void add_edge(int u, int v){
    G[u].push_back(v); G[v].push_back(u);
}

// 増加パスの探索
bool bp_dfs(int v){
    used[v]=true;
    rep(i,G[v].size()){
        int u=G[v][i], w=match[u];
        if(w<0 || (!used[w]&&bp_dfs(w))){
            match[v]=u; match[u]=v;
            return true;
        }
    }
    return false;
}

int bipartite_matching(){
    int ret=0;
    memset(match,-1,sizeof(match));
    rep(i,V){
        if(match[i]<0){
            memset(used,0,sizeof(used));
            if(bp_dfs(i)) ++ret;
        }
    }
    return ret;
}

const int INF = 191919;
vector<int> stable_set(){
    // |最大安定集合| + |最小点カバー| = |V|
    // ""二部グラフの場合には"" |最大マッチング| = |最小点カバー|
    // |最大安定集合| = |V| - |最大マッチング|

    int num_match = bipartite_matching();
    int stable_set_size = V - num_match;

    // 距離の偶奇で二部に分ける
    vector<int> d(V,INF);
    rep(i,V)if(d[i] == INF){
        d[i] = 0;
        queue<int> que({i});
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v]){
                if(d[e] > d[v]+1){
                    d[e] = d[v]+1;
                    que.push(e);
                }
            }
        }
    }

    rep(i,V){
        for(int e:G[i]){
            if(d[i]%2 == d[e]%2) assert(false);
        }
    }

    // マッチングに使われている辺 : 偶 <- 奇
    // マッチングに使われてない辺 : 偶 -> 奇
    vector<vector<int>> dG(V);
    rep(i,V){
        for(int e:G[i]){
            if(match[i] == e){
                if(d[i]%2 == 1) dG[i].pb(e);
            }
            else{
                if(d[i]%2 == 0) dG[i].pb(e);
            }
        }
    }

    vector<bool> matched(V);
    rep(i,V)if(match[i] != -1){
        matched[i] = true;
        matched[match[i]] = true;
    }

    vector<bool> visited(V);
    queue<int> que;
    rep(i,V){
        if(!matched[i] && d[i]%2==0){
            visited[i] = true;
            que.push(i);
        }
    }
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int e:dG[v]){
            if(!visited[e]){
                visited[e] = true;
                que.push(e);
            }
        }
    }

    vector<int> ret;
    rep(i,V){
        if( (visited[i] && d[i]%2==0) || (!visited[i] && d[i]%2==1)) ret.pb(i);
    }
    // if(ret.size() != stable_set_size){
    //     dbg(ret.size());
    //     dbg(stable_set_size);
    //     assert(false);
    // }
    return ret;
}


#define X first
#define Y second
using P = pair<int,int>;

ll dist2(P a, P b){
    ll dx = a.X - b.X;
    ll dy = a.Y - b.Y;
    return dx*dx + dy*dy;
}

P READ(){
    int x,y;
    cin >>x >>y;
    return {x,y};
}

int main(){
    int n;
    ll d;
    cin >>n >>d;
    vector<P> p(n);
    rep(i,n) p[i] = READ();

    vector<int> ans({0});

    // farthest pair
    rep(i,n)rep(j,i){
        ll D = dist2(p[i],p[j]);
        if(D > d*d) continue;

        vector<int> cand;
        rep(k,n)if(k!=i && k!=j){
            if(dist2(p[i],p[k])<=D && dist2(p[j],p[k])<=D){
                cand.pb(k);
            }
        }

        int C = cand.size();
        rep(k,MAX_V) G[k].clear();
        V = C;

        rep(ci,C)rep(cj,ci){
            if(dist2(p[cand[ci]],p[cand[cj]]) > D) add_edge(ci,cj);
        }

        vector<int> tmp({i,j});
        vector<int> indices = stable_set();
        for(int idx:indices) tmp.pb(cand[idx]);

        if(ans.size() < tmp.size()) ans = tmp;
    }

    int A = ans.size();
    cout << A << "\n";
    rep(i,A) cout << ans[i]+1 << " \n"[i==A-1];
    return 0;
}
