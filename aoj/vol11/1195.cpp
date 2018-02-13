#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

string s;
int n;

int ct[1000]={};

priority_queue<string> t;
priority_queue<string, vector<string>, greater<string>> h;

void ANS(){
    set<string> ans;
    while(!h.empty()){
        ans.insert(h.top());
        h.pop();
    }
    while(!t.empty()){
        ans.insert(t.top());
        t.pop();
    }
    for(string a:ans) cout << a << endl;
}

void IN(){
    h.push(s);
    if(h.size()>5) h.pop();
    t.push(s);
    if(t.size()>5) t.pop();
}

set<set<int>> num;
set<int> change;

void dfs(int x){
    if(x == n){
        num.insert(change);
        IN();
        return;
    }

    if(s[x]=='a'){
        if(ct['b']==0){
            s[x] = 'b';
            ++ct[s[x]];
            change.insert(x);
            dfs(x+1);
            change.erase(x);
            --ct[s[x]];
            s[x] = 'a';
        }

        ++ct[s[x]];
        dfs(x+1);
        --ct[s[x]];
    }
    else{
        if(ct[s[x]]>0){
            ++ct[s[x]];
            dfs(x+1);
            --ct[s[x]];
        }

        if(s[x]!='z'){
            char c = s[x]+1;
            if(ct[c]==0){
                ++s[x];
                ++ct[s[x]];
                change.insert(x);
                dfs(x+1);
                change.erase(x);
                --ct[s[x]];
                --s[x];
            }
        }
    }
}

void solve(){
    num.clear();
    change.clear();
    n = s.size();
    change.insert(-1);
    dfs(0);

    cout << num.size() << endl;
    ANS();
}

int main(){
    while(cin >>s,s!="#") solve();
    return 0;
}
