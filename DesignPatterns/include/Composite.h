#ifndef COMPOSITE_H
#define COMPOSITE_H


#define Watt double
#define Currency float

#include <vector>
// #include <iterator>

template <typename T>
class Iterator {
public:

    virtual bool HasNext() const = 0;
    virtual T* Next() = 0;
};

class Equipment {
public:
    virtual ~Equipment();

    const char* Name() const { return _name; }

    virtual Watt Power() = 0;
    virtual Currency NetPrice() = 0;
    virtual Currency DiscountPrice() = 0;

    virtual void Add(Equipment*);
    virtual void Remove(Equipment*);
    virtual Iterator<Equipment*>* CreateIterator() = 0;

protected:
    Equipment(const char*);

private:
    const char* _name;
};


class FloppyDisk : public Equipment {
public:
    FloppyDisk(const char*);
    virtual ~FloppyDisk();
    
    virtual Watt Power();

    virtual Currency NetPrice();
    virtual Currency DiscountPrice();
};


class CompositeEquipment : public Equipment {
public:

    virtual ~CompositeEquipment();

    virtual Watt Power();

    virtual Currency NetPrice();
    virtual Currency DiscountPrice();

    virtual void Add(Equipment*);
    virtual void Remove(Equipment*);
    virtual Iterator<Equipment*>* CreateIterator();

protected:
    CompositeEquipment(const char*);

private:
    std::vector<Equipment*> _equipment;

};

#endif