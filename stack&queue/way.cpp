#include <bits/stdc++.h>

using namespace std;




/*

Дана шахматная доска, состоящая из n*n клеток, несколько из них вырезано. Провести ходом коня через невырезанные клетки путь минимальной длины из одной клетки в другую.

Вход. В первой строке задано число n (2 ≤ n ≤ 50). В следующих n строках содержится по n символов. Символом # обозначена вырезанная клетка, точкой – невырезанная клетка, @ – заданные клетки (таких символов два).

Выход. Если путь построить невозможно вывести "Impossible", в противном случае вывести такую же карту, как и на входе, но пометить все промежуточные положения коня символом @.

Пример входа
5
@..@.
..##.
.....
.....
.....

Пример выхода
@..@.
..##.
.@..@
..@..
@....


*/
int a[55][55],b[55][55],n;

queue<int> x,y;
queue<vector<int>> xx,yy;

int x2[8] = {2,2,-2,-2,1,-1,1,-1};
int y2[8] = {1,-1,1,-1,2,2,-2,-2};

vector<int> u,u1;


int f(){
int x1,y1,z1,x3,y3;
vector<int>xx1,yy1;



while(!x.empty()){
    x1 = x.front();
    y1 = y.front();
    xx1 = xx.front();
    yy1 = yy.front();
    for(int i =0;i<8;i++){
        x3 = x1+x2[i];
        y3 = y1+y2[i];
        if(a[x3][y3]<2 && x3 >0 && x3 <= n && y3>0 && y3<=n){
            if(a[x3][y3]==1){
                    xx1.push_back(x3);
                    yy1.push_back(y3);
                    u = xx1;
                    u1 = yy1;
                    return xx1.size();
            }
            a[x3][y3] = 2;
            x.push(x3);
            y.push(y3);
            xx1.push_back(x3);
            yy1.push_back(y3);
            xx.push(xx1);
            yy.push(yy1);
            xx1.pop_back();
            yy1.pop_back();
        }
    }
    x.pop();
    y.pop();
    xx.pop();
    yy.pop();
}
return -1;

}




int main() {
    freopen("H.in","r",stdin);
    freopen("H.out","w",stdout);
    cin >> n;
vector<int> v,v1;
char c;
int k = 0;
for(int i =1;i<=n;i++)
    for(int j =1;j<=n;j++){
       cin >> c;
       if(c == '@'){
          if(k == 0){
            k++;
            x.push(i);
            y.push(j);
            v.push_back(i);
            v1.push_back(j);
            xx.push(v);
            yy.push(v1);
          }else a[i][j] = 1;
       }
       if(c == '#')a[i][j] = 2;
       b[i][j] = a[i][j];
    }
    int t = f();
    if(t ==-1){
        cout << "Impossible";
        return 0;
    }
for(int i =0;i<t;i++){
    int k1 =u1[i],k = u[i];

    b[k][k1] = 1;
}

for(int i =1;i<=n;i++){
    for(int j =1;j<=n;j++){
        if(b[i][j] == 0)c= '.';
        else if(b[i][j] == 1)c= '@';
        else c = '#';
        cout <<c;
    }
    cout << endl;
}

}

/*
    freopen("br1.in","r",stdin);
    freopen("br1.out","w",stdout);
*/
