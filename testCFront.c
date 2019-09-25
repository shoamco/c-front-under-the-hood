#include "testCFront.h"

void print_box(Box *b) {
    printf("Length: %f,Width: %f, Height: %f getVolume: %f \n", getLength(b), getWidth(b), getHeight(b),
           __getVolume_Box__p(b));
}

void test_box() {
    Box box1, box2, box3;

    printf("\n--- in test_ctor_box ---\n\n");

    __box_CTOR_d_d_d(&box1, 1, 2, 3);
    __box_CTOR_d(&box2, 2);
    __box_CTOR(&box3);

    print_box(&box1);
    print_box(&box2);
    print_box(&box3);


    __print_Box_p(&box1);
    printf("\n\nbox1 += 5\n");
    __operator_Multiplication_Equal_p_d(&box1, 5);


    printf(" \n\n box1 = box3 * 2\n");
    __print_Box_p(&box1);
    __operator_Assignment_p_p(&box1, &box3);
    __print_Box_p(&box1);

    printf(" \n\nbefor box2 = box1 * 2\n");
    __print_Box_p(&box1);

    printf("after\n");


    /*box2 = __operator_Multiplication_p_d(&box1, 2);*/
    __print_Box_p(&box1);


    __print_Box_p(&box1);

    __box_DTOR(&box1);
    __box_DTOR(&box2);
    __box_DTOR(&box3);


}