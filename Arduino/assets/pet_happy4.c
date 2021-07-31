
/*******************************************************************************
* image
* filename: C:/Users/m00bm/Desktop/Files/Arduino/project_pet/assets/pet_happy4.xml
* name: pet_happy4
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



static const uint8_t image_data_pet_happy4[128] = {
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xff, 0x03, 0xc0, 0xff, 
    0xff, 0x03, 0xc0, 0xff, 
    0xff, 0xf0, 0x0f, 0xff, 
    0xff, 0xf0, 0x0f, 0xff, 
    0xff, 0x00, 0x00, 0xff, 
    0xff, 0x00, 0x00, 0xff, 
    0xf0, 0xff, 0xff, 0x0f, 
    0xf0, 0xff, 0xff, 0x0f, 
    0xc3, 0xff, 0xff, 0xc3, 
    0xcb, 0xff, 0xff, 0xc3, 
    0x1f, 0x3f, 0xcf, 0xf0, 
    0x1f, 0x3f, 0xcf, 0xf0, 
    0x3f, 0x3f, 0xcf, 0xfc, 
    0x3f, 0x3f, 0xcf, 0xfc, 
    0x3f, 0xff, 0xff, 0xfc, 
    0x7f, 0xff, 0xff, 0xff, 
    0x0f, 0xcf, 0x3f, 0x0f, 
    0x0f, 0xcf, 0x3f, 0x0d, 
    0x3f, 0xf0, 0xff, 0xfd, 
    0xbf, 0xf0, 0xff, 0xfd, 
    0xef, 0xff, 0xff, 0xcf, 
    0xaf, 0xff, 0xff, 0xc8, 
    0x10, 0xf0, 0x08, 0xb4, 
    0x00, 0x00, 0x20, 0x08, 
    0xc0, 0x00, 0x00, 0x03, 
    0xc0, 0x00, 0x00, 0x03
};
const tImage pet_happy4 = { image_data_pet_happy4, 32, 32,
    8 };

