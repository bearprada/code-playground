#!/usr/bin/env python
import urllib2
import json

def requestUrl(url):
    req = urllib2.Request(url)
    response = urllib2.urlopen(req)
    return json.load(response)

if __name__=="__main__":
    colls = requestUrl("https://api.github.com/repos/rspec/rspec/collaborators")
    result = []
    for c in colls:
        repos = requestUrl("https://api.github.com/users/"+c["login"]+"/repos")
        total = 0
        for r in repos:
            total = total + r['watchers']
        #print "------ the collaborator : " + c['login'] + " total watchers " + str(total)
        result.append({"login":c['login'],"totalWatchers":total})
    new_result = sorted(result,key=lambda k: k['totalWatchers'], reverse=True)

    print "===== show result ======"
    for n in new_result:
        print n