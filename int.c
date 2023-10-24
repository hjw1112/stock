#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define MIN -1000000
#define MAX 1000000

int mae_su(int current_money, int price);
int mae_do(int current_money, int price);

int main()
{
    printf("a사기 b팔기 q조회\n");

    int whole = 0;
    int value = 0;
    int prf = 0;
    int stock = 0;
    int money = 100000;
    srand(time(NULL));
    int number = 1000;

    while (1)
    {

        int buy = 0;
        int sell = 0;
        int price = 1000;

        number += (rand() % 201) - 100;
        number = (number < MIN) ? MIN : ((number > MAX) ? MAX : number);

        printf("%d 원\n", number);

        Sleep(1000); // 1초 대기
        price = number;

        if (kbhit())
        {
            int keyinput = getche();
            if (keyinput == 'a')
            {
                printf("\n구입 개수 선택: ");
                scanf("%d", &buy);
                printf("%d 구입\n", buy);
                money = mae_su(money, price);
                printf("Updated money: %d\n", money);

                stock = stock + buy;
            }
            if (keyinput == 'b')
            {
                printf("\n판매 개수 선택: ");
                scanf("%d", &sell);
                printf("%d 판매\n", sell);
                money = mae_do(money, price);
                printf("Updated money: %d\n", money);

                stock = stock - sell;
            }
            if (keyinput == 'q')
            {
                value = stock * number;
                whole = value + money;
                prf = whole - 100000;
                printf("\n남은 예산: %d", money);
                printf("  %d보유", stock);
                printf("  손익%d원\n", prf);
            }
        }
    }

    return 0;
}

int mae_su(int current_money, int price)
{
    int new_money = current_money - price;
    return new_money;
}

int mae_do(int current_money, int price)
{
    int new_money = current_money + price;
    return new_money;
}