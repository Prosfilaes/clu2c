/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,p_stmt,expr,p_body,p_condition,p_decl_or_assn,p_end,p_env,p_except,p_expr,p_expr_stmt,p_find_a_stmt,p_for,p_forcestmt,p_if,p_ownstmt,p_plist,p_tagcase,p_while,stmt*/
/* param_mod_call,apply,PV1_INp__stmt,p_plist,p_stmt,expr*/
/* param_mod_call,apply,PV2_INp__stmt,p_plist,p_stmt,expr*/
/* depend,p_if,expr,p_body,p_end,p_env,p_expr1*/
/* depend,p_for,p_do,p_env,p_expr1,p_idns_or_decls,p_make_invoke*/
/* depend,p_do,p_body,p_end,p_env*/
/* depend,p_idns_or_decls,idn,p_clist,p_decl,p_env,p_idn,p_type1,typespec*/
/* param_mod_call,apply,PV1_INp__idns__or__decls,p_clist,p_idns_or_decls,idn*/
/* param_mod_call,apply,PV2_INp__idns__or__decls,p_clist,p_idns_or_decls,record[idns:sequence[idn] type_:typespec]*/
/* depend,p_idn,idn,p_env*/
/* depend,p_idn1,idn,p_env,p_idn*/
/* depend,p_decl,idn,p_clist,p_env,p_idn,p_type1,typespec*/
/* param_mod_call,apply,PV1_INp__decl,p_clist,p_decl,idn*/
/* depend,p_tagcase,expr,p_cbody,p_end,p_env,p_expr1,p_list,p_tagarm*/
/* param_mod_call,apply,PV1_INp__tagcase,p_list,p_tagcase,record[body:record[equates:sequence[equate] stmts:sequence[stmt]] line:int tags:sequence[string] var:oneof[decl:record[idns:sequence[idn] type_:typespec] none:null]]*/
/* depend,p_tagarm,p_cbody,p_clist,p_env,p_mdecl,p_name*/
/* param_mod_call,apply,PV1_INp__tagarm,p_clist,p_tagarm,string*/

#include <clu2c.h>

extern object	PV1_INp__idns__or__decls;
extern object	PV2_INp__idns__or__decls;
extern int	AFp__tagarm();
extern int	AFp__decl();
extern int	AFp__name();
extern int	AFp__expr();
extern object	PV1_INp__tagarm;
extern object	PV1_INp__decl;
extern object	PV1_INp__stmt;
extern object	PV2_INp__stmt;
extern object	PV1_INp__tagcase;
extern int	AFp__idn();

