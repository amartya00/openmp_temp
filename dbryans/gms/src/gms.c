#include "gms.h"

int main(void){

    unsigned int count = 0;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;
    unsigned int m = 0;
    unsigned int n = 0;
    unsigned int t = 0;

    unsigned int windowSize = 30;
    unsigned int iterations = 1;

    uint64_t start_time, end_time;
    
    unsigned char *imgIn;

    unsigned char *x;
    unsigned char *y;
    unsigned char *z;

    unsigned char *newX;
    unsigned char *newY;
    unsigned char *newZ;

    unsigned char *x_orig;
    unsigned char *y_orig;
    unsigned char *z_orig;

    unsigned char subX = 0;
    unsigned char subY = 0;
    unsigned char subZ = 0;

    unsigned short multX = 0;
    unsigned short multY = 0;
    unsigned short multZ = 0;

    unsigned short dist = 0;
    unsigned short tid = 0;

    unsigned int gauss[11] = {0};
    unsigned short expIn = 0;
    unsigned int accumG = 0;

    unsigned int accumX = 0;
    unsigned int accumY = 0;
    unsigned int accumZ = 0;

    unsigned int gX = 0;
    unsigned int gY = 0;
    unsigned int gZ = 0;

    imgIn = (unsigned char*)(IMG_IN_ADDR);

    x = (unsigned char *)(X_ADDR);
    y = (unsigned char *)(Y_ADDR);
    z = (unsigned char *)(Z_ADDR);

    newX = (unsigned char *)(NEW_X_ADDR);
    newY = (unsigned char *)(NEW_Y_ADDR);
    newZ = (unsigned char *)(NEW_Z_ADDR);

    x_orig = (unsigned char *)(X_ORIG_ADDR);
    y_orig = (unsigned char *)(Y_ORIG_ADDR);
    z_orig = (unsigned char *)(Z_ORIG_ADDR);

    gauss[0]=100000;
    gauss[1]=36788;
    gauss[2]=13534;
    gauss[3]=4979;
    gauss[4]=1831;
    gauss[5]=674;
    gauss[6]=248;
    gauss[7]=91;
    gauss[8]=34;
    gauss[9]=12;
    gauss[10]=0;

    //omp_set_num_threads(8);

    for(i=0;i<NUM_ROWS;i++){//332//256
        for(j=0;j<NUM_COLS;j++){//464//256
            x_orig[i*(NUM_COLS)+j]=j;
            y_orig[i*(NUM_COLS)+j]=i;
            x[i*(NUM_COLS)+j]=j;
            y[i*(NUM_COLS)+j]=i;
            z_orig[i*(NUM_COLS)+j] = imgIn[i*(NUM_COLS)+j];
            z[i*(NUM_COLS)+j] = imgIn[i*(NUM_COLS)+j];
        }
    }

    start_time = _itoll(TSCH,TSCL);
    //#pragma omp parallel shared(x,y,z,x_orig,y_orig,z_orig,newX,newZ,newY) private(m,n,t,i,j,subX,subY,subZ,multX,multY,multZ,dist,expIn,accumG,gauss,gX,gY,gZ,accumX,accumY,accumZ)
    {
        //#pragma omp for schedule(static, (NUM_ROWS)/(8))
        // tid = omp_get_thread_num();
        //for (m = tid*((NUM_ROWS)/8);  m < (tid+1)*((NUM_ROWS)/8); m++){
        for (m = 0;  m < NUM_ROWS; m++){
        for (n = 0; n < NUM_COLS; n++){
            for (t = 0; t < iterations; t++){
                if(m < windowSize){
                    for (i = 0; i < m+windowSize; i++){
                        for (j = 0; j < NUM_COLS; j++){
                            subX = x[m*(NUM_COLS)+n] -  x_orig[i*(NUM_COLS)+j];
                            multX = subX * subX;
                            
                            subY = y[m*(NUM_COLS)+n] -  y_orig[i*(NUM_COLS)+j];
                            multY = subY * subY;
                                
                            subZ = z[m*(NUM_COLS)+n] -  z_orig[i*(NUM_COLS)+j];
                            multZ = subZ * subZ;

                            dist = multX + multY + multZ;

                            expIn = dist << (KERNEL_SIZE);
                            if (expIn >  11) expIn = 11;
                            accumG = accumG + gauss[expIn];

                            gX = x_orig[i*(NUM_COLS)+j]*gauss[expIn];                            
                            gY = y_orig[i*(NUM_COLS)+j]*gauss[expIn];                            
                            gZ = z_orig[i*(NUM_COLS)+j]*gauss[expIn];

                            accumX=accumX+gX;
                            accumY=accumY+gY;
                            accumZ=accumZ+gZ;
                            
                        }
                    }
                }

                /* else{
                    for(i=m-windowSize; i<m+windowSize; i++){
                        for (j = 0; j < NUM_COLS; j++){
                            subX = x[m*(NUM_COLS)+n] -  x_orig[i*(NUM_COLS)+j];
                            multX = subX * subX;
                            
                            subY = y[m*(NUM_COLS)+n] -  y_orig[i*(NUM_COLS)+j];
                            multY = subY * subY;
                                
                            subZ = z[m*(NUM_COLS)+n] -  z_orig[i*(NUM_COLS)+j];
                            multZ = subZ * subZ;

                            dist = multX + multY + multY;

                            expIn = dist << (KERNEL_SIZE);
                            if (expIn >  11) expIn = 11;
                            accumG = accumG + gauss[expIn];

                            gX = x_orig[i*(NUM_COLS)+j]*gauss[expIn];                            
                            gY = y_orig[i*(NUM_COLS)+j]*gauss[expIn];                            
                            gZ = z_orig[i*(NUM_COLS)+j]*gauss[expIn];

                            accumX=accumX+gX;
                            accumY=accumY+gY;
                            accumZ=accumZ+gZ;
                            
                        }
                    }
                    }*/
                newX[m*(NUM_COLS)+n]=accumX/accumG;
                newY[m*(NUM_COLS)+n]=accumY/accumG;
                newZ[m*(NUM_COLS)+n]=accumZ/accumG;

            //Store results in file.dat
            //file = fopen("file.dat","a");
            ///fprintf(file, "%f\n", new_z[m][n]); //write output data
            //fclose(file);
            //End write to file         
            
                // accumX=0;
                // accumY=0;
                // accumZ=0;
                // accumG=0;
            
                // pix_x[m][n]=new_x[m][n];
                // pix_y[m][n]=new_y[m][n];
                // pix_z[m*464+n]=new_z[m][n]
                    ; //256//464//512
            }
        }
        //printf("%d rows done\n", m);
    }
    }
    end_time = _itoll(TSCH,TSCL);
    printf("cycle count:%lld\n", end_time-start_time);
}


