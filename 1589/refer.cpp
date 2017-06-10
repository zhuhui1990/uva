#include <stdio.h>
#include <string.h>

struct piece{
    char name;
    int row;
    int col;
    int live;
}red[10],redbak[10];


int board[13][13];//���̣�ֻ���red����λ�� 
int book[13][13];//���red���ӹ�Ͻ��Χ
int boardbak[13][13];//���̱��� 

void printinfo(){
    int i,j;
    for(i=1;i<=10;i++){
        for(j=1;j<=9;j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    
    for(i=1;i<=10;i++){
        for(j=1;j<=9;j++){
            printf("%d ",book[i][j]);
        }
        printf("\n");
    }
}
//�����Ͻ���̷�Χ���ȴ����Ͻ�ʹ���ΧҪ��һЩ��
 
void general(int row,int col){//����general��Ͻ��Χ 
    int i;
    
    for(i=row-1;i>=1;i--){
        if(board[i][col]==0){
            if(i<=3&&i>=1)
                book[i][col]=1;
        }else//else���������if�����Ǹ��Ƚ����ҵĴ��� 
            break;
    }
}

void chariot(int row,int col){//��Ͻ���̷�Χ 
    int i;
    for(i=row-1;i>=1;i--){//�д��������ϱ߽� 
        if(board[i][col]==0)
            book[i][col]=1;
        else
            break;
    }
    for(i=row+1;i<=10;i++){//�д��������±߽� 
        if(board[i][col]==0)
            book[i][col]=1;
        else
            break;
    }
    
    for(i=col+1;i<=9;i++){//�д��������ұ߽�
        if(board[row][i]==0)
            book[row][i]=1;
        else
            break; 
    } 
    for(i=col-1;i>=1;i--){//�д���������߽�
        if(board[row][i]==0)
            book[row][i]=1;
        else
            break; 
    }
}
void cannon(int row,int col){//�ڹ�Ͻ���̷�Χ 
    int i;
    int flag;
    //����
    
    flag=0;
    for(i=row-1;i>=1;i--){//�Ϸ�����
        if(flag){
            if(board[i][col]==0)
                book[i][col]=1;
            else
                break;
        }
        if(flag==0&&board[i][col]==1)
            flag=1;
         
    }
    
    flag=0;
    for(i=row+1;i<=10;i++){//�·�����
        if(flag){
            if(board[i][col]==0)
                book[i][col]=1;
            else
                break;
        } 
        if(flag==0&&board[i][col]==1)
            flag=1;
    }
    
    flag=0;
    for(i=col-1;i>=1;i--){//�󷽴���
        if(flag){
            if(board[row][i]==0)
                book[row][i]=1;
            else
                break;
        }
        if(flag==0&&board[row][i]==1)
            flag=1; 
    }
    
    flag=0;
    for(i=col+1;i<=9;i++){//�ҷ�����
        if(flag){
            if(board[row][i]==0)
                book[row][i]=1;
            else
                break;
        } 
        if(flag=0&&board[row][i]==1)
            flag=1;
    } 
}
void horse(int row,int col){//���Ͻ���̷�Χ 
    //�Թ�Ͻλ���Ƿ���ڽ��д���Խ�������������
    
    //��������������ж� 
    if(row-2>=1&&col-1>=1){//���Ͻ� 
        if(board[row-1][col]==0)
            book[row-2][col-1]=1;
    }
    if(row-2>=1&&col+1<=9){//���Ͻ�
        if(board[row-1][col]==0)
            book[row-2][col+1]=1; 
    }
    if(row+2<=10&&col-1>=1){//���½�
        if(board[row+1][col]==0)
            book[row+2][col-1]=1; 
    }
    if(row+2<=10&&col+1<=9){//���½� 
        if(board[row+1][col]==0)
            book[row+2][col+1]=1;
    }
    
    //��������������ж�
    if(row-1>=1&&col-2>=1){//���Ͻ� 
        if(board[row][col-1]==0)
            book[row-1][col-2]=1;
    } 
    if(row+1<=10&&col-2>=1){//���½� 
        if(board[row][col-1]==0)
            book[row+1][col-2]=1;
    }
    if(row-1>=1&&col+2<=10){//���Ͻ� 
        if(board[row][col+1]==0)
            book[row-1][col+2]=1;
    }
    if(row+1<=10&&col+2<=9){//���½� 
        if(board[row][col+1]==0)
            book[row+1][col+2]=1;
    }
}

int check(int newbr,int newbc,int n){//�Ƿ񽫾�
    int i;
    for(i=0;i<n;i++)
        if(red[i].row==newbr&&red[i].col==newbc){
            red[i].live=0;
            board[newbr][newbc]=0;//����������̱����ӵı�ʶ�����Ǽ��ϴ˾��ˡ�2016-10-30 
        }
    for(i=0;i<n;i++)
        if(red[i].live==1){
            switch(red[i].name){
                case 'G':
                    general(red[i].row,red[i].col);
                    break;
                case 'R':
                    chariot(red[i].row,red[i].col);
                    break;
                case 'H':
                    horse(red[i].row,red[i].col);
                    break;
                case 'C':
                    cannon(red[i].row,red[i].col);
                    break;
            }
        } 
    if(book[newbr][newbc]==1)
        return 1;
    else
        return 0;
        
}


int main(){
#ifdef LOCAL
	freopen("rand.in","r",stdin);
	freopen("refout.txt","w",stdout);
#endif
    int n,br,bc;
    char name[5];
    int i;
    int ans;
    int res;
    while(scanf("%d%d%d",&n,&br,&bc)==3&&n&&br&&bc){
        ans=1;
        memset(board,0,sizeof(board));
        memset(red,0,sizeof(red));
        for(i=0;i<n;i++){
            scanf("%s%d%d",name,&(red[i].row),&(red[i].col));
            red[i].name=name[0];
            red[i].live=1;
            board[red[i].row][red[i].col]=1;//�����������λ�� 
        }       
        
        memcpy(boardbak,board,sizeof(board));
        memcpy(redbak,red,sizeof(red));
        memset(book,0,sizeof(book));
        //black general moving like horse
        
        if(br-1>=1){//���ƴ���
            res=check(br-1,bc,n);
            ans*=res;
//            printf("��%d\n",res);
        }
        
        memcpy(board,boardbak,sizeof(boardbak));
        memcpy(red,redbak,sizeof(redbak));
        memset(book,0,sizeof(book));
        if(br+1<=3){//���ƴ���
            res=check(br+1,bc,n);
            ans*=res;
//            printf("��%d\n",res);
        }
        
        memcpy(board,boardbak,sizeof(boardbak));
        memcpy(red,redbak,sizeof(redbak));
        memset(book,0,sizeof(book));
        if(bc-1>=4){//���ƴ��� 
            res=check(br,bc-1,n);
            ans*=res;
//            printf("��%d\n",res);
        } 
        
        memcpy(board,boardbak,sizeof(boardbak));
        memcpy(red,redbak,sizeof(redbak));
        memset(book,0,sizeof(book));
        if(bc+1<=6){//���ƴ��� 
            res=check(br,bc+1,n);//�����˱��󣬽�bc+1д��bc-1 
            ans*=res; 
//            printf("��%d\n",res);
        }
        
        
        if(ans==0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}