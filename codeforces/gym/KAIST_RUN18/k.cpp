#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];
    
    int ans = 2;
    rep(i,n-1){
        int flg = 1;
        if(a[i] < a[i+1]) flg = -1;
        
        int j=i+1;
        while(j+1<n){
            if( (a[j-1]<=a[j] && a[j]<=a[j+1]) || (a[j-1]>=a[j] && a[j]>=a[j+1]) ) break;
            ++j;    
        }
        
        ans = max(ans, j-i+1);
    }
    
    
    cout << ans << endl;
    return 0;
}
