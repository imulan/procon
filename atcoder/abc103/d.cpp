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

int main(){
    int n,m;
    cin >>n >>m;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    rep(i,m){
        int a,b;
        cin >>a >>b;
        pq.push({b,a});
    }

    int ans = 0;
    int x = 0;
    while(!pq.empty()){
        pi p = pq.top();
        pq.pop();
        if(x<=p.se){
            ++ans;
            x = p.fi;
        }
    }
    cout << ans << endl;
    return 0;
}
