#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)n; ++(i))
#define all(x) (x).begin(), (x).end()

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int n;
ll a[500005];
set<ll> used[500005];
set<ll> ans;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n;i++){
        ll val=a[i];
        if(used[i].find(val)!=used[i].end()){
            used[i].clear();
            continue;
        }
        used[i].clear();
        ans.insert(val);
        for(int j=i+1;j<n;j++){
            val=gcd(val,a[j]);
            if(used[j].find(val)!=used[j].end())break;
            ans.insert(val);
            if(val==1LL)break;
            used[j].insert(val);
        }
    }
    printf("%d\n",ans.size());
    return 0;
}
