/* Generated by clu2c (version 1.99.3) */
/* option, optimize time */
/* depend,file_is_block_device,_external_stat,_external_struct_stat,file_name,file_name_to_string*/
/* depend,file_is_character_device,_external_stat,_external_struct_stat,file_name,file_name_to_string*/
/* depend,file_is_directory,_external_stat,_external_struct_stat,file_name,file_name_to_string*/
/* depend,file_is_fifo,_external_stat,_external_struct_stat,file_name,file_name_to_string*/
/* depend,file_is_regular,_external_stat,_external_struct_stat,file_name,file_name_to_string*/
/* depend,file_is_symbolic_link,_external_stat,_external_struct_stat,file_name,file_name_to_string*/

#include <clu2c.h>

/* begin module */
/* c_function_name, AFfile__is__block__device */
/* clu_operation_name, file_is_block_device */
int AFfile__is__block__device(LVfn)
     object LVfn;
{
  object LVs= 0;
  /* begin body */
  if (AFfile__name__to__string(LVfn) == SIG)
    {
      goto except1;
    }
  if (AF__external__stat(retval_area[0]) == SIG)
    {
      goto except1;
    }
  LVs = retval_area[0];
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_POSSIBLE))
        {
	  retval_area[0] = FALSE;
	  return RET;
        }
      else
        {
	  goto except0;
        }
    }
  if (OF__external__struct__stat_Dis__block__device(LVs) == SIG)
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
/* c_function_name, AFfile__is__character__device */
/* clu_operation_name, file_is_character_device */
int AFfile__is__character__device(LVfn)
     object LVfn;
{
  object LVs= 0;
  /* begin body */
  if (AFfile__name__to__string(LVfn) == SIG)
    {
      goto except1;
    }
  if (AF__external__stat(retval_area[0]) == SIG)
    {
      goto except1;
    }
  LVs = retval_area[0];
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_POSSIBLE))
        {
	  retval_area[0] = FALSE;
	  return RET;
        }
      else
        {
	  goto except0;
        }
    }
  if (OF__external__struct__stat_Dis__character__device(LVs) == SIG)
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
/* c_function_name, AFfile__is__directory */
/* clu_operation_name, file_is_directory */
int AFfile__is__directory(LVfn)
     object LVfn;
{
  object LVs= 0;
  /* begin body */
  if (AFfile__name__to__string(LVfn) == SIG)
    {
      goto except1;
    }
  if (AF__external__stat(retval_area[0]) == SIG)
    {
      goto except1;
    }
  LVs = retval_area[0];
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_POSSIBLE))
        {
	  retval_area[0] = FALSE;
	  return RET;
        }
      else
        {
	  goto except0;
        }
    }
  if (OF__external__struct__stat_Dis__directory(LVs) == SIG)
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
/* c_function_name, AFfile__is__fifo */
/* clu_operation_name, file_is_fifo */
int AFfile__is__fifo(LVfn)
     object LVfn;
{
  object LVs= 0;
  /* begin body */
  if (AFfile__name__to__string(LVfn) == SIG)
    {
      goto except1;
    }
  if (AF__external__stat(retval_area[0]) == SIG)
    {
      goto except1;
    }
  LVs = retval_area[0];
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_POSSIBLE))
        {
	  retval_area[0] = FALSE;
	  return RET;
        }
      else
        {
	  goto except0;
        }
    }
  if (OF__external__struct__stat_Dis__fifo(LVs) == SIG)
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
/* c_function_name, AFfile__is__regular */
/* clu_operation_name, file_is_regular */
int AFfile__is__regular(LVfn)
     object LVfn;
{
  object LVs= 0;
  /* begin body */
  if (AFfile__name__to__string(LVfn) == SIG)
    {
      goto except1;
    }
  if (AF__external__stat(retval_area[0]) == SIG)
    {
      goto except1;
    }
  LVs = retval_area[0];
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_POSSIBLE))
        {
	  retval_area[0] = FALSE;
	  return RET;
        }
      else
        {
	  goto except0;
        }
    }
  if (OF__external__struct__stat_Dis__regular(LVs) == SIG)
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
/* c_function_name, AFfile__is__symbolic__link */
/* clu_operation_name, file_is_symbolic_link */
int AFfile__is__symbolic__link(LVfn)
     object LVfn;
{
  object LVs= 0;
  /* begin body */
  if (AFfile__name__to__string(LVfn) == SIG)
    {
      goto except1;
    }
  if (AF__external__stat(retval_area[0]) == SIG)
    {
      goto except1;
    }
  LVs = retval_area[0];
  if (FALSE)
    {
    except1:
      if (OMstring_Dequal(signame, SLNOT_POSSIBLE))
        {
	  retval_area[0] = FALSE;
	  return RET;
        }
      else
        {
	  goto except0;
        }
    }
  if (OF__external__struct__stat_Dis__symbolic__link(LVs) == SIG)
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
