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

int main(){
    int n;
    string s;
    cin >>n >>s;

    int ct[3]={};
    rep(i,n) ++ct[s[i]-'0'];

    int t = n/3;

    auto upd = [&](int idx, int v){
        int u = s[idx]-'0';
        if(ct[u]>t && ct[v]<t){
            --ct[u];
            ++ct[v];
            s[idx] = v+'0';
        }
    };

    rep(i,n) upd(i,0);
    for(int i=n-1; i>=0; --i) upd(i,2);

    for(int i=n-1; i>=0; --i)if(s[i]=='0') upd(i,1);
    rep(i,n)if(s[i]=='2') upd(i,1);

    cout << s << "\n";
    return 0;
}
