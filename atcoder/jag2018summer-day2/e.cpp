#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define repl(i,a,b) for(int (i)=a;(i)<(int)(b);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x<<"="<<x<<endl

string s;

int main(){
    cin >> s;
    int n=s.size();
    int ans=0;
    for(int i=1;i<n;i++){
        int val=0;
        for(int j=0;j<n;j+=i){
            if(s[j]=='0')break;
            val++;
        }
        ans=max(ans,val);
    }
    vector<int> vec;
    if(ans<=3 && ans>=1){
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                vec.push_back(i);
            }
        }
        for(int i=1;i+1<min((int)vec.size(),6000);i++){
            if(vec[i]*2>=n)break;
            for(int j=i+1;j<vec.size();j++){
                int va=vec[i]+vec[j];
                if(va<n && s[va]=='1'){
                    ans=4;
                    break;
                }
                if(va>=n)break;
            }
            if(ans==4)break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
