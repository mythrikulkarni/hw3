#include "Record.h"
#include <iostream>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string.h>
#include "ecs36b_Common.h"
#include "ecs36b_JSON.cpp"
#include "JvTime.h"

void recordNumbers(int recordNum);
void formatRecords();

int main(){
    Person Red{"Little Red Riding Hood"};
    Person Mom{"Mother"};
    Person Wolf{"Wolf"};
    Person Gma{"Grandma"};
    Person alone{}; // plug in "alone" when there is no second person, will return null

    Thing cap{"Red velvet cap"};
    Thing cake{"cake"};
    Thing wine{"wine"};
    Thing none{}; // plug in "none" when there is no second thing, will return null

    Location wood{"In the woods"};
    Location tree{"Grandma's home near three oak trees"};
    Location village{"In the village"};

    Time first{"Event 1"};
    Time second{"Event 2"};
    Time third{"Event 3"};
    Time fourth{"Event 4"};

    Record one{Red, alone, cap, none, village, first}; //Little Red Riding Hood wore the cap

    Record two{Mom, Red, cake, wine, village, second}; //Her mom gave her the cake and wine

    Record three{Red, Wolf, none, none, wood, fourth}; //Little Red met the Wolf at a particular spot in the woods

    Record four{Gma, alone, none, none, tree, third};  //Grandma was at her own home right outside of the wood and there were 3 large oak trees nearby
        // [assuming fourth record occurs before third record] - "Grandma was at her house before Little Red met with the Wolf"

    //formatRecords();
    //recordNumbers(1);
    std::cout << (one.dump2JSON()).toStyledString();    //Record 1
    //formatRecords();
    //recordNumbers(2);
    std::cout << (two.dump2JSON()).toStyledString();    //Record 2
    //formatRecords();
    //recordNumbers(3);
    std::cout << (three.dump2JSON()).toStyledString();  //Record 3
    //formatRecords();
    //recordNumbers(4);
    std::cout << (four.dump2JSON()).toStyledString();   //Record 4
    formatRecords();
    
    int rc;
    char name_buf[256];
    bzero(name_buf, 256);
    sprintf(name_buf, "./%s.json", "Record1");
    Json::Value Record1 = one.dump2JSON();
    char name_buf2[256];
    bzero(name_buf2, 256);
    sprintf(name_buf2, "./%s.json", "Record2");
    Json::Value Record2 = two.dump2JSON();
    char name_buf3[256];
    bzero(name_buf3, 256);
    sprintf(name_buf3, "./%s.json", "Record3");
    Json::Value Record3 = three.dump2JSON();
    char name_buf4[256];
    bzero(name_buf4, 256);
    sprintf(name_buf4, "./%s.json", "Record4");
    Json::Value Record4 = four.dump2JSON();
    myJSON2File(name_buf, &Record1);
    myJSON2File(name_buf2, &Record2);
    myJSON2File(name_buf3, &Record3);
    myJSON2File(name_buf4, &Record4);
    //Create four new Json::Value objects
    Json::Value newFirst;
    Json::Value newSecond;
    Json::Value newThird;
    Json::Value newFourth;
    //Takes the content of file, converts them to JSON and stores them in the four
    //Json::Value objects that were previously created
    myFile2JSON(name_buf, &newFirst);
    myFile2JSON(name_buf2, &newSecond);
    myFile2JSON(name_buf3, &newThird);
    myFile2JSON(name_buf4, &newFourth);
    //Create four blank record objects
    Record firstEvent;
    Record secondEvent;
    Record thirdEvent;
    Record fourthEvent;
    //Filling in the empty record objects
    firstEvent.JSON2Object(newFirst);
    secondEvent.JSON2Object(newSecond);
    thirdEvent.JSON2Object(newThird);
    fourthEvent.JSON2Object(newFourth);
    //Printing the JSON dump of the four new records
    std::cout << "First Record from file" << std::endl;
    std::cout << (firstEvent.dump2JSON()).toStyledString() << std::endl;
    std::cout << "Second Record from file" << std::endl;
    std::cout << (secondEvent.dump2JSON()).toStyledString() << std::endl;
    std::cout << "Third Record from file" << std::endl;
    std::cout << (thirdEvent.dump2JSON()).toStyledString() << std::endl;
    std::cout << "Fourth Record from file" << std::endl;
    std::cout << (fourthEvent.dump2JSON()).toStyledString() << std::endl;


}
void recordNumbers(int recordNum) {     //title & number of each record
    std::cout << "-----------------------------Record "<<recordNum<<"-----------------------------"<< std::endl;
    return;
}

void formatRecords() {  //puts a line above each record to differentiate
    std::cout <<"------------------------------------------------------------------"<<std::endl;
    return;
}