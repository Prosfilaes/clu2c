/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,p_decl_or_assn,p_assn_rhs,p_env,p_idns_or_decls*/
/* depend,p_assn_rhs,expr,p_clist,p_env,p_expr*/
/* param_mod_call,apply,PV1_INp__assn__rhs,p_clist,p_assn_rhs,expr*/
/* depend,p_condition,expr,p_env,p_expr,p_name,p_plist*/
/* param_mod_call,apply,PV1_INp__condition,p_plist,p_condition,expr*/
/* depend,p_while,expr,p_do,p_env,p_expr1*/
/* depend,p_expr_stmt,expr,p_env,p_expr1*/
/* depend,p_make_invoke,expr,p_env*/
/* depend,p_except,p_cbody,p_clist,p_end,p_env,p_list,p_mdecl,p_name,p_semi,p_whenarm,stmt*/
/* param_mod_call,apply,PV1_INp__except,p_clist,p_except,string*/
/* param_mod_call,apply,PV2_INp__except,p_list,p_except,record[body:record[equates:sequence[equate] stmts:sequence[stmt]] line:int names:sequence[string] vars:oneof[decls:sequence[record[idns:sequence[idn] type_:typespec]] none:null star:null]]*/
/* depend,p_whenarm,p_cbody,p_clist,p_env,p_name,p_whendecl*/
/* param_mod_call,apply,PV1_INp__whenarm,p_clist,p_whenarm,string*/
/* depend,p_mdecl,p_decl,p_env*/
/* depend,p_cbody,p_body,p_env*/
/* depend,p_body,equate,p_env,p_equate,p_slist,p_stmt,stmt*/
/* param_mod_call,apply,PV1_INp__body,p_slist,p_body,equate*/
/* param_mod_call,apply,PV2_INp__body,p_slist,p_body,stmt*/
/* depend,p_whendecl,p_clist,p_decl,p_env*/
/* param_mod_call,apply,PV1_INp__whendecl,p_clist,p_whendecl,record[idns:sequence[idn] type_:typespec]*/
/* param_mod_call,apply,PV2_INp__whendecl,p_clist,p_whendecl,record[idns:sequence[idn] type_:typespec]*/
/* depend,p_forcestmt,expr,idn,p_env,p_expr1,p_idn,p_where*/
/* depend,p_ownstmt,p_env,p_owninit*/
/* depend,p_owninit,expr,p_clist,p_decl,p_env,p_expr1*/
/* param_mod_call,apply,PV1_INp__owninit,p_clist,p_owninit,record[idns:sequence[idn] type_:typespec]*/
/* depend,p_end,idn,p_env*/
/* depend,p_find_a_stmt,p_env*/

#include <clu2c.h>

extern object	PV1_INp__owninit;
extern int	AFp__equate();
extern object	PV1_INp__whendecl;
extern object	PV2_INp__whendecl;
extern int	AFp__decl();
extern int	AFp__name();
extern int	AFp__expr();
extern int	AFp__stmt();
extern object	PV1_INp__except;
extern object	PV2_INp__except;
extern int	AFp__whenarm();
extern object	PV1_INp__body;
extern object	PV2_INp__body;
extern object	PV1_INp__assn__rhs;
extern object	PV1_INp__condition;
extern object	PV1_INp__whenarm;

