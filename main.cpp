#include<iostream>
#include<time.h>

char player = 'X';
char cpu = 'O';
bool game_over = false;
bool diagonal_winner;
bool horizontal_winner;
bool vertical_winner;

void display_board(char* _board, unsigned int board_size = 9);
void run_game(char* _board, unsigned int board_size = 9);
void check_winner(char* _board);
void check_diagonal(char* _board, unsigned int board_size = 9);
void check_horizontal(char* _board, unsigned int board_size = 9);
void check_vertical(char* _board, unsigned int boarboard_sized_size = 9);
void check_tie(char* _board, unsigned int board_size = 9);
void restart(char* _board, unsigned int board_size = 9);
void try_again_inp(char* _board, bool try_again);

int main() {
    std::srand(time(0));

    char board[] = {
        '-', '-', '-',
        '-', '-', '-',
        '-', '-', '-'
    };

    run_game(board, sizeof(board) / sizeof(char));

    return 0;
}


void display_board(char* _board, unsigned int board_size) {
    std::system("clear");

    std::cout << "1 | 2 | 3\n--+---+---\n4 | 5 | 6\n--+---+---\n7 | 8 | 9\n\n";

    for(int i = 0; i < board_size; i++) {

        if((i + 1) % 3 == 0) {
            std::cout << _board[i] << std::endl;
            if(i < board_size - 1) {
                std::cout << "--+---+---" << std::endl;
            }
        }
        else {
            std::cout << _board[i] << " | ";
        }

    }

}

void run_game(char* _board, unsigned int board_size) {
    short index;

    unsigned short rand_index = rand() % 9;

    while(!game_over) {

        display_board(_board);
        std::cin >> index;

        if(index > board_size || index <= 0) {
            std::cerr << "!!!ERROR!!!" << std::endl;
            std::cout << '\n';
        }

        if(index > 0) {
            if(_board[index - 1] == '-') {
                _board[index - 1] = player;

                while(_board[rand_index] != '-') {
                    rand_index = rand() % 9 + 0;
                }

                if(_board[rand_index] == '-') {
                    _board[rand_index] = cpu;
                }

                display_board(_board);
                check_winner(_board);

            }
        }
        else {
            std::cerr << "!!!ERROR!!!" << std::endl;
            std::cout << '\n';
        }

    }

}

void check_winner(char* _board) {
    check_diagonal(_board);
    check_horizontal(_board);
    check_vertical(_board);
    check_tie(_board);
}

void check_diagonal(char* _board, unsigned int board_size) {
    if(_board[0] == _board[4] && _board[0] == _board[8] && _board[0] != '-') {

        diagonal_winner = true;
        game_over = true;

        bool try_again;

        if(_board[0] == player) {
            std::cout << '\n' << player << " wins" << std::endl;
            try_again_inp(_board, try_again);
        }
        else {
            std::cout << '\n' << cpu << " wins" << std::endl;
            try_again_inp(_board, try_again);
        }
    }

    else if(_board[2] == _board[4] && _board[2] == _board[6] && _board[2] != '-') {

        diagonal_winner = true;
        game_over = true;

        bool try_again;

        if(_board[2] == player) {
            std::cout << '\n' << player << " wins" << std::endl;
            try_again_inp(_board, try_again);
        }
        else {
            std::cout << '\n' << cpu << " wins" << std::endl;
            try_again_inp(_board, try_again);
        }
    }
}

void check_horizontal(char* _board, unsigned int board_size) {
    for(int i = 0; i < board_size; i++) {
        if(i % 3 == 0) {
            if((_board[i] == _board[i + 1]) && (_board[i] == _board[i + 2]) && (_board[i] != '-')) {

                horizontal_winner = true;
                game_over = true;

                bool try_again;

                if(_board[i] == player) {
                    std::cout << '\n' << player << " wins" << std::endl;
                    try_again_inp(_board, try_again);
                }
                else {
                    std::cout << '\n' << cpu << " wins" << std::endl;
                    try_again_inp(_board, try_again);
                }
            }
        }
    }
}

void check_vertical(char* _board, unsigned int board_size) {
    for(int i = 0; i < 3; i++) {
        if(i == 0 || i == 1 || i == 2) {
            if(_board[i] == _board[i + 3] && _board[i] == _board[i + 6] && _board[i] != '-') {

                vertical_winner = true;
                game_over = true;

                bool try_again;

                if(_board[i] == player) {
                    std::cout << player << " wins" << std::endl;
                    try_again_inp(_board, try_again);
                }
                else {
                    std::cout << cpu << " wins" << std::endl;
                    try_again_inp(_board, try_again);
                }
            }
        }
    }
}

void check_tie(char* _board, unsigned int board_size) {

    int index = 0;

    for(int i = 0; i < board_size; i++) {
        if(_board[i] != '-') {
            index++;
        }
    }

    if(index == board_size - 1) {
        if(!vertical_winner && !horizontal_winner && !diagonal_winner) {
            game_over = true;
            std::cout << "Tie" << std::endl;
        }
    }
}

void restart(char* _board, unsigned int board_size) {
    for(int i = 0; i < board_size; i++) {
        _board[i] = '-';
    }
    bool diagonal_winner = false;
    bool horizontal_winner = false;
    bool vertical_winner = false;
    game_over = false;
}

void try_again_inp(char* _board,bool try_again) {
    std::cout << "input 1 to continue or 0 to exit" << std::endl;
    std::cin >> try_again;
    switch(try_again) {
        case 1: {
            restart(_board);
            break;
        }
        case 0: {
            break;
        }
        default: {
            break;
        }
    }
}

