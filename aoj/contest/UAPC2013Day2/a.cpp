#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n=1000;

int main(){
    rep(i,n){
        string s;
        cin>>s;
        int m=s.size();
        bool ok=true;
        rep(j,m-1){
            int i1=(s[j]-'A')/3;
            int j1=(s[j]-'A')%3;
            int i2=(s[j+1]-'A')/3;
            int j2=(s[j+1]-'A')%3;
            if(!((i1==i2&&min(j1,j2)+1==max(j1,j2))||(min(i1,i2)+1==max(i1,i2)&&j1==j2)))ok=false;
        }
        if(ok)cout<<s<<endl;
    }

    return 0;
}
