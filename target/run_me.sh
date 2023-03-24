#!/bin/bash

python3 /root/server.py &
/usr/sbin/sshd -D
