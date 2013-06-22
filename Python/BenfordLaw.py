#!/usr/bin/env python
import urllib2
import re
import math
import time
import Queue
from threading import Thread, Event, Lock

class BenfordParser:
    def __worker__(self):
        while not self.stop_event.isSet():
            item = self.queue.get()
            if item == self.END_SIG:
                break
            self.__request__(item['url'],item['callback'])
            self.queue.task_done()
        print "-------- terminal thread ---------"

    def __init__(self):
        self.END_SIG = -1
        self.queue = Queue.Queue()
        self.stop_event = Event()
        self.thread = Thread(target=self.__worker__)
        self.thread.start()

    def __request__(self,url,callback):
        req = urllib2.Request(url)
        req.add_header('User-agent', 'Mozilla 5.10') # the wiki page can not access without user-agent
        response = urllib2.urlopen(req)
        callback(self.__analysis__(response.read()))

    def request(self,url,callback):
        self.queue.put({'url':url,'callback':callback})

    @staticmethod
    def show(result):
        totalResult = 0
        keylist = result.keys()
        keylist.sort()
        for k in keylist:
            if k in range(1,10):
                totalResult = totalResult + result[k]
        print "| p | times | our percentage | Benford's Low | "
        for k in keylist:
            if k in range(1,10):
                print "%s\t%d\t%.2f\t%.2f" % (k, result[k], (result[k]*100.0/totalResult), math.log10(1.0+(1.0/k))*100)

    def __analysis__(self,html):
        result = {}
        for i in re.compile("[0-9]{1,}\.?[0-9]{1,}|[0-9]{1,}\,?[0-9]{1,}|[0-9]{1,}").findall(html):
            n = int(str(i.strip())[0])
            if not n in result:
                result[n] = 1
            else:
                result[n] = result[n] + 1
        return result

    def terminal(self):
        self.queue.join()
        self.stop_event.set()
        self.queue.put(self.END_SIG)
        print "------- terminal --------"

def result_callback_func(result):
    BenfordParser.show(result)

if __name__=="__main__":
    url = "http://en.wikipedia.org/wiki/Benford%27s_law"
    bp = BenfordParser()
    for i in range(10):
        bp.request(url,result_callback_func)
    bp.terminal()
