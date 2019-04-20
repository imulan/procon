#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define pb push_back

const int N = 200002;

int s[N];
vector<int> G[N];
int nx[N];
bool cycle[N];

void dfs(int x){
    // printf("DFS %d\n", x+1);
    s[x] = 1;
    for(int e:G[x])if(!cycle[e] && e!=nx[x]){
        dfs(e);
        if(s[e]==1) s[x] = 0;
    }
    // printf(" s[%d] %d\n",x+1,s[x] );
}

int main(){
    memset(s,-1,sizeof(s));

    int n;
    cin >>n;

    int sz = 2*n;
    vector<int> indeg(sz);
    rep(i,sz){
        cin >>nx[i];
        --nx[i];
        ++indeg[nx[i]];

        G[i].pb(nx[i]);
        G[nx[i]].pb(i);
    }

    vector<bool> vis(sz);
    rep(i,sz){
        if(vis[i]) continue;

        vector<int> cc;
        queue<int> que;
        vis[i] = true;
        que.push(i);
        cc.pb(i);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v]){
                if(!vis[e]){
                    vis[e] = true;
                    que.push(e);
                    cc.pb(e);
                }
            }
        }

        bool leaf = false;
        for(int v:cc)if(G[v].size()==1) leaf = true;
        if(leaf){
            int start = 0;
            for(int v:cc)if(G[v].size()==1) start = v;

            set<int> ss;
            vector<int> ord;
            int now = start;
            while(!ss.count(now)){
                ord.push_back(now);
                ss.insert(now);
                now = nx[now];
            }

            int O = ord.size();
            int idx = 0;
            while(ord[idx] != now) ++idx;

            vector<int> vv;
            for(int j=idx; j<O; ++j){
                cycle[ord[j]]=true;
                vv.pb(ord[j]);
            }

            int VV = vv.size();
            int iii = 0;
            rep(j,VV){
                // printf(" j %d\n", vv[j]+1);
                dfs(vv[j]);
                if(s[vv[j]]==1) s[vv[j]]=-1;
                else iii=j;
            }

            // printf(" iii %d\n",vv[iii]);
            if(s[vv[iii]]==-1){
                s[vv[iii]] = 1;
            }

            for(int j=1; j<VV; ++j){
                if(s[vv[(iii+j)%VV]]==-1) s[vv[(iii+j)%VV]] = !s[vv[(iii+j-1+VV)%VV]];
            }
        }
        else{
            for(int v:cc){
                assert(G[v].size()==2);
                s[v] = (v<n);
            }
        }
    }

    rep(i,sz)if(s[i]==-1) s[i]=1;

    vector<int> ans;
    rep(i,sz)if(s[i]==1) ans.push_back(i+1);

    int A = ans.size();
    rep(i,A) cout << ans[i] << " \n"[i==A-1];
    return 0;
}
