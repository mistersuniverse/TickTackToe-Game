#include <iostream>
using namespace std;

// check if anyone wins and also return win status
bool wincheck(int array[3][3],int player){
    bool win=false;
    // checking row-wise
    for (int i=0; i<3; i++){
        if (array[i][0]==array[i][1]==array[i][2] && array[i][2]!=0){
            win = true;
            cout<<"hi"<<endl;
            break;
        }
    }

    // checking column-wise
    for (int i=0; i<3; i++){
        if (array[0][i]==array[1][i]==array[2][i] && array[2][i]!=0){
            win = true;
            cout<<"hi2"<<endl;
            break;
        }
    }
    
    // checking diagnol-wise
    if ( (array[0][0]==array[1][1]==array[2][2] && array[2][2]!=0) || (array[0][2]==array[1][1]==array[2][0] && array[2][0]!=0) ){
        cout<<"hi3"<<endl;
        win = true;
    }

    // checking win status
    if (win==true){
        cout<<"Player"<<player<<" won the match"<<endl;
    }    

    return win;
}

int main(){
    int spaces[3][3] = {{0,0,0},{0,0,0},{0,0,0}}, row, column, player = 1;
    newplayer = choiceExecution(spaces,row-1,column-1,player);


}