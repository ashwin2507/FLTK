#include <FL/Fl_PNG_Image.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Round_Button.H>
#include <iostream>
#include <FL/Fl_Group.H>
#include <vector>
#include <FL/Fl_Widget.H>


using namespace std;

//---------------------------------------------------
 
class MainWindow : public Fl_Window{
 
   public:
      MainWindow(int w, int h, const char* title);
      ~MainWindow();

      Fl_PNG_Image* png;
      Fl_Box* box;   

      Fl_Box*dealer_deck;
      Fl_Box*dealer_value;
      Fl_Box* game_info;
      Fl_Box* table_count;	
      Fl_Box* player1;
      Fl_Box* player1_value;
      Fl_Box* player2;
      Fl_Box* player2_value;
      Fl_Box* player3;
      Fl_Box* player3_value;
      Fl_Box* player4;
      Fl_Box* player4_value;
      Fl_Box* player5;
      Fl_Box* player5_value;
      Fl_Box* player6;
      Fl_Box* player6_value;
      Fl_Box* player7;
      Fl_Box* player7_value;
      Fl_Button* start;
      Fl_Button* quit;
      Fl_Input* name;


   private:
      static void cb_start(Fl_Widget*, void*);
      inline void cb_start_i();
 
      static void cb_quit(Fl_Widget*, void*);
      inline void cb_quit_i();

};

//----------------------------------------------------

int main (){
 
   MainWindow win(1020,700,"UberCasino");
   //Dealer d;
   //Game g;
   return Fl::run();
}

//----------------------------------------------------

MainWindow::MainWindow(int w, int h, const char* title):Fl_Window(w,h,title){
   
   begin();
   
      box=new Fl_Box(0, 0, 1020,700);   
      png = new Fl_PNG_Image("background.png");      
      box->image(png);  
      box->box(FL_BORDER_BOX); 

      dealer_deck = new Fl_Box(440, 100, 137,120,"Dealer's deck");
      dealer_deck->box(FL_BORDER_BOX);
      dealer_deck->labelsize(18);

      dealer_value = new Fl_Box(600, 100, 100,50,"Dealer's vaue");	
      dealer_value->box(FL_BORDER_BOX);
      player1= new Fl_Box(20, 50, 100,180,"player1's deck"); 
      player1->box(FL_BORDER_BOX);
      player1_value = new Fl_Box(20, 250, 100,50,"total value");
      player1_value->box(FL_BORDER_BOX);
      player2= new Fl_Box(167, 150, 100,180,"player2's deck"); 
      player2->box(FL_BORDER_BOX);
      player2_value = new Fl_Box(167, 350, 100,50,"total value");
      player2_value->box(FL_BORDER_BOX);
      player3= new Fl_Box(314, 216, 100,180,"player3's deck"); 
      player3->box(FL_BORDER_BOX);
      player3_value = new Fl_Box(314, 416, 100,50,"total value"); 
      player3_value->box(FL_BORDER_BOX);
      player4= new Fl_Box(461, 280, 100,180,"player4's deck"); 
      player4->box(FL_BORDER_BOX);
      player4_value = new Fl_Box(461, 480, 100,50,"total value"); 
      player4_value->box(FL_BORDER_BOX);
      player5= new Fl_Box(608, 216, 100,180,"player5's deck"); 
      player5->box(FL_BORDER_BOX);
      player5_value = new Fl_Box(608, 416, 100,50,"total value"); 
      player5_value->box(FL_BORDER_BOX);
      player6= new Fl_Box(755, 150, 100,180,"player6's deck"); 
      player6->box(FL_BORDER_BOX);
      player6_value = new Fl_Box(755, 350, 100,50,"total value"); 
      player6_value->box(FL_BORDER_BOX);
      player7= new Fl_Box(900, 50, 100,180,"player7's deck"); 
      player7->box(FL_BORDER_BOX);
      player7_value = new Fl_Box(900, 250, 100,50,"total value"); 
      player7_value->box(FL_BORDER_BOX);
      game_info= new Fl_Box(20, 550, 350,120,"Game info"); 
      game_info->box(FL_BORDER_BOX);
      

      table_count= new Fl_Box(150, 50, 100, 50, "Table Count");
      table_count->box(FL_BORDER_BOX);	

      start = new Fl_Button(900, 550, 80, 50, "&Start");
      start->callback( cb_start, this );
    
      quit = new Fl_Button(900, 630, 80, 50, "&Quit");
      quit->callback(cb_quit, this);


   end();
   resizable(this);
   show();
}

//----------------------------------------------------

MainWindow::~MainWindow(){}


//----------------------------------------------------
void MainWindow::cb_start(Fl_Widget* o, void* v) {
 
    ( (MainWindow*)v )->cb_start_i();
}

void MainWindow::cb_start_i() {
    //dealer_name = name->value();
    //cout << endl << dealer_name << endl; // test
    hide();
}


//----------------------------------------------------

void MainWindow::cb_quit(Fl_Widget* , void* v) {

   ( (MainWindow*)v )->cb_quit_i();
}


void MainWindow::cb_quit_i() {

    hide();
}
