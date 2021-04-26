//Dr. Tyson McMillan a Soccer Scoreboard using 
//Object Oriented Programming in C++
//Updates 4-21-2021 - Dr_T
//Dr_T teaching Object Oriented Scoreboard in C++ 
//Cameron Johnston Scoreboard Assignment

#include <iostream>
#include <string> 
#include <unistd.h>
#include <iomanip>
#include "Input_Validation_Extended.h"
using namespace std; 

class Team 
{
  private:
    int score; 
    bool homeStatus; 
    string name; 
    int shotsOnGoal; 
    string coachName;
    int timeOuts;
    string cityName;
  public:
      Team() //default constructor 
      {
        score = 0; 
        homeStatus = false; //visitor = false, home = true
        name = "DefaultTeamName"; 
        shotsOnGoal = 0; 
        coachName = "Default Coach Name";
        timeOuts = 3;
        cityName = "Default City Name";
      }
      void setScore(int s) { score = s; }
      void setHomeStatus(bool hs) { homeStatus = hs; }
      void setName(string n) { name = n; }
      void setShotsOnGoal(int sog) { shotsOnGoal = sog; }
      void setCoachName(string sCN) {coachName = sCN; }
      void setCityName(string cName) {cityName = cName;}
      void setTimeOuts(int tOuts) {timeOuts = tOuts;}
      int getScore() const { return score; }
      bool getHomeStatus() const { return homeStatus; }
      string getName() const { return name; }
      int getShotsOnGoal() const { return shotsOnGoal; }
      string getCoachName() const {return coachName; }
      string getCityName() const {return cityName;}
      int getTimeOuts() { return timeOuts; }
      

};

