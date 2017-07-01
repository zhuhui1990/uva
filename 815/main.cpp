#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 905;

int h[maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n,m;
	int kase = 0;
	double sum;
	while(cin>>n>>m && n != 0){
		//cout<<"n="<<n<<" m="<<m<<endl;
		memset(h,0,sizeof(h));
		++kase;
		for(int i=0;i<n*m;++i){
			cin>>h[i];
		}
		cin>>sum;
		sum /= 100.;
		sort(h,h+n*m);
		if(sum == 0.){
			printf("Region %d\n",kase);  
    	printf("Water level is %.2lf meters.\n",double(h[0]));  
    	printf("%.2lf percent of the region is under water.\n\n",0.*100);
			continue;
		}
		double tot;
		double high;
		double per;
		for(int i=1;i<n*m;++i){
			tot = (h[i]-h[i-1])*(i);
			//cout<<"i="<<i<<" tot="<<tot<<" sum="<<sum<<endl;
			if(sum > tot){
				sum -= tot;
			}else{
				high = h[i-1]+sum/i;
				//cout<<"high="<<high<<endl;
				sum = 0.;
				per = i*1.0/n/m;
				break;
			}
			
		}
		//cout<<"sum="<<sum<<endl;
		if(sum > 0.){ //淹没整个区域后还有剩余
			high = h[n*m-1]+sum/n/m;
			per = 1.;
		}
		//cout<<"Region "<<kase<<endl;
		printf("Region %d\n",kase);  
    printf("Water level is %.2lf meters.\n",high);  
    printf("%.2lf percent of the region is under water.\n\n",per*100);  
	}
	
	return 0;

}