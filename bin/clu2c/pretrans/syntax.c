/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,typespec,istream*/
/* built-in param,oneof$similar,PV1_INtypespec_Dsimilar,typespec$similar,any_:null apply:record[args:sequence[typespec] gen:du sigs:sequence[record[name:string types:sequence[typespec]]] vals:sequence[typespec]] cluster_:record[gen:du parms:sequence[expr]] cvt_:null idn:idn other:oneof[du:record[gen:du parms:sequence[expr]] op:record[name:string parms:sequence[expr] type_:typespec] return_:typespec] select:record[gen:du parms:sequence[record[sel:string type_:typespec]]] type_:record[gen:du parms:sequence[expr]] unknown:null xclu:record[idn:idn parms:sequence[expr]] xsel:record[idn:idn parms:sequence[record[sel:string type_:typespec]]]*/
/* built-in param,sequence$equal,PV1_INtypespec_Dmismatch,typespec$mismatch,typespec*/
/* built-in param,sequence$equal,PV2_INtypespec_Dmismatch,typespec$mismatch,typespec*/
/* built-in param,record$similar,PV3_INtypespec_Dmismatch,typespec$mismatch,name:string types:sequence[typespec]*/
/* built-in param,oneof$encode,PV1_INtypespec_Dencode,typespec$encode,any_:null apply:record[args:sequence[typespec] gen:du sigs:sequence[record[name:string types:sequence[typespec]]] vals:sequence[typespec]] cluster_:record[gen:du parms:sequence[expr]] cvt_:null idn:idn other:oneof[du:record[gen:du parms:sequence[expr]] op:record[name:string parms:sequence[expr] type_:typespec] return_:typespec] select:record[gen:du parms:sequence[record[sel:string type_:typespec]]] type_:record[gen:du parms:sequence[expr]] unknown:null xclu:record[idn:idn parms:sequence[expr]] xsel:record[idn:idn parms:sequence[record[sel:string type_:typespec]]]*/
/* built-in param,oneof$decode,PV1_INtypespec_Ddecode,typespec$decode,any_:null apply:record[args:sequence[typespec] gen:du sigs:sequence[record[name:string types:sequence[typespec]]] vals:sequence[typespec]] cluster_:record[gen:du parms:sequence[expr]] cvt_:null idn:idn other:oneof[du:record[gen:du parms:sequence[expr]] op:record[name:string parms:sequence[expr] type_:typespec] return_:typespec] select:record[gen:du parms:sequence[record[sel:string type_:typespec]]] type_:record[gen:du parms:sequence[expr]] unknown:null xclu:record[idn:idn parms:sequence[expr]] xsel:record[idn:idn parms:sequence[record[sel:string type_:typespec]]]*/
/* depend,equate,idn*/
/* built-in param,oneof$similar,PV1_INequate_Dsimilar,equate$similar,du:string expr:expr typeset:record[equates:sequence[equate] idn:idn ops:sequence[record[line:int opers:sequence[record[name:string parms:sequence[expr] type_:typespec]]]]]*/
/* depend,stmt*/
/* built-in param,oneof$similar,PV1_INstmt_Dsimilar,stmt$similar,assn:record[anys:sequence[record[idns:sequence[idn] type_:typespec]] left:sequence[idn] right:sequence[expr]] bad:null body:record[equates:sequence[equate] stmts:sequence[stmt]] break_:null continue_:null decl:record[idns:sequence[idn] type_:typespec] declinit:record[anys:sequence[record[idns:sequence[idn] type_:typespec]] decls:sequence[record[idns:sequence[idn] type_:typespec]] expr:expr] except_:record[arms:sequence[record[body:record[equates:sequence[equate] stmts:sequence[stmt]] line:int names:sequence[string] vars:oneof[decls:sequence[record[idns:sequence[idn] type_:typespec]] none:null star:null]]] others_:oneof[arm:record[body:record[equates:sequence[equate] stmts:sequence[stmt]] decl:oneof[decl:record[idns:sequence[idn] type_:typespec] none:null] line:int] none:null] stmt:stmt] exit_:record[args:sequence[expr] name:string] for_:record[anys:sequence[record[idns:sequence[idn] type_:typespec]] body:record[equates:sequence[equate] stmts:sequence[stmt]] call:record[apply:expr args:sequence[expr] line:int] end_line:int send:oneof[none:null send:record[args:sequence[expr] object:expr params:sequence[expr] sel:string]] start_line:int vars:oneof[new:sequence[record[idns:sequence[idn] type_:typespec]] old:sequence[idn]] xent:bool] force_:record[expr:expr type_:idn val:idn where_:sequence[record[idn:idn kind:oneof[has_:sequence[record[line:int opers:sequence[record[name:string parms:sequence[expr] type_:typespec]]]] idn:idn set:record[equates:sequence[equate] idn:idn ops:sequence[record[line:int opers:sequence[record[name:string parms:sequence[expr] type_:typespec]]]]]] line:int]]] if_:record[arms:sequence[record[body:record[equates:sequence[equate] stmts:sequence[stmt]] line:int test:expr]] else_:oneof[body:record[equates:sequence[equate] stmts:sequence[stmt]] none:null]] invoke:record[apply:expr args:sequence[expr] line:int] resignal_:record[resigs:sequence[string] stmt:stmt] return_:sequence[expr] send:record[args:sequence[expr] object:expr params:sequence[expr] sel:string] signal_:record[args:sequence[expr] name:string] sugarassn:record[left:expr right:expr] tag_:record[arms:sequence[record[body:record[equates:sequence[equate] stmts:sequence[stmt]] line:int tags:sequence[string] var:oneof[decl:record[idns:sequence[idn] type_:typespec] none:null]]] obj:expr others_:oneof[body:record[equates:sequence[equate] stmts:sequence[stmt]] none:null]] while_:record[body:record[equates:sequence[equate] stmts:sequence[stmt]] end_line:int start_line:int test:expr] yield_:sequence[expr]*/
/* depend,expr,istream,typespec*/
/* built-in param,record$copy,PV1_INexpr_Dcopy,expr$copy,expr:oneof[a_cons:record[elts:sequence[expr] low:oneof[none:null one:expr] type_:typespec] any_:expr apply:record[gen:du parms:sequence[expr]] asis:string bad:null bool_:bool cand_:record[left:expr right:expr] char_:char cor_:record[left:expr right:expr] down_:expr fetch:record[index:expr object:expr] force_:typespec get:record[object:expr sel:string] idn:idn infix:record[left:expr neg:bool op:string right:expr] int_:int invoke:record[apply:expr args:sequence[expr] line:int] minus:expr not:expr null_:null op:record[name:string parms:sequence[expr] type_:typespec] real_:real ref:record[idn:idn parms:sequence[expr]] s_cons:record[fields:sequence[record[line:int sels:sequence[string] val:expr]] type_:typespec] send:record[args:sequence[expr] object:expr params:sequence[expr] sel:string] str:string type_:typespec type_of_:expr up_:expr] type_:typespec*/
/* built-in param,oneof$similar,PV1_INexpr_Dsimilar,expr$similar,a_cons:record[elts:sequence[expr] low:oneof[none:null one:expr] type_:typespec] any_:expr apply:record[gen:du parms:sequence[expr]] asis:string bad:null bool_:bool cand_:record[left:expr right:expr] char_:char cor_:record[left:expr right:expr] down_:expr fetch:record[index:expr object:expr] force_:typespec get:record[object:expr sel:string] idn:idn infix:record[left:expr neg:bool op:string right:expr] int_:int invoke:record[apply:expr args:sequence[expr] line:int] minus:expr not:expr null_:null op:record[name:string parms:sequence[expr] type_:typespec] real_:real ref:record[idn:idn parms:sequence[expr]] s_cons:record[fields:sequence[record[line:int sels:sequence[string] val:expr]] type_:typespec] send:record[args:sequence[expr] object:expr params:sequence[expr] sel:string] str:string type_:typespec type_of_:expr up_:expr*/
/* built-in param,record$encode,PV1_INexpr_Dencode,expr$encode,expr:oneof[a_cons:record[elts:sequence[expr] low:oneof[none:null one:expr] type_:typespec] any_:expr apply:record[gen:du parms:sequence[expr]] asis:string bad:null bool_:bool cand_:record[left:expr right:expr] char_:char cor_:record[left:expr right:expr] down_:expr fetch:record[index:expr object:expr] force_:typespec get:record[object:expr sel:string] idn:idn infix:record[left:expr neg:bool op:string right:expr] int_:int invoke:record[apply:expr args:sequence[expr] line:int] minus:expr not:expr null_:null op:record[name:string parms:sequence[expr] type_:typespec] real_:real ref:record[idn:idn parms:sequence[expr]] s_cons:record[fields:sequence[record[line:int sels:sequence[string] val:expr]] type_:typespec] send:record[args:sequence[expr] object:expr params:sequence[expr] sel:string] str:string type_:typespec type_of_:expr up_:expr] type_:typespec*/
/* built-in param,record$decode,PV1_INexpr_Ddecode,expr$decode,expr:oneof[a_cons:record[elts:sequence[expr] low:oneof[none:null one:expr] type_:typespec] any_:expr apply:record[gen:du parms:sequence[expr]] asis:string bad:null bool_:bool cand_:record[left:expr right:expr] char_:char cor_:record[left:expr right:expr] down_:expr fetch:record[index:expr object:expr] force_:typespec get:record[object:expr sel:string] idn:idn infix:record[left:expr neg:bool op:string right:expr] int_:int invoke:record[apply:expr args:sequence[expr] line:int] minus:expr not:expr null_:null op:record[name:string parms:sequence[expr] type_:typespec] real_:real ref:record[idn:idn parms:sequence[expr]] s_cons:record[fields:sequence[record[line:int sels:sequence[string] val:expr]] type_:typespec] send:record[args:sequence[expr] object:expr params:sequence[expr] sel:string] str:string type_:typespec type_of_:expr up_:expr] type_:typespec*/

