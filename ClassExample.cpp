#include <iostream>
#include <string>

using namespace std;

class Pawn
{
    public:
        int loc_x;
        int loc_y;
        string side;
        bool has_moved;

        Pawn(string color, int pos)
        {
            if (color.compare("B") == 0)
            {
                loc_x = pos;
                loc_y = 1;
                side = color;
            }
            else
            {
                loc_x = pos;
                loc_y = 6;
                side = color;
            }
            has_moved = 0;
        }

        void movePos(int posy)
        {
            if (side.compare("B") == 0)
                if (has_moved == 0)
                    if (posy <= (loc_y + 2) && posy > loc_y)
                    {
                        loc_y = posy;
                        has_moved = 1;
                    }
                    else
                        cout << "Invalid Move\n";
                else
                    if (posy == (loc_y + 1))
                        loc_y = posy;
                    else
                        cout << "Invalid Move\n";
            else
                if (has_moved == 0)
                    if (posy >= (loc_y - 2) && posy < loc_y)
                    {
                        loc_y = posy;
                        has_moved = 1;
                    }
                    else
                        cout << "Invalid Move\n";
                else
                    if (posy == (loc_y - 1))
                        loc_y = posy;
                    else
                        cout << "Invalid Move\n";
        }

        void attackPos(int posx, int posy)
        {
            if (side.compare("B") == 0)
                if (posy == (loc_y + 1) && ((posx == loc_x + 1) || (posx == loc_x - 1)))
                {
                    loc_x = posx;
                    loc_y = posy;
                    has_moved = 1;
                }
                else
                    cout << "Invalid Move\n";
            else
                if (posy == (loc_y - 1) && ((posx == loc_x + 1) || (posx == loc_x - 1)))
                {
                    loc_y = posy;
                    has_moved = 1;
                }
                else
                    cout << "Invalid Move\n";
        }
};

int main()
{
    Pawn test("B", 1);
    test.movePos(3);
    test.movePos(4);
    cout << test.loc_x << test.loc_y << "\n";
    cout << test.has_moved << "\n";
    cout << test.side;
}