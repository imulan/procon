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

vector<string> split(const string &str, char sep){
    vector<string> v;
    stringstream ss(str + sep);
    string buffer;
    while( getline(ss,buffer,sep ) ) v.pb(buffer);
    return v;
}

set<int> cv(const string &str){
    vector<string> t = split(str, ':');
    set<int> ret;
    for(const auto &x:split(t[1], ',')){
        ret.insert(atoi(x.c_str())-1);
    }
    return ret;
}

const int N = 1000;
vector<int> G[N];

void solve(){
    int n;
    cin >>n;

    int e_sum = 0;
    vector<vector<set<int>>> r(n);
    vector<vector<int>> idx(n,vector<int>(n,-1));
    rep(i,n){
        string s;
        cin >>s;
        for(string t:split(s, '-')) r[i].pb(cv(t));

        rep(j,r[i].size()){
            for(int v:r[i][j]) idx[i][v] = j;
        }
        e_sum += r[i].size();
    }

    if(e_sum != 2*(n-1)){
        cout << "-1" << endl;
        return;
    }

    int edge = 0;
    rep(i,n)rep(j,i){
        if(r[i][idx[i][j]].size() + r[j][idx[j][i]].size() == n){
            ++edge;
            G[i].pb(j);
            G[j].pb(i);
        }
    }

    vector<bool> vis(n);
    vis[0]=true;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(int e:G[now]){
            if(!vis[e]){
                vis[e] = true;
                que.push(e);
            }
        }
    }

    bool connected = true;
    rep(i,n)if(!vis[i]) connected = false;

    if(!connected || edge != n-1){
        cout << "-1" << endl;
        return;
    }
    cout << n-1 << endl;
    rep(i,n){
        for(int j:G[i])if(i<j) cout << i+1 << " " << j+1 << endl;
    }
}

int main(){
    solve();
    return 0;
}
