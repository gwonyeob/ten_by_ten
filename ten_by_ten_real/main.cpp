#include<iostream>
#include<array> 
#include<cstdlib> 
#include<ctime>
#include<string>
using namespace std;

int total_point;
array<array<string, 10>, 10> board;
array<array<string, 10>, 10> the_board;
array<array<string, 5>, 5> part;


struct rand_nums { //create_part -> return
    int n1;
    int n2;
    int n3;
};

void tenbytengame() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            the_board[i][j] = " ";
        }
    }
    total_point = 0;
}


void draw_board(array<array<string, 10>, 10> board) {
    int x = board.size();
    int y = board[0].size();
    cout << "    ";
    for (int a = 0; a < x; ++a) {
        cout << "  " << a + 1 << "   ";
    }
    cout << endl;

    cout << "    ";
    for (int i = 0; i < x; ++i) {
        cout << "_____ ";
    }
    cout << endl;

    for (int i = 0; i < y; ++i) {
        cout << "   |";
        for (int j = 0; j < x; ++j) {
            cout << "     |";
        }
        cout << endl;

        if (i < 9) {
            cout << i + 1 << " ";
        }
        else {
            cout << i + 1;
        }

        cout << " |";
        for (int j = 0; j < x; ++j) {
            cout << "  " << board[i][j] << "  |";
        }
        cout << endl;

        cout << "   |";
        for (int i = 0; i < x; ++i) {
            cout << "_____|";
        }
        cout << endl;
    }
}

void show_part(array<array<string, 5>, 5> part) {
    int x = part.size();
    int y = part[0].size();
    cout << " ";
    for (int a = 0; a < x; ++a) {
        cout << "_____ ";
    }
    cout << endl;

    for (int i = 0; i < y; ++i) {
        cout << "|";
        for (int a = 0; a < x; ++a) {
            cout << "     |";
        }
        cout << endl;

        cout << "|";
        for (int j = 0; j < x; ++j) {
            cout << "  " << part[i][j] << "  |";
        }
        cout << endl;

        cout << "|";
        for (int a = 0; a < x; ++a) {
            cout << "_____|";
        }
        cout << endl;
    }
}

array<array<string, 5>, 5>block(int n) {
    array<array<string, 5>, 5> part;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            part[i][j] = " ";
        }
    }
    switch (n) {
    case 1:
        part[2][2] = "●";
        break;
    case 2:
        part[1][2] = "■";
        part[2][2] = "●";
        break;
    case 3:
        part[1][2] = "■";
        part[2][2] = "●";
        part[3][2] = "■";
        break;
    case 4:
        part[0][2] = "■";
        part[1][2] = "■";
        part[2][2] = "●";
        part[3][2] = "■";
        break;
    case 5:
        part[0][2] = "■";
        part[1][2] = "■";
        part[2][2] = "●";
        part[3][2] = "■";
        part[4][2] = "■";
        break;
    case 6:
        part[2][1] = "■";
        part[2][2] = "●";
        break;
    case 7:
        part[2][1] = "■";
        part[2][2] = "●";
        part[2][3] = "■";
        break;
    case 8:
        part[2][0] = "■";
        part[2][1] = "■";
        part[2][2] = "●";
        part[2][3] = "■";
        break;
    case 9:
        part[2][0] = "■";
        part[2][1] = "■";
        part[2][2] = "●";
        part[2][3] = "■";
        part[2][4] = "■";
        break;
    case 10:
        part[1][1] = "■";
        part[1][2] = "■";
        part[2][2] = "●";
        break;
    case 11:
        part[2][1] = "■";
        part[2][2] = "●";
        part[3][1] = "■";
        break;
    case 12:
        part[2][2] = "●";
        part[3][2] = "■";
        part[3][3] = "■";
        break;
    case 13:
        part[1][3] = "■";
        part[2][2] = "●";
        part[2][3] = "■";
        break;
    case 14:
        part[1][1] = "■";
        part[1][2] = "■";
        part[2][1] = "■";
        part[2][2] = "●";
        break;
    case 15:
        part[1][1] = "■";
        part[1][2] = "■";
        part[1][3] = "■";
        part[2][2] = "○";
        part[2][3] = "■";
        part[3][3] = "■";
        break;
    case 16:
        part[1][1] = "■";
        part[1][2] = "■";
        part[1][3] = "■";
        part[2][1] = "■";
        part[2][2] = "○";
        part[3][1] = "■";
        break;
    case 17:
        part[1][1] = "■";
        part[2][1] = "■";
        part[2][2] = "○";
        part[3][1] = "■";
        part[3][2] = "■";
        part[3][3] = "■";
        break;
    case 18:
        part[1][3] = "■";
        part[2][2] = "○";
        part[2][3] = "■";
        part[3][1] = "■";
        part[3][2] = "■";
        part[3][3] = "■";
        break;
    case 19:
        part[1][1] = "■";
        part[1][2] = "■";
        part[1][3] = "■";
        part[2][1] = "■";
        part[2][2] = "●";
        part[2][3] = "■";
        part[3][1] = "■";
        part[3][2] = "■";
        part[3][3] = "■";
        break;
    }
    return part;
}
rand_nums create_part() {
    rand_nums rd;
    rd.n1 = rand() % 19 + 1;
    rd.n2 = rand() % 19 + 1;
    rd.n3 = rand() % 19 + 1;
    return rd;
}
void playing_game() {
    draw_board(the_board);
    rand_nums value = create_part();
    array<array<string, 5>, 5> part1 = block(value.n1);
    cout << 1 << endl;
    show_part(part1);
    array<array<string, 5>, 5> part2 = block(value.n2);
    cout << 2 << endl;
    show_part(part2);
    array<array<string, 5>, 5> part3 = block(value.n3);
    cout << 3 << endl;
    show_part(part3);

}
void game_end(array<array<string, 10>, 10> board, array<array<string, 5>, 5> part) {

}

int main() {
    tenbytengame();
    playing_game();
}