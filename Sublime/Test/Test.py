import urllib
import urllib2



from BeautifulSoup import BeautifulSoup


c=urllib2.urlopen('http://kiwitobes.com/wiki/Programming_language.html')

contents=c.read( )

print contents[0:50]

print("hello world")