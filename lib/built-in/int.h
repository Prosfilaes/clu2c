#ifndef BUILTIN_INT_H
#define BUILTIN_INT_H

int OFint_Dadd(int i1, int i2);
int OFint_Dsub(int i1, int i2);
int OFint_Dmul(int i1, int i2);
int OFint_Dminus(int i);
int OFint_Ddiv(int i1, int i2);
int OFint_Dmod(int i1, int i2);
int OFint_Dpower(int i1, int i2);
int OFint_Dabs(int i);
int OFint_Dmax(int i1, int i2);
int OFint_Dmin(int i1, int i2);
int OFint_Dfrom__to__by(bool init, object **ivarp, int from, int to, int by);
int OFint_Dfrom__to(bool init, object **ivarp, int from, int to);
int OFint_Dparse(string s);
int OFint_Dunparse(int i);
int OFint_Dlt(int i1, int i2);
int OFint_Dle(int i1, int i2);
int OFint_Dge(int i1, int i2);
int OFint_Dgt(int i1, int i2);
int OFint_Dequal(int i1, int i2);
int OFint_Dsimilar(int i1, int i2);
int OFint_Dcopy(int i);
int OFint_Dprint(int i, object pst);
int OFint_Dencode(int i, object ist);
int OFint_Ddecode(object ist);
int OFint_D__gcd(int i, object tab);
int OFint_D__div(int i1, int i2);
int OFint_D__mod(int i1, int i2);
#endif
