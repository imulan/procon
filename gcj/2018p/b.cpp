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

using pi = pair<int,int>;

void solve(){
    int n;
    cin >>n;

    priority_queue<pi> pq;
    int s = 0;
    rep(i,n){
        int p;
        cin >>p;
        s += p;
        if(p!=0) pq.push({p,i});
    }

    vector<string> ans;
    if(s%2==1){
        pi t = pq.top();
        pq.pop();

        ans.pb(string(1,'A'+t.se));
        --t.fi;
        if(t.fi>0) pq.push(t);

        --s;
    }

    while(s>0){
        string add = "";
        rep(i,2){
            pi t = pq.top();
            pq.pop();

            add += ('A'+t.se);
            --t.fi;
            if(t.fi>0) pq.push(t);
        }
        ans.pb(add);
        s -= 2;
    }

    for(string x:ans) cout << " " << x;
}

int main(){
    int T;
    cin >>T;
    rep(i,T){
        printf("Case #%d:", i+1);
        solve();
        printf("\n");
    }
    return 0;
}
