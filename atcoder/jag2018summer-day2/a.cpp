#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod = 1e9+7;

int main(){
    ll x,y,z;
    cin >>x >>y >>z;

    ll loop = 17*107;
    ll n = -1;
    for(int i=0; i<loop; ++i){
        if(i%17==x && i%107==y){
            n = i;
            break;
        }
    }

    while(n%mod != z) n += loop;
    printf("%lld\n",n);
    return 0;
}
