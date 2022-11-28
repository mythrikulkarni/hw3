#include "Thing.h"

Thing::Thing(std::string thing){
    this->thing = thing;
}

Thing::Thing(){
    this->thing = "";
} //default constructor

void Thing::setThing(std::string thing){
    this->thing = thing;
}

std::string Thing::getThing(){
    return thing;
}

Json::Value Thing::dump2JSON(){
    Json::Value result {};
    if(thing != ""){
        result["item"] = thing;
    }

    return result;
}
bool Thing::JSON2Object(Json::Value arg_jv) {
  if ((arg_jv.isNull() == true) ||
      (arg_jv.isObject() != true))
    {
      return false;
    }

  if (((arg_jv["item"]).isNull() == true) ||
      ((arg_jv["item"]).isString() != true))
    {
      return false;
  }
    this->thing = (arg_jv["item"]).asString();
    return true;
}