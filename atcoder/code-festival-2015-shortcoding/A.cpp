#include <iostream>
using namespace std;

int main(){
  int n,s[100],sum=0,i;
  cin>>n;
  for(i=0;i<n;++i){
    cin>>s[i];
    sum+=s[i];
  }

  string ans;
  if(s[0]*2*n<=sum) ans="Fail";
  else ans="Pass";
  cout<<ans<<endl;
}
