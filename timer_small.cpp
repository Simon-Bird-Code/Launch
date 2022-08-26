/*
Project : timer_small
Version : 1v01
Author  : Simon J Bird
Final Release Circuit : NA
*/

/* a small code developed, and condensed ino 151 chars

below shows the unpacking of the code, and some of the common functions used
ie testbed, main core and debug

the numbers 7 and 3 chosen to be close to 7 min 3 min with 3 times running of 30 min
w=r+o-w; 392+168 seconds close to 420+180 actual is 6:32+2:48=9:20 minuites
  */

/// ============= ORIGINAL CODE ================= ///
/*
#include<stdio.h>#include <time.h>#define t time(0)#define m printf("\a")
main(){int w,r,i=t,e=r=4,o=w=3;while(e){if(t==i){m;e--;w=r+o-w;i+=(r<<o)*w;}
*/


/// unpacked added libaries
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/// windows 10 update for sound
#include <windows.h>
/// uses windows platform
#define n Beep(730,300)

#include <sys/stat.h>
#include <sys/file.h>

#include <stdio.h>
#include <time.h>

/// windows 10 update for sound
#include <windows.h>
/// uses windows platform
#define n Beep(730,300)

#define t time(0)
#define m printf("\a")     /// use this , keyboard carridge beep
/// debug program flags
#define _DEBUG_FULL FALSE
#define _DEBUG_HALF TRUE

/// encasing all debug functions
#define _DEBUG TRUE

using namespace std;

long running_time=time(0);



int debug_main( int line_no , int section_no, string function_name , string var_name , int int_in )
{int ret=0;
if(_DEBUG){
         cout << "[LINE NO - " << line_no << "]";
         cout << "[SECTION NO - " << section_no << "]";
         cout << "[FUNCTION - " << function_name << "] ";
         cout << "(VAR - \'" << var_name << "\')";
         cout << " = \'" << int_in << "\'" << endl;
} return ret;}



/// over loaded functions, string version
int debug_main( int line_no , int section_no, string function_name, string var_name , string string_in )
{int ret=0;
if(_DEBUG){
         cout << "[LINE NO - " << line_no << "]";
         cout << "[SECTION NO - " << section_no << "]";
         cout << "[FUNCTION - " << function_name << "] ";
         cout << "(VAR - \'" << var_name << "\')";
         cout << " = \'" << string_in << "\'" << endl;
}return ret;}



/// a function to put small sections of code in to debug/test/write
int test_bed ( int var_in )
{
    int ret=0;
    int w,i=t,r=7,o=w=3;

    if(_DEBUG_HALF){debug_main(92,2,"test_bed() ", "(r<<o)*w",((r<<o)*w) );}

    i+=(r<<o)*w;

    if(_DEBUG_HALF){debug_main(96,2,"test_bed() ", "i",i);}

    return ret;
}



int main_program( int arg_in )
{
    int ret = 0;
    int w,r,i=t,e=r=7,o=w=3;
    while(e)
    {
        if(_DEBUG_FULL){debug_main(107,3,"main_core() ", "i",i);}

        if(t==i)
        {
            n;
            e--;
            w=r+o-w;
            i+=(r<<o)*w;

            /// names full
            /*
            long marker_for_time = i;
            int counter_for_section = e;
            int working_register_for_time_difference = w;
            int larger_of_two_numbers = r;
            int smaller_of_two_numbers = o;
            int close_to_minite = r<<o;
            int swap_sections_times = w=r+o-w;
            int section_timer = marker_for_time + close_to_minite * working_register_for_time_difference;
            section_timer = i+=(r<<o)*w;
            int ascii_code_for_beep = n;
            */

            if(e!=6){debug_main(132,3,"main_core() ", "HOOK TIME ",time(0));
            debug_main(133,1,"main_core() ", "MARKER","HIT");
            debug_main(134,3,"main_core() ", "i TARGET TIME",i);
            debug_main(135,3,"main_core() ", "w",w);
            debug_main(136,3,"main_core() ", "e",e);
            }
        }
    }
    return ret;
}

/// additional layer to add things like test bed function etc
int main_core( int in_arg )
{
    test_bed(1);
    return main_program ( 7 );
}


/// the main function to deal with command line arguments, passed right to main core
int main ( int avg , char *agc[] )    {   return main_core(1);   }




