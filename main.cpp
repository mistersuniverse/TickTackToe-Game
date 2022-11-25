#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// it will change the blank spaces into the choices made by player
int choiceExecution(int array[3][3],int row,int column,int player){

    // executes if space is empty means if zero
    if (array[row][column]==0){
        if (player == 1){
            array[row][column]=1; // 1 refers O
        }

        else {
            array[row][column]=2; // 2 refers X
        } 
    }   

    // executes if player has already chosen this space
    else{
        cout<<"Space is not Empty"<<endl;
        return player;
    }

    // to shuffle the players
    if (player==1){
            return 2;
        }

        else{
            return 1;
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
        if (array[i][0]==player && array[i][1]==player && array[i][2]==player){
            cout<<i<<endl;
            win = true;
            break;
        }
    }

    // checking column-wise
    for (int i=0; i<3; i++){
        if (array[0][i]==player && array[1][i]==player && array[2][i]==player){
            win = true;
            break;
        }
    }
    
    // checking diagnol-wise
    if ( (array[0][0]==player && array[1][1]==player && array[2][2]==player) || (array[0][2]==player && array[1][1]==player && array[2][0]==player) ){
        win = true;
    }

    // checking win status
    if (win==true){
        cout<<"Player"<<player<<" won the match"<<endl;
    }    

    return win;
}

// greeting function
void greet(){
    cout<<"Welcome to TickTackToe!"<<endl;
}

// function to save the result on txt file - not developed
void resultSaver(int winner){
    string player1,player2;
    ofstream resultfile;
    resultfile.open("results.txt",ios_base::app); // opening the file in append mode
    cout << "Enter player1 & player2 name respectively :";
    cin >> player1 >> player2;

    resultfile << "Player1 : " << player1 <<"; Player2 : "<<player2<<"; winner : " << winner << endl;
    resultfile.close();
}

int main() {
    greet();
    int spaces[3][3] = {{0,0,0},{0,0,0},{0,0,0}}, row, column, player = 1,winner;
    bool winstatus=false; // setting winstatus false by default
    display(spaces);
    while (winstatus == false) {

        cout<<"\nPlayer "<<player<<" :";
        cin>>row>>column;
        int newplayer; // it stores the next player temporarily
        newplayer = choiceExecution(spaces,row-1,column-1,player);
        winstatus = wincheck(spaces,player);

        winner=player; // stores the current player to use it in saving the result
        player=newplayer;
        display(spaces);
         
    }

    char decision;
    cout << "Want to save(y/n) : ";
    cin >> decision;
    if (decision=='y' || decision=='Y'){
        resultSaver(winner);
    }

    cout<<"Thanks for playing";
}