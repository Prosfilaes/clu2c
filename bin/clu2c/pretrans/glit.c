/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,null_expr*/
/* depend,bool_expr*/
/* depend,char_expr,char_expr_1,char_expr_2,g_env*/
/* depend,char_expr_1,g_char_unparse,int_hex_unparse*/
/* depend,char_expr_2,g_char_unparse,int_hex_unparse*/
/* depend,int_expr*/
/* depend,real_expr,conv_opfun*/
/* depend,string_expr,g_env,string_expr1*/
/* depend,string_expr1,g_env,hash,string_expr2_1,string_expr2_2,string_expr2_3,table*/
/* param_mod_call,clop,PV1_INstring__expr1,string_expr1,table[string string],create,no_param*/
/* param_mod_call,clop,PV2_INstring__expr1,string_expr1,table[string string],empty,no_param*/
/* param_mod_call,clop,PV3_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV4_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV5_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV6_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV7_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV8_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV9_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV10_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV11_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV12_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV13_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV14_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV15_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV16_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV17_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV18_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV19_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV20_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV21_INstring__expr1,string_expr1,table[string string],bind,no_param*/
/* param_mod_call,clop,PV22_INstring__expr1,string_expr1,table[string string],lookup,no_param*/
/* depend,string_expr2_1,g_char_unparse,g_env*/
/* depend,string_expr2_2,ac_addh_str,char_expr,code_man,g_env,glb*/
/* depend,string_expr2_3,ac_addh_str,char_expr,code_man,g_env,glb*/
/* depend,ac_addh_str*/
/* depend,g_char_unparse*/

#include <clu2c.h>

extern object	PV1_INstring__expr1;
extern object	PV2_INstring__expr1;
extern object	PV3_INstring__expr1;
extern object	PV4_INstring__expr1;
extern object	PV5_INstring__expr1;
extern object	PV6_INstring__expr1;
extern object	PV7_INstring__expr1;
extern object	PV8_INstring__expr1;
extern object	PV9_INstring__expr1;
extern int	AFhash();
extern object	PV10_INstring__expr1;
extern object	PV20_INstring__expr1;
extern object	PV11_INstring__expr1;
extern object	PV21_INstring__expr1;
extern object	PV12_INstring__expr1;
extern object	PV22_INstring__expr1;
extern object	PV13_INstring__expr1;
extern object	PV14_INstring__expr1;
extern object	PV15_INstring__expr1;
extern object	PV16_INstring__expr1;
extern object	PV17_INstring__expr1;
extern object	PV18_INstring__expr1;
extern object	PV19_INstring__expr1;
extern int	OFstring_Dequal();

