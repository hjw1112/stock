#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define MIN 1
#define MAX 100000000

#define ramin 1.5
#define ramax 1.5

int mae_su(int current_money, int tra, int price);
int mae_do(int current_money, int tra, int price);

int main()
{
    printf("a사기 b팔기 q조회\n");

    int whole = 0;
    int value = 0;
    int prf = 0;
    int stock = 0;
    int money = 100000;
    srand(time(NULL));
    int number = 10000;
    float ra = 0;
    float ran = 0;

    while (1)
    {

        int buy = 0;
        int sell = 0;
        int price = 1000;

        ra += (rand() % 3) - 1.5;
        ra = (ra < ramin) ? ramin : ((ra > ramax) ? ramax : ra);

        number += (rand() % 3001 * ra) - 1500 * ra;
        number = (number < MIN) ? MIN : ((number > MAX) ? MAX : number);

        printf("%d 원\n", number);

        Sleep(1300); // 1.3초 대기
        price = number;

        if (kbhit())
        {
            int keyinput = getch();
            if (keyinput == 'a')
            {
                printf("\n구입 개수 선택: ");
                scanf("%d", &buy);
                if (buy * number <= money)
                {
                    printf("%d 구입\n", buy);
                    money = mae_su(money, buy, price);
                    printf("잔액: %d\n", money);

                    stock = stock + buy;
                }
                else
                {
                    printf("돈 부족\n");
                }
            }
            if (keyinput == 'b')
            {
                printf("\n판매 개수 선택: ");
                scanf("%d", &sell);
                if (sell <= stock)
                {
                    printf("%d 판매\n", sell);
                    money = mae_do(money, sell, price);
                    printf("잔액: %d\n", money);

                    stock = stock - sell;
                }
                else
                {
                    printf("주 부족\n");
                }
            }
            if (keyinput == 'q')
            {
                value = stock * number;
                whole = value + money;
                prf = whole - 100000;
                printf("\n남은 예산: %d원", money);
                printf("  %d개 보유", stock);
                printf("  손익%d원\n", prf);
            }
        }
    }

    return 0;
}

int mae_su(int current_money, int tra, int price)
{
    int new_money = current_money - price * tra;
    return new_money;
}

int mae_do(int current_money, int tra, int price)
{
    int new_money = current_money + price * tra;
    return new_money;
}
