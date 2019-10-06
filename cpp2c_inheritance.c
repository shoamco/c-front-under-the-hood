#include <stdio.h>
#include "cpp2c_inheritance_defs.h"


void doMaterials() {


    Materials mat;
    struct MatTest {
        Materials mat;
        Material_t mat_t;
    };
    struct Material_t mat1;
    Material_t mat2;
    printf("\n--- Start doMaterials() ---\n\n");
    /*size of empty struct in c =1*/
    printf("Size of Materials: %lu\n", sizeof(Materials) + 1);
    printf("Size of mat: %lu\n", sizeof(mat) + 1);
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));


    /*Struct padding ->4*2*/
    printf("Size of Materials + Material_t: %lu\n", sizeof(struct MatTest) * 2);

    mat1.material = OTHER;
    printf("Material created, set to %s\n", "Other");
    mat2.material = METAL;
    /*   Material_t mat2(Materials::METAL);
     */
    printf("Material created, set to %s\n", "Metal");


    printf("\n--- End doMaterials() ---\n\n");
}

void doPhysicalBox() {

    PhysicalBox pb1;
    PhysicalBox pb2;
    PhysicalBox pb3;
    PhysicalBox pb4;
    printf("\n--- Start doPhysicalBox() ---\n\n");

    /*  PhysicalBox pb1(8, 6, 4, Materials::PLASTIC);*/
    __PhysicalBox_CTOR_d_d_d_t__(&pb1, 8, 6, 4, PLASTIC);
    /* PhysicalBox pb2(Materials::WOOD);*/
    __PhysicalBox_CTOR_t__(&pb2, WOOD);
    /*   PhysicalBox pb3(7, 7, 7);*/
    __PhysicalBox_CTOR_d_d_d__(&pb3, 7, 7, 7);


    printf("\npb4 is copy-constructed from pb1\n");
    /*   copy COTR inline    PhysicalBox pb4 = pb1;*/
    __operator_Assignment_p_p(&(pb4.box), &(pb1.box));
    pb4.material.material = pb1.material.material;


    /*  pb4.printp();*/
    __printp_cpc__(&pb4);
    /*pb1.printp();*/
    __printp_cpc__(&pb1);


/*    printf("pb4 %s pb1\n", pb4 == pb1 ? "equals" : "does not equal");*/

    printf("pb4 %s pb1\n",
           pb4.box.height == pb1.box.width && pb4.box.height == pb1.box.height && pb4.box.length == pb1.box.length &&
           pb4.material.material == pb1.material.material ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    /* pb4 = pb3;*/
    __operator_Assignment_p_p(&(pb4.box), &(pb3.box));
    pb4.material.material = pb3.material.material;
    /*   pb4.printp();*/
    __printp_cpc__(&pb4);
    /*   pb3.printp();*/
    __printp_cpc__(&pb3);

    printf("pb4 %s pb3\n",
           pb4.box.height == pb3.box.width && pb4.box.height == pb3.box.height && pb4.box.length == pb3.box.length &&
           pb4.material.material == pb3.material.material ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");
    /*DTOR*/
    __box_DTOR(&pb1);
    __PhysicalBox_DTOR__(&pb1);

    __box_DTOR(&pb2);
    __PhysicalBox_DTOR__(&pb2);

    __box_DTOR(&pb3);
    __PhysicalBox_DTOR__(&pb3);

    __box_DTOR(&pb4);
    __PhysicalBox_DTOR__(&pb4);

}


void doWeightBox() {
    WeightBox pw1;
    WeightBox pw2;
    WeightBox pw3;
    WeightBox pw4;
    printf("\n--- Start doWeightBox() ---\n\n");
/*WeightBox pw1(8, 6, 4, 25);*/
    __WeightBox_CTOR_d_d_d_d__(&pw1, 8, 6, 4, 25);

    /* WeightBox pw2(1, 2, 3);*/
    __WeightBox_CTOR_d_d_d__(&pw2, 1, 2, 3);
    /* WeightBox pw3(10, 20, 30, 15);*/
    __WeightBox_CTOR_d_d_d_d__(&pw3, 10, 20, 30, 15);

    printf("\npw4 is copy-constructed from pw1\n");
    /*  WeightBox pw4 = pw1;*/
    __WeightBox_COPY_CTOR__(&pw4,&pw1);

    /*  pw4.printw();*/
    __WeightBox_printw__(&pw4);
    /* pw1.printw();*/
    __WeightBox_printw__(&pw1);

    printf("pw4 %s pw1\n",
           pw4.box.height == pw1.box.width && pw4.box.height == pw1.box.height && pw4.box.length == pw1.box.length &&
                   pw4.weight == pw1.weight ? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    /* pw4 = pw3;*/
    pw4 = __WeightBox__operator_Assignment_p_p(&pw4, &pw3);

    /* pw4.printw();*/
    __WeightBox_printw__(&pw4);

    /*   pw3.printw();*/
    __WeightBox_printw__(&pw3);


    printf("pw4 %s pw3\n",
           pw4.box.height == pw3.box.width && pw4.box.height == pw3.box.height && pw4.box.length == pw3.box.length &&
           pw4.weight == pw3.weight ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");
    /*DTOR*/
    __box_DTOR(&(pw1.box));
    __WeightBox_DTOR__(&pw1);

    __box_DTOR(&(pw2.box));
    __WeightBox_DTOR__(&pw2);

    __box_DTOR(&(pw3.box));
    __WeightBox_DTOR__(&pw3);

    __box_DTOR(&(pw4.box));
    __WeightBox_DTOR__(&pw4);
}


int main() {
    printf("\n--- Start main() ---\n\n");

    doMaterials();

    doPhysicalBox();

    doWeightBox();

    printf("\n--- End main() ---\n\n");

}


