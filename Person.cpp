#include "Person.h"
#include "ecs36b_Common.h"

Person::Person(std::string name){
    this->name = name;
}
Person::Person(){
    this->name = "";
} //default constructor
void Person::setName(std::string name){
    this->name = name;
}
std::string Person::getName(){
    return name;
}
Json::Value Person::dump2JSON(){
    Json::Value result;
    if(name != ""){
        result["name"] = this->name;  
    }

    return result;
}
bool Person::JSON2Object(Json::Value arg_jv)
{

  if ((arg_jv.isNull() == true) ||
      (arg_jv.isObject() != true))
    {
      return false;
    }

  if (((arg_jv["name"]).isNull() == true) ||
      ((arg_jv["name"]).isString() != true))
    {
      return false;
  }

  // we allow GPS_DD to be modified (for mobility)
  
  this->name = (arg_jv["name"]).asString();
  return true;
}