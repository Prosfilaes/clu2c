/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,file_date,_external_localtime,_external_stat,_external_struct_stat,_external_struct_tm,date,file_name,file_name_to_string*/

#include <clu2c.h>

static STRING_REP(9) str1 = {9, {'b', 'a', 'd', '_', 'f', 'o', 'm', 'a', 't'}};
static STRING_REP(15) str2 = {15, {'b', 'a', 'd', ' ', 'f', 'o', 'r', 'm', 'a', 't', ' ', 'd', 'a', 't', 'e'}};

/* begin module */
/* c_function_name, AFfile__date */
/* clu_operation_name, file_date */
int AFfile__date(LVfn, LVread)
     object LVfn;
     object LVread;
{
  object LVstatus= 0;
  object LVt= 0;
  object LVtime= 0;
  int t1, t2, t3, t4, t5;
  /* begin body */
  if (AFfile__name__to__string(LVfn) == SIG)
    {
      goto except1;
    }
  if (AF__external__stat(retval_area[0]) == SIG)
    {
      goto except1;
    }
  LVstatus = retval_area[0];
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_POSSIBLE))
        {
	  return(SIG);
        }
      else
        {
	  goto except0;
        }
    }
  if (LVread)
    {
      if (OF__external__struct__stat_Dget__atime(LVstatus) == SIG)
        {
	  goto except0;
        }
      LVt = retval_area[0];
    }
  else
    {
      if (OF__external__struct__stat_Dget__mtime(LVstatus) == SIG)
        {
	  goto except0;
        }
      LVt = retval_area[0];
    }
  if (AF__external__localtime(LVt) == SIG)
    {
      goto except0;
    }
  LVtime = retval_area[0];
  if (OF__external__struct__tm_Dget__mday(LVtime) == SIG)
    {
      goto except2;
    }
  t1 = retval_area[0];
  if (OF__external__struct__tm_Dget__mon(LVtime) == SIG)
    {
      goto except2;
    }
  t2 = OMint_Dadd(retval_area[0], 1);
  if (OF__external__struct__tm_Dget__year(LVtime) == SIG)
    {
      goto except2;
    }
  t3 = OMint_Dadd(retval_area[0], 1900);
  if (OF__external__struct__tm_Dget__hour(LVtime) == SIG)
    {
      goto except2;
    }
  t4 = retval_area[0];
  if (OF__external__struct__tm_Dget__min(LVtime) == SIG)
    {
      goto except2;
    }
  t5 = retval_area[0];
  if (OF__external__struct__tm_Dget__sec(LVtime) == SIG)
    {
      goto except2;
    }
  if (OFdate_Dcreate(t1, t2, t3, t4, t5, retval_area[0]) == SIG)
    {
      goto except2;
    }
  retval_area[0] = retval_area[0];
  return RET;
  if (FALSE)
    {
    except2:
      if (OMstring_Dequal(signame, ((string) &str1)))
        {
	  sigarg_area[0] = ((string) &str2);
	  signame = SLNOT_POSSIBLE;
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