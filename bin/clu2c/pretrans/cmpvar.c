/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,cmpvar,binary_suffix*/

#include <clu2c.h>

static object	WVcompiler__stuff_IN_Ccmpvar;
static object	WVlist__externals_IN_Ccmpvar;
static object	WVdebug__mode_IN_Ccmpvar;
static object	WVallow__errors_IN_Ccmpvar;
static object	WVbinary__dir_IN_Ccmpvar;
static object	WVlocal__vars_IN_Ccmpvar;
static object	WVbin__suffix_IN_Ccmpvar;
static object	WVdo__force_IN_Ccmpvar;
static object	WVoptimize__mode_IN_Ccmpvar;
static object	WVexpunge__specs_IN_Ccmpvar;
static bool	IV_IN_Ccmpvar = FALSE;
static object	WVreserved__modules_IN_Ccmpvar;
static object	WVcompiler__version_IN_Ccmpvar;
static object	WVcompiler__save__date_IN_Ccmpvar;

static STRING_REP(3) str1 = {3, {'?', '?', '?'}};

/* begin module */
/* c_function_name, OFcmpvar_Dlocals */
/* clu_operation_name, cmpvar$locals */
int OFcmpvar_Dlocals()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = WVlocal__vars_IN_Ccmpvar;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dset__locals */
/* clu_operation_name, cmpvar$set_locals */
int OFcmpvar_Dset__locals(LVb)
     object LVb;
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVlocal__vars_IN_Ccmpvar = LVb;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dforce__ */
/* clu_operation_name, cmpvar$force_ */
int OFcmpvar_Dforce__()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = WVdo__force_IN_Ccmpvar;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dset__force__ */
/* clu_operation_name, cmpvar$set_force_ */
int OFcmpvar_Dset__force__(LVb)
     object LVb;
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVdo__force_IN_Ccmpvar = LVb;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dexternals */
/* clu_operation_name, cmpvar$externals */
int OFcmpvar_Dexternals()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = WVlist__externals_IN_Ccmpvar;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dset__externals */
/* clu_operation_name, cmpvar$set_externals */
int OFcmpvar_Dset__externals(LVb)
     object LVb;
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVlist__externals_IN_Ccmpvar = LVb;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Ddir */
/* clu_operation_name, cmpvar$dir */
int OFcmpvar_Ddir()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = WVbinary__dir_IN_Ccmpvar;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dset__dir */
/* clu_operation_name, cmpvar$set_dir */
int OFcmpvar_Dset__dir(LVs)
     object LVs;
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVbinary__dir_IN_Ccmpvar = LVs;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dsuffix */
/* clu_operation_name, cmpvar$suffix */
int OFcmpvar_Dsuffix()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = WVbin__suffix_IN_Ccmpvar;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dset__suffix */
/* clu_operation_name, cmpvar$set_suffix */
int OFcmpvar_Dset__suffix(LVs)
     object LVs;
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  if (OMstring_Dempty(LVs))
    {
      if (AFbinary__suffix() == SIG)
        {
	  goto except0;
        }
      LVs = retval_area[0];
    }
  WVbin__suffix_IN_Ccmpvar = LVs;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dallow */
