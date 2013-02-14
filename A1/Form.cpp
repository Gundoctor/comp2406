#include "Form.h"
using namespace std;

Form::Form(std::string s) : index(1), course(s), nBreaker(0)
{
  labels[0] = "First Name:";
  labels[1] = "Last Name:";
  labels[2] = "Student Number:";
  labels[3] = "Email:";
  labels[4] = "Major:";
  labels[5] = "Year Standing:";
  labels[6] = "CGPA:";
  labels[7] = "Major GPA:";
  labels[8] = "Cancel";
  labels[9] = "Accept";

  for(int i = 0; i < 8; i++)
    textFields[i] = "          ";
}

Form::~Form()
{
}

int Form::getIndex() const { return index; }
string Form::getCourse() const { return course; }

////////////////////////////////////////////////////////////////////////////
//<summary> Creates the GUI... draws the labels and textfields  </summary>//
////////////////////////////////////////////////////////////////////////////
void Form::drawForm(int selection)
{
  int x, lx, y, ly, i;
  char c[MAX_BUF + 1];

  x = 24;
  y = 4;
  ly = 4;

  for(i = 0; i < NUM_CHOI; i++) //Draw the labels for the text fields
  {
    for(int j = 0; j < MAX_BUF; j++)
    {
      //gLog << j
      if(j < labels[i].length())
        c[j] = labels[i][j];
      else
        c[j] = 0;
    }
    c[MAX_BUF] = 0;
    
    if(i > 7)
    {
      ly = LINES - 10;
      if(i == 8) { lx = COLS / 3; }
      else if (i == 9) { lx = 2 * COLS / 3; }
    }
    else
    {
      lx = 4;
    }

    if(selection > 8 && selection == i + 1)
    {
      if(selection == 9) { lx = COLS / 3; }
      else if(selection == 10) { lx = 2 * COLS / 3; }
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

  for(i = 0; i < NUM_CHOI - 2; i++) //Draw the textFields
  {
    //Util::stringToChar(textFields[i], &c);
    for(int j = 0; j < MAX_BUF; j++)
    {
      if(j < textFields[i].length())
        c[j] = textFields[i][j];
      else
        c[j] = 0;
    }
    c[MAX_BUF] = 0;

    if(selection == i+1)
    {
      attron(A_REVERSE);
      mvprintw(y, x, "%s\n", c);
      refresh();
      attroff(A_REVERSE);
    }
    else
    {
      mvprintw(y, x, "%s\n", c);
      refresh();
    }

    c[0] = 0;
    
    ++y;
  }

  move(LINES - 2, 0);
}
////////////////////////////////////////////////////////////////////
//<summary> Deal with any character the user might input</summary>//
////////////////////////////////////////////////////////////////////
int Form::handleInput(char c)
{

  switch(c)
    {
      case (char)KEY_UP: //FOR UP KEY
        if (getIndex() == 1)
          index = 1;
        else
          --index;
        break;

      case (char)KEY_LEFT: //FOR LEFT KEY
        if (getIndex() == 1)
          index = 1;
        else
          --index;
        break;

      case (char)KEY_RIGHT: //FOR RIGHT KEY
        if (getIndex() == NUM_CHOI)
          index = NUM_CHOI;
        else
          ++index;
        break;

      case (char)KEY_DOWN: //FOR DOWN KEY
        if(getIndex() == NUM_CHOI)
          index = NUM_CHOI;
        else
          ++index;
        break;

      case (char)KEY_F(2): //FOR F2 KEY, USER WOULD LIKE TO EXIT
        nBreaker = getIndex();
        break;

      case (char)'\r':  //If ENTER KEY IS HIT
        printw("%d is the index when Enter was pressed\n", getIndex());
        handleSelection(c);
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
int Form::handleSelection(char c)
{
  if(getIndex() < 9)
  {
    char cInput[MAX_BUF];
    
    mvprintw(LINES - 1, 0, "\n"); //Line clear
    move(LINES - 1, 0);
    echo();
    getnstr(cInput, MAX_BUF);
    noecho();

    string sInput;
    sInput.assign(cInput, MAX_BUF);
    textFields[getIndex() - 1].assign(sInput);
  }
  else
  {
    if(getIndex() == 9) { return nBreaker = getIndex(); }
    if(getIndex() == 10) {  handleAccept(); }
    printw("   Index is %d", getIndex());
  }

  return 1;
}

////////////////////////////////////////////////////////////
//<summary> Calls error checking functions to make sure   //
//          that the textFields are valid.  </summary>    //
////////////////////////////////////////////////////////////
int Form::handleAccept()
{
  /*This is where we would do all the checking, have *
   *a boolean that would go false if one of the      *
   *input checkers returned false, set the data only *
   *if the boolean remains true.*/
  //But for now...
  printw("DIS USA AWNNA ACCEPT");



  return 1;
}

////////////////////////////////////////////////////////////
//<summary> Creates the form                    </summary>//
////////////////////////////////////////////////////////////  
void Form::initForm()
{
  char ccourse[MAX_BUF];
  for(int i = 0; i < course.length(); i++)
    ccourse[i] = course[i];

  printw("Why hello there, you are registering for: %s\n", ccourse);
  refresh();

  char c;

  drawForm(getIndex());

  while(1)
  {
    c = getch();
    
    handleInput(c); //Will deal with any input the user provides
    
    drawForm(getIndex()); //Redraw the UI based on any changes made by the user

    if(nBreaker != 0)
      break;
  }
  
  noecho();
  clear();
  mvprintw(LINES - 2, 0, "Program over, press any key\n");
  refresh();
  getch();
}