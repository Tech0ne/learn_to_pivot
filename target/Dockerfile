FROM ubuntu:22.04

RUN apt-get update
RUN apt-get -y install sudo vim openssh-server vsftpd

RUN mkdir /var/run/sshd

RUN useradd -rm -d /home/john -s /bin/bash -u 1000 john

RUN echo 'john:U_W0nt_F1nd_Th1s_On3_Eith3r' | chpasswd
COPY vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY vsftpd.conf /etc/vsftpd.conf
RUN chmod 644 /etc/vsftpd.conf
COPY ./run_me.sh /opt/run_me.sh

RUN chmod +x /opt/run_me.sh

RUN service vsftpd start

EXPOSE 21 22

CMD [ "/opt/run_me.sh" ]
