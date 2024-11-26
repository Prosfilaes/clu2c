#ifndef BUILTIN_BOOL_H
#define BUILTIN_BOOL_H

int OFbool_Dand(bool b1, bool b2);
int OFbool_Dor(bool b1, bool b2);
int OFbool_Dnot(bool b);
int OFbool_Dequal(bool b1, bool b2);
int OFbool_Dsimilar(bool b1, bool b2);
int OFbool_Dcopy(bool b);
int OFbool_Dprint(bool b, object pst);
int OFbool_Dencode(bool b, object ist);
int OFbool_Ddecode(object ist);
int OFbool_D__gcd(bool b, object tab);

#endif
