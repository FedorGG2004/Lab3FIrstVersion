#pragma once

#include <iostream>
#include <ostream>
#include <utility>
#include <vector>
#include "bases.h"


enum class CurType {
    INT,
    SHORT,
    BOOL
};

class Value {
    CurType m_type = CurType::INT;
    int m_value = 0;

public:

    CurType type() const { return m_type; }
    void setType(CurType type) { m_type = type; }

    BoolBase BoolValue() const {
        if (m_value < 0)
            return BoolBase::FALSE;
        else if(m_value > 0)
            return BoolBase::TRUE;
        else
            return BoolBase::UNDEF;
    }

//  CTORS

    Value() {}

//  int
    Value(int new_value) : m_type(CurType::INT), m_value(new_value) {}

    Value(short new_value) : m_type(CurType::SHORT), m_value(new_value) {}

    Value(bool new_value) : m_type(CurType::BOOL) {
        if(new_value == true){
            m_value = 1;
        }else if(new_value == false){
            m_value = -1;
        }
    }

    // Value(IntBase type) : m_type(CurType::INT), m_int(type) {}

//  bool
    Value(BoolBase type) : m_type(CurType::BOOL) {
        if (type == BoolBase::TRUE) {
            m_value = 1;
        }
        else if(type == BoolBase::FALSE){
            m_value = -1;
        }
        else{
            m_value = 0;
        }
    }

//  operators

    Value operator+(const Value& other) const {
        return m_value + other.m_value;
    }

    void operator+=(const Value& other) {
        m_value += other.m_value;
    }

    Value operator-(const Value& other) const {
        return m_value - other.m_value;
    }

    Value operator-() {
        return -m_value;
    }

    bool operator>(const Value& other) const {
        return m_value > other.m_value;
    }

    bool operator<(const Value& other) const {
        return m_value < other.m_value;
    }

    bool operator==(const Value& other) const {
        return m_value == other.m_value;
    }

    friend std::ostream& operator<<(std::ostream& os, const Value& integer)  {
        
        switch (integer.m_type) {
            case CurType::INT:
                os << integer.m_value; 
            break;
            case CurType::SHORT:
                os << integer.m_value; 
            break;
            case CurType::BOOL:
                if(integer.m_value > 0)
                    os << "true";
                else if(integer.m_value < 0)
                    os << "false";
                else
                    os << "undef";
        }
        return os; 
    }

};


class GenericType {
    std::vector<Value> m_base;
    CurType m_type;
    bool is_return = 0;
    int size = 0;

public:
    void setRet() { is_return = 1; }
    bool getRet() const{ return is_return;}
    void setSize(int s) { size = s; }
    bool getSize() const{ return size;}

    GenericType() {}
    GenericType(Value first) {
        m_base.push_back(first);
        m_type = first.type();
    }
    GenericType(CurType type) : m_type(type) {}
    CurType getType() const {
        return m_type;
    }
    void printType(std::string name){
        switch (m_type) {
            case CurType::INT:
                std::cout << name << " size: 4" << std::endl; 
            break;
            case CurType::SHORT:
                std::cout << name << " size: 2" << std::endl; 
            break;
            case CurType::BOOL:
                std::cout << name << " size: 1" << std::endl; 
        }
    }
    
    void setType(CurType type) {
        for (auto &e : m_base) {
            e.setType(type);
        }
    }

    BoolBase BoolValue() const {
        if (!m_base.size()) 
            return BoolBase::FALSE;
        if (m_base.size() > 1)
            return BoolBase::TRUE;
        
        return m_base[0].BoolValue();
    }

    friend std::ostream& operator<<(std::ostream& os, const GenericType& a)  {
        for (const auto &e : a.m_base) {
            os << e << ' ';
        }
        return os;
    }

    GenericType operator+(const GenericType &other) {
        int size = m_base.size() > other.m_base.size() ? m_base.size() : other.m_base.size();
        GenericType new_vec;
        new_vec = other;
        for (int i = 0; i < m_base.size(); i++) {
            new_vec.m_base[i] += m_base.at(i);
        }

        return new_vec;
    }

    GenericType operator-() const {
        GenericType new_vec = *this;
        for (auto &e : new_vec.m_base) {
            e = -e;
        }
        return new_vec;
    }

    GenericType operator-(const GenericType &other) {
        return *this + -other;
    }

    GenericType operator==(const GenericType &other) {
        return Value(this->m_base == other.m_base);
    }

    GenericType operator>(const GenericType &other) {
        return Value(this->m_base > other.m_base);
    }

    GenericType operator<(const GenericType &other) {
        return Value(this->m_base < other.m_base);
    }
    Value operator[](int i) {
        return this->m_base[i];
    }

};


/*    BoolBase CellToBool (CellBase val) {
        switch (val) {
            case CellBase::EXIT:
            case CellBase::EMPTY:
                return BoolBase::TRUE;
            case CellBase::WALL:
            case CellBase::BOX:
                return BoolBase::FALSE;
            default:
                return BoolBase::UNDEF;
        }
    }*/

    //  Bool to Cell - semantic error!

