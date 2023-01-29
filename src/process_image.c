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
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    // TODO Fill this in
    return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
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
