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

int main(){
    int n;
    string s;
    cin >>n >>s;

    vector<int> pos[A];
    rep(i,n) pos[s[i]-'a'].pb(i);

    rep(j,A)rep(i,j){
        if(pos[i].empty() || pos[j].empty()) continue;

        int x = pos[i].back(), y = pos[j].front();
        if(x>y){
            cout << "YES\n" << y+1 << " " << x+1 << "\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
