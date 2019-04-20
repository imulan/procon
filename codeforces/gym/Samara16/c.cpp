#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl;

int main(){
    int p;
    scanf(" %d", &p);

    vector<int> a(p,-1);
    rep(i,p){
        int idx = ((ll)i*i)%p;
        a[idx] = i;
    }
    rep(i,p) printf("%d%c", a[i], " \n"[i==p-1]);
    return 0;
}