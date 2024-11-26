#ifndef BUILTIN_SEQUENCE_H
#define BUILTIN_SEQUENCE_H
int OFsequence_Dnew(void);
int OFsequence_Dsize(sequence s);
int OFsequence_Dempty(sequence s);
int OFsequence_Dsubseq(sequence s, int start, int size);
int OFsequence_Dfill(int size, object e);
int OFsequence_Dfill__copy(oplist_t op_list, int size, object elem);
int OFsequence_Dfetch(sequence s, int i);
int OFsequence_Dbottom(sequence s);
int OFsequence_Dtop(sequence s);
int OFsequence_Dreplace(sequence s, int i, object e);
int OFsequence_Daddh(sequence s, object e);
int OFsequence_Daddl(sequence s, object e);
int OFsequence_Dremh(sequence s);
int OFsequence_Dreml(sequence s);
int OFsequence_De2s(object e);
int OFsequence_Dconcat(sequence s1, sequence s2);
int OFsequence_Da2s(array a);
int OFsequence_Ds2a(sequence s);
int OFsequence_Delements(bool init, object **ivarp, sequence s);
int OFsequence_Dindexes(bool init, object **ivarp, sequence s);
int OFsequence_Dequal(oplist_t op_list, sequence s1, sequence s2);
int OFsequence_Dsimilar(oplist_t op_list, sequence s1, sequence s2);
int OFsequence_Dcopy(oplist_t op_list, sequence s);
int OFsequence_Dencode(oplist_t op_list, sequence s, object ist);
int OFsequence_Ddecode(oplist_t op_list, object ist);
int OFsequence_Dprint(oplist_t op_list, sequence s, object pst);
int OFsequence_D__gcd(oplist_t op_list, sequence s, object tab);
sequence OFsequence_D__alloc(int size);
#endif
