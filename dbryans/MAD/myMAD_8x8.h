/*
 * myMAD_8x8.h
 *
 *  Created on: Aug 3, 2012
 *      Author: Dorian
 *      Based on the code from IMG_mad_8x8_cn.c provided by the TI image library version 3.1.1.0
 */

#ifndef MYMAD_8X8_H_
#define MYMAD_8X8_H_

void IMG_myMad_8x8
(
    const unsigned char *restrict refImg,
    const unsigned char *restrict srcImg,
    int pitch, int sx, int sy,
    unsigned int *restrict match
)
{
    int i, j, x, y, matx, maty;
    unsigned matpos, matval;

    matval = ~0U;
    matx   = maty = 0;

/*
#ifndef NOASSUME
    _nassert((int)srcImg % 4 == 0);
    _nassert(pitch >  8);
    _nassert(sx    >= 4);
    _nassert(sy    >= 4);
#endif
 */

    for (x = 0; x < sx; x++)
        for (y = 0; y < sy; y++)
        {
            unsigned acc = 0;

            for (i = 0; i < 8; i++)
                for (j = 0; j < 8; j++)
                    acc += abs(srcImg[i*8 + j] - refImg[(i+y)*pitch + x + j]);

            if (acc < matval)
            {
                matval = acc;
                matx   = x;
                maty   = y;
            }
        }

    matpos    = (0xffff0000 & (matx << 16)) | (0x0000ffff & maty);
    match[0] = matpos;
    match[1] = matval;
}


#endif /* MYMAD_8X8_H_ */