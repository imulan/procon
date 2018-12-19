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

bool solve(){
    int n;
    scanf(" %d", &n);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    rep(i,n) a[i] %= 2;

    stack<int> s;
    rep(i,n){
        if(s.empty()) s.push(a[i]);
        else{
            int v = s.top();
            if(v==a[i]) s.pop();
            else s.push(a[i]);
        }
    }
    return s.size()<=1;
}

int main(){
    cout << (solve()?"YES":"NO") << endl;
    return 0;
}
