/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,user_name,_external_getenv*/

#include <clu2c.h>

static STRING_REP(4) str1 = {4, {'U', 'S', 'E', 'R'}};

/* begin module */
/* c_function_name, AFuser__name */
/* clu_operation_name, user_name */
int AFuser__name()
{
  /* begin body */
  if (AF__external__getenv(((string) &str1)) == SIG)
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
	  retval_area[0] = SLNULL;
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
/* end module */
