/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,c_cluster_op,c_2_parms,c_env,c_get_duspecs,get_clusterop_print,subst_2_parms,typespec*/
/* depend,c_select_op,c_env,c_get_duspecs,c_parms,c_sel_type,c_select_requires,du,expr,get_clusterop_print,subst_2_parms,typespec*/
/* depend,c_sel_type,c_env,typespec*/
/* depend,c_idn_op,c_env,get_clusterop_print,idn,typespec*/
/* built-in param,sequence$similar,PV1_INc__idn__op,c_idn_op,expr*/
/* depend,c_apply_op,c_env,c_get_duspecs,c_parms,expr,get_clusterop_print,subst_2_parms,typespec*/
/* depend,c_requires,c_env,c_restrictions,idn*/
/* depend,c_select_requires,c_env,c_restrictions,expr*/
/* depend,subst_parms,b_type,c_env,typespec*/
/* depend,subst_2_parms,b_type,c_env,typespec*/
/* depend,c_restrictions,c_clusterop,c_env,expr,get_clusterop_print,subst_parms,typespec*/

#include <clu2c.h>

extern object	PV1_INc__idn__op;

static STRING_REP(19) str1 = {19, {'b', 'a', 'd', ' ', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', 's', ' ', 't', 'o', ' ', '\''}};
static STRING_REP(1) str2 = {1, {'\''}};
static STRING_REP(16) str3 = {16, {'\'', ' ', 'd', 'o', 'e', 's', ' ', 'n', 'o', 't', ' ', 'e', 'x', 'i', 's', 't'}};
static STRING_REP(3) str4 = {3, {'s', '2', 'r'}};
static STRING_REP(3) str5 = {3, {'r', '2', 's'}};
static STRING_REP(3) str6 = {3, {'o', '2', 'v'}};
static STRING_REP(3) str7 = {3, {'v', '2', 'o'}};
static STRING_REP(6) str8 = {6, {'c', 'r', 'e', 'a', 't', 'e'}};
static STRING_REP(8) str9 = {8, {'r', '_', 'g', 'e', 't', 's', '_', 's'}};
static STRING_REP(8) str10 = {8, {'v', '_', 'g', 'e', 't', 's', '_', 'o'}};
static STRING_REP(22) str11 = {22, {'\'', ' ', 'n', 'o', 't', ' ', 'a', ' ', 'l', 'e', 'g', 'a', 'l', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r'}};
static STRING_REP(8) str12 = {8, {'t', 'y', 'p', 'e', '_', 'o', 'f', '('}};
static STRING_REP(28) str13 = {28, {')', ' ', 'd', 'o', 'e', 's', ' ', 'n', 'o', 't', ' ', 'm', 'a', 't', 'c', 'h', ' ', 'r', 'e', 's', 't', 'r', 'i', 'c', 't', 'i', 'o', 'n'}};

/* begin module */
/* c_function_name, AFc__cluster__op */
/* clu_operation_name, c_cluster_op */
int AFc__cluster__op(LVe, LVdut, LVcop)
     object LVe;
     object LVdut;
     object LVcop;
{
  object LVinfo= 0;
  object LVspecs= 0;
  object LVn= 0;
  object LVparms= 0;
  object LVtparms= 0;
  int t1, t2, t3, t4;
  /* begin body */
  if (AFc__get__duspecs(LVe, OMrecord_Dget(1, LVdut)) == SIG)
    {
      goto except0;
    }
  LVspecs = retval_area[0];
  t1 = ((oneof) LVspecs)->tag;
  if (t1 == 3)
    {
      object LVinf= 0;
      LVinf = ((oneof) LVspecs)->value;
        {
	  LVinfo = LVinf;
        }
    }
  else if (t1 == 4)
    {
        {
	  OFoneof_Dmake(2, LVcop);
	  OFoneof_Dmake(6, retval_area[0]);
	  if (OFc__env_Dget__type(LVe, retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else
    {
      if (OFc__env_Dget__unknown__type(LVe) == SIG)
        {
	  goto except0;
        }
      retval_area[0] = retval_area[0];
      return RET;
    }
  LVn = OMrecord_Dget(1, LVcop);
  LVparms = OMrecord_Dget(2, LVdut);
  LVtparms = OMrecord_Dget(2, LVinfo);
    {
      object LVop= 0;
      for (t1 = OMrecord_Dget(1, LVinfo), t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVop = OMsequence_Dfetch(t1, t2);
	    {
	      if (OMstring_Dequal(LVn, OMrecord_Dget(2, LVop)))
	        {
		  object LVpparms= 0;
		  object LVainfo= 0;
		  LVpparms = OMrecord_Dget(2, LVcop);
		  LVainfo = OMrecord_Dget(1, LVop);
		  t4 = OMrecord_Dget(1, LVainfo);
		  if (AFc__2__parms(LVe, LVpparms, t4, LVparms, LVtparms, OMrecord_Dget(3, LVop)) == SIG)
		    {
		      goto except0;
		    }
		  if (retval_area[0])
		    {
		      if (AFsubst__2__parms(LVe, LVparms, LVtparms, LVpparms, LVainfo) == SIG)
		        {
			  goto except0;
		        }
		      retval_area[0] = retval_area[0];
		      return RET;
		    }
		  if (AFget__clusterop__print(LVcop) == SIG)
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
  if (AFget__clusterop__print(LVcop) == SIG)
    {
      goto except0;
    }
  t1 = OFsequence_D__alloc(3);
  OMsequence_D__store(t1, 1, ((string) &str2));
  OMsequence_D__store(t1, 2, retval_area[0]);
  OMsequence_D__store(t1, 3, ((string) &str3));
  if (OFc__env_Derr(LVe, t1) == SIG)
    {
      goto except0;
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
/* c_function_name, AFc__select__op */
/* clu_operation_name, c_select_op */
int AFc__select__op(LVe, LVdut, LVcop)
     object LVe;
     object LVdut;
     object LVcop;
{
  object LVinfo= 0;
  object LVspecs= 0;
  object LVn= 0;
  object LVfparms= 0;
  object LVx= 0;
  object LVgen= 0;
  int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
  int t11, t12, t13, t14, t15, t16, t17, t18, t19;
  /* begin body */
  if (AFc__get__duspecs(LVe, OMrecord_Dget(1, LVdut)) == SIG)
    {
      goto except0;
    }
  LVspecs = retval_area[0];
  t1 = ((oneof) LVspecs)->tag;
  if (t1 == 5)
    {
      object LVinf= 0;
      LVinf = ((oneof) LVspecs)->value;
        {
	  LVinfo = LVinf;
        }
    }
  else if (t1 == 4)
    {
        {
	  OFoneof_Dmake(2, LVcop);
	  OFoneof_Dmake(6, retval_area[0]);
	  if (OFc__env_Dget__type(LVe, retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else
    {
      if (OFc__env_Dget__unknown__type(LVe) == SIG)
        {
	  goto except0;
        }
      retval_area[0] = retval_area[0];
      return RET;
    }
  LVn = OMrecord_Dget(1, LVcop);
  LVfparms = OMrecord_Dget(2, LVdut);
  OFoneof_Dmake(27, OMrecord_Dget(3, LVcop));
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
    {
      object LVop= 0;
      for (t1 = OMrecord_Dget(1, LVinfo), t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVop = OMsequence_Dfetch(t1, t2);
	    {
	      object LVopn= 0;
	      LVopn = OMrecord_Dget(2, LVop);
	      if (OMstring_Dequal(LVn, LVopn))
	        {
		  t4 = TRUE;
	        }
	      else
	        {
		  t5 = FALSE;
		  OFstring_Dindexs(LVopn, LVn);
		  if (OMint_Dequal(retval_area[0], 1))
		    {
		      if (OMint_Dequal(OMsequence_Dsize(OMrecord_Dget(1, OMrecord_Dget(1, LVop))), 1))
		        {
			  t5 = TRUE;
		        }
		    }
		  t4 = t5;
	        }
	      if (t4)
	        {
		  object LVainfo= 0;
		  object LVpparms= 0;
		  if (AFc__select__requires(LVe, LVfparms, OMrecord_Dget(3, LVop)) == SIG)
		    {
		      goto except0;
		    }
		  LVainfo = OMrecord_Dget(1, LVop);
		  if (OMstring_Dequal(LVn, LVopn))
		    {
		      LVpparms = OMrecord_Dget(2, LVcop);
		    }
		  else
		    {
		      object LVsel= 0;
		      object LVt= 0;
		      object LVx1= 0;
		      if (OFstring_Drest(LVn, OMint_Dadd(OMstring_Dsize(LVopn), 1)) == SIG)
		        {
			  goto except0;
		        }
		      LVsel = retval_area[0];
		      if (AFc__sel__type(LVe, LVsel, LVfparms) == SIG)
		        {
			  goto except0;
		        }
		      LVt = retval_area[0];
		      OFoneof_Dmake(27, LVt);
		      t6 = retval_area[0];
		      if (OFc__env_Dget__type__type(LVe) == SIG)
		        {
			  goto except0;
		        }
		      if (OFexpr_Dcreate(t6, retval_area[0]) == SIG)
		        {
			  goto except0;
		        }
		      LVx1 = retval_area[0];
		      OFsequence_De2s(LVx1);
		      LVpparms = retval_area[0];
		    }
		  if (AFc__parms(LVe, LVpparms, OMrecord_Dget(1, LVainfo)) == SIG)
		    {
		      goto except0;
		    }
		  if (retval_area[0])
		    {
		      OFsequence_De2s(LVx);
		      t6 = retval_area[0];
		      t7 = OMrecord_Dget(2, LVinfo);
		      if (OMsequence_Dempty(t7))
		        {
			  signame = SLBOUNDS;
			  goto except0;
		        }
		      OFsequence_De2s(OMsequence_Dbottom(t7));
		      if (AFsubst__2__parms(LVe, t6, retval_area[0], LVpparms, LVainfo) == SIG)
		        {
			  goto except0;
		        }
		      retval_area[0] = retval_area[0];
		      return RET;
		    }
		  if (AFget__clusterop__print(LVcop) == SIG)
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
  LVgen = OMrecord_Dget(1, LVdut);
  t5 = FALSE;
  if (OFc__env_Dget__struct__(LVe) == SIG)
    {
      goto except0;
    }
  if (OFdu_Dequal(LVgen, retval_area[0]) == SIG)
    {
      goto except0;
    }
  if (retval_area[0])
    {
      if (OMstring_Dequal(LVn, ((string) &str4)))
        {
	  t6 = TRUE;
        }
      else
        {
	  t6 = OMstring_Dequal(LVn, ((string) &str5));
        }
      if (t6)
        {
	  t5 = TRUE;
        }
    }
  if (t5)
    {
      t4 = TRUE;
    }
  else
    {
      t7 = FALSE;
      if (OFc__env_Dget__oneof__(LVe) == SIG)
        {
	  goto except0;
        }
      if (OFdu_Dequal(LVgen, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      if (retval_area[0])
        {
	  if (OMstring_Dequal(LVn, ((string) &str6)))
	    {
	      t8 = TRUE;
	    }
	  else
	    {
	      t8 = OMstring_Dequal(LVn, ((string) &str7));
	    }
	  if (t8)
	    {
	      t7 = TRUE;
	    }
        }
      t4 = t7;
    }
  if (t4)
    {
      t3 = TRUE;
    }
  else
    {
      t9 = FALSE;
      if (OFc__env_Dget__record__(LVe) == SIG)
        {
	  goto except0;
        }
      if (OFdu_Dequal(LVgen, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      if (retval_area[0])
        {
	  if (OMstring_Dequal(LVn, ((string) &str8)))
	    {
	      t10 = TRUE;
	    }
	  else
	    {
	      t10 = OMstring_Dequal(LVn, ((string) &str9));
	    }
	  if (t10)
	    {
	      t9 = TRUE;
	    }
        }
      t3 = t9;
    }
  if (t3)
    {
      t2 = TRUE;
    }
  else
    {
      t11 = FALSE;
      if (OFc__env_Dget__variant__(LVe) == SIG)
        {
	  goto except0;
        }
      if (OFdu_Dequal(LVgen, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      if (retval_area[0])
        {
	  if (OMstring_Dequal(LVn, ((string) &str10)))
	    {
	      t11 = TRUE;
	    }
        }
      t2 = t11;
    }
  if (t2)
    {
      t1 = TRUE;
    }
  else
    {
      t12 = FALSE;
      if (OMstring_Dequal(LVn, ((string) &str8)))
        {
	  if (OFc__env_Dget__struct__(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (OFdu_Dequal(LVgen, retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  if (retval_area[0])
	    {
	      t15 = TRUE;
	    }
	  else
	    {
	      if (OFc__env_Dget__oneof__(LVe) == SIG)
	        {
		  goto except0;
	        }
	      if (OFdu_Dequal(LVgen, retval_area[0]) == SIG)
	        {
		  goto except0;
	        }
	      t15 = retval_area[0];
	    }
	  if (t15)
	    {
	      t14 = TRUE;
	    }
	  else
	    {
	      if (OFc__env_Dget__record__(LVe) == SIG)
	        {
		  goto except0;
	        }
	      if (OFdu_Dequal(LVgen, retval_area[0]) == SIG)
	        {
		  goto except0;
	        }
	      t14 = retval_area[0];
	    }
	  if (t14)
	    {
	      t13 = TRUE;
	    }
	  else
	    {
	      if (OFc__env_Dget__variant__(LVe) == SIG)
	        {
		  goto except0;
	        }
	      if (OFdu_Dequal(LVgen, retval_area[0]) == SIG)
	        {
		  goto except0;
	        }
	      t13 = retval_area[0];
	    }
	  if (OMbool_Dnot(t13))
	    {
	      t12 = TRUE;
	    }
        }
      t1 = t12;
    }
  if (t1)
    {
      object LVt1= 0;
      object LVdut1= 0;
      object LVt2= 0;
      object LVargs= 0;
      object LVvals= 0;
      object LVapt= 0;
      OFoneof_Dmake(7, LVdut);
      if (OFc__env_Dget__type(LVe, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      LVt1 = retval_area[0];
      if (OFc__env_Dget__struct__(LVe) == SIG)
        {
	  goto except0;
        }
      if (OFdu_Dequal(LVgen, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      if (retval_area[0])
        {
	  if (OFc__env_Dget__record__(LVe) == SIG)
	    {
	      goto except0;
	    }
	  LVgen = retval_area[0];
        }
      else
        {
	  if (OFc__env_Dget__oneof__(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (OFdu_Dequal(LVgen, retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  if (retval_area[0])
	    {
	      if (OFc__env_Dget__variant__(LVe) == SIG)
	        {
		  goto except0;
	        }
	      LVgen = retval_area[0];
	    }
	  else
	    {
	      if (OFc__env_Dget__variant__(LVe) == SIG)
	        {
		  goto except0;
	        }
	      if (OFdu_Dequal(LVgen, retval_area[0]) == SIG)
	        {
		  goto except0;
	        }
	      if (retval_area[0])
	        {
		  if (OFc__env_Dget__oneof__(LVe) == SIG)
		    {
		      goto except0;
		    }
		  LVgen = retval_area[0];
	        }
	      else
	        {
		  if (OFc__env_Dget__struct__(LVe) == SIG)
		    {
		      goto except0;
		    }
		  LVgen = retval_area[0];
	        }
	    }
        }
      t16 = OFrecord_D__alloc(2);
      OMrecord_Dset(1, t16, LVgen);
      OMrecord_Dset(2, t16, LVfparms);
      LVdut1 = t16;
      OFoneof_Dmake(7, LVdut1);
      if (OFc__env_Dget__type(LVe, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      LVt2 = retval_area[0];
      t16 = OFsequence_D__alloc(1);
      OMsequence_D__store(t16, 1, LVt1);
      LVargs = t16;
      t16 = OFsequence_D__alloc(1);
      OMsequence_D__store(t16, 1, LVt2);
      LVvals = t16;
      if (OMstring_Dequal(LVn, ((string) &str5)))
        {
	  t17 = TRUE;
        }
      else
        {
	  t17 = OMstring_Dequal(LVn, ((string) &str7));
        }
      if (t17)
        {
	  t16 = TRUE;
        }
      else
        {
	  t16 = OMstring_Dequal(LVn, ((string) &str8));
        }
      if (t16)
        {
	  t18 = LVvals;
	  t19 = LVargs;
	  LVargs = t18;
	  LVvals = t19;
        }
      else
        {
	  if (OMstring_Dequal(LVn, ((string) &str9)))
	    {
	      t18 = TRUE;
	    }
	  else
	    {
	      t18 = OMstring_Dequal(LVn, ((string) &str10));
	    }
	  if (t18)
	    {
	      OFsequence_Dconcat(LVargs, LVvals);
	      LVargs = retval_area[0];
	      t19 = OFsequence_D__alloc(0);
	      LVvals = t19;
	    }
        }
      if (OFc__env_Dget__proc__(LVe) == SIG)
        {
	  goto except0;
        }
      t16 = retval_area[0];
      OFsequence_Dnew();
      t17 = OFrecord_D__alloc(4);
      OMrecord_Dset(1, t17, LVargs);
      OMrecord_Dset(2, t17, t16);
      OMrecord_Dset(3, t17, retval_area[0]);
      OMrecord_Dset(4, t17, LVvals);
      LVapt = t17;
      OFoneof_Dmake(2, LVapt);
      if (OFc__env_Dget__type(LVe, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      retval_area[0] = retval_area[0];
      return RET;
    }
  if (AFget__clusterop__print(LVcop) == SIG)
    {
      goto except0;
    }
  t1 = OFsequence_D__alloc(3);
  OMsequence_D__store(t1, 1, ((string) &str2));
  OMsequence_D__store(t1, 2, retval_area[0]);
  OMsequence_D__store(t1, 3, ((string) &str3));
  if (OFc__env_Derr(LVe, t1) == SIG)
    {
      goto except0;
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
/* c_function_name, AFc__sel__type */
/* clu_operation_name, c_sel_type */
int AFc__sel__type(LVe, LVsel, LVspecs)
     object LVe;
     object LVsel;
     object LVspecs;
{
  int t1, t2, t3;
  /* begin body */
    {
      object LVspec= 0;
      for (t1 = LVspecs, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVspec = OMsequence_Dfetch(t1, t2);
	    {
	      if (OMstring_Dequal(LVsel, OMrecord_Dget(1, LVspec)))
	        {
		  retval_area[0] = OMrecord_Dget(2, LVspec);
		  return RET;
	        }
	    }
        }
    }
  if (OMbool_Dnot(OMsequence_Dempty(LVspecs)))
    {
      t1 = OFsequence_D__alloc(3);
      OMsequence_D__store(t1, 1, ((string) &str2));
      OMsequence_D__store(t1, 2, LVsel);
      OMsequence_D__store(t1, 3, ((string) &str11));
      if (OFc__env_Derr(LVe, t1) == SIG)
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
/* c_function_name, AFc__idn__op */
/* clu_operation_name, c_idn_op */
int AFc__idn__op(LVe, LVi, LVcop)
     object LVe;
     object LVi;
     object LVcop;
{
  int t1, t2, t3, t4, t5;
  /* begin body */
  if (OFidn_Dget__kind(LVi) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 6 || t1 == 5)
    {
      object LVk= 0;
      LVk = ((oneof) retval_area[0])->value;
        {
	  object LVop= 0;
	  object LVparms= 0;
	  LVop = OMrecord_Dget(1, LVcop);
	  LVparms = OMrecord_Dget(2, LVcop);
	    {
	      object LVspec= 0;
	      for (t2 = LVk, t3 = 1, t4 = OMsequence_Dsize(t2);
	           t3 <= t4;
	           t3++)
	        {
		  LVspec = OMsequence_Dfetch(t2, t3);
		    {
		      t5 = FALSE;
		      if (OMstring_Dequal(LVop, OMrecord_Dget(1, LVspec)))
		        {
			  if ((*((proctype)PV1_INc__idn__op))(LVparms, OMrecord_Dget(2, LVspec)) == SIG)
			    {
			      goto except0;
			    }
			  if (retval_area[0])
			    {
			      t5 = TRUE;
			    }
		        }
		      if (t5)
		        {
			  retval_area[0] = OMrecord_Dget(3, LVspec);
			  return RET;
		        }
		    }
	        }
	    }
	  if (OFc__env_Dbuilding__specs(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (OMbool_Dnot(retval_area[0]))
	    {
	      if (AFget__clusterop__print(LVcop) == SIG)
	        {
		  goto except0;
	        }
	      t2 = OFsequence_D__alloc(3);
	      OMsequence_D__store(t2, 1, ((string) &str2));
	      OMsequence_D__store(t2, 2, retval_area[0]);
	      OMsequence_D__store(t2, 3, ((string) &str3));
	      if (OFc__env_Derr(LVe, t2) == SIG)
	        {
		  goto except0;
	        }
	    }
        }
    }
  else if (t1 == 9 || t1 == 4)
    {
        {
	  OFoneof_Dmake(2, LVcop);
	  OFoneof_Dmake(6, retval_area[0]);
	  if (OFc__env_Dget__type(LVe, retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
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
/* c_function_name, AFc__apply__op */
/* clu_operation_name, c_apply_op */
int AFc__apply__op(LVe, LVat, LVcop)
     object LVe;
     object LVat;
     object LVcop;
{
  object LVinfo= 0;
  object LVspecs= 0;
  object LVn= 0;
  object LVx= 0;
  int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
  /* begin body */
  if (AFc__get__duspecs(LVe, OMrecord_Dget(2, LVat)) == SIG)
    {
      goto except0;
    }
  LVspecs = retval_area[0];
  t1 = ((oneof) LVspecs)->tag;
  if (t1 == 2)
    {
      object LVinf= 0;
      LVinf = ((oneof) LVspecs)->value;
        {
	  LVinfo = LVinf;
        }
    }
  else if (t1 == 4)
    {
        {
	  OFoneof_Dmake(2, LVcop);
	  OFoneof_Dmake(6, retval_area[0]);
	  if (OFc__env_Dget__type(LVe, retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else
    {
      if (OFc__env_Dget__unknown__type(LVe) == SIG)
        {
	  goto except0;
        }
      retval_area[0] = retval_area[0];
      return RET;
    }
  LVn = OMrecord_Dget(1, LVcop);
  OFoneof_Dmake(27, OMrecord_Dget(3, LVcop));
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
    {
      object LVop= 0;
      for (t1 = OMrecord_Dget(1, LVinfo), t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVop = OMsequence_Dfetch(t1, t2);
	    {
	      if (OMstring_Dequal(LVn, OMrecord_Dget(2, LVop)))
	        {
		  object LVpparms= 0;
		  object LVainfo= 0;
		  LVpparms = OMrecord_Dget(2, LVcop);
		  LVainfo = OMrecord_Dget(1, LVop);
		  if (AFc__parms(LVe, LVpparms, OMrecord_Dget(1, LVainfo)) == SIG)
		    {
		      goto except0;
		    }
		  if (retval_area[0])
		    {
		      OFsequence_De2s(LVx);
		      t4 = retval_area[0];
		      if (AFsubst__2__parms(LVe, t4, OMrecord_Dget(2, LVinfo), LVpparms, LVainfo) == SIG)
		        {
			  goto except0;
		        }
		      retval_area[0] = retval_area[0];
		      return RET;
		    }
		  if (AFget__clusterop__print(LVcop) == SIG)
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
  t1 = FALSE;
  t2 = FALSE;
  if (OMstring_Dequal(LVn, ((string) &str8)))
    {
      t3 = OMrecord_Dget(2, LVat);
      if (OFc__env_Dget__proc__(LVe) == SIG)
        {
	  goto except0;
        }
      if (OFdu_Dequal(t3, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      if (OMbool_Dnot(retval_area[0]))
        {
	  t2 = TRUE;
        }
    }
  if (t2)
    {
      t4 = OMrecord_Dget(2, LVat);
      if (OFc__env_Dget__iter__(LVe) == SIG)
        {
	  goto except0;
        }
      if (OFdu_Dequal(t4, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      if (OMbool_Dnot(retval_area[0]))
        {
	  t1 = TRUE;
        }
    }
  if (t1)
    {
      object LVt= 0;
      object LVok= 0;
      object LVpta= 0;
      object LVpt= 0;
      LVok = OMint_Dequal(OMsequence_Dsize(OMrecord_Dget(2, LVcop)), 1);
      if (LVok)
        {
	  t5 = OMrecord_Dget(2, LVcop);
	  if (OMsequence_Dempty(t5))
	    {
	      signame = SLBOUNDS;
	      goto except1;
	    }
	  if (OFexpr_Dget__abs(OMsequence_Dbottom(t5)) == SIG)
	    {
	      goto except1;
	    }
	  if (OFoneof_Dvalue(27, retval_area[0]) == SIG)
	    {
	      goto except1;
	    }
	  LVt = retval_area[0];
        }
      if (FALSE)
        {
	except1:
	  if (OMstring_Dequal(signame, SLWRONG_TAG))
	    {
	      LVok = FALSE;
	    }
	  else
	    {
	      goto except0;
	    }
        }
      if (OMbool_Dnot(LVok))
        {
	  if (AFget__clusterop__print(LVcop) == SIG)
	    {
	      goto except0;
	    }
	  t5 = OFsequence_D__alloc(3);
	  OMsequence_D__store(t5, 1, ((string) &str1));
	  OMsequence_D__store(t5, 2, retval_area[0]);
	  OMsequence_D__store(t5, 3, ((string) &str2));
	  if (OFc__env_Derr(LVe, t5) == SIG)
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
      if (OFc__env_Dget__proc__(LVe) == SIG)
        {
	  goto except0;
        }
      t5 = retval_area[0];
      OFsequence_Daddl(OMrecord_Dget(1, LVat), LVt);
      t6 = retval_area[0];
      t7 = OMrecord_Dget(4, LVat);
      t8 = OFrecord_D__alloc(4);
      OMrecord_Dset(1, t8, t6);
      OMrecord_Dset(2, t8, t5);
      OMrecord_Dset(3, t8, OMrecord_Dget(3, LVat));
      OMrecord_Dset(4, t8, t7);
      LVpta = t8;
      OFoneof_Dmake(2, LVpta);
      if (OFc__env_Dget__type(LVe, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      LVpt = retval_area[0];
      if (OFc__env_Dget__proc__(LVe) == SIG)
        {
	  goto except0;
        }
      t5 = retval_area[0];
      if (OFc__env_Dget__int__type(LVe) == SIG)
        {
	  goto except0;
        }
      t6 = OFsequence_D__alloc(2);
      OMsequence_D__store(t6, 1, retval_area[0]);
      OMsequence_D__store(t6, 2, LVpt);
      t7 = t6;
      t8 = OFsequence_D__alloc(1);
      OMsequence_D__store(t8, 1, OMrecord_Dget(3, LVcop));
      t9 = OFsequence_D__alloc(0);
      t10 = OFrecord_D__alloc(4);
      OMrecord_Dset(1, t10, t7);
      OMrecord_Dset(2, t10, t5);
      OMrecord_Dset(3, t10, t9);
      OMrecord_Dset(4, t10, t8);
      LVpta = t10;
      OFoneof_Dmake(2, LVpta);
      if (OFc__env_Dget__type(LVe, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      retval_area[0] = retval_area[0];
      return RET;
    }
  if (AFget__clusterop__print(LVcop) == SIG)
    {
      goto except0;
    }
  t1 = OFsequence_D__alloc(3);
  OMsequence_D__store(t1, 1, ((string) &str2));
  OMsequence_D__store(t1, 2, retval_area[0]);
  OMsequence_D__store(t1, 3, ((string) &str3));
  if (OFc__env_Derr(LVe, t1) == SIG)
    {
      goto except0;
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
/* c_function_name, AFc__requires */
/* clu_operation_name, c_requires */
int AFc__requires(LVe, LVvals, LVparms, LVreqs)
     object LVe;
     object LVvals;
     object LVparms;
     object LVreqs;
{
  int t1, t2, t3, t4, t5, t6;
  /* begin body */
    {
      object LVreq= 0;
      for (t1 = LVreqs, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVreq = OMsequence_Dfetch(t1, t2);
	    {
	      object LVp= 0;
	      LVp = OMrecord_Dget(2, LVreq);
	        {
		  object LVi= 0;
		  for (t4 = 1, t5 = OMsequence_Dsize(LVparms); t4 <= t5; t4++)
		    {
		      LVi = t4;
		        {
			  if (OMsequence_Dbounds(LVparms, LVi))
			    {
			      signame = SLBOUNDS;
			      goto except0;
			    }
			  if (OFidn_Dequal(LVp, OMsequence_Dfetch(LVparms, LVi)) == SIG)
			    {
			      goto except0;
			    }
			  if (retval_area[0])
			    {
			      if (OMsequence_Dbounds(LVvals, LVi))
			        {
				  signame = SLBOUNDS;
				  goto except0;
			        }
			      t6 = OMsequence_Dfetch(LVvals, LVi);
			      if (AFc__restrictions(LVe, t6, LVvals, LVparms, OMrecord_Dget(1, LVreq)) == SIG)
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
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFc__select__requires */
/* clu_operation_name, c_select_requires */
int AFc__select__requires(LVe, LVspecs, LVreqs)
     object LVe;
     object LVspecs;
     object LVreqs;
{
  int t1, t2, t3, t4, t5, t6, t7, t8;
  /* begin body */
    {
      object LVreq= 0;
      for (t1 = LVreqs, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVreq = OMsequence_Dfetch(t1, t2);
	    {
	        {
		  object LVspec= 0;
		  for (t4 = LVspecs, t5 = 1, t6 = OMsequence_Dsize(t4);
		       t5 <= t6;
		       t5++)
		    {
		      LVspec = OMsequence_Dfetch(t4, t5);
		        {
			  object LVx= 0;
			  OFoneof_Dmake(27, OMrecord_Dget(2, LVspec));
			  t7 = retval_area[0];
			  if (OFc__env_Dget__type__type(LVe) == SIG)
			    {
			      goto except0;
			    }
			  if (OFexpr_Dcreate(t7, retval_area[0]) == SIG)
			    {
			      goto except0;
			    }
			  LVx = retval_area[0];
			  if (OMbool_Dnot(OMsequence_Dempty(OMrecord_Dget(1, LVreq))))
			    {
			      OFsequence_De2s(LVx);
			      t7 = retval_area[0];
			      OFsequence_De2s(OMrecord_Dget(2, LVreq));
			      t8 = retval_area[0];
			      if (AFc__restrictions(LVe, LVx, t7, t8, OMrecord_Dget(1, LVreq)) == SIG)
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
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFsubst__parms */
/* clu_operation_name, subst_parms */
int AFsubst__parms(LVe, LVvals, LVforms, LVt)
     object LVe;
     object LVvals;
     object LVforms;
     object LVt;
{
  /* begin body */
  if (OMsequence_Dempty(LVvals))
    {
      retval_area[0] = LVt;
      return RET;
    }
  if (OFc__env_Dbegin__scope(LVe) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dpush__vals(LVe, LVforms, LVvals) == SIG)
    {
      goto except0;
    }
  if (AFb__type(LVe, LVt) == SIG)
    {
      goto except0;
    }
  LVt = retval_area[0];
  if (OFc__env_Dend__scope(LVe) == SIG)
    {
      goto except0;
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
/* c_function_name, AFsubst__2__parms */
/* clu_operation_name, subst_2_parms */
int AFsubst__2__parms(LVe, LVvals1, LVparms1, LVvals2, LVinfo)
     object LVe;
     object LVvals1;
     object LVparms1;
     object LVvals2;
     object LVinfo;
{
  object LVt= 0;
  int t1;
  /* begin body */
  LVt = OMrecord_Dget(2, LVinfo);
  t1 = FALSE;
  if (OMsequence_Dempty(LVvals1))
    {
      if (OMsequence_Dempty(LVvals2))
        {
	  t1 = TRUE;
        }
    }
  if (t1)
    {
      retval_area[0] = LVt;
      return RET;
    }
  if (OFc__env_Dbegin__scope(LVe) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dpush__vals(LVe, LVparms1, LVvals1) == SIG)
    {
      goto except0;
    }
  if (OFc__env_Dpush__vals(LVe, OMrecord_Dget(1, LVinfo), LVvals2) == SIG)
    {
      goto except0;
    }
  if (AFb__type(LVe, LVt) == SIG)
    {
      goto except0;
    }
  LVt = retval_area[0];
  if (OFc__env_Dend__scope(LVe) == SIG)
    {
      goto except0;
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
/* c_function_name, AFc__restrictions */
/* clu_operation_name, c_restrictions */
int AFc__restrictions(LVe, LVx, LVvals, LVforms, LVspecs)
     object LVe;
     object LVx;
     object LVvals;
     object LVforms;
     object LVspecs;
{
  object LVt= 0;
  object LVok= 0;
  int t1, t2, t3, t4, t5;
  /* begin body */
  if (OFexpr_Dget__abs(LVx) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 27)
    {
      object LVxa= 0;
      LVxa = ((oneof) retval_area[0])->value;
        {
	  LVt = LVxa;
        }
    }
  else if (t1 == 5)
    {
        {
	  retval_area[0] = FALSE;
	  return RET;
        }
    }
  else if (t1 == 3)
    {
        {
	  retval_area[0] = TRUE;
	  return RET;
        }
    }
  else
    {
      retval_area[0] = FALSE;
      return RET;
    }
  LVok = TRUE;
    {
      object LVspec= 0;
      for (t1 = LVspecs, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVspec = OMsequence_Dfetch(t1, t2);
	    {
	      object LVopt= 0;
	      object LVcop= 0;
	      object LVcopt= 0;
	      if (AFsubst__parms(LVe, LVvals, LVforms, OMrecord_Dget(3, LVspec)) == SIG)
	        {
		  goto except0;
	        }
	      LVopt = retval_area[0];
	      t4 = OMrecord_Dget(1, LVspec);
	      t5 = OFrecord_D__alloc(3);
	      OMrecord_Dset(1, t5, t4);
	      OMrecord_Dset(2, t5, OMrecord_Dget(2, LVspec));
	      OMrecord_Dset(3, t5, LVt);
	      LVcop = t5;
	      if (AFc__clusterop(LVe, LVcop) == SIG)
	        {
		  goto except0;
	        }
	      LVcopt = retval_area[0];
	      if (OFtypespec_Dmismatch(LVopt, LVcopt) == SIG)
	        {
		  goto except0;
	        }
	      if (retval_area[0])
	        {
		  LVok = FALSE;
		  if (AFget__clusterop__print(LVcop) == SIG)
		    {
		      goto except0;
		    }
		  t4 = OFsequence_D__alloc(3);
		  OMsequence_D__store(t4, 1, ((string) &str12));
		  OMsequence_D__store(t4, 2, retval_area[0]);
		  OMsequence_D__store(t4, 3, ((string) &str13));
		  if (OFc__env_Derr(LVe, t4) == SIG)
		    {
		      goto except0;
		    }
	        }
	    }
        }
    }
  retval_area[0] = LVok;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */