#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout <<#x" = "<<((x))<<endl

const int N = 1000010;
bool prime[N];
vector<int> p;

int main(){
    fill(prime,prime+N,true);
    prime[0] = prime[1] = false;
    for(int i=2; i<N; ++i){
        if(prime[i]) for(int j=2*i; j<N; j+=i) prime[j] = false;
    }
    rep(i,N)if(prime[i]) p.pb(i);
    
    int x;
    cin >>x;

    int ct = 0;
    while(x>=4){
        auto itr = lower_bound(all(p), x);
        --itr;
        while(1){
            int b = *itr;
            int a = x-b;
            if(prime[a] && prime[b]){
                ++ct;
                x = b-a;
                break;
            }
            --itr;
        }
    }
    cout << ct << endl;
    return 0;
}

