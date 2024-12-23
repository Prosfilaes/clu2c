/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,getopt,program_name,stream*/

#include <clu2c.h>

static STRING_REP(1) str1 = {1, {'-'}};
static STRING_REP(2) str2 = {2, {'-', '-'}};
static STRING_REP(11) str3 = {11, {'n', 'o', '_', 'a', 'r', 'g', 'u', 'm', 'e', 'n', 't'}};
static STRING_REP(14) str4 = {14, {'i', 'l', 'l', 'e', 'g', 'a', 'l', ' ', 'o', 'p', 't', 'i', 'o', 'n'}};
static STRING_REP(27) str5 = {27, {'o', 'p', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'q', 'u', 'i', 'r', 'e', 's', ' ', 'a', 'n', ' ', 'a', 'r', 'g', 'u', 'm', 'e', 'n', 't'}};
static STRING_REP(12) str6 = {12, {'u', 'n', 'r', 'e', 'c', 'o', 'g', 'n', 'i', 'z', 'e', 'd'}};
static STRING_REP(9) str7 = {9, {'a', 'm', 'b', 'i', 'g', 'u', 'o', 'u', 's'}};
static STRING_REP(12) str8 = {12, {'i', 's', ' ', 'a', 'm', 'b', 'i', 'g', 'u', 'o', 'u', 's'}};
static STRING_REP(25) str9 = {25, {'d', 'o', 'e', 's', 'n', '\'', 't', ' ', 'a', 'l', 'l', 'o', 'w', ' ', 'a', 'n', ' ', 'a', 'r', 'g', 'u', 'm', 'e', 'n', 't'}};
static STRING_REP(20) str10 = {20, {'r', 'e', 'q', 'u', 'i', 'r', 'e', 's', ' ', 'a', 'n', ' ', 'a', 'r', 'g', 'u', 'm', 'e', 'n', 't'}};
static STRING_REP(2) str11 = {2, {':', ' '}};
static STRING_REP(4) str12 = {4, {' ', '-', '-', ' '}};
static STRING_REP(11) str13 = {11, {' ', 'o', 'p', 't', 'i', 'o', 'n', ' ', '`', '-', '-'}};

