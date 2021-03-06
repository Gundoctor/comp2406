#include"CutaesAdminMenu.h"
using namespace std;

CutaesAdminMenu::CutaesAdminMenu(ApplicationQueue **aq) : index(1), nBreaker(0), applications(aq)
{
  applications = aq;

  //WELCOME TO ADMIN MENU
  //PRESS 1 TO VIEW AN APPLICATION
  //PRESS 2 TO ASSIGN A SUCCESSFUL APPLICANT
  //PRESS 3 TO VIEW A SUMMARY OF PENDING APPLICATIONS
  //PRESS 4 TO VIEW A SUMMARY OF ASSIGNED APPLICATIONS
  //PRESS 5 TO VIEW AND EDIT A TA EVALUATION
  //PRESS Q TO QUIT

  labels[0] = "View an Application";
  labels[1] = "Assign a Successful Application";
  labels[2] = "View a Summary of Pending Applications";
  labels[3] = "View A Summary of Assigned Application";
  labels[4] = "View and Edit a TA Evaluation";
  labels[5] = "Back to Main Menu";

}

CutaesAdminMenu::~CutaesAdminMenu()
{

}


////////////////////////////////////////////////////////////////////////////
//<summary> Creates the GUI... draws the labels and textfields  </summary>//
////////////////////////////////////////////////////////////////////////////
void CutaesAdminMenu::drawAdminMenu(int selection)
{
  clear();
  
  mvprintw(5, COLS/3, "----------------------------------------");
  mvprintw(6, COLS/3, "--------       Admin Menu      ---------");
  mvprintw(7, COLS/3, "----------------------------------------");

  int lx, ly, i;
  char c[46];

  ly = 10;
  lx = COLS/ 2 - 18;

  for(i = 0; i < 6; i++) //Draw the options for the Student Menu
  {
    for(int j = 0; j < 45; j++)
    {
      if(j < labels[i].length())
        c[j] = labels[i][j];
      else
        c[j] = 0;
    }
    c[46] = 0;

    if(selection == i + 1)
    {
      attron(A_REVERSE);
      mvprintw(ly, lx, "%s", c);
      refresh();
      attroff(A_REVERSE);
    }
    else
    {
      mvprintw(ly, lx, "%s", c);
      refresh();
    }

    ++ly;
  }

  move(LINES - 2, 0);
}


////////////////////////////////////////////////////////////////////
//<summary> Deal with any character the user might input</summary>//
////////////////////////////////////////////////////////////////////
int CutaesAdminMenu::handleInput(char c)
{
  
  switch(c)
    {
      case (char)KEY_UP: //FOR UP KEY
        if (index == 1)
          index = 1;
        else
          --index;
        break;

      case (char)KEY_LEFT: //FOR LEFT KEY
        if (index == 1)
          index = 1;
        else
          --index;
        break;

      case (char)KEY_RIGHT: //FOR RIGHT KEY
        if (index == 6)
          index = 6;
        else
          ++index;
        break;

      case (char)KEY_DOWN: //FOR DOWN KEY
        if(index == 6)
          index = 6;
        else
          ++index;
        break;

      case (char)KEY_F(2): //FOR F2 KEY, USER WOULD LIKE TO EXIT
        nBreaker = index + 1;
        break;

      case (char)'\r':
        handleSelection(index);
        printw("Enter was presssed\n");
        break;

      default:
        printw("%c was entered\n", c);
        break;
    }

  return c;

}

///////////////////////////////////////////////////////////
//<summary> Figures out what to do based on index's      //
//          value  </summary>                            //
///////////////////////////////////////////////////////////
int CutaesAdminMenu::handleSelection(int selection)
{

  switch(selection)
  {
    case 1: //Create an Application

      break;

    case 2:
      break;

    case 3: //Summary of pending applications
      pending = new PendingApps(applications);
      pending -> initPendApps();
      delete pending;

      break;

    case 4:
      break;

    case 5:
      break;

    case 6:
      nBreaker = index  + 1;
      break;

    default:
      break;
  }

  return 1;
}

////////////////////////////////////////////////////////////
//<summary> Creates the form                    </summary>//
////////////////////////////////////////////////////////////  
void CutaesAdminMenu::initAdminMenu()
{
  clear();

  char c;

  drawAdminMenu(index);

  while(1)
  {
    c = getch();
    
    handleInput(c); //Will deal with any input the user provides

    drawAdminMenu(index); //Redraw the UI based on any changes made by the user

    if(nBreaker != 0)
      break;
  }
  
  noecho();
}
