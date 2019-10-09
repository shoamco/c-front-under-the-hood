

#ifndef CPP_UTH_ENCAPSULATION_SHOAMCO_CPP2C_POLYMORPHISM_DEFS_H
#define CPP_UTH_ENCAPSULATION_SHOAMCO_CPP2C_POLYMORPHISM_DEFS_H


#include <stdio.h>



typedef enum {
    false = 0,
    true = 1
} Bool;

typedef void *(vptr)(void *, ...);/*vptr is type of pointer to function */
typedef vptr *VirtualTablePointer;/*VirtualTablePointer is type of pointer to Virtual Table */



/****************  TextFormatter  ****************
  class polymorphism

  function print is a pure virtual

**************************************************/

typedef struct TextFormatter
{
    VirtualTablePointer tablePointer;/*pointer to virtual table*/

} TextFormatter;

void __v_TextFormatter_DTOR_p__(TextFormatter *const

this);

/****************  DefaultTextFormatter  *************************************

  DefaultTextFormatter is class polymorphism that heiress from TextFormatter

  the class overrides (virtual method):
                     print(const char* text)
***************************************************************************/



extern int next_id;/*static variable -> global */
typedef struct Ider Ider;


typedef struct DefaultTextFormatter {
    /* heiress from  TextFormatter*/
    TextFormatter textFormatter;/*Contains DefaultTextFormatter */


    /*DefaultTextFormatter member: */
    struct Ider {
        /*static int next_id;/*--->global*/
    };
    int id;

} DefaultTextFormatter;

/*DefaultTextFormatter function:*/

/*Default CTOR inline*/
void __DefaultTextFormatter_CTOR_p__(DefaultTextFormatter *const this);

void __DefaultTextFormatter_copy_CTOR_p__(DefaultTextFormatter *const this,const DefaultTextFormatter const *other);

void __v_DefaultTextFormatter_DTOR_p__(DefaultTextFormatter *const this);

void __v_print__DefaultTextFormatter_p_cc__(const DefaultTextFormatter *const this,const char *text);

DefaultTextFormatter __DefaultTextFormatter_Assignment_p_p__(DefaultTextFormatter *const this,const DefaultTextFormatter *const other);



/**************************  PrePostFixer  **************************

 PrePostFixer is class polymorphism that heiress from:
     ----> DefaultTextFormatter  ---> TextFormatter


    the class overrides (virtual method):
                       print(const char* text)

    the class add virtual method :
                           getDefaultSymbol()
                           print(long num, char symbol) const;

*******************************************************************************/


typedef struct PrePostFixer {

    /* heiress from  DefaultTextFormatter*/
    DefaultTextFormatter defaultTextFormatter;/*Contains DefaultTextFormatter */

    /* PrePostFixer class member*/
    const char *pre;
    const char *post;


} PrePostFixer;

/*********method of PrePostFixer**********/
void __PrePostFixer_CTOR_p_cc_cc__(PrePostFixer *const

this,
const char *prefix,
const char *postfix
);

void __v_PrePostFixer_DTOR_p__(PrePostFixer *const

this);

void __v_print__PrePostFixer_p_cc__(const PrePostFixer *const this,const char *text);/*override*/

void __v_print__PrePostFixer_p_l_c__(const PrePostFixer *const this,long num,char symbol);

void __v_print__PrePostFixer_p_l__(const PrePostFixer *const this,long num);

char __v_getDefaultSymbol__PrePostFixer_p__(const PrePostFixer *const this);





/****************  PrePostDollarFixer  ****************

 PrePostDollarFixer is class polymorphism that heiress from:
 ----> PrePostFixer---> DefaultTextFormatter  ---> TextFormatter


 the class overrides  (virtual method):
                print(long num, char symbol = DEFAULT_SYMBOL) const;
                getDefaultSymbol()

*************************************************************/


typedef struct PrePostDollarFixer {
    /* heiress from  PrePostFixer*/
    PrePostFixer prePostFixer;

    /*member class */
    /*  static const char DEFAULT_SYMBOL = '$';  ---->  literal */


} PrePostDollarFixer;


