/* Generated by plink */

#include <clu2c.h>

/* Declarations of entry functions */

int OF0array_Dsimilar();
int OF1array_Dsimilar();
int OF0record_Dsimilar();
int OF0oneof_Dsimilar();
int OF1oneof_Dsimilar();
int OF2oneof_Dsimilar();
int OFcluinst_Dsimilar();
int OFint_Dsimilar();
int OFselinst_Dsimilar();
int OFstring_Dsimilar();
int OF0assoc__array_Dnew();
int OF1assoc__array_Dnew();
int OF2assoc__array_Dnew();
int OF0assoc__array_Dreset();
int OF0assoc__array_Dlookup();
int OF1assoc__array_Dlookup();
int OF2assoc__array_Dlookup();
int OF0assoc__array_Denter();
int OF1assoc__array_Denter();
int OF2assoc__array_Denter();
int OF0assoc__array_Dvalues();
int OF1assoc__array_Dvalues();

/* Definitions of entry pointers */

proctype PV1_INappgen_Dlookup__inst = OF0array_Dsimilar;
proctype PV1_INclugen_Dlookup__inst = OF0array_Dsimilar;
proctype PV2_INcluinst_Dlookup__op = OF0array_Dsimilar;
proctype PV2_INselinst_Dlookup__op = OF0array_Dsimilar;
proctype PV1_INselgen_Dlookup__inst = OF1array_Dsimilar;
proctype PV1_INtype__id = OF0oneof_Dsimilar;
proctype PV1_INclugen_Dcreate = OF0assoc__array_Dnew;
proctype PV1_INselgen_Dcreate = OF0assoc__array_Dnew;
proctype PV1_INcluinst_Dcreate = OF1assoc__array_Dnew;
proctype PV1_INselinst_Dcreate = OF1assoc__array_Dnew;
proctype PV1_IN_IF_IN_Cgentab = OF2assoc__array_Dnew;
proctype PV1_INgentab_Dinit = OF0assoc__array_Dreset;
proctype PV1_INclugen_Dlookup__op = OF0assoc__array_Dlookup;
proctype PV1_INselgen_Dlookup__op = OF0assoc__array_Dlookup;
proctype PV1_INcluinst_Dlookup__op = OF1assoc__array_Dlookup;
proctype PV1_INcluinst_Denter__op = OF1assoc__array_Dlookup;
proctype PV1_INselinst_Dlookup__op = OF1assoc__array_Dlookup;
proctype PV1_INselinst_Denter__op = OF1assoc__array_Dlookup;
proctype PV1_INgentab_Dlookup = OF2assoc__array_Dlookup;
proctype PV1_INclugen_Denter__op = OF0assoc__array_Denter;
proctype PV1_INselgen_Denter__op = OF0assoc__array_Denter;
proctype PV2_INcluinst_Denter__op = OF1assoc__array_Denter;
proctype PV2_INselinst_Denter__op = OF1assoc__array_Denter;
proctype PV1_INgentab_Denter = OF2assoc__array_Denter;
proctype PV1_INclugen_Dfix__invokes = OF0assoc__array_Dvalues;
proctype PV1_INclugen_Demit__fundecl = OF0assoc__array_Dvalues;
proctype PV1_INclugen_Demit__ptrdefn = OF0assoc__array_Dvalues;
proctype PV1_INclugen_Demit__fundefn = OF0assoc__array_Dvalues;
proctype PV1_INclugen_Demit__types = OF0assoc__array_Dvalues;
proctype PV1_INselgen_Dfix__invokes = OF0assoc__array_Dvalues;
proctype PV1_INselgen_Demit__fundecl = OF0assoc__array_Dvalues;
proctype PV1_INselgen_Demit__ptrdefn = OF0assoc__array_Dvalues;
proctype PV1_INselgen_Demit__fundefn = OF0assoc__array_Dvalues;
proctype PV1_INselgen_Demit__types = OF0assoc__array_Dvalues;
proctype PV1_INgentab_Dgenerators = OF1assoc__array_Dvalues;

/* Definitions of type ID's */

/* Definitions of entry functions */

/*
 * array$fill_copy
 */

/*
 * array$similar
 */

int OF0array_Dsimilar(arg1, arg2)
    object arg1, arg2;
{
    static void *oplist[] = {
	OF1oneof_Dsimilar,
    };
    return OFarray_Dsimilar(oplist, arg1, arg2);
}

int OF1array_Dsimilar(arg1, arg2)
    object arg1, arg2;
{
    static void *oplist[] = {
	OF0record_Dsimilar,
    };
    return OFarray_Dsimilar(oplist, arg1, arg2);
}

