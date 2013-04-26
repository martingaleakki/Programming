import urllib
import re

urlArg = 'http://www.yahoo.com'
filehandle = urllib.urlopen(urlArg)

for lines in filehandle.readlines():
	m = re.search('http\://[\w\./]+/\w+',lines)
	if m:
		print m.group(0)

filehandle.close()



