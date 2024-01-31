#ifndef COMPOSITE_H
#define COMPOSITE_H


#define Watt double
#define Currency float


class Equipment{

public:
    virtual ~Equipment();

    const char* Name() {return _name;}

    virtual Watt Power();
    virtual Currency NetPrice();
    virtual Currency DiscountPrice();

    virtual void Add(Equipment*);
    virtual void Remove(Equipment*);
    virtual Iterator<Equipment*>* CreateIterator();


protected:
    Equipment(const char*);

private:
    const char* _name;


};


#endif