#ifndef STUDENT_H
#define STUDENT_H

class Student
{
  public:
    Student(string="unknown", string = "unknown", int=000000000, string="unknown@carleton.ca", string="", int=0, int=0, int=0);
    ~Student();
    string getFirstName();

    string getLastName();

    string getName();

    int getNum();

    string getEmail();

    string getMajor();

    int getYear();

    int getCGPA();

    int getMGPA();

    void setFirstName(string);

    void setLastName(string);

    void setNum(int);

    void setEmail(string);

    void setMajor(string);

    void setYear(int);

    void setCGPA(int);

    void setMGPA(int);

    bool canSetMGPA(string);

    bool canSetCGPA(string);

    bool canSetEmail(string);

    bool canSetYear(string);

    bool canSetMajor(string);

    bool canSetStudentNumber(string);

    bool canSetFirstName(string);

    bool canSetLastName(string);

  private:

    int number;
    string firstName;
    string lastName;
    string email;
    string sMajor;
    int yearStanding;
    int cgpa;
    int mgpa;

};


#endif


