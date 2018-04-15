
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Round_Button.H>
#include <iostream>
#include <FL/Fl_Group.H>



using namespace std;

//---------------------------------------------------
 
class StartWindow : public Fl_Window{
 
   public:
      StartWindow(int w, int h, const char* title,const char* uuid );
      ~StartWindow();
      Fl_Box * welcome;
      Fl_Button* start;
      Fl_Button* quit;
      Fl_Input* name;
      Fl_Output* uuid;
      Fl_Round_Button* test_deck;
      Fl_Round_Button* eight_deck;
      Fl_Round_Button* infinite_deck;

      const char* get_dealer_name();

      int get_radio();

   
   private:
      static void cb_start(Fl_Widget*, void*);
      inline void cb_start_i();
 
      static void cb_quit(Fl_Widget*, void*);
      inline void cb_quit_i();

      static void cb_radio(Fl_Widget* o, void* v); 
      inline void cb_radio_i(Fl_Widget *b, void *d); 

      const char* dealer_name;
      int radio;

};

//----------------------------------------------------

int main (){
 
   StartWindow win(300,400,"StartWindow","123123123123");
   return Fl::run();
}

//----------------------------------------------------

StartWindow::StartWindow(int w, int h, const char* title,  const char* uuid_in):Fl_Window(w,h,title){
   
   begin();
   
      welcome = new Fl_Box(80, 10, 100, 50, "Welcome to UberCasino!");
      welcome->labelsize(18);
  
      name = new Fl_Input(80, 80, 140, 30, "Name:");
      uuid = new Fl_Output(80, 130, 140, 30, "Uuid:");
      uuid->value(uuid_in); 



      Fl_Group* rb_group = new Fl_Group(15, 10, 300, 300);
      //rb_group->box(FL_UP_FRAME);   
      { Fl_Round_Button* rb1 = new Fl_Round_Button(80, 180, 70, 30, "Test");
        rb1->type(102);
        rb1->down_box(FL_ROUND_DOWN_BOX);
        rb1->callback(cb_radio,(void*)1);
      } 
      { Fl_Round_Button* rb2 = new Fl_Round_Button(80, 220, 70, 30, "8 Deck");
        rb2->type(102);
        rb2->down_box(FL_ROUND_DOWN_BOX);
        rb2->callback(cb_radio,(void*)2);
      } 
      { Fl_Round_Button* rb3 = new Fl_Round_Button(80, 260, 70, 30, "Infinite");
        rb3->type(102);
        rb3->down_box(FL_ROUND_DOWN_BOX);
        rb3->callback(cb_radio,(void*)3);
      } 
      rb_group->end();

/*
      test_deck = new Fl_Round_Button( 80, 180, 70, 30, "Test");;
      eight_deck = new Fl_Round_Button( 80, 220, 70, 30, "8 Deck") ;
      infinite_deck = new Fl_Round_Button( 80, 260, 70, 30, "Infinite");
*/
      start = new Fl_Button( 50, 350, 70, 30, "Start");
      start->callback( cb_start, this );
    
      quit = new Fl_Button(140, 350, 70, 30, "&Quit");
      quit->callback(cb_quit, this);


   end();
   resizable(this);
   show();
}

//----------------------------------------------------

StartWindow::~StartWindow(){}

//----------------------------------------------------

const char* StartWindow::get_dealer_name(){
    return dealer_name;
}


//----------------------------------------------------

int StartWindow::get_radio(){
    return radio;
}

//----------------------------------------------------
void StartWindow::cb_start(Fl_Widget* o, void* v) {
 
    ( (StartWindow*)v )->cb_start_i();
}

void StartWindow::cb_start_i() {
    dealer_name = name->value();
    cout << endl << dealer_name << endl; // test
    hide();
}

//----------------------------------------------------

void StartWindow::cb_radio(Fl_Widget* o, void* v) {
 
    ( (StartWindow*)v )->cb_radio_i(o,v);
}

void StartWindow::cb_radio_i(Fl_Widget *b, void *d) {
    

    Fl_Round_Button* rb = ((Fl_Round_Button*)b);
    if(rb->value() == 1)
    {
      cout << endl << "button pressed" << endl;
    }
}

//----------------------------------------------------

void StartWindow::cb_quit(Fl_Widget* , void* v) {

   ( (StartWindow*)v )->cb_quit_i();
}


void StartWindow::cb_quit_i() {

    hide();
}

