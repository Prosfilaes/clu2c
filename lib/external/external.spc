% external.spc
%
% Copyright (c) 1996
%	Department of Mathematical and Computing Sciences,
%	Tokyo Institute of Technology.  All rights reserved.
%
% Permission to use, copy, and distribute this file is hereby granted,
% provided that the above copyright notice and this permission notice
% are preserved on all copies.
%
% $Id: external.spc,v 2.2 1997/01/31 12:54:48 ushijima Exp $


_external_argc = proc() returns(int)
	% effects  Returns the size of the argument vector associated with the
	%	   currently executing process.
	end _external_argc


_external_argv = proc(I: int) returns(string) signals(bounds)
	% effects  Signals `bounds' if I < 0 or I >= ARGC, where ARGC is the
	%	   result returned by the _external_argc procedure; otherwise
	%	   returns the element at the position I in the argument vector
	%	   associated with the currently executing process.
	end _external_argv


_external_chdir = proc(PATH: string) signals(not_possible(string))
	% effects  Invokes the `chdir' system call with PATH.  Signals
	%	   `not_possible' if and only if the call returns -1.
	end _external_chdir


_external_chmod = proc(PATH: string, MODE: int) signals(not_possible(string))
	% effects  Invokes the `chmod' system call with PATH.  Signals
	%	   `not_possible' if and only if the call returns -1.
	end _external_chmod


_external_clock = proc() returns(_external_clock_t)
		  signals(not_possible(string))
	% effects  Invokes the `clock' library function.  Signals
	%	   `not_possible' if and only if the function returns -1.  If
	%	   the system does not provide the `clock' function, some
	%	   substitute of it such as `getrusage' may be invoked.
 	end _external_clock


_external_clock_t = cluster is get_sec, get_msec, get_usec

% Overview

% An object of the `_external_clock_t' type provides an interface to the
% `clock_t' type in the standard C library that represents processor time.
% Each `_external_clock_t' object consists of three integer components:
%	`sec'	seconds	     0 ..
%	`msec'	milliseconds 0 .. 999
%	`usec'	microseconds 0 .. 999

% Operations

get_sec = proc(T: _external_clock_t) returns(int)
	% effects  Returns the `sec' component of T.
	end get_sec

get_msec = proc(T: _external_clock_t) returns(int)
	% effects  Returns the `msec' component of T.
	end get_msec

get_usec = proc(T: _external_clock_t) returns(int)
	% effects  Returns the `usec' component of T.
	end get_usec

end _external_clock_t


_external_dir = cluster is open, read, close

% Overview

% `_external_dir' provies the means to read directory entries.

% Operations

open = proc(DIR: string) returns(_external_dir) signals(not_possible(string))
	% effects  Signals `not_possible' if DIR is not a readable directory;
	%	   otherwise returns a input stream associated with the
	%	   directory named DIR.
	end open

read = proc(DST: _external_dir) returns(string) signals(end_of_file)
	% effects  Signals `end_of_file' if DST has no entry; otherwise removes
	%	   the next entry and returns its name.
	end read

close = proc(DST: _external_dir)
	% effects  Removes the association between DST and the associated
	%	   directory.
	end close

end _external_dir


_external_errname = proc() returns(string)
	% effects  Returns the error name (such as "ENOENT") that
	%	   corresponds to the current error number.
	end _external_errname


_external_errno = proc() returns(int)
	% effects  Returns the current error number.
	end _external_errno


_external_exit = proc(STATUS: int)
	% effects  Invokes the `exit' library function with STATUS.
	end _external_exit


_external_getcwd = proc() returns(string) signals(not_possible(string))
	% effects  Invokes the `getcwd' library function.  Signals
	%	   `not_possible' if the function returns a null pointer;
	%	   otherwise returns the resulting string.  If the system does
	%	   not provide the `getcwd' function, some substitute for it
	%	   such as `getwd' may be invoked.
	end _external_getcwd


_external_getdcwd = proc(DRIVE: int) returns(string)
		    signals(not_possible(string))
	% effects  Tries to return the current working directory for the
	%	   specified drive.  If DRIVE is zero, the current drive is
	%	   The current drive is specified if DRIVE is zero; the `A'
	%	   drive is specified if DRIVE is 1; `B' for 2, and so on.
	%	   Signals `not_possible' if any failure is encountered.
	end _external_getdcwd


_external_getenv = proc(NAME: string) returns(string) signals(not_found)
	% effects  Invokes the `getenv' library function with NAME.  Signals
	%	   `not_found' if the function returns null pointer; otherwise
	%	   returns the resulting string.
	end _external_getenv


_external_getpwnam = proc(USER: string) returns(_external_struct_passwd)
		     signals(not_found)
	% effects  Invokes the `getpwnam' library function with USER.  Signals
	%	   `not_found' if the function returns a null pointer;
	%	   otherwise returns the `passwd' structure.
	end _external_getpwnam


