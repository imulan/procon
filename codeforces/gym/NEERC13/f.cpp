#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()

void solve(istream &fin, ostream &fout){
    string str;
    vector<string> ans;
    fin >> str;
    int n;
    fin >> n;
    for(int i=0;i<n;i++){
        string s;
        fin >> s;
        bool flag=true;
        for(int j=0;j<9;j++){
            if(str[j]!='*' && str[j]!=s[j]){
                flag=false;
            }
        }
        if(flag)ans.push_back(s);
    }
    fout << ans.size() << endl;
    for(int i=0;i<ans.size();i++){
        fout << ans[i] << endl;
    }
}

int main(){
#ifdef ONLINE_JUDGE
    ifstream ifs("fraud.in");
    ofstream ofs("fraud.out");
    solve(ifs, ofs);
    ifs.close();
    ofs.close();
#else
    solve(cin, cout);
#endif
    return 0;
}