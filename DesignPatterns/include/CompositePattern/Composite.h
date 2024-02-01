#ifndef COMPOSITE_H
#define COMPOSITE_H


#include <vector>

class Equipment {
public:
    Equipment(const char* name);
    
    const char* Name();
    
    virtual int Power();
    virtual double NetPrice();
    virtual double DiscountPrice();
    
    virtual void Add(Equipment* equipment) {}
    virtual void Remove(Equipment* equipment) {}
    virtual std::vector<Equipment*> CreateIterator() { return {}; }

protected:
    const char* _name;
};

class FloppyDisk : public Equipment {
public:
    FloppyDisk(const char* name);
    
    virtual int Power() override;
    virtual double NetPrice() override;
    virtual double DiscountPrice() override;
};

class CompositeEquipment : public Equipment {
public:
    CompositeEquipment(const char* name);
    virtual ~CompositeEquipment();
    
    virtual int Power() override;
    
    virtual double NetPrice() override;
    
    virtual double DiscountPrice() override;
    
    virtual void Add(Equipment* equipment) override;
    
    virtual void Remove(Equipment* equipment) override { }
    
    virtual std::vector<Equipment*> CreateIterator() override;

private:
    std::vector<Equipment*> _equipment;
};


class Chassis : public CompositeEquipment {
public:
    Chassis(const char* name);
    
    virtual int Power() override;
};

#endif