// https://www.codewars.com/kata/57a429e253ba3381850000fb

// Write function bmi that calculates body mass index (bmi = weight / height2).

// if bmi <= 18.5 return "Underweight"

// if bmi <= 25.0 return "Normal"

// if bmi <= 30.0 return "Overweight"

// if bmi > 30 return "Obese"

std::string bmi(double w, double h) 
{
  double bmi_lmao = w / (h*h);
  if (bmi_lmao <= 18.5) return "Underweight";
  if (bmi_lmao <= 25) return "Normal";
  if (bmi_lmao <= 30) return "Overweight";
  return "Obese";
}
