#ifndef APPLICATION_H
#define APPLICATION_H
using namespace std;
#include <string>
#include "Student.h"
#include "CourseRelatedQueue.h"
#include "TaCourseQueue.h"
#include "WorkExpQueue.h"

class Application{

	public:
		Application (string = "", string = "", Student* = 0, int = 0, CourseRelatedQueue* = 0, TaCourseQueue* = 0, WorkExpQueue* = 0);
		~Application();

		int AppNum ();
		string getApplicationNumber();
		string getCourse();
		string getStatus();
		string getStudentFirstName();
		int getApplicationNumberInt();
		string getStudentLastName();
		string getStudentNum();
		string getStudentEmail();
		int getStudentType();
		Student* getStudent();
		string getStudentTypeString();
		CourseRelatedQueue *getCourseRelated();
		TaCourseQueue *getTaCourse();
		WorkExpQueue *getWorkExp();
		
	private:
		int applicationNum;
		string course;
		string status;
		int studentType;

		Student* student;
		CourseRelatedQueue* CRHead;
		TaCourseQueue* TCHead;
		WorkExpQueue* WEHead;

};

#endif
