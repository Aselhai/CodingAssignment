  #include <iostream>
  #include <cstdlib>
  using namespace std;

  /* 원리가 단순하므로 몇 가지에만 주석을 달도록 하겠습니다.*/
  int array_total_sum(int arr[5][5]) {
    int sum = 0;
    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 5; y++) {
      sum +=arr[x][y];
      }
    }
    return sum;
  }

  int array_find_max(int arr[5][5]) {
    int max = arr[0][0];
    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 5; y++) {
        if (arr[x][y] > max)
          max = arr[x][y];
      }
    }
    return max;
  }

  int array_find_min(int arr[5][5]) {
    int min = arr[0][0];
    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 5; y++) {
        if (arr[x][y] < min)
          min = arr[x][y];
      }
    }
    return min;
  }

  /* 새로운 배열 new_arr에 x와 y를 서로 바꾸어 대입합니다.*/
  void array_transpose(int arr[5][5]) {
    int new_arr[5][5];
    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 5; y++) {
        new_arr[y][x] = arr[x][y];
      }
    }

    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 5; y++) {
        if (y == 4)
          cout<<new_arr[x][y]<<endl;
        else
          cout<<new_arr[x][y]<<' ';
      }
    }
  }
/* 행렬 곱의 원리인 new_arr[x][z] += a1[x][y] * a2[y][z]를 이용합니다.*/
  void array_multiplication(int a1[5][5], int a2[5][5]) {
    int new_arr[5][5] = {0};
    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 5; y++) {
        for (int z = 0; z < 5; z++) {
          new_arr[x][z] += a1[x][y] * a2[y][z];
        }
      }
    }

    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 5; y++) {
        if (y == 4)
          cout<<new_arr[x][y]<<endl;
        else
          cout<<new_arr[x][y]<<' ';
      }
    }
  }

  int main(int argc, char** argv){  
      int arr1[5][5], arr2[5][5];
      /* 제출 시에는 line 9~15의 주석 처리를 해제해주세요. */
      int k = 1;
      for(int i = 0; i<5; i++)
          for(int j = 0; j<5; j++)
              arr1[i][j] = atoi(argv[k++]);
      for(int i = 0; i<5; i++)
          for(int j = 0; j<5; j++)
              arr2[i][j] = atoi(argv[k++]);
      /* 제출 시에는 line 17~19를 주석 처리해주세요. */
      // for(int i = 0; i<5; i++)
      //     for(int j = 0; j<5; j++)
      //         arr1[i][j] = i-j, arr2[i][j] = (i+j)*j;

          /*하단 수정 금지*/
        cout<< array_total_sum(arr1)<<" "<<array_total_sum(arr2)<<endl;
        cout<< array_find_max(arr1)<<" "<<array_find_max(arr2)<<endl;
        cout<< array_find_min(arr1)<<" "<<array_find_min(arr2)<<endl;
          array_transpose(arr1);
          array_transpose(arr2);
          array_multiplication(arr1, arr2);
        return 0;
  }

