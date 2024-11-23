/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,parmlist_unparse,parameter_unparse*/
/* depend,fieldspeclist_unparse,fieldspec_unparse*/
/* depend,fieldspec_unparse,tparm_unparse*/
/* depend,parameter_unparse,tparm_unparse,vparm_unparse*/
/* depend,tparm_unparse,cluinst,selinst*/
/* depend,vparm_unparse*/
/* depend,selinst_unparse,fieldspeclist_unparse,selinst*/
/* depend,cluinst_unparse,cluinst,parmlist_unparse*/
/* depend,appinst_unparse,appinst,parmlist_unparse*/

#include <clu2c.h>

static STRING_REP(1) str1 = {1, {' '}};
static STRING_REP(1) str2 = {1, {':'}};
static STRING_REP(7) str3 = {7, {'#', 't', 'p', 'a', 'r', 'm', '['}};
static STRING_REP(1) str4 = {1, {']'}};
static STRING_REP(7) str5 = {7, {'#', 'v', 'p', 'a', 'r', 'm', '['}};
static STRING_REP(14) str6 = {14, {'#', 'v', 'p', 'a', 'r', 'm', '_', 'f', 'o', 'r', 'm', 'a', 'l', '['}};
static STRING_REP(1) str7 = {1, {'['}};

