#ifndef BUILTIN_ONEOF_H
#define BUILTIN_ONEOF_H

int OFoneof_Dmake(int tag, object value);
int OFoneof_Dis(int tag, oneof o);
int OFoneof_Dvalue(int tag, oneof o);
int OFoneof_Do2v(oneof o);
int OFoneof_Dv2o(variant v);
int OFoneof_Dequal(oplist_t op_list, oneof o1, oneof o2);
int OFoneof_Dsimilar(oplist_t op_list, oneof o1, oneof o2) ;
int OFoneof_Dcopy(oplist_t op_list, oneof o);
int OFoneof_Dencode(oplist_t op_list, oneof o, object ist);
int OFoneof_Ddecode(oplist_t op_list, object ist);
int OFoneof_Dprint(oplist_t op_list, oneof o, object pst);
int OFoneof_D__gcd(oplist_t op_list, oneof o, object tab);

#endif