/* clu_operation_name, cmpvar$allow */
int OFcmpvar_Dallow()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = WVallow__errors_IN_Ccmpvar;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dset__allow */
/* clu_operation_name, cmpvar$set_allow */
int OFcmpvar_Dset__allow(LVb)
     object LVb;
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVallow__errors_IN_Ccmpvar = LVb;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dexpunge */
/* clu_operation_name, cmpvar$expunge */
int OFcmpvar_Dexpunge()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = WVexpunge__specs_IN_Ccmpvar;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dset__expunge */
/* clu_operation_name, cmpvar$set_expunge */
int OFcmpvar_Dset__expunge(LVb)
     object LVb;
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVexpunge__specs_IN_Ccmpvar = LVb;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dmodules */
/* clu_operation_name, cmpvar$modules */
int OFcmpvar_Dmodules()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = WVreserved__modules_IN_Ccmpvar;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dset__modules */
/* clu_operation_name, cmpvar$set_modules */
int OFcmpvar_Dset__modules(LVs)
     object LVs;
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVreserved__modules_IN_Ccmpvar = LVs;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dversion */
/* clu_operation_name, cmpvar$version */
int OFcmpvar_Dversion()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = WVcompiler__version_IN_Ccmpvar;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dset__version */
/* clu_operation_name, cmpvar$set_version */
int OFcmpvar_Dset__version(LVs)
     object LVs;
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVcompiler__version_IN_Ccmpvar = LVs;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Ddate */
/* clu_operation_name, cmpvar$date */
int OFcmpvar_Ddate()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = WVcompiler__save__date_IN_Ccmpvar;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dset__date */
/* clu_operation_name, cmpvar$set_date */
int OFcmpvar_Dset__date(LVs)
     object LVs;
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVcompiler__save__date_IN_Ccmpvar = LVs;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dstuffs */
/* clu_operation_name, cmpvar$stuffs */
int OFcmpvar_Dstuffs()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = WVcompiler__stuff_IN_Ccmpvar;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dset__stuffs */
/* clu_operation_name, cmpvar$set_stuffs */
int OFcmpvar_Dset__stuffs(LVs)
     object LVs;
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVcompiler__stuff_IN_Ccmpvar = LVs;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Ddebug */
/* clu_operation_name, cmpvar$debug */
int OFcmpvar_Ddebug()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = WVdebug__mode_IN_Ccmpvar;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dset__debug */
/* clu_operation_name, cmpvar$set_debug */
int OFcmpvar_Dset__debug(LVflag)
     object LVflag;
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVdebug__mode_IN_Ccmpvar = LVflag;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Doptimize */
/* clu_operation_name, cmpvar$optimize */
int OFcmpvar_Doptimize()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = OMint_Dgt(WVoptimize__mode_IN_Ccmpvar, 0);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Doptimize__time */
/* clu_operation_name, cmpvar$optimize_time */
int OFcmpvar_Doptimize__time()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = OMint_Dequal(WVoptimize__mode_IN_Ccmpvar, 2);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dnot__optimize */
/* clu_operation_name, cmpvar$not_optimize */
int OFcmpvar_Dnot__optimize()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  retval_area[0] = OMint_Dequal(WVoptimize__mode_IN_Ccmpvar, 0);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dset__optimize__space */
/* clu_operation_name, cmpvar$set_optimize_space */
int OFcmpvar_Dset__optimize__space()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVoptimize__mode_IN_Ccmpvar = 1;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dset__optimize__time */
/* clu_operation_name, cmpvar$set_optimize_time */
int OFcmpvar_Dset__optimize__time()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVoptimize__mode_IN_Ccmpvar = 2;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFcmpvar_Dset__not__optimize */
/* clu_operation_name, cmpvar$set_not_optimize */
int OFcmpvar_Dset__not__optimize()
{
  if (IV_IN_Ccmpvar == FALSE)
    {
      IV_IN_Ccmpvar = TRUE;
      if (IF_IN_Ccmpvar() == SIG)
        {
	  goto except0;
        }
    }
  /* begin body */
  WVoptimize__mode_IN_Ccmpvar = 0;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, IF_IN_Ccmpvar */
/* clu_operation_name, cmpvar$#initown */
int IF_IN_Ccmpvar()
{
  /* begin body */
  WVlocal__vars_IN_Ccmpvar = TRUE;
  WVdo__force_IN_Ccmpvar = TRUE;
  WVlist__externals_IN_Ccmpvar = FALSE;
  WVbinary__dir_IN_Ccmpvar = SLNULL;
  if (AFbinary__suffix() == SIG)
    {
      goto except0;
    }
  WVbin__suffix_IN_Ccmpvar = retval_area[0];
  WVallow__errors_IN_Ccmpvar = FALSE;
  WVexpunge__specs_IN_Ccmpvar = FALSE;
  WVreserved__modules_IN_Ccmpvar = SLNULL;
  WVcompiler__version_IN_Ccmpvar = ((string) &str1);
  WVcompiler__save__date_IN_Ccmpvar = ((string) &str1);
  WVdebug__mode_IN_Ccmpvar = FALSE;
  WVoptimize__mode_IN_Ccmpvar = 0;
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */
