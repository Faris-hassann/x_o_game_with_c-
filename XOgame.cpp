#include <iostream>

using namespace std;

// variables
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // for board shape
char current_marker; // current x or o for the player
int current_player; // the player's turn
string player1_name, player2_name;


void board_shape()
{
    // board shape
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void placeMarker(int place)
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
    // counter for the winner
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;

        else if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;    
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;

    if (board[0][2] == board[1][1] && board[2][0] == board[2][0])
        return current_player;

    return 0;        
}

void swap_player_and_style()
{
    // change the sytle
    if (current_marker == 'X')
    {
        // change the marker of the game
        current_marker = 'O';
        // change the color of the game
        system("color F");
    }    
    else 
    {
        // change the marker of the game
        current_marker = 'X';
        // change the color of the game
        system("color a");
    }

    // change the player
    if (current_player == 1)
        current_player = 2; // change from the first to the second
    else
        current_player = 1; // changer from the second to the first

}

void game()
{ 
    char style;

    // the game function
    cout << "enter the first player name: ";
    cin >> player1_name; // take the name

    cout << "enter the second player name: ";
    cin >> player2_name; // take the name

    cout << player1_name << "choose between:\n" 
                         << "1: 'X'\n2: 'O'\n";

    // prompet for the x and o
    cout << "enter the letter: ";                     
    cin >> style; // see the first player will play with x or o                     

    switch (style)
    {
        case 'x':
            style = 'X';
            break;
        case 'o':
            style = 'O';
            break;
        case 'X':
            style = 'X';
            break;
        case 'O':
            style = 'O';
            break;
        case 1:
            style = 'X';
            break;
        case 2:
            style = 'O';
            break;     
        default:
            style = 'X';
            break;
    }                     

    current_player = 1;
    current_marker = style;

    int player_won;

    for (int i = 0; i < 9; i++)
    {
        int place;

        cout << "\n\n";
        cout << "It's " << current_player << " turn." << endl << "\n\n";
        
        board_shape();

        cout << "\n\n";

        // prompet to take the place of x or o
        cout << "enter the place where you want to put 'x' or 'o': ";
        cin >> place;

        while (place < 1 || place > 9)
        {
            // this loop checks if the number of the board is true or false
            cout << "there is an error in the inputs.";
            cout << endl;
            cout << "enter a number between 1 and 9: ";
            cin >> place;
        }

        placeMarker(place);

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

        swap_player_and_style();
        system("cls");    
    }

    board_shape();

    if (player_won == 0)
    {
        cout << "This game ended in draw !" << endl;  
    }
}

int main()
{
    game();

    return 0;
}   