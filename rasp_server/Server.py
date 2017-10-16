import cgi
import time

from controller import getInternetInfo, getLog

def notfound_404(environ, start_response):
    start_response("404 Not Found", [("Content-Type", "text/plain")])
    return [b'Not Found']

class PathDispatcher:

    def __init__(self):
        self.pathmap = {}

    def __call__(self, environ, start_response):

        path = environ["PATH_INFO"]
        params = cgi.FieldStorage(environ["wsgi.input"], environ=environ)
        method = environ["REQUEST_METHOD"].lower()
        environ["params"] = {key : params.getvalue(key) for key in params}
        handler = self.pathmap.get((method, path), notfound_404)
        return handler(environ, start_response)



    def register(self, method, path, function):
        self.pathmap[method.lower(), path] = function
        return function

_hello_resp = '''\
<html>
    <head>
        <meta charset='utf-8'>
        <title>Hello {name}</title>
    </head>
    <body>
        <h1>Hello {name}!</h1>
    </body>
</html>'''

def hello_world(environ, start_response):

    start_response("200 OK", [("Content-Type", "text/html")])
    params = environ["params"]
    resp = _hello_resp.format(name=params.get("name"))
    yield resp.encode("utf-8")



if __name__ == "__main__":

    from wsgiref.simple_server import make_server

    dispatcher = PathDispatcher()
    dispatcher.register("GET", "/hello", hello_world)
    dispatcher.register("GET", "/api", getInternetInfo)
    dispatcher.register("GET", "/api/log", getLog)

    httpd = make_server("", 8000, dispatcher)
    print("Serving on port 8000....")
    httpd.serve_forever()
