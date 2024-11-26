#ifndef BUILTIN_STRING_H
#define BUILTIN_STRING_H
int OFstring_Dsize(string s);
int OFstring_Dempty(string s);
int OFstring_Dindexs(string s1, string s2);
int OFstring_Dindexc(int c, string s);
int OFstring_Dc2s(int c);
int OFstring_Dconcat(string s1, string s2);
int OFstring_Dappend(string s, int c);
int OFstring_Dfetch(string s, int i);
int OFstring_Drest(string s, int i);
int OFstring_Dsubstr(string s, int at, int cnt);
int OFstring_Ds2ac(string s);
int OFstring_Dac2s(array a);
int OFstring_Ds2sc(string s);
int OFstring_Dsc2s(sequence s);
int OFstring_Dchars(bool init, object **ivarp, string s);
int OFstring_Dlt(string s1, string s2);
int OFstring_Dle(string s1, string s2);
int OFstring_Dge(string s1, string s2);
int OFstring_Dgt(string s1, string s2);
int OFstring_Dequal(string s1, string s2);
int OFstring_Dsimilar(string s1, string s2);
int OFstring_Dcopy(string s);
int OFstring_Dprint(string s, object pst);
int OFstring_Dencode(string s, object ist);
int OFstring_Ddecode(object ist);
int OFstring_D__gcd(string s, object tab);
int OFstring_Dwidth(string s);
int OFstring_D__cmp(string s1, string s2);
int OFstring_D__equal(string s1, string s2);
char *OFstring_D__s2cs(string s);
string OFstring_D__cs2s(char *s);
char *OFstring_D__copy(char *s);
string OFstring_D__predict(int size);
int OFstring_D__concat(string s1, string s2);
#endif
