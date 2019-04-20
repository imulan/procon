#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using ps = pair<string,string>;

ps READ(){
    ps ret;
    cin >>ret.fi;
    rep(i,3){
        string dum;
        cin >>dum;
    }
    cin >>ret.se;
    return ret;
}

const int N = 200;
vector<int> G[N];
bool vis[N];

bool REACH(int u, int v){
    fill(vis,vis+N,false);
    vis[u] = true;
    queue<int> que;
    que.push(u);
    while(!que.empty()){
        int c = que.front();
        que.pop();
        for(int e:G[c]){
            if(!vis[e]){
                vis[e] = true;
                que.push(e);
            }
        }
    }
    return vis[v];
}

int main(){
    int n,m;
    cin >>n >>m;

    vector<ps> nyt(n), donald(m);
    rep(i,n) nyt[i] = READ();
    rep(i,m) donald[i] = READ();

    int V = 0;
    map<string,int> name2id;
    rep(i,n){
        for(string s:{nyt[i].fi, nyt[i].se}){
            if(!name2id.count(s)){
                name2id[s] = V;
                V++;
            }
        }
    }

    rep(i,n){
        int a = name2id[nyt[i].fi], b = name2id[nyt[i].se];
        G[a].pb(b);
//        printf(" (%d %d)",a,b);
    }

    auto check = [&](string a, string b){
        if(!name2id.count(a) || !name2id.count(b)){
            return "Pants on Fire";
        }

        int s = name2id[a], g = name2id[b];
//        printf("s g %d %d\n", s, g);

        bool f = REACH(s,g), af = REACH(g,s);
//        cout << f << " " << af << endl;
        if(f&&af) return "Pants on Fire";
        if(f) return "Fact";
        if(af) return "Alternative Fact";
        return "Pants on Fire";
    };

    rep(i,m) cout << check(donald[i].fi, donald[i].se) << endl;
    return 0;
}