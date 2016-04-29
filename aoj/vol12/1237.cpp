#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  while(1){
    int t;
    string num;
    cin >> t >> num;
    if(t==0 && num=="0") break;

    int now=0;
    int same_ct=0;
    int small=1000000;
    vector<int> ans;

    //カットするべき数の桁数
    int len = num.size();
    //各桁の間を切るか切らないかでbitloop
    for(int i=0; i<(1<<(len-1)); ++i){
      vector<int> s;

      int st=0;
      //printf(" %2d:", i);
      for(int j=0; j<len-1; ++j){
        if(i>>j & 1){
          s.push_back(atoi(num.substr(st,j+1-st).c_str()));
          st=j+1;
        }
      }
      s.push_back(atoi(num.substr(st,len+1-st).c_str()));

      int tmp=0;
      for(int j=0; j<s.size(); ++j) tmp+=s[j];
      //printf("%5d\n", tmp);

      small = min(small, tmp);

      if(t<tmp) continue;
      if(now<tmp){
        ans.resize(s.size());
        for(int j=0; j<s.size(); ++j) ans[j]=s[j];
        now=tmp;
        same_ct=1;
      }
      else if(now==tmp) same_ct++;
    }

    //output
    if(small>t) printf("error\n");
    else if(same_ct>1) printf("rejected\n");
    else{
      printf("%d", now);
      for(int i=0; i<ans.size(); ++i) printf(" %d", ans[i]);
      printf("\n");
    }
  }
}
