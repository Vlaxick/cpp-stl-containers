#include <iostream>
#include <string>

class Item {
    private:
    int id;
    double value;
    std::string name;
    public:
    Item(int id, double value, std::string name) : id(id), value(value), name(name) {}
    Item() : id(0), value(0.0), name("") {}
    ~Item() {}
    bool operator<(const Item& other) const {
        return this->value < other.value;
    }
    friend std::ostream& operator<<(std::ostream& os, const Item& item) {
        os << "Item{id: " << item.id << ", value: " << item.value << ", name: " << item.name << "}";
        return os;
    }
    bool operator==(const Item& other) const {
        return this->id == other.id && this->value == other.value && this->name == other.name;
    }
    int getId () const {
        return id;
    }
    double getValue() const {
        return value;
    }
    std::string getName() const {
        return name;
    }
};