static STRING_REP(10) str1 = {10, {'e', 'x', 'p', 'r', 'e', 's', 's', 'i', 'o', 'n'}};
static STRING_REP(26) str2 = {26, {'E', 'N', 'D', ' ', 'o', 'f', ' ', 'B', 'E', 'G', 'I', 'N', '-', 'E', 'N', 'D', ' ', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'}};
static STRING_REP(4) str3 = {4, {'n', 'o', 'n', 'e'}};
static STRING_REP(30) str4 = {30, {'o', 'p', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'o', 'r', ' ', '(', ' ', 's', 't', 'a', 'r', 't', 's', ' ', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'}};
static STRING_REP(39) str5 = {39, {'E', 'X', 'C', 'E', 'P', 'T', ' ', 'c', 'l', 'a', 'u', 's', 'e', ' ', 'n', 'o', 't', ' ', 'a', 't', 't', 'a', 'c', 'h', 'e', 'd', ' ', 't', 'o', ' ', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'}};
static STRING_REP(3) str6 = {3, {'b', 'a', 'd'}};
static STRING_REP(20) str7 = {20, {'T', 'H', 'E', 'N', ' ', 'i', 'n', ' ', 'I', 'F', ' ', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'}};
static STRING_REP(19) str8 = {19, {'E', 'N', 'D', ' ', 'o', 'f', ' ', 'I', 'F', ' ', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'}};
static STRING_REP(23) str9 = {23, {'u', 's', 'e', ' ', 'o', 'f', ' ', ':', '=', ' ', 'i', 'n', 's', 't', 'e', 'a', 'd', ' ', 'o', 'f', ' ', 'I', 'N'}};
static STRING_REP(19) str10 = {19, {'I', 'N', ' ', 'i', 'n', ' ', 'F', 'O', 'R', ' ', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'}};
static STRING_REP(28) str11 = {28, {'e', 'x', 'p', 'r', 'e', 's', 's', 'i', 'o', 'n', ' ', 'n', 'o', 't', ' ', 'a', 'n', ' ', 'i', 'n', 'v', 'o', 'c', 'a', 't', 'i', 'o', 'n'}};
static STRING_REP(21) str12 = {21, {'D', 'O', ' ', 'o', 'f', ' ', 'D', 'O', '.', '.', '.', 'E', 'N', 'D', ' ', 'c', 'l', 'a', 'u', 's', 'e'}};
static STRING_REP(22) str13 = {22, {'E', 'N', 'D', ' ', 'o', 'f', ' ', 'D', 'O', '.', '.', '.', 'E', 'N', 'D', ' ', 'c', 'l', 'a', 'u', 's', 'e'}};
static STRING_REP(3) str14 = {3, {'i', 'd', 'n'}};
static STRING_REP(4) str15 = {4, {'d', 'e', 'c', 'l'}};
static STRING_REP(21) str16 = {21, {':', ' ', 't', 'y', 'p', 'e', ' ', 'i', 'n', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'a', 't', 'i', 'o', 'n'}};
static STRING_REP(34) str17 = {34, {'u', 's', 'e', ' ', 'o', 'f', ' ', 'I', 'N', ' ', 'a', 'f', 't', 'e', 'r', ' ', 't', 'a', 'g', 'c', 'a', 's', 'e', ' ', 'e', 'x', 'p', 'r', 'e', 's', 's', 'i', 'o', 'n'}};
static STRING_REP(7) str18 = {7, {'T', 'A', 'G', ' ', 'a', 'r', 'm'}};
static STRING_REP(17) str19 = {17, {':', ' ', 'i', 'n', ' ', 'O', 'T', 'H', 'E', 'R', 'S', ':', ' ', 'b', 'o', 'd', 'y'}};
static STRING_REP(24) str20 = {24, {'E', 'N', 'D', ' ', 'o', 'f', ' ', 'T', 'A', 'G', 'C', 'A', 'S', 'E', ' ', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'}};
static STRING_REP(4) str21 = {4, {'n', 'a', 'm', 'e'}};
static STRING_REP(17) str22 = {17, {':', ' ', 'i', 'n', ' ', 'T', 'A', 'G', '.', '.', '.', ':', ' ', 'b', 'o', 'd', 'y'}};

/* begin module */
/* c_function_name, AFp__stmt */
/* clu_operation_name, p_stmt */
int AFp__stmt(LVe)
     object LVe;
{
  object LVabs= 0;
  object LVl= 0;
  int t1, t2, t3;
  /* begin body */
  if (OFp__env_Dget__peekline(LVe) == SIG)
    {
      goto except0;
    }
  LVl = retval_area[0];
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except1;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 35)
    {
      object LVk= 0;
      LVk = ((oneof) retval_area[0])->value;
        {
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except1;
	    }
	  t2 = ((oneof) LVk)->tag;
	  if (t2 == 6)
	    {
	        {
		  if (AFp__if(LVe) == SIG)
		    {
		      goto except1;
		    }
		  LVabs = retval_area[0];
	        }
	    }
	  else if (t2 == 5)
	    {
	        {
		  if (AFp__for(LVe) == SIG)
		    {
		      goto except1;
		    }
		  LVabs = retval_area[0];
	        }
	    }
	  else if (t2 == 10)
	    {
	        {
		  if (AFp__tagcase(LVe) == SIG)
		    {
		      goto except1;
		    }
		  LVabs = retval_area[0];
	        }
	    }
	  else if (t2 == 11)
	    {
	        {
		  if (AFp__while(LVe) == SIG)
		    {
		      goto except1;
		    }
		  LVabs = retval_area[0];
	        }
	    }
	  else if (t2 == 8)
	    {
	        {
		  object LVopt= 0;
		  t3 = FALSE;
		  if (OFp__env_Din__proc(LVe) == SIG)
		    {
		      goto except1;
		    }
		  if (retval_area[0])
		    {
		      if (OFp__env_Dspecd__vals(LVe) == SIG)
		        {
			  goto except1;
		        }
		      if (retval_area[0])
		        {
			  t3 = TRUE;
		        }
		    }
		  LVopt = OMbool_Dnot(t3);
		  if ((*((proctype)PV1_INp__stmt))(LVe, AFp__expr, LVopt, FALSE, ((string) &str1)) == SIG)
		    {
		      goto except1;
		    }
		  OFoneof_Dmake(15, retval_area[0]);
		  LVabs = retval_area[0];
	        }
	    }
	  else if (t2 == 12)
	    {
	        {
		  object LVopt= 0;
		  if (OFp__env_Din__proc(LVe) == SIG)
		    {
		      goto except1;
		    }
		  if (retval_area[0])
		    {
		      t3 = TRUE;
		    }
		  else
		    {
		      if (OFp__env_Dspecd__vals(LVe) == SIG)
		        {
			  goto except1;
		        }
		      t3 = OMbool_Dnot(retval_area[0]);
		    }
		  LVopt = t3;
		  if ((*((proctype)PV2_INp__stmt))(LVe, AFp__expr, LVopt, FALSE, ((string) &str1)) == SIG)
		    {
		      goto except1;
		    }
		  OFoneof_Dmake(21, retval_area[0]);
		  LVabs = retval_area[0];
	        }
	    }
	  else if (t2 == 9)
	    {
	        {
		  if (AFp__condition(LVe) == SIG)
		    {
		      goto except1;
		    }
		  OFoneof_Dmake(17, retval_area[0]);
		  LVabs = retval_area[0];
	        }
	    }
	  else if (t2 == 4)
	    {
	        {
		  if (AFp__condition(LVe) == SIG)
		    {
		      goto except1;
		    }
		  OFoneof_Dmake(9, retval_area[0]);
		  LVabs = retval_area[0];
	        }
	    }
	  else if (t2 == 2)
	    {
	        {
		  OFoneof_Dmake(4, NIL);
		  LVabs = retval_area[0];
	        }
	    }
	  else if (t2 == 3)
	    {
	        {
		  OFoneof_Dmake(5, NIL);
		  LVabs = retval_area[0];
	        }
	    }
	  else if (t2 == 1)
	    {
	        {
		  if (AFp__body(LVe, 3) == SIG)
		    {
		      goto except1;
		    }
		  OFoneof_Dmake(3, retval_area[0]);
		  LVabs = retval_area[0];
		  if (AFp__end(LVe, ((string) &str2)) == SIG)
		    {
		      goto except1;
		    }
	        }
	    }
	  else if (t2 == 7)
	    {
	        {
		  if (AFp__ownstmt(LVe) == SIG)
		    {
		      goto except1;
		    }
		  LVabs = retval_area[0];
	        }
	    }
        }
    }
  else if (t1 == 17)
    {
        {
	  if (OFp__env_Dpeek(LVe, 2) == SIG)
	    {
	      goto except1;
	    }
	  t2 = ((oneof) retval_area[0])->tag;
	  if (t2 == 3 || t2 == 1 || t2 == 2)
	    {
	        {
		  if (AFp__decl__or__assn(LVe) == SIG)
		    {
		      goto except1;
		    }
		  LVabs = retval_area[0];
	        }
	    }
	  else if (t2 == 11)
	    {
	        {
		  if (OFp__env_Dpeek(LVe, 3) == SIG)
		    {
		      goto except1;
		    }
		  t3 = ((oneof) retval_area[0])->tag;
		  if (t3 == 4)
		    {
		        {
			  signame = ((string) &str3);
			  return(SIG);
		        }
		    }
		  else
		    {
		      if (AFp__decl__or__assn(LVe) == SIG)
		        {
			  goto except1;
		        }
		      LVabs = retval_area[0];
		    }
	        }
	    }
	  else
	    {
	      if (AFp__expr__stmt(LVe) == SIG)
	        {
		  goto except1;
	        }
	      LVabs = retval_area[0];
	    }
        }
    }
  else if (t1 == 15)
    {
      object LVk= 0;
      LVk = ((oneof) retval_area[0])->value;
        {
	  t2 = ((oneof) LVk)->tag;
	  if (t2 == 2)
	    {
	        {
		  if (OFp__env_Dpeek(LVe, 2) == SIG)
		    {
		      goto except1;
		    }
		  t3 = ((oneof) retval_area[0])->tag;
		  if (t3 == 17)
		    {
		        {
			  if (AFp__forcestmt(LVe) == SIG)
			    {
			      goto except1;
			    }
			  LVabs = retval_area[0];
		        }
		    }
		  else
		    {
		      if (AFp__expr__stmt(LVe) == SIG)
		        {
			  goto except1;
		        }
		      LVabs = retval_area[0];
		    }
	        }
	    }
	  else
	    {
	      if (AFp__expr__stmt(LVe) == SIG)
	        {
		  goto except1;
	        }
	      LVabs = retval_area[0];
	    }
        }
    }
  else if (t1 == 38 || t1 == 39 || t1 == 14)
    {
        {
	  if (AFp__expr__stmt(LVe) == SIG)
	    {
	      goto except1;
	    }
	  LVabs = retval_area[0];
        }
    }
  else if (t1 == 24 || t1 == 23 || t1 == 22)
    {
        {
	  if (OFp__env_Derr(LVe, ((string) &str4), 1) == SIG)
	    {
	      goto except1;
	    }
	  if (AFp__expr__stmt(LVe) == SIG)
	    {
	      goto except1;
	    }
	  LVabs = retval_area[0];
        }
    }
  else if (t1 == 12)
    {
        {
	  if (OFp__env_Derr(LVe, ((string) &str5), 1) == SIG)
	    {
	      goto except1;
	    }
	  OFoneof_Dmake(2, NIL);
	  LVabs = retval_area[0];
        }
    }
  else
    {
      if (AFp__find__a__stmt(LVe) == SIG)
        {
	  goto except1;
        }
      if (retval_area[0])
        {
	  OFoneof_Dmake(2, NIL);
	  LVabs = retval_area[0];
        }
      else
        {
	  signame = ((string) &str3);
	  return(SIG);
        }
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, ((string) &str6)))
        {
	  OFoneof_Dmake(2, NIL);
	  LVabs = retval_area[0];
        }
      else
        {
	  goto except0;
        }
    }
  if (OFstmt_Dcreate(LVabs, LVl) == SIG)
    {
      goto except0;
    }
  if (AFp__except(LVe, retval_area[0]) == SIG)
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
/* c_function_name, AFp__if */
/* clu_operation_name, p_if */
int AFp__if(LVe)
     object LVe;
{
  object LVarms= 0;
  object LVelse__= 0;
  int t1;
  /* begin body */
  OFsequence_Dnew();
  LVarms = retval_area[0];
  OFoneof_Dmake(2, NIL);
  LVelse__ = retval_area[0];
  while (TRUE)
    {
        {
	  object LVline= 0;
	  object LVx= 0;
	  object LVbod= 0;
	  if (OFp__env_Dget__peekline(LVe) == SIG)
	    {
	      goto except0;
	    }
	  LVline = retval_area[0];
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
	  if (t1 == 37)
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
	      if (OFp__env_Dassume(LVe, ((string) &str7)) == SIG)
	        {
		  goto except0;
	        }
	    }
	  if (AFp__body(LVe, 0) == SIG)
	    {
	      goto except0;
	    }
	  LVbod = retval_area[0];
	  t1 = OFrecord_D__alloc(3);
	  OMrecord_Dset(1, t1, LVbod);
	  OMrecord_Dset(2, t1, LVline);
	  OMrecord_Dset(3, t1, LVx);
	  OFsequence_Daddh(LVarms, t1);
	  LVarms = retval_area[0];
	  if (OFp__env_Dget__peek1(LVe) == SIG)
	    {
	      goto except0;
	    }
	  t1 = ((oneof) retval_area[0])->tag;
	  if (t1 == 8)
	    {
	        {
		  if (OFp__env_Dnext__token(LVe) == SIG)
		    {
		      goto except0;
		    }
		  continue;
	        }
	    }
	  else if (t1 == 7)
	    {
	        {
		  if (OFp__env_Dnext__token(LVe) == SIG)
		    {
		      goto except0;
		    }
		  if (AFp__body(LVe, 3) == SIG)
		    {
		      goto except0;
		    }
		  OFoneof_Dmake(1, retval_area[0]);
		  LVelse__ = retval_area[0];
	        }
	    }
	  if (AFp__end(LVe, ((string) &str8)) == SIG)
	    {
	      goto except0;
	    }
	  t1 = OFrecord_D__alloc(2);
	  OMrecord_Dset(1, t1, LVarms);
	  OMrecord_Dset(2, t1, LVelse__);
	  OFoneof_Dmake(12, t1);
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
/* c_function_name, AFp__for */
/* clu_operation_name, p_for */
int AFp__for(LVe)
     object LVe;
{
  object LVvars= 0;
  object LVline= 0;
  object LVcall= 0;
  object LVsend= 0;
  object LVbod= 0;
  int t1, t2;
  /* begin body */
  if (OFp__env_Dget__line(LVe) == SIG)
    {
      goto except0;
    }
  LVline = retval_area[0];
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 18)
    {
        {
	  OFsequence_Dnew();
	  OFoneof_Dmake(2, retval_area[0]);
	  LVvars = retval_area[0];
        }
    }
  else
    {
      if (AFp__idns__or__decls(LVe) == SIG)
        {
	  goto except0;
        }
      LVvars = retval_area[0];
    }
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 18)
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
	  if (OFp__env_Derr(LVe, ((string) &str9), 1) == SIG)
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
      if (OFp__env_Dassume(LVe, ((string) &str10)) == SIG)
        {
	  goto except0;
        }
    }
  if (AFp__expr1(LVe) == SIG)
    {
      goto except0;
    }
  if (AFp__make__invoke(LVe, retval_area[0], ((string) &str11)) == SIG)
    {
      goto except0;
    }
  LVcall = retval_area[0];
  LVsend = retval_area[1];
  if (AFp__do(LVe) == SIG)
    {
      goto except0;
    }
  LVbod = retval_area[0];
  OFsequence_Dnew();
  t1 = retval_area[0];
  if (OFp__env_Dget__line(LVe) == SIG)
    {
      goto except0;
    }
  t2 = OFrecord_D__alloc(8);
  OMrecord_Dset(1, t2, t1);
  OMrecord_Dset(2, t2, LVbod);
  OMrecord_Dset(3, t2, LVcall);
  OMrecord_Dset(4, t2, retval_area[0]);
  OMrecord_Dset(5, t2, LVsend);
  OMrecord_Dset(6, t2, LVline);
  OMrecord_Dset(7, t2, LVvars);
  OMrecord_Dset(8, t2, FALSE);
  OFoneof_Dmake(10, t2);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFp__do */
/* clu_operation_name, p_do */
int AFp__do(LVe)
     object LVe;
{
  object LVbod= 0;
  int t1;
  /* begin body */
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 5)
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
      if (OFp__env_Dassume(LVe, ((string) &str12)) == SIG)
        {
	  goto except0;
        }
    }
  if (AFp__body(LVe, 3) == SIG)
    {
      goto except0;
    }
  LVbod = retval_area[0];
  if (AFp__end(LVe, ((string) &str13)) == SIG)
    {
      goto except0;
    }
  retval_area[0] = LVbod;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFp__idns__or__decls */
/* clu_operation_name, p_idns_or_decls */
int AFp__idns__or__decls(LVe)
     object LVe;
{
  object LVidns= 0;
  int t1, t2;
  /* begin body */
  if ((*((proctype)PV1_INp__idns__or__decls))(LVe, AFp__idn, ((string) &str14)) == SIG)
    {
      goto except0;
    }
  LVidns = retval_area[0];
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 2)
    {
        {
	  object LVt= 0;
	  object LVdecls= 0;
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (AFp__type1(LVe) == SIG)
	    {
	      goto except0;
	    }
	  LVt = retval_area[0];
	  if (OFp__env_Dget__peek1(LVe) == SIG)
	    {
	      goto except0;
	    }
	  t2 = ((oneof) retval_area[0])->tag;
	  if (t2 == 3)
	    {
	        {
		  if (OFp__env_Dnext__token(LVe) == SIG)
		    {
		      goto except0;
		    }
		  if ((*((proctype)PV2_INp__idns__or__decls))(LVe, AFp__decl, ((string) &str15)) == SIG)
		    {
		      goto except0;
		    }
		  LVdecls = retval_area[0];
	        }
	    }
	  else
	    {
	      OFsequence_Dnew();
	      LVdecls = retval_area[0];
	    }
	  t2 = OFrecord_D__alloc(2);
	  OMrecord_Dset(1, t2, LVidns);
	  OMrecord_Dset(2, t2, LVt);
	  OFsequence_Daddl(LVdecls, t2);
	  LVdecls = retval_area[0];
	  OFoneof_Dmake(1, LVdecls);
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else
    {
      OFoneof_Dmake(2, LVidns);
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
/* end module */

/* begin module */
/* c_function_name, AFp__idn */
/* clu_operation_name, p_idn */
int AFp__idn(LVe)
     object LVe;
{
  int t1;
  /* begin body */
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 17)
    {
      object LVk= 0;
      LVk = ((oneof) retval_area[0])->value;
        {
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = LVk;
	  return RET;
        }
    }
  else
    {
      signame = ((string) &str3);
      return(SIG);
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
/* c_function_name, AFp__idn1 */
/* clu_operation_name, p_idn1 */
#define INV_TOP 2
#define WORK_SIZE 2
int AFp__idn1(init, ivarp, LVe)
     bool init;
     int **ivarp;
     object LVe;
{
  if (init)
    {
      *ivarp = (int*) malloc(WORK_SIZE*sizeof(int));
      (*ivarp)[1] = LVe;
    }
  else
    {
      switch ((*ivarp)[0])
  	{
  	  case 1: goto yield1;
  	}
    }
  /* begin body */
  if (AFp__idn((*ivarp)[1]) == SIG)
    {
      goto except1;
    }
  retval_area[0] = retval_area[0];
  (*ivarp)[0] = 1;
  return YIELD;
yield1:
  NO_OPERATION;
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, ((string) &str3)))
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
#undef INV_TOP
#undef WORK_SIZE
/* end module */

/* begin module */
/* c_function_name, AFp__decl */
/* clu_operation_name, p_decl */
int AFp__decl(LVe)
     object LVe;
{
  object LVidns= 0;
  object LVt= 0;
  int t1;
  /* begin body */
  if ((*((proctype)PV1_INp__decl))(LVe, AFp__idn, ((string) &str14)) == SIG)
    {
      goto except0;
    }
  LVidns = retval_area[0];
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
	  if (AFp__type1(LVe) == SIG)
	    {
	      goto except0;
	    }
	  LVt = retval_area[0];
        }
    }
  else
    {
      if (OFp__env_Dassume(LVe, ((string) &str16)) == SIG)
        {
	  goto except0;
        }
      if (OFp__env_Dget__unknown__type(LVe) == SIG)
        {
	  goto except0;
        }
      LVt = retval_area[0];
    }
  t1 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t1, LVidns);
  OMrecord_Dset(2, t1, LVt);
  retval_area[0] = t1;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFp__tagcase */
/* clu_operation_name, p_tagcase */
int AFp__tagcase(LVe)
     object LVe;
{
  object LVobj= 0;
  object LVarms= 0;
  object LVtst= 0;
  object LVabs= 0;
  int t1;
  /* begin body */
  if (AFp__expr1(LVe) == SIG)
    {
      goto except0;
    }
  LVobj = retval_area[0];
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 18)
    {
        {
	  if (OFp__env_Derr(LVe, ((string) &str17), 1) == SIG)
	    {
	      goto except0;
	    }
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
        }
    }
  if ((*((proctype)PV1_INp__tagcase))(LVe, AFp__tagarm, FALSE, ((string) &str18)) == SIG)
    {
      goto except0;
    }
  LVarms = retval_area[0];
  OFoneof_Dmake(2, NIL);
  t1 = OFrecord_D__alloc(3);
  OMrecord_Dset(1, t1, LVarms);
  OMrecord_Dset(2, t1, LVobj);
  OMrecord_Dset(3, t1, retval_area[0]);
  LVtst = t1;
  OFoneof_Dmake(19, LVtst);
  LVabs = retval_area[0];
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 25)
    {
        {
	  if (OFp__env_Dnext__token(LVe) == SIG)
	    {
	      goto except0;
	    }
	  if (AFp__cbody(LVe, 3, ((string) &str19)) == SIG)
	    {
	      goto except0;
	    }
	  OFoneof_Dmake(1, retval_area[0]);
	  OMrecord_Dset(3, LVtst, retval_area[0]);
        }
    }
  if (AFp__end(LVe, ((string) &str20)) == SIG)
    {
      goto except0;
    }
  retval_area[0] = LVabs;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFp__tagarm */
/* clu_operation_name, p_tagarm */
int AFp__tagarm(LVe)
     object LVe;
{
  object LVline= 0;
  object LVtags= 0;
  object LVvar= 0;
  object LVbod= 0;
  int t1;
  /* begin body */
  if (OFp__env_Dget__peek1(LVe) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 36)
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
      signame = ((string) &str3);
      return(SIG);
    }
  if (OFp__env_Dget__line(LVe) == SIG)
    {
      goto except0;
    }
  LVline = retval_area[0];
  if ((*((proctype)PV1_INp__tagarm))(LVe, AFp__name, ((string) &str21)) == SIG)
    {
      goto except0;
    }
  LVtags = retval_area[0];
  if (AFp__mdecl(LVe) == SIG)
    {
      goto except0;
    }
  LVvar = retval_area[0];
  if (AFp__cbody(LVe, 1, ((string) &str22)) == SIG)
    {
      goto except0;
    }
  LVbod = retval_area[0];
  t1 = OFrecord_D__alloc(4);
  OMrecord_Dset(1, t1, LVbod);
  OMrecord_Dset(2, t1, LVline);
  OMrecord_Dset(3, t1, LVtags);
  OMrecord_Dset(4, t1, LVvar);
  retval_area[0] = t1;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */
