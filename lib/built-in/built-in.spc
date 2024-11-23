% built-in.spc - interface specifications for the built-in types
%
% This file was derived from PCLU distribution (as of 11/18/93), and
% has been modified by Department of Mathematical and Computing
% Sciences, Tokyo Institute of Technology.
%
% Conditions for using, copying, modifying, and distributing this
% file are the same as those of PCLU.
%
% $Id: built-in.spc,v 2.0 1996/06/10 09:01:33 ushijima Exp $


null_     = pathname "null"
bool_     = pathname "bool"
int_      = pathname "int"
real_     = pathname "real"
char_     = pathname "char"
string_   = pathname "string"
array_    = pathname "array"
sequence_ = pathname "sequence"
record_   = pathname "record"
struct_   = pathname "struct"
oneof_    = pathname "oneof"
variant_  = pathname "variant"
proctype_ = pathname "proctype"
itertype_ = pathname "itertype"
type_     = pathname "type"


% Null

null_ = cluster is equal, similar, copy, encode, decode, print, _gcd

% Operations

equal = proc(N1, N2: null) returns(bool)
	% effects  ...
	end equal

similar = proc(N1, N2: null) returns(bool)
	% effects  ...
	end similar

copy = proc(N: null) returns(null)
	% effects  ...
	end copy

% Operations for istream

encode = proc(N: null, IST: istream) signals(not_possible(string))
	% modifies IST
	% effects  ...
	end encode

decode = proc(IST: istream) returns(null)
	 signals(end_of_file, not_possible(string))
	% modifies IST
	% effects  ...
	end decode

% Operation for pstream

print = proc(N: null, PST: pstream)
	% modifies PST
	% effects  ...
	end print

% Operation for gc_dump

_gcd = proc(N: null, TAB: gcd_tab) returns(int)
	% modifies TAB
	% effects  ...
	end _gcd

end null_


% Bool

bool_ = cluster is and, or, not, equal, similar, copy, encode, decode, print,
	_gcd

% Operations

and = proc(B1, B2: bool) returns(bool)
	% effects  ...
	end and

or = proc(B1, B2: bool) returns(bool)
	% effects  ...
	end or

not = proc(B: bool) returns(bool)
	% effects  ...
	end not

equal = proc(B1, B2: bool) returns(bool)
	% effects  ...
	end equal

similar = proc(B1, B2: bool) returns(bool)
	% effects  ...
	end similar

copy = proc(B: bool) returns(bool)
	% effects  ...
	end copy

% Operations for istream

encode = proc(B: bool, IST: istream) signals(not_possible(string))
	% modifies IST
	% effects  ...
	end encode

decode = proc(IST: istream) returns(bool)
	 signals(end_of_file, not_possible(string))
	% modifies IST
	% effects  ...
	end decode

% Operation for pstream

print = proc(B: bool, PST: pstream)
	% modifies PST
	% effects  ...
	end print

% Operation for gc_dump

_gcd = proc(B: bool, TAB: gcd_tab) returns(int)
	% modifies TAB
	% effects  ...
	end _gcd

end bool_


% Int

int_ = cluster is add, sub, mul, minus, div, power, mod, abs, min, max,
       from_to_by, from_to, parse, unparse, lt, le, ge, gt, equal, similar,
       copy, print, encode, decode, _gcd

% Operations

add = proc(I1, I2: int) returns(int) signals(overflow)
	% effects  ...
	end add

sub = proc(I1, I2: int) returns(int) signals(overflow)
	% effects  ...
	end sub

mul = proc(I1, I2: int) returns(int) signals(overflow)
	% effects  ...
	end mul

minus = proc(I: int) returns(int) signals(overflow)
	% effects  ...
	end minus

div = proc(I1, I2: int) returns(int) signals(zero_divide, overflow)
	% effects  ...
	end div

power = proc(I, EXP: int) returns(int) signals(negative_exponent, overflow)
	% effects  ...
	end power

mod = proc(I, BASE: int) returns(int) signals(zero_divide, overflow)
	% effects  ...
	end mod

