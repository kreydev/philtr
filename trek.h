#ifndef _TREK_H_
#define _TREK_H_

#include <string>
#include <vector>
#include "attr.h"

class Trek {
private:
    uint id;
    std::string diff;
    std::vector<Attr> attrs;
    std::vector<std::string> activ;
public:
    Trek(uint _id) : id(_id) {};
    Trek(uint _id, const std::string& _diff, const std::vector<Attr>& _attrs) : id(_id), diff(_diff), attrs(_attrs) {};
    void SetDiff(const std::string& _diff) {diff = _diff;}
    void AddAttr(const Attr& _attr) {attrs.push_back(_attr);}
    void AddActiv(const std::string _activ) {activ.push_back(_activ);}
};

#endif
