

#include "cpp2c_encapsulation_defs.h"
const char* const DEF_MSG = "The total volume held on the shelf is";
const char* message = "The total volume held on the shelf is";
void __box_CTOR_d_d_d(Box *const this, double l, double w, double h) {
    this->length = l;
    this->width = w;
    this->height = h;
    __print_Box_p(this);
}

void __box_CTOR_d(Box *const this, double dim) {
    this->length = dim;
    this->width = dim;
    this->height = dim;
    __print_Box_p(this);

}

void __box_CTOR(Box *const this) {

    this->length = 1;
    this->width = 1;
    this->height = 1;
    __print_Box_p(this);

}

void __box_DTOR(Box *const this) {
    printf("Box destructor, %f x %f x %f\n", this->width, this->height, this->length);
}

double getWidth(const Box *const this) {
    return this->width;
}

double getLength(const Box *const this) {
    return this->length;
}

double getHeight(const Box *const this) {
    return this->height;
}

double __getVolume_Box__p(const Box *const this) {
    return this->width * this->length * this->height;
}

void __operator_Assignment_p_p(Box *const this, Box *const other) {
    this->length = other->length;
    this->width = other->width;
    this->height = other->height;

}

Box *__operator_Multiplication_Equal_p_d(Box *const this, double mult) {
    this->width *= mult;
    this->height *= mult;
    this->length *= mult;

    return this;
}

void __print_Box_p(const Box *const this) {
    printf("Box: %f x %f x %f\n", this->length, this->width, this->height);
}
void __print_Shelf_p(const Shelf *const this){
    printf("%s %f\n", message, __getVolume_Shelf_p(this));

}
/*
Box *__operator_Multiplication_p_d(const Box *box, double mult) {
    Box ret = box;


    return __operator_Multiplication_Equal_p_d(ret,mult);

}*/

/*
inline Box operator*(double mult, const Box& box)
{
return box * mult;
}

inline bool operator==(const Box& lhs, const Box& rhs)
{
return lhs.getWidth() == rhs.getWidth() && lhs.getHeight() == rhs.getHeight() && lhs.getLength() == rhs.getLength();
}

inline bool operator!=(const Box& lhs, const Box&rhs)
{
return !(lhs == rhs);
}
*/
/*----------shelf-------*/
void __Shelf_CTOR_default(Shelf *const shelf) {

}

void __setBox_p_i_p(Shelf *const this, int index, const Box *const dims) {
    this->boxes[index] = *dims;
}

double __getVolume_Shelf_p(const Shelf *const this) /*const function*/
{
    double vol = 0;
    int i = 0;
    for (; i < 3; ++i)
        vol += __getVolume_Box__p(&(this->boxes[i]));

    return vol;
}