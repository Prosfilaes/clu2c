/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,conv_appfun*/
/* depend,conv_appent*/
/* depend,conv_opfun,conv_initfun,discard_sel*/
/* depend,conv_opent,discr_clu*/
/* depend,conv_opmac,discard_sel*/
/* depend,discard_sel*/
/* depend,conv_initfun,discr_clu*/
/* depend,conv_localvar*/
/* depend,conv_ownvar_app,discr_app*/
/* depend,conv_ownvar_op,discr_op*/
/* depend,conv_ownvar_clu,discr_clu*/
/* depend,conv_initvar_app,discr_app*/
/* depend,conv_initvar_op,discr_op*/
/* depend,conv_initvar_clu,discr_clu*/
/* depend,conv_entptr_app,conv_entptr,discr_app*/
/* depend,conv_entptr_op,conv_entptr,discr_op*/
/* depend,conv_entptr*/
/* depend,conv_tidvar_app,conv_tidvar,discr_app*/
/* depend,conv_tidvar_op,conv_tidvar,discr_op*/
/* depend,conv_tidvar*/
/* depend,discr_app*/
/* depend,discr_clu*/
/* depend,discr_op,conv_initfun*/
/* depend,conv_idn_j10n,hex_digits*/
/* depend,conv_idn_noj10n*/
/* depend,hex_digits*/
/* depend,decode_var,decode_idn*/
/* depend,decode_idn,hex2int*/
/* depend,hex2int*/

#include <clu2c.h>

