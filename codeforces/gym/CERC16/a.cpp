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

vector<string> rot180(const vector<string> &s){
    vector<string> ret(s);
    int h = s.size(), w = s[0].size();
    rep(i,h)rep(j,w) ret[h-1-i][w-1-j] = s[i][j];
    return ret;
}

vector<string> rot90(const vector<string> &s){
    int n = s.size();
    vector<string> ret(s);
    rep(i,n)rep(j,n) ret[j][n-1-i] = s[i][j];
    return ret;
}

int main(){
    int r,c;
    cin >>r >>c;
    vector<string> s(r);
    rep(i,r) cin >>s[i];

    int h=1,w=1;
    while(s[h][1] != '#') ++h;
    while(s[1][w] != '#') ++w;
    --h; --w;

    // dbg(h);dbg(w);

    set<vector<string>> ans;
    for(int y=1; y<r; y+=h+1)for(int x=1; x<c; x+=w+1){
        vector<string> t(h);
        rep(i,h) t[i] = s[y+i].substr(x,w);

        bool ok = true;
        if(ans.count(t)) ok = false;
        if(ans.count(rot180(t))) ok = false;

        if(h==w){
            vector<string> tmp = t;
            rep(i,4){
                tmp = rot90(tmp);
                if(ans.count(tmp)) ok = false;
            }
        }

        if(ok) ans.insert(t);
    }

    cout << ans.size() << endl;
    return 0;
}
