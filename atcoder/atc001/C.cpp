//??????

//FFT

#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
using namespace std;

const int N=100001;

void dft(double *f, int n){
	if(n==1) return;
	
	int f0[N]={0}, f1[N]={0};
	for(int i=1; i<=n/2; ++i){
		f0[i]=f[2*i+0];
		f1[i]=f[2*i+1];
	}
	
	dft(f0, n/2);
	dft(f1, n/2);
	
	complex<double> zeta = complex<double>(cos(2*M_PI/n), sin(2*M_PI/n) );
	complex<double> pow_zeta = complex<double>(1,0);
	for(int i=1; i<=n; ++i){
		
		f[i] = f0[i%(n/2)] + pow_zeta*f1[	
		
	}
	
}

int main(){
	int n;
	int a[N]={0}, b[N]={0};
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i) scanf(" %d %d", &a[i], &b[i]);
	
	int p=1;
	while(p<=2*n) p*=2; //ここで2の累乗数を選択
	
	//次にaとbをそれぞれDFTする
	dft(a,p);
	dft(b,p);
	
	
	
	
}