_external_gettime = proc() returns(int, int, int, int, int, int)
		    signals(not_possible(string))
	% effects  Returns the current date and time.  The results are year,
	%	   month, day, hour, minute, second, in this order.
	end _external_gettime


_external_localtime = proc(CLOCK: int) returns(_external_struct_tm)
	% effects  Invokes the `localtime' library function and returns the
	%	   resulting `tm' structure.
	end _external_localtime


_external_rename = proc(FROM, TO: string) signals(not_possible(string))
	% effects  Invokes the `rename' system call with FROM and TO.  Signals
	%	   `not_possible' if and only if the call returns -1.
	end _external_rename


_external_stat = proc(PATH: string) returns(_external_struct_stat)
		 signals(not_possible(string))
	% effects  Invokes the `stat' system call with PATH.  Returns the
	%	   resulting `stat' structure on success; otherwise signals
	%	   `not_possible'.
	end _external_stat


_external_struct_passwd = cluster is get_name, get_passwd, get_uid, get_gid,
			  get_gecos, get_dir, get_shell, equal, similar, copy

% Overview

% `_external_struct_passwd' provides the means to access the `passwd'
% structure, typically defined in the <pwd.h> header.  An object of this type
% is created by the `_external_getpwnam' procedure.

% Operations

get_name = proc(PW: _external_struct_passwd) returns(string)
	% effects  Returns the `pw_name' member of PW.
	end get_name

get_passwd = proc(PW: _external_struct_passwd) returns(string)
	% effects  Returns the `pw_passwd' member of PW.
	end get_passwd

get_uid = proc(PW: _external_struct_passwd) returns(int)
	% effects  Returns the `pw_uid' member of PW.
	end get_uid

get_gid = proc(PW: _external_struct_passwd) returns(int)
	% effects  Returns the `pw_gid' member of PW.
	end get_gid

get_gecos = proc(PW: _external_struct_passwd) returns(string)
	% effects  Returns the `pw_gecos' member of PW.
	end get_gecos

get_dir = proc(PW: _external_struct_passwd) returns(string)
	% effects  Returns the `pw_dir' member of PW.
	end get_dir

get_shell = proc(PW: _external_struct_passwd) returns(string)
	% effects  Returns the `pw_shell' member of PW.
	end get_shell

equal = proc(PW1, PW2: _external_struct_passwd) returns(string)
	% effects  Returns `true' if PW1 and PW2 have the same value; otherwise
	%	   returns `false'.
	end equal

similar = proc(PW1, PW2: _external_struct_passwd) returns(string)
	% effects  Equivalent to the `equal' operation.
	end similar

copy = proc(PW: _external_struct_passwd) returns(_external_struct_passwd)
	% effects  Returns a new object that have the same value as PW.
	end copy

end _external_struct_passwd


_external_struct_stat = cluster is get_dev, get_ino, get_mode, get_nlink,
			get_uid, get_gid, get_rdev, get_size, get_atime,
			get_mtime, get_ctime, is_block_device,
			is_character_device, is_directory, is_fifo, is_regular,
			is_symbolic_link, equal, similar, copy

% Overview

% `_external_struct_stat' provides the means to access the `stat' structure,
% typically defined in the <sys/stat.h> header.  An object of this type is
% created by the `_external_stat' procedure.

% Operations

get_dev = proc(S: _external_struct_stat) returns(int)
	% effects  Returns the `st_dev' member of S.
	end get_dev

get_ino = proc(S: _external_struct_stat) returns(int)
	% effects  Returns the `st_ino' member of S.
	end get_ino

get_mode = proc(S: _external_struct_stat) returns(int)
	% effects  Returns the `st_mode' member of S.
	end get_mode

get_nlink = proc(S: _external_struct_stat) returns(int)
	% effects  Returns the `st_nlink' member of S.
	end get_nlink

get_uid = proc(S: _external_struct_stat) returns(int)
	% effects  Returns the `st_uid' member of S.
	end get_uid

get_gid = proc(S: _external_struct_stat) returns(int)
	% effects  Returns the `st_gid' member of S.
	end get_gid

get_rdev = proc(S: _external_struct_stat) returns(int)
	% effects  Returns the `st_rdev' member of S.
	end get_rdev

get_size = proc(S: _external_struct_stat) returns(int)
	% effects  Returns the `st_size' member of S.
	end get_size

get_atime = proc(S: _external_struct_stat) returns(int)
	% effects  Returns the `st_atime' member of S.
	end get_atime

