/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,parse_parmlist,p_parmlist,scanner*/
/* depend,parse_fieldspeclist,p_fieldspeclist,scanner*/
/* depend,p_parmlist,e_env,p_parm,scanner*/
/* depend,p_fieldspeclist,e_env,p_fieldspec,scanner*/
/* depend,p_parm,e_env,p_l_bracket,p_r_bracket,p_tparm,scanner*/
/* depend,p_fieldspec,e_env,p_colon,p_tparm,scanner*/
/* depend,p_tparm,builtin_selector,clugen,cluinst,e_env,p_fieldspeclist,p_l_bracket,p_parmlist,p_r_bracket,scanner,selgen,selinst*/
/* depend,p_l_bracket,e_env,scanner*/
/* depend,p_r_bracket,e_env,scanner*/
/* depend,p_colon,e_env,scanner*/
/* depend,scanner,stream*/

#include <clu2c.h>

static STRING_REP(12) str1 = {12, {'s', 'y', 'n', 't', 'a', 'x', '_', 'e', 'r', 'r', 'o', 'r'}};
static STRING_REP(47) str2 = {47, {'i', 'd', 'e', 'n', 't', 'i', 'f', 'i', 'e', 'r', ',', ' ', 'f', 'o', 'r', 'm', 'a', 'l', ' ', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', ',', ' ', 'o', 'r', ' ', 'V', 'P', 'A', 'R', 'M', ' ', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd'}};
static STRING_REP(11) str3 = {11, {'e', 'n', 'd', '_', 'o', 'f', '_', 's', 'c', 'a', 'n'}};
static STRING_REP(19) str4 = {19, {'i', 'd', 'e', 'n', 't', 'i', 'f', 'i', 'e', 'r', ' ', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd'}};
static STRING_REP(36) str5 = {36, {'l', 'i', 't', 'e', 'r', 'a', 'l', ' ', 'o', 'r', ' ', 'f', 'o', 'r', 'm', 'a', 'l', ' ', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', ' ', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd'}};
static STRING_REP(39) str6 = {39, {'i', 'd', 'e', 'n', 't', 'i', 'f', 'i', 'e', 'r', ' ', 'o', 'r', ' ', 'f', 'o', 'r', 'm', 'a', 'l', ' ', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', ' ', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd'}};
static STRING_REP(12) str7 = {12, {'\'', '[', '\'', ' ', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd'}};
static STRING_REP(12) str8 = {12, {'\'', ']', '\'', ' ', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd'}};
static STRING_REP(12) str9 = {12, {'\'', ':', '\'', ' ', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd'}};
static STRING_REP(6) str10 = {6, {'f', 'o', 'r', 'm', 'a', 'l'}};
static STRING_REP(20) str11 = {20, {'n', 'o', 't', '_', 'f', 'o', 'r', 'm', 'a', 'l', '_', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r'}};
static STRING_REP(6) str12 = {6, {'v', 'p', 'a', 'r', 'm', '['}};
static STRING_REP(5) str13 = {5, {' ', '>', '>', '>', ' '}};
static STRING_REP(4) str14 = {4, {' ', '<', '<', '<'}};
static STRING_REP(1) str15 = {1, {'['}};
static STRING_REP(1) str16 = {1, {']'}};
static STRING_REP(1) str17 = {1, {':'}};
static STRING_REP(5) str18 = {5, {'V', 'P', 'A', 'R', 'M'}};
static STRING_REP(6) str19 = {6, {'F', 'O', 'R', 'M', 'A', 'L'}};
static STRING_REP(1) str20 = {1, {'_'}};
static STRING_REP(15) str21 = {15, {'(', '.', '.', '.', '1', ' ', 't', 'o', 'k', 'e', 'n', '.', '.', '.', ')'}};
static STRING_REP(4) str22 = {4, {'(', '.', '.', '.'}};
static STRING_REP(11) str23 = {11, {' ', 't', 'o', 'k', 'e', 'n', 's', '.', '.', '.', ')'}};

/* begin module */
/* c_function_name, AFparse__parmlist */
/* clu_operation_name, parse_parmlist */
int AFparse__parmlist(LVparms)
     object LVparms;
{
  object LVscan= 0;
  /* begin body */
  if (OFscanner_Dcreate(LVparms) == SIG)
    {
      goto except0;
    }
  LVscan = retval_area[0];
  if (AFp__parmlist(LVscan) == SIG)
    {
      goto except1;
    }
  retval_area[0] = retval_area[0];
  return RET;
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, ((string) &str1)))
        {
	  OFarray_Dnew();
	  retval_area[0] = retval_area[0];
	  return RET;
        }
      else
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
/* end module */

/* begin module */
/* c_function_name, AFparse__fieldspeclist */
/* clu_operation_name, parse_fieldspeclist */
int AFparse__fieldspeclist(LVparms)
     object LVparms;
{
  object LVscan= 0;
  /* begin body */
  if (OFscanner_Dcreate(LVparms) == SIG)
    {
      goto except0;
    }
  LVscan = retval_area[0];
  if (AFp__fieldspeclist(LVscan) == SIG)
    {
      goto except1;
    }
  retval_area[0] = retval_area[0];
  return RET;
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, ((string) &str1)))
        {
	  OFarray_Dnew();
	  retval_area[0] = retval_area[0];
	  return RET;
        }
      else
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
/* end module */

/* begin module */
/* c_function_name, AFp__parmlist */
/* clu_operation_name, p_parmlist */
int AFp__parmlist(LVscan)
     object LVscan;
{
  object LVresult= 0;
  int t1;
  /* begin body */
  OFarray_Dnew();
  LVresult = retval_area[0];
  while (TRUE)
    {
        {
	  if (OFscanner_Dpeek(LVscan) == SIG)
	    {
	      goto except1;
	    }
	  t1 = ((oneof) retval_area[0])->tag;
	  if (t1 == 3 || t1 == 2 || t1 == 6)
	    {
	        {
	        }
	    }
	  else
	    {
	      if (OMarray_Dempty(LVresult))
	        {
		  object LVee= 0;
		  if (OFe__env_Dget() == SIG)
		    {
		      goto except1;
		    }
		  LVee = retval_area[0];
		  if (OFscanner_Dhere(LVscan) == SIG)
		    {
		      goto except1;
		    }
		  if (OFe__env_Dparmerr(LVee, ((string) &str2), retval_area[0]) == SIG)
		    {
		      goto except1;
		    }
		  signame = ((string) &str1);
		  return(SIG);
	        }
	      else
	        {
		  break;
	        }
	    }
	  if (AFp__parm(LVscan) == SIG)
	    {
	      goto except2;
	    }
	  OMarray_Daddh(LVresult, retval_area[0]);
	  if (FALSE)
	    {
	    except2:
	      if (OMstring_Dequal(signame, ((string) &str1)))
	        {
		  return(SIG);
	        }
	      else
	        {
		  goto except1;
	        }
	    }
        }
    }
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
  retval_area[0] = LVresult;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFp__fieldspeclist */
/* clu_operation_name, p_fieldspeclist */
int AFp__fieldspeclist(LVscan)
     object LVscan;
{
  object LVresult= 0;
  int t1;
  /* begin body */
  OFarray_Dnew();
  LVresult = retval_area[0];
  while (TRUE)
    {
        {
	  if (OFscanner_Dpeek(LVscan) == SIG)
	    {
	      goto except1;
	    }
	  t1 = ((oneof) retval_area[0])->tag;
	  if (t1 == 3)
	    {
	        {
	        }
	    }
	  else
	    {
	      if (OMarray_Dempty(LVresult))
	        {
		  object LVee= 0;
		  if (OFe__env_Dget() == SIG)
		    {
		      goto except1;
		    }
		  LVee = retval_area[0];
		  if (OFscanner_Dhere(LVscan) == SIG)
		    {
		      goto except1;
		    }
		  if (OFe__env_Dparmerr(LVee, ((string) &str4), retval_area[0]) == SIG)
		    {
		      goto except1;
		    }
		  signame = ((string) &str1);
		  return(SIG);
	        }
	      else
	        {
		  break;
	        }
	      break;
	    }
	  if (AFp__fieldspec(LVscan) == SIG)
	    {
	      goto except2;
	    }
	  OMarray_Daddh(LVresult, retval_area[0]);
	  if (FALSE)
	    {
	    except2:
	      if (OMstring_Dequal(signame, ((string) &str1)))
	        {
		  return(SIG);
	        }
	      else
	        {
		  goto except1;
	        }
	    }
        }
    }
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
  retval_area[0] = LVresult;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFp__parm */
/* clu_operation_name, p_parm */
int AFp__parm(LVscan)
     object LVscan;
{
  object LVt= 0;
  int t1, t2;
  /* begin body */
  if (OFscanner_Dpeek(LVscan) == SIG)
    {
      goto except0;
    }
  LVt = retval_area[0];
  t1 = ((oneof) LVt)->tag;
  if (t1 == 3 || t1 == 2)
    {
        {
	  if (AFp__tparm(LVscan) == SIG)
	    {
	      goto except1;
	    }
	  OFoneof_Dmake(1, retval_area[0]);
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else if (t1 == 6)
    {
        {
	  object LVparm= 0;
	  if (OFscanner_Dnext(LVscan) == SIG)
	    {
	      goto except1;
	    }
	  if (AFp__l__bracket(LVscan) == SIG)
	    {
	      goto except1;
	    }
	  if (OFscanner_Dpeek(LVscan) == SIG)
	    {
	      goto except1;
	    }
	  t2 = ((oneof) retval_area[0])->tag;
	  if (t2 == 3)
	    {
	      object LVid= 0;
	      LVid = ((oneof) retval_area[0])->value;
	        {
		  OFoneof_Dmake(2, LVid);
		  LVparm = retval_area[0];
	        }
	    }
	  else if (t2 == 2)
	    {
	      object LVid= 0;
	      LVid = ((oneof) retval_area[0])->value;
	        {
		  OFoneof_Dmake(1, LVid);
		  LVparm = retval_area[0];
	        }
	    }
	  else
	    {
	      object LVee= 0;
	      if (OFe__env_Dget() == SIG)
	        {
		  goto except1;
	        }
	      LVee = retval_area[0];
	      if (OFscanner_Dhere(LVscan) == SIG)
	        {
		  goto except1;
	        }
	      if (OFe__env_Dparmerr(LVee, ((string) &str5), retval_area[0]) == SIG)
	        {
		  goto except1;
	        }
	      signame = ((string) &str1);
	      return(SIG);
	    }
	  if (OFscanner_Dnext(LVscan) == SIG)
	    {
	      goto except1;
	    }
	  if (AFp__r__bracket(LVscan) == SIG)
	    {
	      goto except1;
	    }
	  OFoneof_Dmake(2, LVparm);
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else
    {
      object LVee= 0;
      if (OFe__env_Dget() == SIG)
        {
	  goto except1;
        }
      LVee = retval_area[0];
      if (OFscanner_Dhere(LVscan) == SIG)
        {
	  goto except1;
        }
      if (OFe__env_Dparmerr(LVee, ((string) &str2), retval_area[0]) == SIG)
        {
	  goto except1;
        }
      signame = ((string) &str1);
      return(SIG);
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, ((string) &str1)))
        {
	  return(SIG);
        }
      else
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
/* end module */

/* begin module */
/* c_function_name, AFp__fieldspec */
/* clu_operation_name, p_fieldspec */
int AFp__fieldspec(LVscan)
     object LVscan;
{
  object LVsel= 0;
  object LVparm= 0;
  int t1;
  /* begin body */
  if (OFscanner_Dpeek(LVscan) == SIG)
    {
      goto except0;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 3)
    {
      object LVid= 0;
      LVid = ((oneof) retval_area[0])->value;
        {
	  if (OFscanner_Dnext(LVscan) == SIG)
	    {
	      goto except0;
	    }
	  LVsel = LVid;
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
      if (OFscanner_Dhere(LVscan) == SIG)
        {
	  goto except0;
        }
      if (OFe__env_Dparmerr(LVee, ((string) &str4), retval_area[0]) == SIG)
        {
	  goto except0;
        }
      signame = ((string) &str1);
      return(SIG);
    }
    {
      if (AFp__colon(LVscan) == SIG)
        {
	  goto except1;
        }
      if (AFp__tparm(LVscan) == SIG)
        {
	  goto except1;
        }
      LVparm = retval_area[0];
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, ((string) &str1)))
        {
	  return(SIG);
        }
      else
        {
	  goto except0;
        }
    }
  t1 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t1, LVparm);
  OMrecord_Dset(2, t1, LVsel);
  retval_area[0] = t1;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFp__tparm */
/* clu_operation_name, p_tparm */
int AFp__tparm(LVscan)
     object LVscan;
{
  int t1, t2;
  /* begin body */
  if (OFscanner_Dpeek(LVscan) == SIG)
    {
      goto except1;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 3)
    {
      object LVid= 0;
      LVid = ((oneof) retval_area[0])->value;
        {
	  if (OFscanner_Dnext(LVscan) == SIG)
	    {
	      goto except1;
	    }
	  if (AFbuiltin__selector(LVid) == SIG)
	    {
	      goto except1;
	    }
	  if (retval_area[0])
	    {
	      object LVparms= 0;
	      if (AFp__l__bracket(LVscan) == SIG)
	        {
		  goto except1;
	        }
	      if (AFp__fieldspeclist(LVscan) == SIG)
	        {
		  goto except1;
	        }
	      LVparms = retval_area[0];
	      if (AFp__r__bracket(LVscan) == SIG)
	        {
		  goto except1;
	        }
	      if (OFselgen_Dcreate(LVid) == SIG)
	        {
		  goto except1;
	        }
	      if (OFselinst_Dcreate(retval_area[0], LVparms) == SIG)
	        {
		  goto except1;
	        }
	      OFoneof_Dmake(3, retval_area[0]);
	      retval_area[0] = retval_area[0];
	      return RET;
	    }
	  else
	    {
	      object LVparms= 0;
	      if (OFscanner_Dpeek(LVscan) == SIG)
	        {
		  goto except2;
	        }
	      t2 = ((oneof) retval_area[0])->tag;
	      if (t2 == 4)
	        {
		    {
		      if (OFscanner_Dnext(LVscan) == SIG)
		        {
			  goto except2;
		        }
		      if (AFp__parmlist(LVscan) == SIG)
		        {
			  goto except2;
		        }
		      LVparms = retval_area[0];
		      if (AFp__r__bracket(LVscan) == SIG)
		        {
			  goto except2;
		        }
		    }
	        }
	      else
	        {
		  OFarray_Dnew();
		  LVparms = retval_area[0];
	        }
	      if (FALSE)
	        {
		except2:
		  if (OMstring_Dequal(signame, ((string) &str3)))
		    {
		      OFarray_Dnew();
		      LVparms = retval_area[0];
		    }
		  else
		    {
		      goto except1;
		    }
	        }
	      if (OFclugen_Dcreate(LVid) == SIG)
	        {
		  goto except1;
	        }
	      if (OFcluinst_Dcreate(retval_area[0], LVparms) == SIG)
	        {
		  goto except1;
	        }
	      OFoneof_Dmake(1, retval_area[0]);
	      retval_area[0] = retval_area[0];
	      return RET;
	    }
        }
    }
  else if (t1 == 2)
    {
      object LVid= 0;
      LVid = ((oneof) retval_area[0])->value;
        {
	  if (OFscanner_Dnext(LVscan) == SIG)
	    {
	      goto except1;
	    }
	  OFoneof_Dmake(2, LVid);
	  retval_area[0] = retval_area[0];
	  return RET;
        }
    }
  else
    {
      object LVee= 0;
      if (OFe__env_Dget() == SIG)
        {
	  goto except1;
        }
      LVee = retval_area[0];
      if (OFscanner_Dhere(LVscan) == SIG)
        {
	  goto except1;
        }
      if (OFe__env_Dparmerr(LVee, ((string) &str6), retval_area[0]) == SIG)
        {
	  goto except1;
        }
      signame = ((string) &str1);
      return(SIG);
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, ((string) &str1)))
        {
	  return(SIG);
        }
      else
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
/* end module */

/* begin module */
/* c_function_name, AFp__l__bracket */
/* clu_operation_name, p_l_bracket */
int AFp__l__bracket(LVscan)
     object LVscan;
{
  int t1;
  /* begin body */
  if (OFscanner_Dpeek(LVscan) == SIG)
    {
      goto except1;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 4)
    {
        {
	  if (OFscanner_Dnext(LVscan) == SIG)
	    {
	      goto except1;
	    }
	  return RET;
        }
    }
  else
    {
      object LVee= 0;
      if (OFe__env_Dget() == SIG)
        {
	  goto except1;
        }
      LVee = retval_area[0];
      if (OFscanner_Dhere(LVscan) == SIG)
        {
	  goto except1;
        }
      if (OFe__env_Dparmerr(LVee, ((string) &str7), retval_area[0]) == SIG)
        {
	  goto except1;
        }
      signame = ((string) &str1);
      return(SIG);
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, ((string) &str3)))
        {
	  object LVee= 0;
	  if (OFe__env_Dget() == SIG)
	    {
	      goto except0;
	    }
	  LVee = retval_area[0];
	  if (OFscanner_Dhere(LVscan) == SIG)
	    {
	      goto except0;
	    }
	  if (OFe__env_Dparmerr(LVee, ((string) &str7), retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  signame = ((string) &str1);
	  return(SIG);
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
/* end module */

/* begin module */
/* c_function_name, AFp__r__bracket */
/* clu_operation_name, p_r_bracket */
int AFp__r__bracket(LVscan)
     object LVscan;
{
  int t1;
  /* begin body */
  if (OFscanner_Dpeek(LVscan) == SIG)
    {
      goto except1;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 5)
    {
        {
	  if (OFscanner_Dnext(LVscan) == SIG)
	    {
	      goto except1;
	    }
	  return RET;
        }
    }
  else
    {
      object LVee= 0;
      if (OFe__env_Dget() == SIG)
        {
	  goto except1;
        }
      LVee = retval_area[0];
      if (OFscanner_Dhere(LVscan) == SIG)
        {
	  goto except1;
        }
      if (OFe__env_Dparmerr(LVee, ((string) &str8), retval_area[0]) == SIG)
        {
	  goto except1;
        }
      signame = ((string) &str1);
      return(SIG);
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, ((string) &str3)))
        {
	  object LVee= 0;
	  if (OFe__env_Dget() == SIG)
	    {
	      goto except0;
	    }
	  LVee = retval_area[0];
	  if (OFscanner_Dhere(LVscan) == SIG)
	    {
	      goto except0;
	    }
	  if (OFe__env_Dparmerr(LVee, ((string) &str8), retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  signame = ((string) &str1);
	  return(SIG);
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
/* end module */

/* begin module */
/* c_function_name, AFp__colon */
/* clu_operation_name, p_colon */
int AFp__colon(LVscan)
     object LVscan;
{
  int t1;
  /* begin body */
  if (OFscanner_Dpeek(LVscan) == SIG)
    {
      goto except1;
    }
  t1 = ((oneof) retval_area[0])->tag;
  if (t1 == 1)
    {
        {
	  if (OFscanner_Dnext(LVscan) == SIG)
	    {
	      goto except1;
	    }
	  return RET;
        }
    }
  else
    {
      object LVee= 0;
      if (OFe__env_Dget() == SIG)
        {
	  goto except1;
        }
      LVee = retval_area[0];
      if (OFscanner_Dhere(LVscan) == SIG)
        {
	  goto except1;
        }
      if (OFe__env_Dparmerr(LVee, ((string) &str9), retval_area[0]) == SIG)
        {
	  goto except1;
        }
      signame = ((string) &str1);
      return(SIG);
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, ((string) &str3)))
        {
	  object LVee= 0;
	  if (OFe__env_Dget() == SIG)
	    {
	      goto except0;
	    }
	  LVee = retval_area[0];
	  if (OFscanner_Dhere(LVscan) == SIG)
	    {
	      goto except0;
	    }
	  if (OFe__env_Dparmerr(LVee, ((string) &str9), retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  signame = ((string) &str1);
	  return(SIG);
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
/* end module */

/* begin module */
/* c_function_name, OFscanner_Dcreate */
/* clu_operation_name, scanner$create */
int OFscanner_Dcreate(LVparm)
     object LVparm;
{
  object LVsource= 0;
  object LVmax= 0;
  object LVi= 0;
  int t1;
  /* begin body */
  OFarray_Dnew();
  LVsource = retval_area[0];
  LVmax = OMstring_Dsize(LVparm);
  LVi = 1;
  while (TRUE)
    {
      if (!OMint_Dle(LVi, LVmax))
        {
	  break;
        }
        {
	  object LVc= 0;
	  if (OMstring_Dbounds(LVparm, LVi))
	    {
	      signame = SLBOUNDS;
	      goto except0;
	    }
	  LVc = OMstring_Dfetch(LVparm, LVi);
	  if (OMchar_Dequal(LVc, ' '))
	    {
	    }
	  else
	    {
	      if (OMchar_Dequal(LVc, '['))
	        {
		  OFoneof_Dmake(4, NIL);
		  OMarray_Daddh(LVsource, retval_area[0]);
	        }
	      else
	        {
		  if (OMchar_Dequal(LVc, ']'))
		    {
		      OFoneof_Dmake(5, NIL);
		      OMarray_Daddh(LVsource, retval_area[0]);
		    }
		  else
		    {
		      if (OMchar_Dequal(LVc, ':'))
		        {
			  OFoneof_Dmake(1, NIL);
			  OMarray_Daddh(LVsource, retval_area[0]);
		        }
		      else
		        {
			  if (OMchar_Dequal(LVc, 'f'))
			    {
			        {
				  object LVj= 0;
				  object LVk= 0;
				  if (OFstring_Dsubstr(LVparm, LVi, 6) == SIG)
				    {
				      goto except1;
				    }
				  if (OMbool_Dnot(OMstring_Dequal(retval_area[0], ((string) &str10))))
				    {
				      signame = ((string) &str11);
				      goto except1;
				    }
				  LVj = OMint_Dadd(LVi, 6);
				  LVk = LVj;
				  while (TRUE)
				    {
				      if (!OMint_Dlt(LVk, LVmax))
				        {
					  break;
				        }
				        {
					  object LVch= 0;
					  if (OMstring_Dbounds(LVparm, LVk))
					    {
					      signame = SLBOUNDS;
					      goto except1;
					    }
					  LVch = OMstring_Dfetch(LVparm, LVk);
					  t1 = OMchar_Dlt(LVch, '0');
					  if (OMbool_Dor(t1, OMchar_Dlt('9', LVch)))
					    {
					      break;
					    }
					  LVk = OMint_Dadd(LVk, 1);
				        }
				    }
				  if (OMbool_Dnot(OMint_Dlt(LVj, LVk)))
				    {
				      t1 = TRUE;
				    }
				  else
				    {
				      if (OMstring_Dbounds(LVparm, LVk))
				        {
					  signame = SLBOUNDS;
					  goto except1;
				        }
				      t1 = OMbool_Dnot(OMchar_Dequal(OMstring_Dfetch(LVparm, LVk), '_'));
				    }
				  if (t1)
				    {
				      signame = ((string) &str11);
				      goto except1;
				    }
				  if (OFstring_Dsubstr(LVparm, LVj, OMint_Dsub(LVk, LVj)) == SIG)
				    {
				      goto except1;
				    }
				  if (OFint_Dparse(retval_area[0]) == SIG)
				    {
				      goto except1;
				    }
				  OFoneof_Dmake(2, retval_area[0]);
				  OMarray_Daddh(LVsource, retval_area[0]);
				  LVi = LVk;
			        }
			      if (FALSE)
			        {
				except1:
				  if (OMstring_Dequal(signame, ((string) &str11)))
				    {
				      object LVtk= 0;
				      if (OFscanner_Dparse__idn(LVparm, LVi) == SIG)
				        {
					  goto except0;
				        }
				      LVtk = retval_area[0];
				      LVi = retval_area[1];
				      OMarray_Daddh(LVsource, LVtk);
				    }
				  else
				    {
				      goto except0;
				    }
			        }
			    }
			  else
			    {
			      if (OMchar_Dequal(LVc, 'v'))
			        {
				  if (OFstring_Dsubstr(LVparm, LVi, 6) == SIG)
				    {
				      goto except0;
				    }
				  if (OMstring_Dequal(retval_area[0], ((string) &str12)))
				    {
				      OFoneof_Dmake(6, NIL);
				      OMarray_Daddh(LVsource, retval_area[0]);
				      LVi = OMint_Dadd(LVi, 4);
				    }
				  else
				    {
				      object LVtk= 0;
				      if (OFscanner_Dparse__idn(LVparm, LVi) == SIG)
				        {
					  goto except0;
				        }
				      LVtk = retval_area[0];
				      LVi = retval_area[1];
				      OMarray_Daddh(LVsource, LVtk);
				    }
			        }
			      else
			        {
				  object LVtk= 0;
				  if (OFscanner_Dparse__idn(LVparm, LVi) == SIG)
				    {
				      goto except0;
				    }
				  LVtk = retval_area[0];
				  LVi = retval_area[1];
				  OMarray_Daddh(LVsource, LVtk);
			        }
			    }
		        }
		    }
	        }
	    }
	  LVi = OMint_Dadd(LVi, 1);
        }
    }
  t1 = OFrecord_D__alloc(2);
  OMrecord_Dset(1, t1, 1);
  OMrecord_Dset(2, t1, LVsource);
  retval_area[0] = t1;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFscanner_Dempty */
/* clu_operation_name, scanner$empty */
int OFscanner_Dempty(LVs)
     object LVs;
{
  int t1;
  /* begin body */
  t1 = OMrecord_Dget(1, LVs);
  retval_area[0] = OMint_Dgt(t1, OMarray_Dhigh(OMrecord_Dget(2, LVs)));
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFscanner_Dpeek */
/* clu_operation_name, scanner$peek */
int OFscanner_Dpeek(LVs)
     object LVs;
{
  int t1, t2;
  /* begin body */
  t1 = OMrecord_Dget(2, LVs);
  t2 = OMrecord_Dget(1, LVs);
  if (OMarray_Dbounds(t1, t2))
    {
      signame = SLBOUNDS;
      goto except1;
    }
  retval_area[0] = OMarray_Dfetch(t1, t2);
  return RET;
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLBOUNDS))
        {
	  signame = ((string) &str3);
	  return(SIG);
        }
      else
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
/* c_function_name, OFscanner_Dnext */
/* clu_operation_name, scanner$next */
int OFscanner_Dnext(LVs)
     object LVs;
{
  int t1;
  /* begin body */
  t1 = OMrecord_Dget(1, LVs);
  if (OMint_Dle(t1, OMarray_Dhigh(OMrecord_Dget(2, LVs))))
    {
      OMrecord_Dset(1, LVs, OMint_Dadd(OMrecord_Dget(1, LVs), 1));
    }
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFscanner_Dhere */
/* clu_operation_name, scanner$here */
int OFscanner_Dhere(LVs)
     object LVs;
{
  object LVsource= 0;
  object LVindex= 0;
  object LVres= 0;
  object LVstart= 0;
  object LVfirst= 0;
  object LVrest= 0;
  int t1, t2, t3;
  /* begin body */
  LVsource = OMrecord_Dget(2, LVs);
  LVindex = OMrecord_Dget(1, LVs);
  if (OFstream_Dcreate__output() == SIG)
    {
      goto except0;
    }
  LVres = retval_area[0];
  LVstart = 1;
  if (OMint_Dgt(LVindex, 4))
    {
      if (OFscanner_Dput__nr__tokens(OMint_Dsub(LVindex, 4), LVres) == SIG)
        {
	  goto except0;
        }
      if (OFstream_Dputspace(LVres, 1) == SIG)
        {
	  goto except0;
        }
      LVstart = OMint_Dsub(LVindex, 3);
    }
  LVfirst = TRUE;
    {
      object LVi= 0;
      for (t1 = LVstart, t2 = OMint_Dsub(LVindex, 1); t1 <= t2; t1++)
        {
	  LVi = t1;
	    {
	      if (LVfirst)
	        {
		  LVfirst = FALSE;
	        }
	      else
	        {
		  if (OFstream_Dputspace(LVres, 1) == SIG)
		    {
		      goto except0;
		    }
	        }
	      if (OMarray_Dbounds(LVsource, LVi))
	        {
		  signame = SLBOUNDS;
		  goto except0;
	        }
	      if (OFscanner_Dunparse__token(OMarray_Dfetch(LVsource, LVi)) == SIG)
	        {
		  goto except0;
	        }
	      if (OFstream_Dputs(LVres, retval_area[0]) == SIG)
	        {
		  goto except0;
	        }
	    }
        }
    }
  if (OFstream_Dputs(LVres, ((string) &str13)) == SIG)
    {
      goto except0;
    }
  if (OMarray_Dbounds(LVsource, LVindex))
    {
      signame = SLBOUNDS;
      goto except0;
    }
  if (OFscanner_Dunparse__token(OMarray_Dfetch(LVsource, LVindex)) == SIG)
    {
      goto except0;
    }
  if (OFstream_Dputs(LVres, retval_area[0]) == SIG)
    {
      goto except0;
    }
  if (OFstream_Dputs(LVres, ((string) &str14)) == SIG)
    {
      goto except0;
    }
    {
      object LVi= 0;
      t1 = OMint_Dadd(LVindex, 1);
      for (t2 = t1, t3 = OMint_Dadd(LVindex, 3); t2 <= t3; t2++)
        {
	  LVi = t2;
	    {
	      if (OFstream_Dputspace(LVres, 1) == SIG)
	        {
		  goto except1;
	        }
	      if (OMarray_Dbounds(LVsource, LVi))
	        {
		  signame = SLBOUNDS;
		  goto except1;
	        }
	      if (OFscanner_Dunparse__token(OMarray_Dfetch(LVsource, LVi)) == SIG)
	        {
		  goto except1;
	        }
	      if (OFstream_Dputs(LVres, retval_area[0]) == SIG)
	        {
		  goto except1;
	        }
	    }
        }
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
  LVrest = OMint_Dsub(OMint_Dsub(OMarray_Dsize(LVsource), LVindex), 3);
  if (OMint_Dgt(LVrest, 0))
    {
      if (OFstream_Dputspace(LVres, 1) == SIG)
        {
	  goto except0;
        }
      if (OFscanner_Dput__nr__tokens(LVrest, LVres) == SIG)
        {
	  goto except0;
        }
    }
  if (OFstream_Dget__contents(LVres) == SIG)
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
/* c_function_name, OFscanner_Dparse__idn */
/* clu_operation_name, scanner$parse_idn */
int OFscanner_Dparse__idn(LVparm, LVi)
     object LVparm;
     object LVi;
{
  object LVmax= 0;
  object LVj= 0;
  int t1, t2, t3;
  /* begin body */
  LVmax = OMstring_Dsize(LVparm);
  LVj = LVi;
  while (TRUE)
    {
      if (!OMint_Dle(LVj, LVmax))
        {
	  break;
        }
        {
	  object LVc= 0;
	  if (OMstring_Dbounds(LVparm, LVj))
	    {
	      signame = SLBOUNDS;
	      goto except0;
	    }
	  LVc = OMstring_Dfetch(LVparm, LVj);
	  t1 = OMchar_Dequal(LVc, '[');
	  t2 = OMbool_Dor(t1, OMchar_Dequal(LVc, ']'));
	  t3 = OMbool_Dor(t2, OMchar_Dequal(LVc, ':'));
	  if (OMbool_Dor(t3, OMchar_Dequal(LVc, ' ')))
	    {
	      break;
	    }
	  LVj = OMint_Dadd(LVj, 1);
        }
    }
  if (OFstring_Dsubstr(LVparm, LVi, OMint_Dsub(LVj, LVi)) == SIG)
    {
      goto except0;
    }
  OFoneof_Dmake(3, retval_area[0]);
  t1 = retval_area[0];
  t2 = t1;
  t3 = OMint_Dsub(LVj, 1);
  retval_area[0] = t2;
  retval_area[1] = t3;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFscanner_Dunparse__token */
/* clu_operation_name, scanner$unparse_token */
int OFscanner_Dunparse__token(LVt)
     object LVt;
{
  int t1, t2, t3;
  /* begin body */
  t1 = ((oneof) LVt)->tag;
  if (t1 == 3)
    {
      object LVs= 0;
      LVs = ((oneof) LVt)->value;
        {
	  retval_area[0] = LVs;
	  return RET;
        }
    }
  else if (t1 == 4)
    {
        {
	  retval_area[0] = ((string) &str15);
	  return RET;
        }
    }
  else if (t1 == 5)
    {
        {
	  retval_area[0] = ((string) &str16);
	  return RET;
        }
    }
  else if (t1 == 1)
    {
        {
	  retval_area[0] = ((string) &str17);
	  return RET;
        }
    }
  else if (t1 == 6)
    {
        {
	  retval_area[0] = ((string) &str18);
	  return RET;
        }
    }
  else if (t1 == 2)
    {
      object LVid= 0;
      LVid = ((oneof) LVt)->value;
        {
	  OFint_Dunparse(LVid);
	  t2 = OMstring_Dsize(((string) &str19))
	       + OMstring_Dsize(retval_area[0])
	       + OMstring_Dsize(((string) &str20));
	  t3 = OFstring_D__predict(t2);
	  OFstring_D__concat(t3, ((string) &str19));
	  OFstring_D__concat(t3, retval_area[0]);
	  OFstring_D__concat(t3, ((string) &str20));
	  retval_area[0] = t3;
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
/* c_function_name, OFscanner_Dput__nr__tokens */
/* clu_operation_name, scanner$put_nr_tokens */
int OFscanner_Dput__nr__tokens(LVn, LVoutst)
     object LVn;
     object LVoutst;
{
  /* begin body */
  if (OMint_Dequal(LVn, 1))
    {
      if (OFstream_Dputs(LVoutst, ((string) &str21)) == SIG)
        {
	  goto except0;
        }
    }
  else
    {
      if (OMint_Dgt(LVn, 1))
        {
	  if (OFstream_Dputs(LVoutst, ((string) &str22)) == SIG)
	    {
	      goto except0;
	    }
	  OFint_Dunparse(LVn);
	  if (OFstream_Dputs(LVoutst, retval_area[0]) == SIG)
	    {
	      goto except0;
	    }
	  if (OFstream_Dputs(LVoutst, ((string) &str23)) == SIG)
	    {
	      goto except0;
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