#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)n;++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int solve(){
    ll n;
    vector<ll> a,b;
    cin>>n;
    a.resize(n); b.resize(n);
    rep(i,n)cin>>a[i]>>b[i];

    vector<ll> ds;
    rep(i,n){
        ds.push_back(a[i]);
        ds.push_back(b[i]);
    }
    sort(all(ds));
    unique(all(ds));

    rep(i,n){
        a[i]=lower_bound(all(ds),a[i])-ds.begin();
        b[i]=lower_bound(all(ds),b[i])-ds.begin();
    }

    vector<ll> imos(3*n+10,0);
    rep(i,n){
        imos[a[i]]++;
        imos[b[i]+1]--;
    }
    rep(i,imos.size()-1)imos[i+1]+=imos[i];

    return *max_element(all(imos));
}

int main(){
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