static STRING_REP(2) str1 = {2, {'A', 'F'}};
static STRING_REP(6) str2 = {6, {'r', 'e', 'c', 'o', 'r', 'd'}};
static STRING_REP(6) str3 = {6, {'s', 't', 'r', 'u', 'c', 't'}};
static STRING_REP(5) str4 = {5, {'o', 'n', 'e', 'o', 'f'}};
static STRING_REP(7) str5 = {7, {'v', 'a', 'r', 'i', 'a', 'n', 't'}};
static STRING_REP(2) str6 = {2, {'O', 'F'}};
static STRING_REP(2) str7 = {2, {'_', 'D'}};
static STRING_REP(8) str8 = {8, {'#', 'i', 'n', 'i', 't', 'o', 'w', 'n'}};
static STRING_REP(2) str9 = {2, {'I', 'F'}};
static STRING_REP(4) str10 = {4, {'n', 'u', 'l', 'l'}};
static STRING_REP(3) str11 = {3, {'i', 'n', 't'}};
static STRING_REP(4) str12 = {4, {'b', 'o', 'o', 'l'}};
static STRING_REP(4) str13 = {4, {'r', 'e', 'a', 'l'}};
static STRING_REP(4) str14 = {4, {'c', 'h', 'a', 'r'}};
static STRING_REP(6) str15 = {6, {'s', 't', 'r', 'i', 'n', 'g'}};
static STRING_REP(5) str16 = {5, {'a', 'r', 'r', 'a', 'y'}};
static STRING_REP(8) str17 = {8, {'s', 'e', 'q', 'u', 'e', 'n', 'c', 'e'}};
static STRING_REP(8) str18 = {8, {'p', 'r', 'o', 'c', 't', 'y', 'p', 'e'}};
static STRING_REP(8) str19 = {8, {'i', 't', 'e', 'r', 't', 'y', 'p', 'e'}};
static STRING_REP(2) str20 = {2, {'O', 'M'}};
static STRING_REP(4) str21 = {4, {'g', 'e', 't', '_'}};
static STRING_REP(3) str22 = {3, {'g', 'e', 't'}};
static STRING_REP(4) str23 = {4, {'s', 'e', 't', '_'}};
static STRING_REP(3) str24 = {3, {'s', 'e', 't'}};
static STRING_REP(8) str25 = {8, {'r', 'e', 'p', 'l', 'a', 'c', 'e', '_'}};
static STRING_REP(7) str26 = {7, {'r', 'e', 'p', 'l', 'a', 'c', 'e'}};
static STRING_REP(5) str27 = {5, {'m', 'a', 'k', 'e', '_'}};
static STRING_REP(4) str28 = {4, {'m', 'a', 'k', 'e'}};
static STRING_REP(3) str29 = {3, {'i', 's', '_'}};
static STRING_REP(2) str30 = {2, {'i', 's'}};
static STRING_REP(6) str31 = {6, {'v', 'a', 'l', 'u', 'e', '_'}};
static STRING_REP(5) str32 = {5, {'v', 'a', 'l', 'u', 'e'}};
static STRING_REP(7) str33 = {7, {'c', 'h', 'a', 'n', 'g', 'e', '_'}};
static STRING_REP(6) str34 = {6, {'c', 'h', 'a', 'n', 'g', 'e'}};
static STRING_REP(2) str35 = {2, {'L', 'V'}};
static STRING_REP(2) str36 = {2, {'W', 'V'}};
static STRING_REP(2) str37 = {2, {'I', 'V'}};
static STRING_REP(2) str38 = {2, {'P', 'V'}};
static STRING_REP(2) str39 = {2, {'T', 'V'}};
static STRING_REP(3) str40 = {3, {'_', 'I', 'N'}};
static STRING_REP(5) str41 = {5, {'_', 'I', 'N', '_', 'C'}};
static STRING_REP(4) str42 = {4, {'_', 'I', 'N', '_'}};
static STRING_REP(7) str43 = {7, {'c', 'o', 'n', 'v', 'e', 'r', 't'}};
static STRING_REP(16) str44 = {16, {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'}};
static STRING_REP(17) str45 = {17, {'n', 'e', 'g', 'a', 't', 'i', 'v', 'e', '_', 'a', 'r', 'g', 'u', 'm', 'e', 'n', 't'}};

/* begin module */
/* c_function_name, AFconv__appfun */
/* clu_operation_name, conv_appfun */
int AFconv__appfun(LVapply)
     object LVapply;
{
  int t1, t2;
  /* begin body */
  if (AFconv__idn__j10n(LVapply) == SIG)
    {
      goto except0;
    }
  t1 = OMstring_Dsize(((string) &str1))
       + OMstring_Dsize(retval_area[0]);
  t2 = OFstring_D__predict(t1);
  OFstring_D__concat(t2, ((string) &str1));
  OFstring_D__concat(t2, retval_area[0]);
  retval_area[0] = t2;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFconv__appent */
/* clu_operation_name, conv_appent */
int AFconv__appent(LVapply, LVid)
     object LVapply;
     object LVid;
{
  int t1, t2, t3;
  /* begin body */
  OFint_Dunparse(LVid);
  t1 = retval_area[0];
  if (AFconv__idn__j10n(LVapply) == SIG)
    {
      goto except0;
    }
  t2 = OMstring_Dsize(((string) &str1))
       + OMstring_Dsize(t1)
       + OMstring_Dsize(retval_area[0]);
  t3 = OFstring_D__predict(t2);
  OFstring_D__concat(t3, ((string) &str1));
  OFstring_D__concat(t3, t1);
  OFstring_D__concat(t3, retval_area[0]);
  retval_area[0] = t3;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFconv__opfun */
/* clu_operation_name, conv_opfun */
int AFconv__opfun(LVprovider, LVop)
     object LVprovider;
     object LVop;
{
  object LVres= 0;
  int t1, t2, t3, t4, t5, t6;
  /* begin body */
  if (OMstring_Dequal(LVprovider, ((string) &str2)))
    {
      t3 = TRUE;
    }
  else
    {
      t3 = OMstring_Dequal(LVprovider, ((string) &str3));
    }
  if (t3)
    {
      t2 = TRUE;
    }
  else
    {
      t2 = OMstring_Dequal(LVprovider, ((string) &str4));
    }
  if (t2)
    {
      t1 = TRUE;
    }
  else
    {
      t1 = OMstring_Dequal(LVprovider, ((string) &str5));
    }
  if (t1)
    {
      if (AFconv__idn__j10n(LVprovider) == SIG)
        {
	  goto except0;
        }
      t4 = retval_area[0];
      if (AFdiscard__sel(LVop) == SIG)
        {
	  goto except0;
        }
      if (AFconv__idn__j10n(retval_area[0]) == SIG)
        {
	  goto except0;
        }
      t5 = OMstring_Dsize(((string) &str6))
           + OMstring_Dsize(t4)
           + OMstring_Dsize(((string) &str7))
           + OMstring_Dsize(retval_area[0]);
      t6 = OFstring_D__predict(t5);
      OFstring_D__concat(t6, ((string) &str6));
      OFstring_D__concat(t6, t4);
      OFstring_D__concat(t6, ((string) &str7));
      OFstring_D__concat(t6, retval_area[0]);
      LVres = t6;
    }
  else
    {
      if (OMstring_Dequal(LVop, ((string) &str8)))
        {
	  if (AFconv__initfun(LVprovider) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = retval_area[0];
	  return RET;
        }
      if (OMstring_Dbounds(LVop, 1))
        {
	  signame = SLBOUNDS;
	  goto except0;
        }
      if (OMchar_Dequal(OMstring_Dfetch(LVop, 1), '%'))
        {
	  if (OFstring_Drest(LVop, 2) == SIG)
	    {
	      goto except0;
	    }
	  LVop = retval_area[0];
        }
      if (AFconv__idn__j10n(LVprovider) == SIG)
        {
	  goto except0;
        }
      t4 = retval_area[0];
      if (AFconv__idn__j10n(LVop) == SIG)
        {
	  goto except0;
        }
      t5 = OMstring_Dsize(((string) &str6))
           + OMstring_Dsize(t4)
           + OMstring_Dsize(((string) &str7))
           + OMstring_Dsize(retval_area[0]);
      t6 = OFstring_D__predict(t5);
      OFstring_D__concat(t6, ((string) &str6));
      OFstring_D__concat(t6, t4);
      OFstring_D__concat(t6, ((string) &str7));
      OFstring_D__concat(t6, retval_area[0]);
      LVres = t6;
    }
  retval_area[0] = LVres;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFconv__opent */
/* clu_operation_name, conv_opent */
int AFconv__opent(LVprovider, LVop, LVid)
     object LVprovider;
     object LVop;
     object LVid;
{
  int t1, t2, t3, t4;
  /* begin body */
  if (OMstring_Dequal(LVop, ((string) &str8)))
    {
      OFint_Dunparse(LVid);
      t1 = retval_area[0];
      if (AFdiscr__clu(LVprovider) == SIG)
        {
	  goto except0;
        }
      t2 = OMstring_Dsize(((string) &str9))
           + OMstring_Dsize(t1)
           + OMstring_Dsize(retval_area[0]);
      t3 = OFstring_D__predict(t2);
      OFstring_D__concat(t3, ((string) &str9));
      OFstring_D__concat(t3, t1);
      OFstring_D__concat(t3, retval_area[0]);
      retval_area[0] = t3;
      return RET;
    }
  if (OMstring_Dbounds(LVop, 1))
    {
      signame = SLBOUNDS;
      goto except1;
    }
  if (OMchar_Dequal(OMstring_Dfetch(LVop, 1), '%'))
    {
      if (OFstring_Drest(LVop, 2) == SIG)
        {
	  goto except1;
        }
      LVop = retval_area[0];
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLBOUNDS))
        {
        }
      else
        {
	  goto except0;
        }
    }
  OFint_Dunparse(LVid);
  t1 = retval_area[0];
  if (AFconv__idn__j10n(LVprovider) == SIG)
    {
      goto except0;
    }
  t2 = retval_area[0];
  if (AFconv__idn__j10n(LVop) == SIG)
    {
      goto except0;
    }
  t3 = OMstring_Dsize(((string) &str6))
       + OMstring_Dsize(t1)
       + OMstring_Dsize(t2)
       + OMstring_Dsize(((string) &str7))
       + OMstring_Dsize(retval_area[0]);
  t4 = OFstring_D__predict(t3);
  OFstring_D__concat(t4, ((string) &str6));
  OFstring_D__concat(t4, t1);
  OFstring_D__concat(t4, t2);
  OFstring_D__concat(t4, ((string) &str7));
  OFstring_D__concat(t4, retval_area[0]);
  retval_area[0] = t4;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFconv__opmac */
/* clu_operation_name, conv_opmac */
int AFconv__opmac(LVprovider, LVop)
     object LVprovider;
     object LVop;
{
  int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
  int t11, t12, t13, t14, t15, t16;
  /* begin body */
  if (OMstring_Dequal(LVprovider, ((string) &str10)))
    {
      t10 = TRUE;
    }
  else
    {
      t10 = OMstring_Dequal(LVprovider, ((string) &str11));
    }
  if (t10)
    {
      t9 = TRUE;
    }
  else
    {
      t9 = OMstring_Dequal(LVprovider, ((string) &str12));
    }
  if (t9)
    {
      t8 = TRUE;
    }
  else
    {
      t8 = OMstring_Dequal(LVprovider, ((string) &str11));
    }
  if (t8)
    {
      t7 = TRUE;
    }
  else
    {
      t7 = OMstring_Dequal(LVprovider, ((string) &str13));
    }
  if (t7)
    {
      t6 = TRUE;
    }
  else
    {
      t6 = OMstring_Dequal(LVprovider, ((string) &str14));
    }
  if (t6)
    {
      t5 = TRUE;
    }
  else
    {
      t5 = OMstring_Dequal(LVprovider, ((string) &str15));
    }
  if (t5)
    {
      t4 = TRUE;
    }
  else
    {
      t4 = OMstring_Dequal(LVprovider, ((string) &str16));
    }
  if (t4)
    {
      t3 = TRUE;
    }
  else
    {
      t3 = OMstring_Dequal(LVprovider, ((string) &str17));
    }
  if (t3)
    {
      t2 = TRUE;
    }
  else
    {
      t2 = OMstring_Dequal(LVprovider, ((string) &str18));
    }
  if (t2)
    {
      t1 = TRUE;
    }
  else
    {
      t1 = OMstring_Dequal(LVprovider, ((string) &str19));
    }
  if (t1)
    {
      if (AFconv__idn__j10n(LVprovider) == SIG)
        {
	  goto except0;
        }
      t11 = retval_area[0];
      if (AFconv__idn__j10n(LVop) == SIG)
        {
	  goto except0;
        }
      t12 = OMstring_Dsize(((string) &str20))
            + OMstring_Dsize(t11)
            + OMstring_Dsize(((string) &str7))
            + OMstring_Dsize(retval_area[0]);
      t13 = OFstring_D__predict(t12);
      OFstring_D__concat(t13, ((string) &str20));
      OFstring_D__concat(t13, t11);
      OFstring_D__concat(t13, ((string) &str7));
      OFstring_D__concat(t13, retval_area[0]);
      retval_area[0] = t13;
      return RET;
    }
  else
    {
      if (OMstring_Dequal(LVprovider, ((string) &str2)))
        {
	  t13 = TRUE;
        }
      else
        {
	  t13 = OMstring_Dequal(LVprovider, ((string) &str3));
        }
      if (t13)
        {
	  t12 = TRUE;
        }
      else
        {
	  t12 = OMstring_Dequal(LVprovider, ((string) &str4));
        }
      if (t12)
        {
	  t11 = TRUE;
        }
      else
        {
	  t11 = OMstring_Dequal(LVprovider, ((string) &str5));
        }
      if (t11)
        {
	  if (AFconv__idn__j10n(LVprovider) == SIG)
	    {
	      goto except0;
	    }
	  t14 = retval_area[0];
	  if (AFdiscard__sel(LVop) == SIG)
	    {
	      goto except0;
	    }
	  if (AFconv__idn__j10n(retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  t15 = OMstring_Dsize(((string) &str20))
	        + OMstring_Dsize(t14)
	        + OMstring_Dsize(((string) &str7))
	        + OMstring_Dsize(retval_area[0]);
	  t16 = OFstring_D__predict(t15);
	  OFstring_D__concat(t16, ((string) &str20));
	  OFstring_D__concat(t16, t14);
	  OFstring_D__concat(t16, ((string) &str7));
	  OFstring_D__concat(t16, retval_area[0]);
	  retval_area[0] = t16;
	  return RET;
        }
      else
        {
	  t14 = OMstring_Dsize(((string) &str20))
	        + OMstring_Dsize(LVprovider)
	        + OMstring_Dsize(((string) &str7))
	        + OMstring_Dsize(LVop);
	  t15 = OFstring_D__predict(t14);
	  OFstring_D__concat(t15, ((string) &str20));
	  OFstring_D__concat(t15, LVprovider);
	  OFstring_D__concat(t15, ((string) &str7));
	  OFstring_D__concat(t15, LVop);
	  retval_area[0] = t15;
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
/* c_function_name, AFdiscard__sel */
/* clu_operation_name, discard_sel */
int AFdiscard__sel(LVop)
     object LVop;
{
  static bool IV = FALSE;
  static object WVops= 0;
  int t1, t2, t3, t4, t5, t6, t7, t8;
  if (IV == FALSE)
    {
      IV = TRUE;
      t1 = OFstruct_D__alloc(3);
      OMstruct_D__set(1, t1, ((string) &str21));
      OMstruct_D__set(2, t1, ((string) &str22));
      OMstruct_D__set(3, t1, 4);
      t2 = OFstruct_D__alloc(3);
      OMstruct_D__set(1, t2, ((string) &str23));
      OMstruct_D__set(2, t2, ((string) &str24));
      OMstruct_D__set(3, t2, 4);
      t3 = OFstruct_D__alloc(3);
      OMstruct_D__set(1, t3, ((string) &str25));
      OMstruct_D__set(2, t3, ((string) &str26));
      OMstruct_D__set(3, t3, 8);
      t4 = OFstruct_D__alloc(3);
      OMstruct_D__set(1, t4, ((string) &str27));
      OMstruct_D__set(2, t4, ((string) &str28));
      OMstruct_D__set(3, t4, 5);
      t5 = OFstruct_D__alloc(3);
      OMstruct_D__set(1, t5, ((string) &str29));
      OMstruct_D__set(2, t5, ((string) &str30));
      OMstruct_D__set(3, t5, 3);
      t6 = OFstruct_D__alloc(3);
      OMstruct_D__set(1, t6, ((string) &str31));
      OMstruct_D__set(2, t6, ((string) &str32));
      OMstruct_D__set(3, t6, 6);
      t7 = OFstruct_D__alloc(3);
      OMstruct_D__set(1, t7, ((string) &str33));
      OMstruct_D__set(2, t7, ((string) &str34));
      OMstruct_D__set(3, t7, 7);
      t8 = OFsequence_D__alloc(7);
      OMsequence_D__store(t8, 1, t1);
      OMsequence_D__store(t8, 2, t2);
      OMsequence_D__store(t8, 3, t3);
      OMsequence_D__store(t8, 4, t4);
      OMsequence_D__store(t8, 5, t5);
      OMsequence_D__store(t8, 6, t6);
      OMsequence_D__store(t8, 7, t7);
      WVops = t8;
    }
  /* begin body */
    {
      object LVe= 0;
      for (t1 = WVops, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVe = OMsequence_Dfetch(t1, t2);
	    {
	      if (OFstring_Dsubstr(LVop, 1, OMstruct_Dget(3, LVe)) == SIG)
	        {
		  goto except0;
	        }
	      t4 = retval_area[0];
	      if (OMstring_Dequal(t4, OMstruct_Dget(1, LVe)))
	        {
		  retval_area[0] = OMstruct_Dget(2, LVe);
		  return RET;
	        }
	    }
        }
    }
  retval_area[0] = LVop;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFconv__initfun */
/* clu_operation_name, conv_initfun */
int AFconv__initfun(LVowner)
     object LVowner;
{
  int t1, t2;
  /* begin body */
  if (AFdiscr__clu(LVowner) == SIG)
    {
      goto except0;
    }
  t1 = OMstring_Dsize(((string) &str9))
       + OMstring_Dsize(retval_area[0]);
  t2 = OFstring_D__predict(t1);
  OFstring_D__concat(t2, ((string) &str9));
  OFstring_D__concat(t2, retval_area[0]);
  retval_area[0] = t2;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFconv__localvar */
/* clu_operation_name, conv_localvar */
int AFconv__localvar(LVvar)
     object LVvar;
{
  int t1, t2;
  /* begin body */
  if (AFconv__idn__j10n(LVvar) == SIG)
    {
      goto except0;
    }
  t1 = OMstring_Dsize(((string) &str35))
       + OMstring_Dsize(retval_area[0]);
  t2 = OFstring_D__predict(t1);
  OFstring_D__concat(t2, ((string) &str35));
  OFstring_D__concat(t2, retval_area[0]);
  retval_area[0] = t2;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFconv__ownvar__app */
/* clu_operation_name, conv_ownvar_app */
int AFconv__ownvar__app(LVvar, LVowner, LVparmed)
     object LVvar;
     object LVowner;
     object LVparmed;
{
  int t1, t2, t3;
  /* begin body */
  if (LVparmed)
    {
      if (AFconv__idn__j10n(LVvar) == SIG)
        {
	  goto except0;
        }
      t1 = retval_area[0];
      if (AFdiscr__app(LVowner) == SIG)
        {
	  goto except0;
        }
      t2 = OMstring_Dsize(((string) &str36))
           + OMstring_Dsize(t1)
           + OMstring_Dsize(retval_area[0]);
      t3 = OFstring_D__predict(t2);
      OFstring_D__concat(t3, ((string) &str36));
      OFstring_D__concat(t3, t1);
      OFstring_D__concat(t3, retval_area[0]);
      retval_area[0] = t3;
      return RET;
    }
  else
    {
      if (AFconv__idn__j10n(LVvar) == SIG)
        {
	  goto except0;
        }
      t1 = OMstring_Dsize(((string) &str36))
           + OMstring_Dsize(retval_area[0]);
      t2 = OFstring_D__predict(t1);
      OFstring_D__concat(t2, ((string) &str36));
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
/* c_function_name, AFconv__ownvar__op */
/* clu_operation_name, conv_ownvar_op */
int AFconv__ownvar__op(LVvar, LVprovider, LVop, LVparmed)
     object LVvar;
     object LVprovider;
     object LVop;
     object LVparmed;
{
  int t1, t2, t3;
  /* begin body */
  if (LVparmed)
    {
      if (AFconv__idn__j10n(LVvar) == SIG)
        {
	  goto except0;
        }
      t1 = retval_area[0];
      if (AFdiscr__op(LVprovider, LVop) == SIG)
        {
	  goto except0;
        }
      t2 = OMstring_Dsize(((string) &str36))
           + OMstring_Dsize(t1)
           + OMstring_Dsize(retval_area[0]);
      t3 = OFstring_D__predict(t2);
      OFstring_D__concat(t3, ((string) &str36));
      OFstring_D__concat(t3, t1);
      OFstring_D__concat(t3, retval_area[0]);
      retval_area[0] = t3;
      return RET;
    }
  else
    {
      if (AFconv__idn__j10n(LVvar) == SIG)
        {
	  goto except0;
        }
      t1 = OMstring_Dsize(((string) &str36))
           + OMstring_Dsize(retval_area[0]);
      t2 = OFstring_D__predict(t1);
      OFstring_D__concat(t2, ((string) &str36));
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
/* c_function_name, AFconv__ownvar__clu */
/* clu_operation_name, conv_ownvar_clu */
int AFconv__ownvar__clu(LVvar, LVowner)
     object LVvar;
     object LVowner;
{
  int t1, t2, t3;
  /* begin body */
  if (AFconv__idn__j10n(LVvar) == SIG)
    {
      goto except0;
    }
  t1 = retval_area[0];
  if (AFdiscr__clu(LVowner) == SIG)
    {
      goto except0;
    }
  t2 = OMstring_Dsize(((string) &str36))
       + OMstring_Dsize(t1)
       + OMstring_Dsize(retval_area[0]);
  t3 = OFstring_D__predict(t2);
  OFstring_D__concat(t3, ((string) &str36));
  OFstring_D__concat(t3, t1);
  OFstring_D__concat(t3, retval_area[0]);
  retval_area[0] = t3;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFconv__initvar__app */
/* clu_operation_name, conv_initvar_app */
int AFconv__initvar__app(LVowner, LVparmed)
     object LVowner;
     object LVparmed;
{
  int t1, t2;
  /* begin body */
  if (LVparmed)
    {
      if (AFdiscr__app(LVowner) == SIG)
        {
	  goto except0;
        }
      t1 = OMstring_Dsize(((string) &str37))
           + OMstring_Dsize(retval_area[0]);
      t2 = OFstring_D__predict(t1);
      OFstring_D__concat(t2, ((string) &str37));
      OFstring_D__concat(t2, retval_area[0]);
      retval_area[0] = t2;
      return RET;
    }
  else
    {
      retval_area[0] = ((string) &str37);
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
/* c_function_name, AFconv__initvar__op */
/* clu_operation_name, conv_initvar_op */
int AFconv__initvar__op(LVprovider, LVop, LVparmed)
     object LVprovider;
     object LVop;
     object LVparmed;
{
  int t1, t2;
  /* begin body */
  if (LVparmed)
    {
      if (AFdiscr__op(LVprovider, LVop) == SIG)
        {
	  goto except0;
        }
      t1 = OMstring_Dsize(((string) &str37))
           + OMstring_Dsize(retval_area[0]);
      t2 = OFstring_D__predict(t1);
      OFstring_D__concat(t2, ((string) &str37));
      OFstring_D__concat(t2, retval_area[0]);
      retval_area[0] = t2;
      return RET;
    }
  else
    {
      retval_area[0] = ((string) &str37);
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
/* c_function_name, AFconv__initvar__clu */
/* clu_operation_name, conv_initvar_clu */
int AFconv__initvar__clu(LVowner)
     object LVowner;
{
  int t1, t2;
  /* begin body */
  if (AFdiscr__clu(LVowner) == SIG)
    {
      goto except0;
    }
  t1 = OMstring_Dsize(((string) &str37))
       + OMstring_Dsize(retval_area[0]);
  t2 = OFstring_D__predict(t1);
  OFstring_D__concat(t2, ((string) &str37));
  OFstring_D__concat(t2, retval_area[0]);
  retval_area[0] = t2;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFconv__entptr__app */
/* clu_operation_name, conv_entptr_app */
int AFconv__entptr__app(LVapply, LVid)
     object LVapply;
     object LVid;
{
  /* begin body */
  if (AFdiscr__app(LVapply) == SIG)
    {
      goto except0;
    }
  if (AFconv__entptr(LVid, retval_area[0]) == SIG)
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
/* c_function_name, AFconv__entptr__op */
/* clu_operation_name, conv_entptr_op */
int AFconv__entptr__op(LVprovider, LVop, LVid)
     object LVprovider;
     object LVop;
     object LVid;
{
  /* begin body */
  if (AFdiscr__op(LVprovider, LVop) == SIG)
    {
      goto except0;
    }
  if (AFconv__entptr(LVid, retval_area[0]) == SIG)
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
/* c_function_name, AFconv__entptr */
/* clu_operation_name, conv_entptr */
int AFconv__entptr(LVid, LVdiscr)
     object LVid;
     object LVdiscr;
{
  int t1, t2;
  /* begin body */
  OFint_Dunparse(LVid);
  t1 = OMstring_Dsize(((string) &str38))
       + OMstring_Dsize(retval_area[0])
       + OMstring_Dsize(LVdiscr);
  t2 = OFstring_D__predict(t1);
  OFstring_D__concat(t2, ((string) &str38));
  OFstring_D__concat(t2, retval_area[0]);
  OFstring_D__concat(t2, LVdiscr);
  retval_area[0] = t2;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFconv__tidvar__app */
/* clu_operation_name, conv_tidvar_app */
int AFconv__tidvar__app(LVapply, LVid)
     object LVapply;
     object LVid;
{
  /* begin body */
  if (AFdiscr__app(LVapply) == SIG)
    {
      goto except0;
    }
  if (AFconv__tidvar(LVid, retval_area[0]) == SIG)
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
/* c_function_name, AFconv__tidvar__op */
/* clu_operation_name, conv_tidvar_op */
int AFconv__tidvar__op(LVprovider, LVop, LVid)
     object LVprovider;
     object LVop;
     object LVid;
{
  /* begin body */
  if (AFdiscr__op(LVprovider, LVop) == SIG)
    {
      goto except0;
    }
  if (AFconv__tidvar(LVid, retval_area[0]) == SIG)
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
/* c_function_name, AFconv__tidvar */
/* clu_operation_name, conv_tidvar */
int AFconv__tidvar(LVid, LVdiscr)
     object LVid;
     object LVdiscr;
{
  int t1, t2;
  /* begin body */
  OFint_Dunparse(LVid);
  t1 = OMstring_Dsize(((string) &str39))
       + OMstring_Dsize(retval_area[0])
       + OMstring_Dsize(LVdiscr);
  t2 = OFstring_D__predict(t1);
  OFstring_D__concat(t2, ((string) &str39));
  OFstring_D__concat(t2, retval_area[0]);
  OFstring_D__concat(t2, LVdiscr);
  retval_area[0] = t2;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFdiscr__app */
/* clu_operation_name, discr_app */
int AFdiscr__app(LVapply)
     object LVapply;
{
  int t1, t2;
  /* begin body */
  if (AFconv__idn__j10n(LVapply) == SIG)
    {
      goto except0;
    }
  t1 = OMstring_Dsize(((string) &str40))
       + OMstring_Dsize(retval_area[0]);
  t2 = OFstring_D__predict(t1);
  OFstring_D__concat(t2, ((string) &str40));
  OFstring_D__concat(t2, retval_area[0]);
  retval_area[0] = t2;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFdiscr__clu */
/* clu_operation_name, discr_clu */
int AFdiscr__clu(LVclu)
     object LVclu;
{
  int t1, t2;
  /* begin body */
  if (AFconv__idn__j10n(LVclu) == SIG)
    {
      goto except0;
    }
  t1 = OMstring_Dsize(((string) &str41))
       + OMstring_Dsize(retval_area[0]);
  t2 = OFstring_D__predict(t1);
  OFstring_D__concat(t2, ((string) &str41));
  OFstring_D__concat(t2, retval_area[0]);
  retval_area[0] = t2;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFdiscr__op */
/* clu_operation_name, discr_op */
int AFdiscr__op(LVprovider, LVop)
     object LVprovider;
     object LVop;
{
  int t1, t2, t3;
  /* begin body */
  if (OMstring_Dequal(LVop, ((string) &str8)))
    {
      if (AFconv__initfun(LVprovider) == SIG)
        {
	  goto except0;
        }
      t1 = OMstring_Dsize(((string) &str42))
           + OMstring_Dsize(retval_area[0]);
      t2 = OFstring_D__predict(t1);
      OFstring_D__concat(t2, ((string) &str42));
      OFstring_D__concat(t2, retval_area[0]);
      retval_area[0] = t2;
      return RET;
    }
  if (OMstring_Dbounds(LVop, 1))
    {
      signame = SLBOUNDS;
      goto except0;
    }
  if (OMchar_Dequal(OMstring_Dfetch(LVop, 1), '%'))
    {
      if (OFstring_Drest(LVop, 2) == SIG)
        {
	  goto except0;
        }
      LVop = retval_area[0];
    }
  if (AFconv__idn__j10n(LVprovider) == SIG)
    {
      goto except0;
    }
  t1 = retval_area[0];
  if (AFconv__idn__j10n(LVop) == SIG)
    {
      goto except0;
    }
  t2 = OMstring_Dsize(((string) &str40))
       + OMstring_Dsize(t1)
       + OMstring_Dsize(((string) &str7))
       + OMstring_Dsize(retval_area[0]);
  t3 = OFstring_D__predict(t2);
  OFstring_D__concat(t3, ((string) &str40));
  OFstring_D__concat(t3, t1);
  OFstring_D__concat(t3, ((string) &str7));
  OFstring_D__concat(t3, retval_area[0]);
  retval_area[0] = t3;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFconv__idn__j10n */
/* clu_operation_name, conv_idn_j10n */
int AFconv__idn__j10n(LVid)
     object LVid;
{
  static bool IV = FALSE;
  static object WVres= 0;
  object LVstate= 0;
  int t1, t2, t3, t4, t5;
  if (IV == FALSE)
    {
      IV = TRUE;
      OFarray_Dnew();
      WVres = retval_area[0];
    }
  /* begin body */
    {
        {
	  object LVc= 0;
	  for (t1 = LVid, t2 = 1, t3 = OMstring_Dsize(t1);
	       t2 <= t3;
	       t2++)
	    {
	      LVc = OMstring_Dfetch(t1, t2);
	        {
		  t4 = OMchar_Dequal(LVc, '_');
		  if (OMbool_Dor(t4, OMint_Dgt(OMchar_Dc2i(LVc), 127)))
		    {
		      signame = ((string) &str43);
		      goto except1;
		    }
	        }
	    }
        }
      retval_area[0] = LVid;
      return RET;
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, ((string) &str43)))
        {
        }
      else
        {
	  goto except0;
        }
    }
  if (OFarray_Dtrim(WVres, 1, 0) == SIG)
    {
      goto except0;
    }
  LVstate = 0;
    {
      object LVc= 0;
      for (t1 = LVid, t2 = 1, t3 = OMstring_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVc = OMstring_Dfetch(t1, t2);
	    {
	      if (OMint_Dle(OMchar_Dc2i(LVc), 127))
	        {
		  if (OMint_Dequal(LVstate, 1))
		    {
		      OMarray_Daddh(WVres, '_');
		      OMarray_Daddh(WVres, 'A');
		      LVstate = 0;
		    }
		  if (OMchar_Dequal(LVc, '_'))
		    {
		      OMarray_Daddh(WVres, LVc);
		    }
		  OMarray_Daddh(WVres, LVc);
	        }
	      else
	        {
		  if (OMint_Dequal(LVstate, 0))
		    {
		      OMarray_Daddh(WVres, '_');
		      OMarray_Daddh(WVres, 'X');
		      LVstate = 1;
		    }
		    {
		      object LVdigit= 0;
		      for (t4 = AFhex__digits(TRUE, &t5, OMchar_Dc2i(LVc));
		           t4 == YIELD;
		           t4 = AFhex__digits(FALSE, &t5, 0))
		        {
			  LVdigit = retval_area[0];
			    {
			      OMarray_Daddh(WVres, LVdigit);
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
    }
  OFstring_Dac2s(WVres);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFconv__idn__noj10n */
/* clu_operation_name, conv_idn_noj10n */
int AFconv__idn__noj10n(LVid)
     object LVid;
{
  static bool IV = FALSE;
  static object WVres= 0;
  int t1, t2, t3;
  if (IV == FALSE)
    {
      IV = TRUE;
      OFarray_Dnew();
      WVres = retval_area[0];
    }
  /* begin body */
  OFstring_Dindexc('_', LVid);
  if (OMint_Dequal(retval_area[0], 0))
    {
      retval_area[0] = LVid;
      return RET;
    }
  if (OFarray_Dtrim(WVres, 1, 0) == SIG)
    {
      goto except0;
    }
    {
      object LVc= 0;
      for (t1 = LVid, t2 = 1, t3 = OMstring_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVc = OMstring_Dfetch(t1, t2);
	    {
	      if (OMchar_Dequal(LVc, '_'))
	        {
		  OMarray_Daddh(WVres, LVc);
	        }
	      OMarray_Daddh(WVres, LVc);
	    }
        }
    }
  OFstring_Dac2s(WVres);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFhex__digits */
/* clu_operation_name, hex_digits */
#define INV_TOP 5
#define WORK_SIZE 7
int AFhex__digits(init, ivarp, LVi)
     bool init;
     int **ivarp;
     object LVi;
{
  static bool IV = FALSE;
  static object WVdigit__chars= 0;
  if (init)
    {
      *ivarp = (int*) malloc(WORK_SIZE*sizeof(int));
      (*ivarp)[1] = LVi;
    }
  else
    {
      switch ((*ivarp)[0])
  	{
  	  case 1: goto yield1;
  	}
    }
  if (IV == FALSE)
    {
      IV = TRUE;
      WVdigit__chars = ((string) &str44);
    }
  /* begin body */
  if (OMint_Dlt((*ivarp)[1], 0))
    {
      signame = ((string) &str45);
      return(SIG);
    }
    {
      for ((*ivarp)[INV_TOP+0] = 3; (*ivarp)[INV_TOP+0] >= 0; (*ivarp)[INV_TOP+0] -= 1)
        {
	  (*ivarp)[2] = (*ivarp)[INV_TOP+0];
	    {
	      if (OFint_Dpower(16, (*ivarp)[2]) == SIG)
	        {
		  goto except0;
	        }
	      (*ivarp)[3] = retval_area[0];
	      if (OMint_Dzero__divide((*ivarp)[3]))
	        {
		  signame = SLZERO_DIVIDE;
		  goto except0;
	        }
	      (*ivarp)[4] = OMint_Ddiv((*ivarp)[1], (*ivarp)[3]);
	      (*ivarp)[1] = OMint_Dsub((*ivarp)[1], OMint_Dmul((*ivarp)[4], (*ivarp)[3]));
	      (*ivarp)[INV_TOP+1] = OMint_Dadd((*ivarp)[4], 1);
	      if (OMstring_Dbounds(WVdigit__chars, (*ivarp)[INV_TOP+1]))
	        {
		  signame = SLBOUNDS;
		  goto except0;
	        }
	      retval_area[0] = OMstring_Dfetch(WVdigit__chars, (*ivarp)[INV_TOP+1]);
	      (*ivarp)[0] = 1;
	      return YIELD;
	    yield1:
	      NO_OPERATION;
	    }
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
/* c_function_name, AFdecode__var */
/* clu_operation_name, decode_var */
int AFdecode__var(LVvar)
     object LVvar;
{
  /* begin body */
  if (AFdecode__idn(LVvar) == SIG)
    {
      goto except0;
    }
  if (OFstring_Drest(retval_area[0], 3) == SIG)
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
/* c_function_name, AFdecode__idn */
/* clu_operation_name, decode_idn */
int AFdecode__idn(LVid)
     object LVid;
{
  object LVunderscore__flag= 0;
  object LVbyte__state= 0;
  object LVstate= 0;
  object LVcode= 0;
  object LVret= 0;
  int t1, t2, t3, t4, t5, t6, t7, t8, t9;
  /* begin body */
  LVunderscore__flag = FALSE;
  LVbyte__state = 1;
  LVstate = 0;
  LVcode = 0;
  OFarray_Dnew();
  LVret = retval_area[0];
    {
        {
	  object LVc= 0;
	  for (t1 = LVid, t2 = 1, t3 = OMstring_Dsize(t1);
	       t2 <= t3;
	       t2++)
	    {
	      LVc = OMstring_Dfetch(t1, t2);
	        {
		  if (OMbool_Dand(OMchar_Dequal(LVc, '_'), LVunderscore__flag))
		    {
		      OMarray_Daddh(LVret, LVc);
		      LVunderscore__flag = FALSE;
		    }
		  else
		    {
		      t4 = OMchar_Dequal(LVc, '_');
		      if (OMbool_Dand(t4, OMbool_Dnot(LVunderscore__flag)))
		        {
			  LVunderscore__flag = TRUE;
		        }
		      else
		        {
			  if (OMbool_Dand(OMchar_Dequal(LVc, 'A'), LVunderscore__flag))
			    {
			      LVstate = 0;
			    }
			  else
			    {
			      if (OMbool_Dand(OMchar_Dequal(LVc, 'X'), LVunderscore__flag))
			        {
				  LVstate = 1;
			        }
			      else
			        {
				  if (OMint_Dequal(LVstate, 0))
				    {
				      OMarray_Daddh(LVret, LVc);
				    }
				  else
				    {
				      t5 = OMint_Dequal(LVstate, 1);
				      if (OMbool_Dand(t5, OMint_Dequal(LVbyte__state, 1)))
				        {
					  if (AFhex2int(LVc) == SIG)
					    {
					      goto except0;
					    }
					  LVcode = retval_area[0];
					  LVbyte__state = 2;
				        }
				      else
				        {
					  t6 = OMint_Dequal(LVstate, 1);
					  if (OMbool_Dand(t6, OMint_Dequal(LVbyte__state, 2)))
					    {
					      t7 = OMint_Dmul(LVcode, 16);
					      if (AFhex2int(LVc) == SIG)
					        {
						  goto except0;
					        }
					      LVcode = OMint_Dadd(t7, retval_area[0]);
					      LVbyte__state = 3;
					    }
					  else
					    {
					      t7 = OMint_Dequal(LVstate, 1);
					      if (OMbool_Dand(t7, OMint_Dequal(LVbyte__state, 3)))
					        {
						  t8 = OMint_Dmul(LVcode, 16);
						  if (AFhex2int(LVc) == SIG)
						    {
						      goto except0;
						    }
						  LVcode = OMint_Dadd(t8, retval_area[0]);
						  LVbyte__state = 4;
					        }
					      else
					        {
						  t8 = OMint_Dequal(LVstate, 1);
						  if (OMbool_Dand(t8, OMint_Dequal(LVbyte__state, 4)))
						    {
						      t9 = OMint_Dmul(LVcode, 16);
						      if (AFhex2int(LVc) == SIG)
						        {
							  goto except0;
						        }
						      LVcode = OMint_Dadd(t9, retval_area[0]);
						      LVbyte__state = 1;
						      if (OMchar_Dillegal__char(LVcode))
						        {
							  signame = SLILLEGAL_CHAR;
							  goto except0;
						        }
						      OMarray_Daddh(LVret, OMchar_Di2c(LVcode));
						    }
					        }
					    }
				        }
				    }
			        }
			    }
		        }
		    }
	        }
	    }
        }
    }
  OFstring_Dac2s(LVret);
  retval_area[0] = retval_area[0];
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFhex2int */
/* clu_operation_name, hex2int */
int AFhex2int(LVid)
     object LVid;
{
  /* begin body */
  if (OMchar_Dequal(LVid, '0'))
    {
      retval_area[0] = 0;
      return RET;
    }
  else
    {
      if (OMchar_Dequal(LVid, '1'))
        {
	  retval_area[0] = 1;
	  return RET;
        }
      else
        {
	  if (OMchar_Dequal(LVid, '2'))
	    {
	      retval_area[0] = 2;
	      return RET;
	    }
	  else
	    {
	      if (OMchar_Dequal(LVid, '3'))
	        {
		  retval_area[0] = 3;
		  return RET;
	        }
	      else
	        {
		  if (OMchar_Dequal(LVid, '4'))
		    {
		      retval_area[0] = 4;
		      return RET;
		    }
		  else
		    {
		      if (OMchar_Dequal(LVid, '5'))
		        {
			  retval_area[0] = 5;
			  return RET;
		        }
		      else
		        {
			  if (OMchar_Dequal(LVid, '6'))
			    {
			      retval_area[0] = 6;
			      return RET;
			    }
			  else
			    {
			      if (OMchar_Dequal(LVid, '7'))
			        {
				  retval_area[0] = 7;
				  return RET;
			        }
			      else
			        {
				  if (OMchar_Dequal(LVid, '8'))
				    {
				      retval_area[0] = 8;
				      return RET;
				    }
				  else
				    {
				      if (OMchar_Dequal(LVid, '9'))
				        {
					  retval_area[0] = 9;
					  return RET;
				        }
				      else
				        {
					  if (OMchar_Dequal(LVid, 'a'))
					    {
					      retval_area[0] = 10;
					      return RET;
					    }
					  else
					    {
					      if (OMchar_Dequal(LVid, 'b'))
					        {
						  retval_area[0] = 11;
						  return RET;
					        }
					      else
					        {
						  if (OMchar_Dequal(LVid, 'c'))
						    {
						      retval_area[0] = 12;
						      return RET;
						    }
						  else
						    {
						      if (OMchar_Dequal(LVid, 'd'))
						        {
							  retval_area[0] = 13;
							  return RET;
						        }
						      else
						        {
							  if (OMchar_Dequal(LVid, 'e'))
							    {
							      retval_area[0] = 14;
							      return RET;
							    }
							  else
							    {
							      if (OMchar_Dequal(LVid, 'f'))
							        {
								  retval_area[0] = 15;
								  return RET;
							        }
							      else
							        {
								  signame = SLNOT_POSSIBLE;
								  return(SIG);
							        }
							    }
						        }
						    }
					        }
					    }
				        }
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
  noretval(SLNULL);
  return(SIG);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */
