#ifndef BUILTIN_CHAR_H
#define BUILTIN_CHAR_H

int OFchar_Di2c(int i);
int OFchar_Dc2i(int c);
int OFchar_Dlt(int c1, int c2);
int OFchar_Dle(int c1, int c2);
int OFchar_Dge(int c1, int c2);
int OFchar_Dgt(int c1, int c2);
int OFchar_Dequal(int c1, int c2);
int OFchar_Dsimilar(int c1, int c2);
int OFchar_Dcopy(int c);
int OFchar_Dprint(int c, object pst);
int OFchar_Dencode(int c, object ist);
int OFchar_Ddecode(object ist);
int OFchar_D__gcd(int c, object tab);
int OFchar_Dwidth(int c);

#endif
