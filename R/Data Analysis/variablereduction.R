# This file shows how to do variable selection using the lasso method in glmnet
# you require the R package glmnet 
library('glmnet')
model=cv.glmnet(x,y,alpha=1,nfolds=20)
model.coef=coef(model)