
#ifndef CPP_UTH_ENCAPSULATION_SHOAMCO_CPP2C_INHERITANCE_DEFS_H
#define CPP_UTH_ENCAPSULATION_SHOAMCO_CPP2C_INHERITANCE_DEFS_H

#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

/*/// Materials ///////////*/
/*static function-in c its only global-all file can call this function and not only one file(not static in c) */
typedef enum Types{
        PLASTIC,
        METAL,
        WOOD,
        PAPER,
        OTHER
}Types;

typedef struct Materials
{
}Materials;

/*const char* getName(Types type);

const char* getName(Types type)
{

    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    return names[type];
}
 */


/*
struct Material_t: public Materials
{
    Material_t(Types mat = OTHER): material(mat) { printf("Material created, set to %s\n", name()); }
    const char* name() const { return getName(material); }

    Types material;
};*/




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
/*
class PhysicalBox: public Box
{
public:
    PhysicalBox(double l, double w, double h);
    PhysicalBox(double l, double w, double h, Materials::Types t);
    PhysicalBox(Materials::Types t);
    ~PhysicalBox();

    Materials::Types getMaterial() const;
    void printp() const;

private:
    Material_t material;
};

bool operator==(const PhysicalBox&, const PhysicalBox&);
bool operator!=(const PhysicalBox&, const PhysicalBox&);

//// PhysicalBox Defs ////////////

inline Materials::Types PhysicalBox::getMaterial() const
{
    return material.material;
}

inline bool operator==(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
    return (const Box&)lhs == (const Box&)rhs && lhs.getMaterial() == rhs.getMaterial();
}

inline bool operator!=(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
    return !(lhs == rhs);
}

//// WeightBox ////////////

class WeightBox: public Box
{
public:
    WeightBox(double l, double w, double h, double wgt = 0.0);
    WeightBox(const WeightBox& other);
    ~WeightBox();

    WeightBox& operator=(const WeightBox& other);

    double getWeight() const;
    void printw() const;

private:
    double weight;
};

bool operator==(const WeightBox&, const WeightBox&);
bool operator!=(const WeightBox&, const WeightBox&);

//// WeightBox Defs ////////////

inline double WeightBox::getWeight() const
{
    return weight;
}

inline bool operator==(const WeightBox& lhs, const WeightBox& rhs)
{
    return (const Box&)lhs == (const Box&)rhs && lhs.getWeight() == rhs.getWeight();
}

inline bool operator!=(const WeightBox& lhs, const WeightBox& rhs)
{
    return !(lhs == rhs);
}



*/



#endif /*CPP_UTH_ENCAPSULATION_SHOAMCO_CPP2C_INHERITANCE_DEFS_H*/