class Scoreboard
{
  private:
    int half; 
    Team home; //object that is a member of another object
    Team visitor; 
  public: 
    Scoreboard()
    {
      half = 0; 
    }  
    void setHalf(int h) { half = h; }
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    int getHalf() const { return half; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    void showScoreboard()
    {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[32;4m"; //green 
      string score = "\x1b[36;1m"; //score color 
      cout << color << "Football Scoreboard by Cameron Johnston" << reset << endl;
      for (int i = 0; i < 50; i++) {cout << "_"; } cout << endl; 

      cout << home.getName() << setw(25) << visitor.getName()<< endl;
 
      cout << score << home.getScore() << setw(25) << visitor.getScore() << endl << reset; 

      cout << home.getCoachName() << setw(25) << visitor.getCoachName() << endl;  
      for (int i = 0; i < 47; i++) {cout << "-"; } cout << endl;

      cout << "Timeouts Left: " << endl;
      if (home.getHomeStatus() == true) {
        cout << home.getTimeOuts() << setw(25) << visitor.getTimeOuts() << endl;
      }
      else if (visitor.getHomeStatus() == true) {
        cout << visitor.getTimeOuts() << setw(25) << home.getTimeOuts() << endl;
      }
      else {
        cout << "Error:" << endl;
      }

      for (int i = 0; i < 47; i++) {cout << "-"; } cout << endl;

      cout << "Home:    - ";
      if (home.getHomeStatus() == true) {
        cout << home.getCityName() << " - " << setw(10) << home.getName();
      }
      else if (visitor.getHomeStatus() == true) {
        cout << visitor.getCityName() << " - " << setw(10) << visitor.getName();
      }
      else {
        cout << "Error:" << endl;
      }

      cout << endl;

      cout << "Visitor: - ";
      if (home.getHomeStatus() == false) {
        cout << home.getCityName() << " - " << setw(10) << home.getName();
      }
      else if (visitor.getHomeStatus() == false) {
        cout << visitor.getCityName() << " - " << setw(10) << visitor.getName();
      }
      else {
        cout << "Error:" << endl;
      }
      cout << endl;
      for (int i = 0; i < 50; i++) {cout << "_"; } cout << endl << endl;
    }
};

int main() 
{
  cout << setw(11);
  Scoreboard s;
  Team tOne;
  Team tTwo; 
  string newName = ""; 
  string userChoice = ""; 
  string newCoachName = "";
  string newCityName = "";
  int newScore = 0; 
  int homeTeamQuestion = 0;
  int newTimeOuts = 0;

  //Set the home team 
  tOne.setHomeStatus(true); //tOne is the Home Team now   

  //add some initial data to s
  s.setHome(tOne); 
  s.setVisitor(tTwo); 

  //Loop this to make it an interactive menu

  do 
  {
      system("clear"); //clear the screen of previous content 
      s.showScoreboard(); //show the current scoreboard data
      //menu choices 
      cout << "Q = Update Home Team Name" << endl; 
      cout << "W = Update Home Team Score" << endl; 
      cout << "E = Update Home Team Coach Name" << endl;
      cout << "R = Update Home Team Timeouts" << endl;
      cout << "T = Update Home Team City Name" << endl;
      cout << "A = Update Visitor Team Name" << endl;
      cout << "S = Update Visitor Team Score" << endl;
      cout << "D = Update Visitor Team Coach Name" << endl;
      cout << "F = Update Visitor City Name" << endl;
      cout << "G = Visitor Team Timeout Used" << endl;
      cout << "H = Update Home Team Designation" << endl;
      cout << "X = Exit" << endl;
      cout << ">"; 
      userChoice = validateString(userChoice);

      if(userChoice == "Q" || userChoice == "q")
      {
        //Dr_T challenge Accept a new name for s's home team
        cout << "****Update Home Team Name Module*** " << endl; 
        cout << "\nPlease enter a new name for the home team: ";
        newName = validateString(newName);
        //change that home team's default name
        tOne.setName(newName); //set tOne's data to the new desired name
      }
      else if(userChoice == "W" || userChoice == "w")
      {
        cout << "\nUpdate Home Score Module****" << endl; 
        cout << "\nPlease enter a new score for the home team: "; 
        newScore = validateInt(newScore); 
        tOne.setScore(newScore);  //set the new score for tOne        
      }
      else if (userChoice == "E" || userChoice == "e") {
        cout << "\nUpdate Home Coach Name****" << endl;
        cout << "\nPlease enter a new coach name for the home team: ";
        newCoachName = validateString(newCoachName);
        tOne.setCoachName(newCoachName);
      }

      else if (userChoice == "R" || userChoice == "r") {
        cout << "\nUpdate Home Team Timeouts Left****" << endl;
        cout << "\nPlease enter how many timeouts the Home Team has left: ";
        newTimeOuts = validateInt(newTimeOuts);
        tOne.setTimeOuts(newTimeOuts);
      }

      else if (userChoice == "T" || userChoice == "t") {
        cout << "\nUpdate Home Team City****" << endl;
        cout << "\nPlease enter Home Team's City Name: ";
        newCityName = validateString(newCityName);
        tOne.setCityName(newCityName);
      }



      else if(userChoice == "A" || userChoice == "a")
      {
        cout << "\nUpdate Visitor Name Module****" << endl; 
        cout << "\nPlease enter a new name for the visitor team: "; 
        newName = validateString(newName); 
        tTwo.setName(newName);
      }

      else if(userChoice == "S" || userChoice == "s")
      {
        cout << "\nUpdate Visitor Score Module****" << endl; 
        cout << "\nPlease enter a new score for the visitor team: "; 
        newScore = validateInt(newScore);
        tTwo.setScore(newScore);  //set the new score for tOne        
      }

      else if (userChoice == "D" || userChoice == "d") {
        cout << "\nUpdate Visitor Coach Name****" << endl;
        cout << "\nPlease enter a new coach name for the visitor team: ";
        newCoachName = validateString(newCoachName);
        tTwo.setCoachName(newCoachName);
      }

      else if (userChoice == "H" || userChoice == "h") {
        cout << "\nUpdate Home Team Designation****" << endl;
        cout << "\nPlease enter which team is the home team: ";
        homeTeamQuestion = validateInt(homeTeamQuestion);
        if(homeTeamQuestion == 1) {
          tOne.setHomeStatus(true);
          tTwo.setHomeStatus(false);
        }
        else if(homeTeamQuestion == 2) {
          tOne.setHomeStatus(false);
          tTwo.setHomeStatus(true);
        }
      }
      else if (userChoice == "F" || userChoice == "f") {
        cout << "\nUpdate Visitor Team City****" << endl;
        cout << "\nPlease enter Visitor Team's City Name: ";
        newCityName = validateString(newCityName);
        tTwo.setCityName(newCityName);
      }

      else if (userChoice == "G" || userChoice == "g") {
        cout << "\nUpdate Visitor Team Timeouts Left****" << endl;
        cout << "\nPlease enter how many timeouts the Visitor Team has left: ";
        newTimeOuts = validateInt(newTimeOuts);
        tTwo.setTimeOuts(newTimeOuts);
      }

      else if(userChoice == "X" || userChoice == "x")
      {
        cout << "Exit chosen." << endl; 
      }
      else //invalid input: default clause
      {
        cout << "\nInvalid input." << endl; 
        sleep(2); //wait two seconds, go to the next process 
      }

      s.setHome(tOne); //refresh the data in s to the new updates...
      s.setVisitor(tTwo);
      
  
  }while(userChoice != "X" && userChoice != "x");


  return 0; 
}