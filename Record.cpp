#include "Record.h"

Record::Record(Person person, Person person2, Thing thing, Thing thing2, Location location, Time time){
    this->person = person;
    this->person2 = person2;
    this->thing = thing;
    this->thing2 = thing2;
    this->location = location;
    this->time = time;
}

Record::Record(){
    this->person = Person();
    this->person2 = Person();
    this->thing = Thing();
    this->thing2 = Thing();
    this->location = Location();
    this->time = Time();
}

//=========================================================

void Record::setPerson(Person person){
    this->person = person;
}
void Record::setPerson2(Person person2) {
    this->person2 = person2;
}
void Record::setThing(Thing thing){
    this->thing = thing;
}
void Record::setThing2(Thing thing2){
    this->thing2 = thing2;
}
void Record::setLocation(Location location){
    this->location = location;
}
void Record::setTime(Time time){
    this->time = time;
}

//=========================================================

Person Record::getPerson(){
    return person;
}
Person Record::getPerson2() {
    return person2;
}
Thing Record::getThing(){
    return thing;
}
Thing Record::getThing2(){
    return thing2;
}
Location Record::getLocation(){
    return location;
}
Time Record::getTime(){
    return time;
}

//=========================================================

Json::Value Record::dump2JSON(){
    Json::Value result {};
    Json::Value jvresult;
    jvresult = person.dump2JSON(); //calls dump2JSON in Person
    result["person"] = jvresult;

    jvresult = person2.dump2JSON(); //calls dump2JSON in Person (for second person object, if there is one)
    result["person 2"] = jvresult;

    jvresult = thing.dump2JSON(); //calls dump2JSON in Thing 
    result["thing"] = jvresult;

    jvresult = thing2.dump2JSON(); //calls dump2JSON in Thing (for second thing object, if there is one)
    result["thing 2"] = jvresult;

    jvresult = location.dump2JSON(); //calls dump2JSON in Location
    result["location"] = jvresult;

    jvresult = time.dump2JSON(); //calls dump2JSON in Time
    result["time"] = jvresult;

    return result;
} // (no change)
bool Record::JSON2Object(Json::Value arg_jv) {
  if ((arg_jv.isNull() == true) ||
      (arg_jv.isObject() != true))
    {
      return false;
    }

  if (((arg_jv["person"]).isNull() == true))
    {
      return false;
    }
  this->person.JSON2Object(arg_jv["person"]);
  this->person2.JSON2Object(arg_jv["person 2"]);

  if (((arg_jv["location"]).isNull() == true))
    {
      return false;
    }

  this->location.JSON2Object(arg_jv["location"]);
  this->thing.JSON2Object(arg_jv["thing"]);
  this->thing2.JSON2Object(arg_jv["thing 2"]);
  if (((arg_jv["time"]).isNull() == true))
   {
     return false;
   }
  this->time.JSON2Object(arg_jv["time"]);
  return true;   
}