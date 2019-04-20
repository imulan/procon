#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int A = 26;
vector<int> pos[A];

int main(){
    string s;
    cin >>s;
    int n = s.size();
    rep(i,n) pos[s[i]-'a'].pb(i);

    int Q;
    scanf(" %d", &Q);

    int now = -1;
    stack<int> pp;
    pp.push(-1);

    while(Q--){
        char o[10];
        scanf(" %s", o);
        if(o[1]=='u'){
//            push
            char c;
            scanf(" %c", &c);

            int a = c-'a';
            auto itr = upper_bound(all(pos[a]),now);

            if(itr == pos[a].end()) now = n;
            else now = *itr;

            pp.push(now);
        }
        else{
//            pop
            pp.pop();
            now = pp.top();
        }

//        printf("now %d\n",now);
        if(now<n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}