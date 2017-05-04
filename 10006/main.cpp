#include <iostream>
#include <cstdio>

using namespace std;

bool isprime(long long n){
	if(n==0 || n==1)
		return false;
	for(long long i=2;i*i<n;++i){
		if(n % i == 0)
			return false;
	}
	return true;
}

long long mod_pow(long long x, long long n, long long mod){
	long long res = 1;
	while(n>0){
		if(n & 1)
			res = res * x % mod;
			x = x * x % mod;
			n >>= 1;
	}
	return res;
}


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	long long n;
	while(cin>>n && n){
		if(isprime(n)){
			cout<<n<<" is normal."<<endl;
		}else{
			bool flag=true;
			for(long long i=2;i<n;++i){
				if(mod_pow(i,n,n) != i){
					flag = false;
					break;
				}
			}
			if(!flag)
				cout<<n<<" is normal."<<endl;
			else
				cout<<"The number "<<n<<" is a Carmichael number."<<endl;
		}
	}
	return 0;
}