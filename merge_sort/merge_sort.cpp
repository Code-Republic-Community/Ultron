#include <iostream>
#include <vector>

template<typename T>
void merge(std::vector<T> &v, int begin, int mid, int end) {
  unsigned int size1 = mid - begin + 1;
  unsigned int size2 = end - mid;
  std::vector<T> left_vector(size1);
  std::vector<T> right_vector(size2);
  unsigned int i, j, k;
  for (i = 0; i < size1; i++) {
    left_vector[i] = v[begin + i];
  }
  for (j = 0; j < size2; j++) {
    right_vector[j] = v[mid + j + 1];
  }
  i = 0,
  j = 0;
  for (k = begin; (k <= end && i < size1 && j < size2); k++) {
    if (left_vector[i] <= right_vector[j]) {
      v[k] = left_vector[i];
      i++;
    } else {
      v[k] = right_vector[j];
      j++;
    }
  }
  for (i = i; i < size1; ++i) {
    v[k] = left_vector[i];
    k++;
  }
  for (j = j; j < size2; j++) {
    v[k] = right_vector[j];
    k++;
  }
}

template<typename T>
void merge_sort(std::vector<T> &inputed_vector, int begin = 0, int end = -1) {
  if(end == -1) {
    end = inputed_vector.size() - 1;
  }
  if (begin < end) {
    int mid = (begin + end) / 2;
    merge_sort(inputed_vector, begin, mid);
    merge_sort(inputed_vector, mid + 1, end);
    merge(inputed_vector, begin, mid, end);
  }
}

int main()
{
  std::vector<int>int_vec{1, 2421, 5125, 531, 53, 12};
  unsigned int sz = int_vec.size();
  std::cout << "Array before sort: ";
  for(auto n: int_vec) {
    std::cout << n <<" ";
  }
  std::cout << std::endl;
  std::cout << "Array after sort: ";
  merge_sort(int_vec);
  for(int n = 0; n < sz; n++) {
    std::cout << int_vec[n] << " ";
  }
}
