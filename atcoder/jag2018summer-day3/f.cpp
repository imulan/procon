#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back

int N;
int A[100010];

int main(){
    cin>>N;
    ll s=0;
    rep(i,N){
        cin>>A[i];
        s^=A[i];
    }

    string ans = "Alice";
    if(s==0){
        bool odd = false;
        rep(i,N){
            if(A[i]%2==1) odd = true;
        }
        if(!odd) ans = "Bob";
    }
    else if(s==1) ans = "Bob";

    cout << ans << endl;
    return 0;
}
