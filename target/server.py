from socket import socket

while 1:
    s = socket()
    s.bind(("0.0.0.0", 8654))
    s.listen(5)
    try:
        while 1:
            c, _ = s.accept()
            try:
                c.send(b"John's password : 038bf0aded4a35c2169231e0612b39e8697041a6733202b55456a2994e4c9986\n")
                c.close()
            except:
                pass
    except:
        s.close()
