/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,c_typedefn,b_typeinfo,c_env,c_new_module,c_setup_opers,c_type_main,c_type_specs,du,fixup_new_module,idn*/
/* depend,c_setup_opers,c_env,c_member,idn*/
/* depend,c_member,idn*/
/* depend,c_type_specs,c_add_restricts,c_down_type,c_env,c_oper_specs,c_parameters,c_restrictlist,c_up_type,du*/
/* depend,c_type_main,c_env,c_initlist,c_oper_main,c_push_parms,c_restrictlist*/
/* depend,c_up_type,c_env,du,expr,idn,typespec*/
/* depend,c_down_type,c_env,cmpvar,equate,expr,typespec*/
/* depend,c_oper_specs,c_decllist1,c_env,c_exceptionlist1,c_oper_requires,c_parameters,c_restrictlist,c_typelist1,typespec*/
/* depend,c_oper_main,c_add_requires,c_apply_main1,c_env,c_rem_requires*/
/* depend,c_apply_main1,c_decllist1,c_env,c_exceptionlist1,c_initlist,c_push_parms,c_restrictlist,c_stmt,c_type,c_typelist1,stmt*/
/* depend,c_add_requires,c_env*/
/* depend,c_rem_requires,c_env*/
/* depend,c_decllist1,c_env,c_type,idn,typespec*/
/* depend,c_typelist1,c_env,c_type,typespec*/
/* depend,c_exceptionlist1,c_env,c_typelist1*/
/* depend,c_oper_requires,c_add_opspecs,c_env,c_member,c_new_requires,idn*/

#include <clu2c.h>

static STRING_REP(18) str1 = {18, {'r', 'e', 'd', 'e', 'c', 'l', 'a', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'o', 'f', ' ', '\''}};
static STRING_REP(1) str2 = {1, {'\''}};
static STRING_REP(1) str3 = {1, {'%'}};
static STRING_REP(11) str4 = {11, {'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', '\''}};
static STRING_REP(13) str5 = {13, {'\'', ' ', 'n', 'o', 't', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 'd'}};
static STRING_REP(25) str6 = {25, {'R', 'E', 'P', ' ', 'n', 'o', 't', ' ', 'e', 'q', 'u', 'a', 't', 'e', 'd', ' ', 't', 'o', ' ', 'a', ' ', 't', 'y', 'p', 'e'}};
static STRING_REP(13) str7 = {13, {'R', 'E', 'P', ' ', 'u', 'n', 'd', 'e', 'f', 'i', 'n', 'e', 'd'}};

