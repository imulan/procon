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

int main(){
    int n;
    cin >>n;

    vector<string> s(n);
    map<string,int> s2id;
    rep(i,n){
        cin >>s[i];
        s2id[s[i]] = i;
    }

    vector<vector<int>> G(n);
    rep(i,n){
        string name;
        int k;
        cin >>name >>k;

        int u = s2id[name];
        rep(j,k){
            string imp;
            cin >>imp;

            string t;
            while(1){
                bool last = true;
                cin >>t;
                if(t.back() == ','){
                    t = t.substr(0,t.size()-1);
                    last = false;
                }

                assert(s2id.count(t));
                int v = s2id[t];
                G[u].pb(v);

                if(last) break;
            }
        }
    }

    int sz = INF;
    vector<int> ans;
    rep(i,n){
        int tsz = INF;
        int idx = -1;

        vector<int> d(n,INF);
        vector<int> par(n,-1);

        d[i] = 0;
        queue<int> que({i});
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v]){
                if(d[e] > d[v]+1){
                    par[e] = v;
                    d[e] = d[v]+1;
                    que.push(e);
                }
                if(e == i && d[v]+1 < tsz){
                    tsz = d[v]+1;
                    idx = v;
                }
            }
        }


        if(sz > tsz){
            sz = tsz;
            vector<int> tt;
            while(idx != -1){
                tt.pb(idx);
                idx = par[idx];
            }
            ans = tt;
        }
    }

    if(sz == INF){
        cout << "SHIP IT" << '\n';
    }
    else{
        reverse(all(ans));
        rep(i,sz) cout << s[ans[i]] << " \n"[i==sz-1];
    }
    return 0;
}