#include <clu2c.h>

static object	WVsimilar__mode_IN_Ctypespec;
extern object	PV1_INexpr_Dsimilar;
extern object	PV1_INstmt_Dsimilar;
extern object	PV1_INtypespec_Dmismatch;
extern object	PV2_INtypespec_Dmismatch;
extern object	PV3_INtypespec_Dmismatch;
extern object	PV1_INtypespec_Ddecode;
extern object	PV1_INtypespec_Dencode;
extern object	PV1_INexpr_Ddecode;
extern object	PV1_INexpr_Dencode;
static bool	IV_IN_Ctypespec = FALSE;
extern object	PV1_INtypespec_Dsimilar;
extern object	PV1_INequate_Dsimilar;
extern object	PV1_INexpr_Dcopy;

static STRING_REP(6) str1 = {6, {'a', 'n', 'y', 'i', 'z', 'e'}};
static STRING_REP(2) str2 = {2, {'o', 'k'}};
static STRING_REP(3) str3 = {3, {'R', 'E', 'P'}};

/* begin module */
/* c_function_name, OFtypespec_Dcreate */
/* clu_operation_name, typespec$create */
int OFtypespec_Dcreate(LVta, LVid)
     object LVta;
     object LVid;
{
  int t1;
  if (IV_IN_Ctypespec == FALSE)
    {
      IV_IN_Ctypespec = TRUE;
      if (IF_IN_Ctypespec() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  t1 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t1, LVid);
  OMrecord_Dset(2, t1, LVta);
  retval_area[0] = t1;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFtypespec_Dis__unknown */
/* clu_operation_name, typespec$is_unknown */
int OFtypespec_Dis__unknown(LVt)
     object LVt;
{
  if (IV_IN_Ctypespec == FALSE)
    {
      IV_IN_Ctypespec = TRUE;
      if (IF_IN_Ctypespec() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = OMoneof_Dis(9, OMrecord_Dget(2, LVt));
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFtypespec_Dget__abs */
/* clu_operation_name, typespec$get_abs */
int OFtypespec_Dget__abs(LVt)
     object LVt;
{
  if (IV_IN_Ctypespec == FALSE)
    {
      IV_IN_Ctypespec = TRUE;
      if (IF_IN_Ctypespec() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = OMrecord_Dget(2, LVt);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFtypespec_Dset__abs */
/* clu_operation_name, typespec$set_abs */
int OFtypespec_Dset__abs(LVt, LVabs)
     object LVt;
     object LVabs;
{
  if (IV_IN_Ctypespec == FALSE)
    {
      IV_IN_Ctypespec = TRUE;
      if (IF_IN_Ctypespec() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  OMrecord_Dset(2, LVt, LVabs);
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFtypespec_Dget__id */
/* clu_operation_name, typespec$get_id */
int OFtypespec_Dget__id(LVt)
     object LVt;
{
  if (IV_IN_Ctypespec == FALSE)
    {
      IV_IN_Ctypespec = TRUE;
      if (IF_IN_Ctypespec() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = OMrecord_Dget(1, LVt);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFtypespec_Dset__id */
/* clu_operation_name, typespec$set_id */
int OFtypespec_Dset__id(LVt, LVid)
     object LVt;
     object LVid;
{
  if (IV_IN_Ctypespec == FALSE)
    {
      IV_IN_Ctypespec = TRUE;
      if (IF_IN_Ctypespec() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  OMrecord_Dset(1, LVt, LVid);
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFtypespec_Dcopy */
/* clu_operation_name, typespec$copy */
int OFtypespec_Dcopy(LVt)
     object LVt;
{
  if (IV_IN_Ctypespec == FALSE)
    {
      IV_IN_Ctypespec = TRUE;
      if (IF_IN_Ctypespec() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = LVt;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFtypespec_Dequal */
/* clu_operation_name, typespec$equal */
int OFtypespec_Dequal(LVt1, LVt2)
     object LVt1;
     object LVt2;
{
  int t1;
  if (IV_IN_Ctypespec == FALSE)
    {
      IV_IN_Ctypespec = TRUE;
      if (IF_IN_Ctypespec() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  t1 = OMrecord_Dget(1, LVt1);
  retval_area[0] = OMint_Dequal(t1, OMrecord_Dget(1, LVt2));
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFtypespec_Dsimilar */
/* clu_operation_name, typespec$similar */
int OFtypespec_Dsimilar(LVt1, LVt2)
     object LVt1;
     object LVt2;
{
  int t1, t2;
  if (IV_IN_Ctypespec == FALSE)
    {
      IV_IN_Ctypespec = TRUE;
      if (IF_IN_Ctypespec() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  t1 = OMrecord_Dget(1, LVt1);
  if (OMint_Dequal(t1, OMrecord_Dget(1, LVt2)))
    {
      retval_area[0] = TRUE;
      return RET;
    }
  else
    {
      if (WVsimilar__mode_IN_Ctypespec)
        {
	  retval_area[0] = FALSE;
	  return RET;
        }
      else
        {
	  t2 = OMrecord_Dget(2, LVt1);
	  if ((*((proctype)PV1_INtypespec_Dsimilar))(t2, OMrecord_Dget(2, LVt2)) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  /* end body */
  noretval(SLNULL);
  return(SIG);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFtypespec_Dset__similar__mode */
/* clu_operation_name, typespec$set_similar_mode */
int OFtypespec_Dset__similar__mode(LVflag)
     object LVflag;
{
  if (IV_IN_Ctypespec == FALSE)
    {
      IV_IN_Ctypespec = TRUE;
      if (IF_IN_Ctypespec() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVsimilar__mode_IN_Ctypespec = LVflag;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFtypespec_Dmismatch */
/* clu_operation_name, typespec$mismatch */
int OFtypespec_Dmismatch(LVt1, LVt2)
     object LVt1;
     object LVt2;
{
  object LVta2= 0;
  int t1, t2, t3, t4, t5, t6, t7, t8, t9;
  if (IV_IN_Ctypespec == FALSE)
    {
      IV_IN_Ctypespec = TRUE;
      if (IF_IN_Ctypespec() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  t1 = OMrecord_Dget(1, LVt1);
  if (OMint_Dequal(t1, OMrecord_Dget(1, LVt2)))
    {
      retval_area[0] = FALSE;
      return RET;
    }
  LVta2 = OMrecord_Dget(2, LVt2);
  t1 = OMrecord_Dget(2, LVt1);
  t2 = ((oneof) t1)->tag;
  if (t2 == 9)
    {
        {
	  retval_area[0] = FALSE;
	  return RET;
        }
    }
  else if (t2 == 1)
    {
        {
	  t3 = OMrecord_Dget(2, LVt2);
	  t4 = ((oneof) t3)->tag;
	  if (t4 == 9)
	    {
	        {
		  retval_area[0] = FALSE;
		  return RET;
	        }
	    }
	  else
	    {
	      signame = ((string) &str1);
	      return(SIG);
	    }
        }
    }
  else if (t2 == 6)
    {
      object LVot= 0;
      LVot = ((oneof) t1)->value;
        {
	  t3 = ((oneof) LVot)->tag;
	  if (t3 == 3)
	    {
	        {
		  retval_area[0] = FALSE;
		  return RET;
	        }
	    }
	  else
	    {
	      t4 = ((oneof) LVta2)->tag;
	      if (t4 == 9 || t4 == 2 || t4 == 6)
	        {
		    {
		      retval_area[0] = FALSE;
		      return RET;
		    }
	        }
	      else if (t4 == 8)
	        {
		    {
		      retval_area[0] = OMoneof_Dis(2, LVot);
		      return RET;
		    }
	        }
	      else
	        {
		  retval_area[0] = TRUE;
		  return RET;
	        }
	    }
        }
    }
  else if (t2 == 2)
    {
      object LVxa1= 0;
      LVxa1 = ((oneof) t1)->value;
        {
	  t3 = ((oneof) LVta2)->tag;
	  if (t3 == 2)
	    {
	      object LVxa2= 0;
	      LVxa2 = ((oneof) LVta2)->value;
	        {
		  t4 = FALSE;
		  t5 = FALSE;
		  t6 = OMrecord_Dget(2, LVxa1);
		  if (OFdu_Dequal(t6, OMrecord_Dget(2, LVxa2)) == SIG)
		    {
		      goto except0;
		    }
		  if (retval_area[0])
		    {
		      t7 = OMrecord_Dget(1, LVxa1);
		      if ((*((proctype)PV1_INtypespec_Dmismatch))(t7, OMrecord_Dget(1, LVxa2)) == SIG)
		        {
			  goto except0;
		        }
		      if (retval_area[0])
		        {
			  t5 = TRUE;
		        }
		    }
		  if (t5)
		    {
		      t8 = OMrecord_Dget(4, LVxa1);
		      if ((*((proctype)PV2_INtypespec_Dmismatch))(t8, OMrecord_Dget(4, LVxa2)) == SIG)
		        {
			  goto except0;
		        }
		      if (retval_area[0])
		        {
			  t4 = TRUE;
		        }
		    }
		  if (OMbool_Dnot(t4))
		    {
		      retval_area[0] = TRUE;
		      return RET;
		    }
		    {
		      object LVx= 0;
		      for (t4 = OMrecord_Dget(3, LVxa2), t5 = 1, t6 = OMsequence_Dsize(t4);
		           t5 <= t6;
		           t5++)
		        {
			  LVx = OMsequence_Dfetch(t4, t5);
			    {
			        {
				    {
				      object LVy= 0;
				      for (t7 = OMrecord_Dget(3, LVxa1), t8 = 1, t9 = OMsequence_Dsize(t7);
				           t8 <= t9;
				           t8++)
				        {
					  LVy = OMsequence_Dfetch(t7, t8);
					    {
					      if ((*((proctype)PV3_INtypespec_Dmismatch))(LVx, LVy) == SIG)
					        {
						  goto except1;
					        }
					      if (retval_area[0])
					        {
						  signame = ((string) &str2);
						  goto except1;
					        }
					    }
				        }
				    }
				  retval_area[0] = TRUE;
				  return RET;
			        }
			      if (FALSE)
			        {
				except1:
				  if (OMstring_Dequal(signame, ((string) &str2)))
				    {
				    }
				  else
				    {
				      goto except0;
				    }
			        }
			    }
		        }
		    }
		  retval_area[0] = FALSE;
		  return RET;
	        }
	    }
	  else if (t3 == 9 || t3 == 6)
	    {
	        {
		  retval_area[0] = FALSE;
		  return RET;
	        }
	    }
	  else
	    {
	      retval_area[0] = TRUE;
	      return RET;
	    }
        }
    }
  else
    {
      t3 = ((oneof) LVta2)->tag;
      if (t3 == 9)
        {
	    {
	      retval_area[0] = FALSE;
	      return RET;
	    }
        }
      else if (t3 == 6)
        {
	  object LVot= 0;
	  LVot = ((oneof) LVta2)->value;
	    {
	      t4 = ((oneof) LVot)->tag;
	      if (t4 == 3)
	        {
		    {
		      retval_area[0] = FALSE;
		      return RET;
		    }
	        }
	      else if (t4 == 1)
	        {
		    {
		      retval_area[0] = OMbool_Dnot(OMoneof_Dis(8, OMrecord_Dget(2, LVt1)));
		      return RET;
		    }
	        }
	      else
	        {
		  retval_area[0] = TRUE;
		  return RET;
	        }
	    }
        }
      else
        {
	  retval_area[0] = TRUE;
	  return RET;
        }
    }
  /* end body */
  noretval(SLNULL);
  return(SIG);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFtypespec_Dmismatch2 */
/* clu_operation_name, typespec$mismatch2 */
int OFtypespec_Dmismatch2(LVt1, LVt2)
     object LVt1;
     object LVt2;
{
  int t1;
  if (IV_IN_Ctypespec == FALSE)
    {
      IV_IN_Ctypespec = TRUE;
      if (IF_IN_Ctypespec() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  if (OFtypespec_Dmismatch(LVt1, LVt2) == SIG)
    {
      goto except1;
    }
  if (retval_area[0])
    {
      t1 = TRUE;
    }
  else
    {
      if (OFtypespec_Dmismatch(LVt2, LVt1) == SIG)
        {
	  goto except1;
        }
      t1 = retval_area[0];
    }
  retval_area[0] = t1;
  return RET;
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, ((string) &str1)))
        {
	  retval_area[0] = TRUE;
	  return RET;
        }
      else
        {
	  goto except0;
        }
    }
  /* end body */
  noretval(SLNULL);
  return(SIG);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFtypespec_Dencode */
/* clu_operation_name, typespec$encode */
int OFtypespec_Dencode(LVt, LVs)
     object LVt;
     object LVs;
{
  if (IV_IN_Ctypespec == FALSE)
    {
      IV_IN_Ctypespec = TRUE;
      if (IF_IN_Ctypespec() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  if ((*((proctype)PV1_INtypespec_Dencode))(OMrecord_Dget(2, LVt), LVs) == SIG)
    {
      goto except1;
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_POSSIBLE))
        {
	  return(SIG);
        }
      else
        {
	  goto except0;
        }
    }
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFtypespec_Ddecode */
/* clu_operation_name, typespec$decode */
int OFtypespec_Ddecode(LVs)
     object LVs;
{
  if (IV_IN_Ctypespec == FALSE)
    {
      IV_IN_Ctypespec = TRUE;
      if (IF_IN_Ctypespec() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  if ((*((proctype)PV1_INtypespec_Ddecode))(LVs) == SIG)
    {
      goto except1;
    }
  if (OFtypespec_Dcreate(retval_area[0], 0) == SIG)
    {
      goto except1;
    }
  retval_area[0] = retval_area[0];
  return RET;
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLEND_OF_FILE) || OMstring_Dequal(signame, SLNOT_POSSIBLE))
        {
	  return(SIG);
        }
      else
        {
	  goto except0;
        }
    }
  /* end body */
  noretval(SLNULL);
  return(SIG);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, IF_IN_Ctypespec */
/* clu_operation_name, typespec$#initown */
int IF_IN_Ctypespec()
{
  /* begin body */
  WVsimilar__mode_IN_Ctypespec = TRUE;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, OFequate_Dcreate */
/* clu_operation_name, equate$create */
int OFequate_Dcreate(LVid, LVval, LVline)
     object LVid;
     object LVval;
     object LVline;
{
  int t1;
  /* begin body */
  t1 = OFrecord_D__alloc(3);
  OMrecord_Dset(1, t1, LVid);
  OMrecord_Dset(2, t1, LVline);
  OMrecord_Dset(3, t1, LVval);
  retval_area[0] = t1;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFequate_Dis__rep */
/* clu_operation_name, equate$is_rep */
int OFequate_Dis__rep(LVe)
     object LVe;
{
  /* begin body */
  if (OFidn_Dget__str(OMrecord_Dget(1, LVe)) == SIG)
    {
      goto except0;
    }
  retval_area[0] = OMstring_Dequal(((string) &str3), retval_area[0]);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFequate_Dget__idn */
/* clu_operation_name, equate$get_idn */
int OFequate_Dget__idn(LVe)
     object LVe;
{
  /* begin body */
  retval_area[0] = OMrecord_Dget(1, LVe);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFequate_Dget__val */
/* clu_operation_name, equate$get_val */
int OFequate_Dget__val(LVe)
     object LVe;
{
  /* begin body */
  retval_area[0] = OMrecord_Dget(3, LVe);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFequate_Dget__line */
/* clu_operation_name, equate$get_line */
int OFequate_Dget__line(LVe)
     object LVe;
{
  /* begin body */
  retval_area[0] = OMrecord_Dget(2, LVe);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFequate_Dcopy */
/* clu_operation_name, equate$copy */
int OFequate_Dcopy(LVe)
     object LVe;
{
  /* begin body */
  retval_area[0] = LVe;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFequate_Dequal */
/* clu_operation_name, equate$equal */
int OFequate_Dequal(LVe1, LVe2)
     object LVe1;
     object LVe2;
{
  /* begin body */
  OFrecord_Dequal(LVe1, LVe2);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFequate_Dsimilar */
/* clu_operation_name, equate$similar */
int OFequate_Dsimilar(LVe1, LVe2)
     object LVe1;
     object LVe2;
{
  int t1, t2;
  /* begin body */
  t1 = OMrecord_Dget(1, LVe1);
  if (OFidn_Dequal(t1, OMrecord_Dget(1, LVe2)) == SIG)
    {
      goto except0;
    }
  if (retval_area[0])
    {
      t2 = OMrecord_Dget(3, LVe1);
      if ((*((proctype)PV1_INequate_Dsimilar))(t2, OMrecord_Dget(3, LVe2)) == SIG)
        {
	  goto except0;
        }
      retval_area[0] = retval_area[0];
      return RET;
    }
  else
    {
      retval_area[0] = FALSE;
      return RET;
    }
  /* end body */
  noretval(SLNULL);
  return(SIG);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, OFstmt_Dcreate */
/* clu_operation_name, stmt$create */
int OFstmt_Dcreate(LVs, LVl)
     object LVs;
     object LVl;
{
  int t1;
  /* begin body */
  t1 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t1, LVl);
  OMrecord_Dset(2, t1, LVs);
  retval_area[0] = t1;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFstmt_Dget__abs */
/* clu_operation_name, stmt$get_abs */
int OFstmt_Dget__abs(LVs)
     object LVs;
{
  /* begin body */
  retval_area[0] = OMrecord_Dget(2, LVs);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFstmt_Dset__abs */
/* clu_operation_name, stmt$set_abs */
int OFstmt_Dset__abs(LVs, LVa)
     object LVs;
     object LVa;
{
  /* begin body */
  OMrecord_Dset(2, LVs, LVa);
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFstmt_Dget__line */
/* clu_operation_name, stmt$get_line */
int OFstmt_Dget__line(LVs)
     object LVs;
{
  /* begin body */
  retval_area[0] = OMrecord_Dget(1, LVs);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFstmt_Dcopy */
/* clu_operation_name, stmt$copy */
int OFstmt_Dcopy(LVs)
     object LVs;
{
  /* begin body */
  retval_area[0] = LVs;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFstmt_Dequal */
/* clu_operation_name, stmt$equal */
int OFstmt_Dequal(LVs1, LVs2)
     object LVs1;
     object LVs2;
{
  /* begin body */
  OFrecord_Dequal(LVs1, LVs2);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFstmt_Dsimilar */
/* clu_operation_name, stmt$similar */
int OFstmt_Dsimilar(LVs1, LVs2)
     object LVs1;
     object LVs2;
{
  int t1;
  /* begin body */
  t1 = OMrecord_Dget(2, LVs1);
  if ((*((proctype)PV1_INstmt_Dsimilar))(t1, OMrecord_Dget(2, LVs2)) == SIG)
    {
      goto except0;
    }
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, OFexpr_Dcreate */
/* clu_operation_name, expr$create */
int OFexpr_Dcreate(LVx, LVt)
     object LVx;
     object LVt;
{
  int t1;
  /* begin body */
  t1 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t1, LVx);
  OMrecord_Dset(2, t1, LVt);
  retval_area[0] = t1;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFexpr_Dget__abs */
/* clu_operation_name, expr$get_abs */
int OFexpr_Dget__abs(LVx)
     object LVx;
{
  /* begin body */
  retval_area[0] = OMrecord_Dget(1, LVx);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFexpr_Dset__abs */
/* clu_operation_name, expr$set_abs */
int OFexpr_Dset__abs(LVx, LVa)
     object LVx;
     object LVa;
{
  /* begin body */
  OMrecord_Dset(1, LVx, LVa);
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFexpr_Dget__typespec */
/* clu_operation_name, expr$get_typespec */
int OFexpr_Dget__typespec(LVx)
     object LVx;
{
  /* begin body */
  retval_area[0] = OMrecord_Dget(2, LVx);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFexpr_Dset__typespec */
/* clu_operation_name, expr$set_typespec */
int OFexpr_Dset__typespec(LVx, LVt)
     object LVx;
     object LVt;
{
  /* begin body */
  OMrecord_Dset(2, LVx, LVt);
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFexpr_Dcopy */
/* clu_operation_name, expr$copy */
int OFexpr_Dcopy(LVx)
     object LVx;
{
  /* begin body */
  if ((*((proctype)PV1_INexpr_Dcopy))(LVx) == SIG)
    {
      goto except0;
    }
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFexpr_Dequal */
/* clu_operation_name, expr$equal */
int OFexpr_Dequal(LVx1, LVx2)
     object LVx1;
     object LVx2;
{
  /* begin body */
  OFrecord_Dequal(LVx1, LVx2);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFexpr_Dsimilar */
/* clu_operation_name, expr$similar */
int OFexpr_Dsimilar(LVx1, LVx2)
     object LVx1;
     object LVx2;
{
  int t1;
  /* begin body */
  t1 = OMrecord_Dget(1, LVx1);
  if ((*((proctype)PV1_INexpr_Dsimilar))(t1, OMrecord_Dget(1, LVx2)) == SIG)
    {
      goto except0;
    }
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFexpr_Dencode */
/* clu_operation_name, expr$encode */
int OFexpr_Dencode(LVx, LVs)
     object LVx;
     object LVs;
{
  /* begin body */
  if ((*((proctype)PV1_INexpr_Dencode))(LVx, LVs) == SIG)
    {
      goto except1;
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_POSSIBLE))
        {
	  return(SIG);
        }
      else
        {
	  goto except0;
        }
    }
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFexpr_Ddecode */
/* clu_operation_name, expr$decode */
int OFexpr_Ddecode(LVs)
     object LVs;
{
  /* begin body */
  if ((*((proctype)PV1_INexpr_Ddecode))(LVs) == SIG)
    {
      goto except1;
    }
  retval_area[0] = retval_area[0];
  return RET;
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLEND_OF_FILE) || OMstring_Dequal(signame, SLNOT_POSSIBLE))
        {
	  return(SIG);
        }
      else
        {
	  goto except0;
        }
    }
  /* end body */
  noretval(SLNULL);
  return(SIG);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */