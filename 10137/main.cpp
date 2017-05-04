#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=1005;
int array[maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	//double d;
	int a,b;
	int sum = 0;
	int avg = 0;
	int avg1;
	int res,bucket;
	while(cin>>n && n){
		sum = 0;
		avg = 0;
		for(int i=0;i<n;++i){
			cin>>a;
			cin.get();
			cin>>b;
			array[i] = a*100+b;
			sum += array[i];
		}
		avg  = sum / n;
		//if(avg * n == sum){
		//	avg1 = avg;
		//}else{
			avg1 = avg + 1;
		//}
		res = 0,bucket=0;
		for(int i=0; i<n; ++i){
			if(array[i] > avg1){
				int exchange = array[i] - avg1;
				bucket -= exchange;
				res    += exchange;
			}else if(array[i] < avg){
				int exchange = avg-array[i];
				bucket += exchange;
			}
		}
		if(bucket > 0){
			res += bucket;
		}
		
	//cout<<"$"<<res/100<<"."<<res%100<<endl; 
		printf("$%d.%02d\n",res/100,res%100);
	}
	
	
	return 0;
}