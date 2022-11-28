#include <string>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

class Time{
    private:
        std::string time;

    public:
        Time(std::string);
        Time(); //default constructor
        void setTime(std::string);
        std::string getTime();
        Json::Value dump2JSON();
        bool JSON2Object(Json::Value);
};
