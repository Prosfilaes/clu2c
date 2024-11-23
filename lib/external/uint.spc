% $Id: uint.spc,v 1.1 1997/01/31 12:21:15 ushijima Exp $

uint = cluster is create, to_int, add, sub, mul, div, mod, max, min, lt, le,
       ge, gt, and, or, xor, not, shift, parse, hex_parse, oct_parse, unparse,
       hex_unparse, oct_unparse, equal, similar, copy, encode, decode, print

create = proc(i: int) returns(uint) signals(negative_argument)
	end create

to_int = proc(u: uint) returns(int) signals(overflow)
	end to_int

add = proc(u1, u2: uint) returns(uint)
	end add

sub = proc(u1, u2: uint) returns(uint)
	end sub

mul = proc(u1, u2: uint) returns(uint)
	end mul

div = proc(u1, u2: uint) returns(uint) signals(zero_divide)
	end div

mod = proc(u1, u2: uint) returns(uint) signals(zero_divide)
	end mod

max = proc(u1, u2: uint) returns(uint)
	end max

min = proc(u1, u2: uint) returns(uint)
	end min

lt = proc(u1, u2: uint) returns(bool)
	end lt

le = proc(u1, u2: uint) returns(bool)
	end le

ge = proc(u1, u2: uint) returns(bool)
	end ge

gt = proc(u1, u2: uint) returns(bool)
	end gt

and = proc(u1, u2: uint) returns(uint)
	end and

or = proc(u1, u2: uint) returns(uint)
	end or

xor = proc(u1, u2: uint) returns(uint)
	end xor

not = proc(u: uint) returns(uint)
	end not

shift = proc(u: uint, count: int) returns(uint)
	end shift

parse = proc(s: string) returns(uint) signals(bad_format)
	end parse

hex_parse = proc(s: string) returns(uint) signals(bad_format)
	end hex_parse

oct_parse = proc(s: string) returns(uint) signals(bad_format)
	end oct_parse

unparse = proc(u: uint) returns(string)
	end unparse

hex_unparse = proc(u: uint) returns(string)
	end hex_unparse

oct_unparse = proc(u: uint) returns(string)
	end oct_unparse

equal = proc(u1, u2: uint) returns(bool)
	end equal

similar = proc(u1, u2: uint) returns(bool)
	end similar

copy = proc(u: uint) returns(uint)
	end copy

encode = proc(u: uint, output: istream) signals(not_possible(string))
	end encode

decode = proc(input: istream) returns(uint) signals(not_possible(string))
	end decode

print = proc(u: uint, output: pstream)
	end print

end uint
