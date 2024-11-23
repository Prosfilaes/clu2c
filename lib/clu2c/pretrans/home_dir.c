/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,home_directory,_external_getenv,_external_getpwnam,file_name,rt_env*/

#include <clu2c.h>

static STRING_REP(4) str1 = {4, {'H', 'O', 'M', 'E'}};
static STRING_REP(3) str2 = {3, {'C', 'L', 'U'}};

/* begin module */
/* c_function_name, AFhome__directory */
/* clu_operation_name, home_directory */
int AFhome__directory(LVuser)
     object LVuser;
{
  object LVdir= 0;
  /* begin body */
  if (OMstring_Dempty(LVuser))
    {
      if (AF__external__getenv(((string) &str1)) == SIG)
        {
	  goto except1;
        }
      LVdir = retval_area[0];
    }
  else
    {
      if (OMstring_Dequal(LVuser, ((string) &str2)))
        {
	  if (OFrt__env_Done() == SIG)
	    {
	      goto except1;
	    }
	  if (OFrt__env_Dget__system__root__directory(retval_area[0]) == SIG)
	    {
	      goto except1;
	    }
	  if (OFfile__name_Dget__dir(retval_area[0]) == SIG)
	    {
	      goto except1;
	    }
	  LVdir = retval_area[0];
        }
      else
        {
	  if (AF__external__getpwnam(LVuser) == SIG)
	    {
	      goto except1;
	    }
	  if (OF__external__struct__passwd_Dget__dir(retval_area[0]) == SIG)
	    {
	      goto except1;
	    }
	  LVdir = retval_area[0];
        }
    }
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
  if (OFfile__name_Dcreate(LVdir, SLNULL, SLNULL, SLNULL) == SIG)
    {
      goto except2;
    }
  retval_area[0] = retval_area[0];
  return RET;
  if (FALSE)
    {
    except2:
      if (OMstring_Dequal(signame, SLBAD_FORMAT))
        {
	  signame = SLNOT_FOUND;
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