/****************************************************
 File Name: Graders
 
 Author: Jonathan Gonzalez
 Date: Feb 9 , 2015
 Problem Number: 2
 CS 2308 Spring 2015
 Instructor: Priebe
 
 The program will grade a series of exams and then print
 a grade report for students in a course.
 *****************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// function prototypes
int gradeExams(string key, string answers, int numOfQs);
int findNumOfStudents(int numOfQs, int scoreTracker[]);
int findBiggestScore(int numOfQs, int scoreTracker[]);
int findLowestScore(int numOfQs, int scoreTracker[]);
double findAverageScore(int numOfQs, int scoreTracker[]);

/****************************************************
 Function used to gather data from all functions. Opens
 and Reads in data. Writes data to file created within the function.
 *****************************************************/

int main()
{
   string key;
   string answers;
   int numOfQs;
   int finalGrade;
   
   ifstream inFile;
   inFile.open("grade_data.txt");
   
   ofstream outFile;
   outFile.open("grade_report.txt");
   
   inFile >> key;
   numOfQs = key.length(); // Gets number of Questions from answer key;
   
   
   int scoreTracker[numOfQs];
   for (int i = 0; i <= numOfQs; i++)
      scoreTracker[i] = 0; // Sets scoreTracker array to 0;
   
   while (inFile >> answers)
   {
      finalGrade = gradeExams(key, answers, numOfQs);
      outFile << "Student " << findNumOfStudents(numOfQs, scoreTracker) + 1 << " - "<<  finalGrade << endl;
      scoreTracker[finalGrade]++;
   }
   
   outFile << endl;
   outFile << "Final Report" << "\n" << "------------" << endl;
   for (int i = numOfQs; i >= 0; i--)
      outFile << i << " ---- "<<scoreTracker[i] << endl;
   
   outFile << "\n" << "Highest Score - " << findBiggestScore(numOfQs, scoreTracker) << endl;
   
   outFile << "\n" << "Lowest Score - " << findLowestScore(numOfQs, scoreTracker) << endl;
   
   outFile << fixed << showpoint << setprecision(2); // Rounds output to two decimal points;
   outFile << "\n" << "Mean Score - " << findAverageScore(numOfQs, scoreTracker) << endl;
   
}
/****************************************************
 Function grades exams from input file. Parameters Key 
 and answers are the answers provide from inputfile. 
 Parameter numOfQs is passed to compare each of the key
 and answer questions.
 ****************************************************/

int gradeExams(string key, string answers, int numOfQs)
   {
      int grade = 0;
      for (int i = 0; i < numOfQs; i++)
         if( key[i] == answers[i] )
            grade++;
      return grade;
   }

/****************************************************
 Function finds the number of students that have taken
 the exam. Parameter numOfQs is used to go through the 
 scoreTracker array, which then adds up all students.
 ****************************************************/

int findNumOfStudents(int numOfQs, int scoreTracker[])
{
   int numOfStudents = 0;
   for (int i = 0; i <= numOfQs; i++)
      numOfStudents += scoreTracker[i];
   
   return numOfStudents;
}

/****************************************************
 Function finds the highest number of questions answered 
 correctly from all exams. Parameter numOfQs is used to go 
 through the scoreTracker array, which then finds the highest score.
 ****************************************************/

int findBiggestScore(int numOfQs, int scoreTracker[])
{
   int biggest = 0;
   for (int i = 0; i <= numOfQs; i++)
      if (scoreTracker[i] >= 1)
         biggest = i ;
   
   return biggest;
}

/****************************************************
 Function finds the lowest number of questions answered
 correctly from all exams. Parameter numOfQs is used to go
 through the scoreTracker array, which then finds the lowest score.
 ****************************************************/

int findLowestScore(int numOfQs, int scoreTracker[])
{
   int smallest = numOfQs;
   for (int i = numOfQs; i >= 0; i--)
      if (scoreTracker[i] >= 1)
         smallest = i ;
   
   return smallest;
}

/****************************************************
 Function finds the average number of questions answered
 correctly from all exams. Parameter numOfQs is used to go
 through the scoreTracker array, which then finds the average 
 of all exams.
 ****************************************************/

double findAverageScore(int numOfQs, int scoreTracker[])
{
   double average;
   double sumOfScores = 0;

   for (int i = 0; i <= numOfQs; i++)
      sumOfScores += (scoreTracker[i] * i);
   // findNumOfStudents is called to calculate average.
   average = sumOfScores / findNumOfStudents(numOfQs, scoreTracker);

   return average;
}


