#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x<<"="<<x<<endl

ll N;
vector<ll> ds;

int main(){
    cin>>N;

    ll res=0;

    for(ll i=1;i*i<=N;i++){
        if(N%i==0){
            ds.push_back(i);
            if(N/i!=i)ds.push_back(N/i);
        }
    }

    for(ll i : ds){
        if(i==1)continue;

        ll cnt=N/i; cnt--;
        res+=cnt/2;
        if(i>2)res++;
    }

    cout<<res<<endl;

    return 0;
}
