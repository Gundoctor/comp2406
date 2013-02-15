#ifndef CR_H
#define CR_H
#include <string>
class TaCourse
{
  public:
    TaCourse(std::string = "", std::string = "", int = 0, int = 0);
    ~TaCourse();
    std::string getCourseCode();
    std::string print();
    bool canSetCourseCode(std::string);
    bool canSetTerm(std::string);
    bool canSetYear(std::string);
    bool canSetSupervisor(std::string);

  private:

    std::string courseCode;
    std::string term;
    int year;
    string supervisor;

};
#endif