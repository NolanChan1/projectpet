
/*******************************************************************************
* image
* filename: C:/Users/m00bm/Desktop/Files/Arduino/project_pet/assets/alternate1/pet_children1.xml
* name: pet_children1
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



static const uint8_t image_data_pet_children1[16] = {
    0xc1, 0x80, 
    0xbe, 0x80, 
    0x7f, 0x00, 
    0x5d, 0x00, 
    0x5d, 0x00, 
    0x36, 0x00, 
    0x7f, 0x00, 
    0x80, 0x80
};
const tImage pet_children1 = { image_data_pet_children1, 9, 8,
    8 };

