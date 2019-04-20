#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)n; ++(i))
#define all(x) (x).begin(), (x).end()

int n;
map<string,double> mp;

int main(){
    mp["pink"]=0.0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string o,w;
        double r;
        cin >> o >> w >> r;
        //cout << o << " " << w << " " << r << endl;
        if(mp.find(w)==mp.end())continue;
        if(mp.find(o)==mp.end()){
            mp[o]=mp[w]+log10(r);
        }else{
            mp[o]=max(mp[o],mp[w]+log10(r));
        }
    }
    if(mp.find("blue")==mp.end())printf("0\n");
    else{
        if(mp["blue"]>=1.0)printf("10\n");
        else printf("%.10f\n",pow(10,mp["blue"]));
    }
    return 0;
}
