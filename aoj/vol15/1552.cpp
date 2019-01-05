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

    auto check = [&](int l, int r){
        if(l==r){
            if(a[l-1]<a[l] && a[l]>a[l+1]) return 3;
            if(a[l-1]>a[l] && a[l]<a[l+1]) return 4;
            return -1;
        }

        if(a[l-1]<a[l] && a[r]>a[r+1]) return 0;
        if(a[l-1]>a[l] && a[r]<a[r+1]) return 1;
        if(a[l-1]<a[l] && a[r]<a[r+1]) return 2;
        if(a[l-1]>a[l] && a[r]>a[r+1]) return 2;
        return -1;
    };

    int ct[5]={};

    int i=1;
    while(i<n-1){
        int j = i;
        while(j<n-1 && a[i]==a[j]) ++j;
        --j;

        int res = check(i,j);
        if(res != -1) ++ct[res];

        i = j+1;
    }

    rep(z,5) cout << ct[z] << " \n"[z==4];
    return 0;
}
