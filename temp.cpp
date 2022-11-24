#include <iostream>
using namespace std;

void xcreator(){
    for (int i=0;i<=1;++i){
        for (int x=0; x<=i;++x){
            cout<<"  ";
        }
        cout<<'*';
        for (int x=(i*3); x>=0;x=-3){
            cout<<"  ";
        }
        cout<<'*'<<endl;
    }


    for (int i=0;i>=0;--i){
        for (int x=i; x>=0;--x){
            cout<<"  ";
        }
        cout<<'*'<<endl;
    }
}

int main(){
    xcreator();
}