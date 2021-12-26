#include <iostream>

using namespace std;

// variables
char board[3][3] = {
                        {'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'}
                    };

char current_marker; 
int current_player;
string player1_name, player2_name;

// functions
void board_shape();
void place_marker(int place);
int winner();
void change_player_style();
void game();

int main()
{
    game();
    return 0;
}

void board_shape()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void place_marker(int place)
{
    // game engine
    int row = place / 3;
    int col;

    if (place % 3 == 0)
    {
        row = row - 1;
        col = 2;
    }
    else 
        col = (place % 3) - 1;

    board[row][col] = current_marker;    
}

int winner()
{
    for(int i = 0; i < 3; i++)
    {
        // horizontal
        if (board[i][0] == board[i][1] && board[i][1] ==  board[i][2])
            return current_player;

        // vertical
        else if(board[0][i] == board[1][i] && board[1][i]  == board[2][i])
            return current_player;

    }
    // right diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;

    // left diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;

    return 0;  
}

void change_player_style()
{
    // change the style
    if (current_marker == 'X')
    {
        current_marker = 'O';

        // change color of the board
        system("color 9");
    }
    else
    {
        current_marker = 'X';

        // change color of the board
        system("color a");
    }

    // change the player
    if (current_player ==  1)
        current_player = 2;
    else 
        current_player = 1;    
}

void game()
{
    // variables
    char style;
    int player_won;

    // prompet for tha players name
    cout << "Enter the first player name: ";
    cin >> player1_name;

    cout << "Enter the second player name: ";
    cin >> player2_name;

    // asking for the sytle x or o
    cout << player1_name << " choose between: \n"
                         << "1: 'X'\t\t 2: 'O'";
    cin >> style;

    switch (style)
    {
    case 'x':
        style = 'X';
        break;
    
    case 'X':
        style = 'X';
        break;

    case 'o':
        style = 'O';
        break;

    case 'O':
        style = 'O';
        break;

    default:
        style = 'X';
        break;
    }                      

    current_marker = style;
    current_player = 1;

    for (int i = 0; i < 9; i++)
    {
        // varibles
        int place;

        cout << "it's " << current_player << " turn." << endl;

        board_shape();

        cout << "\n\n";

        // prompet to ask the user where he will put his marker
        cout << "Enter the place where you want to put 'X' or 'O': ";
        cin >> place;

        while (place < 1 || place > 9)
        {
            cout << "there is an error in the inputs you entered " << endl;

            // prompet for the user to take care what he entered
            cout << "enter a number between 1 and 9: ";
            cin >> place;
        }

        place_marker(place);

        player_won = winner();

        if (player_won == 1)
        {
            cout << player1_name << " won !!" << endl;
            cout << "\n\n";

            board_shape();

            system("pause");

            break;
        }
        else if (player_won == 2)
        {
            cout << player2_name << " won !!" << endl;
            cout << "\n\n";

            board_shape();

            system("pause");

            break;

        }

        change_player_style();

        system("cls");
    }

    board_shape();

    if (player_won == 0)
    {
        cout << "the game ended in draw!!" << endl;
    }
}