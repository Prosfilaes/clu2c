/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,object_targets,file_name,source_targets,target,user*/

#include <clu2c.h>

static STRING_REP(1) str1 = {1, {'o'}};
static STRING_REP(1) str2 = {1, {' '}};
static STRING_REP(6) str3 = {6, {' ', '-', 'c', ' ', '$', '<'}};

/* begin module */
/* c_function_name, AFobject__targets */
/* clu_operation_name, object_targets */
#define INV_TOP 5
#define WORK_SIZE 10
int AFobject__targets(init, ivarp, LVu)
     bool init;
     int **ivarp;
     object LVu;
{
  if (init)
    {
      *ivarp = (int*) malloc(WORK_SIZE*sizeof(int));
      (*ivarp)[1] = LVu;
    }
  else
    {
      switch ((*ivarp)[0])
  	{
  	  case 1: goto yield1;
  	  case 2: goto yield2;
  	}
    }
  /* begin body */
    {
      for ((*ivarp)[INV_TOP+0] = AFsource__targets(TRUE, &(*ivarp)[INV_TOP+1], (*ivarp)[1]);
           (*ivarp)[INV_TOP+0] == YIELD;
           (*ivarp)[INV_TOP+0] = AFsource__targets(FALSE, &(*ivarp)[INV_TOP+1], 0))
        {
	  (*ivarp)[2] = retval_area[0];
	    {
	      if (OFtarget_Dget__name((*ivarp)[2]) == SIG)
	        {
		  goto except0;
	        }
	      if (OFfile__name_Dget__name(retval_area[0]) == SIG)
	        {
		  goto except0;
	        }
	      if (OFfile__name_Dcreate(SLNULL, retval_area[0], ((string) &str1), SLNULL) == SIG)
	        {
		  goto except0;
	        }
	      (*ivarp)[3] = retval_area[0];
	      if (OFtarget_Dcreate((*ivarp)[3]) == SIG)
	        {
		  goto except0;
	        }
	      (*ivarp)[4] = retval_area[0];
	      if (OFtarget_Dadd__prereq((*ivarp)[4], (*ivarp)[2]) == SIG)
	        {
		  goto except0;
	        }
	      if (OFuser_Dget__cc((*ivarp)[1]) == SIG)
	        {
		  goto except0;
	        }
	      (*ivarp)[INV_TOP+2] = retval_area[0];
	      if (OFuser_Dget__cc__flags((*ivarp)[1]) == SIG)
	        {
		  goto except0;
	        }
	      (*ivarp)[INV_TOP+3] = OMstring_Dsize((*ivarp)[INV_TOP+2])
	                            + OMstring_Dsize(((string) &str2))
	                            + OMstring_Dsize(retval_area[0])
	                            + OMstring_Dsize(((string) &str3));
	      (*ivarp)[INV_TOP+4] = OFstring_D__predict((*ivarp)[INV_TOP+3]);
	      OFstring_D__concat((*ivarp)[INV_TOP+4], (*ivarp)[INV_TOP+2]);
	      OFstring_D__concat((*ivarp)[INV_TOP+4], ((string) &str2));
	      OFstring_D__concat((*ivarp)[INV_TOP+4], retval_area[0]);
	      OFstring_D__concat((*ivarp)[INV_TOP+4], ((string) &str3));
	      if (OFtarget_Dset__action((*ivarp)[4], (*ivarp)[INV_TOP+4]) == SIG)
	        {
		  goto except0;
	        }
	      retval_area[0] = (*ivarp)[4];
	      (*ivarp)[0] = 1;
	      return YIELD;
	    yield1:
	      NO_OPERATION;
	    }
        }
      free((*ivarp)[INV_TOP+1]);
      if ((*ivarp)[INV_TOP+0] == SIG)
        {
	  goto except0;
        }
    }
    {
      for ((*ivarp)[INV_TOP+0] = OFuser_Dobjects(TRUE, &(*ivarp)[INV_TOP+1], (*ivarp)[1]);
           (*ivarp)[INV_TOP+0] == YIELD;
           (*ivarp)[INV_TOP+0] = OFuser_Dobjects(FALSE, &(*ivarp)[INV_TOP+1], 0))
        {
	  (*ivarp)[2] = retval_area[0];
	    {
	      if (OFtarget_Dcreate((*ivarp)[2]) == SIG)
	        {
		  goto except0;
	        }
	      retval_area[0] = retval_area[0];
	      (*ivarp)[0] = 2;
	      return YIELD;
	    yield2:
	      NO_OPERATION;
	    }
        }
      free((*ivarp)[INV_TOP+1]);
      if ((*ivarp)[INV_TOP+0] == SIG)
        {
	  goto except0;
        }
    }
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
#undef INV_TOP
#undef WORK_SIZE
/* end module */
