#ifndef BUILTIN_VARIANT_H
#define BUILTIN_VARIANT_H
int OFvariant_Dmake(int tag, object value);
int OFvariant_Dchange(int tag, variant v, object value);
int OFvariant_Dis(int tag, variant v);
int OFvariant_Dvalue(int tag, variant v);
int OFvariant_Dv__gets__v(variant v1, variant v2);
int OFvariant_Dv__gets__o(variant v, oneof o);
int OFvariant_Dequal(variant v1, variant v2);
int OFvariant_Dsimilar(oplist_t op_list, variant v1, variant v2);
int OFvariant_Dsimilar1(oplist_t op_list, variant v1, variant v2);
int OFvariant_Dcopy(oplist_t op_list, variant v);
int OFvariant_Dcopy1(variant v);
int OFvariant_Dencode(oplist_t op_list, variant v, object ist);
int OFvariant_Ddecode(oplist_t op_list, object ist);
int OFvariant_Dprint(oplist_t op_list, variant v, object pst);
int OFvariant_D__gcd(oplist_t op_list, variant v, object tab);
#endif
