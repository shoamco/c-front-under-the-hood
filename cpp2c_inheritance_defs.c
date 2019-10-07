

#include "cpp2c_inheritance_defs.h"


#include <stdio.h>


/*/// PhysicalBox Defs ////////////*/
void __PhysicalBox_CTOR_d_d_d__(PhysicalBox *const this, double l, double w, double h) {

    __box_CTOR_d_d_d(&(this->box), l, w, h);
    /*inline CTOR Materials member*/
    this->material.material = 0;
    __printp_cpc__(this);

}

void __PhysicalBox_CTOR_d_d_d_t__(PhysicalBox *const this, double l, double w, double h, Types t) {
    __box_CTOR_d_d_d(&(this->box), l, w, h);
    /*inline CTOR Materials member*/
    this->material.material = t;
    __printp_cpc__(this);

}

void __PhysicalBox_CTOR_t__(PhysicalBox *const this, Types t) {
    __box_CTOR(&(this->box));
    this->material.material = t;
    __printp_cpc__(this);

}

void __PhysicalBox_DTOR__(PhysicalBox *const this) {
    const char *const names[] = {"Plastic", "Metal", "Wood", "Paper", "Other"};

    printf("PhysicalBox dtor, %f x %f x %f, %s; ", this->box.length, this->box.width, this->box.height,
           names[this->material.material]);
}

void __printp_cpc__(const PhysicalBox *const this) {

    const char *const names[] = {"Plastic", "Metal", "Wood", "Paper", "Other"};

    printf("PhysicalBox, made of %s; ", names[this->material.material]);
    __print_Box_p(&(this->box));
    __WeightBox_printw__(this);

}

void __WeightBox_CTOR_d_d_d_d__(WeightBox *this, double l, double w, double h, double wgt) {
    __box_CTOR_d_d_d(&(this->box), l, w, h);
    this->weight = wgt;
    __WeightBox_printw__(this);

}

void __WeightBox_CTOR_d_d_d__(WeightBox *this, double l, double w, double h) {
    __box_CTOR_d_d_d(&(this->box), l, w, h);
    this->weight = 0.0;
    __WeightBox_printw__(this);
}

WeightBox __WeightBox__operator_Assignment_p_p(WeightBox *const this, WeightBox *const other) {
    if (this != other) {
        __operator_Assignment_p_p(&(this->box), &(other->box));
        this->weight = other->weight;
    }
    return *this;
}

void __WeightBox_printw__(const WeightBox *const this) {

    printf("WeightBox, weight: %f; ", this->weight);
    __print_Box_p(&(this->box));
}

void __WeightBox_COPY_CTOR__(WeightBox *this, WeightBox *other) {
    /*weight(other.weight);*/

    __box_CTOR(&(this->box));
    this->weight = other->weight;
    __print_Box_p(&(this->box));

}
void __WeightBox_DTOR__(WeightBox *this){
    printf("Destructing WeightBox; ");
    __WeightBox_printw__(this);
}
