library(quantmod)
library(plyr)
setwd("/home/sverma/Rscripts")
source("cointegration_test.R")


tbl =read.csv("ind_niftylist.csv",stringsAsFactors=FALSE)
all.syms=tbl$Symbol

allData=list(data.frame())

#return series fncn
ret=function (x){rets=c(0,x[-1]/x[-length(x)]-1); rets}

#set n
n=length(all.syms)
#n=3

mergedReturns=xts()
mergedPrices=xts()

#get the adjusted close data
for (i in seq(from=1, to=n)){
  print (i)
  print (all.syms[i])
  t=as.data.frame(getSymbols(all.syms[i],src="yahoo",auto.assign=FALSE))
  colnames(t)<-c("open","high","low","close","volume","adjusted")
  
  #add extra columns for returns
  t$returns=ret(t$adjusted)
  
  assign(all.syms[i],t)
  mergedReturns=merge.xts(mergedReturns,as.xts(subset(t,select=c("returns"))))
  mergedPrices=merge.xts(mergedPrices,as.xts(subset(t,select=c("adjusted"))))
  
}

#give names to columns
names(mergedReturns)= all.syms[1:n]
names(mergedPrices)=all.syms[1:n]

#MDV21
MDV21=data.frame(syms=list(),MDV=list(),stringsAsFactors=FALSE)
for (i in seq(from =1 , to =n)){
  MDV21= rbind(MDV21,data.frame(syms=all.syms[i],MDV=mean(tail(get(all.syms[i])$volume,30))))
  }

#get top 25 names by MDV
topN=25
MDV21=head(MDV21[with (MDV21, order(-MDV)),],topN)

#get Correlation
CorrMatrix=cor(na.omit(mergedReturns[,MDV21$syms]))
CorrMatrix[lower.tri(CorrMatrix)==FALSE]=0
topCorr=head(order(-CorrMatrix),topN)

#get rows, cols from matrix
row=floor(topCorr/topN)+1
col=topCorr%%topN

#Pairs=list()
#get the name pairs
Pairs=cbind(colnames(CorrMatrix)[col], colnames(CorrMatrix)[row])
PairPrices=list()
PairReturns=list()

result=data.frame()

#remove NAs
for (i in seq(from=1,to=nrow(Pairs))){
  PairPrices=getPrices(mergedPrices,Pairs,i)
  result=rbind(result,c(i,testCointegration(PairPrices)))
    
}

names(result)=c("index","pval","lags")
result=result[with(result,order(pval)),]


