/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,terminate,_external_exit,stream*/

#include <clu2c.h>

/* begin module */
/* c_function_name, AFterminate */
/* clu_operation_name, terminate */
int AFterminate(LVstatus)
     object LVstatus;
{
  /* begin body */
  if (OFstream_D__close__all() == SIG)
    {
      goto except0;
    }
  if (AF__external__exit(LVstatus) == SIG)
    {
      goto except0;
    }
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */
