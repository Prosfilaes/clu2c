% $Id: basic.spc,v 2.1 1997/01/27 11:02:21 ushijima Exp $

%	BASIC TYPES
%
%	CLU Compiler Version 3: specs for basic types and type generators

null_		= pathname "null"
bool_		= pathname "bool"
int_		= pathname "int"
real_		= pathname "real"
char_		= pathname "char"
string_		= pathname "string"
array_		= pathname "array"
sequence_	= pathname "sequence"
record_		= pathname "record"
oneof_		= pathname "oneof"
struct_		= pathname "struct"
variant_	= pathname "variant"
proctype_	= pathname "proctype"
itertype_	= pathname "itertype"
type_		= pathname "type"

% This is a hack to force gcd_tab to be the last DU.

date_		= pathname "date"
delete_file_	= pathname "delete_file"
e_form_		= pathname "e_form"
f_form_		= pathname "f_form"
file_name_	= pathname "file_name"
file_spec_	= pathname "file_spec"
g_form_		= pathname "g_form"
istream_	= pathname "istream"
now_		= pathname "now"
rename_file_	= pathname "rename_file"
set_working_dir_= pathname "set_working_dir"
stream_		= pathname "stream"
user_name_	= pathname "user_name"
working_dir_	= pathname "working_dir"

equal_set   = {t | t has equal:  proctype (t, t) returns (bool)}
similar_set = {t | t has similar: proctype (t, t) returns (bool)}
copy_set    = {t | t has copy: proctype (t) returns (t)}
print_set   = {t | t has print:  proctype (t, pstream)}
encode_set  = {t | t has encode: proctype (t, istream) signals (not_possible(string))}
decode_set  = {t | t has decode: proctype (istream) returns (t)
				 signals (end_of_file, not_possible(string))}
gcd_set	    = {t | t has _gcd: proctype (t, gcd_tab) returns (int)}

str   = string
fname = file_name
fspec = file_spec

null_ = cluster is	equal, similar, copy, print, encode, decode, _gcd

rep = null

equal = proc (n1, n2: null) returns (bool)
	end equal

similar = proc (n1, n2: null) returns (bool)
	end similar

copy = proc (n: null) returns (null)
	end copy

print = proc (n: null, pst: pstream)
	end print

encode = proc (n: null, ist: istream) signals (not_possible(string))
	end encode

decode = proc (ist: istream) returns (null)
			     signals (end_of_file, not_possible(string))
	end decode

_gcd = proc (n: null, tab: gcd_tab) returns (int)
	end _gcd

end null_


bool_ = cluster is	and, or, not, equal, similar, copy, print,
			encode, decode, _gcd

rep = bool

and = proc (b1, b2: bool) returns (bool)
	end and

or = proc (b1, b2: bool) returns (bool)
	end or

not = proc (b: bool) returns (bool)
	end not

equal = proc (b1, b2: bool) returns (bool)
	end equal

similar = proc (b1, b2: bool) returns (bool)
	end similar

copy = proc (b: bool) returns (bool)
	end copy

print = proc (b: bool, pst: pstream)
	end print

encode = proc (b: bool, ist: istream) signals (not_possible(string))
	end encode

decode = proc (ist: istream) returns (bool)
			     signals (end_of_file, not_possible(string))
	end decode

_gcd = proc (b: bool, tab: gcd_tab) returns (int)
	end _gcd

end bool_


int_ = cluster is	add, sub, mul, minus, div, power, mod, abs, min, max,
			from_to_by, from_to, parse, unparse, lt, le, ge, gt,
			equal, similar, copy, print, encode, decode, _gcd

rep = int

add = proc (i1, i2: int) returns (int) signals (overflow)
	end add

sub = proc (i1, i2: int) returns (int) signals (overflow)
	end sub

mul = proc (i1, i2: int) returns (int) signals (overflow)
	end mul

minus = proc (i: int) returns (int) signals (overflow)
	end minus

div = proc (num, den: int) returns (int) signals (zero_divide, overflow)
	end div

power = proc (i, exp: int) returns (int) signals (negative_exponent, overflow)
	end power

mod = proc (i, base: int) returns (int) signals (zero_divide, overflow)
	end mod

abs = proc (i: int) returns (int) signals (overflow)
	end abs

min = proc (i1, i2: int) returns (int)
	end min

max = proc (i1, i2: int) returns (int)
	end max

from_to_by = iter (from_, to_, by_: int) yields (int)
	end from_to_by

