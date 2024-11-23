/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,date,istream,pstream*/

#include <clu2c.h>

static STRING_REP(1) str1 = {1, {' '}};
static STRING_REP(7) str2 = {7, {'J', 'a', 'n', 'u', 'a', 'r', 'y'}};
static STRING_REP(8) str3 = {8, {'F', 'e', 'b', 'r', 'u', 'a', 'r', 'y'}};
static STRING_REP(5) str4 = {5, {'M', 'a', 'r', 'c', 'h'}};
static STRING_REP(5) str5 = {5, {'A', 'p', 'r', 'i', 'l'}};
static STRING_REP(3) str6 = {3, {'M', 'a', 'y'}};
static STRING_REP(4) str7 = {4, {'J', 'u', 'n', 'e'}};
static STRING_REP(4) str8 = {4, {'J', 'u', 'l', 'y'}};
static STRING_REP(6) str9 = {6, {'A', 'u', 'g', 'u', 's', 't'}};
static STRING_REP(9) str10 = {9, {'S', 'e', 'p', 't', 'e', 'm', 'b', 'e', 'r'}};
static STRING_REP(7) str11 = {7, {'O', 'c', 't', 'o', 'b', 'e', 'r'}};
static STRING_REP(8) str12 = {8, {'N', 'o', 'v', 'e', 'm', 'b', 'e', 'r'}};
static STRING_REP(8) str13 = {8, {'D', 'e', 'c', 'e', 'm', 'b', 'e', 'r'}};
static STRING_REP(1) str14 = {1, {'0'}};
static STRING_REP(1) str15 = {1, {':'}};
static STRING_REP(10) str16 = {10, {'b', 'a', 'd', ' ', 'f', 'o', 'r', 'm', 'a', 't'}};

