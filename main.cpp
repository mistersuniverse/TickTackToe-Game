#include <iostream>
#include <string>

using namespace std;

// it will change the blank spaces into the choices made by player
int choiceExecution(int array[3][3],int row,int column,int player){
    if (player == 1){
        array[row][column]=1; // 1 refers O
    }

    else {
        array[row][column]=2; // 2 refers X
    } 
}

// it controls the user-interface provided to player to play the game
void display(int array[3][3]){
    for (int x=0; x<3; x++){
        for (int y=0; y<3; y++) {
        cout<<array[x][y];
        }
        cout<<endl;
    }
}

// check if anyone wins and also return win status
bool wincheck(int array[3][3],int player){
    bool win=false;
    // checking row-wise
    for (int i=0; i<3; i++){
        if (array[i][0]==array[i][1]==array[i][2] && array[i][2]!=0){
            win = true;
            break;
        }
    }

    // checking column-wise
    for (int i=0; i<3; i++){
        if (array[0][i]==array[1][i]==array[2][i] && array[2][i]!=0){
            win = true;
            break;
        }
    }
    
    // checking diagnol-wise
    if ( (array[0][0]==array[1][1]==array[2][2] && array[2][2]!=0) || (array[0][2]==array[1][1]==array[2][0] && array[2][0]!=0) ){
        win = true;
    }

    // checking win status
    if (win==true){
        cout<<"Player"<<player<<" won the match"<<endl;
    }    

    return win;
}


int main() {
    int spaces[3][3] = {{0,0,0},{0,0,0},{0,0,0}}, row, column, player = 1;
    bool winstatus=false; // setting winstatus false by default
    while (winstatus == false) {
        display(spaces);

        cout<<"\nPlayer "<<player<<" :";
        cin>>row>>column;
        choiceExecution(spaces,row,column,player);
        winstatus = wincheck(spaces,player);

        if (player==1){
            player = 2;
        }

        else{
            player = 1;
        }        
    }
}