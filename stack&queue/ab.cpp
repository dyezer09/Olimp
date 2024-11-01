#include <bits/stdc++.h>

using namespace std;

int a[11][11];

queue<int> x,y;
queue<vector<int>> z;
vector<int> u;

/*
Задана решетка из цифр размером 5*5 параллельная осям координат. Начинать можно с произвольной цифры, и двигаться в одном из четырех направлений (вверх, вниз, влево, вправо, но не диагонально).

Цель - создать 6-значное целое число (которое может иметь ведущие нули, например 000201). Можно становится несколько раз на одну и ту же цифру.

Определите количество различных целых чисел, которые могут быть созданы таким способом.

1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 1 1 1

15
*/

int x2[4] = {1,-1,0,0};
int y2[4] = {0,0,1,-1};


void t(vector<int> v){
    int k = v[0]*100000+v[1]*10000+v[2]*1000+v[3]*100+v[4]*10+v[5];
    u.push_back(k);
    return ;
}

int f(){
int x1,y1,x3,y3;
vector<int> z1;
while(!x.empty()){
    x1 = x.front();
    y1 = y.front();
    z1 = z.front();
    if(z1.size() == 6){
        t(z1);
    }else{
    for(int i =0;i<4;i++){
        x3 = x1+x2[i];
        y3 = y1+y2[i];
        if(a[x3][y3]!=-1){
            x.push(x3);
            y.push(y3);
            z1.push_back(a[x3][y3]);
            z.push(z1);
            z1.pop_back();
        }
    }
    }
    x.pop();
    y.pop();
    z.pop();
}
return 0;
}



int main(){
    freopen("numgrid.in","r",stdin);
    freopen("numgrid.out","w",stdout);
for(int i =0;i<11;i++){
    for(int j =0;j<11;j++){
        a[i][j] = -1;
    }
}
for(int i =1;i<6;i++){
    for(int j =1;j<6;j++){
        cin >>a[i][j];
    }
}
vector<int> v;
for(int i =1;i<6;i++){
    for(int j =1;j<6;j++){
        x.push(i);
        y.push(j);
        v.push_back(a[i][j]);
        z.push(v);
        f();
        v.pop_back();
    }
}
sort(u.begin(),u.end());
u.push_back(-1);;
int sm =0;
for(int i =0;i<u.size()-1;i++){
   // cout << u[i] << endl;
    if(u[i]!=u[i+1])sm++;
}
cout << sm;
}



/*
    freopen("br1.in","r",stdin);
    freopen("br1.out","w",stdout);
*/
