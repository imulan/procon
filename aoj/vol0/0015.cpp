#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main() {
	int tcase;
   
	cin >> tcase;
  	while(tcase--) {
    	string A, B, C = "";
   		cin >> A >> B;
     
    	unsigned sz = max(A.size(), B.size());
    	while(A.size()<sz) A = '0' + A;
    	while(B.size()<sz) B = '0' + B;
 
    	int c = 0;
    	for(int i=sz-1; i>=0; i--) {
      	//answer
      	C += (( (A[i]-'0') + (B[i]-'0') + c ) % 10 + '0');
      	//carry
      	c = ( (A[i]-'0') + (B[i]-'0') + c ) / 10;
    	}
    	if(c>0) C += (c + '0');
     
    	reverse(C.begin(), C.end());
    	if(C.size() > 80) cout << "overflow" << endl;
    	else cout << C << endl;
  	}
  	return 0;
}