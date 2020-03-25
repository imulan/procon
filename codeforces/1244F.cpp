#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

string f(const string &s){
    int n = s.size();
    string ret(n,'B');

    rep(i,n){
        int w = 0;
        for(int j=-1; j<=1; ++j){
            int idx = (i+j+n)%n;
            if(s[idx]=='W') ++w;
        }
        if(w>=2) ret[i] = 'W';
    }
    return ret;
}

void test(int n, int k, string s){
    rep(i,10){
        s = f(s);
        dbg(s);
    }
}

const int INF = 19191919;

int main(){
    int n,k;
    string s;
    cin >>n >>k >>s;

    // test(n,k,s);

    auto calc_d = [&](char c){
        vector<int> d(n,INF);
        queue<int> que;

        rep(i,n){
            int ct = 0;
            for(int j:{-1,1}){
                int idx = (i+j+n)%n;
                if(s[idx]==c) ++ct;
            }

            if(s[i]==c && ct>0){
                que.push(i);
                d[i] = 0;
            }
        }

        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int i:{-1,1}){
                int nx = (v+i+n)%n;
                if(d[nx] > d[v]+1){
                    d[nx] = d[v]+1;
                    que.push(nx);
                }
            }
        }

        return d;
    };

    vector<int> db = calc_d('B'), dw = calc_d('W');
    string ans(n,'?');

    if(db[0]==INF && dw[0]==INF){
        ans = s;
        if(k%2 == 1) reverse(all(ans));
    }
    else{
        rep(i,n){
            if(db[i] < dw[i]){
                if(db[i]<=k) ans[i] = 'B';
            }
            else{
                if(dw[i]<=k) ans[i] = 'W';
            }
        }

        for(int i=1; i<n; ++i)if(ans[i]=='?'){
            if(ans[i-1]=='B') ans[i] = 'W';
            if(ans[i-1]=='W') ans[i] = 'B';
        }
        for(int i=n-2; i>=0; --i)if(ans[i]=='?'){
            if(ans[i+1]=='B') ans[i] = 'W';
            if(ans[i+1]=='W') ans[i] = 'B';
        }
    }

    cout << ans << "\n";
    return 0;
}
