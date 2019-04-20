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
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];
    sort(all(a));

    auto check = [&](int x){
        multiset<int> s;
        for(int i:a) s.insert(i);

        while(!s.empty()){
            auto p = s.begin();
            int need = x - (*p);

            s.erase(p);
            auto q = s.lower_bound(need);

            if(q == s.end()) return false;
            s.erase(q);
        }
        return true;
    };

    int ok = 1, ng = 2222222;
    while(ng-ok>1){
        int mid = (ok+ng)/2;
        // dbg(mid);

        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}
