#include <iostream>
using namespace std;

int main(){
	int i=1;
	while(1){
		int x;
		cin >> x;	
	
		if(x==0) break;
	
		cout << "Case " << i << ": " << x << endl;
		++i;
	}
}