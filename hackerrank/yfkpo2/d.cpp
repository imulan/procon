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
    string s;
    cin >>s;
    int n = s.size();

    vector<int> a;
    rep(i,n-1){
        if(s[i]=='|' && s[i+1]=='|') a.pb(i);
    }
    a.pb(n-1);

    vector<int> x;
    int now = 0;
    for(int i:a){
        int w = i-now+1;
        x.pb((w+1)/2);
        now = i+1;
    }

    int X = x.size();
    rep(i,X) cout << x[i] << " \n"[i==X-1];
    return 0;
}
