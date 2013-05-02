library(tseries)

testCointegration=function(prices){
  reg=lm(prices[,1] ~ prices[,2])
  dfTest=adf.test(coredata(reg$residuals))
  pval=dfTest$p.value
  lag=as.numeric(dfTest$parameter)
  return(c(pval,lag))  
}

getPrices=function(mp,pair,index){
  return (na.omit(subset(mp,select=c(pair[index,]))))
}

showPricePlots=function(prices){
  color=rainbow(ncol(prices))
  ts.plot(prices, col=color)
  legend('topright',names(prices),col=color,lty=1,cex=.65)
}

showErrorPlots=function(prices){
  reg=lm(prices[,1]~prices[,2])
  ts.plot(reg$residuals, col="blue")
  legend('topright',"residuals",col="blue",lty=1,cex=.65)
}