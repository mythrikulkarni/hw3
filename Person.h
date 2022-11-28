#include <string>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

class Person{
    private:
        std::string name;

    public:
        Person(std::string);
        Person(); //default constructor
        void setName(std::string);
        std::string getName();
        Json::Value dump2JSON();
        bool JSON2Object(Json::Value);  
};
