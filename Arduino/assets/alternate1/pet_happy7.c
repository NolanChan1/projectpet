
/*******************************************************************************
* image
* filename: C:/Users/m00bm/Desktop/Files/Arduino/project_pet/assets/alternate1/pet_happy7.xml
* name: pet_happy7
*
* preset name: Monochrome
* data block size: 8 bit(s), uint8_t
* RLE compression enabled: no
* conversion type: Monochrome, Threshold Dither 128
* bits per pixel: 1
*
* preprocess:
*  main scan direction: top_to_bottom
*  line scan direction: forward
*  inverse: no
*******************************************************************************/

/*
 typedef struct {
     const uint8_t *data;
     uint16_t width;
     uint16_t height;
     uint8_t dataSize;
     } tImage;
*/
#include <stdint.h>



static const uint8_t image_data_pet_happy7[128] = {
    0xcf, 0xbf, 0xef, 0x3f, 
    0xdf, 0xbf, 0xff, 0x3f, 
    0xcf, 0x3f, 0xef, 0x7f, 
    0xcf, 0xff, 0xcf, 0xbf, 
    0xf7, 0x0f, 0xbe, 0xff, 
    0xff, 0x0f, 0x7e, 0xff, 
    0x03, 0xc3, 0x3d, 0xff, 
    0x03, 0xc3, 0x7c, 0xff, 
    0xf0, 0xc0, 0x3b, 0xff, 
    0xf0, 0xc0, 0x3b, 0xff, 
    0xf4, 0x33, 0x00, 0x3f, 
    0xf8, 0x33, 0x30, 0x3f, 
    0xf3, 0xff, 0x48, 0xcf, 
    0xf3, 0xff, 0x04, 0xcf, 
    0xcc, 0xfc, 0xc1, 0x33, 
    0xcc, 0xfc, 0xc0, 0x33, 
    0xcc, 0xfc, 0xf3, 0x30, 
    0xcc, 0xfc, 0xf3, 0x30, 
    0xcc, 0xfc, 0xf3, 0x30, 
    0xcc, 0xfc, 0xf3, 0x30, 
    0xc3, 0xff, 0x00, 0x00, 
    0xc3, 0xff, 0x01, 0x00, 
    0xc3, 0x33, 0x00, 0x03, 
    0xc3, 0x33, 0x00, 0x03, 
    0xf3, 0xcf, 0x00, 0x0f, 
    0xf1, 0xcf, 0x00, 0x0f, 
    0xf0, 0x00, 0x00, 0x0f, 
    0xf0, 0x00, 0x00, 0x0f, 
    0xf2, 0x3c, 0xcc, 0xcf, 
    0xf2, 0x3c, 0xcc, 0xcf, 
    0xfc, 0xff, 0x33, 0x3f, 
    0xfc, 0xff, 0x33, 0x3f
};
const tImage pet_happy7 = { image_data_pet_happy7, 32, 32,
    8 };

