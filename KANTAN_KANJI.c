#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <time.h>

#define ONETOTEN 348
#define ELEVENTOTWENTY 346
#define TWENTYONETOTHIRTY 329
#define THIRTYONETOFOURTY 348
#define FOURTYONETOFIFTY 354
#define FIFTYONETOSIXTY 349

void makeQuestion(int kanjiCount, FILE *kanjiFile, FILE *englishFile, int section);
int checkAnswer(char english[], char inputEnglish[]);
void *getKanji(FILE *kanjiFile, int scans);

int main(void) 
{
  int section = 0;
  setlocale(LC_ALL, "");

  wprintf(L"\nWelcome to Kantan Kanji's REVIEW Application\n\n");
  for (int i = 0; i < 6; i++)
  {
      wprintf(L"Type '%d' without the apostrophes to review levels %d to %d\n\n", i+1, 10*i+1, 10*(i+1));
  }

  while (scanf("%d", &section) != 1 || section < 1 || section > 6)
  {
      wprintf(L"Please type only '1', '2', '3', '4', '5', or '6'\n");
  }

  if (section == 1)
  {
    FILE *kanjiFile = fopen("Kanji1to10.txt", "r");
    FILE *englishFile = fopen("English1to10.txt", "r");
    makeQuestion(ONETOTEN, kanjiFile, englishFile, section);
  }
  else  if (section == 2)
  {
    FILE *kanjiFile = fopen("Kanji11to20.txt", "r");
    FILE *englishFile = fopen("English11to20.txt", "r");
    makeQuestion(ELEVENTOTWENTY, kanjiFile, englishFile, section);
  }
  else  if (section == 3)
  {
    FILE *kanjiFile = fopen("Kanji21to30.txt", "r");
    FILE *englishFile = fopen("English21to30.txt", "r");
    makeQuestion(TWENTYONETOTHIRTY, kanjiFile, englishFile, section);
  }
  else  if (section == 4)
  {
    FILE *kanjiFile = fopen("Kanji31to40.txt", "r");
    FILE *englishFile = fopen("English31to40.txt", "r");
    makeQuestion(THIRTYONETOFOURTY, kanjiFile, englishFile, section);
  }
  else  if (section == 5)
  {
    FILE *kanjiFile = fopen("Kanji41to50.txt", "r");
    FILE *englishFile = fopen("English41to50.txt", "r");
    makeQuestion(FOURTYONETOFIFTY, kanjiFile, englishFile, section);
  }
  else
  {
    FILE *kanjiFile = fopen("Kanji51to60.txt", "r");
    FILE *englishFile = fopen("English51to60.txt", "r");
    makeQuestion(FIFTYONETOSIXTY, kanjiFile, englishFile, section);
  }

  return 0;
}

