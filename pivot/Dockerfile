FROM httpd:2.4.55

WORKDIR /var/www/http/

COPY ./apache.conf /usr/local/apache2/conf/httpd.conf

RUN apt-get update

RUN apt-get install -y openssh-server sudo vim

RUN mkdir /var/run/sshd

RUN useradd -rm -d /home/mike/ -s /bin/bash -u 1000 mike

RUN echo "mike:U_W0nt_F1nd_Th1s_On3" | chpasswd

RUN chmod +s /usr/bin/env

RUN sudo -u mike mkdir /home/mike/.ssh/

RUN sudo -u mike ssh-keygen -f /home/mike/.ssh/id_rsa -N "mikey1"

RUN sudo -u mike cp /home/mike/.ssh/id_rsa.pub /home/mike/.ssh/authorized_keys

RUN mkdir /root/.ssh/

RUN ssh-keygen -f /root/.ssh/id_rsa -N ""

RUN cp /root/.ssh/id_rsa.pub /root/.ssh/authorized_keys

RUN sudo -u mike echo "alias l='ls -a'" >> /home/mike/.bashrc

RUN sudo -u mike echo "alias ll='ls -la'" >> /home/mike/.bashrc

COPY index.html /var/www/http/index.html

COPY message.html /var/www/http/message.html

RUN mkdir /var/www/http/rsa/

RUN cp /home/mike/.ssh/id_rsa /var/www/http/rsa/id_rsa

RUN chown -R www-data:www-data /var/www/http/

COPY sshd.conf /etc/ssh/sshd_config

EXPOSE 22

EXPOSE 80

COPY ./start.sh /opt/start.sh

RUN chmod +x /opt/start.sh

CMD [ "/opt/start.sh" ]