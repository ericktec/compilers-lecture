#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/***************************

The labs grammar
E -> T | T  + E
T -> int | int * T| ( E )



***************************/

char l;
bool E();
bool T();
bool T_1();
bool T_2();
bool T_3();
bool E_1();

void error()
{
  printf("Error\n");
  exit(-1);
}

bool match(char t)
{
  if (l == t)
  {
    l = getchar();
    // printf(" Match L = %c\n", l);
    return true;
  }
  else
    error();
}

bool T_1()
{
  // printf(" T1 L = %c\n", l);
  bool test;
  if (test = match('i') && match('n') && match('t'))
  {
    // printf(" T1 L after = %c\n", l);
    // printf("%s\n", test ? "true" : "false");
    return true;
  }
  else
  {
    return false;
  }
}

bool T_2()
{
  // printf(" T2 L = %c\n", l);
  if (match('*') && T())
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool T_3()
{
  // printf(" T3 L = %c\n", l);
  if (match('(') && E() && match(')'))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool T()
{
  // printf(" T L = %c\n", l);
  if (l == '(')
  {
    if (T_3())
    {
      return true;
    }
    else
    {
      error();
      return false;
    }
  }
  else
  {
    if (T_1())
    {
      if (l == '*')
      {
        if (T_2())
        {
          return true;
        }
        else
        {
          return false;
        }
      }
      return true;
    }
    else
    {
      return false;
    }
  }
  return false;
}

bool E_1()
{
  // printf(" E1 L = %c\n", l);
  if (T())
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool E()
{
  // printf(" E L = %c\n", l);
  if (E_1())
  {
    if (l == '+')
    {
      if (match('+') && E())
      {
        return true;
      }
      else
      {
        return false;
        error();
      }
    }
    return true;
  }
  else
  {
    error();
  }
}

int main()
{

  l = getchar();
  //E is a start symbol
  E();

  if (l == '\n'){
    printf("Parsing Successful\n");

  }else{
    error();
  }
}
