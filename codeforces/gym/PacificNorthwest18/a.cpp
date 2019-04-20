#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second


int K,N;
string A,B;

int main(){
    cin>>K;
    cin>>A>>B;
    N=A.size();
    int dif=0,sam=0;
    rep(i,N){
        if(A[i]==B[i])sam++;
        else dif++;
    }
    if(sam>=K){
        cout<<K+dif<<endl;
    }else{
        cout<<2*sam+dif-K<<endl;
    }
    return 0;
}