/* begin module */
/* c_function_name, OFgetopt_Dcreate */
/* clu_operation_name, getopt$create */
int OFgetopt_Dcreate(LVargv, LVoptstring)
     object LVargv;
     object LVoptstring;
{
  static bool IV = FALSE;
  static object WVempty__longopts= 0;
  if (IV == FALSE)
    {
      IV = TRUE;
      OFsequence_Dnew();
      WVempty__longopts = retval_area[0];
    }
  /* begin body */
  if (OMstring_Dempty(LVoptstring))
    {
      signame = SLBAD_FORMAT;
      return(SIG);
    }
  if (OFgetopt_Dcreate__long(LVargv, LVoptstring, WVempty__longopts) == SIG)
    {
      goto except1;
    }
  retval_area[0] = retval_area[0];
  return RET;
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLBAD_FORMAT))
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
/* c_function_name, OFgetopt_Dcreate__long */
/* clu_operation_name, getopt$create_long */
int OFgetopt_Dcreate__long(LVargv, LVshortopts, LVlongopts)
     object LVargv;
     object LVshortopts;
     object LVlongopts;
{
  int t1, t2, t3, t4, t5;
  /* begin body */
  if (OMstring_Dbounds(LVshortopts, 1))
    {
      signame = SLBOUNDS;
      goto except1;
    }
  if (OMchar_Dequal(OMstring_Dfetch(LVshortopts, 1), ':'))
    {
      signame = SLBAD_FORMAT;
      return(SIG);
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
    {
      object LVoption= 0;
      for (t1 = LVlongopts, t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVoption = OMsequence_Dfetch(t1, t2);
	    {
	      object LVarg= 0;
	      LVarg = OMstruct_Dget(1, LVoption);
	      t4 = FALSE;
	      t5 = FALSE;
	      if (OMbool_Dnot(OMint_Dequal(LVarg, 0)))
	        {
		  if (OMbool_Dnot(OMint_Dequal(LVarg, 1)))
		    {
		      t5 = TRUE;
		    }
	        }
	      if (t5)
	        {
		  if (OMbool_Dnot(OMint_Dequal(LVarg, 2)))
		    {
		      t4 = TRUE;
		    }
	        }
	      if (t4)
	        {
		  signame = SLBAD_FORMAT;
		  return(SIG);
	        }
	    }
        }
    }
  OFoneof_Dmake(1, NIL);
  t1 = retval_area[0];
  if (OFstream_Derror__output() == SIG)
    {
      goto except0;
    }
  t2 = OFrecord_D__alloc(8);
  OMrecord_Dset(1, t2, LVargv);
  OMrecord_Dset(2, t2, LVlongopts);
  OMrecord_Dset(3, t2, t1);
  OMrecord_Dset(4, t2, TRUE);
  OMrecord_Dset(5, t2, 1);
  OMrecord_Dset(6, t2, SLNULL);
  OMrecord_Dset(7, t2, retval_area[0]);
  OMrecord_Dset(8, t2, LVshortopts);
  retval_area[0] = t2;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFgetopt_Doptions */
/* clu_operation_name, getopt$options */
#define INV_TOP 4
#define WORK_SIZE 10
int OFgetopt_Doptions(init, ivarp, LVgo)
     bool init;
     int **ivarp;
     object LVgo;
{
  if (init)
    {
      *ivarp = (int*) malloc(WORK_SIZE*sizeof(int));
      (*ivarp)[1] = LVgo;
    }
  else
    {
      switch ((*ivarp)[0])
  	{
  	  case 1: goto yield1;
  	  case 2: goto yield2;
  	}
    }
  /* begin body */
  while (TRUE)
    {
      (*ivarp)[INV_TOP+0] = OMrecord_Dget(5, (*ivarp)[1]);
      if (!OMint_Dle((*ivarp)[INV_TOP+0], OMsequence_Dsize(OMrecord_Dget(1, (*ivarp)[1]))))
        {
	  break;
        }
        {
	  (*ivarp)[INV_TOP+1] = OMrecord_Dget(1, (*ivarp)[1]);
	  (*ivarp)[INV_TOP+2] = OMrecord_Dget(5, (*ivarp)[1]);
	  if (OMsequence_Dbounds((*ivarp)[INV_TOP+1], (*ivarp)[INV_TOP+2]))
	    {
	      signame = SLBOUNDS;
	      goto except0;
	    }
	  (*ivarp)[2] = OMsequence_Dfetch((*ivarp)[INV_TOP+1], (*ivarp)[INV_TOP+2]);
	  if (OMstring_Dempty((*ivarp)[2]))
	    {
	      (*ivarp)[INV_TOP+2] = TRUE;
	    }
	  else
	    {
	      if (OMstring_Dbounds((*ivarp)[2], 1))
	        {
		  signame = SLBOUNDS;
		  goto except0;
	        }
	      (*ivarp)[INV_TOP+2] = OMbool_Dnot(OMchar_Dequal(OMstring_Dfetch((*ivarp)[2], 1), '-'));
	    }
	  if ((*ivarp)[INV_TOP+2])
	    {
	      (*ivarp)[INV_TOP+1] = TRUE;
	    }
	  else
	    {
	      (*ivarp)[INV_TOP+1] = OMstring_Dequal((*ivarp)[2], ((string) &str1));
	    }
	  if ((*ivarp)[INV_TOP+1])
	    {
	      break;
	    }
	  else
	    {
	      if (OMstring_Dequal((*ivarp)[2], ((string) &str2)))
	        {
		  OMrecord_Dset(5, (*ivarp)[1], OMint_Dadd(OMrecord_Dget(5, (*ivarp)[1]), 1));
		  break;
	        }
	      else
	        {
		  (*ivarp)[INV_TOP+3] = FALSE;
		  if (OMstring_Dbounds((*ivarp)[2], 2))
		    {
		      signame = SLBOUNDS;
		      goto except0;
		    }
		  if (OMchar_Dequal(OMstring_Dfetch((*ivarp)[2], 2), '-'))
		    {
		      if (OMbool_Dnot(OMsequence_Dempty(OMrecord_Dget(2, (*ivarp)[1]))))
		        {
			  (*ivarp)[INV_TOP+3] = TRUE;
		        }
		    }
		  if ((*ivarp)[INV_TOP+3])
		    {
		      OMrecord_Dset(5, (*ivarp)[1], OMint_Dadd(OMrecord_Dget(5, (*ivarp)[1]), 1));
		      if (OFgetopt_Dparse__long__option((*ivarp)[1], (*ivarp)[2]) == SIG)
		        {
			  goto except0;
		        }
		      retval_area[0] = retval_area[0];
		      (*ivarp)[0] = 1;
		      return YIELD;
		    yield1:
		      NO_OPERATION;
		    }
		  else
		    {
		        {
			  for ((*ivarp)[INV_TOP+4] = OFgetopt_Dshort__options(TRUE, &(*ivarp)[INV_TOP+5], (*ivarp)[1], (*ivarp)[2]);
			       (*ivarp)[INV_TOP+4] == YIELD;
			       (*ivarp)[INV_TOP+4] = OFgetopt_Dshort__options(FALSE, &(*ivarp)[INV_TOP+5], 0, 0))
			    {
			      (*ivarp)[3] = retval_area[0];
			        {
				  retval_area[0] = (*ivarp)[3];
				  (*ivarp)[0] = 2;
				  return YIELD;
				yield2:
				  NO_OPERATION;
			        }
			    }
			  free((*ivarp)[INV_TOP+5]);
			  if ((*ivarp)[INV_TOP+4] == SIG)
			    {
			      goto except0;
			    }
		        }
		    }
	        }
	    }
        }
    }
  OMrecord_Dset(6, (*ivarp)[1], SLNULL);
  OFoneof_Dmake(1, NIL);
  OMrecord_Dset(3, (*ivarp)[1], retval_area[0]);
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
#undef INV_TOP
#undef WORK_SIZE
/* c_function_name, OFgetopt_Dget__optname */
/* clu_operation_name, getopt$get_optname */
int OFgetopt_Dget__optname(LVgo)
     object LVgo;
{
  /* begin body */
  retval_area[0] = OMrecord_Dget(6, LVgo);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFgetopt_Dget__optarg */
/* clu_operation_name, getopt$get_optarg */
int OFgetopt_Dget__optarg(LVgo)
     object LVgo;
{
  int t1, t2;
  /* begin body */
  t1 = OMrecord_Dget(3, LVgo);
  t2 = ((oneof) t1)->tag;
  if (t2 == 1)
    {
        {
	  signame = ((string) &str3);
	  return(SIG);
        }
    }
  else if (t2 == 2)
    {
      object LVarg= 0;
      LVarg = ((oneof) t1)->value;
        {
	  retval_area[0] = LVarg;
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
/* c_function_name, OFgetopt_Doptarg__is__empty */
/* clu_operation_name, getopt$optarg_is_empty */
int OFgetopt_Doptarg__is__empty(LVgo)
     object LVgo;
{
  /* begin body */
  retval_area[0] = OMoneof_Dis(1, OMrecord_Dget(3, LVgo));
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFgetopt_Doptarg__is__full */
/* clu_operation_name, getopt$optarg_is_full */
int OFgetopt_Doptarg__is__full(LVgo)
     object LVgo;
{
  /* begin body */
  retval_area[0] = OMoneof_Dis(2, OMrecord_Dget(3, LVgo));
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFgetopt_Dget__optind */
/* clu_operation_name, getopt$get_optind */
int OFgetopt_Dget__optind(LVgo)
     object LVgo;
{
  /* begin body */
  retval_area[0] = OMrecord_Dget(5, LVgo);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFgetopt_Dget__opterr */
/* clu_operation_name, getopt$get_opterr */
int OFgetopt_Dget__opterr(LVgo)
     object LVgo;
{
  /* begin body */
  retval_area[0] = OMrecord_Dget(4, LVgo);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFgetopt_Dset__opterr */
/* clu_operation_name, getopt$set_opterr */
int OFgetopt_Dset__opterr(LVgo, LVopterr)
     object LVgo;
     object LVopterr;
{
  /* begin body */
  OMrecord_Dset(4, LVgo, LVopterr);
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFgetopt_Dset__output */
/* clu_operation_name, getopt$set_output */
int OFgetopt_Dset__output(LVgo, LVoutput)
     object LVgo;
     object LVoutput;
{
  /* begin body */
  OMrecord_Dset(7, LVgo, LVoutput);
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFgetopt_Dget__non__options */
/* clu_operation_name, getopt$get_non_options */
int OFgetopt_Dget__non__options(LVgo)
     object LVgo;
{
  int t1, t2, t3;
  /* begin body */
  t1 = OMrecord_Dget(1, LVgo);
  t2 = OMrecord_Dget(5, LVgo);
  t3 = OMsequence_Dsize(OMrecord_Dget(1, LVgo));
  if (OFsequence_Dsubseq(t1, t2, OMint_Dadd(OMint_Dsub(t3, OMrecord_Dget(5, LVgo)), 1)) == SIG)
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
/* c_function_name, OFgetopt_Dnon__options */
/* clu_operation_name, getopt$non_options */
#define INV_TOP 3
#define WORK_SIZE 7
int OFgetopt_Dnon__options(init, ivarp, LVgo)
     bool init;
     int **ivarp;
     object LVgo;
{
  if (init)
    {
      *ivarp = (int*) malloc(WORK_SIZE*sizeof(int));
      (*ivarp)[1] = LVgo;
    }
  else
    {
      switch ((*ivarp)[0])
  	{
  	  case 1: goto yield1;
  	}
    }
  /* begin body */
    {
      (*ivarp)[INV_TOP+0] = OMrecord_Dget(5, (*ivarp)[1]);
      for ((*ivarp)[INV_TOP+1] = (*ivarp)[INV_TOP+0], (*ivarp)[INV_TOP+2] = OMsequence_Dsize(OMrecord_Dget(1, (*ivarp)[1])); (*ivarp)[INV_TOP+1] <= (*ivarp)[INV_TOP+2]; (*ivarp)[INV_TOP+1]++)
        {
	  (*ivarp)[2] = (*ivarp)[INV_TOP+1];
	    {
	      (*ivarp)[INV_TOP+3] = OMrecord_Dget(1, (*ivarp)[1]);
	      if (OMsequence_Dbounds((*ivarp)[INV_TOP+3], (*ivarp)[2]))
	        {
		  signame = SLBOUNDS;
		  goto except0;
	        }
	      retval_area[0] = OMsequence_Dfetch((*ivarp)[INV_TOP+3], (*ivarp)[2]);
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
/* c_function_name, OFgetopt_Dshort__options */
/* clu_operation_name, getopt$short_options */
#define INV_TOP 8
#define WORK_SIZE 10
int OFgetopt_Dshort__options(init, ivarp, LVgo, LVarg)
     bool init;
     int **ivarp;
     object LVgo;
     object LVarg;
{
  if (init)
    {
      *ivarp = (int*) malloc(WORK_SIZE*sizeof(int));
      (*ivarp)[1] = LVgo;
      (*ivarp)[2] = LVarg;
    }
  else
    {
      switch ((*ivarp)[0])
  	{
  	  case 1: goto yield1;
  	}
    }
  /* begin body */
  (*ivarp)[3] = 2;
  while (TRUE)
    {
      if (!OMint_Dle((*ivarp)[3], OMstring_Dsize((*ivarp)[2])))
        {
	  break;
        }
        {
	  OFoneof_Dmake(1, NIL);
	  OMrecord_Dset(3, (*ivarp)[1], retval_area[0]);
	  if (OMstring_Dbounds((*ivarp)[2], (*ivarp)[3]))
	    {
	      signame = SLBOUNDS;
	      goto except0;
	    }
	  (*ivarp)[4] = OMstring_Dfetch((*ivarp)[2], (*ivarp)[3]);
	  (*ivarp)[3] = OMint_Dadd((*ivarp)[3], 1);
	  if (OMint_Dgt((*ivarp)[3], OMstring_Dsize((*ivarp)[2])))
	    {
	      OMrecord_Dset(5, (*ivarp)[1], OMint_Dadd(OMrecord_Dget(5, (*ivarp)[1]), 1));
	    }
	  OFstring_Dappend(((string) &str1), (*ivarp)[4]);
	  OMrecord_Dset(6, (*ivarp)[1], retval_area[0]);
	  if (OFgetopt_Dlookup__short((*ivarp)[1], (*ivarp)[4]) == SIG)
	    {
	      goto except0;
	    }
	  (*ivarp)[5] = retval_area[0];
	  (*ivarp)[6] = retval_area[1];
	  if (OMbool_Dnot((*ivarp)[5]))
	    {
	      if (OFgetopt_Derror((*ivarp)[1], ((string) &str4), (*ivarp)[4]) == SIG)
	        {
		  goto except0;
	        }
	      (*ivarp)[4] = '?';
	    }
	  else
	    {
	      if ((*ivarp)[6])
	        {
		    {
		      if (OMint_Dle((*ivarp)[3], OMstring_Dsize((*ivarp)[2])))
		        {
			  if (OFstring_Drest((*ivarp)[2], (*ivarp)[3]) == SIG)
			    {
			      goto except1;
			    }
			  (*ivarp)[7] = retval_area[0];
		        }
		      else
		        {
			  (*ivarp)[INV_TOP+0] = OMrecord_Dget(1, (*ivarp)[1]);
			  (*ivarp)[INV_TOP+1] = OMrecord_Dget(5, (*ivarp)[1]);
			  if (OMsequence_Dbounds((*ivarp)[INV_TOP+0], (*ivarp)[INV_TOP+1]))
			    {
			      signame = SLBOUNDS;
			      goto except1;
			    }
			  (*ivarp)[7] = OMsequence_Dfetch((*ivarp)[INV_TOP+0], (*ivarp)[INV_TOP+1]);
		        }
		      OFoneof_Dmake(2, (*ivarp)[7]);
		      OMrecord_Dset(3, (*ivarp)[1], retval_area[0]);
		      OMrecord_Dset(5, (*ivarp)[1], OMint_Dadd(OMrecord_Dget(5, (*ivarp)[1]), 1));
		    }
		  if (FALSE)
		    {
		    except1:
		      if (OMstring_Dequal(signame, SLBOUNDS))
		        {
			  if (OFgetopt_Derror((*ivarp)[1], ((string) &str5), (*ivarp)[4]) == SIG)
			    {
			      goto except0;
			    }
			  (*ivarp)[4] = '?';
		        }
		      else
		        {
			  goto except0;
		        }
		    }
		  (*ivarp)[3] = OMint_Dadd(OMstring_Dsize((*ivarp)[2]), 1);
	        }
	    }
	  retval_area[0] = (*ivarp)[4];
	  (*ivarp)[0] = 1;
	  return YIELD;
	yield1:
	  NO_OPERATION;
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
/* c_function_name, OFgetopt_Dlookup__short */
/* clu_operation_name, getopt$lookup_short */
int OFgetopt_Dlookup__short(LVgo, LVoptchar)
     object LVgo;
     object LVoptchar;
{
  object LVlegal= 0;
  object LVrequires__arg= 0;
  object LVi= 0;
  int t1, t2;
  /* begin body */
  LVlegal = FALSE;
  LVrequires__arg = FALSE;
  OFstring_Dindexc(LVoptchar, OMrecord_Dget(8, LVgo));
  LVi = retval_area[0];
  if (OMint_Dgt(LVi, 0))
    {
      LVlegal = TRUE;
      t1 = OMrecord_Dget(8, LVgo);
      t2 = OMint_Dadd(LVi, 1);
      if (OMstring_Dbounds(t1, t2))
        {
	  signame = SLBOUNDS;
	  goto except1;
        }
      LVrequires__arg = OMchar_Dequal(OMstring_Dfetch(t1, t2), ':');
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
    }
  t1 = LVlegal;
  t2 = LVrequires__arg;
  retval_area[0] = t1;
  retval_area[1] = t2;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFgetopt_Dparse__long__option */
/* clu_operation_name, getopt$parse_long_option */
int OFgetopt_Dparse__long__option(LVgo, LVarg)
     object LVgo;
     object LVarg;
{
  object LVwith__arg= 0;
  object LVi= 0;
  object LVname= 0;
  object LVoption= 0;
  int t1, t2;
  /* begin body */
  OFstring_Dindexc('=', LVarg);
  LVi = retval_area[0];
  if (OMint_Dgt(LVi, 0))
    {
      if (OFstring_Dsubstr(LVarg, 1, OMint_Dsub(LVi, 1)) == SIG)
        {
	  goto except0;
        }
      OMrecord_Dset(6, LVgo, retval_area[0]);
      if (OFstring_Drest(LVarg, OMint_Dadd(LVi, 1)) == SIG)
        {
	  goto except0;
        }
      OFoneof_Dmake(2, retval_area[0]);
      OMrecord_Dset(3, LVgo, retval_area[0]);
      LVwith__arg = TRUE;
    }
  else
    {
      OMrecord_Dset(6, LVgo, LVarg);
      OFoneof_Dmake(1, NIL);
      OMrecord_Dset(3, LVgo, retval_area[0]);
      LVwith__arg = FALSE;
    }
  if (OFstring_Drest(OMrecord_Dget(6, LVgo), 3) == SIG)
    {
      goto except0;
    }
  LVname = retval_area[0];
  if (OFgetopt_Dlookup__long(LVgo, LVname) == SIG)
    {
      goto except1;
    }
  LVoption = retval_area[0];
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_FOUND))
        {
	  if (OFgetopt_Derror__long(LVgo, ((string) &str6), LVname, SLNULL) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = '?';
	  return RET;
        }
      else if (OMstring_Dequal(signame, ((string) &str7)))
        {
	  if (OFgetopt_Derror__long(LVgo, SLNULL, LVname, ((string) &str8)) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = '?';
	  return RET;
        }
      else
        {
	  goto except0;
        }
    }
  t1 = FALSE;
  if (OMint_Dequal(OMstruct_Dget(1, LVoption), 0))
    {
      if (LVwith__arg)
        {
	  t1 = TRUE;
        }
    }
  if (t1)
    {
      if (OFgetopt_Derror__long(LVgo, SLNULL, OMstruct_Dget(2, LVoption), ((string) &str9)) == SIG)
        {
	  goto except0;
        }
      retval_area[0] = '?';
      return RET;
    }
  else
    {
      t2 = FALSE;
      if (OMint_Dequal(OMstruct_Dget(1, LVoption), 1))
        {
	  if (OMbool_Dnot(LVwith__arg))
	    {
	      t2 = TRUE;
	    }
        }
      if (t2)
        {
	  if (OFgetopt_Derror__long(LVgo, SLNULL, OMstruct_Dget(2, LVoption), ((string) &str10)) == SIG)
	    {
	      goto except0;
	    }
	  retval_area[0] = '?';
	  return RET;
        }
    }
  retval_area[0] = OMstruct_Dget(3, LVoption);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFgetopt_Dlookup__long */
/* clu_operation_name, getopt$lookup_long */
int OFgetopt_Dlookup__long(LVgo, LVname)
     object LVgo;
     object LVname;
{
  object LVfound= 0;
  object LVresult= 0;
  int t1, t2, t3;
  /* begin body */
  LVfound = FALSE;
    {
      object LVoption= 0;
      for (t1 = OMrecord_Dget(2, LVgo), t2 = 1, t3 = OMsequence_Dsize(t1);
           t2 <= t3;
           t2++)
        {
	  LVoption = OMsequence_Dfetch(t1, t2);
	    {
	      if (OMstring_Dequal(LVname, OMstruct_Dget(2, LVoption)))
	        {
		  LVfound = TRUE;
		  LVresult = LVoption;
		  break;
	        }
	      else
	        {
		  OFstring_Dindexs(LVname, OMstruct_Dget(2, LVoption));
		  if (OMint_Dequal(retval_area[0], 1))
		    {
		      if (LVfound)
		        {
			  signame = ((string) &str7);
			  return(SIG);
		        }
		      LVfound = TRUE;
		      LVresult = LVoption;
		    }
	        }
	    }
        }
    }
  if (OMbool_Dnot(LVfound))
    {
      signame = SLNOT_FOUND;
      return(SIG);
    }
  retval_area[0] = LVresult;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFgetopt_Derror */
/* clu_operation_name, getopt$error */
int OFgetopt_Derror(LVgo, LVmessage, LVoptchar)
     object LVgo;
     object LVmessage;
     object LVoptchar;
{
  /* begin body */
  if (OMrecord_Dget(4, LVgo))
    {
      object LVoutput= 0;
      LVoutput = OMrecord_Dget(7, LVgo);
      if (AFprogram__name() == SIG)
        {
	  goto except1;
        }
      if (OFstream_Dputs(LVoutput, retval_area[0]) == SIG)
        {
	  goto except1;
        }
      if (OFstream_Dputs(LVoutput, ((string) &str11)) == SIG)
        {
	  goto except1;
        }
      if (OFstream_Dputs(LVoutput, LVmessage) == SIG)
        {
	  goto except1;
        }
      if (OFstream_Dputs(LVoutput, ((string) &str12)) == SIG)
        {
	  goto except1;
        }
      if (OFstream_Dputc(LVoutput, LVoptchar) == SIG)
        {
	  goto except1;
        }
      if (OFstream_Dputc(LVoutput, '\n') == SIG)
        {
	  goto except1;
        }
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_POSSIBLE))
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
/* c_function_name, OFgetopt_Derror__long */
/* clu_operation_name, getopt$error_long */
int OFgetopt_Derror__long(LVgo, LVwhat, LVname, LVdesc)
     object LVgo;
     object LVwhat;
     object LVname;
     object LVdesc;
{
  /* begin body */
  if (OMrecord_Dget(4, LVgo))
    {
      object LVoutput= 0;
      LVoutput = OMrecord_Dget(7, LVgo);
      if (AFprogram__name() == SIG)
        {
	  goto except1;
        }
      if (OFstream_Dputs(LVoutput, retval_area[0]) == SIG)
        {
	  goto except1;
        }
      if (OFstream_Dputc(LVoutput, ':') == SIG)
        {
	  goto except1;
        }
      if (OMbool_Dnot(OMstring_Dempty(LVwhat)))
        {
	  if (OFstream_Dputspace(LVoutput, 1) == SIG)
	    {
	      goto except1;
	    }
	  if (OFstream_Dputs(LVoutput, LVwhat) == SIG)
	    {
	      goto except1;
	    }
        }
      if (OFstream_Dputs(LVoutput, ((string) &str13)) == SIG)
        {
	  goto except1;
        }
      if (OFstream_Dputs(LVoutput, LVname) == SIG)
        {
	  goto except1;
        }
      if (OFstream_Dputc(LVoutput, '\'') == SIG)
        {
	  goto except1;
        }
      if (OMbool_Dnot(OMstring_Dempty(LVdesc)))
        {
	  if (OFstream_Dputspace(LVoutput, 1) == SIG)
	    {
	      goto except1;
	    }
	  if (OFstream_Dputs(LVoutput, LVdesc) == SIG)
	    {
	      goto except1;
	    }
        }
      if (OFstream_Dputc(LVoutput, '\n') == SIG)
        {
	  goto except1;
        }
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_POSSIBLE))
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
/* end module */
