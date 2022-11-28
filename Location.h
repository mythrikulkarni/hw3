#include <string>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

class Location{
    private:
        std::string location;

    public:
        Location(std::string);
        Location(); //default constructor
        void setLocation(std::string);
        std::string getLocation();
        Json::Value dump2JSON();
        bool JSON2Object(Json::Value);
};