/*
 * array$similar1
 */

/*
 * array$copy
 */

/*
 * array$print
 */

/*
 * array$encode
 */

/*
 * array$decode
 */

/*
 * array$_gcd
 */

/*
 * record$similar
 */

int OF0record_Dsimilar(arg1, arg2)
    object arg1, arg2;
{
    static void *oplist[] = {
	OF0oneof_Dsimilar,
	OFstring_Dsimilar,
    };
    return OFrecord_Dsimilar(oplist, arg1, arg2);
}

/*
 * oneof$similar
 */

int OF0oneof_Dsimilar(arg1, arg2)
    object arg1, arg2;
{
    static void *oplist[] = {
	OFcluinst_Dsimilar,
	OFint_Dsimilar,
	OFselinst_Dsimilar,
    };
    return OFoneof_Dsimilar(oplist, arg1, arg2);
}

int OF1oneof_Dsimilar(arg1, arg2)
    object arg1, arg2;
{
    static void *oplist[] = {
	OF0oneof_Dsimilar,
	OF2oneof_Dsimilar,
    };
    return OFoneof_Dsimilar(oplist, arg1, arg2);
}

int OF2oneof_Dsimilar(arg1, arg2)
    object arg1, arg2;
{
    static void *oplist[] = {
	OFint_Dsimilar,
	OFstring_Dsimilar,
    };
    return OFoneof_Dsimilar(oplist, arg1, arg2);
}

/*
 * cluinst$similar
 */


/*
 * int$similar
 */


/*
 * selinst$similar
 */


/*
 * string$similar
 */


/*
 * assoc_array$new
 */

int OF0assoc__array_Dnew()
{
    static param_info pi = {0, 0, 0, 0};
    return OFassoc__array_Dnew(&pi);
}

int OF1assoc__array_Dnew()
{
    static param_info pi = {0, 1, 1, 0};
    return OFassoc__array_Dnew(&pi);
}

int OF2assoc__array_Dnew()
{
    static param_info pi = {0, 2, 2, 0};
    return OFassoc__array_Dnew(&pi);
}

/*
 * assoc_array$reset
 */

int OF0assoc__array_Dreset(arg1)
    object arg1;
{
    static param_info pi = {0, 0, 2, 0};
    return OFassoc__array_Dreset(&pi, arg1);
}

/*
 * assoc_array$lookup
 */

int OF0assoc__array_Dlookup(arg1, arg2)
    object arg1, arg2;
{
    static param_info pi = {0, 0, 0, 0};
    return OFassoc__array_Dlookup(&pi, arg1, arg2);
}

int OF1assoc__array_Dlookup(arg1, arg2)
    object arg1, arg2;
{
    static param_info pi = {0, 1, 1, 0};
    return OFassoc__array_Dlookup(&pi, arg1, arg2);
}

int OF2assoc__array_Dlookup(arg1, arg2)
    object arg1, arg2;
{
    static param_info pi = {0, 2, 2, 0};
    return OFassoc__array_Dlookup(&pi, arg1, arg2);
}

/*
 * assoc_array$enter
 */

int OF0assoc__array_Denter(arg1, arg2, arg3)
    object arg1, arg2, arg3;
{
    static param_info pi = {0, 0, 0, 0};
    return OFassoc__array_Denter(&pi, arg1, arg2, arg3);
}

int OF1assoc__array_Denter(arg1, arg2, arg3)
    object arg1, arg2, arg3;
{
    static param_info pi = {0, 1, 1, 0};
    return OFassoc__array_Denter(&pi, arg1, arg2, arg3);
}

int OF2assoc__array_Denter(arg1, arg2, arg3)
    object arg1, arg2, arg3;
{
    static param_info pi = {0, 2, 2, 0};
    return OFassoc__array_Denter(&pi, arg1, arg2, arg3);
}

/*
 * assoc_array$keys
 */

/*
 * assoc_array$values
 */

int OF0assoc__array_Dvalues(arg1, arg2, arg3)
    object arg1, arg2, arg3;
{
    static param_info pi = {0, 0, 0, 0};
    return OFassoc__array_Dvalues(&pi, arg1, arg2, arg3);
}

int OF1assoc__array_Dvalues(arg1, arg2, arg3)
    object arg1, arg2, arg3;
{
    static param_info pi = {0, 1, 2, 0};
    return OFassoc__array_Dvalues(&pi, arg1, arg2, arg3);
}