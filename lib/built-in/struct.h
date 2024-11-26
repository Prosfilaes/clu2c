#ifndef BUILTIN_STRUCT_H
#define BUILTIN_STRUCT_H
int OFstruct_Dget(int i, struct_ s);
int OFstruct_Dreplace(int i, struct_ s, object e);
int OFstruct_Ds2r(struct_ s);
int OFstruct_Dr2s(record r);
int OFstruct_Dequal(oplist_t op_list, struct_ s1, struct_ s2);
int OFstruct_Dsimilar(oplist_t op_list, struct_ s1, struct_ s2);
int OFstruct_Dcopy(oplist_t op_list, struct_ s);
int OFstruct_Dencode(oplist_t op_list, struct_ s, object ist);
int OFstruct_Ddecode(oplist_t op_list, object ist);
int OFstruct_Dprint(oplist_t op_list, struct_ s, object pst);
int OFstruct_D__gcd(oplist_t op_list, struct_ s, object tab);
struct_ OFstruct_D__alloc(int nr_components);
#endif
