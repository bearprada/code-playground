#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define DELTA 10000
#define SIMPLE 4
#define RANGE 64
#define PI 3.1415

#define THcross 7500
#define THmuta 2

#define ANSWARE 0.0997370409

double normal_distribution(float a ,float u,int value) {
  return (1 / (sqrt(2 * PI) * a)) * exp((float)((value - u) * (value - u)) * (float)((-1) / (2 * a * a)));
}

int main(){
  int i,j,k,count;
  
  double n,sum;
  double fit[SIMPLE];
  double fit_value[SIMPLE];
  double tol = 0; 
  double max;           //紀錄基因裡面最大值 
  
  int chrom[SIMPLE],simple[SIMPLE];
  int new_gener[SIMPLE];
  int flag[RANGE];      //紀錄基因使用狀態 
  int mark[SIMPLE];     //紀錄挑選狀態 
  int iter=0;           //紀錄迭代次數
  int log;

  srand(time(NULL));
  for(i=0;i<RANGE;i++) {
    flag[i]=0;
  }

  count=0;
  //初始四個種子
  while( count<SIMPLE ) {
    k = rand() % RANGE;
    if (flag[k] == 0) { //避免選到一樣
      chrom[count++]=k;
      flag[k]=1;
    }
  }
  FILE *fo = fopen("ga_log.txt","w");
  /*
  for(i=0;i<32;i++)
  fprintf(fo,"%d = %.10f\n",i,normal_distribution(4.0,16.0,i));
  */
  //開始交配
  do{
    // calculate the fit value 
    sum = 0;
    for(i=0 ; i<SIMPLE ; i++){
      fit_value[i]= normal_distribution(4.0, 16.0, chrom[i]);
      sum+=fit_value[i];
    }

    //­ calculate the select prop
    for (i = 0 ; i < SIMPLE ; i++){
      fit[i] = (fit_value[i] / sum) * DELTA;
      //printf("%f ",fit[i]);
    }

    // pick up half of cadidate
    count=0;
    for(i = 0 ; i < SIMPLE ; i++) {
      mark[i]=0;
    }
    while (count < SIMPLE / 2) {
      for (i = 0 ; i < SIMPLE ; i++) {
        if (fit[i] > rand() % DELTA && mark[i] == 0 ) {
          simple[count++] = chrom[i];
          mark[i] = 1;
        }
      }
    }

    //嘗試交配
    if ((rand()%DELTA)<THcross) {
      for (i = 0 ; i < SIMPLE / 2 ; i+=2) {
        // keep the first byte
        new_gener[i+1] = simple[i]%RANGE   + (simple[i+1]/RANGE)*RANGE;
        new_gener[i]   = simple[i+1]%RANGE + (simple[i]/RANGE)*RANGE;
        // keep the first and second bytes
        // new_gener[i+1]   = simple[i]%8   + (simple[i+1]/8)*8;
        // new_gener[i]     = simple[i+1]%8 + (simple[i]/8)*8;                 
        // printf("%d %d => %d %d \n",simple[i],simple[i+1],new_gener[i],new_gener[i+1]);
      }
    } else {
      //¤£¥æ°tª½±µ½Æ»s
      new_gener[i+1]   = simple[i+1]; 
      new_gener[i]     = simple[i];
    } 

    // try to muation
    if(rand()<THmuta){
      for(i=0;i<SIMPLE/2;i++) {
        new_gener[i] = rand()%RANGE;
      }
      printf("this time don't care about it\n");
    }

    // 替換fit值比較低的基因 （換沒有選到的）
    for(i=0;i<SIMPLE/2;i++) {
      for(j=0;j<SIMPLE;j++) {
        if(new_gener[i]==chrom[j]) {
          new_gener[i] = rand()%RANGE;
        }
      }
    }
 
    // 找基因最大值
    j = 0;
    for (i = 0; i < SIMPLE ; i++) {
      if (j >= 2) {
        break;
      }
      if (mark[i] == 0) {
        chrom[i] = new_gener[j++];     
      }
    }

    //§ä°ò¦]³Ì¤j­È 
    max = fit_value[0]; 
    log = 0;
    for (i = 0; i < SIMPLE ; i++) {
      if (fit_value[i] > max) {
        max = fit_value[i];
        log = i;
      }
    }
    // printf("iter = %d\n", iter);
    fprintf(fo, "Generation %d\n", iter);
    for (i = 0 ; i < SIMPLE ; i++) {
      // printf("%d ",chrom[i]);
      fprintf(fo, "%d ",chrom[i]);
      //¤ñ¸û®t¶Z
      printf("max:[%d]\n", chrom[log]);
      if (max > ANSWARE)
        tol = max - ANSWARE;
      else
        tol = ANSWARE - max;
      //mark the value
      // printf("tol:%f\n",tol);
    }
    fprintf(fo, "\n");
  } while (tol > 0.00001 && iter++ < 100); //少考慮飽和問題（停止進步變數)
  
  fprintf(fo, "iter:%d\nmax:%.10f\n[%d]\n",iter,max,chrom[log]);
  for (i = 0 ; i < SIMPLE ; i++) {
    printf("|%d|",chrom[i]);
  }

  fclose(fo);
  system("pause");
  return 0;
}
