import sys
import signal
import BaseHTTPServer
import SimpleHTTPServer
from SimpleHTTPServer import SimpleHTTPRequestHandler
import cgi
import RPi.GPIO as GPIO

class MyServer(SimpleHTTPRequestHandler):
	def __init__(self,req,client_addr,server):
		GPIO.setmode(GPIO.BOARD)
		GPIO.setup(22, GPIO.OUT)	
		SimpleHTTPRequestHandler.__init__(self,req,client_addr,server)

	def do_GET(self):
		SimpleHTTPServer.SimpleHTTPRequestHandler.do_GET(self)

        def do_POST(self):
		action = self.rfile.read(int(self.headers.get('content-length')))
		value = action.split("=")
		if len(value) > 0:
			state = GPIO.input(22)
			if value[1] == 'liga':
				if state == GPIO.HIGH:
					GPIO.output(22, GPIO.LOW) 	
			elif value[1] == 'desliga':
				if state == GPIO.LOW:
					GPIO.output(22, GPIO.HIGH)
		
                SimpleHTTPServer.SimpleHTTPRequestHandler.do_GET(self)

def signal_handler(signal, frame):
	GPIO.cleanup()
	sys.exit(0)
signal.signal(signal.SIGINT, signal_handler)
HandlerClass = MyServer
ServerClass  = BaseHTTPServer.HTTPServer
Protocol     = "HTTP/1.0"

if sys.argv[1:]:
    port = int(sys.argv[1])
else:
    port = 8000
server_address = ('0.0.0.0', port)

HandlerClass.protocol_version = Protocol
httpd = ServerClass(server_address, HandlerClass)

sa = httpd.socket.getsockname()
print "Serving HTTP on", sa[0], "port", sa[1], "..."
httpd.serve_forever()























A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A

