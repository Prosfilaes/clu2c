/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,file_name_nondirectory,file_name*/

#include <clu2c.h>

/* begin module */
/* c_function_name, AFfile__name__nondirectory */
/* clu_operation_name, file_name_nondirectory */
int AFfile__name__nondirectory(LVfn)
     object LVfn;
{
  object LVentry= 0;
  int t1, t2, t3;
  /* begin body */
  if (OFfile__name_Dget__name(LVfn) == SIG)
    {
      goto except0;
    }
  if (OMstring_Dempty(retval_area[0]))
    {
      LVentry = SLNULL;
    }
  else
    {
      if (OFfile__name_Dget__suffix(LVfn) == SIG)
        {
	  goto except0;
        }
      if (OMstring_Dempty(retval_area[0]))
        {
	  if (OFfile__name_Dget__name(LVfn) == SIG)
	    {
	      goto except0;
	    }
	  LVentry = retval_area[0];
        }
      else
        {
	  if (OFfile__name_Dget__name(LVfn) == SIG)
	    {
	      goto except0;
	    }
	  OFstring_Dappend(retval_area[0], '.');
	  t1 = retval_area[0];
	  if (OFfile__name_Dget__suffix(LVfn) == SIG)
	    {
	      goto except0;
	    }
	  t2 = OMstring_Dsize(t1)
	       + OMstring_Dsize(retval_area[0]);
	  t3 = OFstring_D__predict(t2);
	  OFstring_D__concat(t3, t1);
	  OFstring_D__concat(t3, retval_area[0]);
	  LVentry = t3;
        }
    }
  retval_area[0] = LVentry;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */