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

    deque<int> e,o;
    rep(i,n){
        if(s[i] == '8') e.pb(i);
        else o.pb(i);
    }

    vector<bool> er(n,false);
    int now = n;
    int t = 0;
    while(now>11){
        if(t){
            if(!e.empty()){
                er[e.front()] = true;
                e.pop_front();
            }
            else{
                er[o.back()] = true;
                o.pop_back();
            }
        }
        else{
            if(!o.empty()){
                er[o.front()] = true;
                o.pop_front();
            }
            else{
                er[e.back()] = true;
                e.pop_back();
            }
        }

        t = !t;
        --now;
    }

    string ans = "NO";
    rep(i,n)if(!er[i]){
        if(s[i] == '8') ans = "YES";
        break;
    }
    cout << ans << "\n";
    return 0;
}
