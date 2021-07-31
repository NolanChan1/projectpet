
/*******************************************************************************
* image
* filename: C:/Users/m00bm/Desktop/Files/Arduino/project_pet/assets/pet_normal1.xml
* name: pet_normal1
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



static const uint8_t image_data_pet_normal1[128] = {
    0xff, 0xfc, 0x3f, 0xff, 
    0xff, 0xfc, 0x3f, 0xff, 
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x03, 0x40, 0x3f, 
    0xfc, 0x03, 0xc0, 0x3f, 
    0xf3, 0xf0, 0x0f, 0x4f, 
    0xf3, 0xf0, 0x0f, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xcf, 0xff, 0xff, 0xf3, 
    0xcf, 0xff, 0xff, 0xf3, 
    0xcf, 0x3f, 0xcf, 0xf3, 
    0xcf, 0x3f, 0xcf, 0xf3, 
    0xcf, 0x3f, 0xcf, 0xf3, 
    0xcf, 0x3f, 0xcf, 0xf3, 
    0xc0, 0xf0, 0xf0, 0xf3, 
    0xc0, 0xf0, 0xf0, 0xe3, 
    0xc7, 0xff, 0xff, 0xf3, 
    0xcf, 0xff, 0xff, 0xc3, 
    0xcb, 0xff, 0xff, 0xf3, 
    0xcf, 0xff, 0xff, 0xb3, 
    0xf3, 0xff, 0xfe, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xfc, 0x00, 0x00, 0x3f, 
    0xfc, 0x00, 0x00, 0x3f
};
const tImage pet_normal1 = { image_data_pet_normal1, 32, 32,
    8 };

