#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back

int n,m;
string s[100005];
int d[100005];
vector<string> vec;
vector<int> vi[100005];
int siz[1000005];

int main(){

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin >> s[i] >> d[i];
        vec.push_back(s[i]);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i=0;i<n;i++){
        int v=lower_bound(vec.begin(),vec.end(),s[i])-vec.begin();
        vi[v].push_back(d[i]);
    }
    for(int i=0;i<vec.size();i++){
        sort(vi[i].begin(),vi[i].end());
        //reverse(vi[i].begin(),vi[i].end());
    }
    scanf("%d",&m);
    int pr=-1;
    bool flag=true;
    for(int i=0;i<m;i++){
        if(!flag)break;
        string ss;
        cin >> ss;
        int v=lower_bound(vec.begin(),vec.end(),ss)-vec.begin();
        if(v==vec.size() || vec[v]!=ss){
            flag=false;
        }else{
            if(siz[v]==vi[v].size())flag=false;
            else{
                while(siz[v]<vi[v].size() && vi[v][siz[v]]<=pr){
                    siz[v]++;
                }
                if(siz[v]==vi[v].size())flag=false;
                else pr=vi[v][siz[v]++];
            }

        }
    }
    printf("%s\n",flag?"Yes":"No");
    return 0;
}
