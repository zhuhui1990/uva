#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Rect{
	int a;
	int b;
};

inline bool operator != (const Rect& r1, const Rect &r2){
	return (r1.a != r2.a || r1.b != r2.b);
}

inline bool operator < (const Rect& r1, const Rect& r2){
	if(r1.a != r2.a){
		return r1.a < r2.a;
	}else{
		return r1.b < r2.b;
	}
}

Rect rect[6];

void process(){
	int temp;
	for(int i=0;i<6;++i){
		if(rect[i].a > rect[i].b){
			temp = rect[i].a;
			rect[i].a = rect[i].b;
			rect[i].b = temp;
		}
	}
	sort(rect,rect+6);
	bool flag = true;
	if(rect[0] != rect[1]){
		flag = false;
	}else if (rect[2] != rect[3]){
		flag = false;
	}else if (rect[4] != rect[5]){
		flag = false;
	}else if(rect[0].b != rect[4].a){
		flag = false;
	}else if(rect[0].a != rect[2].a){
		flag = false;
	}else if(rect[2].b != rect[4].b){
		flag = false;
	}
	if(flag){
		cout<<"POSSIBLE"<<endl;
	}else{
		cout<<"IMPOSSIBLE"<<endl;
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	int cnt = 0;
	while(cin>>rect[cnt].a>>rect[cnt].b){
		++cnt;
		if(cnt == 6){
			process();
			cnt = 0;
		}
	}
	return 0;

}