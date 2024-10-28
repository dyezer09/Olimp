#include<bits/stdc++.h>

using namespace std;






/*
Определите минимальное количество символов в строке из круглых скобок, которые нужно заменить на противоположный ( левую скобку на правую, или наоборот) , чтобы получить сбалансированную строку.
())(
2
*/


int main(){
 //   freopen("clumsy.in","r",stdin);
 //   freopen("clumsy.out","w",stdout);
string s;
cin >> s;
int k =0,sm =0;
for(int i=0;i<s.size();i++){
    if(s[i] == '(')k++;
    else k--;
    if(k<0){
        s[i] = '(';
        k = 1;
        sm++;
    }
}
k =0;
for(int i=s.size()-1;i>=0;i--){
    if(s[i] == ')')k++;
    else k--;
    if(k<0){
        s[i] = ')';
        k = 1;
        sm++;
    }
}
cout << sm;

}
/*
    freopen("br1.in","r",stdin);
    freopen("br1.out","w",stdout);
*/
