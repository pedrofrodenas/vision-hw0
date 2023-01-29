#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    // TODO Fill this in
    int channels = im.c;
    int rows = im.h;
    int cols = im.w;

    // Clamp
    x = (x > 0) ? ((x<cols) ? x : (cols-1)) : 0;
    y = (y > 0) ? ((y<rows) ? y : (rows-1)) : 0;
    c = (c > 0) ? ((c<channels) ? c : (channels-1)) : 0;

    float pixel = *(im.data+(rows*cols*c)+(cols*y+x));
    return pixel;
}

void set_pixel(image im, int x, int y, int c, float v)
{
    // TODO Fill this in
    int rows = im.h;
    int cols = im.w;
    int channels = im.c;

    if (x < 0 || y < 0 || c < 0 || x >= cols || y >= rows || c >= channels) {
        return;
    }
    else{
        *(im.data+(rows*cols*c)+(cols*y+x)) = v;
        return;
    }
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    // TODO Fill this in
    size_t n_bytes = im.w*im.h*im.c*sizeof(float);
    memcpy(copy.data, im.data, n_bytes);
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    // TODO Fill this in
    int pixel_per_channel = im.w*im.h;
    for (size_t i = 0; i!= pixel_per_channel; ++i){
        gray.data[i] = 0.299*im.data[i] + 0.587*im.data[i+pixel_per_channel] + 0.114*im.data[i+pixel_per_channel*2];
    }
    return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
    int pixel_per_channel = im.w*im.h;
    for (int i = 0; i < pixel_per_channel; ++i){
        *(im.data + pixel_per_channel*c + i) = (*(im.data + pixel_per_channel*c + i))+v;
    }
}

void clamp_image(image im)
{
    // TODO Fill this in
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
