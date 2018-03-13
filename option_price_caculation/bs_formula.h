#ifndef BS_FORMULA_H_INCLUDED
#define BS_FORMULA_H_INCLUDED
//欧式期权BS公式
double option_price_bs(const double &S, //标的价格
                            const double &X, //执行价格
                            const double &r,//无风险利率
                            const double &sigma,//市场波动率
                            const double &time,//年化到期时间
                             bool call//True为计算Call，False为计算Put
                            );
#endif // BS_FORMULA_H_INCLUDED
