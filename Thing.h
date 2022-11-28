#include <string>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

class Thing{
    private:
        std::string thing;

    public:
        Thing(std::string);
        Thing(); //default constructor
        void setThing(std::string);
        std::string getThing();
        Json::Value dump2JSON();
        bool JSON2Object(Json::Value);
};
