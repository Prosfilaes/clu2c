/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,appgen,appinst,clugen,conv_appfun,conv_opfun,db_env,discard_sel,e_env,emit_owns,gentab,need_sel_id,op_cluname,replace_tparm,selgen,stream,type_id*/
/* built-in param,array$similar,PV1_INappgen_Dlookup__inst,appgen$lookup_inst,oneof[tparm:oneof[clu:cluinst fparm:int sel:selinst] vparm:oneof[fparm:int lit:string]]*/

#include <clu2c.h>

extern object	PV1_INappgen_Dlookup__inst;

static STRING_REP(8) str1 = {8, {'c', 'o', 'n', 'f', 'l', 'i', 'c', 't'}};
static STRING_REP(9) str2 = {9, {'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n'}};
static STRING_REP(6) str3 = {6, {'e', 'x', 'i', 's', 't', 's'}};
static STRING_REP(17) str4 = {17, {'a', 'p', 'p', 'g', 'e', 'n', '$', 'e', 'n', 't', 'e', 'r', '_', 'i', 'n', 's', 't'}};
static STRING_REP(29) str5 = {29, {'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'o', 'f', ' ', 'f', 'o', 'r', 'm', 'a', 'l', ' ', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r'}};
static STRING_REP(3) str6 = {3, {'?', '?', '?'}};
static STRING_REP(19) str7 = {19, {'a', 'p', 'p', 'g', 'e', 'n', '$', 'g', 'e', 't', '_', 'f', 'u', 'n', '_', 'n', 'a', 'm', 'e'}};
static STRING_REP(4) str8 = {4, {'n', 'o', 'n', 'e'}};
static STRING_REP(2) str9 = {2, {'/', '*'}};
static STRING_REP(3) str10 = {3, {' ', '*', ' '}};
static STRING_REP(3) str11 = {3, {' ', '*', '/'}};
static STRING_REP(4) str12 = {4, {'i', 'n', 't', ' '}};
static STRING_REP(6) str13 = {6, {'[', ']', ' ', '=', ' ', '{'}};
static STRING_REP(2) str14 = {2, {',', ' '}};
static STRING_REP(2) str15 = {2, {'}', ';'}};
static STRING_REP(1) str16 = {1, {'\t'}};

/* begin module */
/* c_function_name, OFappgen_Dcreate */
/* clu_operation_name, appgen$create */
int OFappgen_Dcreate(LVname)
     object LVname;
{
  object LVres= 0;
  int t1;
  /* begin body */
    {
      object LVgen= 0;
      if (OFgentab_Dlookup(LVname) == SIG)
        {
	  goto except1;
        }
      LVgen = retval_area[0];
      t1 = ((oneof) LVgen)->tag;
      if (t1 == 1)
        {
	  object LVg= 0;
	  LVg = ((oneof) LVgen)->value;
	    {
	      retval_area[0] = LVg;
	      return RET;
	    }
        }
      else
        {
	  signame = ((string) &str1);
	  return(SIG);
        }
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_FOUND))
        {
        }
      else
        {
	  goto except0;
        }
    }
  OFoneof_Dmake(3, NIL);
  if (OFappgen_Dcreate0(LVname, retval_area[0]) == SIG)
    {
      goto except0;
    }
  LVres = retval_area[0];
  OFoneof_Dmake(1, LVres);
  if (OFgentab_Denter(LVname, retval_area[0]) == SIG)
    {
      goto except0;
    }
  retval_area[0] = LVres;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFappgen_Dcreate__cluop */
/* clu_operation_name, appgen$create_cluop */
int OFappgen_Dcreate__cluop(LVname, LVgen)
     object LVname;
     object LVgen;
{
  object LVag= 0;
  /* begin body */
  if (OFclugen_Dlookup__op(LVgen, LVname) == SIG)
    {
      goto except1;
    }
  retval_area[0] = retval_area[0];
  return RET;
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_FOUND))
        {
        }
      else
        {
	  goto except0;
        }
    }
  OFoneof_Dmake(1, LVgen);
  if (OFappgen_Dcreate0(LVname, retval_area[0]) == SIG)
    {
      goto except0;
    }
  LVag = retval_area[0];
  if (OFclugen_Denter__op(LVgen, LVag) == SIG)
    {
      goto except0;
    }
  retval_area[0] = LVag;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFappgen_Dcreate__selop */
