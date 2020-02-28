void Puziryok(char* massiv, int size)
{
  char temp;
  for (int i = 0; i < size; i++)
  {
    for (int j = size - 1; j > i; j--)
    {
      if (massiv[j - 1] > massiv[j])
      {
        temp = massiv[j - 1];
        massiv[j - 1] = massiv[j];
        massiv[j] = temp;
      }
    }
  }
}

void Vstavka(char* massiv, int size)
{
  int i, j;
  char x;
  for (i = 1; i < size; i++)
  {
    x = massiv[i];
    for (j = i - 1; j >= 0 && massiv[j] > x; j--)
      massiv[j + 1] = massiv[j];
    massiv[j + 1] = x;
  }
}

void QuickSort(char* massiv, int size)
{
  int i = 0, j = size - 1;
  char temp;
  long p;
  p = massiv[size >> 1];
  do {
    while (massiv[i] < p)
      i++;
    while (massiv[j] > p)
      j--;
    if (i <= j)
    {
      temp = massiv[i];
      massiv[i] = massiv[j];
      massiv[j] = temp;
      i++;
      j--;
    }
  } while (i <= j);
  if (j > 0) QuickSort(massiv, j + 1);
  if (size > i) QuickSort(massiv + i, size - i);
}