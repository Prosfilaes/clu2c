#ifndef BUILTIN_NULL_H
#define BUILTIN_NULL_H
int OFnull_Dequal(null n1, null n2);
int OFnull_Dsimilar(null n1, null n2);
int OFnull_Dcopy(null n);
int OFnull_Dprint(null n, object pst);
int OFnull_Dencode(null n, object ist);
int OFnull_Ddecode(object ist);
int OFnull_D__gcd(null n, object tab);
#endif
