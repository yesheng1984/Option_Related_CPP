#include <iostream>
#include "normdist.h"
#include "bs_formula.h"
#include "iv_formula.h"

using namespace std;

int main()
{
    cout << "N(1): " <<N(1)<< endl;
    double S = 50;
    double X = 50;
    double r = 0.10;
    double sigma = 0.30;
    double time = 0.50;
    cout <<"欧式看涨期权价格: ";
    double c = option_price_bs(S,X,r,sigma,time,true);
    double p = option_price_bs(S,X,r,sigma,time,false);
    cout <<c<<endl;
    cout <<"欧式看跌期权价格: ";
    cout <<p<<endl;
    cout<<"二分法计算隐含波动率: ";
    cout<< iv_bisections(S,X,r,time,c)<<endl;
    cout<<"牛顿法计算隐含波动率: ";
    cout<<iv_newton(S,X,r,time,c)<<endl;
    return 0;
}