abs = proc(I: int) returns(int) signals(overflow)
	% effects  ...
	end abs

min = proc(I1, I2: int) returns(int)
	% effects  ...
	end min

max = proc(I1, I2: int) returns(int)
	% effects  ...
	end max

from_to_by = iter(FROM, TO, BY: int) yields(int)
	% effects  ...
	end from_to_by

from_to = iter(FROM, TO: int) yields(int)
	% effects  ...
	end from_to

parse = proc(S: string) returns(int) signals(bad_format, overflow)
	% effects  ...
	end parse

unparse = proc(I: int) returns(string)
	% effects  ...
	end unparse

lt = proc(I1, I2: int) returns(bool)
	% effects  ...
	end lt

le = proc(I1, I2: int) returns(bool)
	% effects  ...
	end le

ge = proc(I1, I2: int) returns(bool)
	% effects  ...
	end ge

gt = proc(I1, I2: int) returns(bool)
	% effects  ...
	end gt

equal = proc(I1, I2: int) returns(bool)
	% effects  ...
	end equal

similar = proc(I1, I2: int) returns(bool)
	% effects  ...
	end similar

copy = proc(I: int) returns(int)
	% effects  ...
	end copy

% Operations for istream

encode = proc(I: int, IST: istream) signals(not_possible(string))
	% modifies IST
	% effects  ...
	end encode

decode = proc(IST: istream) returns(int)
	 signals(end_of_file, not_possible(string))
	% modifies IST
	% effects  ...
	end decode

% Operation for pstream

print = proc(I: int, PST: pstream)
	% modifies PST
	% effects  ...
	end print

% Operation for gc_dump

_gcd = proc(I: int, TAB: gcd_tab) returns(int)
	% modifies TAB
	% effects  ...
	end _gcd

end int_


% Real

real_ = cluster is add, sub, mul, div, minus, power, abs, min, max, i2r, r2i,
	trunc, parse, unparse, exponent, mantissa, lt, le, ge, gt, equal,
	similar, copy, print, encode, decode, _gcd, _real_max, _real_min,
	_max_width, _exp_width, _unparse

% Operations

add = proc(R1, R2: real) returns(real) signals(overflow, underflow)
	% effects  ...
	end add

sub = proc(R1, R2: real) returns(real) signals(overflow, underflow)
	% effects  ...
	end sub

mul = proc(R1, R2: real) returns(real) signals(overflow, underflow)
	% effects  ...
	end mul

div = proc(R1, R2: real) returns(real)
      signals(zero_divide, overflow, underflow)
	% effects  ...
	end div

minus = proc(R: real) returns(real)
	% effects  ...
	end minus

power = proc(R1, R2: real) returns(real)
	signals(zero_divide, complex_result, overflow, underflow)
	% effects  ...
	end power

abs = proc(R: real) returns(real)
	% effects  ...
	end abs

min = proc(R1, R2: real) returns(real)
	% effects  ...
	end min

max = proc(R1, R2: real) returns(real)
	% effects  ...
	end max

i2r = proc(I: int) returns(real) signals(overflow)
	% effects  ...
	end i2r

r2i = proc(R: real) returns(int) signals(oveflow)
	% effects  ...
	end r2i

trunc = proc(R: real) returns(int) signals(overflow)
	% effects  ...
	end trunc

parse = proc(S: string) returns(real) signals(bad_format, overflow, underflow)
	% effects  ...
	end parse

unparse = proc(R: real) returns(string)
	% effects  ...
	end unparse

exponent = proc(R: real) returns(int) signals(undefined)
	% effects  ...
	end exponent

mantissa = proc(R: real) returns(real)
	% effects  ...
	end mantissa

lt = proc(R1, R2: real) returns(bool)
	% effects  ...
	end lt

le = proc(R1, R2: real) returns(bool)
	% effects  ...
	end le

ge = proc(R1, R2: real) returns(bool)
	% effects  ...
	end ge

gt = proc(R1, R2: real) returns(bool)
	% effects  ...
	end gt

