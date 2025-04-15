from http.server import HTTPServer , BaseHTTPRequestHandler
HOST = "128.185.112.57"
PORT = 8000
class AadithyaHTTPRequest(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("conten-type","text/html")
        self.end_headers
        self.wfile.write(bytes("<html><body><h1>HHELLO WORLD!</h1></body></html>","utf-8"))
        server = HTTPServer(HSOT,PORT,AadithyaHTTPRequest)
        print("Server is running . . . ")
        server.serve_forever()
        server.server_close()
        print("server is stopped . . .")