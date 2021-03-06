#include "Cutaes.h"
using namespace std;

Cutaes::Cutaes() : index(1), nBreaker(0), sMenu(0), aMenu(0)
{
  labels[0] = "Student";
  labels[1] = "Admin";
  labels[2] = "Quit";
}

Cutaes::~Cutaes() { }


////////////////////////////////////////////////////////////////////////////
//<summary> Creates the GUI... draws the labels and textfields  </summary>//
////////////////////////////////////////////////////////////////////////////
void Cutaes::drawMainMenu(int selection)
{
  clear();

  
  mvprintw(5, 20, "----------------------------------------");
  mvprintw(6, 20, "--------    CUTAES Main Menu   ---------");
  mvprintw(7, 20, "----------------------------------------");

  int lx, ly, i;
  char c[31];

  ly = 10;
  lx = COLS/ 2 - 8;

  for(i = 0; i < 3; i++) //Draw the options for the Student Menu
  {
    for(int j = 0; j < 30; j++)
    {
      if(j < labels[i].length())
        c[j] = labels[i][j];
      else
        c[j] = 0;
    }
    c[31] = 0;

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
int Cutaes::handleInput(char c)
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
        if (index == 3)
          index = 3;
        else
          ++index;
        break;

      case (char)KEY_DOWN: //FOR DOWN KEY
        if(index == 3)
          index = 3;
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
int Cutaes::handleSelection(int selection)
{

  switch(selection)
  {
    case 1: //Create an Application
      studentMenu(&applications);
      break;

    case 2:
      adminMenu(&applications);
      break;

    case 3:
      nBreaker = index  + 1;
      break;

    default:
      break;
  }

  return 1;
}

//This will be at the bottom of the control flow
////////////////////////////////////////////////////////////
//<summary> Creates the form                    </summary>//
////////////////////////////////////////////////////////////  
void Cutaes::initCutaes()
{
  clear();

  char c;

  drawMainMenu(index);

  while(1)
  {
    c = getch();
    
    handleInput(c); //Will deal with any input the user provides

    drawMainMenu(index); //Redraw the UI based on any changes made by the user

    if(nBreaker != 0)
      break;
  }
  
  noecho();
}

//Write code for student menu
void Cutaes::studentMenu(ApplicationQueue **aq)
{
  sMenu = new CutaesStudentMenu(aq);
  sMenu -> initStudentMenu();
  delete sMenu;

}

//Write code for admin menu
void Cutaes::adminMenu(ApplicationQueue **aq)
{

  aMenu = new CutaesAdminMenu(aq);
  aMenu -> initAdminMenu();
  delete aMenu;

}