void makeQuestion(int kanjiCount, FILE *kanjiFile, FILE *englishFile, int section) 
{
  fclose(englishFile);
  fclose(kanjiFile);
  
  setlocale(LC_ALL, "");
  int scans[kanjiCount];
  int temp;
  int randomIndex;
  wchar_t inputEnglish[20];
  wchar_t kanji[] = L"";
  wchar_t english[20];
  int ender = 0;
  time_t t;
  srand((unsigned) time(&t));
  int check = 1;
  char q[] = "q";

  for (int i = 0; i < kanjiCount; i++) 
  {
    scans[i] = i + 1;
  }
  for (int i = 0; i < kanjiCount; i++) 
  {
    randomIndex = rand() % kanjiCount;
    temp = scans[i];
    scans[i] = scans[randomIndex];
    scans[randomIndex] = temp;
  }

  for (int j = 0; j < kanjiCount; j++)
  {
    if (section == 1)
    {
      FILE *kanjiFile = fopen("Kanji1to10.txt", "r");
      wprintf(L"\nWhat is the Kanji reading of: %s\n", getKanji(kanjiFile, scans[j]));
      FILE *englishFile = fopen("English1to10.txt", "r");
      for (int i = 0; i < scans[j]; i++)
      {
        fwscanf(englishFile, L"%s", english);
      }
      fclose(englishFile);
    }
    else  if (section == 2)
    {
      FILE *kanjiFile = fopen("Kanji11to20.txt", "r");
      wprintf(L"\nWhat is the Kanji reading of: %s\n", getKanji(kanjiFile, scans[j]));
      FILE *englishFile = fopen("English11to20.txt", "r");
      for (int i = 0; i < scans[j]; i++)
      {
        fwscanf(englishFile, L"%s", english);
      }
      fclose(englishFile);
    }
    else  if (section == 3)
    {
      FILE *kanjiFile = fopen("Kanji21to30.txt", "r");
      wprintf(L"\nWhat is the Kanji reading of: %s\n", getKanji(kanjiFile, scans[j]));
      FILE *englishFile = fopen("English21to30.txt", "r");
      for (int i = 0; i < scans[j]; i++)
      {
        fwscanf(englishFile, L"%s", english);
      }
      fclose(englishFile);
    }
    else  if (section == 4)
    {
      FILE *kanjiFile = fopen("Kanji31to40.txt", "r");
      wprintf(L"\nWhat is the Kanji reading of: %s\n", getKanji(kanjiFile, scans[j]));
      FILE *englishFile = fopen("English31to40.txt", "r");
      for (int i = 0; i < scans[j]; i++)
      {
        fwscanf(englishFile, L"%s", english);
      }
      fclose(englishFile);
    }
    else  if (section == 5)
    {
      FILE *kanjiFile = fopen("Kanji41to50.txt", "r");
      wprintf(L"\nWhat is the Kanji reading of: %s\n", getKanji(kanjiFile, scans[j]));
      FILE *englishFile = fopen("English41to50.txt", "r");
      for (int i = 0; i < scans[j]; i++)
      {
        fwscanf(englishFile, L"%s", english);
      }
      fclose(englishFile);
    }
    else
    {
      FILE *kanjiFile = fopen("Kanji51to60.txt", "r");
      wprintf(L"\nWhat is the Kanji reading of: %s\n", getKanji(kanjiFile, scans[j]));
      FILE *englishFile = fopen("English51to60.txt", "r");
      for (int i = 0; i < scans[j]; i++)
      {
        fwscanf(englishFile, L"%s", english);
      }
      fclose(englishFile);
    }
    
    scanf("%s", inputEnglish);
    
    while (checkAnswer(english, inputEnglish) != 1 && check == 1)
    {
      wprintf(L"Please Try Again (or re-start program for new start): ");
      scanf("%s", inputEnglish);
    }
    wprintf(L"\nCORRECT! :)\n");
    wprintf(L"\nIf you want to continue type '1'. If not type '0': \n");
    scanf("%d", &ender);

    if (ender == 0)
    {
      break;
    }
  }
}

int checkAnswer(char english[], char inputEnglish[])
{
  int size = 0;
  int check = 0;
  double numCorrectOrder = 0;
  double numCorrect = 0;
  while (english[size] != '\0')
  {
    size++;
  }

  for (int i = 0; i<size; i++)
  {
    if (inputEnglish[i] == english[i])
    {
      numCorrectOrder = numCorrectOrder + 1.0;
    }
    for (int j = 0; j<size; j++)
    {
      if (inputEnglish[j] == english[i])
      {
        numCorrect = numCorrect + 1.0;
      }
    }
  }

  if (numCorrectOrder/size >= 0.60 && numCorrect/size >=0.60)
  {
    check = 1;
  }
  return check;
}

void* getKanji(FILE *kanjiFile, int scans)
{
  wchar_t kanji[] = L"";
  for (int k = 0; k < scans; k++)
  {
    fwscanf(kanjiFile, L"%s", kanji, 2);
  }
  wchar_t *pkanji = kanji;
  
  fclose(kanjiFile);
  return pkanji;
}