// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        counter++;
    }
  }
  if (counter != 0)
    return counter;
  return 0;
}
int countPairs2(int *arr, int len, int value) {
  int i = 0, j = len - 1;
  int counter = 0;
  if (arr[j] > value)
    j--;
  for (i = 0; i < len - 1; i++) {
    for (j = i + 1; j < len; j++) {
      if (arr[i] + arr [j] == value)
        counter++;
    }
  }
  if (counter != 0)
    return counter;
  return 0;
}
int countPairs3(int *arr, int len, int value) {
  int counter  = 0;
  for (int i = 0; i < len - 1; i++) {
    int begin = i, end = len;
    while (begin < end - 1) {
      int mid = (begin + end) / 2;
      if (arr[i] + arr[mid] == value) {
        counter++;
        int j = mid + 1;
        while (arr[i] + arr[j] == value && j < end) {
          counter++;
          j++;
        }
        j = mid - 1;
        while (arr[i] + arr[j] == value && j > begin) {
          counter++;
          j--;
        }
        break;
      }
      if (arr[i] + arr[mid] < value)
        begin = mid;
      if (arr[i] + arr[mid] > value)
        end = mid;
    }
  }
  if (counter != 0)
    return counter;
  return 0;
}
