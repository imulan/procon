#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;
  vector<int> a(n);
  for(int i=0; i<n; ++i) cin >>a[i];

  sort(a.begin(), a.end(), greater<int>());

  int ans=0;
  for(int i=0; i<n; i+=2) ans+=a[i];

  cout << ans << endl;
  return 0;
}