/*********method of PrePostDollarFixer**********/
void __PrePostDollarFixer_CTOR_p_cc_cc__(PrePostDollarFixer *const this,const char *prefix,const char *postfix);
void __PrePostDollarFixer_COPY_CTOR_p_p__(PrePostDollarFixer *const this ,const PrePostDollarFixer *other);
void __PrePostDollarFixer_DTOR_p__(PrePostDollarFixer *const this);

void __v_print__PrePostDollarFixer_p_l_c__(const PrePostDollarFixer *const this,long num,char symbol);/*override*/

void __v_print__PrePostDollarFixer_p_l__(const PrePostDollarFixer *const this,long num);/*override*/

char __v_getDefaultSymbol__PrePostDollarFixer_p__(const PrePostDollarFixer *const this);/*override*/
void __print_PrePostDollarFixer_i__(const PrePostDollarFixer *const this,int num);
void __print_PrePostDollarFixer_i_c__(const PrePostDollarFixer *const this,int num, char symbol);

void __print_PrePostDollarFixer_d__(const PrePostDollarFixer *const this,double num);
void __print_PrePostDollarFixer_d_c__(const PrePostDollarFixer *const this,double num, char symbol);


/****************  PrePostHashFixer  ****************
   PrePostHashFixer is class polymorphism that heiress from:
            ----> PrePostDollarFixer---->PrePostFixer---> DefaultTextFormatter  ---> TextFormatter

  the class overrides  (virtual method):
            print(long num, char symbol = DEFAULT_SYMBOL) const;
            getDefaultSymbol()

*************************************************************/



typedef struct PrePostHashFixer{
    /* heiress from  PrePostDollarFixer*/
    PrePostDollarFixer prePostDollarFixer;

    /*static const char DEFAULT_SYMBOL = '#';---->literal*/

    int precision;
}PrePostHashFixer;

/******method of PrePostHashFixer*******/
void __PrePostHashFixer_CTOR_p__(PrePostHashFixer *const this);
void __PrePostHashFixer_CTOR_p_i__(PrePostHashFixer *const this, int prc);
void __PrePostHashFixer_DTOR_p__(PrePostHashFixer *const this);


void __v_print__PrePostHashFixer_p_l_c__(const PrePostHashFixer *const this,long num,char symbol);/*override*/
void __v_print__PrePostHashFixer_p_l__(const PrePostHashFixer *const this,long num);/*override*/

char __v_getDefaultSymbol__PrePostHashFixer_p__(const PrePostHashFixer *const this);/*override*/


void __print_PrePostHashFixer_p_i_c__(const PrePostHashFixer *const this,int num, char symbol);
void __print_PrePostHashFixer_p_i__(const PrePostHashFixer *const this,int num);



/****************PrePostFloatDollarFixer ***************
 *  PrePostFloatDollarFixer is class polymorphism that heiress from:
           ----> PrePostDollarFixer---->PrePostFixer---> DefaultTextFormatter  ---> TextFormatter

  the class overrides  (virtual method):
            getDefaultSymbol()

*************************************************************/


typedef struct PrePostFloatDollarFixer
{
    /* heiress from  PrePostDollarFixer*/
    PrePostDollarFixer prePostDollarFixer;
  /*  static const char DEFAULT_SYMBOL = '@';----> literal*/
/*
public:
    PrePostFloatDollarFixer(const char* prefix, const char* postfix);
    ~PrePostFloatDollarFixer();
    void print(float num) const;
    void print(float num, char symbol) const;
    char getDefaultSymbol() const;
    */
}PrePostFloatDollarFixer;

/******method of PrePostFloatDollarFixer*******/


void __PrePostFloatDollarFixer_CTOR_p_cc_cc__(PrePostFloatDollarFixer *const this, const char* prefix, const char* postfix);
void __PrePostFloatDollarFixer_DTOR_p__(PrePostFloatDollarFixer *const this);
void __print_PrePostFloatDollarFixer_f__(const PrePostFloatDollarFixer *const this,float num);
void __print_PrePostFloatDollarFixer_f_c__(const PrePostFloatDollarFixer *const this,float num, char symbol);
char __v_getDefaultSymbol__PrePostFloatDollarFixer_p__(const PrePostFloatDollarFixer *const this);/*override*/

#endif /*CPP_UTH_ENCAPSULATION_SHOAMCO_CPP2C_POLYMORPHISM_DEFS_H*/
