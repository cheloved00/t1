#include "laba2.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
int main()
{
  setlocale(LC_ALL, "rus");
  srand(time(NULL));
  FILE* f = NULL;
  int size, tip, pechat;
  char* massiv = NULL;
  clock_t time_start, time_finish;
  printf("Сколько элементов в массиве?\n");
  scanf_s("%d", &size);
  massiv = (char*)malloc(size * sizeof(char));
  f = fopen("Laba.txt", "w");
  for (int i = 0; i < size; i++)
  {
    massiv[i] = rand() % 256;
  }
  fwrite(massiv, sizeof(char), size, f);
  fclose(f);
  printf("Напечатать полученный файл?\n1 - ДА\n2 - НЕТ\n");

  scanf_s("%d", &pechat);
  if (pechat == 1) 
  {
    for (int i = 0; i < size; i++)
    {
      printf("%c", massiv[i]);
    }
  }
  f = fopen("laba.txt", "r");
  fread(massiv, sizeof(char), size, f);
  fclose(f);
  printf("\nВыберите тип сортировки:\n1 - пузырьком;\n2 - вставками;\n3 - быстрая\n");
  scanf_s("%d", &tip);
  switch (tip) {
  case(1):
    time_start = clock();
    Puziryok(massiv, size);
    time_finish = clock();
    break;
  case(2):
    time_start = clock();
    Vstavka(massiv, size);
    time_finish = clock();
    break;
  case(3):
    time_start = clock();
    QuickSort(massiv, size);
    time_finish = clock();
    break;
  }
  for (int i = 0; i < size; i++)
  {
    printf("%c", massiv[i]);
  }
  double time = (double)(time_finish - time_start) / CLOCKS_PER_SEC;
  printf("\nВремя сортировки = %f\n", time);
  free(massiv);
  return 0;
}