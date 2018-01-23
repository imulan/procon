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

const int M = 1000010;
int s[M]={};

int solve(){
    int n,m,k;
    cin >>n >>m >>k;

    set<int> al;
    rep(i,n){
        int v;
        cin >>v;
        ++s[v];
        al.insert(v);
    }

    if(k==1) return n;

    int ans = 0;
    int ct = 0;
    rep(i,m) ct += s[i];

    for(int i=m; i<M; ++i){
        ct += s[i];
        ct -= s[i-m];

        while(ct>=k){
            auto itr = al.upper_bound(i);
            --itr;
            s[*itr] = 0;
            al.erase(itr);
            --ct;
            ++ans;
        }
    }

    return ans;
}

int main(){
    cout << solve() << endl;
    return 0;
}
