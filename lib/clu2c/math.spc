% math.spc - interface specifications of mathematical functions
%
% $Id: math.spc,v 2.0 1996/06/10 09:02:02 ushijima Exp $


% In the following descriptions, `PI' denotes the ratio of the
% circumference of a circle to its diameter.
%
% The `overflow' exception occurs if the magnitude of the result is greater
% than Real_Max, unless otherwise specified.
%
% The underflow exception occurs if the magnitude of the result is less than
% Real_Min, unless otherwise specified.


acos = proc(R: real) returns(real) signals(undefined, underflow)
	% effects  Signals `undefined' if R is less than -1 or greater than 1;
	%	   otherwise returns the arc cosine of R in the range [0, PI]
	%	   radians.
	end acos


asin = proc(R: real) returns(real) signals(undefined, underflow)
	% effects  Signals `undefined' if R is less than -1 or greater than 1;
	%	   otherwise returns the arc sine of R in the range
	%	   [-PI/2, +PI/2] radians.
	end asin


atan = proc(R: real) returns(real) signals(underflow)
	% effects  Returns the arc tangent of R in the range [-PI/2, +PI/2]
	%	   radians.
	end atan


atan2 = proc(Y, X: real) returns(real) signals(undefined, underflow)
	% effects  Signals `undefined' if both X and Y are zero; otherwise
	%	   returns the arc tangent of Y/X in the range [-PI, +PI]
	%	   radians.
	end atan2


cos = proc(R: real) returns(real) signals(underflow)
	% effects  Returns the cosine of R (measured in radians).
	end cos


sin = proc(R: real) returns(real) signals(underflow)
	% effects  Returns the sine of R (measured in radians).
	end sin


tan = proc(R: real) returns(real) signals(overflow, underflow)
	% effects  Returns the tangent of R (measured in radians).
	end tan


cosh = proc(R: real) returns(real) signals(onverflow, underflow)
	% effects  Returns the hyperbolic cosine of R.
	end cosh


sinh = proc(R: real) returns(real) signals(overflow, underflow)
	% effects  Returns the hyperbolic sine of R.
	end sinh


tanh = proc(R: real) returns(real) signals(underflow)
	% effects  Returns the hyperbolic tangent of R.
	end tanh


exp = proc(R: real) returns(real) signals(overflow, underflow)
	% effects  Returns the exponential function of R.
	end exp


log = proc(R: real) returns(real)
      signals(complex_result, undefined, overflow, underflow)
	% effects  Signals `complex_result' if R is negative; signals
	%	   `undefined' if R is zero; otherwise returns the natural
	%	   logarithm of R.
	end log


log10 = proc(R: real) returns(real)
	signals(complex_result, undefined, overflow, underflow)
	% effects  Signals `complex_result' if R is negative; signals
	%	   `undefined' if R is zero; otherwise returns the base-ten
	%	   logarithm of R.
	end log10


sqrt = proc(R: real) returns(real) signals(complex_result, overflow, underflow)
	% effects  Signals `complex_result' if R is negative; otherwise returns
	%	   the square root of R.
	end sqrt
