
#ifndef CPP_UTH_ENCAPSULATION_SHOAMCO_CPP2C_INHERITANCE_DEFS_H
#define CPP_UTH_ENCAPSULATION_SHOAMCO_CPP2C_INHERITANCE_DEFS_H

#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

/*/// Materials ///////////*/
/*static function-in c its only global-all file can call this function and not only one file(not static in c) */

typedef enum Types{/*enum type only declaration-outside the struct Materials*/
        PLASTIC,
        METAL,
        WOOD,
        PAPER,
        OTHER
}Types;

typedef struct Materials
{
    /*empty struct-physical size =1*/
    /*getName-is implicit inline-because of the definition inside the struct*/
}Materials;


typedef struct  Material_t{
    /*inheritance Materials-empty*/

    /*struct Material_t*/
    Types material;

}Material_t;




/*/// PhysicalBox ////////////*/
typedef struct PhysicalBox{
    /*inheritance Box*/
    Box box;
/*PhysicalBox*/
    Material_t material;

}PhysicalBox;
void __PhysicalBox_CTOR_d_d_d__(PhysicalBox *const this,double l, double w, double h);
void __PhysicalBox_CTOR_d_d_d_t__(PhysicalBox *const this,double l, double w, double h, Types t);
void __PhysicalBox_CTOR_t__(PhysicalBox *const this ,Types t);
void __PhysicalBox_DTOR__(PhysicalBox *const this);
void __printp_cpc__(const PhysicalBox *const this) ;

typedef struct WeightBox{
    /*inheritance Box*/
    Box box;
    /*WeightBox*/
    double weight;
}WeightBox;
void __WeightBox_CTOR_d_d_d_d__(WeightBox *this,double l, double w, double h, double wgt);
void __WeightBox_CTOR_d_d_d__(WeightBox *this,double l, double w, double h);
void __WeightBox_COPY_CTOR__(WeightBox *this,WeightBox *other);
void __WeightBox_DTOR__(WeightBox *this);
WeightBox __WeightBox__operator_Assignment_p_p (WeightBox *const this,WeightBox *const other);
void __WeightBox_printw__(const WeightBox *const this);





#endif /*CPP_UTH_ENCAPSULATION_SHOAMCO_CPP2C_INHERITANCE_DEFS_H*/