/* clu_operation_name, appgen$create_selop */
int OFappgen_Dcreate__selop(LVname, LVgen)
     object LVname;
     object LVgen;
{
  object LVag= 0;
  /* begin body */
  if (OFselgen_Dlookup__op(LVgen, LVname) == SIG)
    {
      goto except1;
    }
  retval_area[0] = retval_area[0];
  return RET;
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_FOUND))
        {
        }
      else
        {
	  goto except0;
        }
    }
  OFoneof_Dmake(4, LVgen);
  if (OFappgen_Dcreate0(LVname, retval_area[0]) == SIG)
    {
      goto except0;
    }
  LVag = retval_area[0];
  if (OFselgen_Denter__op(LVgen, LVag) == SIG)
    {
      goto except0;
    }
  if (AFneed__sel__id(LVname) == SIG)
    {
      goto except0;
    }
  if (retval_area[0])
    {
      if (AFdiscard__sel(LVname) == SIG)
        {
	  goto except0;
        }
      if (OFselgen_Dlookup__op(LVgen, retval_area[0]) == SIG)
        {
	  goto except0;
        }
      if (OFappgen_Dget__nr__args(retval_area[0]) == SIG)
        {
	  goto except0;
        }
      OMrecord_Dset(4, LVag, retval_area[0]);
    }
  retval_area[0] = LVag;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFappgen_Dcreate__formalop */
