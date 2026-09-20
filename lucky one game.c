#include <stdio.h>

#define SIZE 6
char board[6][6] = {{'*','*','X','*','*','*'},{'*','*','*','*','*','*'},{'*','*','*','*','*','*'},{'*','*','*','*','*','*'},{'*','*','*','O','*','*'},{'*','*','*','*','*','*'}};
void gameBoard(){
    printf(" Welcome to lucky one game \n");
    printf("    0   1   2   3   4   5 \n");
    printf("   ___ ___ ___ ___ ___ ___\n\n");
        printf("0 ");
    printf("| %c | %c | %c | %c | %c | %c | \n",board[0][0],board[0][1],board[0][2],board[0][3],board[0][4],board[0][5]);
    printf("   ___ ___ ___ ___ ___ ___\n\n");
        printf("1 ");
    printf("| %c | %c | %c | %c | %c | %c |\n",board[1][0],board[1][1],board[1][2],board[1][3],board[1][4],board[1][5]);
    printf("   ___ ___ ___ ___ ___ ___\n\n");
        printf("2 ");
    printf("| %c | %c | %c | %c | %c | %c |\n",board[2][0],board[2][1],board[2][2],board[2][3],board[2][4],board[2][5]);
    printf("   ___ ___ ___ ___ ___ ___\n\n");
        printf("3 ");
    printf("| %c | %c | %c | %c | %c | %c |\n",board[3][0],board[3][1],board[3][2],board[3][3],board[3][4],board[3][5]);
    printf("   ___ ___ ___ ___ ___ ___\n\n");
        printf("4 ");
    printf("| %c | %c | %c | %c | %c | %c |\n",board[4][0],board[4][1],board[4][2],board[4][3],board[4][4],board[4][5]);
    printf("   ___ ___ ___ ___ ___ ___\n\n");
        printf("5 ");
    printf("| %c | %c | %c | %c | %c | %c |\n",board[5][0],board[5][1],board[5][2],board[5][3],board[5][4],board[5][5]);
    printf("   ___ ___ ___ ___ ___ ___\n\n");
} 

int checkWin(char f) {
 
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == f && board[i][1] == f && board[i][2] == f && board[i][3] == f && board[i][4] == f && board[i][5] == f)
        return 1;
        if (board[0][i] == f && board[1][i] == f && board[2][i] == f && board[3][i] == f && board[4][i] == f && board[5][i] == f) 
        return 1;
    }
   
    if (board[0][0] == f && board[1][1] == f && board[2][2] == f && board[3][3] == f && board[4][4] == f && board[5][5] == f) 
    return 1;
    if (board[0][5] == f && board[1][4] == f && board[2][3] == f && board[3][2] == f && board[4][1] == f && board[5][0] == f) 
    return 1;

    return 0;
}

int placeMark(int r, int c, char playerMark) {
     if (r < 0 || r >= SIZE || c < 0 || c >= SIZE || board[r][c] != '*'){
         return 0;
     }
     if ((r > 0 && board[r-1][c] == playerMark) || (r < 5 && board[r+1][c] == playerMark) || (c > 0 && board[r][c-1] == playerMark) ||(c < 5 && board[r][c+1] == playerMark) ||(r > 0 && c > 0 && board[r-1][c-1] == playerMark) ||(r > 0 && c < 5 && board[r-1][c+1] == playerMark) ||(r < 5 && c > 0 && board[r+1][c-1] == playerMark) || (r < 5 && c < 5 && board[r+1][c+1] == playerMark)){
    board[r][c] = playerMark;
}
 else{
     return 0;
 }
}
int main() {
    int row, column, moves = 0, turn = 0;
    char player[] = {'X', 'O'};


    while (moves < SIZE * SIZE) {
        gameBoard();
        int currentPlayer = turn % 2;
        char *player_mark= &player[currentPlayer]; 

        printf("P%d(%c), enter Row and Column: ", currentPlayer + 1, *player_mark);
        scanf(" %d %d",&row, &column);
        
        if (placeMark(row, column, *player_mark)) {
        turn++;
            moves++;
        }else {
            printf("\n INVALID MOVE!\n");
        }
        if (checkWin(*player_mark)) {
                gameBoard();
                printf("p%d(%c) wins!\n", currentPlayer + 1, *player_mark);
                return 0;
            
    }
                    
}
    gameBoard();
    printf("It's a draw!\n");
    return 0;
}