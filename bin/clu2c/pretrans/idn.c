/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,idn,_cvt,istream,table*/
/* param_mod_call,clop,PV1_INidn_Dsimilar,idn$similar,table[record[kind:oneof[expr:expr gen:du opgen:string ownvar:typespec tconst:sequence[record[name:string parms:sequence[expr] type_:typespec]] tparm:sequence[record[name:string parms:sequence[expr] type_:typespec]] typeset:record[opers:sequence[record[name:string parms:sequence[expr] type_:typespec]] parm:idn] unknown:null var:typespec vparm:typespec] str:string] array[record[kind:oneof[expr:expr gen:du opgen:string ownvar:typespec tconst:sequence[record[name:string parms:sequence[expr] type_:typespec]] tparm:sequence[record[name:string parms:sequence[expr] type_:typespec]] typeset:record[opers:sequence[record[name:string parms:sequence[expr] type_:typespec]] parm:idn] unknown:null var:typespec vparm:typespec] str:string]]],mbind,no_param*/
/* built-in param,oneof$similar,PV2_INidn_Dsimilar,idn$similar,expr:expr gen:du opgen:string ownvar:typespec tconst:sequence[record[name:string parms:sequence[expr] type_:typespec]] tparm:sequence[record[name:string parms:sequence[expr] type_:typespec]] typeset:record[opers:sequence[record[name:string parms:sequence[expr] type_:typespec]] parm:idn] unknown:null var:typespec vparm:typespec*/
/* param_mod_call,clop,PV1_INidn_Dset__similar__mode,idn$set_similar_mode,table[record[kind:oneof[expr:expr gen:du opgen:string ownvar:typespec tconst:sequence[record[name:string parms:sequence[expr] type_:typespec]] tparm:sequence[record[name:string parms:sequence[expr] type_:typespec]] typeset:record[opers:sequence[record[name:string parms:sequence[expr] type_:typespec]] parm:idn] unknown:null var:typespec vparm:typespec] str:string] array[record[kind:oneof[expr:expr gen:du opgen:string ownvar:typespec tconst:sequence[record[name:string parms:sequence[expr] type_:typespec]] tparm:sequence[record[name:string parms:sequence[expr] type_:typespec]] typeset:record[opers:sequence[record[name:string parms:sequence[expr] type_:typespec]] parm:idn] unknown:null var:typespec vparm:typespec] str:string]]],flush,no_param*/
/* built-in param,record$encode,PV1_INidn_Dencode,idn$encode,kind:oneof[expr:expr gen:du opgen:string ownvar:typespec tconst:sequence[record[name:string parms:sequence[expr] type_:typespec]] tparm:sequence[record[name:string parms:sequence[expr] type_:typespec]] typeset:record[opers:sequence[record[name:string parms:sequence[expr] type_:typespec]] parm:idn] unknown:null var:typespec vparm:typespec] str:string*/
/* built-in param,record$decode,PV1_INidn_Ddecode,idn$decode,kind:oneof[expr:expr gen:du opgen:string ownvar:typespec tconst:sequence[record[name:string parms:sequence[expr] type_:typespec]] tparm:sequence[record[name:string parms:sequence[expr] type_:typespec]] typeset:record[opers:sequence[record[name:string parms:sequence[expr] type_:typespec]] parm:idn] unknown:null var:typespec vparm:typespec] str:string*/
/* param_mod_call,clop,PV1_IN_IF_IN_Cidn,idn$#initown,table[record[kind:oneof[expr:expr gen:du opgen:string ownvar:typespec tconst:sequence[record[name:string parms:sequence[expr] type_:typespec]] tparm:sequence[record[name:string parms:sequence[expr] type_:typespec]] typeset:record[opers:sequence[record[name:string parms:sequence[expr] type_:typespec]] parm:idn] unknown:null var:typespec vparm:typespec] str:string] array[record[kind:oneof[expr:expr gen:du opgen:string ownvar:typespec tconst:sequence[record[name:string parms:sequence[expr] type_:typespec]] tparm:sequence[record[name:string parms:sequence[expr] type_:typespec]] typeset:record[opers:sequence[record[name:string parms:sequence[expr] type_:typespec]] parm:idn] unknown:null var:typespec vparm:typespec] str:string]]],create,no_param*/

#include <clu2c.h>

