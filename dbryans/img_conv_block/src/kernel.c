void kernel (unsigned short imgIn, short featureIn, int imgOut)
for (i = 0; i < (WINDOW_ROWS - FEATURE_SIZE); i++) {
    for (j = 0; j < (WINDOW_COLS - FEATURE_SIZE); j++) {
        for (k = 0; k < FEATURE_SIZE; k++) {
            for (l = 0; l < FEATURE_SIZE-1; l += 4){
                        
                imgInPix_64 = _mem8(&imgIn[(i+k)*(WINDOW_COLS) + j+l]);
                featureInPix_64 = _mem8(&featureIn[k*(FEATURE_SIZE)+l]);
                temp += _dotpsu4h(imgInPix_64, featureInPix_64);
                        
                // imgOut[i][j] += imgIn[i+k][j+l] * featureIn[k][l];
            }
            temp += imgIn[(imgInL2+k)*(WINDOW_ROWS) + (j) + (FEATURE_SIZE)-1] * featureIn[k*(FEATURE_SIZE) + (FEATURE_SIZE)-1];
        }
        // imgOut[(i+m*(WINDOW_ROWS-FEATURE_SIZE))*(OUTPUT_COLS) + j +n*(WINDOW_COLS-FEATURE_SIZE)] = temp;
        imgOut[(i)*(OUTPUT_COLS) + j ] = temp;
        temp = 0;
    }
 }
