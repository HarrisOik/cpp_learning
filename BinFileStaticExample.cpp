#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct Board
{
    string game_board[9][9];
} chessBoard;

int main()
{
    int count_letter = 97;
    int count_number = 8;
    
     ofstream wf("game_save.bin", ios::out | ios::binary);
     if (!wf)
     {
         cout << "Cannot open file!" << endl;
         return 1;
     }

    cout << "Creating New Game...\n\n";

    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            if (i == 8 && j == 0)
                chessBoard.game_board[i][j] = " ";
            else if (i == 8)
            {
                chessBoard.game_board[i][j] = count_letter;
                count_letter++;
            }
            else if (j == 0)
            {
                chessBoard.game_board[i][j] = to_string(count_number);
                count_number--;
            }
            else if (i == 1)
                chessBoard.game_board[i][j] = "BP";
            else if (i == 6)
                chessBoard.game_board[i][j] = "WP";
            else if (i == 0 && (j == 1 || j == 8))
                chessBoard.game_board[i][j] = "BR";
            else if (i == 7 && (j == 1 || j == 8))
                chessBoard.game_board[i][j] = "WR";
            else if (i == 0 && (j == 2 || j == 7))
                chessBoard.game_board[i][j] = "Bk";
            else if (i == 7 && (j == 2 || j == 7))
                chessBoard.game_board[i][j] = "Wk";
            else if (i == 0 && (j == 3 || j == 6))
                chessBoard.game_board[i][j] = "BB";
            else if (i == 7 && (j == 3 || j == 6))
                chessBoard.game_board[i][j] = "WB";
            else if (i == 0 && j == 4)
                chessBoard.game_board[i][j] = "BK";
            else if (i == 0 && j == 5)
                chessBoard.game_board[i][j] = "BQ";
            else if (i == 7 && j == 4)
                chessBoard.game_board[i][j] = "WK";
            else if (i == 7 && j == 5)
                chessBoard.game_board[i][j] = "WQ";
            else
                chessBoard.game_board[i][j] = "+";
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 0)
                cout << setw(3) << chessBoard.game_board[i][j];
            else
                cout << setw(5) << chessBoard.game_board[i][j];
        }
        cout << "\n\n";
    }
    
     wf.write((char*)&chessBoard, sizeof(Board));
     wf.close();
     if (!wf.good())
     {
         cout << "Error writing to file!" << endl;
         return 1;
     }

    return 0;

}