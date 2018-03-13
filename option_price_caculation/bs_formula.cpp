#include "bs_formula.h"
#include "normdist.h"
#include <cmath>

double option_price_bs(const double &S, //标的价格
                            const double &X, //执行价格
                            const double &r,//无风险利率
                            const double &sigma,//市场波动率
                            const double &time,//年化到期时间
                            bool call//True为计算Call，False为计算Put
                            )
{
    double time_sqrt = sqrt(time);
    double d1 = (log(S / X) + r * time)/(sigma * time_sqrt) + 0.5 * sigma * time_sqrt;
    double d2 = d1 - (sigma*time_sqrt);
    double price = S * N(d1) - X*exp(-r*time) * N(d2);
    if(!call)
        price = price + X * exp(-r*time) - S; //根据期权平价公式计算 C + X *e^(-rT) = P + S
//    if(call)
//        price = S * N(d1) - X*exp(-r*time) * N(d2);
//    else
//        price =  X*exp(-r*time)*(1-N(d2)) - S * (1 - N(d1));
    return price;
}
