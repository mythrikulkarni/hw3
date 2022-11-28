#include "Time.h"

Time::Time(std::string time){
    this->time = time;
}
Time::Time(){
    this->time = "";
} //default constructor
void Time::setTime(std::string time){
    this->time = time;
}
std::string Time::getTime(){
    return time;
}
Json::Value Time::dump2JSON(){  
    Json::Value result {};
    if(time != ""){
        result["order"] = time; //not a specific time, just the chronological order of events
    }

    return result;
}
bool Time::JSON2Object(Json::Value arg_jv) {
  if ((arg_jv.isNull() == true) ||
      (arg_jv.isObject() != true))
    {
      return false;
    }

  if (((arg_jv["order"]).isNull() == true) ||
      ((arg_jv["order"]).isString() != true))
    {
      return false;
  }
    this->time = (arg_jv["order"]).asString();
    return true;
}