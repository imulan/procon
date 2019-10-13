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

const int A = 26;
set<int> a[A];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);

    string s;
    int q;
    cin >>s >>q;

    int S = s.size();
    rep(i,S) a[s[i]-'a'].insert(i);
    rep(i,A) a[i].insert(S+1);

    rep(query,q){
        int t;
        cin >>t;
        if(t==1){
            int pos;
            char c;
            cin >>pos >>c;
            --pos;

            int x = s[pos]-'a';
            int y = c-'a';

            s[pos] = c;
            a[x].erase(pos);
            a[y].insert(pos);
        }
        else{
            int l,r;
            cin >>l >>r;
            --l; --r;

            int ans = 0;
            rep(i,A){
                auto itr = a[i].lower_bound(l);
                if(*itr <= r) ++ans;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
