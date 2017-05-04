#include <iostream>

using namespace std;

const int n = 8;

char board[n][n];
int ctrl1[n][n];
int ctrl2[n][n];
int  dxy[16][2] = {1,1,1,-1,-1,1,-1,-1, 1,0,0,1,-1,0,0,-1,  
                   1,2,1,-2,-1,2,-1,-2, 2,1,2,-1,-2,1,-2,-1};  


inline bool isvalid(int i,int j){
	return (i >= 0 && i < n && j >= 0 && j < n);
}

inline bool isvalid1(int ii,int jj){
	return isvalid(ii,jj) && (board[ii][jj] == '.' || board[ii][jj] == 'K');
}

inline bool isvalid2(int ii,int jj){
	return isvalid(ii,jj) && (board[ii][jj] == '.' || board[ii][jj] == 'k');
}

inline void setCtrl1(int ii,int jj){
	if(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
	}
}

inline void setCtrl2(int ii,int jj){
	if(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
	}
}


void setCtrl(char c,int i,int j){
	int ii,jj;
	switch(c){
	case('p'):
		ii = i+1;
		jj = j-1;
		setCtrl1(ii,jj);
		ii = i+1;
		jj = j+1;
		setCtrl1(ii,jj);
		break;
	case('P'):
		ii = i-1;
		jj = j-1;
		setCtrl2(ii,jj);
		ii = i-1;
		jj = j+1;
		setCtrl2(ii,jj);
		break;
	case('n'):
		ii = i-2;
		jj = j-1;
		setCtrl1(ii,jj);
		jj = j+1;
		setCtrl1(ii,jj);
		ii = i-1;
		jj = j-2;
		setCtrl1(ii,jj);
		jj = j+2;
		setCtrl1(ii,jj);
		ii = i+1;
		jj = j-2;
		setCtrl1(ii,jj);
		jj = j+2;
		setCtrl1(ii,jj);
		ii = i+2;
		jj = j-1;
		setCtrl1(ii,jj);
		jj = j+1;
		setCtrl1(ii,jj);
		break;
	case('N'):
		ii = i-2;
		jj = j-1;
		setCtrl2(ii,jj);
		jj = j+1;
		setCtrl2(ii,jj);
		ii = i-1;
		jj = j-2;
		setCtrl2(ii,jj);
		jj = j+2;
		setCtrl2(ii,jj);
		ii = i+1;
		jj = j-2;
		setCtrl2(ii,jj);
		jj = j+2;
		setCtrl2(ii,jj);
		ii = i+2;
		jj = j-1;
		setCtrl2(ii,jj);
		jj = j+1;
		setCtrl2(ii,jj);
		break;
	case('b'):
		ii = i-1;
		jj = j-1;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			--ii;
			--jj;
		}
		ii = i-1;
		jj = j+1;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			--ii;
			++jj;
		}
		ii = i+1;
		jj = j-1;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			++ii;
			--jj;
		}
		ii = i+1;
		jj = j+1;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			++ii;
			++jj;
		}
		break;
	case('B'):
		ii = i-1;
		jj = j-1;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			--ii;
			--jj;
		}
		ii = i-1;
		jj = j+1;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			--ii;
			++jj;
		}
		ii = i+1;
		jj = j-1;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			++ii;
			--jj;
		}
		ii = i+1;
		jj = j+1;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			++ii;
			++jj;
		}
		break;
	case('r'):
		ii = i-1;
		jj = j;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			--ii;
		}
		ii = i+1;
		jj = j;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			++ii;
		}
		ii = i;
		jj = j-1;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			--jj;
		}
		ii = i;
		jj = j+1;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			++jj;
		}
		break;
	case('R'):
		ii = i-1;
		jj = j;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			--ii;
		}
		ii = i+1;
		jj = j;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			++ii;
		}
		ii = i;
		jj = j-1;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			--jj;
		}
		ii = i;
		jj = j+1;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			++jj;
		}
		break;
	case('q'):
		ii = i-1;
		jj = j-1;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			--ii;
			--jj;
		}
		ii = i-1;
		jj = j+1;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			--ii;
			++jj;
		}
		ii = i+1;
		jj = j-1;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			++ii;
			--jj;
		}
		ii = i+1;
		jj = j+1;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			++ii;
			++jj;
		}
		ii = i-1;
		jj = j;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			--ii;
		}
		ii = i+1;
		jj = j;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			++ii;
		}
		ii = i;
		jj = j-1;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			--jj;
		}
		ii = i;
		jj = j+1;
		while(isvalid1(ii,jj)){
			ctrl1[ii][jj] = 1;
			++jj;
		}
		break;
	case('Q'):
		ii = i-1;
		jj = j-1;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			--ii;
			--jj;
		}
		ii = i-1;
		jj = j+1;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			--ii;
			++jj;
		}
		ii = i+1;
		jj = j-1;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			++ii;
			--jj;
		}
		ii = i+1;
		jj = j+1;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			++ii;
			++jj;
		}
		ii = i-1;
		jj = j;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			--ii;
		}
		ii = i+1;
		jj = j;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			++ii;
		}
		ii = i;
		jj = j-1;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			--jj;
		}
		ii = i;
		jj = j+1;
		while(isvalid2(ii,jj)){
			ctrl2[ii][jj] = 1;
			++jj;
		}
		break;
	/*		
	case('k'):
		for(int ii=-1;ii<=1;++ii){
			for(int jj=-1;jj<=1;++jj){
				if(!(ii == 0 && jj== 0)){
					setCtrl1(ii,jj);
				}
			}
		}
		break;
	case('K'):
		for(int ii=-1;ii<=1;++ii){
			for(int jj=-1;jj<=1;++jj){
				if(!(ii == 0 && jj== 0)){
					setCtrl2(ii,jj);
				}
			}
		}
		break;
	*/
	default:
		break;
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif
	int kase = 0;
	while(true){
		++kase;
		int cnt = 0;
		int x1,y1,x2,y2;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cin>>board[i][j];
				if(board[i][j] != '.'){
					++cnt;
				}
				ctrl1[i][j] = 0;
				ctrl2[i][j] = 0;
			}
		}
		if(cnt == 0){
			break;
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(board[i][j] != '.'){
					if(board[i][j] == 'k'){
						x1 = i;
						y1 = j;
					}else if(board[i][j] == 'K'){
						x2 = i;
						y2 = j;
					}
					setCtrl(board[i][j],i,j);
				}
			}
		}
		int res=0;

		if(ctrl2[x1][y1] == 1){
			res = 1;
		}
		if(ctrl1[x2][y2]  == 1){
			res = 2;
		}
		/*
		if(kase==35){
			cout<<"kase="<<kase<<endl;
			cout<<"x2="<<x2<<" y2="<<y2<<" ctrl="<<int(ctrl[x2][y2])<<endl;
		}
		*/
		cout<<"Game #"<<kase<<": ";
		switch(res){
		case(0):
			cout<<"no";
			break;
		case(1):
			cout<<"black";
			break;
		case(2):
			cout<<"white";
			break;
		default:
			break;
		}
		cout<<" king is in check."<<endl;
	}

	return 0;
}