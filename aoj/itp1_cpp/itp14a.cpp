#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	
	cout << a/b << " " << a%b << " " << flush;
	cout << fixed << setprecision(6) << (double)a/(double)b << endl;

	return 0;
}