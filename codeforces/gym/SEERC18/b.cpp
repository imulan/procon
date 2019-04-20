#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

/*
__int128 extgcd(__int128 a,__int128 b,__int128& x,__int128& y){
    __int128 d=a;
    if(b!=0LL){
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }else{
        x=1;
        y=0;
    }
    return d;
}

__int128 mod_inverse(__int128 a,__int128 m){
    __int128 x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
*/

ll a[3],n;
int ord[3];
set<vector<ll>> vi;

const ll inv_3 = 12297829382473034411ULL;

int main(){
    cin >> a[0] >> a[1] >> a[2] >> n;
    for(int i=0;i<3;i++){
        ord[i]=i;
    }
    int flag=0;
    if(a[0]==a[1] && a[0]==a[2])flag=2;
    else{
        if(a[0]==a[1] || a[0]==a[2] || a[1]==a[2])flag=1;
    }
   // ll inv_3=mod_inverse(3LL,(__int128)1LL<<64);
   // cout << inv_3 << endl;
   // cout << inv_3*3LL << endl;
    assert(inv_3*3LL==1LL);
   // ll inv_2=mod_inverse(2LL,(__int128)1LL<<64);
    ll ans=0;
    do{
        vector<ll> vec;
        for(int i=0;i<3;i++){
            vec.push_back(a[ord[i]]);
        }
        if(vi.find(vec)!=vi.end())continue;
        vi.insert(vec);
        ll val;
        if(n%2==0){
            val=(n/2LL+1LL)*(n/2LL)/2LL;
            val+=n/2LL-2LL;
        }else{
            val=((n-1LL)/2LL)*((n-1LL)/2LL+1LL)/2LL;
        }
        ans+=val;
    }while(next_permutation(ord,ord+3));
    if(flag>=0)ans*=inv_3*n;
    cout << ans << endl;
    return 0;
}
