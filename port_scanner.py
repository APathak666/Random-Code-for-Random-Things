#!/usr/bin/python3

import socket
import sys
from datetime import datetime

target = input(str('Target IP: '))

print('_' * 50)
print('Scanning target: ' + target)
print('Scan start time: ' + str(datetime.now()))
print('_' * 50)
print()
try:

    for port in range(1, 65535):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        socket.setdefaulttimeout(0.5)

        result = s.connect_ex((target, port))
        if result == 0:
            print('[*] Port {} is open'.format(port))

        # print(port)
        s.close()

except KeyboardInterrupt:
    print('Exiting')
    sys.exit()

except socket.error:
    print('Host not responding...')
    sys.exit()

print('_' * 50)
print('Scan completed')
print('_' * 50)
