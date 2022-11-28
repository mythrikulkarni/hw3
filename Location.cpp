#include "Location.h"

Location::Location(std::string location){
    this->location = location;
}

Location::Location(){
    this->location = "";
} //default constructor

void Location::setLocation(std::string location){
    this->location = location;
}

std::string Location::getLocation(){
    return location;
}

Json::Value Location::dump2JSON(){
    Json::Value result {};
    if(location != ""){
        result["place"] = location;
    }

    return result;
}
bool Location::JSON2Object(Json::Value arg_jv) {
    if ((arg_jv.isNull() == true) ||
      (arg_jv.isObject() != true)) {
      return false;
    }
    if (((arg_jv["place"]).isNull() == true) ||
    ((arg_jv["place"]).isString() != true))
    {
      return false;
    }
    this->location = (arg_jv["place"]).asString();
    return true;
}