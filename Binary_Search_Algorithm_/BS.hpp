template<typename T>
int BinarySearch(T* arr, int size, T value)
{
    int zero = 0;
    int new_size = size;
    int half = size / 2;
    while(zero < size) {
        if(arr[half] < value) {
            zero = half + 1;
        }
        if(arr[half] > value) {
            new_size = half - 1;
        }
        if(arr[half] == value) {
            return half;
        }
        half = (zero + new_size) / 2;
    }
    return - 1;
}
template<typename iter>
int size(iter begin, iter end)
{
    int a = 0;
    for(auto it = begin; it != end; ++it) {
        ++a;
    }
    if(a) {
        a /= 2;
    }
    return a;
}
template<typename iterator>
iterator add(iterator it, int value)
{
    while(value) {
        ++it;
        --value;
    }
    return it;
}
template<typename iterator, typename T>
iterator BinarySearch(iterator begin, iterator end, T value, std::forward_iterator_tag)
{
    int half = size(begin, end);
    int new_half = half;
    iterator it = begin;
    iterator return_end = end;
    it = add(it, new_half);
    new_half = half;
    while(begin != end) {
         if(*it < value) {
             begin = add(begin, new_half);
             new_half = half;
         }
         if(*it == value) {
             return it;
         }
         if(*it > value) {
             while(new_half) {
                 --end;
                 --new_half;
             }
         }
         half = size(begin, end);
         new_half = half;
         it = begin;
         it = add(it, new_half);
         new_half = half;
         if(!half && *it != value) {
             break;
         }
    }
    return --return_end;
}
template<typename iterator, typename T>
iterator BinarySearch(iterator begin, iterator end, T value, std::random_access_iterator_tag)
{
    int half = (end - begin) / 2;
    iterator return_end = end;
    iterator it = begin + half;
    while(begin != end){
    if(*it < value) {
        begin += half;
    }
    if(*it == value) {
        return it;
    }
    if(*it > value) {
        end -= half;
    }
    half = (end - begin) / 2;
    it = begin;
    it += half;
    if(!half && *it != value) {
        break;
    }
	}
    return --return_end;
}
template<typename IteratorType, typename T>
IteratorType Binary_Search(IteratorType start, IteratorType end, T value)
{
	return BinarySearch(start, end,value, typename std::iterator_traits<IteratorType>::iterator_category());
}

