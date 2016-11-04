library(plot3Drgl)
w=60
q=40
m=matrix(0,w,w)
k=terrain.colors(w)

for(i in 2:(w-1)){
  for(j in 2:(w-1)){
    m[i,j]=sample(c(0,1),1,prob=c(0.2,0.8))
  }
}
szer=matrix(,w,w)
dlug=matrix(,w,w)
for(i in 1:w){
  for(j in 1:w){
    szer[i,j]=i
    dlug[i,j]=j
  }
}

for (reps in 1:q){
  s=matrix(0,w,w)
  for(i in 2:(w-1)){
    for(j in 2:(w-1)){
      s[i,j]=m[i-1,j-1]+m[i-1,j]+m[i-1,j+1]+m[i,j-1]+m[i,j+1]+m[i+1,j-1]+m[i+1,j]+m[i+1,j+1]
    }
  }
  for(i in 2:(w-1)){
    for(j in 2:(w-1)){
      if(m[i,j]>0){
        m[i,j]=m[i,j]+sample(c(0,1),1,prob=c(1-1/(s[i,j]+1),1/(s[i,j]+1)))
      }
    }
  }
}

persp3D(x=szer,y=dlug,z=20*m,scale=F,col=rev(k),pch=15,expand=0.02,plot=T)
plotrgl(lighting=F,smooth=T)