#!/usr/bin/expect -f
set p1 [lindex $argv 0];
set p2 [lindex $argv 1];
set p3 [lindex $argv 2];
set p4 [lindex $argv 3];
set p5 [lindex $argv 4];
spawn $p1 $p2 $p3 $p4
expect "Password:"
send $p5\n
interact
