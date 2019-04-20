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

const int INF = 10101010;

const int SZ = 26;
struct Trie{
    vector<array<int,SZ>> nodes;
    vector<int> tab;

    int V;
    vector<vector<int>> G;
    vector<int> d;

    Trie(){
        nodes.pb({});
        tab.pb(0);
        V = 1;
    }

    void add(string &s){
        int node_num = 0;
        for(char c:s){
           // 行き先が無いのでnodeを作成
            if(!nodes[node_num][c-'a']){
                nodes[node_num][c-'a'] = nodes.size();
                nodes.pb({});
                tab.pb(-1);
                ++V;
            }

            node_num = nodes[node_num][c-'a'];
            // printf(" %c:  --> %d \n",c,node_num);
        }

        int ed = node_num;
        node_num = 0;
        for(char c:s){
            node_num = nodes[node_num][c-'a'];

            if(tab[node_num] == -1){
                // printf(" tab[%d] = %d\n", node_num, ed);
                tab[node_num] = ed;
            }
        }
    }

    void make_graph(){
        G = vector<vector<int>>(V);
        rep(i,V){
            rep(j,SZ){
                if(nodes[i][j]){
                    int u = i, v = nodes[i][j];
                    G[u].pb(v);
                    G[v].pb(u);
                }
            }
            if(tab[i]>=0) G[i].pb(tab[i]);
        }

        d = vector<int>(V,INF);
        queue<int> que({0});
        d[0] = 0;
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

    int query(string &s){
        int n = s.size();
        int node_num = 0;
        int ret = n;
        rep(i,n){
            int nx = s[i]-'a';
            if(!nodes[node_num][nx]) break;

            node_num = nodes[node_num][nx];
            ret = min(ret, d[node_num]+(n-1-i));
        }
        return ret;
    }
};

int main(){
    cin.tie(0);ios::sync_with_stdio(false);

    Trie t;

    int n,m;
    cin >>n >>m;
    rep(i,n){
        string s;
        cin >>s;
        t.add(s);
    }

    t.make_graph();

    rep(i,m){
        string s;
        cin >>s;
        cout << t.query(s) << "\n";
    }
    return 0;
}
