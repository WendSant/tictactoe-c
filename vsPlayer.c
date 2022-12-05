#include <stdio.h>

#include <stdlib.h>

#include <ctype.h>

#include <time.h>

char boardVsPlayer[3][3];

const char PLAYERONE = 'X';

const char PLAYERTWO = 'O';

struct rankingPlayerVsPlayer
{
    char playerOneName[50],
        playerTwoName[50];
};

struct rankingPlayerVsPlayer rankingVsPlayer;

void resetBoardVsPlayer();

void printBoardVsPlayer();

int checkFreeSpacesVsPlayer();

void playerOneMove();

void playerTwoMove();

char checkWinnerPlayer();

void printWinnerPlayer(char);

int mainPlayer()

{

    char winner = ' ';

    char response = ' ';

    printf("P1 digite seu nome: ");
    scanf("%s", rankingVsPlayer.playerOneName);
    printf("P2 digite seu nome: ");
    scanf("%s", rankingVsPlayer.playerTwoName);

    do

    {

        winner = ' ';

        response = ' ';

        resetBoardVsPlayer();

        while (winner == ' ' && checkFreeSpacesVsPlayer() != 0)

        {

            printBoardVsPlayer();

            playerOneMove();

            winner = checkWinnerPlayer();

            if (winner != ' ' || checkFreeSpacesVsPlayer() == 0)

            {

                break;
            }
            printBoardVsPlayer();
            playerTwoMove();

            winner = checkWinnerPlayer();

            if (winner != ' ' || checkFreeSpacesVsPlayer() == 0)

            {

                break;
            }
        }

        printBoardVsPlayer();

        printWinnerPlayer(winner);

        printf("\nJogar novamente? (Y/N): ");

        scanf("%c");

        scanf("%c", &response);

        response = toupper(response);

    } while (response == 'Y');

    printf("Obrigado por jogar!");

    return 0;
}

void resetBoardVsPlayer()

{

    for (int i = 0; i < 3; i++)

    {

        for (int j = 0; j < 3; j++)

        {

            boardVsPlayer[i][j] = ' ';
        }
    }
}

void printBoardVsPlayer()

{

    printf(" %c | %c | %c ", boardVsPlayer[0][0], boardVsPlayer[0][1], boardVsPlayer[0][2]);

    printf("\n---|---|---\n");

    printf(" %c | %c | %c ", boardVsPlayer[1][0], boardVsPlayer[1][1], boardVsPlayer[1][2]);

    printf("\n---|---|---\n");

    printf(" %c | %c | %c ", boardVsPlayer[2][0], boardVsPlayer[2][1], boardVsPlayer[2][2]);

    printf("\n");
}

int checkFreeSpacesVsPlayer()

{

    int freeSpaces = 9;

    for (int i = 0; i < 3; i++)

    {

        for (int j = 0; j < 3; j++)

        {

            if (boardVsPlayer[i][j] != ' ')

            {

                freeSpaces--;
            }
        }
    }

    return freeSpaces;
}

void playerOneMove()

{

    int x;

    int y;

    do

    {

        printf("Jogador %s: Escolha a linha #(1-3): ", rankingVsPlayer.playerOneName);

        scanf("%d", &x);

        x--;

        printf("Jogador %s: Escolha a coluna #(1-3): ", rankingVsPlayer.playerOneName);

        scanf("%d", &y);

        y--;

        if (boardVsPlayer[x][y] != ' ')

        {

            printf("Movimento invalido!\n");
        }

        else

        {

            boardVsPlayer[x][y] = PLAYERONE;

            break;
        }

    } while (boardVsPlayer[x][y] != ' ');
}

void playerTwoMove()

{

    int x;

    int y;

    do

    {

        printf("Jogador %s: Escolha a linha #(1-3): ", rankingVsPlayer.playerTwoName);

        scanf("%d", &x);

        x--;

        printf("Jogador %s: Escolha a coluna#(1-3): ", rankingVsPlayer.playerTwoName);

        scanf("%d", &y);

        y--;

        if (boardVsPlayer[x][y] != ' ')

        {

            printf("Movimento invalido!\n");
        }

        else

        {

            boardVsPlayer[x][y] = PLAYERTWO;

            break;
        }

    } while (boardVsPlayer[x][y] != ' ');
}

char checkWinnerPlayer()
{
    for (int i = 0; i < 3; i++)
    {
        if (boardVsPlayer[i][0] == boardVsPlayer[i][1] && boardVsPlayer[i][0] == boardVsPlayer[i][2])
        {
            return boardVsPlayer[i][0];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (boardVsPlayer[0][i] == boardVsPlayer[1][i] && boardVsPlayer[0][i] == boardVsPlayer[2][i])
        {
            return boardVsPlayer[0][i];
        }
    }
    if (boardVsPlayer[0][0] == boardVsPlayer[1][1] && boardVsPlayer[0][0] == boardVsPlayer[2][2])
    {
        return boardVsPlayer[0][0];
    }
    if (boardVsPlayer[0][2] == boardVsPlayer[1][1] && boardVsPlayer[0][2] == boardVsPlayer[2][0])
    {
        return boardVsPlayer[0][2];
    }
    return ' ';
}

void printWinnerPlayer(char winner)
{
    if (winner == PLAYERONE)

    {
        printf("Ganhador: %s", rankingVsPlayer.playerOneName);
        FILE *file;
        file = fopen("ranking.txt", "a");
        fprintf(file, "%s\r\n", rankingVsPlayer.playerOneName);
        fclose(file);
    }

    else if (winner == PLAYERTWO)

    {
        printf("Ganhador: %s", rankingVsPlayer.playerTwoName);
        FILE *file;
        file = fopen("ranking.txt", "a");
        fprintf(file, "%s\r\n", rankingVsPlayer.playerTwoName);
        fclose(file);
    }

    else
    {
        printf("Empate!");
    }
}