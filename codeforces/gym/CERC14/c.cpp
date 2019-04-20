#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef long long ll;

int main(){

    ll T;
    cin>>T;
    while(T--){
        ll N;
        cin>>N;
        ll a=-1,rx=-1;
        repl(x,2,40000){
            ll p=2*N-x*x-x;
            ll q=2*x;
            if(p>=0&&p%q==0){
                a=(p/q)+1;
                rx=x;
                break;
            }
        }
        if(a==-1){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<N<<" = "<<a;
        repl(i,a+1,a+rx){
            cout<<" + "<<i;
        }
        cout<<endl;
    }

    return 0;
}

