#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"
#include "testCFront.h"

/*
 *
 gcc cpp2c_encapsulation.c cpp2c_encapsulation_defs.c cpp2c_encapsulation_defs.h -std=gnu90 -Wall -pedantic -Wconversion -Wconversion -ansi -o a

 gcc testCFront.c testCFront.h cpp2c_encapsulation.c cpp2c_encapsulation_defs.c cpp2c_encapsulation_defs.h -std=gnu90 -Wall -pedantic -Wconversion -Wconversion -ansi -o a

 */




static Box largeBox;

Bool flag_static = false;

void thisFunc() {
    static Box box99;
    printf("\n--- thisFunc() ---\n\n");
    if (flag_static == false) {
        __box_CTOR_d_d_d(&box99, 99, 99, 99);
        flag_static = true;
    }
    /* box99 *= 10;*/
    box99.width *= 10;
    box99.height *= 10;
    box99.length *= 10;
}

void thatFunc() {
    static Box box88;
    printf("\n--- thatFunc() ---\n\n");

    __box_CTOR_d_d_d(&box88, 88, 88, 88);
    /* box88 *= 10;*/
    box88.width *= 10;
    box88.height *= 10;
    box88.length *= 10;

}

void doBoxes() {
    Box b1;
    Box b2;
    Box b3;
    Box b4;


    printf("\n--- Start doBoxes() ---\n\n");


    __box_CTOR_d(&b1, 3);


    __box_CTOR_d_d_d(&b2, 4, 5, 6);


    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);

    /* b1 *= 1.5;*/
    b1.width *= 1.5;
    b1.height *= 1.5;
    b1.length *= 1.5;

    /* b2 *= 0.5;*/
    b2.width *= 0.5;
    b2.height *= 0.5;
    b2.length *= 0.5;


    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b1.length * b1.height);

    /*b3 = b2;*/
    __operator_Assignment_p_p(&b3, &b2);
    /*b4 = 3 * b2*/
    b4.width *= 3;
    b4.height *= 3;
    b4.length *= 3;


    printf("b3 %s b4\n",
           b3.height == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    /*  b3 *= 1.5;*/
    b3.width *= 1.5;
    b3.height *= 1.5;
    b3.length *= 1.5;


    /*b4 *= 0.5;*/
    b4.width *= 0.5;
    b4.height *= 0.5;
    b4.length *= 0.5;
    printf("Now, b3 %s b4\n",
           b3.height == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");
}


void doShelves() {
    Box aBox;
    Shelf aShelf;
    __box_CTOR_d(&aBox, 5);


    printf("\n--- start doShelves() ---\n\n");


    __print_Shelf_p(&aShelf);
    __setBox_p_i_p(&aShelf, 1, &largeBox);
    __setBox_p_i_p(&aShelf, 0, &aBox);
    __print_Shelf_p(&aShelf);

    /*


    aShelf.setMessage("This is the total volume on the shelf:");
    aShelf.print();
    Shelf::setMessage("Shelf's volume:");
    aShelf.print();

    aShelf.setBox(1, Box(2, 4, 6));

    aShelf.setBox(2, 2);
    aShelf.print();
*/
    printf("\n--- end doShelves() ---\n\n");
}

int main() {
    __box_CTOR_d_d_d(&largeBox, 10, 20, 30);
    /* test_box();*/
    doBoxes();

    thisFunc();
    thisFunc();
    thisFunc();

    doShelves();

    printf("\n--- End main() ---\n\n");

    return 0;
}

