#include "Gap_Buffer.h"

MyGap_Buffer::MyGap_Buffer(): buffer{nullptr}, gap_size {}, gap_left {}, gap_right {}, size {}
{}
MyGap_Buffer::MyGap_Buffer(std::string Myword)
{
    this->gap_size = Myword.length() *2;
    this->size = Myword.length() + gap_size;
    buffer = new char[size];
    for (int i = 0; i < Myword.length(); i++)
    {
        buffer[i] = Myword[i];
    }
    for (int i = Myword.length(); i < size; i++)
    {
        buffer[i] = '-';
    }
    gap_left = size - gap_size;
    gap_right = size - 1;
}
MyGap_Buffer::MyGap_Buffer(const MyGap_Buffer &other)
{
   	//Copy constructor
    this->size = other.size;
    this->gap_size = other.gap_size;
    this->buffer = new char[other.size];
    this->gap_left = other.gap_left;
    this->gap_right = other.gap_right;
    for (int i = 0; i < other.size; i++)
    {
        this->buffer[i] = other.buffer[i];
    }
}
MyGap_Buffer::MyGap_Buffer(MyGap_Buffer && other): gap_size{other.gap_size}, gap_left{other.gap_left}, gap_right{other.gap_right}, buffer{other.buffer}
{
    other.buffer = nullptr;
    other.gap_size = 0;
    other.gap_left = 0;
    other.gap_right = 0;
}
MyGap_Buffer::~MyGap_Buffer()	//Destructor
{
    delete[] buffer;
    buffer = nullptr;
}
MyGap_Buffer &MyGap_Buffer::operator=(const MyGap_Buffer &other)
{
   	//Copy operator assignment =
    if (this == &other)
    {
        return * this;
    }
    else
    {
        this->gap_size = other.gap_size;
        this->gap_left = other.gap_left;
        this->gap_right = other.gap_right;
        this->size = other.size;
        this->buffer = new char[other.size];
        for (int i = 0; i < other.size; i++)
        {
            this->buffer[i] = other.buffer[i];
        }
        return * this;
    }
}
MyGap_Buffer &MyGap_Buffer::operator=(MyGap_Buffer && other)	//Move operator assignment = 
{
    if (this->buffer != nullptr)
    {
        delete[] buffer;
    }
    this->gap_size = other.gap_size;
    this->buffer = other.buffer;
    this->gap_left = other.gap_left;
    this->gap_right = other.gap_right;
    this->size = other.size;
    other.buffer = nullptr;
    return * this;
}
void MyGap_Buffer::Print_buf()
{
    std::cout << "the gap buffer " << "with size " << size << " and buf_size " << gap_size << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;
}
int MyGap_Buffer::get_left()
{
    return gap_left;
}
int MyGap_Buffer::get_rigth()
{
    return gap_right;
}
int MyGap_Buffer::get_gap_size()
{
    return gap_size;
}
void MyGap_Buffer::move_left(int index_to)	// Move the gap left character by character and the buffers
{
    if (index_to >= 0)
    {
        while (index_to < gap_left)
        {
            gap_left--;
            gap_right--;
            buffer[gap_right + 1] = buffer[gap_left];
            buffer[gap_left] = '-';
        }
    }
    else
    {
        std::cout << "your cursot is out of your array" << std::endl;
    }
}
void MyGap_Buffer::move_right(int index_to)	//Move the gap right character by character and the buffers
{
    if (size - gap_size >= index_to)
    {
        while ((index_to > gap_left) && (gap_right <= size))
        {
            gap_left++;
            gap_right++;
            buffer[gap_left - 1] = buffer[gap_right];
            buffer[gap_right] = '-';
        }
    }
    else
    {
        std::cout << "your cursot is out of your array" << std::endl;
    }
}
void MyGap_Buffer::move_cursor_to(int index_to)
{
    if (index_to < gap_left)
    {
        move_left(index_to);
    }
    if (index_to == gap_left)
    {
        return;
    }
    else
    {
        move_right(index_to);
    }
}
void MyGap_Buffer::expand(int num_to_exp, int index)
{
    char mid1[index];
    char mid2[size - index - 1];
    if ((index < gap_left) || (index > gap_right))
    {
        std::cout << "you can not expend new buffer in that position" << std::endl;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
           	// Copy characters of buffer to mid[] befor "index"
            mid1[i] = buffer[i];
        }
        for (int i = index; i < size; i++)
        {
           	// Copy characters of buffer to mid[] after "index"
            mid2[i - index] = buffer[i];
        }
        size += num_to_exp;
        gap_right += num_to_exp - 1;
        gap_size += num_to_exp;
        delete[] buffer;
        buffer = new char[size];
        for (int i = 0; i < index; i++)
        {
            buffer[i] = mid1[i];
        }
        for (int i = 0; i < num_to_exp; i++)
        {
           	// Insert a gap from index position gap is being represented by '-'
            buffer[i + index] = '-';
        }
        for (int i = 0; i < size; i++)
        {
            buffer[i + index + num_to_exp] = mid2[i];
        }
    }
}
void MyGap_Buffer::insert_string(std::string input, int position)
{
    if (position != gap_left)
    {
       	//move the cursor to index
        move_cursor_to(position);
    }
    for (int i = 0; i < input.length(); ++i)
    {
       	//Insert characters one by one
        if (gap_right == gap_left)
        {
           	// If the gap is empty expend the buffer
            int exp_gap = input.length() *2;
            expand(exp_gap, position);
        }
        buffer[gap_left] = input[i];	// Insert the sring in the gap and  move the gap
        gap_left++;
        position++;
    }
    gap_size = gap_right - gap_left + 1;
}
void MyGap_Buffer::insert_char(char input, int position)
{
    if (position != gap_left)
    {
       	//move the cursor to index
        move_cursor_to(position);
    }
    if (gap_right == gap_left)
    {
       	// If the gap is empty expend the buffer
        int exp_gap = gap_size;
        expand(exp_gap, position);
    }
    buffer[gap_left] = input;	// Insert the char in the gap and  move the gap
    gap_left++;
    gap_size = gap_right - gap_left + 1;
}
int MyGap_Buffer::Size()
{
    return size;
}
void MyGap_Buffer::empty()
{
    delete[] buffer;
    buffer = nullptr;
    size = 0;
}
std::string MyGap_Buffer::get_string(int first_pos, int last_pos)
{
    std::string rezult = {};
    if ((first_pos < 0) || (last_pos >= size) || (last_pos < 0) || (first_pos >= size))
    {
        return "your position out of your ARRAY";
    }
    for (int i = first_pos; i <= last_pos; ++i)
    {
        rezult += buffer[i];
    }
    return rezult;
}
char MyGap_Buffer::get_char(int position)
{
    if ((position < 0) || (position >= size))
    {
        std::cout << "your position out of your ARRAY" << std::endl;
        return '0';
    }
    return buffer[position];
}
void MyGap_Buffer::erase(int ferst_index, int last_index)
{
    int mid_index = last_index - ferst_index + 1;
    int last = 0;
    if ((last_index < 0) || (ferst_index < 0))
    {
        std::cout << "your position is  wrong, please enter anather position" << std::endl;
        return;
    }
    if (ferst_index < gap_left)
    {
        if (last_index >= gap_left)
        {
            std::cout << "your position is in your buffer, you can not erase it, please enter anather position" << std::endl;
        }
        else
        {
            move_cursor_to(ferst_index);
            for (int i = gap_right + 1; i < gap_right + mid_index + 1; i++)
            {
                buffer[i] = buffer[i - 1];
                last++;
                gap_size++;
            }
            gap_right += last;
        }
    }
    else
    {
        if (((ferst_index >= gap_left) && (ferst_index <= gap_right)) || (last_index >= size))
        {
            std::cout << "your position is in your buffer, you can not erase it, please enter anather position" << std::endl;
        }
        else
        {
            move_cursor_to(gap_left + mid_index);

            for (int i = gap_left; i > gap_left - mid_index; i--)
            {
                buffer[i - 1] = buffer[i];
                last++;
                gap_size++;
            }
            gap_left -= last;
        }
    }
}
bool MyGap_Buffer::is_empty()
{
    if (gap_size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
std::ostream &operator<<(std::ostream &os, const MyGap_Buffer &MyBuf)
{
    for (int i = 0; i < MyBuf.size; i++)
    {
        if (MyBuf.buffer[i] != '-')
        {
            os << MyBuf.buffer[i];
        }
    }
    return os;
}