from_to = iter (from_, to_: int) yields (int)
	end from_to

parse = proc (s: string) returns (int) signals (bad_format, overflow)
	end parse

unparse = proc (i: int) returns (string)
	end unparse

lt = proc (i1, i2: int) returns (bool)
	end lt

le = proc (i1, i2: int) returns (bool)
	end le

ge = proc (i1, i2: int) returns (bool)
	end ge

gt = proc (i1, i2: int) returns (bool)
	end gt

equal = proc (i1, i2: int) returns (bool)
	end equal

similar = proc (i1, i2: int) returns (bool)
	end similar

copy = proc (i: int) returns (int)
	end copy

print = proc (i: int, pst: pstream)
	end print

encode = proc (i: int, ist: istream) signals (not_possible(string))
	end encode

decode = proc (ist: istream) returns (int)
			     signals (end_of_file, not_possible(string))
	end decode

_gcd = proc (i: int, tab: gcd_tab) returns (int)
	end _gcd

end int_


real_ = cluster is	add, sub, mul, div, minus, power, abs, min, max,
			i2r, r2i, trunc, parse, unparse, exponent, mantissa,
			lt, le, ge, gt, equal, similar, copy, print,
			encode, decode, _gcd, _real_max, _real_min, _max_width,
			_exp_width, _unparse

rep = real

add = proc (r1, r2: real) returns (real) signals (overflow, underflow)
	end add

sub = proc (r1, r2: real) returns (real) signals (overflow, underflow)
	end sub

mul = proc (r1, r2: real) returns (real) signals (overflow, underflow)
	end mul

div = proc (r1, r2: real) returns (real) signals (zero_divide, overflow, underflow)
	end div

minus = proc (r: real) returns (real)
	end minus

power = proc (r1, r2: real) returns (real)
			    signals (zero_divide, complex_result, overflow, underflow)
	end power

abs = proc (r: real) returns (real)
	end abs

min = proc (r1, r2: real) returns (real)
	end min

max = proc (r1, r2: real) returns (real)
	end max

i2r = proc (i: int) returns (real) signals (overflow)
	end i2r

r2i = proc (r: real) returns (int) signals (oveflow)
	end r2i

trunc = proc (r: real) returns (int) signals (overflow)
	end trunc

parse = proc (s: string) returns (real) signals (bad_format, overflow, underflow)
	end parse

unparse = proc (r: real) returns (string)
	end unparse

exponent = proc (r: real) returns (int) signals (undefined)
	end exponent

mantissa = proc (r: real) returns (real)
	end mantissa

lt = proc (r1, r2: real) returns (bool)
	end lt

le = proc (r1, r2: real) returns (bool)
	end le

ge = proc (r1, r2: real) returns (bool)
	end ge

gt = proc (r1, r2: real) returns (bool)
	end gt

equal = proc (r1, r2: real) returns (bool)
	end equal

similar = proc (r1, r2: real) returns (bool)
	end similar

copy = proc (r: real) returns (real)
	end copy

print = proc (r: real, pst: pstream)
	end print

encode = proc (r: real, ist: istream) signals (not_possible(string))
	end encode

decode = proc (ist: istream) returns (real)
			     signals (end_of_file, not_possible(string))
	end decode

_gcd = proc (r: real, tab: gcd_tab) returns (int)
	end _gcd

_real_max = proc () returns (real)
	end _real_max

_real_min = proc () returns (real)
	end _real_min

_max_width = proc () returns (int)
	end _max_width

_exp_width = proc () returns (int)
	end _exp_width

_unparse = proc (r: real) returns (string, int)
	end _unparse

end real_


char_ = cluster is	i2c, c2i, lt, le, ge, gt, equal, similar, copy, print,
			encode, decode, _gcd, width

rep = char

i2c = proc (i: int) returns (char) signals (illegal_char)
	end i2c

c2i = proc (c: char) returns (int)
	end c2i

lt = proc (c1, c2: char) returns (bool)
	end lt

le = proc (c1, c2: char) returns (bool)
	end le

ge = proc (c1, c2: char) returns (bool)
	end ge

gt = proc (c1, c2: char) returns (bool)
	end gt

equal = proc (c1, c2: char) returns (bool)
	end equal

similar = proc (c1, c2: char) returns (bool)
	end similar

copy = proc (c: char) returns (char)
	end copy

print = proc (c: char, pst: pstream)
	end print

encode = proc (c: char, ist: istream) signals (not_possible(string))
	end encode

