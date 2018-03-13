#ifndef IV_FORMULA_H_INCLUDED
#define IV_FORMULA_H_INCLUDED
//隐含波动率（二分法）
double iv_bisections(const double &S,
                     const double &X,
                     const double &r,
                     const double &time,
                     const double &option_price);

//隐含波动率（牛顿法)
double iv_newton(const double &S,
                 const double &X,
                 const double &r,
                 const double &time,
                 const double &option_price);
#endif // IV_FORMULA_H_INCLUDED
