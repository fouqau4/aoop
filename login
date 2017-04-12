#!/usr/bin/expect
spawn ssh b023040001aoop2017s@hw.oslab.cse.nsysu.edu.tw
expect "Password:"
send "9Vu26r\n"
interact
