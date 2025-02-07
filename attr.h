#ifndef _ATTR_H_
#define _ATTR_H_

#include <string>

class Attr {
private:
    std::string name;
    int num;
public:
    Attr(const std::string& _name, int _num = 0) : name(_name), num(_num) {};
    std::string GetName() const {return name;}
    int GetNum() const {return num;}
    void SetNum(const int _num) {num=_num;}
};

#endif