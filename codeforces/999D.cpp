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

int main(){
    int n,m;
    cin >>n >>m;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    vector<ll> c(m);
    vector<set<int>> idx(m);
    rep(i,n){
        int r = a[i]%m;
        ++c[r];
        idx[r].insert(i);
    }

    set<int> over;
    rep(i,m){
        if(c[i] > n/m) over.insert(i);
    }

    ll ans = 0;
    for(int i=m-1; i>=0; --i){
        while(c[i] < n/m){
            auto itr = over.lower_bound(i);
            if(itr==over.begin()){
                itr = over.end();
            }
            --itr;

            int j = *itr;
            auto itr2 = idx[j].begin();
            int aidx = *itr2;

            --c[a[aidx]%m];
            idx[j].erase(itr2);
            if(idx[j].size() <= n/m){
                over.erase(j);
            }

            if(j<i){
                ans += i-j;
                a[aidx] += i-j;
            }
            else{
                ans += m+i-j;
                a[aidx] += m+i-j;
            }

            assert(a[aidx]%m == i);
            ++c[a[aidx]%m];
            idx[a[aidx]%m].insert(aidx);
        }
    }



    cout << ans << endl;
    rep(i,n) cout << a[i] << " \n"[i==n-1];
    return 0;
}
