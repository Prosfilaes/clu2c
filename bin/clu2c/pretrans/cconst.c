/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,c_parm_type,c_env,c_type,expr,idn,typespec*/
/* depend,c_equateval,c_env,c_equate_expr,c_pathname,c_xtypeset,expr*/
/* depend,c_equate_expr,c_env,c_expr,e_expr,expr,idn*/
/* depend,c_xtypeset,c_add_opspecs,c_env,c_operdecllist,expr,idn,typespec*/
/* depend,c_pathname,c_env,c_get_idnkind,du,xlib*/
/* depend,c_get_idnkind,c_env,c_get_duspecs,du,expr,typespec*/
/* depend,c_constlist,c_const,c_env,expr*/
/* depend,c_const,c_env,c_expr,e_expr,expr*/
/* depend,c_type,c_constlist,c_env,c_exceptionlist,c_gen_parms,c_idn_gen,c_idn_type,c_type1,c_typelist,c_xsel_type,idn,typespec*/
/* depend,c_type1,c_env,c_gen_parms,expr,typespec*/
/* depend,c_typelist,c_env,c_type,typespec*/
/* depend,c_exceptionlist,c_env,c_typelist*/
/* depend,c_idn_gen,c_env,c_gen_parms,du,idn,typespec*/
/* depend,c_idn_type,c_env,expr,idn,typespec*/
/* depend,c_xsel_type,c_env,c_get_duspecs,du,idn*/

#include <clu2c.h>

