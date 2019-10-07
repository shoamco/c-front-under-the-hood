

#ifndef CPP_UTH_ENCAPSULATION_SHOAMCO_CPP2C_POLYMORPHISM_DEFS_H
#define CPP_UTH_ENCAPSULATION_SHOAMCO_CPP2C_POLYMORPHISM_DEFS_H




#include <stdio.h>


typedef enum {
    false = 0,
    true = 1
} Bool;
/*typedef void (*vptr)();*/


/*vptr g_virtual_tables_TextFormatter[2];*/

/*// TextFormatter ///////////*/

typedef struct TextFormatter
{
/*
 *  virtual ~TextFormatter() { }; -->add to virtual table
    virtual void print(const char* text) const = 0;--->pure virtual
    */

}TextFormatter;
void __v_TextFormatter_DTOR_p__(TextFormatter *const this);
/*/// DefaultTextFormatter ////////////*/
extern int next_id;/*static variable -> global */
typedef struct Ider Ider;
typedef struct DefaultTextFormatter
{
   /* inheritance  TextFormatter*/

    struct Ider
    {
   /* private:
        static int next_id;/*global
    public:
        static int getId() { return next_id++; }
        */
    };
    int id;

}DefaultTextFormatter;
void   __DefaultTextFormatter_CTOR_p__(DefaultTextFormatter *const this);
void __DefaultTextFormatter_copy_CTOR_p__(DefaultTextFormatter *const this,const DefaultTextFormatter const*other);
void __v_DefaultTextFormatter_DTOR_p__(DefaultTextFormatter *const this);
void __v_print__DefaultTextFormatter_p_cc__(const DefaultTextFormatter *const this,const char* text);
DefaultTextFormatter __DefaultTextFormatter_Assignment_p_p__(DefaultTextFormatter *const this,const DefaultTextFormatter const*other);


typedef struct PrePostFixer
{
    /* inheritance  DefaultTextFormatter*/

    const char* pre;
    const char* post;
}PrePostFixer;
void  __PrePostFixer_CTOR_p_cc_cc__(PrePostFixer *const this,const char* prefix, const char* postfix);