/* clu_operation_name, appgen$create_formalop */
int OFappgen_Dcreate__formalop(LVname, LVid)
     object LVname;
     object LVid;
{
  /* begin body */
  OFoneof_Dmake(2, LVid);
  if (OFappgen_Dcreate0(LVname, retval_area[0]) == SIG)
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
/* c_function_name, OFappgen_Dcreate0 */
/* clu_operation_name, appgen$create0 */
int OFappgen_Dcreate0(LVname, LVprovider)
     object LVname;
     object LVprovider;
{
  int t1, t2, t3, t4, t5;
  /* begin body */
  OFarray_Dnew();
  t1 = retval_area[0];
  OFarray_Dcreate(0);
  t2 = retval_area[0];
  OFarray_Dnew();
  t3 = retval_area[0];
  OFarray_Dnew();
  t4 = retval_area[0];
  OFarray_Dnew();
  t5 = OFrecord_D__alloc(9);
  OMrecord_Dset(1, t5, t2);
  OMrecord_Dset(2, t5, t3);
  OMrecord_Dset(3, t5, LVname);
  OMrecord_Dset(4, t5, 0);
  OMrecord_Dset(5, t5, t1);
  OMrecord_Dset(6, t5, FALSE);
  OMrecord_Dset(7, t5, LVprovider);
  OMrecord_Dset(8, t5, t4);
  OMrecord_Dset(9, t5, retval_area[0]);
  retval_area[0] = t5;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFappgen_Dlookup__inst */
/* clu_operation_name, appgen$lookup_inst */
int OFappgen_Dlookup__inst(LVgen, LVparms)
     object LVgen;
     object LVparms;
{
  int t1, t2, t3, t4, t5;
  /* begin body */
  t1 = OMrecord_Dget(7, LVgen);
  t2 = ((oneof) t1)->tag;
  if (t2 == 3)
    {
        {
	    {
	      object LVinst= 0;
	      for (t3 = OMrecord_Dget(1, LVgen), t4 = OMarray_Dlow(t3), t5 = OMarray_Dhigh(t3);
	           t4 <= t5;
	           t4++)
	        {
		  LVinst = OMarray_Dfetch(t3, t4);
		    {
		      if (OFappinst_Dget__parms(LVinst) == SIG)
		        {
			  goto except0;
		        }
		      if ((*((proctype)PV1_INappgen_Dlookup__inst))(retval_area[0], LVparms) == SIG)
		        {
			  goto except0;
		        }
		      if (retval_area[0])
		        {
			  retval_area[0] = LVinst;
			  return RET;
		        }
		    }
	        }
	    }
	  signame = SLNOT_FOUND;
	  return(SIG);
        }
    }
  else
    {
      signame = ((string) &str2);
      return(SIG);
    }
  /* end body */
  noretval(SLNULL);
  return(SIG);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFappgen_Denter__inst */
/* clu_operation_name, appgen$enter_inst */
int OFappgen_Denter__inst(LVgen, LVinst)
     object LVgen;
     object LVinst;
{
  object LVinsts= 0;
  int t1, t2;
  /* begin body */
  LVinsts = OMrecord_Dget(1, LVgen);
  t1 = OMrecord_Dget(7, LVgen);
  t2 = ((oneof) t1)->tag;
  if (t2 == 3)
    {
        {
	    {
	      if (OFappinst_Dget__parms(LVinst) == SIG)
	        {
		  goto except1;
	        }
	      if (OFappgen_Dlookup__inst(LVgen, retval_area[0]) == SIG)
	        {
		  goto except1;
	        }
	      signame = ((string) &str3);
	      return(SIG);
	    }
	  if (FALSE)
	    {
	    except1:
	      if (OMstring_Dequal(signame, SLNOT_FOUND))
	        {
	        }
	      else
	        {
		  goto except0;
	        }
	    }
        }
    }
  else if (t2 == 1 || t2 == 4)
    {
        {
        }
    }
  else
    {
      object LVee= 0;
      if (OFe__env_Dget() == SIG)
        {
	  goto except0;
        }
      LVee = retval_area[0];
      if (OFe__env_Dinterr1(LVee, ((string) &str4), ((string) &str5)) == SIG)
        {
	  goto except0;
        }
    }
  OMarray_Daddh(LVinsts, LVinst);
  retval_area[0] = OMarray_Dhigh(LVinsts);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFappgen_Dget__name */
/* clu_operation_name, appgen$get_name */
int OFappgen_Dget__name(LVgen)
     object LVgen;
{
  /* begin body */
  retval_area[0] = OMrecord_Dget(3, LVgen);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFappgen_Dadd__invoke */
/* clu_operation_name, appgen$add_invoke */
int OFappgen_Dadd__invoke(LVgen, LVinv)
     object LVgen;
     object LVinv;
{
  /* begin body */
  OMarray_Daddh(OMrecord_Dget(2, LVgen), LVinv);
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFappgen_Dadd__type */
/* clu_operation_name, appgen$add_type */
int OFappgen_Dadd__type(LVgen, LVtp, LVvar)
     object LVgen;
     object LVtp;
     object LVvar;
{
  /* begin body */
  OMarray_Daddh(OMrecord_Dget(9, LVgen), LVtp);
  OMarray_Daddh(OMrecord_Dget(8, LVgen), LVvar);
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFappgen_Dget__clu__name */
/* clu_operation_name, appgen$get_clu_name */
int OFappgen_Dget__clu__name(LVgen)
     object LVgen;
{
  int t1, t2, t3;
  /* begin body */
  t1 = OMrecord_Dget(7, LVgen);
  t2 = ((oneof) t1)->tag;
  if (t2 == 3)
    {
        {
	  retval_area[0] = OMrecord_Dget(3, LVgen);
	  return RET;
        }
    }
  else if (t2 == 1)
    {
      object LVg= 0;
      LVg = ((oneof) t1)->value;
        {
	  if (OFclugen_Dget__name(LVg) == SIG)
	    {
	      goto except0;
	    }
	  t3 = retval_area[0];
	  if (AFop__cluname(t3, OMrecord_Dget(3, LVgen)) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else if (t2 == 4)
    {
      object LVg= 0;
      LVg = ((oneof) t1)->value;
        {
	  if (OFselgen_Dget__name(LVg) == SIG)
	    {
	      goto except0;
	    }
	  t3 = retval_area[0];
	  if (AFop__cluname(t3, OMrecord_Dget(3, LVgen)) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else
    {
      if (AFop__cluname(((string) &str6), OMrecord_Dget(3, LVgen)) == SIG)
        {
	  goto except0;
        }
      retval_area[0] = retval_area[0];
      return RET;
    }
  /* end body */
  noretval(SLNULL);
  return(SIG);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFappgen_Dget__fun__name */
/* clu_operation_name, appgen$get_fun_name */
int OFappgen_Dget__fun__name(LVgen)
     object LVgen;
{
  int t1, t2, t3;
  /* begin body */
  t1 = OMrecord_Dget(7, LVgen);
  t2 = ((oneof) t1)->tag;
  if (t2 == 3)
    {
        {
	  if (AFconv__appfun(OMrecord_Dget(3, LVgen)) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else if (t2 == 1)
    {
      object LVg= 0;
      LVg = ((oneof) t1)->value;
        {
	  if (OFclugen_Dget__name(LVg) == SIG)
	    {
	      goto except0;
	    }
	  t3 = retval_area[0];
	  if (AFconv__opfun(t3, OMrecord_Dget(3, LVgen)) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else if (t2 == 4)
    {
      object LVg= 0;
      LVg = ((oneof) t1)->value;
        {
	  if (OFselgen_Dget__name(LVg) == SIG)
	    {
	      goto except0;
	    }
	  t3 = retval_area[0];
	  if (AFconv__opfun(t3, OMrecord_Dget(3, LVgen)) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else
    {
      object LVee= 0;
      if (OFe__env_Dget() == SIG)
        {
	  goto except0;
        }
      LVee = retval_area[0];
      if (OFe__env_Dinterr1(LVee, ((string) &str7), ((string) &str5)) == SIG)
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
/* c_function_name, OFappgen_Dadd__own__var */
/* clu_operation_name, appgen$add_own_var */
int OFappgen_Dadd__own__var(LVgen, LVdecl)
     object LVgen;
     object LVdecl;
{
  /* begin body */
  OMarray_Daddh(OMrecord_Dget(5, LVgen), LVdecl);
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFappgen_Dfix__invokes */
/* clu_operation_name, appgen$fix_invokes */
int OFappgen_Dfix__invokes(LVgen)
     object LVgen;
{
  object LVinsts= 0;
  object LVinvokes= 0;
  object LVseed= 0;
  int t1, t2, t3;
  /* begin body */
  LVinsts = OMrecord_Dget(1, LVgen);
  LVinvokes = OMrecord_Dget(2, LVgen);
  t1 = OMrecord_Dget(7, LVgen);
  t2 = ((oneof) t1)->tag;
  if (t2 == 4)
    {
        {
	  if (OMarray_Dbounds(LVinvokes, 1))
	    {
	      signame = SLBOUNDS;
	      goto except1;
	    }
	  LVseed = OMarray_Dfetch(LVinvokes, 1);
	  if (FALSE)
	    {
	    except1:
	      if (OMstring_Dequal(signame, SLBOUNDS))
	        {
		  return RET;
	        }
	      else
	        {
		  goto except0;
	        }
	    }
        }
    }
  while (TRUE)
    {
        {
	  object LVinst= 0;
	  object LVall__parms= 0;
	  object LVnewinvokes= 0;
	  object LVgrown__gens= 0;
	  if (OFappgen_Dpick__one__inst(LVinsts) == SIG)
	    {
	      goto except2;
	    }
	  LVinst = retval_area[0];
	  if (OFappinst_Dget__all__parms(LVinst) == SIG)
	    {
	      goto except2;
	    }
	  LVall__parms = retval_area[0];
	  t1 = OMrecord_Dget(7, LVgen);
	  t2 = ((oneof) t1)->tag;
	  if (t2 == 4)
	    {
	        {
		  if (OFappgen_Dexpand__invoke(LVseed, OMarray_Dsize(LVall__parms)) == SIG)
		    {
		      goto except2;
		    }
		  LVnewinvokes = retval_area[0];
	        }
	    }
	  else
	    {
	      LVnewinvokes = LVinvokes;
	    }
	  OFarray_Dnew();
	  LVgrown__gens = retval_area[0];
	    {
	      object LVinvoke= 0;
	      for (t1 = LVnewinvokes, t2 = OMarray_Dlow(t1), t3 = OMarray_Dhigh(t1);
	           t2 <= t3;
	           t2++)
	        {
		  LVinvoke = OMarray_Dfetch(t1, t2);
		    {
		      object LVnewinst= 0;
		      if (OFappinst_Dreplace(LVinvoke, LVall__parms) == SIG)
		        {
			  goto except2;
		        }
		      LVnewinst = retval_area[0];
		      if (OFappinst_Dadd__invoke(LVinst, LVnewinst) == SIG)
		        {
			  goto except2;
		        }
		      if (OFappinst_Dget__gen(LVnewinst) == SIG)
		        {
			  goto except2;
		        }
		      OMarray_Daddh(LVgrown__gens, retval_area[0]);
		    }
	        }
	    }
	    {
	      object LVtp= 0;
	      for (t1 = OMrecord_Dget(9, LVgen), t2 = OMarray_Dlow(t1), t3 = OMarray_Dhigh(t1);
	           t2 <= t3;
	           t2++)
	        {
		  LVtp = OMarray_Dfetch(t1, t2);
		    {
		      if (AFreplace__tparm(LVtp, LVall__parms) == SIG)
		        {
			  goto except2;
		        }
		      if (OFappinst_Dadd__type(LVinst, retval_area[0]) == SIG)
		        {
			  goto except2;
		        }
		    }
	        }
	    }
	  if (OFappinst_Dset__fixed(LVinst, TRUE) == SIG)
	    {
	      goto except2;
	    }
	    {
	      object LVgrown= 0;
	      for (t1 = LVgrown__gens, t2 = OMarray_Dlow(t1), t3 = OMarray_Dhigh(t1);
	           t2 <= t3;
	           t2++)
	        {
		  LVgrown = OMarray_Dfetch(t1, t2);
		    {
		      if (OFappgen_Dfix__invokes(LVgrown) == SIG)
		        {
			  goto except2;
		        }
		    }
	        }
	    }
        }
    }
  if (FALSE)
    {
    except2:
      if (OMstring_Dequal(signame, ((string) &str8)))
        {
        }
      else
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
/* c_function_name, OFappgen_Dpick__one__inst */
/* clu_operation_name, appgen$pick_one_inst */
int OFappgen_Dpick__one__inst(LVinsts)
     object LVinsts;
{
  int t1, t2, t3;
  /* begin body */
    {
      object LVinst= 0;
      for (t1 = LVinsts, t2 = OMarray_Dlow(t1), t3 = OMarray_Dhigh(t1);
           t2 <= t3;
           t2++)
        {
	  LVinst = OMarray_Dfetch(t1, t2);
	    {
	      if (OFappinst_Dget__fixed(LVinst) == SIG)
	        {
		  goto except0;
	        }
	      if (OMbool_Dnot(retval_area[0]))
	        {
		  retval_area[0] = LVinst;
		  return RET;
	        }
	    }
        }
    }
  signame = ((string) &str8);
  return(SIG);
  /* end body */
  noretval(SLNULL);
  return(SIG);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFappgen_Dexpand__invoke */
/* clu_operation_name, appgen$expand_invoke */
int OFappgen_Dexpand__invoke(LVseed, LVnr__parms)
     object LVseed;
     object LVnr__parms;
{
  object LVres= 0;
  int t1, t2, t3;
  /* begin body */
  OFarray_Dnew();
  LVres = retval_area[0];
    {
      object LVi= 0;
      for (t1 = 1, t2 = LVnr__parms; t1 <= t2; t1++)
        {
	  LVi = t1;
	    {
	      if (OFappinst_Dget__gen(LVseed) == SIG)
	        {
		  goto except0;
	        }
	      if (OFappgen_Dget__name(retval_area[0]) == SIG)
	        {
		  goto except0;
	        }
	      if (OFappgen_Dcreate__formalop(retval_area[0], LVi) == SIG)
	        {
		  goto except0;
	        }
	      t3 = retval_area[0];
	      if (OFappinst_Dget__parms(LVseed) == SIG)
	        {
		  goto except0;
	        }
	      if (OFappinst_Dcreate__formalop(LVi, t3, retval_area[0]) == SIG)
	        {
		  goto except0;
	        }
	      OMarray_Daddh(LVres, retval_area[0]);
	    }
        }
    }
  retval_area[0] = LVres;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFappgen_Demit__fundecl */
/* clu_operation_name, appgen$emit_fundecl */
int OFappgen_Demit__fundecl(LVgen, LVoutst)
     object LVgen;
     object LVoutst;
{
  int t1, t2, t3;
  /* begin body */
    {
      object LVinst= 0;
      for (t1 = OMrecord_Dget(1, LVgen), t2 = OMarray_Dlow(t1), t3 = OMarray_Dhigh(t1);
           t2 <= t3;
           t2++)
        {
	  LVinst = OMarray_Dfetch(t1, t2);
	    {
	      if (OFappinst_Demit__fundecl(LVinst, LVoutst) == SIG)
	        {
		  goto except0;
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
/* c_function_name, OFappgen_Demit__ptrdefn */
/* clu_operation_name, appgen$emit_ptrdefn */
int OFappgen_Demit__ptrdefn(LVgen, LVoutst)
     object LVgen;
     object LVoutst;
{
  int t1, t2, t3;
  /* begin body */
    {
      object LVinst= 0;
      for (t1 = OMrecord_Dget(1, LVgen), t2 = OMarray_Dlow(t1), t3 = OMarray_Dhigh(t1);
           t2 <= t3;
           t2++)
        {
	  LVinst = OMarray_Dfetch(t1, t2);
	    {
	      if (OFappinst_Demit__ptrdefn(LVinst, LVoutst) == SIG)
	        {
		  goto except0;
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
/* c_function_name, OFappgen_Demit__fundefn */
/* clu_operation_name, appgen$emit_fundefn */
int OFappgen_Demit__fundefn(LVgen, LVoutst)
     object LVgen;
     object LVoutst;
{
  object LVinsts= 0;
  object LVowns= 0;
  object LVnr__insts= 0;
  int t1, t2, t3;
  /* begin body */
  LVinsts = OMrecord_Dget(1, LVgen);
  LVowns = OMrecord_Dget(5, LVgen);
  t1 = FALSE;
  if (OMarray_Dempty(LVowns))
    {
      if (OFappgen_Dno__entry(LVgen) == SIG)
        {
	  goto except0;
        }
      if (retval_area[0])
        {
	  t1 = TRUE;
        }
    }
  if (t1)
    {
      return RET;
    }
  if (OFstream_Dputc(LVoutst, '\n') == SIG)
    {
      goto except0;
    }
  if (OFstream_Dputl(LVoutst, ((string) &str9)) == SIG)
    {
      goto except0;
    }
  if (OFstream_Dputs(LVoutst, ((string) &str10)) == SIG)
    {
      goto except0;
    }
  if (OFappgen_Dget__clu__name(LVgen) == SIG)
    {
      goto except0;
    }
  if (OFstream_Dputl(LVoutst, retval_area[0]) == SIG)
    {
      goto except0;
    }
  if (OFstream_Dputl(LVoutst, ((string) &str11)) == SIG)
    {
      goto except0;
    }
  LVnr__insts = OMarray_Dsize(LVinsts);
  if (OMint_Dequal(LVnr__insts, 0))
    {
      t1 = OMrecord_Dget(7, LVgen);
      t2 = ((oneof) t1)->tag;
      if (t2 == 1)
        {
	  object LVprovider= 0;
	  LVprovider = ((oneof) t1)->value;
	    {
	      if (OFclugen_Dget__nr__insts(LVprovider) == SIG)
	        {
		  goto except0;
	        }
	      LVnr__insts = retval_area[0];
	    }
        }
    }
  if (AFemit__owns(SLNULL, OMrecord_Dget(5, LVgen), LVnr__insts, LVoutst) == SIG)
    {
      goto except0;
    }
    {
      object LVinst= 0;
      for (t1 = LVinsts, t2 = OMarray_Dlow(t1), t3 = OMarray_Dhigh(t1);
           t2 <= t3;
           t2++)
        {
	  LVinst = OMarray_Dfetch(t1, t2);
	    {
	      if (OFstream_Dputc(LVoutst, '\n') == SIG)
	        {
		  goto except0;
	        }
	      if (OFappinst_Demit__fundefn(LVinst, LVoutst) == SIG)
	        {
		  goto except0;
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
/* c_function_name, OFappgen_Dno__entry */
/* clu_operation_name, appgen$no_entry */
int OFappgen_Dno__entry(LVgen)
     object LVgen;
{
  object LVno__insts= 0;
  int t1, t2, t3, t4;
  /* begin body */
  LVno__insts = OMarray_Dempty(OMrecord_Dget(1, LVgen));
  t1 = OMrecord_Dget(7, LVgen);
  t2 = ((oneof) t1)->tag;
  if (t2 == 3)
    {
        {
	  retval_area[0] = LVno__insts;
	  return RET;
        }
    }
  else if (t2 == 1)
    {
      object LVprovider= 0;
      LVprovider = ((oneof) t1)->value;
        {
	  t3 = FALSE;
	  if (OFclugen_Dnonparmed(LVprovider) == SIG)
	    {
	      goto except0;
	    }
	  if (retval_area[0])
	    {
	      if (LVno__insts)
	        {
		  t3 = TRUE;
	        }
	    }
	  retval_area[0] = t3;
	  return RET;
        }
    }
  else if (t2 == 4)
    {
        {
	  if (LVno__insts)
	    {
	      t3 = TRUE;
	    }
	  else
	    {
	      t4 = FALSE;
	      if (OMarray_Dempty(OMrecord_Dget(2, LVgen)))
	        {
		  if (AFneed__sel__id(OMrecord_Dget(3, LVgen)) == SIG)
		    {
		      goto except0;
		    }
		  if (OMbool_Dnot(retval_area[0]))
		    {
		      t4 = TRUE;
		    }
	        }
	      t3 = t4;
	    }
	  retval_area[0] = t3;
	  return RET;
        }
    }
  else if (t2 == 2)
    {
        {
	  retval_area[0] = FALSE;
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
/* c_function_name, OFappgen_Demit__types */
/* clu_operation_name, appgen$emit_types */
int OFappgen_Demit__types(LVgen, LVoutst)
     object LVgen;
     object LVoutst;
{
  object LVtiddefs= 0;
  object LVnr__vars= 0;
  object LVdb= 0;
  int t1, t2, t3, t4, t5, t6, t7, t8, t9;
  /* begin body */
  OFarray_Dnew();
  LVtiddefs = retval_area[0];
    {
      object LVvar= 0;
      for (t1 = OMrecord_Dget(8, LVgen), t2 = OMarray_Dlow(t1), t3 = OMarray_Dhigh(t1);
           t2 <= t3;
           t2++)
        {
	  LVvar = OMarray_Dfetch(t1, t2);
	    {
	      OFarray_Dcreate(0);
	      t4 = OFrecord_D__alloc(2);
	      OMrecord_Dset(1, t4, retval_area[0]);
	      OMrecord_Dset(2, t4, LVvar);
	      OMarray_Daddh(LVtiddefs, t4);
	    }
        }
    }
  LVnr__vars = OMarray_Dsize(OMrecord_Dget(8, LVgen));
    {
      object LVinst= 0;
      for (t1 = OMrecord_Dget(1, LVgen), t2 = OMarray_Dlow(t1), t3 = OMarray_Dhigh(t1);
           t2 <= t3;
           t2++)
        {
	  LVinst = OMarray_Dfetch(t1, t2);
	    {
	      object LVtypes= 0;
	      if (OFappinst_Dget__types(LVinst) == SIG)
	        {
		  goto except0;
	        }
	      LVtypes = retval_area[0];
	        {
		  object LVi= 0;
		  for (t4 = 1, t5 = LVnr__vars; t4 <= t5; t4++)
		    {
		      LVi = t4;
		        {
			  if (OMarray_Dbounds(LVtiddefs, LVi))
			    {
			      signame = SLBOUNDS;
			      goto except0;
			    }
			  t6 = OMrecord_Dget(1, OMarray_Dfetch(LVtiddefs, LVi));
			  if (OMarray_Dbounds(LVtypes, LVi))
			    {
			      signame = SLBOUNDS;
			      goto except0;
			    }
			  if (AFtype__id(OMarray_Dfetch(LVtypes, LVi)) == SIG)
			    {
			      goto except0;
			    }
			  OMarray_Daddh(t6, retval_area[0]);
		        }
		    }
	        }
	    }
        }
    }
    {
      object LVt= 0;
      for (t1 = LVtiddefs, t2 = OMarray_Dlow(t1), t3 = OMarray_Dhigh(t1);
           t2 <= t3;
           t2++)
        {
	  LVt = OMarray_Dfetch(t1, t2);
	    {
	      if (OFstream_Dputs(LVoutst, ((string) &str12)) == SIG)
	        {
		  goto except0;
	        }
	      if (OFstream_Dputs(LVoutst, OMrecord_Dget(2, LVt)) == SIG)
	        {
		  goto except0;
	        }
	      if (OFstream_Dputs(LVoutst, ((string) &str13)) == SIG)
	        {
		  goto except0;
	        }
	        {
		  object LVtid= 0;
		  for (t4 = OMrecord_Dget(1, LVt), t5 = OMarray_Dlow(t4), t6 = OMarray_Dhigh(t4);
		       t5 <= t6;
		       t5++)
		    {
		      LVtid = OMarray_Dfetch(t4, t5);
		        {
			  OFint_Dunparse(LVtid);
			  if (OFstream_Dputs(LVoutst, retval_area[0]) == SIG)
			    {
			      goto except0;
			    }
			  if (OFstream_Dputs(LVoutst, ((string) &str14)) == SIG)
			    {
			      goto except0;
			    }
		        }
		    }
	        }
	      if (OFstream_Dputl(LVoutst, ((string) &str15)) == SIG)
	        {
		  goto except0;
	        }
	    }
        }
    }
  if (OFdb__env_Dget() == SIG)
    {
      goto except0;
    }
  LVdb = retval_area[0];
  if (OFdb__env_Dget__debug(LVdb) == SIG)
    {
      goto except0;
    }
  if (retval_area[0])
    {
        {
	  object LVt= 0;
	  for (t1 = LVtiddefs, t2 = OMarray_Dlow(t1), t3 = OMarray_Dhigh(t1);
	       t2 <= t3;
	       t2++)
	    {
	      LVt = OMarray_Dfetch(t1, t2);
	        {
		    {
		      object LVtid= 0;
		      for (t4 = OMrecord_Dget(1, LVt), t5 = OMarray_Dlow(t4), t6 = OMarray_Dhigh(t4);
		           t5 <= t6;
		           t5++)
		        {
			  LVtid = OMarray_Dfetch(t4, t5);
			    {
			      t7 = OMrecord_Dget(2, LVt);
			      OFint_Dunparse(LVtid);
			      if (OFdb__env_Dtid__info(LVdb, t7, retval_area[0]) == SIG)
			        {
				  goto except0;
			        }
			      t8 = OMstring_Dsize(((string) &str16))
			           + OMstring_Dsize(retval_area[0]);
			      t9 = OFstring_D__predict(t8);
			      OFstring_D__concat(t9, ((string) &str16));
			      OFstring_D__concat(t9, retval_area[0]);
			      if (OFstream_Dputl(LVoutst, t9) == SIG)
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
/* c_function_name, OFappgen_Dset__nr__args */
/* clu_operation_name, appgen$set_nr_args */
int OFappgen_Dset__nr__args(LVgen, LVnr__args)
     object LVgen;
     object LVnr__args;
{
  /* begin body */
  OMrecord_Dset(4, LVgen, LVnr__args);
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFappgen_Dget__nr__args */
/* clu_operation_name, appgen$get_nr_args */
int OFappgen_Dget__nr__args(LVgen)
     object LVgen;
{
  /* begin body */
  retval_area[0] = OMrecord_Dget(4, LVgen);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFappgen_Dsimilar */
/* clu_operation_name, appgen$similar */
int OFappgen_Dsimilar(LVgen1, LVgen2)
     object LVgen1;
     object LVgen2;
{
  /* begin body */
  OFrecord_Dequal(LVgen1, LVgen2);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */
