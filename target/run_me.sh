#!/bin/bash

/usr/sbin/vsftpd -obackground=NO &
/usr/sbin/sshd -D
