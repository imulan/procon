#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)n; ++(i))
#define all(x) (x).begin(), (x).end()

int n;
vector<ll> a,b,c;
set<ll> st;

int main(){
    cin>>n;
    rep(i,n){
        ll aa;
        cin>>aa;
        a.push_back(aa);
    }
    while(a.size()>1){
        b.clear();
        rep(i,a.size()){
            st.insert(a[i]);
            if(i<(int)a.size()-1){
                b.push_back(__gcd(a[i],a[i+1]));
            }
        }
        a.clear();
        rep(i,b.size()){
            int j=i;
            a.push_back(b[i]);
            while(j<(int)b.size()&&b[j]==b[i]){
                j++;
            }
            i=j-1;
        }
    }
    st.insert(a[0]);
    cout<<st.size()<<endl;

    return 0;
}
