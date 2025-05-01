// Function to convert a string of digits into an integer
int parseInt(const char *str, int size)
{
  int result = 0;
  for (int i = 0; i < size; i++)
  {
    // Multiply the current result by 10 and add the numeric value of the current character
    result = result * 10 + str[i] - '0';
  }
  return result;
}

int main()
{
  // Define a character array containing the digits '1', '2', and '3'
  char digits[] = "123";

  // Call parseInt with the digits array and its size, and return the result
  return parseInt(digits, 3);

  // Also try
  // char digits[] = "1234";

  // Explain the asnwer in echo $?
  // return parseInt(digits, 4);
}