decode = proc (ist: istream) returns (char)
			     signals (end_of_file, not_possible(string))
	end decode

_gcd = proc (c: char, tab: gcd_tab) returns (int)
	end _gcd

width = proc (c: char) returns (int)
	end width

end char_


string_ = cluster is	size, indexs, indexc, c2s, concat, append, fetch,
			empty, substr, rest, s2ac, ac2s, s2sc, sc2s, chars,
			lt, le, ge, gt, equal, similar, copy, print,
			encode, decode, _gcd, width

rep = string

size = proc (s: string) returns (int)
	end size

indexs = proc (find, s: string) returns (int)
	end indexs

indexc = proc (find: char, s: string) returns (int)
	end indexc

c2s = proc (c: char) returns (string)
	end c2s

concat = proc (s1, s2: string) returns (string)
	end concat

append = proc (s: string, c: char) returns (string)
	end append

fetch = proc (s: string, index: int) returns (char) signals (bounds)
	end fetch

empty = proc (s: string) returns (bool)
	end empty

substr = proc (s: string, start, len: int) returns (string)
					   signals (bounds, negative_size)
	end substr

rest = proc (s: string, start: int) returns (string) signals (bounds)
	end rest

s2ac = proc (s: string) returns (array[char])
	end s2ac

ac2s = proc (a: array[char]) returns (string)
	end ac2s

s2sc = proc (s: string) returns (sequence[char])
	end s2sc

sc2s = proc (q: sequence[char]) returns (string)
	end sc2s

chars = iter (s: string) yields (char)
	end chars

lt = proc (s1, s2: string) returns (bool)
	end lt

le = proc (s1, s2: string) returns (bool)
	end le

ge = proc (s1, s2: string) returns (bool)
	end ge

gt = proc (s1, s2: string) returns (bool)
	end gt

equal = proc (s1, s2: string) returns (bool)
	end equal

similar = proc (s1, s2: string) returns (bool)
	end similar

copy = proc (s: string) returns (string)
	end copy

print = proc (s: string, pst: pstream)
	end print

encode = proc (s: string, ist: istream) signals (not_possible(string))
	end encode

decode = proc (ist: istream) returns (string)
			     signals (end_of_file, not_possible(string))
	end decode

_gcd = proc (s: string, tab: gcd_tab) returns (int)
	end _gcd

width = proc (s: string) returns (int)
	end width

end string_


array_ = cluster [t: type] is	create, new, predict, cons, cons2, empty, low,
				high, size, set_low, trim, fill, fill_copy,
				fetch, bottom, top, store, addh, addl, remh,
				reml, elements, indexes, equal, similar,
				similar1, copy, copy1, print, encode, decode,
				_gcd

rep = array[t]

at = array[t]

create = proc (low_: int) returns (at)
	end create

new = proc () returns (at)
	end new

predict = proc (low_, size_: int) returns (at)
	end predict

cons = proc (q: sequence[t]) returns (at)
	end cons

cons2 = proc (low_: int, q: sequence[t]) returns (at)
	end cons2

empty = proc (a: at) returns (bool)
	end empty

low = proc (a: at) returns (int)
	end low

high = proc (a: at) returns (int)
	end high

size = proc (a: at) returns (int)
	end size

set_low = proc (a: at, low_: int)
	end set_low

trim = proc (a: at, low_, size_: int) signals (bounds, negative_size)
	end trim

fill = proc (low_, size_: int, elt: t) returns (at) signals (negative_size)
	end fill

fill_copy = proc (low_, size_: int, elt: t) returns (at) signals (negative_size)
					    where t in copy_set
	end fill_copy

fetch = proc (a: at, index: int) returns (t) signals (bounds)
	end fetch

bottom = proc (a: at) returns (t) signals (bounds)
	end bottom

top = proc (a: at) returns (t) signals (bounds)
	end top

store = proc (a: at, index: int, elt: t) signals (bounds)
	end store

addh = proc (a: at, elt: t)
	end addh

addl = proc (a: at, elt: t)
	end addl

remh = proc (a: at) returns (t) signals (bounds)
	end remh

reml = proc (a: at) returns (t) signals (bounds)
	end reml

elements = iter (a: at) yields (t)
	end elements

indexes = iter (a: at) yields (int)
	end indexes

equal = proc (a1, a2: at) returns (bool)
	end equal

similar = proc (a1, a2: at) returns (bool)  where t in similar_set
	end similar

