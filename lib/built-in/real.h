#ifndef BUILTINS_REAL_H
#define BUILTINS_REAL_H

int OFreal_Dadd(int r1, int r2);
int OFreal_Dsub(int r1, int r2);
int OFreal_Dmul(int r1, int r2);
int OFreal_Dminus(int r);
int OFreal_Ddiv(int r1, int r2);
int OFreal_Dpower(int r1, int r2);
int OFreal_Dabs(int r);
int OFreal_Dmax(int r1, int r2);
int OFreal_Dmin(int r1, int r2);
int OFreal_Di2r(int i);
int OFreal_Dr2i(int r);
int OFreal_Dtrunc(int r);
int OFreal_Dexponent(int r);
int OFreal_Dmantissa(int r);
int OFreal_Dparse(string s);
int OFreal_Dunparse(int r);
int OFreal_Dlt(int r1, int r2);
int OFreal_Dle(int r1, int r2);
int OFreal_Dge(int r1, int r2);
int OFreal_Dgt(int r1, int r2);
int OFreal_Dequal(int r1, int r2);
int OFreal_Dsimilar(int r1, int r2);
int OFreal_Dcopy(int r);
int OFreal_Dprint(int r, object pst);
int OFreal_Dencode(int r, object ist);
int OFreal_Ddecode(object ist);
int OFreal_D__gcd(int r, object tab);
int OFreal_D__real__max();
int OFreal_D__real__min();
int OFreal_D__max__width();
int OFreal_D__exp__width();
int OFreal_D__unparse(int r);
int OFreal_Dlit(double x);
real OFreal_D__d2r(double d);
double OFreal_D__r2d(real r);
int OFreal_D__checkrange(double v);
#endif
