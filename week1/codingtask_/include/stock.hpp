#ifndef  STOCK_H_
#define  STOCK_H_

#include <string>
//声明一个类
class Stock

{
    private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot(){total_val=share_val*shares;}

    public:
    Stock();             //构造函数
    Stock(const std::string &co, long n=0,double pr=0.0);
    ~Stock();            //析构函数
    void acquire(const std::string & co ,long n, double pr);     //资产情况
    void buy(long num,double price);                             //购入股票
    void sell(long num,double price);                            //卖出股票
    void update(double price);                                   //更新资产

    //以下两个成员函数被引用，用到this指针，使用const限定
    void show() const;
    const Stock& topval(const Stock& s) const;                   //股票种类中比较出最大值
};


#endif