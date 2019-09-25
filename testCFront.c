#include "testCFront.h"
void print_box(Box *b){
    printf("Length: %lf,Width: %lf, Height: %lf getVolume: %lf \n",getLength(b),getWidth(b),getHeight(b),getVolume(b));
}

void test_ctor_box() {

    printf("\n--- in test_ctor_box ---\n\n");
    Box box1, box2, box3;

    __box_CTOR_d_d_d(&box1, 1, 2, 3);
    __box_CTOR_d(&box2, 2);
    __box_CTOR(&box3);

    print_box(&box1);
    print_box(&box2);
    print_box(&box3);


    __box_DTOR(&box1);
    __box_DTOR(&box2);
    __box_DTOR(&box3);


}