similar1 = proc (a1, a2: at) returns (bool)  where t in equal_set
	end similar1

copy = proc (a: at) returns (at)  where t in copy_set
	end copy

copy1 = proc (a: at) returns (at)
	end copy1

print = proc (a: at, pst: pstream)  where t in print_set
	end print

encode = proc (a: at, ist: istream) signals (not_possible(string))  where t in encode_set
	end encode

decode = proc (ist: istream) returns (at)
			     signals (end_of_file, not_possible(string))
			     where t in decode_set
	end decode

_gcd = proc (a: at, tab: gcd_tab) returns (int) where t in gcd_set
	end _gcd

end array_


sequence_ = cluster [t: type] is new, cons, e2s, size, subseq, fill,
				 fill_copy, fetch, bottom, top, replace,
				 addh, addl, remh, reml, concat, a2s, s2a,
				 empty, elements, indexes, equal, similar,
				 copy, print, encode, decode, _gcd

rep = any

seq = sequence[t]

new = proc () returns (seq)
	end new

cons = proc (x: seq) returns (seq)
	end cons

e2s = proc (x: t) returns (seq)
	end e2s

size = proc (s: seq) returns (int)
	end size

subseq = proc (s: seq, start: int, length: int) returns (seq)
						signals (bounds, negative_size)
	end subseq

fill = proc (length: int, x: t) returns (seq) signals (negative_size)
	end fill

fill_copy = proc (length: int, x: t) returns (seq) signals (negative_size)
			where t has copy: proctype (t) returns (t)
	end fill_copy

fetch = proc (s: seq, i: int) returns (t) signals (bounds)
	end fetch

bottom = proc (s: seq) returns (t) signals (bounds)
	end bottom

top = proc (s: seq) returns (t) signals (bounds)
	end top

replace = proc (s: seq, i: int, x: t) returns (seq) signals (bounds)
	end replace

addh = proc (s: seq, x: t) returns (seq)
	end addh

addl = proc (s: seq, x: t) returns (seq)
	end addl

remh = proc (s: seq) returns (seq) signals (bounds)
	end remh

reml = proc (s: seq) returns (seq) signals (bounds)
	end reml

concat = proc (s1, s2: seq) returns (seq)
	end concat

a2s = proc (a: array[t]) returns (seq)
	end a2s

s2a = proc (s: seq) returns (array[t])
	end s2a

empty = proc (s: seq) returns (bool)
	end empty

elements = iter (s: seq) yields (t)
	end elements

indexes = iter (s: seq) yields (int)
	end indexes

equal = proc (s1, s2: seq) returns (bool)
		where t has equal: proctype (t, t) returns (bool)
	end equal

similar = proc (s1, s2: seq) returns (bool)
		where t has similar: proctype (t, t) returns (bool)
	end similar

copy = proc (s: seq) returns (seq)
		where t has copy: proctype (t) returns (t)
	end copy

print = proc (s: seq, pst: pstream)  where t in print_set
	end print

encode = proc (s: seq, ist: istream) signals (not_possible(string))
				     where t in encode_set
	end encode

decode = proc (ist: istream) returns (seq)
			     signals (end_of_file, not_possible(string))
			     where t in decode_set
	end decode

_gcd = proc (s: seq, tab: gcd_tab) returns (int) where t in gcd_set
	end _gcd

end sequence_


# extend


record_ = selector [rt, tt: type] is	%create, r_gets_s,
					get_, set_, r_gets_r,
					equal, similar, similar1,
					copy, copy1, print, encode, decode,
					_gcd

rep = any

% create = proc (q: sequence[...]) returns (rt) end create

get_ = proc [t: type] (r: rt) returns (t)
	end get_

set_ = proc [t: type] (r: rt, elt: t)
	end set_

r_gets_r = proc (r1, r2: rt)
	end r_gets_r

% r_gets_s = proc (r: rt, s: struct[...]) end r_gets_s

equal = proc (r1, r2: rt) returns (bool)
	end equal

similar = proc (r1, r2: rt) returns (bool)  where tt in similar_set
	end similar

similar1 = proc (r1, r2: rt) returns (bool)  where tt in equal_set
	end similar1

copy = proc (r: rt) returns (rt)  where tt in copy_set
	end copy

copy1 = proc (r: rt) returns (rt)
	end copy1

print = proc (r: rt, pst: pstream)  where tt in print_set
	end print

