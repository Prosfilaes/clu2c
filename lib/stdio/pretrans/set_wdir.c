/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,set_working_dir,file_name,file_name_apply_directory,rt_env*/

#include <clu2c.h>

/* begin module */
/* c_function_name, AFset__working__dir */
/* clu_operation_name, set_working_dir */
int AFset__working__dir(LVs)
     object LVs;
{
  object LVe= 0;
  object LVworking__dir= 0;
  /* begin body */
  if (OFrt__env_Done() == SIG)
    {
      goto except0;
    }
  LVe = retval_area[0];
  if (OMstring_Dempty(LVs))
    {
      if (OFrt__env_Dunset__working__directory(LVe) == SIG)
        {
	  goto except0;
        }
      return RET;
    }
  if (OFfile__name_Dcreate(LVs, SLNULL, SLNULL, SLNULL) == SIG)
    {
      goto except1;
    }
  LVworking__dir = retval_area[0];
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLBAD_FORMAT))
        {
	  return(SIG);
        }
      else
        {
	  goto except0;
        }
    }
  if (OFrt__env_Dget__working__directory(LVe) == SIG)
    {
      goto except2;
    }
  if (AFfile__name__apply__directory(LVworking__dir, retval_area[0]) == SIG)
    {
      goto except2;
    }
  LVworking__dir = retval_area[0];
  if (FALSE)
    {
    except2:
      if (OMstring_Dequal(signame, SLUNDEFINED))
        {
        }
      else
        {
	  goto except0;
        }
    }
  if (OFrt__env_Dset__working__directory(LVe, LVworking__dir) == SIG)
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