equal = proc(R1, R2: real) returns(bool)
	% effects  ...
	end equal

similar = proc(R1, R2: real) returns(bool)
	% effects  ...
	end similar

copy = proc(R: real) returns(real)
	% effects  ...
	end copy

% Operations for istream

encode = proc(R: real, IST: istream) signals(not_possible(string))
	% modifies IST
	% effects  ...
	end encode

decode = proc(IST: istream) returns(real)
	 signals(end_of_file, not_possible(string))
	% modifies IST
	% effects  ...
	end decode

% Operation for pstream

print = proc(R: real, PST: pstream)
	% modifies PST
	% effects  ...
	end print

% Operation for gc_dump

_gcd = proc(R: real, TAB: gcd_tab) returns(int)
	% modifies TAB
	% effects  ...
	end _gcd

%

_real_max = proc() returns(real)
	% effects  Returns the maximum real object.
	end _real_max

_real_min = proc() returns(real)
	% effects  Returns the minimum real object.
	end _real_min

_max_width = proc() returns(int)
	% effects  Returns the maximum number of decimal digits in a mantissa
	%	   required to represent every real object accurately.
	end _max_width

_exp_width = proc() returns(int)
	% effects  Returns the maximum number of decimal digits in an exponent
	%	   required to represent an exponent of every real object.
	end _exp_width

_unparse = proc(R: real) returns(string, int)
	% effects  Returns "0" and 0 if R = 0.0; otherwise returns the mantissa
	%	   without decimal point and the exponent of R when represented
	%	   in standard form.
	end _unparse

end real_


% Char

char_ = cluster is i2c, c2i, lt, le, ge, gt, equal, similar, copy, print,
	encode, decode, _gcd, width

% Operations

i2c = proc(I: int) returns(char) signals(illegal_char)
	% effects  ...
	end i2c

c2i = proc(C: char) returns(int)
	% effects  ...
	end c2i

lt = proc(C1, C2: char) returns(bool)
	% effects  ...
	end lt

le = proc(C1, C2: char) returns(bool)
	% effects  ...
	end le

ge = proc(C1, C2: char) returns(bool)
	% effects  ...
	end ge

gt = proc(C1, C2: char) returns(bool)
	% effects  ...
	end gt

equal = proc(C1, C2: char) returns(bool)
	% effects  ...
	end equal

similar = proc(C1, C2: char) returns(bool)
	% effects  ...
	end similar

copy = proc(C: char) returns(char)
	% effects  ...
	end copy

% Operations for istream

encode = proc(C: char, IST: istream) signals(not_possible(string))
	% modifies IST
	% effects  ...
	end encode

decode = proc(IST: istream) returns(char)
	 signals(end_of_file, not_possible(string))
	% modifies IST
	% effects  ...
	end decode

% Operation for pstream

print = proc(C: char, PST: pstream)
	% modifies PST
	% effects  ...
	end print

% Operation for gc_dump

_gcd = proc(C: char, TAB: gcd_tab) returns(int)
	% modifies TAB
	% effects  ...
	end _gcd

width = proc(C: char) returns(int)
	% effects  ...
	end width

end char_


% String

string_ = cluster is size, indexs, indexc, c2s, concat, append, fetch, empty,
	  substr, rest, s2ac, ac2s, s2sc, sc2s, chars, lt, le, ge, gt, equal,
	  similar, copy, print, encode, decode, _gcd, width

% Operations

size = proc(S: string) returns(int)
	% effects  ...
	end size

indexs = proc(FIND, S: string) returns(int)
	% effects  ...
	end indexs

indexc = proc(FIND: char, S: string) returns(int)
	% effects  ...
	end indexc

c2s = proc(C: char) returns(string)
	% effects  ...
	end c2s

concat = proc(S1, S2: string) returns(string)
	% effects  ...
	end concat

append = proc(S: string, C: char) returns(string)
	% effects  ...
	end append

fetch = proc(S: string, INDEX: int) returns(char) signals(bounds)
	% effects  ...
	end fetch