/* begin module */
/* c_function_name, AFc__typedefn */
/* clu_operation_name, c_typedefn */
int AFc__typedefn(LVe, LVdef, LVkind)
     object LVe;
     object LVdef;
     object LVkind;
{
  object LVi= 0;
  object LVwant= 0;
  object LVmod= 0;
  object LVspecs= 0;
  object LVinfo= 0;
  object LVextsize= 0;
  object LVninfo= 0;
  object LVnspecs= 0;
  int t1, t2;
  /* begin body */
  if (OFc__env_Dset__line(LVe, OMrecord_Dget(10, LVdef)) == SIG)
    {
      goto except0;
    }
  LVi = OMrecord_Dget(5, LVdef);
  if (OMsequence_Dempty(OMrecord_Dget(8, LVdef)))
    {
      LVwant = 1;
    }
  else
    {
      LVwant = 0;
    }
  if (AFc__new__module(LVe, LVi, LVwant) == SIG)
    {
      goto except0;
    }
  LVmod = retval_area[0];
  LVspecs = retval_area[1];
  if (OFdu_Dget__unique(LVmod) == SIG)
    {
      goto except0;
    }
  t1 = retval_area[0];
  if (OFidn_Dget__str(LVi) == SIG)
    {
      goto except0;
    }
  if (OMbool_Dnot(OMstring_Dequal(t1, retval_area[0])))
    {
      if (OFdu_Dget__unique(LVmod) == SIG)
        {
	  goto except0;
        }
      t2 = retval_area[0];
      if (OFidn_Dget__kind(LVi) == SIG)
        {
	  goto except0;
        }
      if (OFidn_Dcreate(t2, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      LVi = retval_area[0];
      OMrecord_Dset(5, LVdef, LVi);
    }
  if (OFc__env_Dbegin__scope(LVe) == SIG)
    {
      goto except0;
    }
  if (AFc__setup__opers(LVe, LVdef) == SIG)
    {
      goto except0;
    }
  if (AFc__type__specs(LVe, LVdef, LVmod) == SIG)
    {
      goto except0;
    }
  LVinfo = retval_area[0];
  LVextsize = retval_area[1];
  if (AFb__typeinfo(LVe, LVinfo) == SIG)
    {
      goto except0;
    }
  LVninfo = retval_area[0];
  if (OMint_Dequal(LVkind, 0))
    {
      OFoneof_Dmake(3, LVninfo);
      LVnspecs = retval_area[0];
    }
  else
    {
      if (OMint_Dequal(LVkind, 1))
        {
	  OFoneof_Dmake(5, LVninfo);
	  LVnspecs = retval_area[0];
        }
      else
        {
	  OFoneof_Dmake(2, LVninfo);
	  LVnspecs = retval_area[0];
        }
    }
  if (AFfixup__new__module(LVe, LVi, LVmod, LVnspecs) == SIG)
    {
      goto except0;
    }
  if (AFc__type__main(LVe, LVdef, LVinfo) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dend__scope(LVe) == SIG)
    {
      goto except0;
    }
  if (OFsequence_Dsubseq(OMrecord_Dget(1, LVninfo), 1, LVextsize) == SIG)
    {
      goto except0;
    }
  OMrecord_Dset(1, LVninfo, retval_area[0]);
  if (OFc__env_Dget__unknown__type(LVe) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dset__up__type(LVe, retval_area[0]) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dget__unknown__type(LVe) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dset__down__type(LVe, retval_area[0]) == SIG)
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

/* begin module */
/* c_function_name, AFc__setup__opers */
/* clu_operation_name, c_setup_opers */
int AFc__setup__opers(LVe, LVdef)
     object LVe;
     object LVdef;
{
  object LVextops= 0;
  object LVuk= 0;
  int t1, t2, t3, t4, t5;
  /* begin body */
  LVextops = OMrecord_Dget(7, LVdef);
  OFoneof_Dmake(8, NIL);
  LVuk = retval_area[0];
    {
      object LVi= 0;
      for (t1 = LVextops, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVi = OMsequence_Dfetch(t1, t2);
	    {
	      if (OFc__env_Ddeclare(LVe, LVi, LVuk) == SIG)
	        {
		  goto except0;
	        }
	    }
        }
    }
    {
      object LVop= 0;
      for (t1 = OMrecord_Dget(1, LVdef), t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVop = OMsequence_Dfetch(t1, t2);
	    {
	      object LVi= 0;
	      object LVn= 0;
	      if (OFc__env_Dset__line(LVe, OMrecord_Dget(11, LVop)) == SIG)
	        {
		  goto except0;
	        }
	      LVi = OMrecord_Dget(6, LVop);
	      if (OFidn_Dget__str(LVi) == SIG)
	        {
		  goto except0;
	        }
	      LVn = retval_area[0];
	      if (AFc__member(LVi, LVextops) == SIG)
	        {
		  goto except0;
	        }
	      if (retval_area[0])
	        {
		  if (OFidn_Dget__kind(LVi) == SIG)
		    {
		      goto except0;
		    }
		  if (OMoneof_Dis(8, retval_area[0]))
		    {
		      OFoneof_Dmake(3, LVn);
		      if (OFidn_Dset__kind(LVi, retval_area[0]) == SIG)
		        {
			  goto except0;
		        }
		    }
		  else
		    {
		      if (OFidn_Dget__str(LVi) == SIG)
		        {
			  goto except0;
		        }
		      t4 = OFsequence_D__alloc(3);
		      OMsequence_D__store(t4, 1, ((string) &str1));
		      OMsequence_D__store(t4, 2, retval_area[0]);
		      OMsequence_D__store(t4, 3, ((string) &str2));
		      if (OFc__env_Derr(LVe, t4) == SIG)
		        {
			  goto except0;
		        }
		    }
	        }
	      else
	        {
		  t4 = OMstring_Dsize(((string) &str3))
		       + OMstring_Dsize(LVn);
		  t5 = OFstring_D__predict(t4);
		  OFstring_D__concat(t5, ((string) &str3));
		  OFstring_D__concat(t5, LVn);
		  LVn = t5;
		  OFoneof_Dmake(3, LVn);
		  if (OFc__env_Ddeclare(LVe, LVi, retval_area[0]) == SIG)
		    {
		      goto except0;
		    }
		  if (OFidn_Dcreate(LVn, LVuk) == SIG)
		    {
		      goto except0;
		    }
		  OMrecord_Dset(6, LVop, retval_area[0]);
	        }
	    }
        }
    }
  if (OFc__env_Dset__line(LVe, OMrecord_Dget(10, LVdef)) == SIG)
    {
      goto except0;
    }
    {
      object LVi= 0;
      for (t1 = LVextops, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVi = OMsequence_Dfetch(t1, t2);
	    {
	      if (OFidn_Dget__kind(LVi) == SIG)
	        {
		  goto except0;
	        }
	      if (OMoneof_Dis(8, retval_area[0]))
	        {
		  if (OFidn_Dget__str(LVi) == SIG)
		    {
		      goto except0;
		    }
		  t4 = OFsequence_D__alloc(3);
		  OMsequence_D__store(t4, 1, ((string) &str4));
		  OMsequence_D__store(t4, 2, retval_area[0]);
		  OMsequence_D__store(t4, 3, ((string) &str5));
		  if (OFc__env_Derr(LVe, t4) == SIG)
		    {
		      goto except0;
		    }
		  if (OFidn_Dget__str(LVi) == SIG)
		    {
		      goto except0;
		    }
		  OFoneof_Dmake(3, retval_area[0]);
		  if (OFidn_Dset__kind(LVi, retval_area[0]) == SIG)
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
/* c_function_name, AFc__member */
/* clu_operation_name, c_member */
int AFc__member(LVi, LVidns)
     object LVi;
     object LVidns;
{
  int t1, t2, t3;
  /* begin body */
    {
      object LVid= 0;
      for (t1 = LVidns, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVid = OMsequence_Dfetch(t1, t2);
	    {
	      if (OFidn_Dequal(LVi, LVid) == SIG)
	        {
		  goto except0;
	        }
	      if (retval_area[0])
	        {
		  retval_area[0] = TRUE;
		  return RET;
	        }
	    }
        }
    }
  retval_area[0] = FALSE;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__type__specs */
/* clu_operation_name, c_type_specs */
int AFc__type__specs(LVe, LVdef, LVmod)
     object LVe;
     object LVdef;
     object LVmod;
{
  object LVdparms= 0;
  object LVreqs= 0;
  object LVequates= 0;
  object LVopers= 0;
  object LVnparms= 0;
  object LVextinfo= 0;
  object LVintinfo= 0;
  int t1, t2, t3, t4;
  /* begin body */
  LVdparms = OMrecord_Dget(8, LVdef);
  LVreqs = OMrecord_Dget(12, LVdef);
  LVequates = OMrecord_Dget(4, LVdef);
  LVopers = OMrecord_Dget(1, LVdef);
  if (OFc__env_Dbegin__specs(LVe) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Deval__parms(LVe, LVdparms, LVequates) == SIG)
    {
      goto except0;
    }
  if (AFc__parameters(LVe, LVdparms) == SIG)
    {
      goto except0;
    }
  LVnparms = retval_area[0];
  if (AFc__up__type(LVe, LVmod, LVnparms) == SIG)
    {
      goto except0;
    }
  OMrecord_Dset(11, LVdef, retval_area[0]);
  if (OFc__env_Dset__up__type(LVe, OMrecord_Dget(11, LVdef)) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Deval__equates(LVe) == SIG)
    {
      goto except0;
    }
  if (AFc__down__type(LVe, LVequates) == SIG)
    {
      goto except0;
    }
  OMrecord_Dset(2, LVdef, retval_area[0]);
  if (OFc__env_Dset__down__type(LVe, OMrecord_Dget(2, LVdef)) == SIG)
    {
      goto except0;
    }
  if (AFc__restrictlist(LVe, LVreqs) == SIG)
    {
      goto except0;
    }
  if (AFc__add__restricts(LVe, LVreqs) == SIG)
    {
      goto except0;
    }
  OFsequence_Dnew();
  LVextinfo = retval_area[0];
  OFsequence_Dnew();
  LVintinfo = retval_area[0];
    {
      object LVop= 0;
      for (t1 = LVopers, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVop = OMsequence_Dfetch(t1, t2);
	    {
	      object LVinf= 0;
	      if (AFc__oper__specs(LVe, LVop) == SIG)
	        {
		  goto except0;
	        }
	      LVinf = retval_area[0];
	      t4 = OMrecord_Dget(2, LVinf);
	      if (OMstring_Dbounds(t4, 1))
	        {
		  signame = SLBOUNDS;
		  goto except0;
	        }
	      if (OMchar_Dequal(OMstring_Dfetch(t4, 1), '%'))
	        {
		  OFsequence_Daddh(LVintinfo, LVinf);
		  LVintinfo = retval_area[0];
	        }
	      else
	        {
		  OFsequence_Daddh(LVextinfo, LVinf);
		  LVextinfo = retval_area[0];
	        }
	    }
        }
    }
  if (OFc__env_Dend__specs(LVe) == SIG)
    {
      goto except0;
    }
  OFsequence_Dconcat(LVextinfo, LVintinfo);
  t1 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t1, retval_area[0]);
  OMrecord_Dset(2, t1, LVnparms);
  t2 = t1;
  t3 = t2;
  t4 = OMsequence_Dsize(LVextinfo);
  retval_area[0] = t3;
  retval_area[1] = t4;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__type__main */
/* clu_operation_name, c_type_main */
int AFc__type__main(LVe, LVdef, LVinfo)
     object LVe;
     object LVdef;
     object LVinfo;
{
  object LVopers= 0;
  int t1, t2, t3;
  /* begin body */
  if (OFc__env_Dset__line(LVe, OMrecord_Dget(10, LVdef)) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dbegin__scope(LVe) == SIG)
    {
      goto except0;
    }
  t1 = OMrecord_Dget(8, LVdef);
  if (AFc__push__parms(LVe, t1, OMrecord_Dget(2, LVinfo)) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dbegin__recheck(LVe, OMbool_Dnot(OMsequence_Dempty(OMrecord_Dget(2, LVinfo)))) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dequates(LVe, OMrecord_Dget(4, LVdef)) == SIG)
    {
      goto except0;
    }
  if (AFc__restrictlist(LVe, OMrecord_Dget(12, LVdef)) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dend__recheck(LVe, OMbool_Dnot(OMsequence_Dempty(OMrecord_Dget(2, LVinfo)))) == SIG)
    {
      goto except0;
    }
  if (AFc__initlist(LVe, OMrecord_Dget(6, LVdef)) == SIG)
    {
      goto except0;
    }
  LVopers = OMrecord_Dget(1, LVinfo);
    {
      object LVop= 0;
      for (t1 = OMrecord_Dget(1, LVdef), t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVop = OMsequence_Dfetch(t1, t2);
	    {
	      if (AFc__oper__main(LVe, LVop, LVopers) == SIG)
	        {
		  goto except0;
	        }
	    }
        }
    }
  if (OFc__env_Dend__scope(LVe) == SIG)
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

/* begin module */
/* c_function_name, AFc__up__type */
/* clu_operation_name, c_up_type */
int AFc__up__type(LVe, LVgen, LVparms)
     object LVe;
     object LVgen;
     object LVparms;
{
  object LVexprs= 0;
  object LVtt= 0;
  int t1, t2, t3, t4;
  /* begin body */
  OFsequence_Dnew();
  LVexprs = retval_area[0];
  if (OFc__env_Dget__type__type(LVe) == SIG)
    {
      goto except0;
    }
  LVtt = retval_area[0];
    {
      object LVi= 0;
      for (t1 = LVparms, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVi = OMsequence_Dfetch(t1, t2);
	    {
	      if (OFidn_Dget__kind(LVi) == SIG)
	        {
		  goto except0;
	        }
	      t4 = ((oneof) retval_area[0])->tag;
	      if (t4 == 6)
	        {
		    {
		      object LVta= 0;
		      object LVxa= 0;
		      OFoneof_Dmake(5, LVi);
		      LVta = retval_area[0];
		      if (OFc__env_Dget__type(LVe, LVta) == SIG)
		        {
			  goto except0;
		        }
		      OFoneof_Dmake(27, retval_area[0]);
		      LVxa = retval_area[0];
		      if (OFexpr_Dcreate(LVxa, LVtt) == SIG)
		        {
			  goto except0;
		        }
		      OFsequence_Daddh(LVexprs, retval_area[0]);
		      LVexprs = retval_area[0];
		    }
	        }
	      else if (t4 == 10)
	        {
		  object LVk= 0;
		  LVk = ((oneof) retval_area[0])->value;
		    {
		      OFoneof_Dmake(14, LVi);
		      if (OFexpr_Dcreate(retval_area[0], LVk) == SIG)
		        {
			  goto except0;
		        }
		      OFsequence_Daddh(LVexprs, retval_area[0]);
		      LVexprs = retval_area[0];
		    }
	        }
	    }
        }
    }
  t1 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t1, LVgen);
  OMrecord_Dset(2, t1, LVexprs);
  OFoneof_Dmake(3, t1);
  if (OFc__env_Dget__type(LVe, retval_area[0]) == SIG)
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
/* c_function_name, AFc__down__type */
/* clu_operation_name, c_down_type */
int AFc__down__type(LVe, LVeqs)
     object LVe;
     object LVeqs;
{
  int t1, t2, t3, t4, t5;
  /* begin body */
    {
      object LVeq= 0;
      for (t1 = LVeqs, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVeq = OMsequence_Dfetch(t1, t2);
	    {
	      if (OFequate_Dis__rep(LVeq) == SIG)
	        {
		  goto except0;
	        }
	      if (retval_area[0])
	        {
		  if (OFequate_Dget__line(LVeq) == SIG)
		    {
		      goto except0;
		    }
		  if (OFc__env_Dset__line(LVe, retval_area[0]) == SIG)
		    {
		      goto except0;
		    }
		  if (OFequate_Dget__idn(LVeq) == SIG)
		    {
		      goto except0;
		    }
		  if (OFidn_Dget__kind(retval_area[0]) == SIG)
		    {
		      goto except0;
		    }
		  t4 = ((oneof) retval_area[0])->tag;
		  if (t4 == 1)
		    {
		      object LVk= 0;
		      LVk = ((oneof) retval_area[0])->value;
		        {
			  if (OFexpr_Dget__abs(LVk) == SIG)
			    {
			      goto except0;
			    }
			  t5 = ((oneof) retval_area[0])->tag;
			  if (t5 == 27)
			    {
			      object LVxa= 0;
			      LVxa = ((oneof) retval_area[0])->value;
			        {
				  retval_area[0] = LVxa;
				  return RET;
			        }
			    }
			  else if (t5 == 3)
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
				      object LVta= 0;
				      object LVt= 0;
				      OFoneof_Dmake(3, LVxa);
				      LVta = retval_area[0];
				      if (OFc__env_Dget__type(LVe, LVta) == SIG)
				        {
					  goto except0;
				        }
				      LVt = retval_area[0];
				      OFoneof_Dmake(27, LVt);
				      if (OFexpr_Dset__abs(LVk, retval_area[0]) == SIG)
				        {
					  goto except0;
				        }
				      if (OFc__env_Dget__type__type(LVe) == SIG)
				        {
					  goto except0;
				        }
				      if (OFexpr_Dset__typespec(LVk, retval_area[0]) == SIG)
				        {
					  goto except0;
				        }
				      retval_area[0] = LVt;
				      return RET;
				    }
			        }
			    }
		        }
		    }
		  if (OFc__env_Derr1(LVe, ((string) &str6)) == SIG)
		    {
		      goto except0;
		    }
		  if (OFc__env_Dget__unknown__type(LVe) == SIG)
		    {
		      goto except0;
		    }
		  retval_area[0] = retval_area[0];
		  return RET;
	        }
	    }
        }
    }
  if (OFcmpvar_Dstuffs() == SIG)
    {
      goto except0;
    }
  if (OMbool_Dnot(OMint_Dequal(OMrecord_Dget(13, retval_area[0]), 4)))
    {
      if (OFc__env_Derr1(LVe, ((string) &str7)) == SIG)
        {
	  goto except0;
        }
    }
  if (OFc__env_Dget__unknown__type(LVe) == SIG)
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
/* c_function_name, AFc__oper__specs */
/* clu_operation_name, c_oper_specs */
int AFc__oper__specs(LVe, LVdef)
     object LVe;
     object LVdef;
{
  object LVdparms= 0;
  object LVreqs= 0;
  object LVnparms= 0;
  object LVargs= 0;
  object LVvals= 0;
  object LVivals= 0;
  object LVsigs= 0;
  object LVat= 0;
  object LVxreqs= 0;
  object LVt= 0;
  object LVn= 0;
  int t1, t2;
  /* begin body */
  if (OFc__env_Dset__line(LVe, OMrecord_Dget(11, LVdef)) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dset__varlist(LVe, OMrecord_Dget(14, LVdef)) == SIG)
    {
      goto except0;
    }
  LVdparms = OMrecord_Dget(8, LVdef);
  LVreqs = OMrecord_Dget(15, LVdef);
  if (OFc__env_Dbegin__scope(LVe) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Deval__parms(LVe, LVdparms, OMrecord_Dget(4, LVdef)) == SIG)
    {
      goto except0;
    }
  if (AFc__parameters(LVe, LVdparms) == SIG)
    {
      goto except0;
    }
  LVnparms = retval_area[0];
  if (OFc__env_Deval__equates(LVe) == SIG)
    {
      goto except0;
    }
  if (AFc__decllist1(LVe, OMrecord_Dget(1, LVdef)) == SIG)
    {
      goto except0;
    }
  LVargs = retval_area[0];
  if (AFc__typelist1(LVe, OMrecord_Dget(13, LVdef)) == SIG)
    {
      goto except0;
    }
  LVvals = retval_area[0];
  LVivals = retval_area[1];
  OMrecord_Dset(13, LVdef, LVivals);
  if (AFc__exceptionlist1(LVe, OMrecord_Dget(10, LVdef)) == SIG)
    {
      goto except0;
    }
  LVsigs = retval_area[0];
  if (AFc__restrictlist(LVe, LVreqs) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dend__scope(LVe) == SIG)
    {
      goto except0;
    }
  t1 = OFrecord_D__alloc(4);
  OMrecord_Dset(1, t1, LVargs);
  OMrecord_Dset(2, t1, OMrecord_Dget(5, LVdef));
  OMrecord_Dset(3, t1, LVsigs);
  OMrecord_Dset(4, t1, LVvals);
  LVat = t1;
  if (AFc__oper__requires(LVe, OMrecord_Dget(15, LVdef), LVnparms) == SIG)
    {
      goto except0;
    }
  LVxreqs = retval_area[0];
  OFoneof_Dmake(2, LVat);
  if (OFc__env_Dget__type(LVe, retval_area[0]) == SIG)
    {
      goto except0;
    }
  LVt = retval_area[0];
  OMrecord_Dset(12, LVdef, LVt);
  if (OFidn_Dget__str(OMrecord_Dget(6, LVdef)) == SIG)
    {
      goto except0;
    }
  LVn = retval_area[0];
  t1 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t1, LVnparms);
  OMrecord_Dset(2, t1, LVt);
  t2 = OFrecord_D__alloc(3);
  OMrecord_Dset(1, t2, t1);
  OMrecord_Dset(2, t2, LVn);
  OMrecord_Dset(3, t2, LVxreqs);
  retval_area[0] = t2;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__oper__main */
/* clu_operation_name, c_oper_main */
int AFc__oper__main(LVe, LVdef, LVinfos)
     object LVe;
     object LVdef;
     object LVinfos;
{
  object LVn= 0;
  int t1, t2, t3;
  /* begin body */
  if (OFidn_Dget__str(OMrecord_Dget(6, LVdef)) == SIG)
    {
      goto except0;
    }
  LVn = retval_area[0];
    {
      object LVinfo= 0;
      for (t1 = LVinfos, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVinfo = OMsequence_Dfetch(t1, t2);
	    {
	      if (OMstring_Dequal(LVn, OMrecord_Dget(2, LVinfo)))
	        {
		  object LVreqs= 0;
		  LVreqs = OMrecord_Dget(3, LVinfo);
		  if (AFc__add__requires(LVe, LVreqs) == SIG)
		    {
		      goto except0;
		    }
		  if (AFc__apply__main1(LVe, LVdef, OMrecord_Dget(1, OMrecord_Dget(1, LVinfo))) == SIG)
		    {
		      goto except0;
		    }
		  if (AFc__rem__requires(LVe, LVreqs) == SIG)
		    {
		      goto except0;
		    }
		  return RET;
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
/* c_function_name, AFc__apply__main1 */
/* clu_operation_name, c_apply_main1 */
int AFc__apply__main1(LVe, LVdef, LVnparms)
     object LVe;
     object LVdef;
     object LVnparms;
{
  object LVargs= 0;
  object LVvals= 0;
  object LVivals= 0;
  object LVsigs= 0;
  int t1, t2, t3;
  /* begin body */
  if (OFc__env_Dset__line(LVe, OMrecord_Dget(11, LVdef)) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dset__varlist(LVe, OMrecord_Dget(14, LVdef)) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dbegin__scope(LVe) == SIG)
    {
      goto except0;
    }
  if (AFc__push__parms(LVe, OMrecord_Dget(8, LVdef), LVnparms) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dbegin__recheck(LVe, OMbool_Dnot(OMsequence_Dempty(LVnparms))) == SIG)
    {
      goto except0;
    }
  if (AFc__decllist1(LVe, OMrecord_Dget(1, LVdef)) == SIG)
    {
      goto except0;
    }
  LVargs = retval_area[0];
  if (AFc__typelist1(LVe, OMrecord_Dget(13, LVdef)) == SIG)
    {
      goto except0;
    }
  LVvals = retval_area[0];
  LVivals = retval_area[1];
  OMrecord_Dset(13, LVdef, LVivals);
  if (AFc__exceptionlist1(LVe, OMrecord_Dget(10, LVdef)) == SIG)
    {
      goto except0;
    }
  LVsigs = retval_area[0];
  if (AFc__restrictlist(LVe, OMrecord_Dget(15, LVdef)) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dequates(LVe, OMrecord_Dget(4, LVdef)) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dset__line(LVe, OMrecord_Dget(11, LVdef)) == SIG)
    {
      goto except0;
    }
  if (AFc__type(LVe, OMrecord_Dget(12, LVdef)) == SIG)
    {
      goto except0;
    }
  OMrecord_Dset(12, LVdef, retval_area[0]);
  t1 = OFrecord_D__alloc(4);
  OMrecord_Dset(1, t1, LVargs);
  OMrecord_Dset(2, t1, OMrecord_Dget(5, LVdef));
  OMrecord_Dset(3, t1, LVsigs);
  OMrecord_Dset(4, t1, LVvals);
  if (OFc__env_Dnew__apply(LVe, t1) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dend__recheck(LVe, OMbool_Dnot(OMsequence_Dempty(LVnparms))) == SIG)
    {
      goto except0;
    }
  if (AFc__initlist(LVe, OMrecord_Dget(7, LVdef)) == SIG)
    {
      goto except0;
    }
  if (OFarray_Dtrim(OMrecord_Dget(14, LVdef), 1, 0) == SIG)
    {
      goto except0;
    }
    {
      object LVs= 0;
      for (t1 = OMrecord_Dget(2, LVdef), t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVs = OMsequence_Dfetch(t1, t2);
	    {
	      if (AFc__stmt(LVe, LVs) == SIG)
	        {
		  goto except0;
	        }
	    }
        }
    }
  if (OFc__env_Dend__scope(LVe) == SIG)
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

/* begin module */
/* c_function_name, AFc__add__requires */
/* clu_operation_name, c_add_requires */
int AFc__add__requires(LVe, LVreqs)
     object LVe;
     object LVreqs;
{
  int t1, t2, t3, t4, t5;
  /* begin body */
    {
      object LVreq= 0;
      for (t1 = LVreqs, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVreq = OMsequence_Dfetch(t1, t2);
	    {
	      if (OFidn_Dget__kind(OMrecord_Dget(2, LVreq)) == SIG)
	        {
		  goto except0;
	        }
	      t4 = ((oneof) retval_area[0])->tag;
	      if (t4 == 6)
	        {
		  object LVk= 0;
		  LVk = ((oneof) retval_area[0])->value;
		    {
		      t5 = OMrecord_Dget(2, LVreq);
		      OFsequence_Dconcat(LVk, OMrecord_Dget(1, LVreq));
		      OFoneof_Dmake(6, retval_area[0]);
		      if (OFidn_Dset__kind(t5, retval_area[0]) == SIG)
		        {
			  goto except0;
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
/* c_function_name, AFc__rem__requires */
/* clu_operation_name, c_rem_requires */
int AFc__rem__requires(LVe, LVreqs)
     object LVe;
     object LVreqs;
{
  int t1, t2, t3, t4, t5;
  /* begin body */
    {
      object LVreq= 0;
      for (t1 = LVreqs, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVreq = OMsequence_Dfetch(t1, t2);
	    {
	      if (OFidn_Dget__kind(OMrecord_Dget(2, LVreq)) == SIG)
	        {
		  goto except0;
	        }
	      t4 = ((oneof) retval_area[0])->tag;
	      if (t4 == 6)
	        {
		  object LVk= 0;
		  LVk = ((oneof) retval_area[0])->value;
		    {
		      t5 = OMsequence_Dsize(LVk);
		      if (OFsequence_Dsubseq(LVk, 1, OMint_Dsub(t5, OMsequence_Dsize(OMrecord_Dget(1, LVreq)))) == SIG)
		        {
			  goto except0;
		        }
		      LVk = retval_area[0];
		      t5 = OMrecord_Dget(2, LVreq);
		      OFoneof_Dmake(6, LVk);
		      if (OFidn_Dset__kind(t5, retval_area[0]) == SIG)
		        {
			  goto except0;
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
/* c_function_name, AFc__decllist1 */
/* clu_operation_name, c_decllist1 */
int AFc__decllist1(LVe, LVdecls)
     object LVe;
     object LVdecls;
{
  object LVtypes= 0;
  object LVcvt__= 0;
  object LVdown__= 0;
  object LVnt= 0;
  int t1, t2, t3, t4, t5, t6;
  /* begin body */
  OFsequence_Dnew();
  LVtypes = retval_area[0];
  if (OFc__env_Dget__cvt__type(LVe) == SIG)
    {
      goto except0;
    }
  LVcvt__ = retval_area[0];
  if (OFc__env_Dget__down__type(LVe) == SIG)
    {
      goto except0;
    }
  LVdown__ = retval_area[0];
  if (OFc__env_Dbuilding__specs(LVe) == SIG)
    {
      goto except0;
    }
  if (retval_area[0])
    {
      if (OFc__env_Dget__up__type(LVe) == SIG)
        {
	  goto except0;
        }
      LVnt = retval_area[0];
    }
  else
    {
      LVnt = LVcvt__;
    }
    {
      object LVd= 0;
      for (t1 = LVdecls, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVd = OMsequence_Dfetch(t1, t2);
	    {
	      object LVdt= 0;
	      object LVat= 0;
	      LVdt = OMrecord_Dget(2, LVd);
	      if (OFtypespec_Dequal(LVdt, LVcvt__) == SIG)
	        {
		  goto except0;
	        }
	      if (retval_area[0])
	        {
		  LVdt = LVdown__;
		  LVat = LVnt;
	        }
	      else
	        {
		  if (AFc__type(LVe, LVdt) == SIG)
		    {
		      goto except0;
		    }
		  LVdt = retval_area[0];
		  OMrecord_Dset(2, LVd, LVdt);
		  LVat = LVdt;
	        }
	        {
		  object LVi= 0;
		  for (t4 = OMrecord_Dget(1, LVd), t5 = 1, t6 = OMsequence_Dsize(t4);
		       t5 <= t6;
		       t5++)
		    {
		      LVi = OMsequence_Dfetch(t4, t5);
		        {
			  if (OFc__env_Dadd__var(LVe, LVi, LVdt) == SIG)
			    {
			      goto except0;
			    }
			  OFsequence_Daddh(LVtypes, LVat);
			  LVtypes = retval_area[0];
		        }
		    }
	        }
	    }
        }
    }
  retval_area[0] = LVtypes;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__typelist1 */
/* clu_operation_name, c_typelist1 */
int AFc__typelist1(LVe, LVtypes)
     object LVe;
     object LVtypes;
{
  object LVcvt__= 0;
  object LVnt= 0;
  object LVxtypes= 0;
  object LVitypes= 0;
  int t1, t2;
  /* begin body */
  if (OFc__env_Dget__cvt__type(LVe) == SIG)
    {
      goto except0;
    }
  LVcvt__ = retval_area[0];
  if (OFc__env_Dbuilding__specs(LVe) == SIG)
    {
      goto except0;
    }
  if (retval_area[0])
    {
      if (OFc__env_Dget__up__type(LVe) == SIG)
        {
	  goto except0;
        }
      LVnt = retval_area[0];
    }
  else
    {
      LVnt = LVcvt__;
    }
  OFsequence_Dnew();
  LVxtypes = retval_area[0];
  OFsequence_Dnew();
  LVitypes = retval_area[0];
    {
      object LVi= 0;
      for (t1 = 1, t2 = OMsequence_Dsize(LVtypes); t1 <= t2; t1++)
        {
	  LVi = t1;
	    {
	      object LVt= 0;
	      object LVxt= 0;
	      if (OMsequence_Dbounds(LVtypes, LVi))
	        {
		  signame = SLBOUNDS;
		  goto except0;
	        }
	      LVt = OMsequence_Dfetch(LVtypes, LVi);
	      if (OFtypespec_Dequal(LVt, LVcvt__) == SIG)
	        {
		  goto except0;
	        }
	      if (retval_area[0])
	        {
		  LVxt = LVnt;
	        }
	      else
	        {
		  if (AFc__type(LVe, LVt) == SIG)
		    {
		      goto except0;
		    }
		  LVt = retval_area[0];
		  LVxt = LVt;
	        }
	      OFsequence_Daddh(LVxtypes, LVxt);
	      LVxtypes = retval_area[0];
	      OFsequence_Daddh(LVitypes, LVt);
	      LVitypes = retval_area[0];
	    }
        }
    }
  t1 = LVxtypes;
  t2 = LVitypes;
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
/* c_function_name, AFc__exceptionlist1 */
/* clu_operation_name, c_exceptionlist1 */
int AFc__exceptionlist1(LVe, LVsigs)
     object LVe;
     object LVsigs;
{
  object LVnsigs= 0;
  int t1, t2, t3, t4;
  /* begin body */
  OFsequence_Dnew();
  LVnsigs = retval_area[0];
    {
      object LVsig= 0;
      for (t1 = LVsigs, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVsig = OMsequence_Dfetch(t1, t2);
	    {
	      object LVtypes= 0;
	      object LVitypes= 0;
	      if (AFc__typelist1(LVe, OMrecord_Dget(2, LVsig)) == SIG)
	        {
		  goto except0;
	        }
	      LVtypes = retval_area[0];
	      LVitypes = retval_area[1];
	      OMrecord_Dset(2, LVsig, LVitypes);
	      t4 = OFrecord_D__alloc(2);
	      OMrecord_Dset(1, t4, OMrecord_Dget(1, LVsig));
	      OMrecord_Dset(2, t4, LVtypes);
	      OFsequence_Daddh(LVnsigs, t4);
	      LVnsigs = retval_area[0];
	    }
        }
    }
  retval_area[0] = LVnsigs;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__oper__requires */
/* clu_operation_name, c_oper_requires */
int AFc__oper__requires(LVe, LVreqs, LVparms)
     object LVe;
     object LVreqs;
     object LVparms;
{
  object LVxreqs= 0;
  int t1, t2, t3, t4, t5, t6;
  /* begin body */
  OFsequence_Dnew();
  LVxreqs = retval_area[0];
    {
      object LVreq= 0;
      for (t1 = LVreqs, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVreq = OMsequence_Dfetch(t1, t2);
	    {
	      object LVi= 0;
	      LVi = OMrecord_Dget(1, LVreq);
	      t4 = OMrecord_Dget(2, LVreq);
	      t5 = ((oneof) t4)->tag;
	      if (t5 == 1)
	        {
		  object LVrk= 0;
		  LVrk = ((oneof) t4)->value;
		    {
		      if (AFc__member(LVi, LVparms) == SIG)
		        {
			  goto except0;
		        }
		      if (retval_area[0])
		        {
			  if (AFc__add__opspecs(LVe, LVi, LVrk) == SIG)
			    {
			      goto except0;
			    }
		        }
		      else
		        {
			  object LVopers= 0;
			  OFsequence_Dnew();
			  if (AFc__new__requires(retval_area[0], LVrk) == SIG)
			    {
			      goto except0;
			    }
			  LVopers = retval_area[0];
			  t6 = OFrecord_D__alloc(2);
			  OMrecord_Dset(1, t6, LVopers);
			  OMrecord_Dset(2, t6, LVi);
			  OFsequence_Daddh(LVxreqs, t6);
			  LVxreqs = retval_area[0];
		        }
		    }
	        }
	    }
        }
    }
  retval_area[0] = LVxreqs;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */