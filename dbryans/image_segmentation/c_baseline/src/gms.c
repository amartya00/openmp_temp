#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>
#define Sleep(p) usleep(1000*p)
double timerval () {
    struct timeval st;
    gettimeofday(&st, NULL);
    return (st.tv_sec+st.tv_usec*1e-6);
}

double totaltimesec (double start, double stop) {
    return (stop-start);
}



#define N_PIX 154048//262144
#define ROWS 332//512
#define COLS 464//512
#define SIZE 26

//const char DATA_FILE[] = "lena2.dat";// File with pixel values
const char DATA_FILE[] = "./test_vectors/bobby.dat";// File with pixel values
const char outFile[] = "./out/result.dat";// File with pixel values
unsigned int count, data[N_PIX], pix_x[ROWS][COLS], pix_y[ROWS][COLS];
unsigned int pix_x_orig[ROWS][COLS], pix_y_orig[ROWS][COLS];
unsigned int pix_z[N_PIX], pix_z_orig[N_PIX];
unsigned int sub_outx, sub_outy, sub_outz, mult_outx, mult_outy, mult_outz, add_outxy;
unsigned int dist, sig, exp_in, Gx, Gy, Gz;
unsigned int accum_x=0, accum_y=0, accum_z=0, accum_G=0;
unsigned int h=0, i =0, j=0, k=0, m, n, n_rows, n_cols, norm=1, t=0;
unsigned int new_G, acc_x, acc_y, acc_z, acc_G;
unsigned int new_x, new_y, new_z;
unsigned long int Gauss_k[11] = {0};

int main ()
{
    int lookUp[SIZE] = {0};
    FILE *file;  // Output file
    int i = 0;
    ///////////////////////////////////////////////////////
    //Read from file
    ///////////////////////////////////////////////////////
    FILE *in_file;  // Input file
    char line[8];   // Input line
    in_file = fopen(DATA_FILE, "r");
    if (in_file == NULL) {
        fprintf(stderr,"Error:Unable to open %s\n", DATA_FILE);
        exit (8);
    }

    for (i = 0; i <= SIZE; i++)  lookUp[i] = i*i;

    
    Gauss_k[0]=100000;
    Gauss_k[1]=36788;
    Gauss_k[2]=13534;
    Gauss_k[3]=4979;
    Gauss_k[4]=1831;
    Gauss_k[5]=674;
    Gauss_k[6]=248;
    Gauss_k[7]=91;
    Gauss_k[8]=34;
    Gauss_k[9]=12;
    Gauss_k[10]=0;


    count = 0;
    for(i=0;i<N_PIX;i++){                   //Read N_PIX values
        fgets(line, sizeof(line),  in_file);
        sscanf(line, "%d", &data[count]);   //convert number
        pix_z_orig[i]=data[count];
        pix_z[i]=data[count];
        ++count;
    }
    fclose(in_file);
    //End read from file  
    ///////////////////////////////////////////////////////
  
    //Initialize
    ///////////////////////////////////////////////////////
    //double StartTime=timerval();  //start timing
    for(i=0;i<332;i++){//512
        for(j=0;j<464;j++){//512
            pix_x_orig[i][j]=j+1;
            pix_y_orig[i][j]=i+1;
            pix_x[i][j]=j+1;
            pix_y[i][j]=i+1;
        }
    }
    //End initialization
    ///////////////////////////////////////////////////////
  
    n_rows=332;//332
    n_cols=464;//464
    sig=64;  //kernel size
  
    double StartTime=timerval();  //start timing
    //for(t=0;t<1;t++){
  
    for(m=0;m<n_rows;m++){
        for(n=0;n<n_cols;n++){  
            for(i = 0;i < 332; i++){ //332//512
                for(j = 0;j < 464; j++){ //464//512

                    sub_outx=pix_x_orig[m][n]-pix_x_orig[i][j];
                    sub_outy=pix_y_orig[m][n]-pix_y_orig[i][j];
                    sub_outz=pix_z_orig[m*464+n]-pix_z_orig[i*464+j];//464//512
                    //printf ("pix_x_orig =  %d \n", pix_x_orig[i][j]);
                    //printf ("pix_y_orig =  %d \n", pix_y_orig[i][j]);
                    //printf ("pix_z_orig =  %d \n", pix_z_orig[m*464+n]);

                    // mult_outx=sub_outx*sub_outx;
                    // mult_outy=sub_outy*sub_outy;
                    if (sub_outx > SIZE) sub_outx = SIZE;
                    mult_outx = lookUp[sub_outx];
                    

                    if (sub_outy > SIZE) sub_outy = SIZE;
                    mult_outy = lookUp[sub_outy];
                                        
                    mult_outz=sub_outz*sub_outz;
                    //add_outxy=mult_outx+mult_outy;
    
                    dist = mult_outx+mult_outy+mult_outz;
                    
                    exp_in = dist << 8; 

                    if (exp_in >  11) exp_in = 11;
                    
                    accum_G=accum_G+Gauss_k[exp_in];
                    
                    Gx=pix_x_orig[i][j]*Gauss_k[exp_in];
                    Gy=pix_y_orig[i][j]*Gauss_k[exp_in];
                    Gz=pix_z_orig[i*464+j]*Gauss_k[exp_in];//464//512
        
                    accum_x=accum_x+Gx;
                    accum_y=accum_y+Gy;
                    accum_z=accum_z+Gz;
                    
                    //Store results in file.dat
                    //file = fopen("file.dat","a");
                    //fprintf(file, "%d\n", accum_x); //write output data
                    //fprintf(file, "%d %d %d %d\n", accum_x, accum_y, accum_z, accum_G); //write output data
                    //fclose(file);
                    //End write to file
                }
                
            }
            
            /*acc_x=accum_x;
              acc_y=accum_y;
              acc_z=accum_z;
              acc_G=accum_G;
              new_x=acc_x/acc_G;
              new_y=acc_y/acc_G;
              new_z=acc_z/acc_G;*/
            if (accum_G==0){
                accum_G=1;
            }
            
            new_x=accum_x/accum_G;
            new_y=accum_y/accum_G;
            new_z=accum_z/accum_G;
            
            
            ////////////////////////////////////////////////////////////////////
            //Changed here for debug
            //Store results in file.dat
            //file = fopen("file.dat","a");
            //fprintf(file, "%d %d %d %d\n", accum_x, accum_y, accum_z, accum_G); //write output data
            //fclose(file);
            //End write to file
            
            //Store results in file.dat
            file = fopen(outFile,"a");
            fprintf(file, "%d  %d %d\n", new_x, new_y, new_z); //write output data
            //fprintf(file, "%d\n", accum_G); //write output data
            fclose(file);
            //End write to file
            
            accum_x=0;
            accum_y=0;
            accum_z=0;
            accum_G=0;
        }
        
    }
        
    //}
    double StopTime=timerval();
    printf (" elapsed time in seconds: %g\n", (StopTime - StartTime));
    return (EXIT_SUCCESS);
}