empty = proc(S: string) returns(bool)
	% effects  ...
	end empty

substr = proc(S: string, START, LEN: int) returns(string)
	 signals(bounds, negative_size)
	% effects  ...
	end substr

rest = proc(S: string, START: int) returns(string) signals(bounds)
	% effects  ...
	end rest

s2ac = proc(S: string) returns(array[char])
	% effects  ...
	end s2ac

ac2s = proc(A: array[char]) returns(string)
	% effects  ...
	end ac2s

s2sc = proc(S: string) returns(sequence[char])
	% effects  ...
	end s2sc

sc2s = proc(Q: sequence[char]) returns(string)
	% effects  ...
	end sc2s

chars = iter(S: string) yields(char)
	% effects  ...
	end chars

lt = proc(S1, S2: string) returns(bool)
	% effects  ...
	end lt

le = proc(S1, S2: string) returns(bool)
	% effects  ...
	end le

ge = proc(S1, S2: string) returns(bool)
	% effects  ...
	end ge

gt = proc(S1, S2: string) returns(bool)
	% effects  ...
	end gt

equal = proc(S1, S2: string) returns(bool)
	% effects  ...
	end equal

similar = proc(S1, S2: string) returns(bool)
	% effects  ...
	end similar

copy = proc(S: string) returns(string)
	% effects  ...
	end copy

% Operations for istream

encode = proc(S: string, IST: istream) signals(not_possible(string))
	% modifies IST
	% effects  ...
	end encode

decode = proc(IST: istream) returns(string)
	signals(end_of_file, not_possible(string))
	% modifies IST
	% effects  ...
	end decode

% Operation for pstream

print = proc(S: string, PST: pstream)
	% modifies PST
	% effects  ...
	end print

% Operation for gc_dump

_gcd = proc(S: string, TAB: gcd_tab) returns(int)
	% modifies TAB
	% effects  ...
	end _gcd

% Operation for Japanized CLU

width = proc(S: string) returns(int)
	% effects  ...
	end width

end string_


% Array Types

array_ = cluster[T: type] is create, new, predict, cons, cons2, empty, low,
	 high, size, set_low, trim, fill, fill_copy, fetch, bottom, top, store,
	 addh, addl, remh, reml, elements, indexes, equal, similar, similar1,
	 copy, copy1, print, encode, decode, _gcd

% Operations

create = proc(LOW_BOUND: int) returns(array[T])
	% effects  ...
	end create

new = proc() returns(array[T])
	% effects  ...
	end new

predict = proc(LOW_BOUND, COUNT: int) returns(array[T])
	% effects  ...
	end predict

cons = proc(Q: sequence[T]) returns(array[T])
	% effects  ...
	end cons

cons2 = proc(LOW_BOUND: int, Q: sequence[T]) returns(array[T])
	% effects  ...
	end cons2

empty = proc(A: array[T]) returns(bool)
	% effects  ...
	end empty

low = proc(A: array[T]) returns(int)
	% effects  ...
	end low

high = proc(A: array[T]) returns(int)
	% effects  ...
	end high

size = proc(A: array[T]) returns(int)
	% effects  ...
	end size

set_low = proc(A: array[T], LOW_BOUND: int)
	% modifies A
	% effects  ...
	end set_low

trim = proc(A: array[T], LOW_BOUND, LENGTH: int) signals(bounds, negative_size)
	% modifies A
	% effects  ...
	end trim

fill = proc(LOW_BOUND, LENGTH: int, ELEMENT: T) returns(array[T])
       signals(negative_size)
	% effects  ...
	end fill

fill_copy = proc(LOW_BOUND, LENGTH: int, ELEMENT: T) returns(array[T])
	    signals(negative_size)
	    where T has copy: proctype(T) returns(T)
	% effects  ...
	end fill_copy

fetch = proc(A: array[T], INDEX: int) returns(T) signals(bounds)
	% effects  ...
	end fetch

bottom = proc(A: array[T]) returns(T) signals(bounds)
	% effects  ...
	end bottom