encode = proc (r: rt, ist: istream) signals (not_possible(string))
				    where tt in encode_set
	end encode

decode = proc (ist: istream) returns (rt)
			     signals (end_of_file, not_possible(string))
			     where tt in decode_set
	end decode

_gcd = proc (r: rt, tab: gcd_tab) returns (int) where tt in gcd_set
	end _gcd

end record_


oneof_ = selector [ot, tt: type] is	make_, is_, value_,
					% o2v, v2o,
					equal, similar, copy, print,
					encode, decode, _gcd

rep = any

make_ = proc [t: type] (x: t) returns (ot)
	end make_

is_ = proc [t: type] (o: ot) returns (bool)
	end is_

value_ = proc [t: type] (o: ot) returns (t) signals (wrong_tag)
	end value_

% o2v = proc (o: ot) returns (variant[...]) end o2v
% v2o = proc (v: variant[...]) returns (ot) end v2o

equal = proc (o1, o2: ot) returns (bool)  where tt in equal_set
	end equal

similar = proc (o1, o2: ot) returns (bool)  where tt in similar_set
	end similar

copy = proc (o: ot) returns (ot)  where tt has copy: proctype (tt) returns (tt)
	end copy

print = proc (o: ot, pst: pstream)  where tt in print_set
	end print

encode = proc (o: ot, ist: istream) signals (not_possible(string))
				    where tt in encode_set
	end encode

decode = proc (ist: istream) returns (ot)
			     signals (end_of_file, not_possible(string))
			     where tt in decode_set
	end decode

_gcd = proc (o: ot, tab: gcd_tab) returns (int) where tt in gcd_set
	end _gcd

end oneof_


struct_ = selector [st, tt: type] is	create, get_, replace_,
					% s2r, r2s,
					equal, similar, copy, print,
					encode, decode, _gcd

rep = any

create = proc (s: st) returns (st)
	end create

get_ = proc [t: type] (s: st) returns (t)
	end get_

replace_ = proc [t: type] (s: st, elt: t) returns (st)
	end replace_

% s2r = proc (s: st) returns (record[...]) end s2r
% r2s = proc (r: record[...]) returns (st) end r2s

equal = proc (s1, s2: st) returns (bool)  where tt in equal_set
	end equal

similar = proc (s1, s2: st) returns (bool)  where tt in similar_set
	end similar

copy = proc (s: st) returns (st)  where tt in copy_set
	end copy

print = proc (s: st, pst: pstream)  where tt in print_set
	end print

encode = proc (s: st, ist: istream) signals (not_possible(string))
				    where tt in encode_set
	end encode

decode = proc (ist: istream) returns (st)
			     signals (end_of_file, not_possible(string))
			     where tt in decode_set
	end decode

_gcd = proc (s: st, tab: gcd_tab) returns (int) where tt in gcd_set
	end _gcd

end struct_


variant_ = selector [vt, tt: type] is	make_, change_, is_, value_, v_gets_v,
					% v_gets_o,
					equal, similar, similar1, copy, copy1,
					print, encode, decode, _gcd

rep = any

make_ = proc [t: type] (x: t) returns (vt)
	end make_

change_ = proc [t: type] (v: vt, x: t)
	end change_

is_ = proc [t: type] (v: vt) returns (bool)
	end is_

value_ = proc [t: type] (v: vt) returns (t) signals (wrong_tag)
	end value_

v_gets_v = proc (v1, v2: vt)
	end v_gets_v

% v_gets_o = proc (v: vt, o: oneof[...]) end v_gets_o end

equal = proc (v1, v2: vt) returns (bool)
	end equal

similar = proc (v1, v2: vt) returns (bool)  where tt in similar_set
	end similar

similar1 = proc (v1, v2: vt) returns (bool)  where tt in equal_set
	end similar1

copy = proc (v: vt) returns (vt)  where tt in copy_set
	end copy

copy1 = proc (v: vt) returns (vt)
	end copy1

print = proc (v: vt, pst: pstream)  where tt in print_set
	end print

encode = proc (v: vt, ist: istream) signals (not_possible(string))
				    where tt in encode_set
	end encode

decode = proc (ist: istream) returns (vt)
			     signals (end_of_file, not_possible(string))
			     where tt in decode_set
	end decode

_gcd = proc (v: vt, tab: gcd_tab) returns (int) where tt in gcd_set
	end _gcd

end variant_


proctype_ = applytype [pt: type] is	equal, similar, copy

rep = any

