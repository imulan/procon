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

void p(int n){
    if(n%2==1){
        cout << "NO" << endl;
        return;
    }

    vector<int> ans(n+1);

    int pw=1;
    while(pw*2<=n) pw*=2;

    while(pw>1){
        int i = 0;
        while(1){
            int idx = pw + i;
            int ridx = pw - i - 1;
            if(idx<=n && ridx>0 && ans[idx]==0 && ans[ridx]==0){
                ans[idx] = ridx;
                ans[ridx] = idx;
            }
            else break;
            ++i;
        }
        pw/=2;
    }

    cout << "YES" << endl;
    for(int i=1; i<=n; ++i) cout << ans[i] << " \n"[i==n];
}

void q(int n){
    bool ok = (n>=6);
    int pw = 2;
    while(pw<=n){
        if(pw == n) ok = false;
        pw *= 2;
    }
    if(!ok){
        cout << "NO" << endl;
        return;
    }

    vector<int> ans;
    if(n==6) ans = {0,3,6,2,5,1,4};
    else ans = {0,7,3,6,5,1,2,4};
    ans.resize(n+1);

    pw = 8;
    while(pw<n){
        for(int i=pw; i<min(pw*2-1,n); ++i) ans[i]=i+1;
        ans[min(pw*2-1,n)] = pw;
        pw *= 2;
    }

    cout << "YES" << endl;
    for(int i=1; i<=n; ++i) cout << ans[i] << " \n"[i==n];
}

int main(){
    int n;
    cin >>n;
    p(n);
    q(n);
    return 0;
}