top = proc(A: array[T]) returns(T) signals(bounds)
	% effects  ...
	end top

store = proc(A: array[T], index: int, ELEMENT: T) signals(bounds)
	% modifies A
	% effects  ...
	end store

addh = proc(A: array[T], ELEMENT: T)
	% modifies A
	% effects  ...
	end addh

addl = proc(A: array[T], ELEMENT: T)
	% modifies A
	% effects  ...
	end addl

remh = proc(A: array[T]) returns(T) signals(bounds)
	% modifies A
	% effects  ...
	end remh

reml = proc(A: array[T]) returns(T) signals(bounds)
	% modifies A
	% effects  ...
	end reml

elements = iter(A: array[T]) yields(T)
	% effects  ...
	end elements

indexes = iter(A: array[T]) yields(int)
	% effects  ...
	end indexes

equal = proc(A1, A2: array[T]) returns(bool)
	% effects  ...
	end equal

similar = proc(A1, A2: array[T]) returns(bool)
	      where T has similar: proctype(T, T) returns(bool)
	% effects  ...
	end similar

similar1 = proc(A1, A2: array[T]) returns(bool)
	   where T has equal: proctype(T, T) returns(bool)
	% effects  ...
	end similar1

copy = proc(A: array[T]) returns(array[T])
       where T has copy: proctype(t) returns(T)
	% effects  ...
	end copy

copy1 = proc(A: array[T]) returns(array[T])
	% effects  ...
	end copy1

% Operations for istream

encode = proc(A: array[T], IST: istream) signals(not_possible(string))
	 where T has encode: proctype(T, istream) signals(not_possible(string))
	% modifies IST
	% effects  ...
	end encode

decode = proc(IST: istream) returns(array[T])
	 signals(end_of_file, not_possible(string))
	 where T has decode: proctype(istream) returns(T)
			     signals(end_of_file, not_possible(string))
	% modifies IST
	% effects  ...
	end decode

% Operation for pstream

print = proc(A: array[T], PST: pstream)
	where T has print: proctype(T, pstream)
	% modifies PST
	% effects  ...
	end print

% Operation for gc_dump

_gcd = proc(A: array[T], TAB: gcd_tab) returns(int)
       where T has _gcd: proctype(T, gcd_tab) returns(int)
	% modifies TAB
	% effects  ...
	end _gcd

end array_


% Sequence Types

sequence_ = cluster[T: type] is new, cons, e2s, size, subseq, fill, fill_copy,
	    fetch, bottom, top, replace, addh, addl, remh, reml, concat, a2s,
	    s2a, empty, elements, indexes, equal, similar, copy, print, encode,
 	    decode, _gcd

% Operations

new = proc() returns(sequence[T])
	% effects  ...
	end new

cons = proc(S: sequence[T]) returns(sequence[T])
	% effects  ...
	end cons

e2s = proc(ELEMENT: T) returns(sequence[T])
	% effects  ...
	end e2s

size = proc(S: sequence[T]) returns(int)
	% effects  ...
	end size

subseq = proc(S: sequence[T], START: int, LENGTH: int) returns(sequence[T])
	 signals(bounds, negative_size)
	% effects  ...
	end subseq

fill = proc(LENGTH: int, ELEMENT: T) returns(sequence[T])
       signals(negative_size)
	% effects  ...
	end fill

fill_copy = proc(LENGTH: int, ELEMENT: T) returns(sequence[T])
	    signals(negative_size)
	    where T has copy: proctype(T) returns(T)
	% effects  ...
	end fill_copy

fetch = proc(S: sequence[T], INDEX: int) returns(T) signals(bounds)
	% effects  ...
	end fetch

bottom = proc(S: sequence[T]) returns(T) signals(bounds)
	% effects  ...
	end bottom

top = proc(S: sequence[T]) returns(T) signals(bounds)
	% effects  ...
	end top

replace = proc(S: sequence[T], INDEX: int, ELEMENT: T) returns(sequence[T])
	  signals(bounds)
	% effects  ...
	end replace

