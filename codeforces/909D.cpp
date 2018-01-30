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

using P = pair<char,int>;

vector<P> process(const vector<P> &v, int t){
    vector<P> nv(v);
    int V = v.size();

    rep(i,V){
        if(i==0 || i==V-1){
            nv[i].se -= t;
        }
        else{
            nv[i].se = max(0, nv[i].se-2*t);
        }
    }

    vector<P> ret;
    rep(i,V){
        if(nv[i].se>0){
            if(ret.size()==0) ret.pb(nv[i]);
            else{
                if(ret.back().fi == nv[i].fi) ret.back().se += nv[i].se;
                else ret.pb(nv[i]);
            }
        }
    }
    return ret;
}

int main(){
    string s;
    cin >>s;

    int n = s.size();

    vector<P> v;
    int st = 0;
    while(st<n){
        int idx = st;
        while(idx<n && s[idx]==s[st]) ++idx;
        v.pb({s[st],idx-st});
        st = idx;
    }

    int ans = 0;
    while(v.size()>1){
        int V = v.size();

        vector<int> life(V);
        rep(i,V) life[i] = v[i].se;
        for(int i=1; i<V-1; ++i) life[i] = (life[i]+1)/2;

        int turn = 19191919;
        rep(i,V) turn = min(turn,life[i]);

        v = process(v,turn);
        ans += turn;
    }
    cout << ans << endl;
    return 0;
}
