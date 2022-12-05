#include <stdio.h>
#include "vsMaquina.c"
#include "vsPlayer.c"

int main()
{
    int option = 0;
    do
    {
        printf("=================================\n");
        printf("========Escolha uma opção========\n");
        printf("=================================\n");
        printf("1 - Jogar contra Maquina\n");
        printf("2 - Jogar contra player\n");
        printf("3 - Ranking\n");
        printf("4 - Creditos\n");
        printf("5 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            mainTeste();
            break;
        case 2:
            mainPlayer();
            break;
        case 3:
            printf("Ranking Vencedores:\n");
            showRanking();
            break;
        case 4:
            printf("Cŕeditos:\n");
            showCreditos();
            break;
        case 5:
            printf("Obrigado por jogar");
            break;
        default:
            printf("Opção invalida\n");
            break;
        }
    } while (option != 5);

    return 0;
}

void showRanking()
{
    FILE *file;
    file = fopen("ranking.txt", "r");
    char frase[100];
    while (fgets(frase, 100, file) != NULL)
    {
        printf("%s", frase);
    }
    fclose(file);
}

void showCreditos()
{
    printf("Feito por: Eu, mim, apenas eu, just me, me, myself & i\n");
    printf("Oh, it's just me, myself and I\nSolo ride until I die\n'Cause I got me for life\n\n");
}