/* begin module */
/* c_function_name, AFparmlist__unparse */
/* clu_operation_name, parmlist_unparse */
int AFparmlist__unparse(LVparm)
     object LVparm;
{
  object LVparmlist__string= 0;
  object LVfirst= 0;
  int t1, t2, t3, t4, t5;
  /* begin body */
  LVparmlist__string = SLNULL;
  LVfirst = TRUE;
    {
      object LVp= 0;
      for (t1 = LVparm, t2 = OMarray_Dlow(t1), t3 = OMarray_Dhigh(t1);
           t2 <= t3;
           t2++)
        {
	  LVp = OMarray_Dfetch(t1, t2);
	    {
	      if (LVfirst)
	        {
		  if (AFparameter__unparse(LVp) == SIG)
		    {
		      goto except0;
		    }
		  LVparmlist__string = retval_area[0];
		  LVfirst = FALSE;
	        }
	      else
	        {
		  if (AFparameter__unparse(LVp) == SIG)
		    {
		      goto except0;
		    }
		  t4 = OMstring_Dsize(LVparmlist__string)
		       + OMstring_Dsize(((string) &str1))
		       + OMstring_Dsize(retval_area[0]);
		  t5 = OFstring_D__predict(t4);
		  OFstring_D__concat(t5, LVparmlist__string);
		  OFstring_D__concat(t5, ((string) &str1));
		  OFstring_D__concat(t5, retval_area[0]);
		  LVparmlist__string = t5;
	        }
	    }
        }
    }
  retval_area[0] = LVparmlist__string;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFfieldspeclist__unparse */
/* clu_operation_name, fieldspeclist_unparse */
int AFfieldspeclist__unparse(LVparm)
     object LVparm;
{
  object LVfieldspec__string= 0;
  object LVfirst= 0;
  int t1, t2, t3, t4, t5;
  /* begin body */
  LVfieldspec__string = SLNULL;
  LVfirst = TRUE;
    {
      object LVf= 0;
      for (t1 = LVparm, t2 = OMarray_Dlow(t1), t3 = OMarray_Dhigh(t1);
           t2 <= t3;
           t2++)
        {
	  LVf = OMarray_Dfetch(t1, t2);
	    {
	      if (LVfirst)
	        {
		  if (AFfieldspec__unparse(LVf) == SIG)
		    {
		      goto except0;
		    }
		  LVfieldspec__string = retval_area[0];
		  LVfirst = FALSE;
	        }
	      else
	        {
		  if (AFfieldspec__unparse(LVf) == SIG)
		    {
		      goto except0;
		    }
		  t4 = OMstring_Dsize(LVfieldspec__string)
		       + OMstring_Dsize(((string) &str1))
		       + OMstring_Dsize(retval_area[0]);
		  t5 = OFstring_D__predict(t4);
		  OFstring_D__concat(t5, LVfieldspec__string);
		  OFstring_D__concat(t5, ((string) &str1));
		  OFstring_D__concat(t5, retval_area[0]);
		  LVfieldspec__string = t5;
	        }
	    }
        }
    }
  retval_area[0] = LVfieldspec__string;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFfieldspec__unparse */
/* clu_operation_name, fieldspec_unparse */
int AFfieldspec__unparse(LVf)
     object LVf;
{
  int t1, t2, t3;
  /* begin body */
  t1 = OMrecord_Dget(2, LVf);
  if (AFtparm__unparse(OMrecord_Dget(1, LVf)) == SIG)
    {
      goto except0;
    }
  t2 = OMstring_Dsize(t1)
       + OMstring_Dsize(((string) &str2))
       + OMstring_Dsize(retval_area[0]);
  t3 = OFstring_D__predict(t2);
  OFstring_D__concat(t3, t1);
  OFstring_D__concat(t3, ((string) &str2));
  OFstring_D__concat(t3, retval_area[0]);
  retval_area[0] = t3;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFparameter__unparse */
/* clu_operation_name, parameter_unparse */
int AFparameter__unparse(LVparm)
     object LVparm;
{
  int t1;
  /* begin body */
  t1 = ((oneof) LVparm)->tag;
  if (t1 == 1)
    {
      object LVt= 0;
      LVt = ((oneof) LVparm)->value;
        {
	  if (AFtparm__unparse(LVt) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else if (t1 == 2)
    {
      object LVv= 0;
      LVv = ((oneof) LVparm)->value;
        {
	  if (AFvparm__unparse(LVv) == SIG)
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
/* end module */

/* begin module */
/* c_function_name, AFtparm__unparse */
/* clu_operation_name, tparm_unparse */
int AFtparm__unparse(LVt)
     object LVt;
{
  int t1, t2, t3;
  /* begin body */
  t1 = ((oneof) LVt)->tag;
  if (t1 == 1)
    {
      object LVclu= 0;
      LVclu = ((oneof) LVt)->value;
        {
	  if (OFcluinst_Dget__typeid(LVclu) == SIG)
	    {
	      goto except0;
	    }
	  OFint_Dunparse(retval_area[0]);
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else if (t1 == 3)
    {
      object LVsel= 0;
      LVsel = ((oneof) LVt)->value;
        {
	  if (OFselinst_Dget__typeid(LVsel) == SIG)
	    {
	      goto except0;
	    }
	  OFint_Dunparse(retval_area[0]);
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else if (t1 == 2)
    {
      object LVi= 0;
      LVi = ((oneof) LVt)->value;
        {
	  OFint_Dunparse(LVi);
	  t2 = OMstring_Dsize(((string) &str3))
	       + OMstring_Dsize(retval_area[0])
	       + OMstring_Dsize(((string) &str4));
	  t3 = OFstring_D__predict(t2);
	  OFstring_D__concat(t3, ((string) &str3));
	  OFstring_D__concat(t3, retval_area[0]);
	  OFstring_D__concat(t3, ((string) &str4));
	  retval_area[0] = t3;
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
/* end module */

/* begin module */
/* c_function_name, AFvparm__unparse */
/* clu_operation_name, vparm_unparse */
int AFvparm__unparse(LVv)
     object LVv;
{
  int t1, t2, t3;
  /* begin body */
  t1 = ((oneof) LVv)->tag;
  if (t1 == 2)
    {
      object LVs= 0;
      LVs = ((oneof) LVv)->value;
        {
	  t2 = OMstring_Dsize(((string) &str5))
	       + OMstring_Dsize(LVs)
	       + OMstring_Dsize(((string) &str4));
	  t3 = OFstring_D__predict(t2);
	  OFstring_D__concat(t3, ((string) &str5));
	  OFstring_D__concat(t3, LVs);
	  OFstring_D__concat(t3, ((string) &str4));
	  retval_area[0] = t3;
	  return RET;
        }
    }
  else if (t1 == 1)
    {
      object LVi= 0;
      LVi = ((oneof) LVv)->value;
        {
	  OFint_Dunparse(LVi);
	  t2 = OMstring_Dsize(((string) &str6))
	       + OMstring_Dsize(retval_area[0])
	       + OMstring_Dsize(((string) &str4));
	  t3 = OFstring_D__predict(t2);
	  OFstring_D__concat(t3, ((string) &str6));
	  OFstring_D__concat(t3, retval_area[0]);
	  OFstring_D__concat(t3, ((string) &str4));
	  retval_area[0] = t3;
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
/* end module */

/* begin module */
/* c_function_name, AFselinst__unparse */
/* clu_operation_name, selinst_unparse */
int AFselinst__unparse(LVinst)
     object LVinst;
{
  int t1, t2, t3;
  /* begin body */
  if (OFselinst_Dget__parms(LVinst) == SIG)
    {
      goto except0;
    }
  if (OMarray_Dempty(retval_area[0]))
    {
      if (OFselinst_Dget__gen(LVinst) == SIG)
        {
	  goto except0;
        }
      if (OFselgen_Dget__name(retval_area[0]) == SIG)
        {
	  goto except0;
        }
      retval_area[0] = retval_area[0];
      return RET;
    }
  else
    {
      if (OFselinst_Dget__gen(LVinst) == SIG)
        {
	  goto except0;
        }
      if (OFselgen_Dget__name(retval_area[0]) == SIG)
        {
	  goto except0;
        }
      t1 = retval_area[0];
      if (OFselinst_Dget__parms(LVinst) == SIG)
        {
	  goto except0;
        }
      if (AFfieldspeclist__unparse(retval_area[0]) == SIG)
        {
	  goto except0;
        }
      t2 = OMstring_Dsize(t1)
           + OMstring_Dsize(((string) &str7))
           + OMstring_Dsize(retval_area[0])
           + OMstring_Dsize(((string) &str4));
      t3 = OFstring_D__predict(t2);
      OFstring_D__concat(t3, t1);
      OFstring_D__concat(t3, ((string) &str7));
      OFstring_D__concat(t3, retval_area[0]);
      OFstring_D__concat(t3, ((string) &str4));
      retval_area[0] = t3;
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
/* c_function_name, AFcluinst__unparse */
/* clu_operation_name, cluinst_unparse */
int AFcluinst__unparse(LVinst)
     object LVinst;
{
  int t1, t2, t3;
  /* begin body */
  if (OFcluinst_Dget__parms(LVinst) == SIG)
    {
      goto except0;
    }
  if (OMarray_Dempty(retval_area[0]))
    {
      if (OFcluinst_Dget__gen(LVinst) == SIG)
        {
	  goto except0;
        }
      if (OFclugen_Dget__name(retval_area[0]) == SIG)
        {
	  goto except0;
        }
      retval_area[0] = retval_area[0];
      return RET;
    }
  else
    {
      if (OFcluinst_Dget__gen(LVinst) == SIG)
        {
	  goto except0;
        }
      if (OFclugen_Dget__name(retval_area[0]) == SIG)
        {
	  goto except0;
        }
      t1 = retval_area[0];
      if (OFcluinst_Dget__parms(LVinst) == SIG)
        {
	  goto except0;
        }
      if (AFparmlist__unparse(retval_area[0]) == SIG)
        {
	  goto except0;
        }
      t2 = OMstring_Dsize(t1)
           + OMstring_Dsize(((string) &str7))
           + OMstring_Dsize(retval_area[0])
           + OMstring_Dsize(((string) &str4));
      t3 = OFstring_D__predict(t2);
      OFstring_D__concat(t3, t1);
      OFstring_D__concat(t3, ((string) &str7));
      OFstring_D__concat(t3, retval_area[0]);
      OFstring_D__concat(t3, ((string) &str4));
      retval_area[0] = t3;
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
/* c_function_name, AFappinst__unparse */
/* clu_operation_name, appinst_unparse */
int AFappinst__unparse(LVinst)
     object LVinst;
{
  int t1, t2, t3;
  /* begin body */
  if (OFappinst_Dget__parms(LVinst) == SIG)
    {
      goto except0;
    }
  if (OMarray_Dempty(retval_area[0]))
    {
      if (OFappinst_Dget__gen(LVinst) == SIG)
        {
	  goto except0;
        }
      if (OFappgen_Dget__name(retval_area[0]) == SIG)
        {
	  goto except0;
        }
      retval_area[0] = retval_area[0];
      return RET;
    }
  else
    {
      if (OFappinst_Dget__gen(LVinst) == SIG)
        {
	  goto except0;
        }
      if (OFappgen_Dget__name(retval_area[0]) == SIG)
        {
	  goto except0;
        }
      t1 = retval_area[0];
      if (OFappinst_Dget__parms(LVinst) == SIG)
        {
	  goto except0;
        }
      if (AFparmlist__unparse(retval_area[0]) == SIG)
        {
	  goto except0;
        }
      t2 = OMstring_Dsize(t1)
           + OMstring_Dsize(((string) &str7))
           + OMstring_Dsize(retval_area[0])
           + OMstring_Dsize(((string) &str4));
      t3 = OFstring_D__predict(t2);
      OFstring_D__concat(t3, t1);
      OFstring_D__concat(t3, ((string) &str7));
      OFstring_D__concat(t3, retval_area[0]);
      OFstring_D__concat(t3, ((string) &str4));
      retval_area[0] = t3;
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