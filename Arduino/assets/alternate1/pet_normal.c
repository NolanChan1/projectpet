
/*******************************************************************************
* image
* filename: C:/Users/m00bm/Desktop/Files/Arduino/project_pet/assets/alternate1/pet_normal.xml
* name: pet_normal
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



static const uint8_t image_data_pet_normal[128] = {
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 
    0xbf, 0xff, 0xff, 0xf7, 
    0xf5, 0xff, 0xff, 0x3b, 
    0xff, 0x0f, 0xfc, 0xff, 
    0xff, 0x0f, 0xff, 0xff, 
    0x03, 0xc3, 0xdf, 0xfe, 
    0x03, 0xc3, 0xff, 0xff, 
    0xf0, 0xc0, 0x3f, 0xcf, 
    0xe0, 0xc0, 0x3f, 0xeb, 
    0xfc, 0x33, 0x00, 0x3f, 
    0xfc, 0x33, 0x00, 0x3f, 
    0xf3, 0xff, 0x00, 0xcf, 
    0xf3, 0xff, 0x00, 0xcf, 
    0xcf, 0xff, 0xc0, 0x33, 
    0xcf, 0xff, 0xc0, 0x33, 
    0xcc, 0xfc, 0xf3, 0x30, 
    0xcc, 0xfc, 0xf3, 0x30, 
    0xcc, 0xfc, 0xf3, 0x30, 
    0xcc, 0xfc, 0xf3, 0x30, 
    0xc3, 0xcf, 0x00, 0x00, 
    0xc3, 0xcf, 0x00, 0x00, 
    0xc3, 0xff, 0x00, 0x03, 
    0xc3, 0xff, 0x00, 0x03, 
    0xf0, 0x00, 0x00, 0x0f, 
    0xf0, 0x00, 0x00, 0x0f, 
    0xf0, 0x00, 0x00, 0x0f, 
    0xf0, 0x00, 0x00, 0x0f, 
    0xf0, 0x3c, 0xcc, 0xcf, 
    0xf0, 0x3c, 0xcc, 0xcf, 
    0xfc, 0xff, 0x33, 0x3f, 
    0xfc, 0xff, 0x33, 0x3f
};
const tImage pet_normal = { image_data_pet_normal, 32, 32,
    8 };

