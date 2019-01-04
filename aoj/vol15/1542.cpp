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

const int N = 100000;
vector<int> G[N];

int main(){
    int n,m;
    cin >>n >>m;
    vector<char> a(n);
    rep(i,n) cin >>a[i];
    rep(i,m){
        int u,v;
        cin >>u >>v;
        G[u].pb(v);
        G[v].pb(u);
    }

    rep(i,n){
        if(a[i]=='?'){
            vector<bool> used(26);
            for(int j:G[i]){
                if(a[j]!='?') used[a[j]-'a'] = true;
            }

            a[i] = 'a';
            while(used[a[i]-'a']) ++a[i];
        }
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