addh = proc(S: sequence[T], ELEMENT: T) returns(sequence[T])
	% effects  ...
	end addh

addl = proc(S: sequence[T], ELEMENT: T) returns(sequence[T])
	% effects  ...
	end addl

remh = proc(S: sequence[T]) returns(sequence[T]) signals(bounds)
	% effects  ...
	end remh

reml = proc(S: sequence[T]) returns(sequence[T]) signals(bounds)
	% effects  ...
	end reml

concat = proc(S1, S2: sequence[T]) returns(sequence[T])
	% effects  ...
	end concat

a2s = proc(A: array[T]) returns(sequence[T])
	% effects  ...
	end a2s

s2a = proc(S: sequence[T]) returns(array[T])
	% effects  ...
	end s2a

empty = proc(S: sequence[T]) returns(bool)
	% effects  ...
	end empty

elements = iter(S: sequence[T]) yields(T)
	% effects  ...
	end elements

indexes = iter(S: sequence[T]) yields(int)
	% effects  ...
	end indexes

equal = proc(S1, S2: sequence[T]) returns(bool)
	where T has equal: proctype(T, T) returns(bool)
	% effects  ...
	end equal

similar = proc(S1, S2: sequence[T]) returns(bool)
	  where T has similar: proctype(T, T) returns(bool)
	% effects  ...
	end similar

copy = proc(S: sequence[T]) returns(sequence[T])
       where T has copy: proctype(T) returns(T)
	% effects  ...
	end copy

% Operations for istream

encode = proc(S: sequence[T], IST: istream) signals(not_possible(string))
	 where T has encode: proctype(T, istream) signals(not_possible(string))
	% modifies IST
	% effects  ...
	end encode

decode = proc(IST: istream) returns(sequence[T])
	 signals(end_of_file, not_possible(string))
	 where T has decode: proctype(istream) returns(T)
			     signals(end_of_file, not_possible(string))
	% modifies IST
	% effects  ...
	end decode

% Operation for pstream

print = proc(S: sequence[T], PST: pstream)
	where T has print: proctype(T, pstream)
	% modifies PST
	% effects  ...
	end print

% Operation for gc_dump

_gcd = proc(S: sequence[T], TAB: gcd_tab) returns(int)
       where T has _gcd: proctype(t, gcd_tab) returns(int)
	% modifies TAB
	% effects  ...
	end _gcd

end sequence_


% Record Types

#extend

record_ = selector[RT, TT: type] is get_, set_, r_gets_r, equal, similar,
	  similar1, copy, copy1, print, encode, decode, _gcd

% Operations

%create = proc(Q: sequence[...]) returns(RT)
%	% effects  ...
%	end create

get_ = proc[T: type](R: RT) returns(T)
	% effects  ...
	end get_

set_ = proc[T: type](R: RT, COMPONENT: T)
	% modifies R
	% effects  ...
	end set_

r_gets_r = proc(R1, R2: RT)
	% modifies R1
	% effects  ...
	end r_gets_r

%r_gets_s = proc(R: RT, S: struct[...])
%	% modifies R
%	% effects  ...
%	end r_gets_s

equal = proc(R1, R2: RT) returns(bool)
	% effects  ...
	end equal

similar = proc(R1, R2: RT) returns(bool)
	  where TT has similar: proctype(TT, TT) returns(bool)
	% effects  ...
	end similar

similar1 = proc(R1, R2: RT) returns(bool)
	   where TT has equal: proctype(TT, TT) returns(bool)
	% effects  ...
	end similar1

copy = proc(R: RT) returns(RT)
       where TT has copy: proctype(TT) returns(TT)
	% effects  ...
	end copy

copy1 = proc(R: RT) returns(RT)
	% effects  ...
	end copy1

% Operations for istream

encode = proc(R: RT, IST: istream) signals(not_possible(string))
	 where TT has encode: proctype(TT, istream)
			      signals(not_possible(string))
	% modifies IST
	% effects  ...
	end encode

