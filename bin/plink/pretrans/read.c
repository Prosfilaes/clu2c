/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,read_comments,e_env,file_name,read_comments_one_file,stream*/
/* depend,read_comments_one_file,chop_trailing_blanks,e_env,match_comment_end,match_comment_start,match_continued_comment,stream*/
/* depend,split*/
/* depend,match_comment_start*/
/* depend,match_comment_end*/
/* depend,chop_trailing_blanks*/
/* depend,match_continued_comment*/

#include <clu2c.h>

static STRING_REP(4) str1 = {4, {'r', 'e', 'a', 'd'}};
static STRING_REP(2) str2 = {2, {':', ' '}};
static STRING_REP(1) str3 = {1, {' '}};
static STRING_REP(2) str4 = {2, {'/', '*'}};
static STRING_REP(2) str5 = {2, {'*', '/'}};
static STRING_REP(8) str6 = {8, {'a', 's', 't', 'e', 'r', 'i', 's', 'k'}};

/* begin module */
/* c_function_name, AFread__comments */
/* clu_operation_name, read_comments */
#define INV_TOP 6
#define WORK_SIZE 11
int AFread__comments(init, ivarp, LVfnames)
     bool init;
     int **ivarp;
     object LVfnames;
{
  if (init)
    {
      *ivarp = (int*) malloc(WORK_SIZE*sizeof(int));
      (*ivarp)[1] = LVfnames;
    }
  else
    {
      switch ((*ivarp)[0])
  	{
  	  case 1: goto yield1;
  	}
    }
  /* begin body */
  if (OFe__env_Dget() == SIG)
    {
      goto except0;
    }
  (*ivarp)[2] = retval_area[0];
    {
      for ((*ivarp)[INV_TOP+0] = (*ivarp)[1], (*ivarp)[INV_TOP+1] = OMarray_Dlow((*ivarp)[INV_TOP+0]), (*ivarp)[INV_TOP+2] = OMarray_Dhigh((*ivarp)[INV_TOP+0]);
           (*ivarp)[INV_TOP+1] <= (*ivarp)[INV_TOP+2];
           (*ivarp)[INV_TOP+1]++)
        {
	  (*ivarp)[3] = OMarray_Dfetch((*ivarp)[INV_TOP+0], (*ivarp)[INV_TOP+1]);
	    {
	      if (OFstream_Dopen((*ivarp)[3], ((string) &str1)) == SIG)
	        {
		  goto except1;
	        }
	      (*ivarp)[4] = retval_area[0];
	      if (FALSE)
	        {
		except1:
		  if (OMstring_Dequal(signame, SLNOT_POSSIBLE))
		    {
		      (*ivarp)[5] = sigarg_area[0];
		        {
			  if (OFfile__name_Dunparse((*ivarp)[3]) == SIG)
			    {
			      goto except0;
			    }
			  (*ivarp)[INV_TOP+3] = OFsequence_D__alloc(3);
			  OMsequence_D__store((*ivarp)[INV_TOP+3], 1, retval_area[0]);
			  OMsequence_D__store((*ivarp)[INV_TOP+3], 2, ((string) &str2));
			  OMsequence_D__store((*ivarp)[INV_TOP+3], 3, (*ivarp)[5]);
			  if (OFe__env_Derr((*ivarp)[2], (*ivarp)[INV_TOP+3]) == SIG)
			    {
			      goto except0;
			    }
			  continue;
		        }
		    }
		  else
		    {
		      goto except0;
		    }
	        }
	      if (OFe__env_Dset__file__name((*ivarp)[2], (*ivarp)[3]) == SIG)
	        {
		  goto except0;
	        }
	        {
		  for ((*ivarp)[INV_TOP+3] = AFread__comments__one__file(TRUE, &(*ivarp)[INV_TOP+4], (*ivarp)[4]);
		       (*ivarp)[INV_TOP+3] == YIELD;
		       (*ivarp)[INV_TOP+3] = AFread__comments__one__file(FALSE, &(*ivarp)[INV_TOP+4], 0))
		    {
		      (*ivarp)[5] = retval_area[0];
		        {
			  retval_area[0] = (*ivarp)[5];
			  (*ivarp)[0] = 1;
			  return YIELD;
			yield1:
			  NO_OPERATION;
		        }
		    }
		  free((*ivarp)[INV_TOP+4]);
		  if ((*ivarp)[INV_TOP+3] == SIG)
		    {
		      goto except0;
		    }
	        }
	      if (OFstream_Dclose((*ivarp)[4]) == SIG)
	        {
		  goto except2;
	        }
	      if (FALSE)
	        {
		except2:
		  if (OMstring_Dequal(signame, SLNOT_POSSIBLE))
		    {
		      if (OFstream_Dabort((*ivarp)[4]) == SIG)
		        {
			  goto except0;
		        }
		    }
		  else
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
#undef INV_TOP
#undef WORK_SIZE
/* end module */

/* begin module */
/* c_function_name, AFread__comments__one__file */
/* clu_operation_name, read_comments_one_file */
#define INV_TOP 7
#define WORK_SIZE 9
int AFread__comments__one__file(init, ivarp, LVinst)
     bool init;
     int **ivarp;
     object LVinst;
{
  if (init)
    {
      *ivarp = (int*) malloc(WORK_SIZE*sizeof(int));
      (*ivarp)[1] = LVinst;
    }
  else
    {
      switch ((*ivarp)[0])
  	{
  	  case 1: goto yield1;
  	}
    }
  /* begin body */
  if (OFe__env_Dget() == SIG)
    {
      goto except0;
    }
  (*ivarp)[2] = retval_area[0];
  if (OFstream_Dget__lineno((*ivarp)[1]) == SIG)
    {
      goto except0;
    }
  if (OFe__env_Dset__line((*ivarp)[2], retval_area[0]) == SIG)
    {
      goto except0;
    }
  if (OFstream_Dgetl((*ivarp)[1]) == SIG)
    {
      goto except1;
    }
  (*ivarp)[3] = retval_area[0];
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLEND_OF_FILE) || OMstring_Dequal(signame, SLNOT_POSSIBLE))
        {
	  return RET;
        }
      else
        {
	  goto except0;
        }
    }
  if (AFmatch__comment__start((*ivarp)[3]) == SIG)
    {
      goto except0;
    }
  (*ivarp)[4] = retval_area[0];
  while (TRUE)
    {
      if (!OMint_Dgt((*ivarp)[4], 0))
        {
	  break;
        }
        {
	  (*ivarp)[5] = SLNULL;
	  while (TRUE)
	    {
	        {
		  if (AFmatch__comment__end((*ivarp)[3]) == SIG)
		    {
		      goto except2;
		    }
		  (*ivarp)[6] = retval_area[0];
		  if (OMint_Dge((*ivarp)[6], 0))
		    {
		      if (OMint_Dle((*ivarp)[4], (*ivarp)[6]))
		        {
			  if (OMbool_Dnot(OMstring_Dempty((*ivarp)[5])))
			    {
			      (*ivarp)[INV_TOP+0] = OMstring_Dsize((*ivarp)[5])
			                            + OMstring_Dsize(((string) &str3));
			      (*ivarp)[INV_TOP+1] = OFstring_D__predict((*ivarp)[INV_TOP+0]);
			      OFstring_D__concat((*ivarp)[INV_TOP+1], (*ivarp)[5]);
			      OFstring_D__concat((*ivarp)[INV_TOP+1], ((string) &str3));
			      (*ivarp)[5] = (*ivarp)[INV_TOP+1];
			    }
			  if (OFstring_Dsubstr((*ivarp)[3], (*ivarp)[4], OMint_Dadd(OMint_Dsub((*ivarp)[6], (*ivarp)[4]), 1)) == SIG)
			    {
			      goto except2;
			    }
			  (*ivarp)[INV_TOP+0] = OMstring_Dsize((*ivarp)[5])
			                        + OMstring_Dsize(retval_area[0]);
			  (*ivarp)[INV_TOP+1] = OFstring_D__predict((*ivarp)[INV_TOP+0]);
			  OFstring_D__concat((*ivarp)[INV_TOP+1], (*ivarp)[5]);
			  OFstring_D__concat((*ivarp)[INV_TOP+1], retval_area[0]);
			  (*ivarp)[5] = (*ivarp)[INV_TOP+1];
		        }
		      if (OMbool_Dnot(OMstring_Dempty((*ivarp)[5])))
		        {
			  retval_area[0] = (*ivarp)[5];
			  (*ivarp)[0] = 1;
			  return YIELD;
			yield1:
			  NO_OPERATION;
		        }
		      break;
		    }
		  if (AFchop__trailing__blanks((*ivarp)[3]) == SIG)
		    {
		      goto except2;
		    }
		  (*ivarp)[6] = retval_area[0];
		  if (OMint_Dle((*ivarp)[4], (*ivarp)[6]))
		    {
		      if (OMbool_Dnot(OMstring_Dempty((*ivarp)[5])))
		        {
			  (*ivarp)[INV_TOP+0] = OMstring_Dsize((*ivarp)[5])
			                        + OMstring_Dsize(((string) &str3));
			  (*ivarp)[INV_TOP+1] = OFstring_D__predict((*ivarp)[INV_TOP+0]);
			  OFstring_D__concat((*ivarp)[INV_TOP+1], (*ivarp)[5]);
			  OFstring_D__concat((*ivarp)[INV_TOP+1], ((string) &str3));
			  (*ivarp)[5] = (*ivarp)[INV_TOP+1];
		        }
		      if (OFstring_Dsubstr((*ivarp)[3], (*ivarp)[4], OMint_Dadd(OMint_Dsub((*ivarp)[6], (*ivarp)[4]), 1)) == SIG)
		        {
			  goto except2;
		        }
		      (*ivarp)[INV_TOP+0] = OMstring_Dsize((*ivarp)[5])
		                            + OMstring_Dsize(retval_area[0]);
		      (*ivarp)[INV_TOP+1] = OFstring_D__predict((*ivarp)[INV_TOP+0]);
		      OFstring_D__concat((*ivarp)[INV_TOP+1], (*ivarp)[5]);
		      OFstring_D__concat((*ivarp)[INV_TOP+1], retval_area[0]);
		      (*ivarp)[5] = (*ivarp)[INV_TOP+1];
		    }
		  if (OFstream_Dgetl((*ivarp)[1]) == SIG)
		    {
		      goto except2;
		    }
		  (*ivarp)[3] = retval_area[0];
		  if (AFmatch__continued__comment((*ivarp)[3]) == SIG)
		    {
		      goto except2;
		    }
		  (*ivarp)[4] = retval_area[0];
	        }
	    }
	  if (OFstream_Dget__lineno((*ivarp)[1]) == SIG)
	    {
	      goto except2;
	    }
	  if (OFe__env_Dset__line((*ivarp)[2], retval_area[0]) == SIG)
	    {
	      goto except2;
	    }
	  if (OFstream_Dgetl((*ivarp)[1]) == SIG)
	    {
	      goto except2;
	    }
	  (*ivarp)[3] = retval_area[0];
	  if (AFmatch__comment__start((*ivarp)[3]) == SIG)
	    {
	      goto except2;
	    }
	  (*ivarp)[4] = retval_area[0];
        }
    }
  if (FALSE)
    {
    except2:
      if (OMstring_Dequal(signame, SLEND_OF_FILE) || OMstring_Dequal(signame, SLNOT_POSSIBLE))
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
/* c_function_name, AFsplit */
/* clu_operation_name, split */
int AFsplit(LVcomment)
     object LVcomment;
{
  static bool IV = FALSE;
  static object WVres= 0;
  object LVin__field= 0;
  object LVin__char__lit= 0;
  object LVin__str__lit= 0;
  object LVlastc= 0;
  object LVstart= 0;
  int t1, t2, t3, t4, t5, t6;
  if (IV == FALSE)
    {
      IV = TRUE;
      OFarray_Dpredict(1, 10);
      WVres = retval_area[0];
    }
  /* begin body */
  if (OFarray_Dtrim(WVres, 1, 0) == SIG)
    {
      goto except0;
    }
  LVin__field = FALSE;
  LVin__char__lit = FALSE;
  LVin__str__lit = FALSE;
  LVlastc = '\000';
    {
      object LVi= 0;
      for (t1 = 1, t2 = OMstring_Dsize(LVcomment); t1 <= t2; t1++)
        {
	  LVi = t1;
	    {
	      object LVc= 0;
	      if (OMstring_Dbounds(LVcomment, LVi))
	        {
		  signame = SLBOUNDS;
		  goto except0;
	        }
	      LVc = OMstring_Dfetch(LVcomment, LVi);
	      if (OMbool_Dnot(LVin__field))
	        {
		  t3 = OMchar_Dequal(LVc, ' ');
		  if (OMbool_Dor(t3, OMchar_Dequal(LVc, '\t')))
		    {
		      LVlastc = LVc;
		      continue;
		    }
		  else
		    {
		      LVin__field = TRUE;
		      LVstart = LVi;
		    }
	        }
	      t3 = FALSE;
	      t4 = FALSE;
	      if (OMchar_Dequal(LVc, ','))
	        {
		  if (OMbool_Dnot(LVin__char__lit))
		    {
		      t4 = TRUE;
		    }
	        }
	      if (t4)
	        {
		  if (OMbool_Dnot(LVin__str__lit))
		    {
		      t3 = TRUE;
		    }
	        }
	      if (t3)
	        {
		  if (OFstring_Dsubstr(LVcomment, LVstart, OMint_Dsub(LVi, LVstart)) == SIG)
		    {
		      goto except0;
		    }
		  OMarray_Daddh(WVres, retval_area[0]);
		  LVin__field = FALSE;
	        }
	      else
	        {
		  t5 = FALSE;
		  if (OMchar_Dequal(LVc, '\''))
		    {
		      if (OMbool_Dnot(OMchar_Dequal(LVlastc, '\\')))
		        {
			  t5 = TRUE;
		        }
		    }
		  if (t5)
		    {
		      LVin__char__lit = OMbool_Dnot(LVin__char__lit);
		    }
		  else
		    {
		      t6 = FALSE;
		      if (OMchar_Dequal(LVc, '\"'))
		        {
			  if (OMbool_Dnot(OMchar_Dequal(LVlastc, '\\')))
			    {
			      t6 = TRUE;
			    }
		        }
		      if (t6)
		        {
			  LVin__str__lit = OMbool_Dnot(LVin__str__lit);
		        }
		    }
	        }
	      LVlastc = LVc;
	    }
        }
    }
  if (LVin__field)
    {
      if (OFstring_Drest(LVcomment, LVstart) == SIG)
        {
	  goto except0;
        }
      OMarray_Daddh(WVres, retval_area[0]);
    }
  retval_area[0] = WVres;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFmatch__comment__start */
/* clu_operation_name, match_comment_start */
int AFmatch__comment__start(LVline)
     object LVline;
{
  object LVindex= 0;
  object LVsize= 0;
  int t1, t2, t3;
  /* begin body */
  OFstring_Dindexs(((string) &str4), LVline);
  LVindex = retval_area[0];
  if (OMint_Dequal(LVindex, 0))
    {
      retval_area[0] = 0;
      return RET;
    }
    {
      object LVi= 0;
      for (t1 = 1, t2 = OMint_Dsub(LVindex, 1); t1 <= t2; t1++)
        {
	  LVi = t1;
	    {
	      object LVc= 0;
	      if (OMstring_Dbounds(LVline, LVi))
	        {
		  signame = SLBOUNDS;
		  goto except0;
	        }
	      LVc = OMstring_Dfetch(LVline, LVi);
	      t3 = OMbool_Dnot(OMchar_Dequal(LVc, ' '));
	      if (OMbool_Dand(t3, OMbool_Dnot(OMchar_Dequal(LVc, '\t'))))
	        {
		  retval_area[0] = 0;
		  return RET;
	        }
	    }
        }
    }
  LVindex = OMint_Dadd(LVindex, 2);
  LVsize = OMstring_Dsize(LVline);
  while (TRUE)
    {
      if (!OMint_Dle(LVindex, LVsize))
        {
	  break;
        }
        {
	  object LVc= 0;
	  if (OMstring_Dbounds(LVline, LVindex))
	    {
	      signame = SLBOUNDS;
	      goto except0;
	    }
	  LVc = OMstring_Dfetch(LVline, LVindex);
	  t1 = OMbool_Dnot(OMchar_Dequal(LVc, ' '));
	  if (OMbool_Dand(t1, OMbool_Dnot(OMchar_Dequal(LVc, '\t'))))
	    {
	      retval_area[0] = LVindex;
	      return RET;
	    }
	  LVindex = OMint_Dadd(LVindex, 1);
        }
    }
  retval_area[0] = LVindex;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFmatch__comment__end */
/* clu_operation_name, match_comment_end */
int AFmatch__comment__end(LVline)
     object LVline;
{
  object LVindex= 0;
  int t1, t2, t3, t4;
  /* begin body */
  OFstring_Dindexs(((string) &str5), LVline);
  LVindex = retval_area[0];
  if (OMint_Dequal(LVindex, 0))
    {
      retval_area[0] = -1;
      return RET;
    }
    {
      object LVi= 0;
      t1 = OMint_Dadd(LVindex, 2);
      for (t2 = t1, t3 = OMstring_Dsize(LVline); t2 <= t3; t2++)
        {
	  LVi = t2;
	    {
	      object LVc= 0;
	      if (OMstring_Dbounds(LVline, LVi))
	        {
		  signame = SLBOUNDS;
		  goto except0;
	        }
	      LVc = OMstring_Dfetch(LVline, LVi);
	      t4 = OMbool_Dnot(OMchar_Dequal(LVc, ' '));
	      if (OMbool_Dand(t4, OMbool_Dnot(OMchar_Dequal(LVc, '\t'))))
	        {
		  retval_area[0] = -1;
		  return RET;
	        }
	    }
        }
    }
  LVindex = OMint_Dsub(LVindex, 1);
  while (TRUE)
    {
      if (!OMint_Dge(LVindex, 1))
        {
	  break;
        }
        {
	  object LVc= 0;
	  if (OMstring_Dbounds(LVline, LVindex))
	    {
	      signame = SLBOUNDS;
	      goto except0;
	    }
	  LVc = OMstring_Dfetch(LVline, LVindex);
	  t1 = OMbool_Dnot(OMchar_Dequal(LVc, ' '));
	  if (OMbool_Dand(t1, OMbool_Dnot(OMchar_Dequal(LVc, '\t'))))
	    {
	      retval_area[0] = LVindex;
	      return RET;
	    }
	  LVindex = OMint_Dsub(LVindex, 1);
        }
    }
  retval_area[0] = LVindex;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFchop__trailing__blanks */
/* clu_operation_name, chop_trailing_blanks */
int AFchop__trailing__blanks(LVline)
     object LVline;
{
  int t1, t2;
  /* begin body */
    {
      object LVindex= 0;
      for (t1 = OMstring_Dsize(LVline); t1 >= 1; t1 -= 1)
        {
	  LVindex = t1;
	    {
	      object LVc= 0;
	      if (OMstring_Dbounds(LVline, LVindex))
	        {
		  signame = SLBOUNDS;
		  goto except0;
	        }
	      LVc = OMstring_Dfetch(LVline, LVindex);
	      t2 = OMbool_Dnot(OMchar_Dequal(LVc, ' '));
	      if (OMbool_Dand(t2, OMbool_Dnot(OMchar_Dequal(LVc, '\t'))))
	        {
		  retval_area[0] = LVindex;
		  return RET;
	        }
	    }
        }
    }
  retval_area[0] = 0;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */

/* begin module */
/* c_function_name, AFmatch__continued__comment */
/* clu_operation_name, match_continued_comment */
int AFmatch__continued__comment(LVline)
     object LVline;
{
  object LVindex= 0;
  object LVsize= 0;
  int t1;
  /* begin body */
  LVindex = 1;
  LVsize = OMstring_Dsize(LVline);
    {
      while (TRUE)
        {
	  if (!OMint_Dle(LVindex, LVsize))
	    {
	      break;
	    }
	    {
	      object LVc= 0;
	      if (OMstring_Dbounds(LVline, LVindex))
	        {
		  signame = SLBOUNDS;
		  goto except1;
	        }
	      LVc = OMstring_Dfetch(LVline, LVindex);
	      t1 = OMbool_Dnot(OMchar_Dequal(LVc, ' '));
	      if (OMbool_Dand(t1, OMbool_Dnot(OMchar_Dequal(LVc, '\t'))))
	        {
		  if (OMchar_Dequal(LVc, '*'))
		    {
		      signame = ((string) &str6);
		      goto except1;
		    }
		  else
		    {
		      break;
		    }
	        }
	      LVindex = OMint_Dadd(LVindex, 1);
	    }
        }
      retval_area[0] = LVindex;
      return RET;
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, ((string) &str6)))
        {
        }
      else
        {
	  goto except0;
        }
    }
  LVindex = OMint_Dadd(LVindex, 1);
  while (TRUE)
    {
      if (!OMint_Dle(LVindex, LVsize))
        {
	  break;
        }
        {
	  object LVc= 0;
	  if (OMstring_Dbounds(LVline, LVindex))
	    {
	      signame = SLBOUNDS;
	      goto except0;
	    }
	  LVc = OMstring_Dfetch(LVline, LVindex);
	  t1 = OMbool_Dnot(OMchar_Dequal(LVc, ' '));
	  if (OMbool_Dand(t1, OMbool_Dnot(OMchar_Dequal(LVc, '\t'))))
	    {
	      break;
	    }
	  LVindex = OMint_Dadd(LVindex, 1);
        }
    }
  retval_area[0] = LVindex;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* end module */