get_mtime = proc(S: _external_struct_stat) returns(int)
	% effects  Returns the `st_mtime' member of S.
	end get_mtime

get_ctime = proc(S: _external_struct_stat) returns(int)
	% effects  Returns the `st_ctime' member of S.
	end get_ctime

is_block_device = proc(S: _external_struct_stat) returns(bool)
	% effects  Returns `true' if the `st_mode' member of S indicates that
	%	   the corresponding file is a block device; otherwise returns
	%	   `false'.
	end is_block_device

is_character_device = proc(S: _external_struct_stat) returns(bool)
	% effects  Returns `true' if the `st_mode' member of S indicates that
	%	   the corresponding file is a character device; otherwise
	%	   returns `false'.
	end is_character_device

is_directory = proc(S: _external_struct_stat) returns(bool)
	% effects  Returns `true' if the `st_mode' member of S indicates that
	%	   the corresponding file is a directory; otherwise returns
	%	   `false'.
	end is_directory

is_fifo = proc(S: _external_struct_stat) returns(bool)
	% effects  Returns `true' if the `st_mode' member of S indicates that
	%	   the corresponding file is a FIFO (named pipe); otherwise
	%	   returns `false'.
	end is_fifo

is_regular = proc(S: _external_struct_stat) returns(bool)
	% effects  Returns `true' if the `st_mode' member of S indicates that
	%	   the corresponding file is a regular file; otherwise returns
	%	   `false'.
	end is_regular

is_symbolic_link = proc(S: _external_struct_stat) returns(bool)
	% effects  Returns `true' if the `st_mode' member of S indicates that
	%	   the corresponding file is a symbolic link; otherwise returns
	%	   `false'.
	end is_symbolic_link

equal = proc(S1, S2: _external_struct_stat) returns(bool)
	% effects  Returns `true' if S1 and S2 have the same value; otherwise
	%	   returns `false'.
	end equal

similar = proc(S1, S2: _external_struct_stat) returns(bool)
	% effects  Equivalent to the `equal' operation.
	end similar

copy = proc(S: _external_struct_stat) returns(_external_struct_stat)
	% effects  Returns a new object that have the same value as S.
	end copy

end _external_struct_stat


_external_struct_tm = cluster is get_sec, get_min, get_hour, get_mday, get_mon,
				 get_year, get_wday, get_yday, get_isdst,
				 equal, similar, copy
% Overview

% An object of the `_external_struct_tm' provides an interface to the
% `struct tm' type in the standard C library.

% Operations

get_sec = proc(TIME: _external_struct_tm) returns(int)
	% effects  Returns the `tm_sec' member of TIME.
	end get_sec

get_min = proc(TIME: _external_struct_tm) returns(int)
	% effects  Returns the `tm_min' member of TIME.
	end get_min

get_hour = proc(TIME: _external_struct_tm) returns(int)
	% effects  Returns the `tm_hour' member of TIME.
	end get_hour

get_mday = proc(TIME: _external_struct_tm) returns(int)
	% effects  Returns the `tm_mday' member of TIME.
	end get_mday

get_mon = proc(TIME: _external_struct_tm) returns(int)
	% effects  Returns the `tm_mon' member of TIME.
	end get_mon

get_year = proc(TIME: _external_struct_tm) returns(int)
	% effects  Returns the `tm_year' member of TIME.
	end get_year

get_wday = proc(TIME: _external_struct_tm) returns(int)
	% effects  Returns the `tm_wday' member of TIME.
	end get_wday

get_yday = proc(TIME: _external_struct_tm) returns(int)
	% effects  Returns the `tm_yday' member of TIME.
	end get_yday

get_isdst = proc(TIME: _external_struct_tm) returns(bool)
	% effects  Returns the `tm_isdst' member of TIME.
	end get_isdst

equal = proc(TIME1, TIME2: _external_struct_tm) returns(bool)
	% effects  Returns `true' if TIME1 and TIME2 have the same value;
	%	   otherwise returns `false'.
	end equal

similar = proc(TIME1, TIME2: _external_struct_tm) returns(bool)
	% effects  Equivalent to the `equal' operation.
	end similar

copy = proc(TIME: _external_struct_tm) returns(_external_struct_tm)
	% effects  Returns a new object that has the same value as TIME.
	end copy

end _external_struct_tm


_external_suspend = proc()
	% effects  Temporarily suspends the currently executing process, or
	%	   spawns a new command interpreter.
	end _external_suspend


_external_system = proc(COMMAND: string) returns(int)
	% effects  Invokes the `system' library function with COMMAND and
	%	   returns the result of the function.
	end _external_system


_external_unlink = proc(PATH: string) signals(not_possible(string))
	% effects  Invokes the `unlink' system call with PATH.  Signals
	%	   `not_possible' if and only if the call returns -1.
	end _external_unlink
