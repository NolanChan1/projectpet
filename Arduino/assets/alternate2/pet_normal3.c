
/*******************************************************************************
* image
* filename: C:/Users/m00bm/Desktop/Files/Arduino/project_pet/assets/alternate2/pet_normal3.xml
* name: pet_normal3
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



static const uint8_t image_data_pet_normal3[128] = {
    0xff, 0xf0, 0x0f, 0xff, 
    0xff, 0xf0, 0x0f, 0xff, 
    0xff, 0xf0, 0x0f, 0xff, 
    0xff, 0xc0, 0x0f, 0xff, 
    0xff, 0xc0, 0x0f, 0xff, 
    0xff, 0x00, 0x3f, 0xff, 
    0xff, 0x0c, 0x3f, 0xff, 
    0xfc, 0xff, 0x3f, 0xff, 
    0xfc, 0xff, 0x3f, 0xff, 
    0xf3, 0x3c, 0xcc, 0x03, 
    0xf3, 0x3c, 0xcc, 0x03, 
    0xf3, 0x3c, 0xc3, 0xfc, 
    0xf3, 0x3c, 0xc3, 0xfc, 
    0xcf, 0xfc, 0xcf, 0xfc, 
    0xcf, 0xfc, 0xcf, 0xfc, 
    0xf0, 0xff, 0xff, 0xf3, 
    0xf0, 0xff, 0xff, 0xf3, 
    0xcf, 0xff, 0xff, 0xfc, 
    0xcf, 0xff, 0xff, 0xfc, 
    0x3f, 0xff, 0xcf, 0x3c, 
    0x3f, 0xff, 0xcf, 0x3c, 
    0x3f, 0xff, 0xf0, 0xf3, 
    0x3f, 0xff, 0xf0, 0xf3, 
    0x3f, 0xff, 0xff, 0xc3, 
    0x3f, 0xff, 0xff, 0xc3, 
    0xc3, 0xff, 0xc3, 0xcf, 
    0xc3, 0xff, 0xc3, 0xcf, 
    0xf0, 0xff, 0x3c, 0x0f, 
    0xf0, 0xff, 0x3c, 0x0f, 
    0xfc, 0x03, 0x3c, 0x3f, 
    0xfc, 0x03, 0x3c, 0x3f, 
    0xf3, 0xf3, 0xf3, 0xff
};
const tImage pet_normal3 = { image_data_pet_normal3, 32, 32,
    8 };

