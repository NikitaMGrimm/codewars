// https://www.codewars.com/kata/57b06f90e298a7b53d000a86/train/cpp

// There is a queue for the self-checkout tills at the supermarket. Your task is write a function to calculate the total time required for all the customers to check out!
// input

//     customers: an array of positive integers representing the queue. Each integer represents a customer, and its value is the amount of time they require to check out.
//     n: a positive integer, the number of checkout tills.

// output

// The function should return an integer, the total time required.

long queueTime(std::vector<int> customers, int tills_num) {
  long time = 0;
  
  std::vector<int> tills(tills_num, 0); // initialize all tills to zero
  
  while (!customers.empty() || std::any_of(tills.begin(), tills.end(), [](int t) { return t > 0; })) {
    // find all empty tills
    std::vector<int> empty_tills_indexes;
    for (int i = 0; i < tills_num; ++i) {
      if (tills[i] == 0) {
        empty_tills_indexes.push_back(i);
      }
    }

    // fill all empty tills with waiting customers
    for (size_t i = 0; i < empty_tills_indexes.size() && !customers.empty(); ++i) {
      tills[empty_tills_indexes[i]] = customers[0];
      customers.erase(customers.begin());
    }

    // decrement time remaining for each customer in a till
    for (int i = 0; i < tills_num; ++i) {
      if (tills[i] > 0) --tills[i];
    }
    
    ++time;
  }
  
  return time;
}

// solution that I liked most from all the solutions (not mine):

long queueTime2(std::vector<int> customers,int n){
  std::vector<long> queues(n, 0);
  
  for (auto&& customer : customers)
    *std::min_element(queues.begin(), queues.end()) += customer;
    
  return *std::max_element(queues.cbegin(), queues.cend());
}
// explanation of this: we add the customers to the tills with the shortest queues (in order), then the longest till time is the time
// after which all the queues are empty. (its the longest afterall)