static STRING_REP(3) str1 = {3, {'N', 'I', 'L'}};
static STRING_REP(4) str2 = {4, {'T', 'R', 'U', 'E'}};
static STRING_REP(5) str3 = {5, {'F', 'A', 'L', 'S', 'E'}};
static STRING_REP(30) str4 = {30, {'c', 'h', 'a', 'r', '_', 'e', 'x', 'p', 'r', ':', ' ', 'u', 'n', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'v', 'e', 'r', 's', 'i', 'o', 'n', ' '}};
static STRING_REP(2) str5 = {2, {'0', 'x'}};
static STRING_REP(1) str6 = {1, {'\''}};
static STRING_REP(4) str7 = {4, {'r', 'e', 'a', 'l'}};
static STRING_REP(3) str8 = {3, {'l', 'i', 't'}};
static STRING_REP(1) str9 = {1, {'('}};
static STRING_REP(1) str10 = {1, {')'}};
static STRING_REP(6) str11 = {6, {'S', 'L', 'N', 'U', 'L', 'L'}};
static STRING_REP(12) str12 = {12, {'S', 'L', 'B', 'A', 'D', '_', 'F', 'O', 'R', 'M', 'A', 'T'}};
static STRING_REP(8) str13 = {8, {'S', 'L', 'B', 'O', 'U', 'N', 'D', 'S'}};
static STRING_REP(16) str14 = {16, {'S', 'L', 'C', 'O', 'M', 'P', 'L', 'E', 'X', '_', 'R', 'E', 'S', 'U', 'L', 'T'}};
static STRING_REP(13) str15 = {13, {'S', 'L', 'E', 'N', 'D', '_', 'O', 'F', '_', 'F', 'I', 'L', 'E'}};
static STRING_REP(9) str16 = {9, {'S', 'L', 'F', 'A', 'I', 'L', 'U', 'R', 'E'}};
static STRING_REP(14) str17 = {14, {'S', 'L', 'I', 'L', 'L', 'E', 'G', 'A', 'L', '_', 'C', 'H', 'A', 'R'}};
static STRING_REP(19) str18 = {19, {'S', 'L', 'N', 'E', 'G', 'A', 'T', 'I', 'V', 'E', '_', 'E', 'X', 'P', 'O', 'N', 'E', 'N', 'T'}};
static STRING_REP(22) str19 = {22, {'S', 'L', 'N', 'E', 'G', 'A', 'T', 'I', 'V', 'E', '_', 'F', 'I', 'E', 'L', 'D', '_', 'W', 'I', 'D', 'T', 'H'}};
static STRING_REP(15) str20 = {15, {'S', 'L', 'N', 'E', 'G', 'A', 'T', 'I', 'V', 'E', '_', 'S', 'I', 'Z', 'E'}};
static STRING_REP(10) str21 = {10, {'S', 'L', 'N', 'O', '_', 'L', 'I', 'M', 'I', 'T'}};
static STRING_REP(11) str22 = {11, {'S', 'L', 'N', 'O', 'T', '_', 'F', 'O', 'U', 'N', 'D'}};
static STRING_REP(14) str23 = {14, {'S', 'L', 'N', 'O', 'T', '_', 'P', 'O', 'S', 'S', 'I', 'B', 'L', 'E'}};
static STRING_REP(10) str24 = {10, {'S', 'L', 'O', 'V', 'E', 'R', 'F', 'L', 'O', 'W'}};
static STRING_REP(11) str25 = {11, {'S', 'L', 'U', 'N', 'D', 'E', 'F', 'I', 'N', 'E', 'D'}};
static STRING_REP(11) str26 = {11, {'S', 'L', 'U', 'N', 'D', 'E', 'R', 'F', 'L', 'O', 'W'}};
static STRING_REP(11) str27 = {11, {'S', 'L', 'W', 'R', 'O', 'N', 'G', '_', 'T', 'A', 'G'}};
static STRING_REP(12) str28 = {12, {'S', 'L', 'W', 'R', 'O', 'N', 'G', '_', 'T', 'Y', 'P', 'E'}};
static STRING_REP(13) str29 = {13, {'S', 'L', 'Z', 'E', 'R', 'O', '_', 'D', 'I', 'V', 'I', 'D', 'E'}};
static STRING_REP(32) str30 = {32, {'s', 't', 'r', 'i', 'n', 'g', '_', 'e', 'x', 'p', 'r', '1', ':', ' ', 'u', 'n', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ', 'v', 'e', 'r', 's', 'i', 'o', 'n'}};
static STRING_REP(2) str31 = {2, {'s', 'l'}};
static STRING_REP(6) str32 = {6, {'s', 't', 'r', 'l', 'i', 't'}};
static STRING_REP(7) str33 = {7, {'s', 't', 'a', 't', 'i', 'c', ' '}};
static STRING_REP(11) str34 = {11, {'s', 't', 'r', 'i', 'n', 'g', '_', 'r', 'e', 'p', ' '}};
static STRING_REP(4) str35 = {4, {' ', '=', ' ', '{'}};
static STRING_REP(2) str36 = {2, {',', ' '}};
static STRING_REP(2) str37 = {2, {'}', ';'}};
static STRING_REP(3) str38 = {3, {'s', 't', 'r'}};
static STRING_REP(11) str39 = {11, {'S', 'T', 'R', 'I', 'N', 'G', '_', 'R', 'E', 'P', '('}};
static STRING_REP(2) str40 = {2, {')', ' '}};
static STRING_REP(3) str41 = {3, {',', ' ', '{'}};
static STRING_REP(3) str42 = {3, {'}', '}', ';'}};
static STRING_REP(11) str43 = {11, {'(', '(', 's', 't', 'r', 'i', 'n', 'g', ')', ' ', '&'}};
static STRING_REP(9) str44 = {9, {'\'', '\"', '\\', '\n', '\t', '\f', '\b', '\r', '\v'}};
static STRING_REP(9) str45 = {9, {'\'', '\"', '\\', 'n', 't', 'f', 'b', 'r', 'v'}};

/* begin module */
/* c_function_name, AFnull__expr */
/* clu_operation_name, null_expr */
int AFnull__expr()
{
  /* begin body */
  retval_area[0] = ((string) &str1);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFbool__expr */
/* clu_operation_name, bool_expr */
int AFbool__expr(LVb)
     object LVb;
{
  /* begin body */
  if (LVb)
    {
      retval_area[0] = ((string) &str2);
      return RET;
    }
  else
    {
      retval_area[0] = ((string) &str3);
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
/* c_function_name, AFchar__expr */
/* clu_operation_name, char_expr */
int AFchar__expr(LVe, LVc)
     object LVe;
     object LVc;
{
  object LVversion= 0;
  /* begin body */
  if (OFg__env_Dget__char__version(LVe) == SIG)
    {
      goto except0;
    }
  LVversion = retval_area[0];
  if (OMint_Dequal(LVversion, 1))
    {
      if (AFchar__expr__1(LVc) == SIG)
        {
	  goto except0;
        }
      retval_area[0] = retval_area[0];
      return RET;
    }
  else
    {
      if (OMint_Dequal(LVversion, 2))
        {
	  if (AFchar__expr__2(LVc) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  sigarg_area[0] = ((string) &str4);
  signame = SLFAILURE;
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
/* c_function_name, AFchar__expr__1 */
/* clu_operation_name, char_expr_1 */
int AFchar__expr__1(LVc)
     object LVc;
{
  static bool IV = FALSE;
  static object WVcode= 0;
  int t1, t2;
  if (IV == FALSE)
    {
      IV = TRUE;
      OFarray_Dnew();
      WVcode = retval_area[0];
    }
  /* begin body */
  if (OMchar_Dgt(LVc, '\177'))
    {
      if (AFint__hex__unparse(OMchar_Dc2i(LVc)) == SIG)
        {
	  goto except0;
        }
      t1 = OMstring_Dsize(((string) &str5))
           + OMstring_Dsize(retval_area[0]);
      t2 = OFstring_D__predict(t1);
      OFstring_D__concat(t2, ((string) &str5));
      OFstring_D__concat(t2, retval_area[0]);
      retval_area[0] = t2;
      return RET;
    }
  if (OFarray_Dtrim(WVcode, 1, 0) == SIG)
    {
      goto except0;
    }
    {
      object LVc1= 0;
      for (t1 = AFg__char__unparse(TRUE, &t2, LVc);
           t1 == YIELD;
           t1 = AFg__char__unparse(FALSE, &t2, 0))
        {
	  LVc1 = retval_area[0];
	    {
	      OMarray_Daddh(WVcode, LVc1);
	    }
        }
      free(t2);
      if (t1 == SIG)
        {
	  goto except0;
        }
    }
  OFstring_Dac2s(WVcode);
  t1 = OMstring_Dsize(((string) &str6))
       + OMstring_Dsize(retval_area[0])
       + OMstring_Dsize(((string) &str6));
  t2 = OFstring_D__predict(t1);
  OFstring_D__concat(t2, ((string) &str6));
  OFstring_D__concat(t2, retval_area[0]);
  OFstring_D__concat(t2, ((string) &str6));
  retval_area[0] = t2;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFchar__expr__2 */
/* clu_operation_name, char_expr_2 */
int AFchar__expr__2(LVc)
     object LVc;
{
  static bool IV = FALSE;
  static object WVcode= 0;
  object LVi= 0;
  int t1, t2;
  if (IV == FALSE)
    {
      IV = TRUE;
      OFarray_Dnew();
      WVcode = retval_area[0];
    }
  /* begin body */
  LVi = OMchar_Dc2i(LVc);
  if (OMint_Dlt(LVi, 256))
    {
      if (OMint_Dgt(LVi, 127))
        {
	  if (AFint__hex__unparse(LVi) == SIG)
	    {
	      goto except0;
	    }
	  t1 = OMstring_Dsize(((string) &str5))
	       + OMstring_Dsize(retval_area[0]);
	  t2 = OFstring_D__predict(t1);
	  OFstring_D__concat(t2, ((string) &str5));
	  OFstring_D__concat(t2, retval_area[0]);
	  retval_area[0] = t2;
	  return RET;
        }
      if (OFarray_Dtrim(WVcode, 1, 0) == SIG)
        {
	  goto except0;
        }
        {
	  object LVc1= 0;
	  for (t1 = AFg__char__unparse(TRUE, &t2, LVc);
	       t1 == YIELD;
	       t1 = AFg__char__unparse(FALSE, &t2, 0))
	    {
	      LVc1 = retval_area[0];
	        {
		  OMarray_Daddh(WVcode, LVc1);
	        }
	    }
	  free(t2);
	  if (t1 == SIG)
	    {
	      goto except0;
	    }
        }
      OFstring_Dac2s(WVcode);
      t1 = OMstring_Dsize(((string) &str6))
           + OMstring_Dsize(retval_area[0])
           + OMstring_Dsize(((string) &str6));
      t2 = OFstring_D__predict(t1);
      OFstring_D__concat(t2, ((string) &str6));
      OFstring_D__concat(t2, retval_area[0]);
      OFstring_D__concat(t2, ((string) &str6));
      retval_area[0] = t2;
      return RET;
    }
  else
    {
      if (AFint__hex__unparse(LVi) == SIG)
        {
	  goto except0;
        }
      t1 = OMstring_Dsize(((string) &str5))
           + OMstring_Dsize(retval_area[0]);
      t2 = OFstring_D__predict(t1);
      OFstring_D__concat(t2, ((string) &str5));
      OFstring_D__concat(t2, retval_area[0]);
      retval_area[0] = t2;
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
/* c_function_name, AFint__expr */
/* clu_operation_name, int_expr */
int AFint__expr(LVi)
     object LVi;
{
  /* begin body */
  OFint_Dunparse(LVi);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFreal__expr */
/* clu_operation_name, real_expr */
int AFreal__expr(LVr)
     object LVr;
{
  int t1, t2, t3;
  /* begin body */
  if (AFconv__opfun(((string) &str7), ((string) &str8)) == SIG)
    {
      goto except0;
    }
  t1 = retval_area[0];
  if (OFreal_Dunparse(LVr) == SIG)
    {
      goto except0;
    }
  t2 = OMstring_Dsize(t1)
       + OMstring_Dsize(((string) &str9))
       + OMstring_Dsize(retval_area[0])
       + OMstring_Dsize(((string) &str10));
  t3 = OFstring_D__predict(t2);
  OFstring_D__concat(t3, t1);
  OFstring_D__concat(t3, ((string) &str9));
  OFstring_D__concat(t3, retval_area[0]);
  OFstring_D__concat(t3, ((string) &str10));
  retval_area[0] = t3;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFstring__expr */
/* clu_operation_name, string_expr */
int AFstring__expr(LVe, LVs)
     object LVe;
     object LVs;
{
  /* begin body */
  if (AFstring__expr1(LVe, LVs, TRUE) == SIG)
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
/* c_function_name, AFstring__expr1 */
/* clu_operation_name, string_expr1 */
int AFstring__expr1(LVe, LVs, LVstatic)
     object LVe;
     object LVs;
     object LVstatic;
{
  static bool IV = FALSE;
  static object WVcommlits= 0;
  object LVversion= 0;
  if (IV == FALSE)
    {
      IV = TRUE;
      if ((*((proctype)PV1_INstring__expr1))(100, AFhash, OFstring_Dequal) == SIG)
        {
	  goto except0;
        }
      WVcommlits = retval_area[0];
    }
  /* begin body */
  if ((*((proctype)PV2_INstring__expr1))(WVcommlits) == SIG)
    {
      goto except0;
    }
  if (retval_area[0])
    {
      if ((*((proctype)PV3_INstring__expr1))(WVcommlits, SLNULL, ((string) &str11)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV4_INstring__expr1))(WVcommlits, SLBAD_FORMAT, ((string) &str12)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV5_INstring__expr1))(WVcommlits, SLBOUNDS, ((string) &str13)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV6_INstring__expr1))(WVcommlits, SLCOMPLEX_RESULT, ((string) &str14)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV7_INstring__expr1))(WVcommlits, SLEND_OF_FILE, ((string) &str15)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV8_INstring__expr1))(WVcommlits, SLFAILURE, ((string) &str16)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV9_INstring__expr1))(WVcommlits, SLILLEGAL_CHAR, ((string) &str17)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV10_INstring__expr1))(WVcommlits, SLNEGATIVE_EXPONENT, ((string) &str18)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV11_INstring__expr1))(WVcommlits, SLNEGATIVE_FIELD_WIDTH, ((string) &str19)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV12_INstring__expr1))(WVcommlits, SLNEGATIVE_SIZE, ((string) &str20)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV13_INstring__expr1))(WVcommlits, SLNO_LIMIT, ((string) &str21)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV14_INstring__expr1))(WVcommlits, SLNOT_FOUND, ((string) &str22)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV15_INstring__expr1))(WVcommlits, SLNOT_POSSIBLE, ((string) &str23)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV16_INstring__expr1))(WVcommlits, SLOVERFLOW, ((string) &str24)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV17_INstring__expr1))(WVcommlits, SLUNDEFINED, ((string) &str25)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV18_INstring__expr1))(WVcommlits, SLUNDERFLOW, ((string) &str26)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV19_INstring__expr1))(WVcommlits, SLWRONG_TAG, ((string) &str27)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV20_INstring__expr1))(WVcommlits, SLWRONG_TYPE, ((string) &str28)) == SIG)
        {
	  goto except0;
        }
      if ((*((proctype)PV21_INstring__expr1))(WVcommlits, SLZERO_DIVIDE, ((string) &str29)) == SIG)
        {
	  goto except0;
        }
    }
  if ((*((proctype)PV22_INstring__expr1))(WVcommlits, LVs) == SIG)
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
  if (OFg__env_Dlookup__string(LVe, LVs) == SIG)
    {
      goto except2;
    }
  retval_area[0] = retval_area[0];
  return RET;
  if (FALSE)
    {
    except2:
      if (OMstring_Dequal(signame, SLNOT_FOUND))
        {
        }
      else
        {
	  goto except0;
        }
    }
  if (OFg__env_Dget__string__version(LVe) == SIG)
    {
      goto except0;
    }
  LVversion = retval_area[0];
  if (OMint_Dequal(LVversion, 1))
    {
      if (AFstring__expr2__1(LVe, LVs, LVstatic) == SIG)
        {
	  goto except0;
        }
      retval_area[0] = retval_area[0];
      return RET;
    }
  else
    {
      if (OMint_Dequal(LVversion, 2))
        {
	  if (AFstring__expr2__2(LVe, LVs, LVstatic) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
      else
        {
	  if (OMint_Dequal(LVversion, 3))
	    {
	      if (AFstring__expr2__3(LVe, LVs, LVstatic) == SIG)
	        {
		  goto except0;
	        }
	      retval_area[0] = retval_area[0];
	      return RET;
	    }
        }
    }
  sigarg_area[0] = ((string) &str30);
  signame = SLFAILURE;
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
/* c_function_name, AFstring__expr2__1 */
/* clu_operation_name, string_expr2_1 */
int AFstring__expr2__1(LVe, LVs, LVstatic)
     object LVe;
     object LVs;
     object LVstatic;
{
  static bool IV = FALSE;
  static object WVbuf= 0;
  object LVcode= 0;
  int t1, t2, t3, t4, t5;
  if (IV == FALSE)
    {
      IV = TRUE;
      OFarray_Dnew();
      WVbuf = retval_area[0];
    }
  /* begin body */
  OMarray_Daddh(WVbuf, '\"');
    {
      object LVc= 0;
      for (t1 = LVs, t2 = 1, t3 = OMstring_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVc = OMstring_Dfetch(t1, t2);
	    {
	        {
		  object LVc1= 0;
		  for (t4 = AFg__char__unparse(TRUE, &t5, LVc);
		       t4 == YIELD;
		       t4 = AFg__char__unparse(FALSE, &t5, 0))
		    {
		      LVc1 = retval_area[0];
		        {
			  OMarray_Daddh(WVbuf, LVc1);
		        }
		    }
		  free(t5);
		  if (t4 == SIG)
		    {
		      goto except0;
		    }
	        }
	    }
        }
    }
  OMarray_Daddh(WVbuf, '\"');
  OFstring_Dac2s(WVbuf);
  LVcode = retval_area[0];
  if (OFarray_Dtrim(WVbuf, 1, 0) == SIG)
    {
      goto except0;
    }
  if (OFg__env_Denter__string(LVe, LVcode, LVs) == SIG)
    {
      goto except0;
    }
  retval_area[0] = LVcode;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFstring__expr2__2 */
/* clu_operation_name, string_expr2_2 */
int AFstring__expr2__2(LVe, LVs, LVstatic)
     object LVe;
     object LVs;
     object LVstatic;
{
  static bool IV = FALSE;
  static object WVbuf= 0;
  object LVvar= 0;
  object LVdef= 0;
  int t1, t2, t3;
  if (IV == FALSE)
    {
      IV = TRUE;
      OFarray_Dnew();
      WVbuf = retval_area[0];
    }
  /* begin body */
  if (OFglb_Dadd(((string) &str32)) == SIG)
    {
      goto except0;
    }
  OFint_Dunparse(retval_area[0]);
  t1 = OMstring_Dsize(((string) &str31))
       + OMstring_Dsize(retval_area[0]);
  t2 = OFstring_D__predict(t1);
  OFstring_D__concat(t2, ((string) &str31));
  OFstring_D__concat(t2, retval_area[0]);
  LVvar = t2;
  if (OFarray_Dtrim(WVbuf, 1, 0) == SIG)
    {
      goto except0;
    }
  if (LVstatic)
    {
      if (AFac__addh__str(WVbuf, ((string) &str33)) == SIG)
        {
	  goto except0;
        }
    }
  if (AFac__addh__str(WVbuf, ((string) &str34)) == SIG)
    {
      goto except0;
    }
  if (AFac__addh__str(WVbuf, LVvar) == SIG)
    {
      goto except0;
    }
  if (AFac__addh__str(WVbuf, ((string) &str35)) == SIG)
    {
      goto except0;
    }
  OFint_Dunparse(OMstring_Dsize(LVs));
  if (AFac__addh__str(WVbuf, retval_area[0]) == SIG)
    {
      goto except0;
    }
    {
      object LVc= 0;
      for (t1 = LVs, t2 = 1, t3 = OMstring_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVc = OMstring_Dfetch(t1, t2);
	    {
	      if (AFac__addh__str(WVbuf, ((string) &str36)) == SIG)
	        {
		  goto except0;
	        }
	      if (AFchar__expr(LVe, LVc) == SIG)
	        {
		  goto except0;
	        }
	      if (AFac__addh__str(WVbuf, retval_area[0]) == SIG)
	        {
		  goto except0;
	        }
	    }
        }
    }
  if (AFac__addh__str(WVbuf, ((string) &str37)) == SIG)
    {
      goto except0;
    }
  OFstring_Dac2s(WVbuf);
  LVdef = retval_area[0];
  if (OFarray_Dtrim(WVbuf, 1, 0) == SIG)
    {
      goto except0;
    }
  if (OFg__env_Dget__co(LVe) == SIG)
    {
      goto except0;
    }
  if (OFcode__man_Dconst(retval_area[0], LVdef) == SIG)
    {
      goto except0;
    }
  if (OFg__env_Denter__string(LVe, LVvar, LVs) == SIG)
    {
      goto except0;
    }
  retval_area[0] = LVvar;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFstring__expr2__3 */
/* clu_operation_name, string_expr2_3 */
int AFstring__expr2__3(LVe, LVs, LVstatic)
     object LVe;
     object LVs;
     object LVstatic;
{
  static bool IV = FALSE;
  static object WVbuf= 0;
  object LVnumber= 0;
  object LVvar= 0;
  object LVdef= 0;
  object LVsize= 0;
  object LVfirst= 0;
  object LVcode= 0;
  int t1, t2, t3;
  if (IV == FALSE)
    {
      IV = TRUE;
      OFarray_Dnew();
      WVbuf = retval_area[0];
    }
  /* begin body */
  if (OFglb_Dadd(((string) &str32)) == SIG)
    {
      goto except0;
    }
  OFint_Dunparse(retval_area[0]);
  LVnumber = retval_area[0];
  t1 = OMstring_Dsize(((string) &str38))
       + OMstring_Dsize(LVnumber);
  t2 = OFstring_D__predict(t1);
  OFstring_D__concat(t2, ((string) &str38));
  OFstring_D__concat(t2, LVnumber);
  LVvar = t2;
  LVdef = SLNULL;
  if (LVstatic)
    {
      LVdef = ((string) &str33);
    }
  OFint_Dunparse(OMstring_Dsize(LVs));
  LVsize = retval_area[0];
  t1 = OMstring_Dsize(LVdef)
       + OMstring_Dsize(((string) &str39))
       + OMstring_Dsize(LVsize)
       + OMstring_Dsize(((string) &str40))
       + OMstring_Dsize(LVvar)
       + OMstring_Dsize(((string) &str35))
       + OMstring_Dsize(LVsize)
       + OMstring_Dsize(((string) &str41));
  t2 = OFstring_D__predict(t1);
  OFstring_D__concat(t2, LVdef);
  OFstring_D__concat(t2, ((string) &str39));
  OFstring_D__concat(t2, LVsize);
  OFstring_D__concat(t2, ((string) &str40));
  OFstring_D__concat(t2, LVvar);
  OFstring_D__concat(t2, ((string) &str35));
  OFstring_D__concat(t2, LVsize);
  OFstring_D__concat(t2, ((string) &str41));
  LVdef = t2;
  LVfirst = TRUE;
    {
      object LVc= 0;
      for (t1 = LVs, t2 = 1, t3 = OMstring_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVc = OMstring_Dfetch(t1, t2);
	    {
	      if (LVfirst)
	        {
		  LVfirst = FALSE;
	        }
	      else
	        {
		  if (AFac__addh__str(WVbuf, ((string) &str36)) == SIG)
		    {
		      goto except0;
		    }
	        }
	      if (AFchar__expr(LVe, LVc) == SIG)
	        {
		  goto except0;
	        }
	      if (AFac__addh__str(WVbuf, retval_area[0]) == SIG)
	        {
		  goto except0;
	        }
	    }
        }
    }
  OFstring_Dac2s(WVbuf);
  t1 = OMstring_Dsize(LVdef)
       + OMstring_Dsize(retval_area[0])
       + OMstring_Dsize(((string) &str42));
  t2 = OFstring_D__predict(t1);
  OFstring_D__concat(t2, LVdef);
  OFstring_D__concat(t2, retval_area[0]);
  OFstring_D__concat(t2, ((string) &str42));
  LVdef = t2;
  if (OFarray_Dtrim(WVbuf, 1, 0) == SIG)
    {
      goto except0;
    }
  if (OFg__env_Dget__co(LVe) == SIG)
    {
      goto except0;
    }
  if (OFcode__man_Dconst(retval_area[0], LVdef) == SIG)
    {
      goto except0;
    }
  t1 = OMstring_Dsize(((string) &str43))
       + OMstring_Dsize(LVvar)
       + OMstring_Dsize(((string) &str10));
  t2 = OFstring_D__predict(t1);
  OFstring_D__concat(t2, ((string) &str43));
  OFstring_D__concat(t2, LVvar);
  OFstring_D__concat(t2, ((string) &str10));
  LVcode = t2;
  if (OFg__env_Denter__string(LVe, LVcode, LVs) == SIG)
    {
      goto except0;
    }
  retval_area[0] = LVcode;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFac__addh__str */
/* clu_operation_name, ac_addh_str */
int AFac__addh__str(LVa, LVs)
     object LVa;
     object LVs;
{
  int t1, t2, t3;
  /* begin body */
    {
      object LVc= 0;
      for (t1 = LVs, t2 = 1, t3 = OMstring_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVc = OMstring_Dfetch(t1, t2);
	    {
	      OMarray_Daddh(LVa, LVc);
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
/* c_function_name, AFg__char__unparse */
/* clu_operation_name, g_char_unparse */
#define INV_TOP 4
#define WORK_SIZE 7
int AFg__char__unparse(init, ivarp, LVc)
     bool init;
     int **ivarp;
     object LVc;
{
  if (init)
    {
      *ivarp = (int*) malloc(WORK_SIZE*sizeof(int));
      (*ivarp)[1] = LVc;
    }
  else
    {
      switch ((*ivarp)[0])
  	{
  	  case 1: goto yield1;
  	  case 2: goto yield2;
  	  case 3: goto yield3;
  	  case 4: goto yield4;
  	  case 5: goto yield5;
  	  case 6: goto yield6;
  	}
    }
  /* begin body */
  OFstring_Dindexc((*ivarp)[1], ((string) &str44));
  (*ivarp)[2] = retval_area[0];
  (*ivarp)[INV_TOP+0] = OMint_Dequal((*ivarp)[2], 0);
  (*ivarp)[INV_TOP+1] = OMbool_Dand((*ivarp)[INV_TOP+0], OMchar_Dle(' ', (*ivarp)[1]));
  if (OMbool_Dand((*ivarp)[INV_TOP+1], OMchar_Dle((*ivarp)[1], '~')))
    {
      retval_area[0] = (*ivarp)[1];
      (*ivarp)[0] = 1;
      return YIELD;
    yield1:
      NO_OPERATION;
      return RET;
    }
  retval_area[0] = '\\';
  (*ivarp)[0] = 2;
  return YIELD;
yield2:
  NO_OPERATION;
  if (OMint_Dgt((*ivarp)[2], 0))
    {
      if (OMstring_Dbounds(((string) &str45), (*ivarp)[2]))
        {
	  signame = SLBOUNDS;
	  goto except0;
        }
      retval_area[0] = OMstring_Dfetch(((string) &str45), (*ivarp)[2]);
      (*ivarp)[0] = 3;
      return YIELD;
    yield3:
      NO_OPERATION;
    }
  else
    {
      (*ivarp)[3] = OMchar_Dc2i((*ivarp)[1]);
      (*ivarp)[INV_TOP+0] = OMchar_Dc2i('0');
      if (OMint_Dzero__divide(64))
        {
	  signame = SLZERO_DIVIDE;
	  goto except0;
        }
      (*ivarp)[INV_TOP+1] = OMint_Dadd((*ivarp)[INV_TOP+0], OMint_Ddiv((*ivarp)[3], 64));
      if (OMchar_Dillegal__char((*ivarp)[INV_TOP+1]))
        {
	  signame = SLILLEGAL_CHAR;
	  goto except0;
        }
      retval_area[0] = OMchar_Di2c((*ivarp)[INV_TOP+1]);
      (*ivarp)[0] = 4;
      return YIELD;
    yield4:
      NO_OPERATION;
      (*ivarp)[INV_TOP+0] = OMchar_Dc2i('0');
      if (OMint_Dzero__divide(8))
        {
	  signame = SLZERO_DIVIDE;
	  goto except0;
        }
      (*ivarp)[INV_TOP+1] = OMint_Ddiv((*ivarp)[3], 8);
      if (OMint_Dzero__divide(8))
        {
	  signame = SLZERO_DIVIDE;
	  goto except0;
        }
      (*ivarp)[INV_TOP+2] = OMint_Dadd((*ivarp)[INV_TOP+0], OMint_Dmod((*ivarp)[INV_TOP+1], 8));
      if (OMchar_Dillegal__char((*ivarp)[INV_TOP+2]))
        {
	  signame = SLILLEGAL_CHAR;
	  goto except0;
        }
      retval_area[0] = OMchar_Di2c((*ivarp)[INV_TOP+2]);
      (*ivarp)[0] = 5;
      return YIELD;
    yield5:
      NO_OPERATION;
      (*ivarp)[INV_TOP+0] = OMchar_Dc2i('0');
      if (OMint_Dzero__divide(8))
        {
	  signame = SLZERO_DIVIDE;
	  goto except0;
        }
      (*ivarp)[INV_TOP+1] = OMint_Dadd((*ivarp)[INV_TOP+0], OMint_Dmod((*ivarp)[3], 8));
      if (OMchar_Dillegal__char((*ivarp)[INV_TOP+1]))
        {
	  signame = SLILLEGAL_CHAR;
	  goto except0;
        }
      retval_area[0] = OMchar_Di2c((*ivarp)[INV_TOP+1]);
      (*ivarp)[0] = 6;
      return YIELD;
    yield6:
      NO_OPERATION;
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