equal = proc (p1, p2: pt) returns (bool)
	end equal

similar = proc (p1, p2: pt) returns (bool)
	end similar

copy = proc (p: pt) returns (pt)
	end copy

end proctype_


itertype_ = applytype [it: type] is	equal, similar, copy

rep = any

equal = proc (p1, p2: it) returns (bool)
	end equal

similar = proc (p1, p2: it) returns (bool)
	end similar

copy = proc (p: it) returns (it)
	end copy

end itertype_


type_ = cluster is	equal, similar, copy

rep = type

equal = proc (t1, t2: type) returns (bool)
	end equal

similar = proc (t1, t2: type) returns (bool)
	end similar

copy = proc (t: type) returns (type)
	end copy

end type_


# normal


file_name = cluster is	create, parse, unparse, get_dir, get_name, get_suffix,
			get_other, make_output, make_temp, print,
			equal, similar, copy, encode, decode, _gcd
    
rep = any

create = proc (dir, name, suffix, other: string) returns (fname) signals (bad_format)
	end create
    
parse = proc (s: string) returns (fname) signals (bad_format)
	end parse
    
unparse = proc (f: fname) returns (string)
	end unparse
    
get_dir = proc (x: fname) returns (string)
	end get_dir
    
get_name = proc (x: fname) returns (string)
	end get_name
    
get_suffix = proc (x: fname) returns (string)
	end get_suffix
    
get_other = proc (x: fname) returns (string)
	end get_other
    
make_output = proc (x: fname, ext: string) returns (fname)
	end make_output
    
make_temp = proc (tdir, prog, kind: string) returns (fname)
				    signals (bad_format)
	end make_temp
    
print = proc (x: fname, ps: pstream)
	end print

equal = proc (x, y: fname) returns (bool)
	end equal
    
similar = proc (x, y: fname) returns (bool)
	end similar
    
copy = proc (x: fname) returns (fname)
	end copy
    
encode = proc (x: fname, ist: istream) signals (not_possible(string))
	end encode

decode = proc (ist: istream) returns (fname)
			     signals (end_of_file, not_possible(string))
	end decode

_gcd = proc (x: fname, tab: gcd_tab) returns (int)
	end _gcd

end file_name

file_spec = cluster is	create, parse, unparse, get_dir, get_name, get_suffix,
			get_other, print, equal, similar, copy, encode, decode,
			_gcd
    
rep = any

create = proc (dir, name, suffix, other: string) returns (fspec) signals (bad_format)
	end create
    
parse = proc (s: string) returns (fspec) signals (bad_format)
	end parse
    
unparse = proc (f: fspec) returns (string)
	end unparse
    
get_dir = proc (x: fspec) returns (string)
	end get_dir
    
get_name = proc (x: fspec) returns (string)
	end get_name
    
get_suffix = proc (x: fspec) returns (string)
	end get_suffix
    
get_other = proc (x: fspec) returns (string)
	end get_other
    
print = proc (x: fspec, ps: pstream)
	end print

equal = proc (x, y: fspec) returns (bool)
	end equal
    
similar = proc (x, y: fspec) returns (bool)
	end similar
    
copy = proc (x: fspec) returns (fspec)
	end copy
    
encode = proc (x: fspec, ist: istream) signals (not_possible(string))
	end encode

decode = proc (ist: istream) returns (fspec)
			     signals (end_of_file, not_possible(string))
	end decode

_gcd = proc (x: fspec, tab: gcd_tab) returns (int)
	end _gcd

end file_spec


delete_file = proc (fn: file_name) signals (not_possible(string))
	end delete_file

rename_file = proc (from, to: file_name) signals (not_possible(string))
	end rename_file

working_dir = proc () returns (string)
	end working_dir

set_working_dir = proc (d: string) signals (bad_format)
	end set_working_dir

now = proc () returns (date)
	end now

user_name = proc () returns (string)
	end user_name

stream = cluster is open, primary_input, primary_output, error_output,
		    add_script, rem_script, unscript, can_read,
		    can_write, getc, peekc, pending, empty, putc, putc_image,
		    getc_image, get_lineno, set_lineno, reset, flush,
		    get_line_length, get_page_length, get_date, set_date,
		    get_name, close, abort, is_closed, is_terminal, getl, putl,
		    gets, gets_image, puts, puts_image, putzero, putleft,
		    putright, putspace, create_input, create_output,
		    get_contents, getbuf, display, modify_display,
		    get_prompt, set_prompt, get_rescan, set_rescan,
		    get_input_buffered, set_input_buffered,
		    get_output_buffered, set_output_buffered,
		    get_eof_flag, set_eof_flag, equal, similar,
		    copy, print, _reset, _close_all, _open_streams,
		    get_code, set_code

