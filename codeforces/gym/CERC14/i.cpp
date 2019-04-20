#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

int n;
ll a[100005];
int t[100005];

ll gcd(ll av,ll bv){
    if(bv==0LL)return av;
    return gcd(bv,av%bv);
}

void solve(){
    scanf("%d",&n);
    ll as=0,bs=0;
    for(int i=0;i<n;i++){
        char c;
        scanf("%d %c",&a[i],&c);
        if(c=='B'){
            t[i]=0;
            as+=a[i];
        }else{
            t[i]=1;
            bs+=a[i];
        }
    }
    if(as==0LL || bs==0LL){
        printf("%lld\n",as+bs);
        return;
    }
    ll g=gcd(as,bs);
    as/=g;
    bs/=g;
    ll ac=0,bc=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(t[i]==0){
            ac+=a[i];
        }else{
            bc+=a[i];
        }
        if(t[i]==0){
            ll gd=-1;
            if(bc%bs==0LL){
                gd=bc/bs;
            }
            if(gd>=1LL && as*gd>ac-a[i] && as*gd<=ac){
                ans++;
                ac-=gd*as;
                bc-=gd*bs;
            }
        }else{
            ll gd=-1;
            if(ac%as==0LL){
                gd=ac/as;
            }
            if(gd>=1LL && bs*gd<=bc && bs*gd>bc-a[i]){
                ans++;
                ac-=gd*as;
                bc-=gd*bs;
            }
        }
    }
    printf("%d\n",ans);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        solve();
    }
    return 0;
}

