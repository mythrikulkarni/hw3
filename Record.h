#include "Person.h"
#include "Thing.h"
#include "Location.h"
#include "Time.h"

class Record{
    private:
        Person person;
        Person person2;
        Thing thing;
        Thing thing2;
        Location location;
        Time time;

    public:
        Record(Person, Person, Thing, Thing, Location, Time);
        Record();
        void setPerson(Person);
        void setPerson2(Person);    // second person
        void setThing(Thing);
        void setThing2(Thing);      // second thing
        void setLocation(Location);
        void setTime(Time);
        
        Person getPerson();
        Person getPerson2();        //second person
        Thing getThing();
        Thing getThing2();          // second thing
        Location getLocation();
        Time getTime();

        Json::Value dump2JSON(); // (no change)
        bool JSON2Object(Json::Value);
};
