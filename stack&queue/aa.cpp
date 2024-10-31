#include <bits/stdc++.h>

using namespace std;

/*
�� ��������-������ �������� ����������� � ��������� �������� ��������� �������������� ������� ���� ��������������� ����������. ���� ����������� �� ����������, ��� ��������� �� ��� �������� �� ����� ���� � ����� �� ���������� ���������� ����� � �� ����� ����� ���������� ���� ��������� ����� (�� ���� ��������, ��� ������� � ����� ���������� �� ���������, ���������� � ������������ �������). ��������� ���������� ���������� ���������, ��� ����� ������ �������� ����������� �������� ����������.

��� ����, ����� ��������� ������������ ����� ��� ������������, ���������� ������, ������� ������ ��������� �� ����. �������� ���������, ������� ��� �������.


8 6
......
...##.
...##.
......
.###..
.###..
.###..
......


2


*/


int a[510][510];
queue<int> x,y;


int x2[4] = {1,-1,0,0};
int y2[4] = {0,0,1,-1};

int f(){
int x1,y1,x3,y3;
while(!x.empty()){
    x1 = x.front();
    y1 = y.front();
    for(int i =0;i<4;i++){
        x3 = x1+x2[i];
        y3 = y1+y2[i];
        if(a[x3][y3] == 0){
            a[x3][y3] = 1;
            x.push(x3);
            y.push(y3);
        }
    }
    x.pop();
    y.pop();
}
return 0;
}



int main(){

int n,m;
cin >> n >> m;
for(int i =0;i<n+4;i++)
    for(int j =0;j<m+4;j++)a[i][j] = 1;

char c;
for(int i =1;i<n+1;i++){
    for(int j =1;j<m+1;j++){
        cin >> c;
        if(c == '#')a[i][j] =0;
    }
}
int sm=0;
for(int i =1;i<n+1;i++){
    for(int j =1;j<m+1;j++){
        if(a[i][j] == 0){
            x.push(i);
            y.push(j);
            f();
            sm++;
        }
    }
}
cout << sm;
}



/*
    freopen("br1.in","r",stdin);
    freopen("br1.out","w",stdout);
*/
