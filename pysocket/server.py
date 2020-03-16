#!/usr/bin/env python3

#https://realpython.com/python-sockets
#https://github.com/realpython/materials/tree/master/python-sockets-tutorial
# Chat server
import socket

messages = []
HOST ='127.0.0.1'#IP or Name
PORT =2000 #1-65535 if port <1024 superuser require in some system
#AF_INET: IPV4 (HOST,PORT) , TCP: SOCK_STREAM
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    #BIND
    s.bind((HOST, PORT))
    #LISTEN
    s.listen()
    print('-- SERVER IS ONLINE --')

    while True:
        #ACCEPT
        conn, addr = s.accept()
        with conn:
            #print('Connection from', addr)
            
            while True:
                #RECEIVE Buffer size =1024
                data = conn.recv(1024).decode('utf8') 
                if data:
                    if data.startswith('send'):
                        messages.append(f'{addr[0]}: {data[4:]}')
                        print(data[4:])
                        m=data[4:8]
                        if m == 'exit': 
                              exit(0)
                    elif data.startswith('get'):
                        #SEND
                        conn.sendall('\n'.join(messages[-10:]).encode('utf8'))
                    break
     #CLOSE
     #No need to call s.close() uses "pass"
                    
