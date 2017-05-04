#include <iostream>

//#define LOCAL

using namespace std;

int count(int i){
	int cnt = 1;
	while (i != 1){
		++cnt;
		if (i % 2 == 1){
			i = i * 3 + 1;
		}
		else{
			i /= 2;
		}
	}
	return cnt;
}


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a, b, max = 0;
	while (cin >> a >> b){
		int aa = a, bb = b;
		max = 0;
		if (a > b){
			aa = b;
			bb = a;
		}
		for (int i = aa; i <= bb; ++i){
			int cnt = count(i);
			if (cnt > max){
				max = cnt;
			}
		}
		cout << a << " " << b << " " << max << endl;
	}



	return 0;
}