extern object	PV1_INidn_Dset__similar__mode;
extern object	PV1_INidn_Ddecode;
extern object	PV1_INidn_Dencode;
static object	WVsimilar__table_IN_Cidn;
static bool	IV_IN_Cidn = FALSE;
extern object	PV1_IN_IF_IN_Cidn;
extern object	PV1_INidn_Dsimilar;
extern object	PV2_INidn_Dsimilar;
extern int	OFrecord_Dequal();
static object	WVsimilar__mode_IN_Cidn;
extern int	OFidn_Didn__hasher();

/* begin module */
/* c_function_name, OFidn_Dcreate */
/* clu_operation_name, idn$create */
int OFidn_Dcreate(LVs, LVk)
     object LVs;
     object LVk;
{
  int t1;
  if (IV_IN_Cidn == FALSE)
    {
      IV_IN_Cidn = TRUE;
      if (IF_IN_Cidn() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  t1 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t1, LVk);
  OMrecord_Dset(2, t1, LVs);
  retval_area[0] = t1;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFidn_Dget__str */
/* clu_operation_name, idn$get_str */
int OFidn_Dget__str(LVi)
     object LVi;
{
  if (IV_IN_Cidn == FALSE)
    {
      IV_IN_Cidn = TRUE;
      if (IF_IN_Cidn() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = OMrecord_Dget(2, LVi);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFidn_Dset__kind */
/* clu_operation_name, idn$set_kind */
int OFidn_Dset__kind(LVi, LVk)
     object LVi;
     object LVk;
{
  if (IV_IN_Cidn == FALSE)
    {
      IV_IN_Cidn = TRUE;
      if (IF_IN_Cidn() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  OMrecord_Dset(1, LVi, LVk);
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFidn_Dget__kind */
/* clu_operation_name, idn$get_kind */
int OFidn_Dget__kind(LVi)
     object LVi;
{
  if (IV_IN_Cidn == FALSE)
    {
      IV_IN_Cidn = TRUE;
      if (IF_IN_Cidn() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = OMrecord_Dget(1, LVi);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFidn_Dcopy */
/* clu_operation_name, idn$copy */
int OFidn_Dcopy(LVi)
     object LVi;
{
  if (IV_IN_Cidn == FALSE)
    {
      IV_IN_Cidn = TRUE;
      if (IF_IN_Cidn() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = LVi;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFidn_Dequal */
/* clu_operation_name, idn$equal */
int OFidn_Dequal(LVi1, LVi2)
     object LVi1;
     object LVi2;
{
  if (IV_IN_Cidn == FALSE)
    {
      IV_IN_Cidn = TRUE;
      if (IF_IN_Cidn() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  OFrecord_Dequal(LVi1, LVi2);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFidn_Dsimilar */
/* clu_operation_name, idn$similar */
int OFidn_Dsimilar(LVi1, LVi2)
     object LVi1;
     object LVi2;
{
  int t1, t2, t3, t4, t5, t6, t7;
  if (IV_IN_Cidn == FALSE)
    {
      IV_IN_Cidn = TRUE;
      if (IF_IN_Cidn() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  OFrecord_Dequal(LVi1, LVi2);
  if (retval_area[0])
    {
      retval_area[0] = TRUE;
      return RET;
    }
  else
    {
      if (WVsimilar__mode_IN_Cidn)
        {
	  t1 = TRUE;
        }
      else
        {
	  t2 = OMrecord_Dget(2, LVi1);
	  t1 = OMbool_Dnot(OMstring_Dequal(t2, OMrecord_Dget(2, LVi2)));
        }
      if (t1)
        {
	  retval_area[0] = FALSE;
	  return RET;
        }
      else
        {
	  object LVxx= 0;
	  t3 = OFarray_D__alloc(1, 0);
	  if ((*((proctype)PV1_INidn_Dsimilar))(WVsimilar__table_IN_Cidn, LVi1, t3) == SIG)
	    {
	      goto except0;
	    }
	  LVxx = retval_area[0];
	    {
	      object LVx= 0;
	      for (t3 = LVxx, t4 = OMarray_Dlow(t3), t5 = OMarray_Dhigh(t3);
	           t4 <= t5;
	           t4++)
	        {
		  LVx = OMarray_Dfetch(t3, t4);
		    {
		      OFrecord_Dequal(LVx, LVi2);
		      if (retval_area[0])
		        {
			  retval_area[0] = TRUE;
			  return RET;
		        }
		    }
	        }
	    }
	  OMarray_Daddh(LVxx, LVi2);
	  t3 = OMrecord_Dget(1, LVi1);
	  if ((*((proctype)PV2_INidn_Dsimilar))(t3, OMrecord_Dget(1, LVi2)) == SIG)
	    {
	      goto except0;
	    }
	  if (retval_area[0])
	    {
	      retval_area[0] = TRUE;
	      return RET;
	    }
	  else
	    {
	        {
		  object LVi= 0;
		  for (t4 = OMarray_Dlow(LVxx), t5 = OMarray_Dhigh(LVxx); t4 <= t5; t4++)
		    {
		      LVi = t4;
		        {
			  if (OMarray_Dbounds(LVxx, LVi))
			    {
			      signame = SLBOUNDS;
			      goto except0;
			    }
			  OFrecord_Dequal(OMarray_Dfetch(LVxx, LVi), LVi2);
			  if (retval_area[0])
			    {
			      t6 = OMarray_Dhigh(LVxx);
			      if (OMarray_Dbounds(LVxx, t6))
			        {
				  signame = SLBOUNDS;
				  goto except0;
			        }
			      t7 = OMarray_Dfetch(LVxx, t6);
			      if (OMarray_Dbounds(LVxx, LVi))
			        {
				  signame = SLBOUNDS;
				  goto except0;
			        }
			      OMarray_Dstore(LVxx, LVi, t7);
			      if (OMarray_Dempty(LVxx))
			        {
				  signame = SLBOUNDS;
				  goto except0;
			        }
			      OMarray_Dremh(LVxx);
			      retval_area[0] = FALSE;
			      return RET;
			    }
		        }
		    }
	        }
	      retval_area[0] = FALSE;
	      return RET;
	    }
        }
    }
  /* end body */
  noretval(SLNULL);
  return(SIG);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFidn_Dset__similar__mode */
/* clu_operation_name, idn$set_similar_mode */
int OFidn_Dset__similar__mode(LVflag)
     object LVflag;
{
  if (IV_IN_Cidn == FALSE)
    {
      IV_IN_Cidn = TRUE;
      if (IF_IN_Cidn() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVsimilar__mode_IN_Cidn = LVflag;
  if (LVflag)
    {
      if ((*((proctype)PV1_INidn_Dset__similar__mode))(WVsimilar__table_IN_Cidn) == SIG)
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
/* c_function_name, OFidn_Dencode */
/* clu_operation_name, idn$encode */
int OFidn_Dencode(LVi, LVs)
     object LVi;
     object LVs;
{
  if (IV_IN_Cidn == FALSE)
    {
      IV_IN_Cidn = TRUE;
      if (IF_IN_Cidn() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  if ((*((proctype)PV1_INidn_Dencode))(LVi, LVs) == SIG)
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
/* c_function_name, OFidn_Ddecode */
/* clu_operation_name, idn$decode */
int OFidn_Ddecode(LVs)
     object LVs;
{
  if (IV_IN_Cidn == FALSE)
    {
      IV_IN_Cidn = TRUE;
      if (IF_IN_Cidn() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  if ((*((proctype)PV1_INidn_Ddecode))(LVs) == SIG)
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
/* c_function_name, OFidn_Didn__hasher */
/* clu_operation_name, idn$idn_hasher */
int OFidn_Didn__hasher(LVkey, LVsize)
     object LVkey;
     object LVsize;
{
  int t1;
  if (IV_IN_Cidn == FALSE)
    {
      IV_IN_Cidn = TRUE;
      if (IF_IN_Cidn() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  t1 = LVkey;
  if (OMint_Dzero__divide(LVsize))
    {
      signame = SLZERO_DIVIDE;
      goto except0;
    }
  retval_area[0] = OMint_Dmod(t1, LVsize);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, IF_IN_Cidn */
/* clu_operation_name, idn$#initown */
int IF_IN_Cidn()
{
  /* begin body */
  WVsimilar__mode_IN_Cidn = TRUE;
  if ((*((proctype)PV1_IN_IF_IN_Cidn))(100, OFidn_Didn__hasher, OFrecord_Dequal) == SIG)
    {
      goto except0;
    }
  WVsimilar__table_IN_Cidn = retval_area[0];
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */
