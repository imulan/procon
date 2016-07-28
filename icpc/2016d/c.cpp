#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define dbg(x) cout<<#x"="<<x<<endl
#define rep1(i,n) for(int (i)=1;(i)<=(int)(n);++(i))

#define NUM 7368795

bool c[NUM];

int main()
{
    int m,n;
    while(cin>>m>>n, m|n){
        fill(c,c+NUM,true);

        for(int i=m; i<NUM; i++){
            if(c[i]){
                if(n==0){
                    cout<<i<<endl;
                    break;
                }
                for(int j=i; j<NUM; j+=i) c[j]=false;
                n--;
            }
        }

    }
    return 0;
}
