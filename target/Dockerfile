FROM ubuntu:22.04

RUN apt-get update
RUN apt-get -y install sudo vim openssh-server vsftpd python3 gcc

COPY ./server.py /root/server.py

RUN echo "You found the target file. Your POC : I_W1ll_N3ver_F0rget_Th4t_R00m_U_B17ch" > /passwd

COPY ./suid.c /opt/suid.c

RUN gcc -o /opt/some_random_file /opt/suid.c

RUN rm /opt/suid.c

RUN chmod +s /opt/some_random_file

RUN chmod 400 /passwd

RUN mkdir /var/run/sshd

RUN useradd -rm -d /home/john -s /bin/bash -u 1000 john

RUN echo 'john:pucciwrecker' | chpasswd

COPY ./run_me.sh /opt/run_me.sh

RUN chmod +x /opt/run_me.sh

EXPOSE 22 8654

CMD [ "/opt/run_me.sh" ]