decode = proc(IST: istream) returns(RT)
	 signals(end_of_file, not_possible(string))
	 where TT has decode: proctype(istream) returns(TT)
			      signals(end_of_file, not_possible(string))
	% modifies IST
	% effects  ...
	end decode

% Operation for pstream

print = proc(R: RT, PST: pstream)
	where TT has print: proctype(TT, pstream)
	% modifies PST
	% effects  ...
	end print

% Operation for gc_dump

_gcd = proc(R: RT, TAB: gcd_tab) returns(int)
       where TT has _gcd: proctype(TT, gcd_tab) returns(int)
	% modifies TAB
	% effects  ...
	end _gcd

end record_


% Structure Types

struct_ = selector[ST, TT: type] is create, get_, replace_, equal, similar,
	  copy, print, encode, decode, _gcd

% Operations

create = proc(S: ST) returns(ST)
	% effects  ...
	end create

get_ = proc[T: type](S: ST) returns(T)
	% effects  ...
	end get_

replace_ = proc[T: type](S: ST, COMPONENT: T) returns(ST)
	% effects  ...
	end replace_

%s2r = proc(S: ST) returns(record[...])
%	% effects  ...
%	end s2r

%r2s = proc(R: record[...]) returns(ST)
%	% effects  ...
%	end r2s

equal = proc(S1, S2: ST) returns(bool)
	where TT has equal: proctype(TT, TT) returns(bool)
	% effects  ...
	end equal

similar = proc(S1, S2: ST) returns(bool)
	  where TT has similar: proctype(TT, TT) returns(bool)
	% effects  ...
	end similar

copy = proc(S: ST) returns(ST)
       where TT has copy: proctype(TT) returns(TT)
	% effects  ...
	end copy

% Operations for istream

encode = proc(S: ST, IST: istream) signals(not_possible(string))
	 where TT has encode: proctype(TT, istream)
			      signals(not_possible(string))
	% modifies IST
	% effects  ...
	end encode

decode = proc(IST: istream) returns(ST)
	 signals(end_of_file, not_possible(string))
	 where TT has decode: proctype(istream) returns(TT)
			      signals(end_of_file, not_possible(string))
	% modifies IST
	% effects  ...
	end decode

% Operation for pstream

print = proc(S: ST, PST: pstream)
	where TT has print: proctype(TT, pstream)
	% modifies PST
	% effects  ...
	end print

% Operation for gc_dump

_gcd = proc(S: ST, TAB: gcd_tab) returns(int)
       where TT has _gcd: proctype(TT, gcd_tab) returns(int)
	% modifies TAB
	% effects  ...
	end _gcd

end struct_


% Oneof Types

oneof_ = selector[OT, TT: type] is make_, is_, value_, equal, similar, copy,
	 print, encode, decode, _gcd

% Operations

make_ = proc[T: type](VALUE: T) returns(OT)
	% effects  ...
	end make_

is_ = proc[T: type](O: OT) returns(bool)
	% effects  ...
	end is_

value_ = proc[T: type](O: OT) returns(T) signals(wrong_tag)
	% effects  ...
	end value_

%o2v = proc(O: OT) returns(variant[...])
%	% effects  ...
%	end o2v

%v2o = proc(V: variant[...]) returns(OT)
%	% effects  ...
%	end v2o

equal = proc(O1, O2: OT) returns(bool)
	where TT has equal: proctype(TT, TT) returns(bool) 
	% effects  ...
	end equal

similar = proc(O1, O2: OT) returns(bool)
	  where TT has similar: proctype(TT, TT) returns(bool)
	% effects  ...
	end similar

copy = proc(O: OT) returns(OT)
       where TT has copy: proctype(TT) returns(TT)
	% effects  ...
	end copy

% Operations for istream

encode = proc(O: OT, IST: istream) signals(not_possible(string))
	 where TT has encode: proctype(TT, istream)
			      signals(not_possible(string))
	% modifies IST
	% effects  ...
	end encode

