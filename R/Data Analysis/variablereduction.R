# This file shows how to do variable selection using the lasso method in glmnet
# you require the R package glmnet 
# reference http://stats.stackexchange.com/questions/34859/how-to-present-results-of-a-lasso-using-glmnet
library('glmnet')
model=cv.glmnet(x,y,alpha=1,nfolds=20)
model.coef=coef(model)
model.coef.nonZero=which(model.coef!=0)