static STRING_REP(11) str1 = {11, {'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', ' ', '\''}};
static STRING_REP(28) str2 = {28, {'\'', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'e', 'd', ' ', 'w', 'i', 't', 'h', ' ', 'i', 'l', 'l', 'e', 'g', 'a', 'l', ' ', 't', 'y', 'p', 'e'}};
static STRING_REP(20) str3 = {20, {'i', 'l', 'l', 'e', 'g', 'a', 'l', ' ', 'u', 's', 'e', ' ', 'o', 'f', ' ', '\'', 'c', 'v', 't', '\''}};
static STRING_REP(26) str4 = {26, {'i', 'l', 'l', 'e', 'g', 'a', 'l', ' ', 'u', 's', 'e', ' ', 'o', 'f', ' ', 't', 'y', 'p', 'e', ' ', '\'', 't', 'y', 'p', 'e', '\''}};
static STRING_REP(34) str5 = {34, {'\'', 'f', 'a', 'i', 'l', 'u', 'r', 'e', '\'', ' ', 'l', 'i', 's', 't', 'e', 'd', ' ', 'i', 'n', ' ', 's', 'i', 'g', 'n', 'a', 'l', 's', ' ', 'c', 'l', 'a', 'u', 's', 'e'}};
static STRING_REP(1) str6 = {1, {'\''}};
static STRING_REP(32) str7 = {32, {'\'', ' ', 'd', 'o', 'e', 's', ' ', 'n', 'o', 't', ' ', 'n', 'a', 'm', 'e', ' ', 'a', ' ', 't', 'y', 'p', 'e', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r'}};
static STRING_REP(22) str8 = {22, {'\'', ' ', 'd', 'o', 'e', 's', ' ', 'n', 'o', 't', ' ', 'n', 'a', 'm', 'e', ' ', 'a', ' ', 't', 'y', 'p', 'e'}};
static STRING_REP(17) str9 = {17, {'u', 's', 'e', ' ', 'o', 'f', ' ', 'v', 'a', 'r', 'i', 'a', 'b', 'l', 'e', ' ', '\''}};
static STRING_REP(20) str10 = {20, {'\'', ' ', 'a', 's', ' ', 'a', ' ', 't', 'y', 'p', 'e', ' ', 'c', 'o', 'n', 's', 't', 'a', 'n', 't'}};
static STRING_REP(18) str11 = {18, {'u', 's', 'e', ' ', 'o', 'f', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', '\''}};
static STRING_REP(11) str12 = {11, {'\'', ' ', 'a', 's', ' ', 'a', ' ', 't', 'y', 'p', 'e'}};
static STRING_REP(41) str13 = {41, {'\'', ' ', 'd', 'o', 'e', 's', ' ', 'n', 'o', 't', ' ', 'n', 'a', 'm', 'e', ' ', 'a', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 't', 'y', 'p', 'e', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r'}};

/* begin module */
/* c_function_name, AFc__parm__type */
/* clu_operation_name, c_parm_type */
int AFc__parm__type(LVe, LVi, LVt)
     object LVe;
     object LVi;
     object LVt;
{
  object LVxa= 0;
  int t1, t2, t3, t4, t5, t6;
  /* begin body */
  if (AFc__type(LVe, LVt) == SIG)
    {
      goto except0;
    }
  LVt = retval_area[0];
  if (OFc__env_Dget__type__type(LVe) == SIG)
    {
      goto except0;
    }
  if (OFtypespec_Dequal(LVt, retval_area[0]) == SIG)
    {
      goto except0;
    }
  if (retval_area[0])
    {
      object LVni= 0;
      object LVnt= 0;
      if (OFidn_Dget__str(LVi) == SIG)
        {
	  goto except0;
        }
      t1 = retval_area[0];
      OFsequence_Dnew();
      OFoneof_Dmake(6, retval_area[0]);
      if (OFidn_Dcreate(t1, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      LVni = retval_area[0];
      OFoneof_Dmake(5, LVni);
      if (OFc__env_Dget__type(LVe, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      LVnt = retval_area[0];
      OFoneof_Dmake(27, LVnt);
      LVxa = retval_area[0];
    }
  else
    {
      object LVni= 0;
      if (OFc__env_Dget__null__type(LVe) == SIG)
        {
	  goto except0;
        }
      if (OFtypespec_Dequal(LVt, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      if (retval_area[0])
        {
	  t5 = TRUE;
        }
      else
        {
	  if (OFc__env_Dget__bool__type(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (OFtypespec_Dequal(LVt, retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  t5 = retval_area[0];
        }
      if (t5)
        {
	  t4 = TRUE;
        }
      else
        {
	  if (OFc__env_Dget__int__type(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (OFtypespec_Dequal(LVt, retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  t4 = retval_area[0];
        }
      if (t4)
        {
	  t3 = TRUE;
        }
      else
        {
	  if (OFc__env_Dget__real__type(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (OFtypespec_Dequal(LVt, retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  t3 = retval_area[0];
        }
      if (t3)
        {
	  t2 = TRUE;
        }
      else
        {
	  if (OFc__env_Dget__char__type(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (OFtypespec_Dequal(LVt, retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  t2 = retval_area[0];
        }
      if (t2)
        {
	  t1 = TRUE;
        }
      else
        {
	  if (OFc__env_Dget__str__type(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (OFtypespec_Dequal(LVt, retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  t1 = retval_area[0];
        }
      if (OMbool_Dnot(t1))
        {
	  if (OFidn_Dget__str(LVi) == SIG)
	    {
	      goto except0;
	    }
	  t6 = OFsequence_D__alloc(3);
	  OMsequence_D__store(t6, 1, ((string) &str1));
	  OMsequence_D__store(t6, 2, retval_area[0]);
	  OMsequence_D__store(t6, 3, ((string) &str2));
	  if (OFc__env_Derr(LVe, t6) == SIG)
	    {
	      goto except0;
	    }
        }
      if (OFidn_Dget__str(LVi) == SIG)
        {
	  goto except0;
        }
      t1 = retval_area[0];
      OFoneof_Dmake(10, LVt);
      if (OFidn_Dcreate(t1, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      LVni = retval_area[0];
      OFoneof_Dmake(14, LVni);
      LVxa = retval_area[0];
    }
  if (OFexpr_Dcreate(LVxa, LVt) == SIG)
    {
      goto except0;
    }
  OFoneof_Dmake(1, retval_area[0]);
  t1 = LVt;
  t2 = retval_area[0];
  retval_area[0] = t1;
  retval_area[1] = t2;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__equateval */
/* clu_operation_name, c_equateval */
int AFc__equateval(LVe, LVval)
     object LVe;
     object LVval;
{
  int t1;
  /* begin body */
  t1 = ((oneof) LVval)->tag;
  if (t1 == 2)
    {
      object LVx= 0;
      LVx = ((oneof) LVval)->value;
        {
	  if (AFc__equate__expr(LVe, LVx) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else if (t1 == 3)
    {
      object LVset= 0;
      LVset = ((oneof) LVval)->value;
        {
	  if (AFc__xtypeset(LVe, LVset) == SIG)
	    {
	      goto except0;
	    }
	  OFoneof_Dmake(7, retval_area[0]);
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else if (t1 == 1)
    {
      object LVd= 0;
      LVd = ((oneof) LVval)->value;
        {
	  if (AFc__pathname(LVe, LVd) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
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

/* begin module */
/* c_function_name, AFc__equate__expr */
/* clu_operation_name, c_equate_expr */
int AFc__equate__expr(LVe, LVx)
     object LVe;
     object LVx;
{
  object LVnx= 0;
  int t1, t2;
  /* begin body */
  if (OFexpr_Dget__abs(LVx) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 14)
    {
      object LVxa= 0;
      LVxa = ((oneof) retval_area[0])->value;
        {
	  if (OFidn_Dget__kind(LVxa) == SIG)
	    {
	      goto except0;
	    }
	  t2 = ((oneof) retval_area[0])->tag;
	  if (t2 == 7)
	    {
	      object LVk= 0;
	      LVk = ((oneof) retval_area[0])->value;
	        {
		  OFoneof_Dmake(7, LVk);
		  retval_area[0] = retval_area[0];
		  return RET;
	        }
	    }
        }
    }
  if (AFc__expr(LVe, LVx) == SIG)
    {
      goto except0;
    }
  if (AFe__expr(LVe, LVx) == SIG)
    {
      goto except0;
    }
  LVnx = retval_area[0];
  if (OFexpr_Dget__abs(LVnx) == SIG)
    {
      goto except0;
    }
  if (OFexpr_Dset__abs(LVx, retval_area[0]) == SIG)
    {
      goto except0;
    }
  if (OFexpr_Dget__typespec(LVnx) == SIG)
    {
      goto except0;
    }
  if (OFexpr_Dset__typespec(LVx, retval_area[0]) == SIG)
    {
      goto except0;
    }
  OFoneof_Dmake(1, LVx);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__xtypeset */
/* clu_operation_name, c_xtypeset */
int AFc__xtypeset(LVe, LVset)
     object LVe;
     object LVset;
{
  object LVi= 0;
  object LVeqs= 0;
  object LVops= 0;
  object LVnops= 0;
  int t1, t2, t3, t4, t5, t6;
  /* begin body */
  LVi = OMrecord_Dget(2, LVset);
  LVeqs = OMrecord_Dget(1, LVset);
  LVops = OMrecord_Dget(3, LVset);
  if (OFc__env_Dchecking__specs(LVe) == SIG)
    {
      goto except0;
    }
  if (OMbool_Dnot(retval_area[0]))
    {
      object LVnt= 0;
      object LVx= 0;
      if (OFc__env_Dbegin__specs(LVe) == SIG)
        {
	  goto except0;
        }
      if (OFidn_Dget__str(LVi) == SIG)
        {
	  goto except0;
        }
      t1 = retval_area[0];
      OFsequence_Dnew();
      OFoneof_Dmake(5, retval_area[0]);
      if (OFidn_Dcreate(t1, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      LVi = retval_area[0];
      if (OFc__env_Dscopify(LVe, LVi) == SIG)
        {
	  goto except0;
        }
      OFoneof_Dmake(5, LVi);
      if (OFc__env_Dget__type(LVe, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      LVnt = retval_area[0];
      OFoneof_Dmake(27, LVnt);
      t1 = retval_area[0];
      if (OFc__env_Dget__type__type(LVe) == SIG)
        {
	  goto except0;
        }
      if (OFexpr_Dcreate(t1, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      LVx = retval_area[0];
      t1 = OMrecord_Dget(2, LVset);
      OFoneof_Dmake(1, LVx);
      if (OFc__env_Ddeclare(LVe, t1, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      OMrecord_Dset(2, LVset, LVi);
      if (OFc__env_Dequates(LVe, LVeqs) == SIG)
        {
	  goto except0;
        }
      if (AFc__operdecllist(LVe, LVops) == SIG)
        {
	  goto except0;
        }
      if (OFc__env_Dend__specs(LVe) == SIG)
        {
	  goto except0;
        }
    }
  if (OFc__env_Dbuilding__specs(LVe) == SIG)
    {
      goto except0;
    }
  if (OMbool_Dnot(retval_area[0]))
    {
      if (OFc__env_Dbegin__scope(LVe) == SIG)
        {
	  goto except0;
        }
      if (OFc__env_Dbegin__recheck(LVe, TRUE) == SIG)
        {
	  goto except0;
        }
      OFsequence_Dnew();
      OFoneof_Dmake(6, retval_area[0]);
      if (OFc__env_Ddeclare(LVe, LVi, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      if (AFc__add__opspecs(LVe, LVi, LVops) == SIG)
        {
	  goto except0;
        }
      if (AFc__operdecllist(LVe, LVops) == SIG)
        {
	  goto except0;
        }
      if (OFc__env_Dend__recheck(LVe, TRUE) == SIG)
        {
	  goto except0;
        }
      if (OFc__env_Dend__scope(LVe) == SIG)
        {
	  goto except0;
        }
    }
  OFsequence_Dnew();
  LVnops = retval_area[0];
    {
      object LVod= 0;
      for (t1 = LVops, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVod = OMsequence_Dfetch(t1, t2);
	    {
	        {
		  object LVop= 0;
		  for (t4 = OMrecord_Dget(2, LVod), t5 = 1, t6 = OMsequence_Dsize(t4);
		       t5 <= t6;
		       t5++)
		    {
		      LVop = OMsequence_Dfetch(t4, t5);
		        {
			  OFsequence_Daddh(LVnops, LVop);
			  LVnops = retval_area[0];
		        }
		    }
	        }
	    }
        }
    }
  t1 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t1, LVnops);
  OMrecord_Dset(2, t1, LVi);
  retval_area[0] = t1;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__pathname */
/* clu_operation_name, c_pathname */
int AFc__pathname(LVe, LVpath)
     object LVe;
     object LVpath;
{
  object LVgen= 0;
  /* begin body */
  if (OFxlib_Dlookup(LVpath) == SIG)
    {
      goto except1;
    }
  if (OFc__env_Dget__du(LVe, retval_area[0]) == SIG)
    {
      goto except1;
    }
  LVgen = retval_area[0];
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_FOUND))
        {
	  if (OFxlib_Dget__du(LVpath) == SIG)
	    {
	      goto except0;
	    }
	  if (OFc__env_Dget__du(LVe, retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  LVgen = retval_area[0];
	  if (AFc__get__idnkind(LVe, LVgen, 2) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
      else
        {
	  goto except0;
        }
    }
  if (AFc__get__idnkind(LVe, LVgen, 0) == SIG)
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

/* begin module */
/* c_function_name, AFc__get__idnkind */
/* clu_operation_name, c_get_idnkind */
int AFc__get__idnkind(LVe, LVgen, LVwant)
     object LVe;
     object LVgen;
     object LVwant;
{
  object LVk= 0;
  object LVclut= 0;
  object LVxa= 0;
  object LVt= 0;
  object LVspecs= 0;
  int t1;
  /* begin body */
  OFoneof_Dmake(2, LVgen);
  LVk = retval_area[0];
  OFsequence_Dnew();
  t1 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t1, LVgen);
  OMrecord_Dset(2, t1, retval_area[0]);
  LVclut = t1;
  if (AFc__get__duspecs(LVe, LVgen) == SIG)
    {
      goto except0;
    }
  LVspecs = retval_area[0];
  t1 = ((oneof) LVspecs)->tag;
  if (t1 == 1)
    {
      object LVinf= 0;
      LVinf = ((oneof) LVspecs)->value;
        {
	  if (OMbool_Dnot(OMsequence_Dempty(OMrecord_Dget(1, LVinf))))
	    {
	      retval_area[0] = LVk;
	      return RET;
	    }
	  OFoneof_Dmake(3, LVclut);
	  LVxa = retval_area[0];
	  LVt = OMrecord_Dget(2, LVinf);
        }
    }
  else if (t1 == 3)
    {
      object LVinf= 0;
      LVinf = ((oneof) LVspecs)->value;
        {
	  if (OMbool_Dnot(OMsequence_Dempty(OMrecord_Dget(2, LVinf))))
	    {
	      retval_area[0] = LVk;
	      return RET;
	    }
	  OFoneof_Dmake(3, LVclut);
	  if (OFc__env_Dget__type(LVe, retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  OFoneof_Dmake(27, retval_area[0]);
	  LVxa = retval_area[0];
	  if (OFc__env_Dget__type__type(LVe) == SIG)
	    {
	      goto except0;
	    }
	  LVt = retval_area[0];
        }
    }
  else if (t1 == 5 || t1 == 2)
    {
        {
	  retval_area[0] = LVk;
	  return RET;
        }
    }
  else
    {
      if (OMint_Dequal(LVwant, 0))
        {
	  retval_area[0] = LVk;
	  return RET;
        }
      else
        {
	  if (OMint_Dequal(LVwant, 2))
	    {
	      object LVot= 0;
	      OFoneof_Dmake(3, LVclut);
	      LVxa = retval_area[0];
	      OFoneof_Dmake(1, LVclut);
	      LVot = retval_area[0];
	      OFoneof_Dmake(6, LVot);
	      if (OFc__env_Dget__type(LVe, retval_area[0]) == SIG)
	        {
		  goto except0;
	        }
	      LVt = retval_area[0];
	    }
	  else
	    {
	      object LVta= 0;
	      OFoneof_Dmake(3, LVclut);
	      LVta = retval_area[0];
	      if (OFc__env_Dget__type(LVe, LVta) == SIG)
	        {
		  goto except0;
	        }
	      OFoneof_Dmake(27, retval_area[0]);
	      LVxa = retval_area[0];
	      if (OFc__env_Dget__type__type(LVe) == SIG)
	        {
		  goto except0;
	        }
	      LVt = retval_area[0];
	    }
        }
    }
  if (OFexpr_Dcreate(LVxa, LVt) == SIG)
    {
      goto except0;
    }
  OFoneof_Dmake(1, retval_area[0]);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__constlist */
/* clu_operation_name, c_constlist */
int AFc__constlist(LVe, LVexprs)
     object LVe;
     object LVexprs;
{
  int t1, t2;
  /* begin body */
  if (OFc__env_Dbegin__type__scope(LVe) == SIG)
    {
      goto except0;
    }
    {
      object LVi= 0;
      for (t1 = 1, t2 = OMsequence_Dsize(LVexprs); t1 <= t2; t1++)
        {
	  LVi = t1;
	    {
	      object LVox= 0;
	      object LVnx= 0;
	      if (OMsequence_Dbounds(LVexprs, LVi))
	        {
		  signame = SLBOUNDS;
		  goto except0;
	        }
	      LVox = OMsequence_Dfetch(LVexprs, LVi);
	      if (AFc__const(LVe, LVox) == SIG)
	        {
		  goto except0;
	        }
	      LVnx = retval_area[0];
	      if (OFexpr_Dequal(LVnx, LVox) == SIG)
	        {
		  goto except0;
	        }
	      if (OMbool_Dnot(retval_area[0]))
	        {
		  if (OFsequence_Dreplace(LVexprs, LVi, LVnx) == SIG)
		    {
		      goto except0;
		    }
		  LVexprs = retval_area[0];
	        }
	    }
        }
    }
  if (OFc__env_Dend__type__scope(LVe) == SIG)
    {
      goto except0;
    }
  retval_area[0] = LVexprs;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__const */
/* clu_operation_name, c_const */
int AFc__const(LVe, LVx)
     object LVe;
     object LVx;
{
  int t1;
  /* begin body */
  if (AFc__expr(LVe, LVx) == SIG)
    {
      goto except0;
    }
  if (OFexpr_Dget__abs(LVx) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 3)
    {
      object LVxa= 0;
      LVxa = ((oneof) retval_area[0])->value;
        {
	  if (OFexpr_Dget__typespec(LVx) == SIG)
	    {
	      goto except0;
	    }
	  if (OFtypespec_Dget__abs(retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  if (OMoneof_Dis(6, retval_area[0]))
	    {
	      object LVta= 0;
	      OFoneof_Dmake(3, LVxa);
	      LVta = retval_area[0];
	      if (OFc__env_Dget__type(LVe, LVta) == SIG)
	        {
		  goto except0;
	        }
	      OFoneof_Dmake(27, retval_area[0]);
	      if (OFexpr_Dset__abs(LVx, retval_area[0]) == SIG)
	        {
		  goto except0;
	        }
	      if (OFc__env_Dget__type__type(LVe) == SIG)
	        {
		  goto except0;
	        }
	      if (OFexpr_Dset__typespec(LVx, retval_area[0]) == SIG)
	        {
		  goto except0;
	        }
	    }
        }
    }
  if (AFe__expr(LVe, LVx) == SIG)
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

/* begin module */
/* c_function_name, AFc__type */
/* clu_operation_name, c_type */
int AFc__type(LVe, LVt)
     object LVe;
     object LVt;
{
  object LVabs= 0;
  object LVold= 0;
  int t1, t2, t3, t4;
  /* begin body */
  if (OFtypespec_Dget__id(LVt) == SIG)
    {
      goto except0;
    }
  if (OMbool_Dnot(OMint_Dequal(retval_area[0], 0)))
    {
      if (OFc__env_Dchecking__specs(LVe) == SIG)
        {
	  goto except0;
        }
      if (OMbool_Dnot(retval_area[0]))
        {
	  if (OFtypespec_Dget__abs(LVt) == SIG)
	    {
	      goto except0;
	    }
	  t1 = ((oneof) retval_area[0])->tag;
	  if (t1 == 4)
	    {
	        {
		  if (OFc__env_Derr1(LVe, ((string) &str3)) == SIG)
		    {
		      goto except0;
		    }
	        }
	    }
	  else if (t1 == 8)
	    {
	        {
		  if (OFc__env_Dtypes__illegal(LVe) == SIG)
		    {
		      goto except0;
		    }
		  if (retval_area[0])
		    {
		      if (OFc__env_Derr1(LVe, ((string) &str4)) == SIG)
		        {
			  goto except0;
		        }
		    }
	        }
	    }
        }
      else
        {
	  if (OFc__env_Drechecking__types(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (retval_area[0])
	    {
	      if (AFc__type1(LVe, LVt) == SIG)
	        {
		  goto except0;
	        }
	    }
        }
      retval_area[0] = LVt;
      return RET;
    }
  if (OFtypespec_Dget__abs(LVt) == SIG)
    {
      goto except0;
    }
  LVabs = retval_area[0];
  t1 = ((oneof) LVabs)->tag;
  if (t1 == 3)
    {
      object LVta= 0;
      LVta = ((oneof) LVabs)->value;
        {
	  if (AFc__constlist(LVe, OMrecord_Dget(2, LVta)) == SIG)
	    {
	      goto except0;
	    }
	  OMrecord_Dset(2, LVta, retval_area[0]);
        }
    }
  else if (t1 == 7)
    {
      object LVta= 0;
      LVta = ((oneof) LVabs)->value;
        {
	    {
	      object LVspec= 0;
	      for (t2 = OMrecord_Dget(2, LVta), t3 = 1, t4 = OMsequence_Dsize(t2);
	           t3 <= t4;
	           t3++)
	        {
		  LVspec = OMsequence_Dfetch(t2, t3);
		    {
		      if (AFc__type(LVe, OMrecord_Dget(2, LVspec)) == SIG)
		        {
			  goto except0;
		        }
		      OMrecord_Dset(2, LVspec, retval_area[0]);
		    }
	        }
	    }
        }
    }
  else if (t1 == 2)
    {
      object LVta= 0;
      LVta = ((oneof) LVabs)->value;
        {
	  if (AFc__typelist(LVe, OMrecord_Dget(1, LVta)) == SIG)
	    {
	      goto except0;
	    }
	  OMrecord_Dset(1, LVta, retval_area[0]);
	  if (AFc__typelist(LVe, OMrecord_Dget(4, LVta)) == SIG)
	    {
	      goto except0;
	    }
	  OMrecord_Dset(4, LVta, retval_area[0]);
	  if (AFc__exceptionlist(LVe, OMrecord_Dget(3, LVta)) == SIG)
	    {
	      goto except0;
	    }
        }
    }
  else if (t1 == 5)
    {
      object LVi= 0;
      LVi = ((oneof) LVabs)->value;
        {
	  if (AFc__idn__type(LVe, LVi) == SIG)
	    {
	      goto except0;
	    }
	  LVabs = retval_area[0];
        }
    }
  else if (t1 == 10)
    {
      object LVta= 0;
      LVta = ((oneof) LVabs)->value;
        {
	  if (OMbool_Dnot(OMsequence_Dempty(OMrecord_Dget(2, LVta))))
	    {
	      if (AFc__constlist(LVe, OMrecord_Dget(2, LVta)) == SIG)
	        {
		  goto except0;
	        }
	      OMrecord_Dset(2, LVta, retval_area[0]);
	      if (AFc__idn__gen(LVe, LVta) == SIG)
	        {
		  goto except0;
	        }
	      LVabs = retval_area[0];
	    }
	  else
	    {
	      if (AFc__idn__type(LVe, OMrecord_Dget(1, LVta)) == SIG)
	        {
		  goto except0;
	        }
	      LVabs = retval_area[0];
	    }
        }
    }
  else if (t1 == 11)
    {
      object LVta= 0;
      LVta = ((oneof) LVabs)->value;
        {
	    {
	      object LVspec= 0;
	      for (t2 = OMrecord_Dget(2, LVta), t3 = 1, t4 = OMsequence_Dsize(t2);
	           t3 <= t4;
	           t3++)
	        {
		  LVspec = OMsequence_Dfetch(t2, t3);
		    {
		      if (AFc__type(LVe, OMrecord_Dget(2, LVspec)) == SIG)
		        {
			  goto except0;
		        }
		      OMrecord_Dset(2, LVspec, retval_area[0]);
		    }
	        }
	    }
	  if (AFc__xsel__type(LVe, LVta) == SIG)
	    {
	      goto except0;
	    }
	  LVabs = retval_area[0];
        }
    }
  if (OFc__env_Dfix__type(LVe, LVabs) == SIG)
    {
      goto except0;
    }
  LVt = retval_area[0];
  LVold = retval_area[1];
  if (OMbool_Dnot(LVold))
    {
      t1 = TRUE;
    }
  else
    {
      if (OFc__env_Drechecking__types(LVe) == SIG)
        {
	  goto except0;
        }
      t1 = retval_area[0];
    }
  if (t1)
    {
      if (OFtypespec_Dget__abs(LVt) == SIG)
        {
	  goto except0;
        }
      t2 = ((oneof) retval_area[0])->tag;
      if (t2 == 3)
        {
	  object LVta= 0;
	  LVta = ((oneof) retval_area[0])->value;
	    {
	      if (AFc__gen__parms(LVe, LVta) == SIG)
	        {
		  goto except0;
	        }
	    }
        }
    }
  retval_area[0] = LVt;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__type1 */
/* clu_operation_name, c_type1 */
int AFc__type1(LVe, LVt)
     object LVe;
     object LVt;
{
  int t1, t2, t3, t4, t5, t6, t7;
  /* begin body */
  if (OFtypespec_Dget__abs(LVt) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 3)
    {
      object LVta= 0;
      LVta = ((oneof) retval_area[0])->value;
        {
	  if (OMbool_Dnot(OMsequence_Dempty(OMrecord_Dget(2, LVta))))
	    {
	        {
		  object LVx= 0;
		  for (t2 = OMrecord_Dget(2, LVta), t3 = 1, t4 = OMsequence_Dsize(t2);
		       t3 <= t4;
		       t3++)
		    {
		      LVx = OMsequence_Dfetch(t2, t3);
		        {
			  if (OFexpr_Dget__abs(LVx) == SIG)
			    {
			      goto except0;
			    }
			  t5 = ((oneof) retval_area[0])->tag;
			  if (t5 == 27)
			    {
			      object LVxa= 0;
			      LVxa = ((oneof) retval_area[0])->value;
			        {
				  if (AFc__type1(LVe, LVxa) == SIG)
				    {
				      goto except0;
				    }
			        }
			    }
		        }
		    }
	        }
	      if (AFc__gen__parms(LVe, LVta) == SIG)
	        {
		  goto except0;
	        }
	    }
        }
    }
  else if (t1 == 7)
    {
      object LVta= 0;
      LVta = ((oneof) retval_area[0])->value;
        {
	    {
	      object LVspec= 0;
	      for (t2 = OMrecord_Dget(2, LVta), t3 = 1, t4 = OMsequence_Dsize(t2);
	           t3 <= t4;
	           t3++)
	        {
		  LVspec = OMsequence_Dfetch(t2, t3);
		    {
		      if (AFc__type1(LVe, OMrecord_Dget(2, LVspec)) == SIG)
		        {
			  goto except0;
		        }
		    }
	        }
	    }
        }
    }
  else if (t1 == 2)
    {
      object LVta= 0;
      LVta = ((oneof) retval_area[0])->value;
        {
	    {
	      object LVtt= 0;
	      for (t2 = OMrecord_Dget(1, LVta), t3 = 1, t4 = OMsequence_Dsize(t2);
	           t3 <= t4;
	           t3++)
	        {
		  LVtt = OMsequence_Dfetch(t2, t3);
		    {
		      if (AFc__type1(LVe, LVtt) == SIG)
		        {
			  goto except0;
		        }
		    }
	        }
	    }
	    {
	      object LVtt= 0;
	      for (t2 = OMrecord_Dget(4, LVta), t3 = 1, t4 = OMsequence_Dsize(t2);
	           t3 <= t4;
	           t3++)
	        {
		  LVtt = OMsequence_Dfetch(t2, t3);
		    {
		      if (AFc__type1(LVe, LVtt) == SIG)
		        {
			  goto except0;
		        }
		    }
	        }
	    }
	    {
	      object LVsig= 0;
	      for (t2 = OMrecord_Dget(3, LVta), t3 = 1, t4 = OMsequence_Dsize(t2);
	           t3 <= t4;
	           t3++)
	        {
		  LVsig = OMsequence_Dfetch(t2, t3);
		    {
		        {
			  object LVtt= 0;
			  for (t5 = OMrecord_Dget(2, LVsig), t6 = 1, t7 = OMsequence_Dsize(t5);
			       t6 <= t7;
			       t6++)
			    {
			      LVtt = OMsequence_Dfetch(t5, t6);
			        {
				  if (AFc__type1(LVe, LVtt) == SIG)
				    {
				      goto except0;
				    }
			        }
			    }
		        }
		    }
	        }
	    }
        }
    }
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__typelist */
/* clu_operation_name, c_typelist */
int AFc__typelist(LVe, LVtypes)
     object LVe;
     object LVtypes;
{
  object LVntypes= 0;
  int t1, t2, t3;
  /* begin body */
  OFsequence_Dnew();
  LVntypes = retval_area[0];
    {
      object LVt= 0;
      for (t1 = LVtypes, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVt = OMsequence_Dfetch(t1, t2);
	    {
	      if (AFc__type(LVe, LVt) == SIG)
	        {
		  goto except0;
	        }
	      OFsequence_Daddh(LVntypes, retval_area[0]);
	      LVntypes = retval_area[0];
	    }
        }
    }
  retval_area[0] = LVntypes;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__exceptionlist */
/* clu_operation_name, c_exceptionlist */
int AFc__exceptionlist(LVe, LVsigs)
     object LVe;
     object LVsigs;
{
  int t1, t2, t3;
  /* begin body */
    {
      object LVsig= 0;
      for (t1 = LVsigs, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVsig = OMsequence_Dfetch(t1, t2);
	    {
	      if (AFc__typelist(LVe, OMrecord_Dget(2, LVsig)) == SIG)
	        {
		  goto except0;
	        }
	      OMrecord_Dset(2, LVsig, retval_area[0]);
	      if (OMstring_Dequal(OMrecord_Dget(1, LVsig), SLFAILURE))
	        {
		  if (OFc__env_Derr1(LVe, ((string) &str5)) == SIG)
		    {
		      goto except0;
		    }
	        }
	    }
        }
    }
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__idn__gen */
/* clu_operation_name, c_idn_gen */
int AFc__idn__gen(LVe, LVxt)
     object LVe;
     object LVxt;
{
  object LVi= 0;
  object LVparms= 0;
  int t1, t2;
  /* begin body */
  LVi = OMrecord_Dget(1, LVxt);
  LVparms = OMrecord_Dget(2, LVxt);
  if (OFidn_Dget__kind(LVi) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 2)
    {
      object LVk= 0;
      LVk = ((oneof) retval_area[0])->value;
        {
	  object LVdut= 0;
	  object LVt= 0;
	  t2 = OFrecord_D__alloc(2);
	  OMrecord_Dset(1, t2, LVk);
	  OMrecord_Dset(2, t2, LVparms);
	  LVdut = t2;
	  if (AFc__gen__parms(LVe, LVdut) == SIG)
	    {
	      goto except0;
	    }
	  LVt = retval_area[0];
	  if (OFtypespec_Dget__abs(LVt) == SIG)
	    {
	      goto except0;
	    }
	  t2 = ((oneof) retval_area[0])->tag;
	  if (t2 == 8 || t2 == 6)
	    {
	        {
		  OFoneof_Dmake(3, LVdut);
		  retval_area[0] = retval_area[0];
		  return RET;
	        }
	    }
	  else
	    {
	      if (OFtypespec_Dget__abs(LVt) == SIG)
	        {
		  goto except0;
	        }
	      retval_area[0] = retval_area[0];
	      return RET;
	    }
        }
    }
  else if (t1 == 8)
    {
        {
	  if (OFc__env_Dlookup(LVe, LVi, 0) == SIG)
	    {
	      goto except0;
	    }
	  if (AFc__idn__gen(LVe, LVxt) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  if (OFidn_Dget__str(LVi) == SIG)
    {
      goto except0;
    }
  t1 = OFsequence_D__alloc(3);
  OMsequence_D__store(t1, 1, ((string) &str6));
  OMsequence_D__store(t1, 2, retval_area[0]);
  OMsequence_D__store(t1, 3, ((string) &str7));
  if (OFc__env_Derr(LVe, t1) == SIG)
    {
      goto except0;
    }
  OFoneof_Dmake(9, NIL);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__idn__type */
/* clu_operation_name, c_idn_type */
int AFc__idn__type(LVe, LVi)
     object LVe;
     object LVi;
{
  int t1, t2;
  /* begin body */
  if (OFidn_Dget__kind(LVi) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 6 || t1 == 5)
    {
        {
	  OFoneof_Dmake(5, LVi);
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else if (t1 == 1)
    {
      object LVk= 0;
      LVk = ((oneof) retval_area[0])->value;
        {
	  if (OFexpr_Dget__abs(LVk) == SIG)
	    {
	      goto except0;
	    }
	  t2 = ((oneof) retval_area[0])->tag;
	  if (t2 == 27)
	    {
	      object LVxa= 0;
	      LVxa = ((oneof) retval_area[0])->value;
	        {
		  if (OFtypespec_Dget__abs(LVxa) == SIG)
		    {
		      goto except0;
		    }
		  retval_area[0] = retval_area[0];
		  return RET;
	        }
	    }
	  else if (t2 == 5)
	    {
	        {
		  OFoneof_Dmake(9, NIL);
		  retval_area[0] = retval_area[0];
		  return RET;
	        }
	    }
	  else if (t2 == 3)
	    {
	      object LVxa= 0;
	      LVxa = ((oneof) retval_area[0])->value;
	        {
		  if (OFexpr_Dget__typespec(LVk) == SIG)
		    {
		      goto except0;
		    }
		  if (OFtypespec_Dget__abs(retval_area[0]) == SIG)
		    {
		      goto except0;
		    }
		  if (OMoneof_Dis(6, retval_area[0]))
		    {
		      OFoneof_Dmake(3, LVxa);
		      retval_area[0] = retval_area[0];
		      return RET;
		    }
	        }
	    }
	  if (OFidn_Dget__str(LVi) == SIG)
	    {
	      goto except0;
	    }
	  t2 = OFsequence_D__alloc(3);
	  OMsequence_D__store(t2, 1, ((string) &str6));
	  OMsequence_D__store(t2, 2, retval_area[0]);
	  OMsequence_D__store(t2, 3, ((string) &str8));
	  if (OFc__env_Derr(LVe, t2) == SIG)
	    {
	      goto except0;
	    }
        }
    }
  else if (t1 == 9 || t1 == 4)
    {
      object LVk= 0;
      LVk = ((oneof) retval_area[0])->value;
        {
	  if (OFidn_Dget__str(LVi) == SIG)
	    {
	      goto except0;
	    }
	  t2 = OFsequence_D__alloc(3);
	  OMsequence_D__store(t2, 1, ((string) &str9));
	  OMsequence_D__store(t2, 2, retval_area[0]);
	  OMsequence_D__store(t2, 3, ((string) &str10));
	  if (OFc__env_Derr(LVe, t2) == SIG)
	    {
	      goto except0;
	    }
        }
    }
  else if (t1 == 2)
    {
        {
	  if (OFidn_Dget__str(LVi) == SIG)
	    {
	      goto except0;
	    }
	  t2 = OFsequence_D__alloc(3);
	  OMsequence_D__store(t2, 1, ((string) &str11));
	  OMsequence_D__store(t2, 2, retval_area[0]);
	  OMsequence_D__store(t2, 3, ((string) &str12));
	  if (OFc__env_Derr(LVe, t2) == SIG)
	    {
	      goto except0;
	    }
        }
    }
  else if (t1 == 8)
    {
        {
	  if (OFc__env_Dlookup(LVe, LVi, 1) == SIG)
	    {
	      goto except0;
	    }
	  if (AFc__idn__type(LVe, LVi) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else
    {
      if (OFidn_Dget__str(LVi) == SIG)
        {
	  goto except0;
        }
      t2 = OFsequence_D__alloc(3);
      OMsequence_D__store(t2, 1, ((string) &str6));
      OMsequence_D__store(t2, 2, retval_area[0]);
      OMsequence_D__store(t2, 3, ((string) &str8));
      if (OFc__env_Derr(LVe, t2) == SIG)
        {
	  goto except0;
        }
    }
  OFoneof_Dmake(9, NIL);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__xsel__type */
/* clu_operation_name, c_xsel_type */
int AFc__xsel__type(LVe, LVxsel)
     object LVe;
     object LVxsel;
{
  object LVi= 0;
  int t1, t2, t3;
  /* begin body */
  LVi = OMrecord_Dget(1, LVxsel);
  if (OFidn_Dget__kind(LVi) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 2)
    {
      object LVk= 0;
      LVk = ((oneof) retval_area[0])->value;
        {
	  object LVspecs= 0;
	  if (AFc__get__duspecs(LVe, LVk) == SIG)
	    {
	      goto except0;
	    }
	  LVspecs = retval_area[0];
	  t2 = ((oneof) LVspecs)->tag;
	  if (t2 == 5 || t2 == 4)
	    {
	        {
		  t3 = OFrecord_D__alloc(2);
		  OMrecord_Dset(1, t3, LVk);
		  OMrecord_Dset(2, t3, OMrecord_Dget(2, LVxsel));
		  OFoneof_Dmake(7, t3);
		  retval_area[0] = retval_area[0];
		  return RET;
	        }
	    }
        }
    }
  else if (t1 == 8)
    {
        {
	  if (OFc__env_Dlookup(LVe, LVi, 0) == SIG)
	    {
	      goto except0;
	    }
	  if (AFc__xsel__type(LVe, LVxsel) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  if (OFidn_Dget__str(LVi) == SIG)
    {
      goto except0;
    }
  t1 = OFsequence_D__alloc(3);
  OMsequence_D__store(t1, 1, ((string) &str6));
  OMsequence_D__store(t1, 2, retval_area[0]);
  OMsequence_D__store(t1, 3, ((string) &str13));
  if (OFc__env_Derr(LVe, t1) == SIG)
    {
      goto except0;
    }
  OFoneof_Dmake(9, NIL);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */