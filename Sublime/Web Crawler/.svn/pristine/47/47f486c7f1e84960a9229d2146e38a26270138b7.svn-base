import urllib2
from BeautifulSoup import BeautifulSoup

from urlparse import urljoin

class crawler(object):
	"""docstring for crawler"""
	ignorewords=set(['the','of','to','and','a','in','is','it'])
	index=dict()
	indexFileName="F:\Programming\Sublime\Web Crawler\Index.Txt"
	
	def __init__(self, arg):
		super(crawler, self).__init__()
		self.arg = arg
		self.loadIndex()
		return

	def crawl(self,pages,depth=2):
		temp=[]
		temp.extend(pages)
		print("begin of loop0")	
		for i in range(depth):
			print("Crawling ..."+str(i))
			print("Pages Length"+str(len(temp)))
			newpages=[]	
			print("begin of loop1")		
			for page in temp:
				print("Looking for links in "+page)
				try:
					c=urllib2.urlopen(page)
				except:
					print "Could not open %s" % page
					continue
				soup=BeautifulSoup(c.read( ))
				self.addtoindex(page,soup)
				links=soup('a')
				print("begin of loop2")	
				for link in links:
					if ('href' in dict(link.attrs)):							
						url=urljoin(page,link['href'])
						print("Checking " + url)
						if url.find("'")!=-1: 
							continue
	  					url=url.split('#')[0] # remove location portion
	  					if url[0:4]=='http' and not self.isindexed(url):
	  						newpages.append(url)	          	
	          	print("end of loop2")
	          	print("New pages Length:" + str(len(newpages)))
	    		temp=newpages
	    		print("end of loop1")	    
	 		self.dbcommit()
	

	def addtoindex(self,page,soup) :
	    print ("Indexing "+page)
	    self.index[page]=len(self.index)+1
	    	

	def addlinkref(self,page,url,linkText):
		print('')


	def dbcommit(self):
		print("Saving index to " + self.indexFileName)
		f=open(self.indexFileName,'w')
	    	for page in self.index.keys():
	    		print(page+"\n")
	        	f.write(page + "\n")
	        f.close()	
	    
	        
	def isindexed(self,url):
		return (self.index.has_key(url))


	def loadIndex(self):
	    print("Loading Index ...")
	    try:
	    	f=open(self.indexFileName,'r')
	    except:
	        f=open(self.indexFileName,'r+')
	        print("Warning: Index was empty")
	    lines = (line.rstrip() for line in f)
	    lines = (line for line in lines if line)
	    for line in lines:
	    	self.index[line]=len(self.index)+1
	    f.close()	
	    return
