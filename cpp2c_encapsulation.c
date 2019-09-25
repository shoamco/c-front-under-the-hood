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

    if (flag_static == false) {

        __box_CTOR_d_d_d(&box99, 99, 99, 99);
        flag_static = true;
    }
    printf("\n--- thisFunc() ---\n\n");
    /* box99 *= 10;*/
    __operator_Multiplication_Equal_p_d(&box99,10);
    __print_Box_p(&box99);
    __box_DTOR(&box99);


}

void thatFunc() {
    static Box box88;
    printf("\n--- thatFunc() ---\n\n");

    __box_CTOR_d_d_d(&box88, 88, 88, 88);
    /* box88 *= 10;*/

    __operator_Multiplication_Equal_p_d(&box88,10);

    __box_DTOR(&box88);
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

    __operator_Multiplication_Equal_p_d(&b1,1.5);

    /* b2 *= 0.5;*/
    __operator_Multiplication_Equal_p_d(&b1,0.5);

    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b1.length * b1.height);

    /*b3 = b2;*/
    __operator_Assignment_p_p(&b3, &b2);
    /*b4 = 3 * b2*/
    __operator_Assignment_p_p(&b4,__operator_Multiplication_Equal_p_d(&b2,3));


    printf("b3 %s b4\n",
           b3.height == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    /*  b3 *= 1.5;*/
    __operator_Multiplication_Equal_p_d(&b3,1.5);



    /*b4 *= 0.5;*/
    __operator_Multiplication_Equal_p_d(&b4,0.5);

    printf("Now, b3 %s b4\n",
           b3.height == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");
    __box_DTOR(&b1);
    __box_DTOR(&b2);
    __box_DTOR(&b3);
    __box_DTOR(&b4);
}


void doShelves() {
    Box aBox;
    Shelf aShelf;
    Box temporary ;



    __box_CTOR_d(&aBox, 5);


    printf("\n--- start doShelves() ---\n\n");


    __print_Shelf_p(&aShelf);
    __setBox_p_i_p(&aShelf, 1, &largeBox);
    __setBox_p_i_p(&aShelf, 0, &aBox);
    __print_Shelf_p(&aShelf);


    /* aShelf.setBox(1, Box(2, 4, 6));*/

    __box_CTOR_d_d_d(&temporary, 2, 4, 6);
    __setBox_p_i_p(&aShelf, 1,&temporary);

    __box_DTOR(&temporary);
    /*


    aShelf.setMessage("This is the total volume on the shelf:");
    aShelf.print();
    Shelf::setMessage("Shelf's volume:");
    aShelf.print();

    aShelf.setBox(1, Box(2, 4, 6));

    aShelf.setBox(2, 2);
    aShelf.print();
*/
    __box_DTOR(&aBox);
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
    __box_DTOR(&largeBox);
    return 0;
}

