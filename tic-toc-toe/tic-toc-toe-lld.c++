#include <iostream>
#include <vector>
#include <string>
using namespace std;


enum class Symbol{
    X, O, EMPTY
};

class WinningStrategy {
public:
    virtual bool checkWinner(
        const vector<vector<Symbol>>& board,
        Symbol symbol
    ) = 0;

    virtual ~WinningStrategy() = default;
};

class RowColumnDiagonalStrategy : public WinningStrategy {
public:
    bool checkWinner(
        const vector<vector<Symbol>>& board,
        Symbol symbol
    ) override {
        int n = board.size();

        // check rows
        for (int i = 0; i < n; i++) {
            bool win = true;
            for (int j = 0; j < n; j++) {
                if (board[i][j] != symbol) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }

        // check columns
        for (int j = 0; j < n; j++) {
            bool win = true;
            for (int i = 0; i < n; i++) {
                if (board[i][j] != symbol) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }

        // main diagonal
        bool win = true;
        for (int i = 0; i < n; i++) {
            if (board[i][i] != symbol) {
                win = false;
                break;
            }
        }
        if (win) return true;

        // anti diagonal
        win = true;
        for (int i = 0; i < n; i++) {
            if (board[i][n - i - 1] != symbol) {
                win = false;
                break;
            }
        }
        return win;
    }
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

class Board {
private:
    int size;
    vector<vector<Symbol>> grid;
    WinningStrategy* winningStrategy;

public:
    Board(int size, WinningStrategy* strategy)
        : size(size), winningStrategy(strategy) {
        grid = vector<vector<Symbol>>(size, vector<Symbol>(size, Symbol::EMPTY));
    }

    bool checkWinner(Symbol symbol) {
        return winningStrategy->checkWinner(grid, symbol);
    }

    const vector<vector<Symbol>>& getGrid() const {
        return grid;
    }
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