rep = any

open = proc (f: file_name, access: string) returns (stream)
					   signals (not_possible(string))
	end open

primary_input = proc () returns (stream)
	end primary_input

primary_output = proc () returns (stream)
	end primary_output

error_output = proc () returns (stream)
	end error_output

add_script = proc (st1, st2: stream) signals (script_failed)
	end add_script

rem_script = proc (st1, st2: stream)
	end rem_script

unscript = proc (st: stream)
	end unscript

can_read = proc (st: stream) returns (bool)
	end can_read

can_write = proc (st: stream) returns (bool)
	end can_write

getc = proc (st: stream) returns (char) signals (end_of_file, not_possible(string))
	end getc

peekc = proc (st: stream) returns (char) signals (end_of_file, not_possible(string))
	end peekc

pending = proc (st: stream) returns (bool) signals (not_possible(string))
	end pending

empty = proc (st: stream) returns (bool) signals (not_possible(string))
	end empty

putc = proc (st: stream, c: char) signals (not_possible(string))
	end putc

putc_image = proc (st: stream, c: char) signals (not_possible(string))
	end putc_image

getc_image = proc (st: stream) returns (char) signals (end_of_file, not_possible(string))
	end getc_image

get_lineno = proc (st: stream) returns (int) signals (not_possible(string))
	end get_lineno

set_lineno = proc (st: stream, ln: int) signals(not_possible(string))
	end set_lineno

reset = proc (st: stream) signals (not_possible(string))
	end reset

flush = proc (st: stream) signals (not_possible(string))
	end flush

get_line_length = proc (st: stream) returns (int) signals (no_limit)
	end get_line_length

get_page_length = proc (st: stream) returns (int) signals (no_limit)
	end get_page_length

get_date = proc (st: stream) returns (date) signals (not_possible(string))
	end get_date

set_date = proc (st: stream, new_date: date) signals (not_possible(string))
	end set_date

get_name = proc (st: stream) returns (file_name) signals (not_possible(string))
	end get_name

close = proc (st: stream) signals (not_possible(string))
	end close

abort = proc (st: stream)
	end abort

is_closed = proc (st: stream) returns (bool)
	end is_closed

is_terminal = proc (st: stream) returns (bool)
	end is_terminal

getl = proc (st: stream) returns (string) signals (end_of_file, not_possible(string))
	end getl

putl = proc (st: stream, line: string) signals (not_possible(string))
	end putl

gets = proc (st: stream, term: string) returns (string)
				    signals (end_of_file, not_possible(string))
	end gets

gets_image = proc (st: stream, term: string) returns (string)
				    signals (end_of_file, not_possible(string))
	end gets_image

puts = proc (st: stream, s: string) signals (not_possible(string))
	end puts

puts_image = proc (st: stream, s: string) signals (not_possible(string))
	end puts_image

putzero = proc (st: stream, s: string, size: int) signals (not_possible(string),
							   negative_field_width)
	end putzero

putleft = proc (st: stream, s: string, size: int) signals (not_possible(string),
							   negative_field_width)
	end putleft

putright = proc (st: stream, s: string, size: int) signals (not_possible(string),
							    negative_field_width)
	end putright

putspace = proc (st: stream, len: int) signals (not_possible(string),
					        negative_field_width)
	end putspace

create_input = proc (s: string) returns (stream)
	end create_input

create_output = proc () returns (stream)
	end create_output

get_contents = proc (st: stream) returns (string) signals (not_possible(string))
	end get_contents

getbuf = proc (st: stream, term: string) returns (string)
				      signals (not_possible(string), end_of_file)
	end getbuf
	
display = proc (st: stream, s: string) returns (bool)
				       signals (not_possible(string))
	end display

modify_display = proc (st: stream, term: string) signals (not_possible(string))
	end modify_display

get_prompt = proc (st: stream) returns (string)
	end get_prompt

set_prompt = proc (st: stream, prompt: string)
	end set_prompt

get_rescan = proc (st: stream) returns (string)
	end get_rescan

set_rescan = proc (st: stream, s: string) signals (not_possible(string))
	end set_rescan

get_input_buffered = proc (st: stream) returns (bool)
	end get_input_buffered

