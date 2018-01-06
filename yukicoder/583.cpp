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

const int N = 500;
vector<int> G[N];

string solve(){
    int n,m;
    cin >>n >>m;

    set<int> s;
    rep(i,m){
        int u,v;
        cin >>u >>v;
        s.insert(u);
        s.insert(v);
        G[u].pb(v);
        G[v].pb(u);
    }

    int start = *s.begin();
    vector<bool> vis(n);
    queue<int> que;
    vis[start] = true;
    que.push(start);
    while(!que.empty()){
        int now=que.front();
        que.pop();
        for(int e:G[now]){
            if(!vis[e]){
                vis[e]=true;
                que.push(e);
            }
        }
    }

    int odd = 0;
    for(int i:s){
        if(!vis[i]) return "NO";
        odd += (G[i].size()%2);
    }

    return (odd==0||odd==2)?"YES":"NO";
}

int main(){
    cout << solve() << endl;
    return 0;
}
