// https://www.codewars.com/kata/57814d79a56c88e3e0000786/solutions/cpp

// Implement a pseudo-encryption algorithm which given a string S and an integer N concatenates all the odd-indexed characters of S with all the even-indexed characters of S, this process should be repeated N times.

// Examples:

// encrypt("012345", 1)  =>  "135024"
// encrypt("012345", 2)  =>  "135024"  ->  "304152"
// encrypt("012345", 3)  =>  "135024"  ->  "304152"  ->  "012345"

// encrypt("01234", 1)  =>  "13024"
// encrypt("01234", 2)  =>  "13024"  ->  "32104"
// encrypt("01234", 3)  =>  "13024"  ->  "32104"  ->  "20314"

// Together with the encryption function, you should also implement a decryption function which reverses the process.

// If the string S is an empty value or the integer N is not positive, return the first argument without changes.

std::string encrypt(std::string text, int n)
{
  std::string temp = text;
  std::string even = "";
  std::string odd = "";
  for (int i = 0; i < n; ++i) {
    for (std::string::iterator it = temp.begin(); it != temp.end(); ++it) {
      int i = it - temp.begin();
      if (i % 2 == 0) even += *it;
      else odd += *it;
    }
    temp = odd + even;
    odd = ""; even = "";
  }
  return temp;
}

std::string alternateStrings(std::string str1, std::string str2) {
  bool first = true;
  std::string merged = "";
  std::string first_str = str1;
  std::string second_str = str2;
  int end_length = str1.length() + str2.length();
  
  while (merged.length() != end_length) {
    if (first) {
      merged += first_str[0];
      first_str = first_str.substr(1, first_str.length());
      first = false;
    }
    else {
      merged += second_str[0];
      second_str = second_str.substr(1, second_str.length());
      first = true;
    }
  }
  
  return merged;
}

std::string decrypt(std::string encryptedText, int n)
{
  std::string decrypted = encryptedText;
  std::string front_odd;
  std::string back_even;
  std::string last_char = "";
  int str_len = decrypted.length();
  
  if (str_len != 0 && str_len % 2 != 0) {
    last_char = encryptedText.substr(str_len - 1, 1);
    decrypted = decrypted.substr(0, str_len - 1);
    --str_len;
  }
  
  for (int i = 0; i < n; ++i) {
    front_odd = decrypted.substr(0, str_len / 2);

    if (str_len % 2 == 0) {
      back_even = decrypted.substr(str_len / 2, str_len);
    }
    else back_even = decrypted.substr(str_len / 2 + 1, str_len - 1);
    
    decrypted = alternateStrings(back_even, front_odd);
  }
  
  return decrypted + last_char;
}