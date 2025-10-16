#include <iostream>
#include<stock.hpp>

const int num=3;
int main()
{
    Stock stocks[num]={
        Stock("dji",12,20.0),
        Stock("yushu",200,2.0),
        Stock("zhiyuan",60,6.5),
    };
    std::cout<<"Stock holdings:\n";
    int st;
    for(st=0;st<num;st++)
        stocks[st].show();          //遍历展示股票持有情况

    const Stock *top=&stocks[0];
    for(st=1;st<num;st++)
        top=&top->topval(stocks[st]); //遍历选出最高价值的股票类型
    std::cout<<"\nMost valuable holding:\n";
    top->show();
    return 0;
} 