decode = proc(IST: istream) returns(OT)
	 signals(end_of_file, not_possible(string))
	 where TT has decode: proctype(istream) returns(TT)
			      signals(end_of_file, not_possible(string))
	% modifies IST
	% effects  ...
	end decode

% Operation for pstream

print = proc(O: OT, PST: pstream)
	where TT has print: proctype(TT, pstream)
	% modifies PST
	% effects  ...
	end print

% Operation for gc_dump

_gcd = proc(O: OT, TAB: gcd_tab) returns(int)
       where TT has _gcd: proctype(TT, gcd_tab) returns(int)
	% modifies TAB
	% effects  ...
	end _gcd

end oneof_


% Variant Types

variant_ = selector[VT, TT: type] is make_, change_, is_, value_, v_gets_v,
	   equal, similar, similar1, copy, copy1, print, encode, decode, _gcd

% Operations

make_ = proc[T: type](VALUE: T) returns(VT)
	% effects  ...
	end make_

change_ = proc[T: type](V: VT, VALUE: T)
	% modifies V
	% effects  ...
	end change_

is_ = proc[T: type](V: VT) returns(bool)
	% effects  ...
	end is_

value_ = proc[T: type](V: VT) returns(T) signals(wrong_tag)
	% effects  ...
	end value_

v_gets_v = proc(V1, V2: VT)
	% modifies V1
	% effects  ...
	end v_gets_v

%v_gets_o = proc(V: VT, O: oneof[...])
%	% modifies V
%	% effects  ...
%	end v_gets_o

equal = proc(V1, V2: VT) returns(bool)
	% effects  ...
	end equal

similar = proc(V1, V2: VT) returns(bool)
	  where TT has similar: proctype(TT, TT) returns(bool)
	% effects  ...
	end similar

similar1 = proc(V1, V2: VT) returns(bool)
	   where TT has equal: proctype(TT, TT) returns(bool)
	% effects  ...
	end similar1

copy = proc(V: VT) returns(VT)
       where TT has copy: proctype(TT) returns(TT)
	% effects  ...
	end copy

copy1 = proc(V: VT) returns(VT)
	% effects  ...
	end copy1

% Operations for istream

encode = proc(V: VT, IST: istream) signals(not_possible(string))
	 where TT has encode: proctype(TT, istream)
			      signals(not_possible(string))
	% modifies IST
	% effects  ...
	end encode

decode = proc(IST: istream) returns(VT)
	 signals(end_of_file, not_possible(string))
	 where TT has decode: proctype(istream) returns(TT)
			      signals(end_of_file, not_possible(string))
	% modifies IST
	% effects  ...
	end decode

% Operation for pstream

print = proc(V: VT, PST: pstream)
	where TT has print: proctype(TT, pstream)
	% modifies PST
	% effects  ...
	end print

% Operation for gc_dump

_gcd = proc(V: VT, TAB: gcd_tab) returns(int)
       where TT has _gcd: proctype(TT, gcd_tab) returns(int)
	% modifies TAB
	% effects  ...
	end _gcd

end variant_


% Procedure and Iterator Types

proctype_ = applytype[PT: type] is equal, similar, copy

% Operations

equal = proc(P1, P2: PT) returns(bool)
	% effects  ...
	end equal

similar = proc(P1, P2: PT) returns(bool)
	% effects  ...
	end similar

copy = proc(P: PT) returns(PT)
	% effects  ...
	end copy

end proctype_


itertype_ = applytype[IT: type] is equal, similar, copy

% Operations

equal = proc(I1, I2: IT) returns(bool)
	% effects  ...
	end equal

similar = proc(I1, I2: IT) returns(bool)
	% effects  ...
	end similar

copy = proc(I: IT) returns(IT)
	% effects  ...
	end copy

end itertype_


% Type

type_ = cluster is equal, similar, copy

% Operations

equal = proc(T1, T2: type) returns(bool)
	% effects  ...
	end equal

similar = proc(T1, T2: type) returns(bool)
	% effects  ...
	end similar

copy = proc(T: type) returns(type)
	% effects  ...
	end copy

end type_
