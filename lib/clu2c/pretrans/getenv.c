/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,getenv,_external_getenv*/

#include <clu2c.h>

/* begin module */
/* c_function_name, AFgetenv */
/* clu_operation_name, getenv */
int AFgetenv(LVname)
     object LVname;
{
  /* begin body */
  if (AF__external__getenv(LVname) == SIG)
    {
      goto except1;
    }
  retval_area[0] = retval_area[0];
  return RET;
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_FOUND))
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
