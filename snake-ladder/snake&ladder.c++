#include <iostream>
#include <vector>
#include <string>
using namespace std;

using namespace std;

//Baord , Player, Dice, Game, Snake, Ladder

class Player {
    private:
        int playerNumber;
        string name;
        int position;
    public:
        Player(int playerNumber, string name){
            this->playerNumber = playerNumber;
            this->name = name;
            this->position = 0;
        }
        int getPlayerNumber(){
            return playerNumber;
        }
        string getName(){
            return name;
        }
        int getPosition(){
            return position;
        }
        void setPosition(int position){
            this->position =this->position + position;
        }
};

class Dice{
    private:
        int size;
    public:
        Dice(int size){
            this->size = size;
        }
       int roll(){
    return rand()%size + 1;
}
}

class Board{
    private:
        int size;
        vector<int>grid;
    public:
        Board(int size){
            this->size = size;
            grid = vector<int>(size, 0);
        }
        void print(){
            for(int i = 0; i < size; i++){
                cout<<grid[i]<<" ";
                cout<<endl;
            }
        }
}

class Jump{
    private:
        int start;
        int end;
    public:
        Jump(int start, int end){
            this->start = start;
            this->end = end;
        }
        int getStart(){
            return start;
        }
        int getEnd(){
            return end;
        }
}

class Game{
    private:
        vector<Player>players;
        int currentPlayerIndex;
        Dice dice;
        Board board;
    public:
        Game(vector<Player>players, Dice dice, Board board){
            this->players = players;
            this->dice = dice;
            this->board = board;
        } 
        void play(){
            while(true){
                int diceValue = dice.roll();
                int currentPlayer = players[currentPlayerIndex];
                currentPlayer.setPosition(diceValue);
                if(currentPlayer.getPosition)
            }
        }   
}



int main() {
    Player player1(1, "Sunny");
    Player player2(2, "John");
    Dice dice(6);
    Board board(10);
    vector<Player>players = {player1, player2};
    Game game(players, dice, board);
    game.play();
    
    return 0;
}