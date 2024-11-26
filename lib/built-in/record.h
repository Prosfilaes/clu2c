#ifndef BUILTIN_RECORD_H
#define BUILTIN_RECORD_H
int OFrecord_Dget(int i, record r);
int OFrecord_Dset(int i, record r, object e);
int OFrecord_Dr__gets__r(record r1, record r2);
int OFrecord_Dr__gets__s(record r, struct_ s);
int OFrecord_Dequal(record r1, record r2);
int OFrecord_Dsimilar(oplist_t op_list, record r1, record r2);
int OFrecord_Dsimilar1(oplist_t op_list, record r1, record r2);
int OFrecord_Dcopy1(record r);
int OFrecord_Dcopy(oplist_t op_list, record r);
int OFrecord_Dencode(oplist_t op_list, record r, object ist);
int OFrecord_Ddecode(oplist_t op_list, object ist);
int OFrecord_Dprint(oplist_t op_list, record r, object pst);
int OFrecord_D__gcd(oplist_t op_list, record r, object tab);
record OFrecord_D__alloc(int nr_components);
#endif
