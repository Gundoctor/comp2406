#include "PendingApps.h"
using namespace std;

PendingApps::PendingApps(ApplicationQueue **aq) : index(0), nBreaker(0), choosePage(0), onePage(0),
                                                  applications(aq)
{

}

PendingApps::~PendingApps()
{
}

////////////////////////////////////////////////////////////
//<summary> Update the screen based on what's supposed    //
//          to be drawn </summary>                        //
////////////////////////////////////////////////////////////
int PendingApps::update()
{
  int n = index;
  int result;

  switch(n)
  {
    case 0:
      choosePage = new PendingChoose();
      result = choosePage -> initPendChoose();
      delete choosePage;
      
      if (result > 2) nBreaker = 50;
      else index = result;
      
      break;
    case 1: //For one course
      onePage = new PendingOneCourse(applications);
      onePage -> initPendOCourse();
      delete onePage;

      mvprintw(LINES - 2, 0, "Football is a sport");
      getch();

      nBreaker = index; //temp kill
      break;

    case 2:
      nBreaker = index; //temp kill
      break;
    default:
      break;
  }
}


////////////////////////////////////////////////////////////
//<summary> Creates the form                    </summary>//
////////////////////////////////////////////////////////////  
void PendingApps::initPendApps()
{
  clear();

  while(1)
  { 
    update();

    if(nBreaker != 0)
      break;
  }
  
  noecho();
  clear();

  mvprintw(LINES - 1, 0, "It really is, I promise");
  getch();
}
