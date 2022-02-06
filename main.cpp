#include <fstream>
#include <vector>
#include <iostream>
#include <random>
#include <set>
#include <algorithm>
#include <functional>
#include <chrono>
#include "zonemaps.h"
#include "zonemaps.cpp"

using namespace std;

std::vector<int> generatePointQueries(std::vector<int> data, int n)
{
  std::vector<int> queries(data.begin(), data.end());

  // add a few elements out of range
  int non_existing_counter = (data.size() * 0.1);
  std::uniform_int_distribution<int> dist{n, (int)(1.8 * n)};
  // Initialize the random_device
  std::random_device rd;
  // Seed the engine
  std::mt19937_64 generator(rd());
  std::set<int> non_existing;
  while (non_existing.size() != non_existing_counter)
  {
    non_existing.insert(dist(generator));
  }

  queries.insert(queries.end(), non_existing.begin(), non_existing.end());

  // shuffle indexes
  std::random_shuffle(queries.begin(), queries.end());

  return queries;
}

int main(int argc, char **argv)
{

  if (argc < 3)
  {
    std::cout << "Usage: ./main <input_file> <test_case>" << std::endl;
    return 0;
  }

  std::string input_file = argv[1];
  std::string test_case = argv[2];

  if (test_case != "test_pq" && test_case != "test_rq_1" && test_case != "test_rq_2" && test_case != "test_rq_3" && test_case != "test_rq_4")
  {
    std::cout << "<test_case> argument has to be one of the following: test_pq, test_rq_1, test_rq_2, test_rq_3 or test_rq_4" << std::endl;
    return 0;
  }

  // read data
  std::ifstream ifs;
  std::vector<int> data;

  ifs.open(input_file, std::ios::binary);
  ifs.seekg(0, std::ios::end);
  size_t filesize = ifs.tellg();
  ifs.seekg(0, std::ios::beg);

  data.resize(filesize / sizeof(int));
  ifs.read((char *)data.data(), filesize);

  //1. ----------------------------- initialize zonemap and build -----------------------------
  //build zonemap
  zonemap<int> zones(data, (uint)data.size() / 100);

  if (test_case == "test_pq")
  {
    //2. ----------------------------- point queries -----------------------------
    std::vector<int> queries = generatePointQueries(data, data.size());
    auto start = std::chrono::high_resolution_clock::now();

    // query from zonemaps here
    for (int query : queries) {
        bool found = zones.query(query);

        // Check if the result is correct. 
        // std::vector<int>::iterator it;
        // it = find(data.begin(), data.end(), query);
        // if (found ^ (it != data.end())) {
        //     std::cout << "Error" << std::endl;
        //     std::cout << "Key is " << query << std::endl;
        //     std::cout << "Found in query: " << found << std::endl;
        //     std::cout << "Found in data: " << (it != data.end()) << std::endl;
        // }
            
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    unsigned long long point_query_time = duration.count();
    std::cout << "Time taken to perform point queries from zonemap = " << point_query_time << " microseconds" << endl;
    /*
    Results:
        1 million integers:
            1% noise: Time taken to perform point queries from zonemap = 5257214872 microseconds
    */
  }
  else if (test_case == "test_rq_1")
  {
    //3. ----------------------------- range queries -----------------------------
    auto start = std::chrono::high_resolution_clock::now();
    // range query from zonemaps here
    int n = data.size();
    // Search between 10% and 20% of whole workload. 
    int low = n / 10;
    int high = n / 10 * 2;
    std::vector<int> result = zones.query(low, high);

    // Check if the result is correct. 
    // std::cout << "Checking" << std::endl;
    // for (int i = low; i <= high; i++) {
    //     std::vector<int>::iterator itdata = find(data.begin(), data.end(), i);
    //     std::vector<int>::iterator itres = find(result.begin(), result.end(), i);
    //     if ((itres != result.end()) ^ (itdata != data.end())) {
    //         std::cout << "Error" << std::endl;
    //         std::cout << "Key is " << i << std::endl;
    //         std::cout << "Found in query: " << (itres != result.end()) << std::endl;
    //         std::cout << "Found in data: " << (itdata != data.end()) << std::endl;
    //     }
    // }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    unsigned long long range_query_time = duration.count();
    std::cout << "Time taken to perform range query 1 from zonemap = " << range_query_time << " microseconds" << endl;
  }
  else if (test_case == "test_rq_2")
  {
    //3. ----------------------------- range queries -----------------------------
    auto start = std::chrono::high_resolution_clock::now();
    // range query from zonemaps here
    int n = data.size();
    // Search between 30% and 40% of whole workload. 
    int low = n / 10 * 3;
    int high = n / 10 * 4;
    std::vector<int> result = zones.query(low, high);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    unsigned long long range_query_time = duration.count();
    std::cout << "Time taken to perform range query 2 from zonemap = " << range_query_time << " microseconds" << endl;
  }
  else if (test_case == "test_rq_3")
  {
    //3. ----------------------------- range queries -----------------------------
    auto start = std::chrono::high_resolution_clock::now();
    // range query from zonemaps here
    int n = data.size();
    // Search between 50% and 60% of whole workload. 
    int low = n / 10 * 5;
    int high = n / 10 * 6;
    std::vector<int> result = zones.query(low, high);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    unsigned long long range_query_time = duration.count();
    std::cout << "Time taken to perform range query 3 from zonemap = " << range_query_time << " microseconds" << endl;
  }
  else if (test_case == "test_rq_4")
  {
    //3. ----------------------------- range queries -----------------------------
    auto start = std::chrono::high_resolution_clock::now();
    // range query from zonemaps here
    int n = data.size();
    // Search between 70% and 80% of whole workload. 
    int low = n / 10 * 7;
    int high = n / 10 * 8;
    std::vector<int> result = zones.query(low, high);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    unsigned long long range_query_time = duration.count();
    std::cout << "Time taken to perform range query 4 from zonemap = " << range_query_time << " microseconds" << endl;
  }
 
  return 0;
}