void __v_PrePostFixer_DTOR_p__(PrePostFixer *const this);
void __v_print__PrePostFixer_p_cc__(const PrePostFixer *const this,const char* text);
void __v_print__PrePostFixer_p_l__(const PrePostFixer *const this,long num);
/*
inline void printFunc(const char* fname)
{
    printf("%-60s | ", fname);
}

//// TextFormatter ////////////

class TextFormatter
{
public:
    virtual ~TextFormatter() { };
    virtual void print(const char* text) const = 0;
};

//// DefaultTextFormatter ////////////

class DefaultTextFormatter: public TextFormatter
{
public:
    DefaultTextFormatter();
    DefaultTextFormatter(const DefaultTextFormatter&);
    DefaultTextFormatter& operator=(const DefaultTextFormatter&);
    ~DefaultTextFormatter();

    virtual void print(const char* text) const;

private:
    class Ider
    {
    private:
        static int next_id;
    public:
        static int getId() { return next_id++; }
    };

    const int id;
};

DefaultTextFormatter* generateFormatterArray();


//// PrePostFixer ////////////

class PrePostFixer: public DefaultTextFormatter
{
public:
    PrePostFixer(const char* prefix, const char* postfix);
    ~PrePostFixer();

    virtual void print(const char* text) const;
    virtual void print(long num, char symbol = '\0') const;

    virtual char getDefaultSymbol() const;

protected:
    const char* getPrefix() const;
    const char* getPostfix() const;

private:
    void print_num(long num) const;
    void print_num(long num, char symbol) const;

    const char* pre;
    const char* post;
};

//// PrePostFixer Defs ////////////

inline const char* PrePostFixer::getPrefix() const
{
    return pre;
}

inline const char* PrePostFixer::getPostfix() const
{
    return post;
}

inline char PrePostFixer::getDefaultSymbol() const
{
    return '\0';
}

inline void PrePostFixer::print(long num, char symbol) const
{
    printFunc("[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol)
        print_num(num, symbol);
    else
        print_num(num);
}

inline void PrePostFixer::print_num(long num) const
{
    printFunc("[PrePostFixer::print_num(long)]");
    printf("%s%ld%s\n", pre, num, post);
}

inline void PrePostFixer::print_num(long num, char symbol) const
{
    printFunc("[PrePostFixer::print_num(long, char)]");
    printf("%s%c%ld%s\n", pre, symbol, num, post);
}


//// PrePostDollarFixer ////////////

class PrePostDollarFixer: public PrePostFixer
{
protected:
    static const char DEFAULT_SYMBOL = '$';

public:
    PrePostDollarFixer(const char* prefix, const char* postfix);
    PrePostDollarFixer(const PrePostDollarFixer& other);
    ~PrePostDollarFixer();

    void print(int num, char symbol = DEFAULT_SYMBOL) const;
    void print(long num, char symbol = DEFAULT_SYMBOL) const;
    void print(double num, char symbol = DEFAULT_SYMBOL) const;
    char getDefaultSymbol() const;
};

//// PrePostDollarFixer Defs ////////////

inline char PrePostDollarFixer::getDefaultSymbol() const
{
    return DEFAULT_SYMBOL;
}

//// PrePostHashFixer ////////////

class PrePostHashFixer: public PrePostDollarFixer
{
private:
    static const char DEFAULT_SYMBOL = '#';
public:
    PrePostHashFixer(int prc = 4);
    ~PrePostHashFixer();

    void print(int num, char symbol = DEFAULT_SYMBOL) const;
    void print(long num, char symbol = DEFAULT_SYMBOL) const;
    void print(double num, char symbol = DEFAULT_SYMBOL) const;
    char getDefaultSymbol() const;

private:
    int precision;
};

//// PrePostHashFixer Defs ////////////

inline void PrePostHashFixer::print(double num, char symbol) const
{
    printFunc("[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", getPrefix(), symbol, precision, num, getPostfix());
}

inline char PrePostHashFixer::getDefaultSymbol() const
{
    return DEFAULT_SYMBOL;
}


//// PrePostFloatDollarFixer ////////////

class PrePostFloatDollarFixer: public PrePostDollarFixer
{
protected:
    static const char DEFAULT_SYMBOL = '@';

public:
    PrePostFloatDollarFixer(const char* prefix, const char* postfix);
    ~PrePostFloatDollarFixer();
    void print(float num) const;
    void print(float num, char symbol) const;
    char getDefaultSymbol() const;
};

//// PrePostFloatDollarFixer Defs ////////////

inline char PrePostFloatDollarFixer::getDefaultSymbol() const
{
    return DEFAULT_SYMBOL;
}

//// PrePostChecker ////////////

class PrePostChecker: public PrePostFloatDollarFixer
{
public:
    PrePostChecker();
    ~PrePostChecker();

    void printThisSymbolUsingFunc() const;
    void printThisSymbolDirectly() const;
    void printDollarSymbolByCastUsingFunc() const;
    void printDollarSymbolByScopeUsingFunc() const;
    void printDollarSymbolByCastDirectly() const;
    void printDollarSymbolByScopeDirectly() const;
};


//// Multiplier ////////////

class Multiplier: public DefaultTextFormatter
{
public:
    Multiplier(int t = 2);
    ~Multiplier();

    void print(const char*) const;
    int getTimes() const;
    void setTimes(int);
private:
    int times;
};

//// Multiplier Defs ////////////

inline Multiplier::Multiplier(int t)
        :   times(t)
{
    printf("--- Multiplier CTOR: times = %d\n", times);
}

inline Multiplier::~Multiplier()
{
    printf("--- Multiplier DTOR: times = %d\n", times);
}

inline int Multiplier::getTimes() const
{
    return times;
}

inline void Multiplier::setTimes(int t)
{
    times = t;
}



*/

#endif /*CPP_UTH_ENCAPSULATION_SHOAMCO_CPP2C_POLYMORPHISM_DEFS_H*/
