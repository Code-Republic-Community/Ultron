#ifndef _GAP_BUFFER_INIT_H
#define _GAP_BUFFER_INIT_H

#include <iostream>
#include <string>
#include <fstream>

class MyGap_Buffer
{
	private: //data members
		char *buffer;
	    int gap_size;
	    int gap_left;
	    int gap_right;
	    int size;
	public:   //constructros and destructor
		MyGap_Buffer();
	    MyGap_Buffer(std::string);
	    MyGap_Buffer(const MyGap_Buffer &);
	    MyGap_Buffer(MyGap_Buffer &&);
	    ~MyGap_Buffer();
	public:   //operators
		MyGap_Buffer &operator=(const MyGap_Buffer &);
	    MyGap_Buffer &operator=(MyGap_Buffer &&);
        friend std::ostream &operator<<(std::ostream &os, const MyGap_Buffer &dt);
	public: 
		void Print_buf();    //print all buffer
	    int get_left();      
	    int get_rigth();     
	    int get_gap_size();    
	    void move_left(int);
	    void move_right(int);
	    void move_cursor_to(int);   
	    void expand(int, int);     // grow buffer at ferst argument in second argument
	    void insert_string(std::string, int);   // insert word in position
	    void insert_char(char, int); //insert sinvol in position
	    int Size();   //return size of gap buffer
	    void empty();   // clear the buffer
	    std::string get_string(int, int); // return stirng at ferst position to second position
	    char get_char(int);   //return sinvol in position
	    void erase(int, int);  // delet sinvols in positions and grow buffer
	    bool is_empty(); //return true if empty, false if not

};

#endif