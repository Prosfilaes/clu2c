/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,working_dir,file_name,rt_env*/

#include <clu2c.h>

/* begin module */
/* c_function_name, AFworking__dir */
/* clu_operation_name, working_dir */
int AFworking__dir()
{
  object LVe= 0;
  object LVwork__dir= 0;
  /* begin body */
  if (OFrt__env_Done() == SIG)
    {
      goto except0;
    }
  LVe = retval_area[0];
  if (OFrt__env_Dget__working__directory(LVe) == SIG)
    {
      goto except1;
    }
  if (OFfile__name_Dunparse(retval_area[0]) == SIG)
    {
      goto except1;
    }
  LVwork__dir = retval_area[0];
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLUNDEFINED))
        {
	  LVwork__dir = SLNULL;
        }
      else
        {
	  goto except0;
        }
    }
  retval_area[0] = LVwork__dir;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */