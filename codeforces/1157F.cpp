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

const int N = 200002;
int ct[N];

int main(){
    int n;
    scanf(" %d", &n);
    rep(i,n){
        int a;
        scanf(" %d", &a);
        ++ct[a];
    }

    vector<int> ans;
    // 1
    rep(i,N)if(ct[i]>0){
        ans.pb(i);
        break;
    }

    // 2
    rep(i,N-1)if(ct[i]>0 && ct[i+1]>0){
        ans.clear();
        ans.pb(i);
        ans.pb(i+1);
        break;
    }

    int s = 0;
    while(s<N){
        if(ct[s]>=2){
            int r = s;
            while(ct[r]>=2) ++r;
            --r;

            vector<int> t;
            t.pb(s);
            if(ct[s-1]>0) t.pb(s-1);
            for(int i=s; i<=r; ++i) t.pb(i);
            if(ct[r+1]>0) t.pb(r+1);
            for(int i=r; i>=s; --i){
                int sub = 1;
                if(i==s) sub = 2;
                rep(j,ct[i]-sub) t.pb(i);
            }

            if(t.size() > ans.size()) ans = t;
            s = r+1;
        }
        else ++s;
    }

    int A = ans.size();
    printf("%d\n", A);
    rep(i,A) printf("%d%c", ans[i], " \n"[i==A-1]);
    return 0;
}
