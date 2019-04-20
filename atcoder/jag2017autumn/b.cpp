#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()

string s;
int idx=0;
map<char, int> mp;

int func(){
    if('a'<=s[idx] && s[idx]<='z'){
        int res=mp[s[idx]];
        idx++;
        return res;
    }
    if(s[idx]=='['){
        idx++;
        int left=func();
        idx++;
        int right=func();
        idx++;
        if(max(right,left)>0 && min(left,right)==0)return max(left,right)-1;
        return -10000;
    }
}

int main()
{
    cin>>s;
    string c;
    while(cin>>c){
        int d;
        cin>>d;
        mp[c[0]]=d;
    }
    if(func()==0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
