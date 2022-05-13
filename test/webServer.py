import tornado.ioloop
import tornado.web
import json
import psutil


class MainHandler(tornado.web.RequestHandler):
    def get(self):
        self.write("ok")


class DeviceHandler(tornado.web.RequestHandler):
    def get(self):
        PCinfo = {
            "cpu" : psutil.cpu_percent(percpu=True),
            "mem" : psutil.virtual_memory().percent,
        }
        self.write(json.dumps(PCinfo))


def make_app():
    return tornado.web.Application([
        (r"/", MainHandler),
        (r"/device", DeviceHandler),
    ])

if __name__ == "__main__":
    app = make_app()
    app.listen(8888)
    tornado.ioloop.IOLoop.current().start()