static STRING_REP(22) str1 = {22, {'u', 's', 'e', ' ', 'o', 'f', ' ', '=', ' ', 'i', 'n', 's', 't', 'e', 'a', 'd', ' ', 'o', 'f', ' ', ':', '='}};
static STRING_REP(21) str2 = {21, {':', ' ', 't', 'y', 'p', 'e', ' ', 'i', 'n', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'a', 't', 'i', 'o', 'n'}};
static STRING_REP(32) str3 = {32, {':', '=', ' ', 'i', 'n', 'v', 'o', 'c', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'a', 't', 'i', 'o', 'n', 's'}};
static STRING_REP(10) str4 = {10, {'e', 'x', 'p', 'r', 'e', 's', 's', 'i', 'o', 'n'}};
static STRING_REP(60) str5 = {60, {'o', 'n', 'l', 'y', ' ', '1', ' ', 'e', 'x', 'p', 'r', 'e', 's', 's', 'i', 'o', 'n', ' ', 'a', 'l', 'l', 'o', 'w', 'e', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', ':', '=', ' ', 'i', 'n', ' ', 'a', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'a', 't', 'i', 'o', 'n'}};
static STRING_REP(4) str6 = {4, {'n', 'o', 'n', 'e'}};
static STRING_REP(21) str7 = {21, {'e', 'x', 'c', 'e', 'p', 't', 'i', 'o', 'n', 'a', 'l', ' ', 'c', 'o', 'n', 'd', 'i', 't', 'i', 'o', 'n'}};
static STRING_REP(3) str8 = {3, {'b', 'a', 'd'}};
static STRING_REP(28) str9 = {28, {'e', 'x', 'p', 'r', 'e', 's', 's', 'i', 'o', 'n', ' ', 'u', 's', 'e', 'd', ' ', 'a', 's', ' ', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'}};
static STRING_REP(4) str10 = {4, {'n', 'a', 'm', 'e'}};
static STRING_REP(8) str11 = {8, {'W', 'H', 'E', 'N', ' ', 'a', 'r', 'm'}};
static STRING_REP(20) str12 = {20, {':', ' ', 'i', 'n', ' ', 'O', 'T', 'H', 'E', 'R', 'S', '.', '.', '.', ':', ' ', 'b', 'o', 'd', 'y'}};
static STRING_REP(23) str13 = {23, {'E', 'N', 'D', ' ', 'o', 'f', ' ', 'E', 'X', 'C', 'E', 'P', 'T', ' ', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'}};
static STRING_REP(18) str14 = {18, {':', ' ', 'i', 'n', ' ', 'W', 'H', 'E', 'N', '.', '.', '.', ':', ' ', 'b', 'o', 'd', 'y'}};
static STRING_REP(26) str15 = {26, {'m', 'o', 'r', 'e', ' ', 't', 'h', 'a', 'n', ' ', 'o', 'n', 'e', ' ', 'i', 'd', 'n', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'e', 'd'}};
static STRING_REP(16) str16 = {16, {')', ' ', 'i', 'n', ' ', '(', 'i', 'd', 'n', ':', ' ', 't', 'y', 'p', 'e', ')'}};
static STRING_REP(3) str17 = {3, {'m', 'u', 'l'}};
static STRING_REP(11) str18 = {11, {'d', 'e', 'c', 'l', 'a', 'r', 'a', 't', 'i', 'o', 'n'}};
static STRING_REP(30) str19 = {30, {')', ' ', 'i', 'n', ' ', '(', 'd', 'e', 'c', 'l', 'a', 'r', 'a', 't', 'i', 'o', 'n', '_', 'l', 'i', 's', 't', ')', ' ', 'o', 'r', ' ', '(', '*', ')'}};
static STRING_REP(20) str20 = {20, {':', ' ', 'i', 'n', ' ', 'F', 'O', 'R', 'C', 'E', ' ', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'}};
static STRING_REP(28) str21 = {28, {'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', ' ', 'i', 'n', ' ', 'F', 'O', 'R', 'C', 'E', ' ', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'}};
static STRING_REP(22) str22 = {22, {'u', 's', 'e', ' ', 'o', 'f', ' ', ':', '=', ' ', 'i', 'n', 's', 't', 'e', 'a', 'd', ' ', 'o', 'f', ' ', '='}};
static STRING_REP(20) str23 = {20, {'=', ' ', 'i', 'n', ' ', 'F', 'O', 'R', 'C', 'E', ' ', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'}};
static STRING_REP(28) str24 = {28, {'i', 'l', 'l', 'e', 'g', 'a', 'l', ' ', 'u', 's', 'e', ' ', 'o', 'f', ' ', 'O', 'W', 'N', ' ', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'}};
static STRING_REP(31) str25 = {31, {'i', 'n', 'i', 't', 'i', 'a', 'l', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', ' ', 'O', 'W', 'N', ' ', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'}};
static STRING_REP(23) str26 = {23, {'l', 'o', 'o', 'k', 'i', 'n', 'g', ' ', 'f', 'o', 'r', ' ', 'a', ' ', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'}};
static STRING_REP(28) str27 = {28, {'r', 'e', 's', 'u', 'm', 'i', 'n', 'g', ' ', 'p', 'a', 'r', 's', 'e', ' ', 'a', 't', ' ', 't', 'h', 'i', 's', ' ', 'p', 'o', 'i', 'n', 't'}};

/* begin module */
/* c_function_name, AFp__decl__or__assn */
/* clu_operation_name, p_decl_or_assn */
int AFp__decl__or__assn(LVe)
     object LVe;
{
  object LVvars= 0;
  int t1, t2, t3;
  /* begin body */
  if (AFp__idns__or__decls(LVe) == SIG)
    {
      goto except0;
    }
  LVvars = retval_area[0];
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 1)
    {
        {
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (AFp__assn__rhs(LVe, LVvars) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else if (t1 == 11)
    {
        {
	  if (OFp__env_Derr(LVe, ((string) &str1), 1) == SIG)
	    {
	      goto except0;
	    }
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (AFp__assn__rhs(LVe, LVvars) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  t1 = ((oneof) LVvars)->tag;
  if (t1 == 2)
    {
      object LVidns= 0;
      LVidns = ((oneof) LVvars)->value;
        {
	  if (OFp__env_Dassume(LVe, ((string) &str2)) == SIG)
	    {
	      goto except0;
	    }
	  if (OFp__env_Dget__unknown__type(LVe) == SIG)
	    {
	      goto except0;
	    }
	  t2 = OFrecord_D__alloc(2);
	  OMrecord_Dset(1, t2, LVidns);
	  OMrecord_Dset(2, t2, retval_area[0]);
	  OFoneof_Dmake(6, t2);
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else if (t1 == 1)
    {
      object LVdecls= 0;
      LVdecls = ((oneof) LVvars)->value;
        {
	  if (OMint_Dequal(OMsequence_Dsize(LVdecls), 1))
	    {
	      if (OMsequence_Dempty(LVdecls))
	        {
		  signame = SLBOUNDS;
		  goto except0;
	        }
	      OFoneof_Dmake(6, OMsequence_Dbottom(LVdecls));
	      retval_area[0] = retval_area[0];
	      return RET;
	    }
	  else
	    {
	      if (OFp__env_Dassume(LVe, ((string) &str3)) == SIG)
	        {
		  goto except0;
	        }
	      OFsequence_Dnew();
	      t2 = retval_area[0];
	      if (OFp__env_Dget__bad__expr(LVe) == SIG)
	        {
		  goto except0;
	        }
	      t3 = OFrecord_D__alloc(3);
	      OMrecord_Dset(1, t3, t2);
	      OMrecord_Dset(2, t3, LVdecls);
	      OMrecord_Dset(3, t3, retval_area[0]);
	      OFoneof_Dmake(7, t3);
	      retval_area[0] = retval_area[0];
	      return RET;
	    }
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
/* c_function_name, AFp__assn__rhs */
/* clu_operation_name, p_assn_rhs */
int AFp__assn__rhs(LVe, LVvars)
     object LVe;
     object LVvars;
{
  object LVexprs= 0;
  int t1, t2;
  /* begin body */
  if ((*((proctype)PV1_INp__assn__rhs))(LVe, AFp__expr, ((string) &str4)) == SIG)
    {
      goto except0;
    }
  LVexprs = retval_area[0];
  t1 = ((oneof) LVvars)->tag;
  if (t1 == 2)
    {
      object LVidns= 0;
      LVidns = ((oneof) LVvars)->value;
        {
	  OFsequence_Dnew();
	  t2 = OFrecord_D__alloc(3);
	  OMrecord_Dset(1, t2, retval_area[0]);
	  OMrecord_Dset(2, t2, LVidns);
	  OMrecord_Dset(3, t2, LVexprs);
	  OFoneof_Dmake(1, t2);
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else if (t1 == 1)
    {
      object LVdecls= 0;
      LVdecls = ((oneof) LVvars)->value;
        {
	  object LVx= 0;
	  if (OMint_Dequal(OMsequence_Dsize(LVexprs), 1))
	    {
	      if (OMsequence_Dempty(LVexprs))
	        {
		  signame = SLBOUNDS;
		  goto except0;
	        }
	      LVx = OMsequence_Dbottom(LVexprs);
	    }
	  else
	    {
	      if (OFp__env_Derr(LVe, ((string) &str5), 1) == SIG)
	        {
		  goto except0;
	        }
	      if (OFp__env_Dget__bad__expr(LVe) == SIG)
	        {
		  goto except0;
	        }
	      LVx = retval_area[0];
	    }
	  OFsequence_Dnew();
	  t2 = OFrecord_D__alloc(3);
	  OMrecord_Dset(1, t2, retval_area[0]);
	  OMrecord_Dset(2, t2, LVdecls);
	  OMrecord_Dset(3, t2, LVx);
	  OFoneof_Dmake(7, t2);
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
/* c_function_name, AFp__condition */
/* clu_operation_name, p_condition */
int AFp__condition(LVe)
     object LVe;
{
  object LVn= 0;
  object LVargs= 0;
  int t1;
  /* begin body */
  if (AFp__name(LVe) == SIG)
    {
      goto except1;
    }
  LVn = retval_area[0];
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, ((string) &str6)))
        {
	  if (OFp__env_Dassume(LVe, ((string) &str7)) == SIG)
	    {
	      goto except0;
	    }
	  signame = ((string) &str8);
	  return(SIG);
        }
      else
        {
	  goto except0;
        }
    }
  if ((*((proctype)PV1_INp__condition))(LVe, AFp__expr, TRUE, FALSE, ((string) &str4)) == SIG)
    {
      goto except0;
    }
  LVargs = retval_area[0];
  t1 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t1, LVargs);
  OMrecord_Dset(2, t1, LVn);
  retval_area[0] = t1;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFp__while */
/* clu_operation_name, p_while */
int AFp__while(LVe)
     object LVe;
{
  object LVline= 0;
  object LVtest= 0;
  object LVbod= 0;
  int t1;
  /* begin body */
  if (OFp__env_Dget__line(LVe) == SIG)
    {
      goto except0;
    }
  LVline = retval_area[0];
  if (AFp__expr1(LVe) == SIG)
    {
      goto except0;
    }
  LVtest = retval_area[0];
  if (AFp__do(LVe) == SIG)
    {
      goto except0;
    }
  LVbod = retval_area[0];
  if (OFp__env_Dget__line(LVe) == SIG)
    {
      goto except0;
    }
  t1 = OFrecord_D__alloc(4);
  OMrecord_Dset(1, t1, LVbod);
  OMrecord_Dset(2, t1, retval_area[0]);
  OMrecord_Dset(3, t1, LVline);
  OMrecord_Dset(4, t1, LVtest);
  OFoneof_Dmake(20, t1);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFp__expr__stmt */
/* clu_operation_name, p_expr_stmt */
int AFp__expr__stmt(LVe)
     object LVe;
{
  object LVx= 0;
  int t1, t2, t3, t4, t5;
  /* begin body */
  if (AFp__expr1(LVe) == SIG)
    {
      goto except0;
    }
  LVx = retval_area[0];
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 1)
    {
        {
	  object LVright= 0;
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (AFp__expr1(LVe) == SIG)
	    {
	      goto except0;
	    }
	  LVright = retval_area[0];
	  t2 = OFrecord_D__alloc(2);
	  OMrecord_Dset(1, t2, LVx);
	  OMrecord_Dset(2, t2, LVright);
	  OFoneof_Dmake(18, t2);
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else
    {
      if (OFexpr_Dget__abs(LVx) == SIG)
        {
	  goto except0;
        }
      t2 = ((oneof) retval_area[0])->tag;
      if (t2 == 17)
        {
	  object LVabs= 0;
	  LVabs = ((oneof) retval_area[0])->value;
	    {
	      OFoneof_Dmake(13, LVabs);
	      retval_area[0] = retval_area[0];
	      return RET;
	    }
        }
      else if (t2 == 25)
        {
	  object LVabs= 0;
	  LVabs = ((oneof) retval_area[0])->value;
	    {
	      OFoneof_Dmake(16, LVabs);
	      retval_area[0] = retval_area[0];
	      return RET;
	    }
        }
      else
        {
	  if (OFp__env_Derr(LVe, ((string) &str9), 1) == SIG)
	    {
	      goto except0;
	    }
	  if (OFp__env_Dget__bad__expr(LVe) == SIG)
	    {
	      goto except0;
	    }
	  t3 = retval_area[0];
	  OFsequence_Dnew();
	  t4 = retval_area[0];
	  if (OFp__env_Dget__line(LVe) == SIG)
	    {
	      goto except0;
	    }
	  t5 = OFrecord_D__alloc(3);
	  OMrecord_Dset(1, t5, t3);
	  OMrecord_Dset(2, t5, t4);
	  OMrecord_Dset(3, t5, retval_area[0]);
	  OFoneof_Dmake(13, t5);
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
/* c_function_name, AFp__make__invoke */
/* clu_operation_name, p_make_invoke */
int AFp__make__invoke(LVe, LVx, LVwhy)
     object LVe;
     object LVx;
     object LVwhy;
{
  int t1, t2, t3, t4, t5, t6, t7;
  /* begin body */
  if (OFexpr_Dget__abs(LVx) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 17)
    {
      object LVabs= 0;
      LVabs = ((oneof) retval_area[0])->value;
        {
	  OFoneof_Dmake(1, NIL);
	  t2 = LVabs;
	  t3 = retval_area[0];
	  retval_area[0] = t2;
	  retval_area[1] = t3;
	  return RET;
        }
    }
  else if (t1 == 25)
    {
      object LVabs= 0;
      LVabs = ((oneof) retval_area[0])->value;
        {
	  if (OFp__env_Dget__bad__expr(LVe) == SIG)
	    {
	      goto except0;
	    }
	  t2 = retval_area[0];
	  OFsequence_Dnew();
	  t3 = retval_area[0];
	  if (OFp__env_Dget__line(LVe) == SIG)
	    {
	      goto except0;
	    }
	  t4 = OFrecord_D__alloc(3);
	  OMrecord_Dset(1, t4, t2);
	  OMrecord_Dset(2, t4, t3);
	  OMrecord_Dset(3, t4, retval_area[0]);
	  t5 = t4;
	  OFoneof_Dmake(2, LVabs);
	  t6 = t5;
	  t7 = retval_area[0];
	  retval_area[0] = t6;
	  retval_area[1] = t7;
	  return RET;
        }
    }
  else
    {
      if (OFp__env_Derr(LVe, LVwhy, 1) == SIG)
        {
	  goto except0;
        }
      if (OFp__env_Dget__bad__expr(LVe) == SIG)
        {
	  goto except0;
        }
      t2 = retval_area[0];
      OFsequence_Dnew();
      t3 = retval_area[0];
      if (OFp__env_Dget__line(LVe) == SIG)
        {
	  goto except0;
        }
      t4 = OFrecord_D__alloc(3);
      OMrecord_Dset(1, t4, t2);
      OMrecord_Dset(2, t4, t3);
      OMrecord_Dset(3, t4, retval_area[0]);
      t5 = t4;
      OFoneof_Dmake(1, NIL);
      t6 = t5;
      t7 = retval_area[0];
      retval_area[0] = t6;
      retval_area[1] = t7;
      return RET;
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
/* c_function_name, AFp__except */
/* clu_operation_name, p_except */
int AFp__except(LVe, LVst)
     object LVe;
     object LVst;
{
  int t1, t2;
  /* begin body */
  while (TRUE)
    {
        {
	  object LVl= 0;
	  object LVarms= 0;
	  object LVxs= 0;
	  if (AFp__semi(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (OFp__env_Dget__peek1(LVe) == SIG)
	    {
	      goto except0;
	    }
	  t1 = ((oneof) retval_area[0])->tag;
	  if (t1 == 12)
	    {
	        {
		  if (OFp__env_Dnext__token(LVe) == SIG)
		    {
		      goto except0;
		    }
	        }
	    }
	  else if (t1 == 30)
	    {
	        {
		  object LVl= 0;
		  object LVsigs= 0;
		  object LVrs= 0;
		  if (OFp__env_Dnext__token(LVe) == SIG)
		    {
		      goto except0;
		    }
		  if (OFp__env_Dget__line(LVe) == SIG)
		    {
		      goto except0;
		    }
		  LVl = retval_area[0];
		  if ((*((proctype)PV1_INp__except))(LVe, AFp__name, ((string) &str10)) == SIG)
		    {
		      goto except0;
		    }
		  LVsigs = retval_area[0];
		  t2 = OFrecord_D__alloc(2);
		  OMrecord_Dset(1, t2, LVsigs);
		  OMrecord_Dset(2, t2, LVst);
		  LVrs = t2;
		  OFoneof_Dmake(14, LVrs);
		  if (OFstmt_Dcreate(retval_area[0], LVl) == SIG)
		    {
		      goto except0;
		    }
		  LVst = retval_area[0];
		  continue;
	        }
	    }
	  else
	    {
	      retval_area[0] = LVst;
	      return RET;
	    }
	  if (OFp__env_Dget__line(LVe) == SIG)
	    {
	      goto except0;
	    }
	  LVl = retval_area[0];
	  if ((*((proctype)PV2_INp__except))(LVe, AFp__whenarm, TRUE, ((string) &str11)) == SIG)
	    {
	      goto except0;
	    }
	  LVarms = retval_area[0];
	  OFoneof_Dmake(2, NIL);
	  t1 = OFrecord_D__alloc(3);
	  OMrecord_Dset(1, t1, LVarms);
	  OMrecord_Dset(2, t1, retval_area[0]);
	  OMrecord_Dset(3, t1, LVst);
	  LVxs = t1;
	  OFoneof_Dmake(8, LVxs);
	  if (OFstmt_Dcreate(retval_area[0], LVl) == SIG)
	    {
	      goto except0;
	    }
	  LVst = retval_area[0];
	  if (OFp__env_Dget__peek1(LVe) == SIG)
	    {
	      goto except0;
	    }
	  t1 = ((oneof) retval_area[0])->tag;
	  if (t1 == 25)
	    {
	        {
		  object LVline= 0;
		  object LVdec= 0;
		  object LVbod= 0;
		  if (OFp__env_Dnext__token(LVe) == SIG)
		    {
		      goto except0;
		    }
		  if (OFp__env_Dget__line(LVe) == SIG)
		    {
		      goto except0;
		    }
		  LVline = retval_area[0];
		  if (AFp__mdecl(LVe) == SIG)
		    {
		      goto except0;
		    }
		  LVdec = retval_area[0];
		  if (AFp__cbody(LVe, 3, ((string) &str12)) == SIG)
		    {
		      goto except0;
		    }
		  LVbod = retval_area[0];
		  t2 = OFrecord_D__alloc(3);
		  OMrecord_Dset(1, t2, LVbod);
		  OMrecord_Dset(2, t2, LVdec);
		  OMrecord_Dset(3, t2, LVline);
		  OFoneof_Dmake(1, t2);
		  OMrecord_Dset(2, LVxs, retval_area[0]);
	        }
	    }
	  if (AFp__end(LVe, ((string) &str13)) == SIG)
	    {
	      goto except0;
	    }
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
/* c_function_name, AFp__whenarm */
/* clu_operation_name, p_whenarm */
int AFp__whenarm(LVe)
     object LVe;
{
  object LVline= 0;
  object LVnames= 0;
  object LVvars= 0;
  object LVbod= 0;
  int t1;
  /* begin body */
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 40)
    {
        {
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
        }
    }
  else
    {
      signame = ((string) &str6);
      return(SIG);
    }
  if (OFp__env_Dget__line(LVe) == SIG)
    {
      goto except0;
    }
  LVline = retval_area[0];
  if ((*((proctype)PV1_INp__whenarm))(LVe, AFp__name, ((string) &str10)) == SIG)
    {
      goto except0;
    }
  LVnames = retval_area[0];
  if (AFp__whendecl(LVe) == SIG)
    {
      goto except0;
    }
  LVvars = retval_area[0];
  if (AFp__cbody(LVe, 2, ((string) &str14)) == SIG)
    {
      goto except0;
    }
  LVbod = retval_area[0];
  t1 = OFrecord_D__alloc(4);
  OMrecord_Dset(1, t1, LVbod);
  OMrecord_Dset(2, t1, LVline);
  OMrecord_Dset(3, t1, LVnames);
  OMrecord_Dset(4, t1, LVvars);
  retval_area[0] = t1;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFp__mdecl */
/* clu_operation_name, p_mdecl */
int AFp__mdecl(LVe)
     object LVe;
{
  object LVdec= 0;
  int t1, t2;
  /* begin body */
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 22)
    {
        {
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
        }
    }
  else
    {
      OFoneof_Dmake(2, NIL);
      retval_area[0] = retval_area[0];
      return RET;
    }
  if (AFp__decl(LVe) == SIG)
    {
      goto except0;
    }
  LVdec = retval_area[0];
  if (OMint_Dgt(OMsequence_Dsize(OMrecord_Dget(1, LVdec)), 1))
    {
      if (OFp__env_Derr(LVe, ((string) &str15), 1) == SIG)
        {
	  goto except0;
        }
      t1 = OMrecord_Dget(1, LVdec);
      if (OMsequence_Dempty(t1))
        {
	  signame = SLBOUNDS;
	  goto except0;
        }
      t2 = OFsequence_D__alloc(1);
      OMsequence_D__store(t2, 1, OMsequence_Dbottom(t1));
      OMrecord_Dset(1, LVdec, t2);
    }
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 29)
    {
        {
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
        }
    }
  else
    {
      if (OFp__env_Dassume(LVe, ((string) &str16)) == SIG)
        {
	  goto except0;
        }
    }
  OFoneof_Dmake(1, LVdec);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFp__cbody */
/* clu_operation_name, p_cbody */
int AFp__cbody(LVe, LVkind, LVassume)
     object LVe;
     object LVkind;
     object LVassume;
{
  int t1;
  /* begin body */
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 2)
    {
        {
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
        }
    }
  else
    {
      if (OFp__env_Dassume(LVe, LVassume) == SIG)
        {
	  goto except0;
        }
    }
  if (AFp__body(LVe, LVkind) == SIG)
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
/* c_function_name, AFp__body */
/* clu_operation_name, p_body */
int AFp__body(LVe, LVkind)
     object LVe;
     object LVkind;
{
  object LVequates= 0;
  object LVstmts= 0;
  int t1;
  /* begin body */
  if (OFp__env_Dbegin__body(LVe, LVkind) == SIG)
    {
      goto except0;
    }
  if ((*((proctype)PV1_INp__body))(LVe, AFp__equate) == SIG)
    {
      goto except0;
    }
  LVequates = retval_area[0];
  if ((*((proctype)PV2_INp__body))(LVe, AFp__stmt) == SIG)
    {
      goto except0;
    }
  LVstmts = retval_area[0];
  if (OFp__env_Dend__body(LVe) == SIG)
    {
      goto except0;
    }
  t1 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t1, LVequates);
  OMrecord_Dset(2, t1, LVstmts);
  retval_area[0] = t1;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFp__whendecl */
/* clu_operation_name, p_whendecl */
int AFp__whendecl(LVe)
     object LVe;
{
  object LVdec= 0;
  int t1, t2;
  /* begin body */
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 22)
    {
        {
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
        }
    }
  else
    {
      OFoneof_Dmake(2, NIL);
      retval_area[0] = retval_area[0];
      return RET;
    }
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 24)
    {
      object LVk= 0;
      LVk = ((oneof) retval_area[0])->value;
        {
	  t2 = FALSE;
	  if (OMstring_Dequal(((string) &str17), OMstruct_Dget(2, LVk)))
	    {
	      if (OMbool_Dnot(OMstruct_Dget(1, LVk)))
	        {
		  t2 = TRUE;
	        }
	    }
	  if (t2)
	    {
	      if (OFp__env_Dnext__token(LVe) == SIG)
	        {
		  goto except0;
	        }
	      OFoneof_Dmake(3, NIL);
	      LVdec = retval_area[0];
	    }
	  else
	    {
	      if ((*((proctype)PV1_INp__whendecl))(LVe, AFp__decl, ((string) &str18)) == SIG)
	        {
		  goto except0;
	        }
	      OFoneof_Dmake(1, retval_area[0]);
	      LVdec = retval_area[0];
	    }
        }
    }
  else
    {
      if ((*((proctype)PV2_INp__whendecl))(LVe, AFp__decl, ((string) &str18)) == SIG)
        {
	  goto except0;
        }
      OFoneof_Dmake(1, retval_area[0]);
      LVdec = retval_area[0];
    }
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 29)
    {
        {
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
        }
    }
  else
    {
      if (OFp__env_Dassume(LVe, ((string) &str19)) == SIG)
        {
	  goto except0;
        }
    }
  retval_area[0] = LVdec;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFp__forcestmt */
/* clu_operation_name, p_forcestmt */
int AFp__forcestmt(LVe)
     object LVe;
{
  object LVval= 0;
  object LVtype__= 0;
  object LVx= 0;
  object LVrest= 0;
  int t1;
  /* begin body */
  if (OFp__env_Dnext__token(LVe) == SIG)
    {
      goto except0;
    }
  if (AFp__idn(LVe) == SIG)
    {
      goto except0;
    }
  LVval = retval_area[0];
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 2)
    {
        {
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
        }
    }
  else
    {
      if (OFp__env_Dassume(LVe, ((string) &str20)) == SIG)
        {
	  goto except0;
        }
    }
  if (AFp__idn(LVe) == SIG)
    {
      goto except1;
    }
  LVtype__ = retval_area[0];
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, ((string) &str6)))
        {
	  if (OFp__env_Derr(LVe, ((string) &str21), 2) == SIG)
	    {
	      goto except0;
	    }
	  signame = ((string) &str8);
	  return(SIG);
        }
      else
        {
	  goto except0;
        }
    }
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 11)
    {
        {
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
        }
    }
  else if (t1 == 1)
    {
        {
	  if (OFp__env_Derr(LVe, ((string) &str22), 1) == SIG)
	    {
	      goto except0;
	    }
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
        }
    }
  else
    {
      if (OFp__env_Dassume(LVe, ((string) &str23)) == SIG)
        {
	  goto except0;
        }
    }
  if (AFp__expr1(LVe) == SIG)
    {
      goto except0;
    }
  LVx = retval_area[0];
  if (AFp__where(LVe) == SIG)
    {
      goto except0;
    }
  LVrest = retval_area[0];
  t1 = OFrecord_D__alloc(4);
  OMrecord_Dset(1, t1, LVx);
  OMrecord_Dset(2, t1, LVtype__);
  OMrecord_Dset(3, t1, LVval);
  OMrecord_Dset(4, t1, LVrest);
  OFoneof_Dmake(11, t1);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFp__ownstmt */
/* clu_operation_name, p_ownstmt */
int AFp__ownstmt(LVe)
     object LVe;
{
  /* begin body */
  if (OFp__env_Derr(LVe, ((string) &str24), 2) == SIG)
    {
      goto except0;
    }
  if (AFp__owninit(LVe) == SIG)
    {
      goto except0;
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
/* end module */

/* begin module */
/* c_function_name, AFp__owninit */
/* clu_operation_name, p_owninit */
int AFp__owninit(LVe)
     object LVe;
{
  object LVdecls= 0;
  object LVx= 0;
  int t1;
  /* begin body */
  if ((*((proctype)PV1_INp__owninit))(LVe, AFp__decl, ((string) &str18)) == SIG)
    {
      goto except0;
    }
  LVdecls = retval_area[0];
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 1)
    {
        {
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (AFp__expr1(LVe) == SIG)
	    {
	      goto except0;
	    }
	  LVx = retval_area[0];
        }
    }
  else if (t1 == 11)
    {
        {
	  if (OFp__env_Derr(LVe, ((string) &str1), 1) == SIG)
	    {
	      goto except0;
	    }
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (AFp__expr1(LVe) == SIG)
	    {
	      goto except0;
	    }
	  LVx = retval_area[0];
        }
    }
  else
    {
      if (OMint_Dequal(OMsequence_Dsize(LVdecls), 1))
        {
	  if (OMsequence_Dempty(LVdecls))
	    {
	      signame = SLBOUNDS;
	      goto except0;
	    }
	  OFoneof_Dmake(1, OMsequence_Dbottom(LVdecls));
	  retval_area[0] = retval_area[0];
	  return RET;
        }
      if (OFp__env_Dassume(LVe, ((string) &str25)) == SIG)
        {
	  goto except0;
        }
      if (OFp__env_Dget__bad__expr(LVe) == SIG)
        {
	  goto except0;
        }
      LVx = retval_area[0];
    }
  OFsequence_Dnew();
  t1 = OFrecord_D__alloc(3);
  OMrecord_Dset(1, t1, retval_area[0]);
  OMrecord_Dset(2, t1, LVdecls);
  OMrecord_Dset(3, t1, LVx);
  OFoneof_Dmake(2, t1);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFp__end */
/* clu_operation_name, p_end */
int AFp__end(LVe, LVassume)
     object LVe;
     object LVassume;
{
  int t1, t2, t3;
  /* begin body */
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 9)
    {
        {
        }
    }
  else
    {
      if (OFp__env_Dassume(LVe, LVassume) == SIG)
        {
	  goto except0;
        }
      return RET;
    }
  if (OFp__env_Dpeek(LVe, 2) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 17)
    {
      object LVk= 0;
      LVk = ((oneof) retval_area[0])->value;
        {
	  object LVs= 0;
	  if (OFidn_Dget__str(LVk) == SIG)
	    {
	      goto except0;
	    }
	  LVs = retval_area[0];
	  if (OFp__env_Dget__applystr(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (OMstring_Dequal(LVs, retval_area[0]))
	    {
	      t2 = TRUE;
	    }
	  else
	    {
	      if (OFp__env_Dget__clustr(LVe) == SIG)
	        {
		  goto except0;
	        }
	      t2 = OMstring_Dequal(LVs, retval_area[0]);
	    }
	  if (t2)
	    {
	      if (OFp__env_Dpeek(LVe, 3) == SIG)
	        {
		  goto except0;
	        }
	      t3 = ((oneof) retval_area[0])->tag;
	      if (t3 == 32 || t3 == 17 || t3 == 10)
	        {
		    {
		      if (OFp__env_Dassume(LVe, LVassume) == SIG)
		        {
			  goto except0;
		        }
		      return RET;
		    }
	        }
	    }
        }
    }
  if (OFp__env_Dnext__token(LVe) == SIG)
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
/* c_function_name, AFp__find__a__stmt */
/* clu_operation_name, p_find_a_stmt */
int AFp__find__a__stmt(LVe)
     object LVe;
{
  object LVflushed= 0;
  object LVfound= 0;
  int t1, t2;
  /* begin body */
  LVflushed = FALSE;
  LVfound = FALSE;
  while (TRUE)
    {
        {
	  if (OFp__env_Dget__peek1(LVe) == SIG)
	    {
	      goto except0;
	    }
	  t1 = ((oneof) retval_area[0])->tag;
	  if (t1 == 7 || t1 == 8)
	    {
	        {
		  if (OFp__env_Din__body(LVe, 0) == SIG)
		    {
		      goto except0;
		    }
		  if (retval_area[0])
		    {
		      break;
		    }
	        }
	    }
	  else if (t1 == 36)
	    {
	        {
		  if (OFp__env_Din__body(LVe, 1) == SIG)
		    {
		      goto except0;
		    }
		  if (retval_area[0])
		    {
		      break;
		    }
	        }
	    }
	  else if (t1 == 40)
	    {
	        {
		  if (OFp__env_Din__body(LVe, 2) == SIG)
		    {
		      goto except0;
		    }
		  if (retval_area[0])
		    {
		      break;
		    }
	        }
	    }
	  else if (t1 == 25)
	    {
	        {
		  if (OFp__env_Din__body(LVe, 1) == SIG)
		    {
		      goto except0;
		    }
		  if (retval_area[0])
		    {
		      t2 = TRUE;
		    }
		  else
		    {
		      if (OFp__env_Din__body(LVe, 2) == SIG)
		        {
			  goto except0;
		        }
		      t2 = retval_area[0];
		    }
		  if (t2)
		    {
		      break;
		    }
	        }
	    }
	  else if (t1 == 9 || t1 == 4 || t1 == 31 || t1 == 42 || t1 == 41 || t1 == 19 || t1 == 16 || t1 == 10)
	    {
	        {
		  break;
	        }
	    }
	  else if (t1 == 35 || t1 == 12)
	    {
	        {
		  LVfound = TRUE;
		  break;
	        }
	    }
	  else if (t1 == 32)
	    {
	        {
		  if (OFp__env_Dnext__token(LVe) == SIG)
		    {
		      goto except0;
		    }
		  LVfound = TRUE;
		  break;
	        }
	    }
	  if (OMbool_Dnot(LVflushed))
	    {
	      if (OFp__env_Derr(LVe, ((string) &str26), 2) == SIG)
	        {
		  goto except0;
	        }
	      LVflushed = TRUE;
	    }
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
        }
    }
  if (LVflushed)
    {
      if (OFp__env_Derr(LVe, ((string) &str27), 0) == SIG)
        {
	  goto except0;
        }
    }
  retval_area[0] = LVfound;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */
