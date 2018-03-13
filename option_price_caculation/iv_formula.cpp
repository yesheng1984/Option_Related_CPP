#include "normdist.h"
#include <cmath>
#include "iv_formula.h"
#include "bs_formula.h"

double iv_bisections(const double &S,
                     const double &X,
                     const double &r,
                     const double &time,
                     const double &option_price)
{
    const double ACCURACY = 1.0e-5;
    const int MAX_ITERATIONS = 100;
    const double ERROR = -1e40;
    //确定隐含波动率的上、下限
    double sigma_low = 1e-5;
    double sigma_high = 0.5;
    for(int i = 0;i < MAX_ITERATIONS; i++)
    {
        double sigma = (sigma_low + sigma_high) * 0.5;
        double price = option_price_bs(S,X,r,sigma,time,true);
        double test = (price - option_price);
        if(fabs(test) < ACCURACY){return sigma;};
        if(test < 0.0){sigma_low = sigma;}
        else{sigma_high = sigma;}
    }
    return ERROR;
}
double iv_newton(const double &S,
                 const double &X,
                 const double &r,
                 const double &time,
                 const double &option_price)
{
    const double ACCURACY = 1.0e-5;
    const int MAX_ITERATIONS = 100;
    const double ERROR = -1e40;
    double time_sqrt = sqrt(time);
    //隐含波动率初始值
    double sigma = (option_price/S)/(0.398*time_sqrt);
    for(int i = 0;i<MAX_ITERATIONS;i++)
    {
        double price = option_price_bs(S,X,r,sigma,time,true);
        double diff = option_price - price;
        if(fabs(diff)< ACCURACY) return sigma;
        double d1 = (log(S/X) + r*time)/(sigma * time_sqrt) + 0.5*sigma*time_sqrt;
        double vega = S *time_sqrt*N(d1);
        sigma = sigma + diff/vega;
    }
    return ERROR;
}
