#include <iostream>

#include<stock.hpp>
int main()
{
    Stock zheng;
    zheng.acquire("Njust", 20, 12.50);
    zheng.show();
    zheng.buy(15, 18.125);
    zheng.show();
    zheng.sell(400, 20.00);
    zheng.show();
    zheng.buy(300000, 40.125);
    zheng.show();
    zheng.sell(300000, 0.125);
    zheng.show();
    return 0;
}