set_input_buffered = proc (st: stream, flag: bool)
	end set_input_buffered

get_output_buffered = proc (st: stream) returns (bool)
	end get_output_buffered

set_output_buffered = proc (st: stream, flag: bool)
	end set_output_buffered

get_eof_flag = proc (st: stream) returns (bool)
	end get_eof_flag

set_eof_flag = proc (st: stream, eofok: bool) signals (not_possible(string))
	end set_eof_flag

equal = proc (x,y: stream) returns (bool)
	end equal

similar = proc (x,y: stream) returns (bool)
	end similar

copy = proc (x: stream) returns (stream)
	end copy

print = proc (x: stream, ps: pstream)
	end print

_reset = proc ()
	end _reset

_close_all = proc ()
	end _close_all

_open_streams = iter () yields (stream)
	end _open_streams

get_code = proc(x: stream) returns(string) signals(not_possible(string))
	end get_code

set_code = proc(x: stream, code: string) signals(not_possible(string))
	end set_code

end stream


istream = cluster is	open, empty, reset, flush, get_date, set_date,
			get_name, close, abort, is_closed, equal, similar, copy,
			can_read, can_write

rep = any

open = proc (fn: file_name, mode: string) returns (istream)
					  signals (not_possible(string))
	end open

can_read = proc (ist: istream) returns (bool)
	end can_read

can_write = proc (ist: istream) returns (bool)
	end can_write

empty = proc (ist: istream) returns (bool) signals (not_possible(string))
	end empty

reset = proc (ist: istream) signals (not_possible(string))
	end reset

flush = proc (ist: istream)
	end flush

get_date = proc (ist: istream) returns (date) signals (not_possible(string))
	end get_date

set_date = proc (ist: istream) signals (not_possible(string))
	end set_date

get_name = proc (ist: istream) returns (file_name)
	end get_name

close = proc (ist: istream)
	end close

abort = proc (ist: istream)
	end abort

is_closed = proc (ist: istream) returns (bool)
	end is_closed

equal = proc (ist1, ist2: istream) returns (bool)
	end equal

similar = proc (ist1, ist2: istream) returns (bool)
	end similar

copy = proc (ist: istream) returns (istream)
	end copy

end istream


date = cluster is	create, get_day, get_month, get_year, get_hour, get_minute,
			get_second, get_all, unparse, unparse_date, unparse_time, equal, similar,
			copy, lt, le, gt, ge, print, encode, decode, _gcd

rep = any

create = proc (day, month, year, hour, minute, second: int) returns (date)
							    signals (bad_format)
	end create

get_day = proc (d: date) returns (int)
	end get_day

get_month = proc (d: date) returns (int)
	end get_month

get_year = proc (d: date) returns (int)
	end get_year

get_hour = proc (d: date) returns (int)
	end get_hour

get_minute = proc (d: date) returns (int)
	end get_minute

get_second = proc (d: date) returns (int)
	end get_second

get_all = proc (d: date) returns (int, int, int, int, int, int)
	end get_all

unparse = proc (d: date) returns (string)
	end unparse

unparse_date = proc (d: date) returns (string)
	end unparse_date

unparse_time = proc (d: date) returns (string)
	end unparse_time

equal = proc (date1, date2: date) returns (bool)
	end equal

similar = proc (date1, date2: date) returns (bool)
	end similar

copy = proc (d: date) returns (date)
	end copy

lt = proc (d1, d2: date) returns (bool)
	end lt

le = proc (d1, d2: date) returns (bool)
	end le

gt = proc (d1, d2: date) returns (bool)
	end gt

ge = proc (d1, d2: date) returns (bool)
	end ge

print = proc (d: date, ps: pstream)
	end print

encode = proc (d: date, ist: istream) signals (not_possible(string))
	end encode

decode = proc (ist: istream) returns (date)
			     signals (end_of_file, not_possible(string))
	end decode

_gcd = proc (d: date, tab: gcd_tab) returns (int)
	end _gcd

end date

e_form = proc (x: real, i, f: int) returns (string)
				   signals (illegal_field_width)
	end e_form

f_form = proc (x: real, i, f: int) returns (string)
			signals (illegal_field_width, insufficient_field_width)
	end f_form

g_form = proc (x: real, i, f: int) returns (string)
			signals (illegal_field_width, insufficient_field_width)
	end g_form

_cvt = proc [from, to: type] (x: from) returns (to)
	% Built into the compiler.
	end _cvt
