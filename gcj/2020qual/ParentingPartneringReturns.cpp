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

using pi = pair<int,int>;
using P = pair<pi,int>;

string solve(){
    int n;
    cin >>n;

    priority_queue<P, vector<P>, greater<P>> pq;
    rep(i,n){
        int s,e;
        cin >>s >>e;
        pq.push({{s,e},i});
    }

    int x = 0, y = 0;
    string ans(n,'?');
    while(!pq.empty()){
        P a = pq.top();
        pq.pop();

        int s = a.fi.fi, e = a.fi.se, idx = a.se;
        if(x <= s){
            x = e;
            ans[idx] = 'C';
        }
        else if(y <= s){
            y = e;
            ans[idx] = 'J';
        }
        else return "IMPOSSIBLE";
    }
    return ans;
}

int main(){
    int T;
    scanf(" %d", &T);
    rep(i,T){
        printf("Case #%d: ", i+1);
        cout << solve() << "\n";
    }
    return 0;
}
