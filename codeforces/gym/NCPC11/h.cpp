#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main(){
    int n;
    cin >>n;

    vector<int> v(n+1);
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >>v[i];
        sum += (ll)i*v[i];
    }

    if(sum>78){
        printf("impossible\n");
        return 0;
    }

    auto check =[&](int lim){
        printf(" -- CH %d\n",lim);

        vector<int> x;
        for(int i=n; i>0; --i){
            rep(j,v[i]) x.pb(i+1);
        }

        vector<int> num(15);
        for(int i=1; i<=lim; ++i) num[i+1] = 1;
        for(int i:x){
            bool found = false;
            for(int j=i; j<=lim+1; ++j){
                if(num[j]>0){
                    printf(" %d: %d\n",i,j);
                    --num[j];
                    int nj = j-i;
                    ++num[nj];

                    found = true;
                    break;
                }
            }

            if(!found) return false;
        }
        return true;
    };

    for(int i=1; i<=12; ++i){
        if(check(i)){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("impossible\n");
    return 0;
}


