def getInternetInfo(environ, start_response):

    start_response("200 OK", [("Content-Type", "application/json"), ("Access-Control-Allow-Origin", "*")])
    params = environ["params"]

    with open("ap_info.json", "r") as f:

        resp = f.read()

    yield resp.encode("utf-8")


def getLog(environ, start_response):

    start_response("200 OK", [("Content-Type", "application/json"), ("Access-Control-Allow-Origin", "*")])
    params = environ["params"]

    with open("log.json", "r") as f:

        resp = f.read()

    yield resp.encode("utf-8")
