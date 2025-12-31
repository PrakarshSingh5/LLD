#include <iostream>
#include <vector>
#include <string>
using namespace std;


enum class Symbol{
    X, O, EMPTY
};

class Player {
    private:
        string name;
        Symbol symbol;

    public:
        Player(string n, Symbol s) : name(n), symbol(s) {}
        string getName(){
            return name;
        }
        Symbol getSymbol(){
            return symbol;
        };
};

class Board{
    private:
         int size;
         vector<vector<Symbol>>board;
    public:
         Board(int s) : size(s), board(s, vector<Symbol>(s, Symbol::EMPTY)) {}
         bool placeSymbol(int row, int col, Symbol symbol){
            if(row<0 || row>=size || col<0 || col>=size || board[row][col]!=Symbol::EMPTY){
                return false;
            }
            board[row][col] = symbol;
            return true;
         };
         bool checkWinner(Symbol symbol){
            for(int i=0;i<size;i++){
                if(board[i][0]==symbol && board[i][1]==symbol && board[i][2]==symbol){
                    return true;
                }
            }
            for(int i=0;i<size;i++){
                if(board[0][i]==symbol && board[1][i]==symbol && board[2][i]==symbol){
                    return true;
                }
            }
            if(board[0][0]==symbol && board[1][1]==symbol && board[2][2]==symbol){
                return true;
            }
            if(board[0][2]==symbol && board[1][1]==symbol && board[2][0]==symbol){
                return true;
            }
            return false;
         };
         bool isFull(){
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    if(board[i][j]==Symbol::EMPTY){
                        return false;
                    }
                }
            }
            return true;
         };
         void print(){
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    if(board[i][j] == Symbol::X) cout << "X ";
                    else if(board[i][j] == Symbol::O) cout << "O ";
                    else cout << "- ";
                }
                cout<<endl;
            }
         };
};

class Game{
    private:
         Board board;
         vector<Player> players;
         int currentPlayerIndex;
    public:
         Game(int size, vector<Player> p) : board(size), players(p), currentPlayerIndex(0) {}
         void start(){
            board.print();
            while(!board.isFull()){
                Player& currentPlayer = getCurrentPlayer();
                cout<<currentPlayer.getName()<<"'s turn."<<endl;

                int row, col;
                cout<<"Enter row and column: ";
                cin>>row>>col;  
                if(!board.placeSymbol(row, col, currentPlayer.getSymbol())){
                    cout<<"Invalid move. Try again."<<endl;
                    continue;
                }
                board.print();
                
                if(board.checkWinner(currentPlayer.getSymbol())){
                    cout<<currentPlayer.getName()<<" wins!"<<endl;
                    break;
                }else {
                    switchTurn();
                }
            }
            board.print();
         };
         void switchTurn(){
             currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
         }
         Player& getCurrentPlayer(){
             return players[currentPlayerIndex];
         }
};

// main()

int main(){
    
   Player p1("Alice", Symbol::X);
   Player p2("Bob", Symbol::O);
   
    vector<Player> players = {p1, p2};

    Game game(3, players);
    game.start();

    return 0;
}
