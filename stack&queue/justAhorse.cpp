#include <bits/stdc++.h>

using namespace std;

/*
���� ������������ ��������� ����� 8*8, �������� �� ������� ������������ ������ ����� �����
���� - ��� ����������� ��������� ������, ������� ����� ������� ����� ������ �� ������� "L".

������, �� ������� ���� K ������������ �������� ������� ����, � ����� �� 1 �� 8 - ��� ��������� ���� �� ���� �������.
���� ��������� ������ ��������� ��������� ������� ���� � ������� ����������� ���������� �����, ������� ��������� ����, ����� ������� � �������, ��������� �� ������ ������ �����.


����
2 1
3 3

�����
1


����
4 2
7 5

�����
2
*/
int a[9][9];

queue<int> x,y,z;

int x2[8] = {2,2,-2,-2,1,-1,1,-1};
int y2[8] = {1,-1,1,-1,2,2,-2,-2};


int f(){
int x1,y1,z1,x3,y3;


while(!x.empty()){
    x1 = x.front();
    y1 = y.front();
    z1 = z.front();
    for(int i =0;i<8;i++){
        x3 = x1+x2[i];
        y3 = y1+y2[i];
        if(a[x3][y3]<2 && x3 >0 && x3 < 9 && y3>0 && y3<9){
            if(a[x3][y3]==1)return z1+1;
            a[x3][y3] = 2;
            x.push(x3);
            y.push(y3);
            z.push(z1+1);
        }
    }
    x.pop();
    y.pop();
    z.pop();
}
return -1;

}




int main() {
for(int i =1;i<9;i++)
    for(int j =1;j<9;j++)a[i][j] = 0;

    int b,b1;
    cin >> b >> b1;
    x.push(b);
    y.push(b1);
    z.push(0);
    cin >> b >> b1;
    a[b][b1] = 1;
    if(b == x.front() && b1 == y.front()){
        cout << 0;
        return 0;
    }
    cout << f();
}


/*
    freopen("br1.in","r",stdin);
    freopen("br1.out","w",stdout);
*/
