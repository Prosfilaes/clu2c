/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,program_arguments,rt_env*/

#include <clu2c.h>

/* begin module */
/* c_function_name, AFprogram__arguments */
/* clu_operation_name, program_arguments */
int AFprogram__arguments()
{
  /* begin body */
  if (OFrt__env_Done() == SIG)
    {
      goto except0;
    }
  if (OFrt__env_Dget__argument__vector(retval_area[0]) == SIG)
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