#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pb push_back

ll solve(){
    ll a,b,c,la,lb;
    cin >>a >>b >>c >>la >>lb;

    ll min_limit = min(la,lb);

    ll ret = a+b+c;
    if(c+a > la) ret = min(ret, la);
    if(c+b > lb) ret = min(ret, lb);

    return ret;
}

int main(){
    cout << solve() << "\n";
    return 0;
}