/* begin module */
/* c_function_name, OFdate_Dcreate */
/* clu_operation_name, date$create */
int OFdate_Dcreate(LVday, LVmonth, LVyear, LVhour, LVminute, LVsecond)
     object LVday;
     object LVmonth;
     object LVyear;
     object LVhour;
     object LVminute;
     object LVsecond;
{
  int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
  /* begin body */
  if (OMint_Dlt(LVday, 1))
    {
      t10 = TRUE;
    }
  else
    {
      t10 = OMint_Dgt(LVday, 31);
    }
  if (t10)
    {
      t9 = TRUE;
    }
  else
    {
      t9 = OMint_Dlt(LVmonth, 1);
    }
  if (t9)
    {
      t8 = TRUE;
    }
  else
    {
      t8 = OMint_Dgt(LVmonth, 12);
    }
  if (t8)
    {
      t7 = TRUE;
    }
  else
    {
      t7 = OMint_Dlt(LVyear, 1);
    }
  if (t7)
    {
      t6 = TRUE;
    }
  else
    {
      t6 = OMint_Dlt(LVhour, 0);
    }
  if (t6)
    {
      t5 = TRUE;
    }
  else
    {
      t5 = OMint_Dgt(LVhour, 23);
    }
  if (t5)
    {
      t4 = TRUE;
    }
  else
    {
      t4 = OMint_Dlt(LVminute, 0);
    }
  if (t4)
    {
      t3 = TRUE;
    }
  else
    {
      t3 = OMint_Dgt(LVminute, 59);
    }
  if (t3)
    {
      t2 = TRUE;
    }
  else
    {
      t2 = OMint_Dlt(LVsecond, 0);
    }
  if (t2)
    {
      t1 = TRUE;
    }
  else
    {
      t1 = OMint_Dgt(LVsecond, 59);
    }
  if (t1)
    {
      signame = SLBAD_FORMAT;
      return(SIG);
    }
  t1 = OFstruct_D__alloc(6);
  OMstruct_D__set(1, t1, LVday);
  OMstruct_D__set(2, t1, LVhour);
  OMstruct_D__set(3, t1, LVminute);
  OMstruct_D__set(4, t1, LVmonth);
  OMstruct_D__set(5, t1, LVsecond);
  OMstruct_D__set(6, t1, LVyear);
  retval_area[0] = t1;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dget__day */
/* clu_operation_name, date$get_day */
int OFdate_Dget__day(LVd)
     object LVd;
{
  /* begin body */
  retval_area[0] = OMstruct_Dget(1, LVd);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dget__month */
/* clu_operation_name, date$get_month */
int OFdate_Dget__month(LVd)
     object LVd;
{
  /* begin body */
  retval_area[0] = OMstruct_Dget(4, LVd);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dget__year */
/* clu_operation_name, date$get_year */
int OFdate_Dget__year(LVd)
     object LVd;
{
  /* begin body */
  retval_area[0] = OMstruct_Dget(6, LVd);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dget__hour */
/* clu_operation_name, date$get_hour */
int OFdate_Dget__hour(LVd)
     object LVd;
{
  /* begin body */
  retval_area[0] = OMstruct_Dget(2, LVd);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dget__minute */
/* clu_operation_name, date$get_minute */
int OFdate_Dget__minute(LVd)
     object LVd;
{
  /* begin body */
  retval_area[0] = OMstruct_Dget(3, LVd);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dget__second */
/* clu_operation_name, date$get_second */
int OFdate_Dget__second(LVd)
     object LVd;
{
  /* begin body */
  retval_area[0] = OMstruct_Dget(5, LVd);
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dget__all */
/* clu_operation_name, date$get_all */
int OFdate_Dget__all(LVd)
     object LVd;
{
  int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
  int t11;
  /* begin body */
  t1 = OMstruct_Dget(1, LVd);
  t2 = OMstruct_Dget(4, LVd);
  t3 = OMstruct_Dget(6, LVd);
  t4 = OMstruct_Dget(2, LVd);
  t5 = OMstruct_Dget(3, LVd);
  t6 = t1;
  t7 = t2;
  t8 = t3;
  t9 = t4;
  t10 = t5;
  t11 = OMstruct_Dget(5, LVd);
  retval_area[0] = t6;
  retval_area[1] = t7;
  retval_area[2] = t8;
  retval_area[3] = t9;
  retval_area[4] = t10;
  retval_area[5] = t11;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dunparse */
/* clu_operation_name, date$unparse */
int OFdate_Dunparse(LVd)
     object LVd;
{
  int t1, t2, t3;
  /* begin body */
  if (OFdate_Dunparse__date(LVd) == SIG)
    {
      goto except0;
    }
  t1 = retval_area[0];
  if (OFdate_Dunparse__time(LVd) == SIG)
    {
      goto except0;
    }
  t2 = OMstring_Dsize(t1)
       + OMstring_Dsize(((string) &str1))
       + OMstring_Dsize(retval_area[0]);
  t3 = OFstring_D__predict(t2);
  OFstring_D__concat(t3, t1);
  OFstring_D__concat(t3, ((string) &str1));
  OFstring_D__concat(t3, retval_area[0]);
  retval_area[0] = t3;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dunparse__date */
/* clu_operation_name, date$unparse_date */
int OFdate_Dunparse__date(LVd)
     object LVd;
{
  int t1, t2, t3, t4, t5, t6;
  /* begin body */
  OFint_Dunparse(OMstruct_Dget(1, LVd));
  t1 = retval_area[0];
  t2 = OFsequence_D__alloc(12);
  OMsequence_D__store(t2, 1, ((string) &str2));
  OMsequence_D__store(t2, 2, ((string) &str3));
  OMsequence_D__store(t2, 3, ((string) &str4));
  OMsequence_D__store(t2, 4, ((string) &str5));
  OMsequence_D__store(t2, 5, ((string) &str6));
  OMsequence_D__store(t2, 6, ((string) &str7));
  OMsequence_D__store(t2, 7, ((string) &str8));
  OMsequence_D__store(t2, 8, ((string) &str9));
  OMsequence_D__store(t2, 9, ((string) &str10));
  OMsequence_D__store(t2, 10, ((string) &str11));
  OMsequence_D__store(t2, 11, ((string) &str12));
  OMsequence_D__store(t2, 12, ((string) &str13));
  t3 = OMstruct_Dget(4, LVd);
  if (OMsequence_Dbounds(t2, t3))
    {
      signame = SLBOUNDS;
      goto except0;
    }
  t4 = OMsequence_Dfetch(t2, t3);
  OFint_Dunparse(OMstruct_Dget(6, LVd));
  t5 = OMstring_Dsize(t1)
       + OMstring_Dsize(((string) &str1))
       + OMstring_Dsize(t4)
       + OMstring_Dsize(((string) &str1))
       + OMstring_Dsize(retval_area[0]);
  t6 = OFstring_D__predict(t5);
  OFstring_D__concat(t6, t1);
  OFstring_D__concat(t6, ((string) &str1));
  OFstring_D__concat(t6, t4);
  OFstring_D__concat(t6, ((string) &str1));
  OFstring_D__concat(t6, retval_area[0]);
  retval_area[0] = t6;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dunparse__time */
/* clu_operation_name, date$unparse_time */
int OFdate_Dunparse__time(LVd)
     object LVd;
{
  object LVhour= 0;
  object LVminute= 0;
  object LVsecond= 0;
  int t1, t2;
  /* begin body */
  OFint_Dunparse(OMstruct_Dget(2, LVd));
  LVhour = retval_area[0];
  OFint_Dunparse(OMstruct_Dget(3, LVd));
  LVminute = retval_area[0];
  OFint_Dunparse(OMstruct_Dget(5, LVd));
  LVsecond = retval_area[0];
  if (OMint_Dlt(OMstruct_Dget(2, LVd), 10))
    {
      t1 = OMstring_Dsize(((string) &str14))
           + OMstring_Dsize(LVhour);
      t2 = OFstring_D__predict(t1);
      OFstring_D__concat(t2, ((string) &str14));
      OFstring_D__concat(t2, LVhour);
      LVhour = t2;
    }
  if (OMint_Dlt(OMstruct_Dget(3, LVd), 10))
    {
      t1 = OMstring_Dsize(((string) &str14))
           + OMstring_Dsize(LVminute);
      t2 = OFstring_D__predict(t1);
      OFstring_D__concat(t2, ((string) &str14));
      OFstring_D__concat(t2, LVminute);
      LVminute = t2;
    }
  if (OMint_Dlt(OMstruct_Dget(5, LVd), 10))
    {
      t1 = OMstring_Dsize(((string) &str14))
           + OMstring_Dsize(LVsecond);
      t2 = OFstring_D__predict(t1);
      OFstring_D__concat(t2, ((string) &str14));
      OFstring_D__concat(t2, LVsecond);
      LVsecond = t2;
    }
  t1 = OMstring_Dsize(LVhour)
       + OMstring_Dsize(((string) &str15))
       + OMstring_Dsize(LVminute)
       + OMstring_Dsize(((string) &str15))
       + OMstring_Dsize(LVsecond);
  t2 = OFstring_D__predict(t1);
  OFstring_D__concat(t2, LVhour);
  OFstring_D__concat(t2, ((string) &str15));
  OFstring_D__concat(t2, LVminute);
  OFstring_D__concat(t2, ((string) &str15));
  OFstring_D__concat(t2, LVsecond);
  retval_area[0] = t2;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dequal */
/* clu_operation_name, date$equal */
int OFdate_Dequal(LVdate1, LVdate2)
     object LVdate1;
     object LVdate2;
{
  int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
  int t11;
  /* begin body */
  t1 = FALSE;
  t2 = FALSE;
  t3 = FALSE;
  t4 = FALSE;
  t5 = FALSE;
  t6 = OMstruct_Dget(5, LVdate1);
  if (OMint_Dequal(t6, OMstruct_Dget(5, LVdate2)))
    {
      t7 = OMstruct_Dget(3, LVdate1);
      if (OMint_Dequal(t7, OMstruct_Dget(3, LVdate2)))
        {
	  t5 = TRUE;
        }
    }
  if (t5)
    {
      t8 = OMstruct_Dget(2, LVdate1);
      if (OMint_Dequal(t8, OMstruct_Dget(2, LVdate2)))
        {
	  t4 = TRUE;
        }
    }
  if (t4)
    {
      t9 = OMstruct_Dget(6, LVdate1);
      if (OMint_Dequal(t9, OMstruct_Dget(6, LVdate2)))
        {
	  t3 = TRUE;
        }
    }
  if (t3)
    {
      t10 = OMstruct_Dget(4, LVdate1);
      if (OMint_Dequal(t10, OMstruct_Dget(4, LVdate2)))
        {
	  t2 = TRUE;
        }
    }
  if (t2)
    {
      t11 = OMstruct_Dget(1, LVdate1);
      if (OMint_Dequal(t11, OMstruct_Dget(1, LVdate2)))
        {
	  t1 = TRUE;
        }
    }
  retval_area[0] = t1;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dsimilar */
/* clu_operation_name, date$similar */
int OFdate_Dsimilar(LVdate1, LVdate2)
     object LVdate1;
     object LVdate2;
{
  /* begin body */
  if (OFdate_Dequal(LVdate1, LVdate2) == SIG)
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
/* c_function_name, OFdate_Dcopy */
/* clu_operation_name, date$copy */
int OFdate_Dcopy(LVd)
     object LVd;
{
  /* begin body */
  retval_area[0] = LVd;
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dlt */
/* clu_operation_name, date$lt */
int OFdate_Dlt(LVd1, LVd2)
     object LVd1;
     object LVd2;
{
  int t1, t2;
  /* begin body */
  t1 = OMstruct_Dget(6, LVd1);
  if (OMbool_Dnot(OMint_Dequal(t1, OMstruct_Dget(6, LVd2))))
    {
      t2 = OMstruct_Dget(6, LVd1);
      retval_area[0] = OMint_Dlt(t2, OMstruct_Dget(6, LVd2));
      return RET;
    }
  t1 = OMstruct_Dget(4, LVd1);
  if (OMbool_Dnot(OMint_Dequal(t1, OMstruct_Dget(4, LVd2))))
    {
      t2 = OMstruct_Dget(4, LVd1);
      retval_area[0] = OMint_Dlt(t2, OMstruct_Dget(4, LVd2));
      return RET;
    }
  t1 = OMstruct_Dget(1, LVd1);
  if (OMbool_Dnot(OMint_Dequal(t1, OMstruct_Dget(1, LVd2))))
    {
      t2 = OMstruct_Dget(1, LVd1);
      retval_area[0] = OMint_Dlt(t2, OMstruct_Dget(1, LVd2));
      return RET;
    }
  t1 = OMstruct_Dget(2, LVd1);
  if (OMbool_Dnot(OMint_Dequal(t1, OMstruct_Dget(2, LVd2))))
    {
      t2 = OMstruct_Dget(2, LVd1);
      retval_area[0] = OMint_Dlt(t2, OMstruct_Dget(2, LVd2));
      return RET;
    }
  t1 = OMstruct_Dget(3, LVd1);
  if (OMbool_Dnot(OMint_Dequal(t1, OMstruct_Dget(3, LVd2))))
    {
      t2 = OMstruct_Dget(3, LVd1);
      retval_area[0] = OMint_Dlt(t2, OMstruct_Dget(3, LVd2));
      return RET;
    }
  t1 = OMstruct_Dget(5, LVd1);
  retval_area[0] = OMint_Dlt(t1, OMstruct_Dget(5, LVd2));
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dle */
/* clu_operation_name, date$le */
int OFdate_Dle(LVd1, LVd2)
     object LVd1;
     object LVd2;
{
  int t1, t2;
  /* begin body */
  t1 = OMstruct_Dget(6, LVd1);
  if (OMbool_Dnot(OMint_Dequal(t1, OMstruct_Dget(6, LVd2))))
    {
      t2 = OMstruct_Dget(6, LVd1);
      retval_area[0] = OMint_Dlt(t2, OMstruct_Dget(6, LVd2));
      return RET;
    }
  t1 = OMstruct_Dget(4, LVd1);
  if (OMbool_Dnot(OMint_Dequal(t1, OMstruct_Dget(4, LVd2))))
    {
      t2 = OMstruct_Dget(4, LVd1);
      retval_area[0] = OMint_Dlt(t2, OMstruct_Dget(4, LVd2));
      return RET;
    }
  t1 = OMstruct_Dget(1, LVd1);
  if (OMbool_Dnot(OMint_Dequal(t1, OMstruct_Dget(1, LVd2))))
    {
      t2 = OMstruct_Dget(1, LVd1);
      retval_area[0] = OMint_Dlt(t2, OMstruct_Dget(1, LVd2));
      return RET;
    }
  t1 = OMstruct_Dget(2, LVd1);
  if (OMbool_Dnot(OMint_Dequal(t1, OMstruct_Dget(2, LVd2))))
    {
      t2 = OMstruct_Dget(2, LVd1);
      retval_area[0] = OMint_Dlt(t2, OMstruct_Dget(2, LVd2));
      return RET;
    }
  t1 = OMstruct_Dget(3, LVd1);
  if (OMbool_Dnot(OMint_Dequal(t1, OMstruct_Dget(3, LVd2))))
    {
      t2 = OMstruct_Dget(3, LVd1);
      retval_area[0] = OMint_Dlt(t2, OMstruct_Dget(3, LVd2));
      return RET;
    }
  t1 = OMstruct_Dget(5, LVd1);
  retval_area[0] = OMint_Dle(t1, OMstruct_Dget(5, LVd2));
  return RET;
  /* end body */
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dgt */
/* clu_operation_name, date$gt */
int OFdate_Dgt(LVd1, LVd2)
     object LVd1;
     object LVd2;
{
  /* begin body */
  if (OFdate_Dlt(LVd2, LVd1) == SIG)
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
/* c_function_name, OFdate_Dge */
/* clu_operation_name, date$ge */
int OFdate_Dge(LVd1, LVd2)
     object LVd1;
     object LVd2;
{
  /* begin body */
  if (OFdate_Dle(LVd2, LVd1) == SIG)
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
/* c_function_name, OFdate_Dprint */
/* clu_operation_name, date$print */
int OFdate_Dprint(LVd, LVps)
     object LVd;
     object LVps;
{
  /* begin body */
  if (OFdate_Dunparse(LVd) == SIG)
    {
      goto except0;
    }
  if (OFpstream_Dtext(LVps, retval_area[0]) == SIG)
    {
      goto except0;
    }
  /* end body */
  return(RET);
except0:
  out_handler(SLNULL);
  return(SIG);
}
/* c_function_name, OFdate_Dencode */
/* clu_operation_name, date$encode */
int OFdate_Dencode(LVd, LVist)
     object LVd;
     object LVist;
{
  /* begin body */
    {
      if (OFint_Dencode(OMstruct_Dget(1, LVd), LVist) == SIG)
        {
	  goto except1;
        }
      if (OFint_Dencode(OMstruct_Dget(4, LVd), LVist) == SIG)
        {
	  goto except1;
        }
      if (OFint_Dencode(OMstruct_Dget(6, LVd), LVist) == SIG)
        {
	  goto except1;
        }
      if (OFint_Dencode(OMstruct_Dget(2, LVd), LVist) == SIG)
        {
	  goto except1;
        }
      if (OFint_Dencode(OMstruct_Dget(3, LVd), LVist) == SIG)
        {
	  goto except1;
        }
      if (OFint_Dencode(OMstruct_Dget(5, LVd), LVist) == SIG)
        {
	  goto except1;
        }
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_POSSIBLE))
        {
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
/* c_function_name, OFdate_Ddecode */
/* clu_operation_name, date$decode */
int OFdate_Ddecode(LVist)
     object LVist;
{
  int t1, t2, t3, t4, t5;
  /* begin body */
  if (OFint_Ddecode(LVist) == SIG)
    {
      goto except2;
    }
  t1 = retval_area[0];
  if (OFint_Ddecode(LVist) == SIG)
    {
      goto except2;
    }
  t2 = retval_area[0];
  if (OFint_Ddecode(LVist) == SIG)
    {
      goto except2;
    }
  t3 = retval_area[0];
  if (OFint_Ddecode(LVist) == SIG)
    {
      goto except2;
    }
  t4 = retval_area[0];
  if (OFint_Ddecode(LVist) == SIG)
    {
      goto except2;
    }
  t5 = retval_area[0];
  if (OFint_Ddecode(LVist) == SIG)
    {
      goto except2;
    }
  if (OFdate_Dcreate(t1, t2, t3, t4, t5, retval_area[0]) == SIG)
    {
      goto except2;
    }
  retval_area[0] = retval_area[0];
  return RET;
  if (FALSE)
    {
    except2:
      if (OMstring_Dequal(signame, SLEND_OF_FILE) || OMstring_Dequal(signame, SLNOT_POSSIBLE))
        {
	  return(SIG);
        }
      else
        {
	  goto except1;
        }
    }
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLBAD_FORMAT))
        {
	  sigarg_area[0] = ((string) &str16);
	  signame = SLNOT_POSSIBLE;
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