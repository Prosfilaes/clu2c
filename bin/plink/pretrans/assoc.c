/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,assoc_array*/
/* param_mod_decl,cluster,assoc_array,1*/
/* param_mod_decl,clus_op,0,assoc_array,new*/
/* param_mod_decl,clus_op,1,assoc_array,reset*/
/* param_mod_decl,clus_op,2,assoc_array,lookup*/
/* param_mod_decl,clus_op,3,assoc_array,enter*/
/* param_mod_decl,clus_op,3,assoc_array,keys*/
/* param_mod_decl,clus_op,3,assoc_array,values*/

#include <clu2c.h>

static STRING_REP(6) str1 = {6, {'e', 'x', 'i', 's', 't', 's'}};

/* begin module */
/* c_function_name, OFassoc__array_Dnew */
/* clu_operation_name, assoc_array$new */
int OFassoc__array_Dnew(pi)
     param_info *pi;
{
  int t1, t2;
  /* begin body */
  OFarray_Dnew();
  t1 = retval_area[0];
  OFoneof_Dmake(2, NIL);
  t2 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t2, t1);
  OMrecord_Dset(2, t2, retval_area[0]);
  retval_area[0] = t2;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFassoc__array_Dreset */
/* clu_operation_name, assoc_array$reset */
int OFassoc__array_Dreset(pi, LVtab)
     param_info *pi;
     object LVtab;
{
  /* begin body */
  if (OFarray_Dtrim(OMrecord_Dget(1, LVtab), 1, 0) == SIG)
    {
      goto except0;
    }
  OFoneof_Dmake(2, NIL);
  OMrecord_Dset(2, LVtab, retval_area[0]);
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFassoc__array_Dlookup */
/* clu_operation_name, assoc_array$lookup */
int OFassoc__array_Dlookup(pi, LVtab, LVkey)
     param_info *pi;
     object LVtab;
     object LVkey;
{
  int t1, t2, t3;
  /* begin body */
  t1 = OMrecord_Dget(2, LVtab);
  t2 = ((oneof) t1)->tag;
  if (t2 == 1)
    {
      object LVent= 0;
      LVent = ((oneof) t1)->value;
        {
	  if (OMstring_Dequal(OMrecord_Dget(1, LVent), LVkey))
	    {
	      retval_area[0] = OMrecord_Dget(2, LVent);
	      return RET;
	    }
        }
    }
  else if (t2 == 3)
    {
      object LVn= 0;
      LVn = ((oneof) t1)->value;
        {
	  if (OMstring_Dequal(LVn, LVkey))
	    {
	      signame = SLNOT_FOUND;
	      return(SIG);
	    }
        }
    }
    {
      object LVent= 0;
      for (t1 = OMrecord_Dget(1, LVtab), t2 = OMarray_Dlow(t1), t3 = OMarray_Dhigh(t1);
           t2 <= t3;
           t2++)
        {
	  LVent = OMarray_Dfetch(t1, t2);
	    {
	      if (OMstring_Dequal(OMrecord_Dget(1, LVent), LVkey))
	        {
		  OFoneof_Dmake(1, LVent);
		  OMrecord_Dset(2, LVtab, retval_area[0]);
		  retval_area[0] = OMrecord_Dget(2, LVent);
		  return RET;
	        }
	    }
        }
    }
  OFoneof_Dmake(3, LVkey);
  OMrecord_Dset(2, LVtab, retval_area[0]);
  signame = SLNOT_FOUND;
  return(SIG);
  /* end body */
  noretval(SLNULL);
  return(SIG);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFassoc__array_Denter */
/* clu_operation_name, assoc_array$enter */
int OFassoc__array_Denter(pi, LVtab, LVkey, LVval)
     param_info *pi;
     object LVtab;
     object LVkey;
     object LVval;
{
  int t1, t2, t3;
  /* begin body */
  t1 = OMrecord_Dget(2, LVtab);
  t2 = ((oneof) t1)->tag;
  if (t2 == 1)
    {
      object LVent= 0;
      LVent = ((oneof) t1)->value;
        {
	  if (OMstring_Dequal(OMrecord_Dget(1, LVent), LVkey))
	    {
	      signame = ((string) &str1);
	      return(SIG);
	    }
        }
    }
  else if (t2 == 3)
    {
      object LVn= 0;
      LVn = ((oneof) t1)->value;
        {
	  if (OMstring_Dequal(LVn, LVkey))
	    {
	      t3 = OFrecord_D__alloc(2);
	      OMrecord_Dset(1, t3, LVkey);
	      OMrecord_Dset(2, t3, LVval);
	      OMarray_Daddh(OMrecord_Dget(1, LVtab), t3);
	      OFoneof_Dmake(2, NIL);
	      OMrecord_Dset(2, LVtab, retval_area[0]);
	      return RET;
	    }
        }
    }
    {
      object LVent= 0;
      for (t1 = OMrecord_Dget(1, LVtab), t2 = OMarray_Dlow(t1), t3 = OMarray_Dhigh(t1);
           t2 <= t3;
           t2++)
        {
	  LVent = OMarray_Dfetch(t1, t2);
	    {
	      if (OMstring_Dequal(OMrecord_Dget(1, LVent), LVkey))
	        {
		  signame = ((string) &str1);
		  return(SIG);
	        }
	    }
        }
    }
  t1 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t1, LVkey);
  OMrecord_Dset(2, t1, LVval);
  OMarray_Daddh(OMrecord_Dget(1, LVtab), t1);
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFassoc__array_Dkeys */
/* clu_operation_name, assoc_array$keys */
#define INV_TOP 3
#define WORK_SIZE 6
int OFassoc__array_Dkeys(pi, init, ivarp, LVtab)
     param_info *pi;
     bool init;
     int **ivarp;
     object LVtab;
{
  if (init)
    {
      *ivarp = (int*) malloc(WORK_SIZE*sizeof(int));
      (*ivarp)[1] = LVtab;
    }
  else
    {
      switch ((*ivarp)[0])
  	{
  	  case 1: goto yield1;
  	}
    }
  /* begin body */
    {
      for ((*ivarp)[INV_TOP+0] = OMrecord_Dget(1, (*ivarp)[1]), (*ivarp)[INV_TOP+1] = OMarray_Dlow((*ivarp)[INV_TOP+0]), (*ivarp)[INV_TOP+2] = OMarray_Dhigh((*ivarp)[INV_TOP+0]);
           (*ivarp)[INV_TOP+1] <= (*ivarp)[INV_TOP+2];
           (*ivarp)[INV_TOP+1]++)
        {
	  (*ivarp)[2] = OMarray_Dfetch((*ivarp)[INV_TOP+0], (*ivarp)[INV_TOP+1]);
	    {
	      retval_area[0] = OMrecord_Dget(1, (*ivarp)[2]);
	      (*ivarp)[0] = 1;
	      return YIELD;
	    yield1:
	      NO_OPERATION;
	    }
        }
    }
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
#undef INV_TOP
#undef WORK_SIZE
/* c_function_name, OFassoc__array_Dvalues */
/* clu_operation_name, assoc_array$values */
#define INV_TOP 3
#define WORK_SIZE 6
int OFassoc__array_Dvalues(pi, init, ivarp, LVtab)
     param_info *pi;
     bool init;
     int **ivarp;
     object LVtab;
{
  if (init)
    {
      *ivarp = (int*) malloc(WORK_SIZE*sizeof(int));
      (*ivarp)[1] = LVtab;
    }
  else
    {
      switch ((*ivarp)[0])
  	{
  	  case 1: goto yield1;
  	}
    }
  /* begin body */
    {
      for ((*ivarp)[INV_TOP+0] = OMrecord_Dget(1, (*ivarp)[1]), (*ivarp)[INV_TOP+1] = OMarray_Dlow((*ivarp)[INV_TOP+0]), (*ivarp)[INV_TOP+2] = OMarray_Dhigh((*ivarp)[INV_TOP+0]);
           (*ivarp)[INV_TOP+1] <= (*ivarp)[INV_TOP+2];
           (*ivarp)[INV_TOP+1]++)
        {
	  (*ivarp)[2] = OMarray_Dfetch((*ivarp)[INV_TOP+0], (*ivarp)[INV_TOP+1]);
	    {
	      retval_area[0] = OMrecord_Dget(2, (*ivarp)[2]);
	      (*ivarp)[0] = 1;
	      return YIELD;
	    yield1:
	      NO_OPERATION;
	    }
        }
    }
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
#undef INV_TOP
#undef WORK_SIZE
/* end module */