#include <iostream>
#include <pthread.h>
#include <random>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std::chrono;

#define TOTAL_THREADS 1000

typedef struct MyData
{
    int start, step;
    int threadNum;
} MYDATA, * PMYDATA;

int amount = 100;
std::vector<int> nums;
std::vector<int> res;
std::vector<int> hash(1001, 0);
int THREADS;
int maximum;
int total_max = 0;
MYDATA pDataArray[TOTAL_THREADS];


/*inline int GenerateRandomNumber(int from, int to){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>dist(from, to);
    return dist(gen);
}*/

inline void ReadFromFile(std::string fileName){
    std::fstream file;
    file.open(fileName);
    for(int i = 0; i < amount; i++){
        int temp;
        file >> temp;
        nums.push_back(temp);
    }
    file.close();
}

/*inline void FillFiles(std::string fileName){
    std::fstream file;
    file.open(fileName);
    for(int i = 0; i < amount; i++){
        file << GenerateRandomNumber(0, 1000) << std::endl;
    }
    
    file.close();
}*/

inline void Find(int start, int step, int all) {                                                             
    maximum = 0;
    for (int i = start; i < amount; i += step) {
        if(nums[i] > maximum){
            maximum = nums[i];
        }
        hash[nums[i]]++;
    }                                                              
    if(maximum > total_max){
        total_max = maximum;
    }                                    
}

void * Execute(void * ptr){
    PMYDATA pDataVar;
    pDataVar = (PMYDATA)ptr;
    MYDATA DataVar = *pDataVar;
 
    Find(DataVar.start,DataVar.step, DataVar.threadNum);
}

int main(){
    ReadFromFile("input.txt");
    int ThreadArray[TOTAL_THREADS];
    pthread_t thrds[TOTAL_THREADS];
    while(1){
        std::cout << "Enter amount of threads: ";
        std::cin >> THREADS;

        std::cout << "Do you want to change thread`s priority?(y/n): ";
        char ans;
        std::cin >> ans;
        int n = 0;
        std::string prior;
        if (ans == 'y') {
            std::cout << "Choose number of thread: ";
            std::cin >> n;
            while (n > THREADS || n < 0) {
                std::cout << "Choose number of thread correctly: ";
                std::cin >> n;
            }
            std::cout << "Choose the priority for this thread(low, normal, high): ";
            
            std::cin >> prior;
            while (prior != "low" && prior != "normal" && prior != "high") {
                std::cout << "Choose priority correctly(low, normal, high): ";
                std::cin >> prior;
            }
        }

        auto start = high_resolution_clock::now();

        for(int i = 0; i < THREADS; i++){
            pDataArray[i].threadNum = i;

            pDataArray[i].start = i%THREADS;
            pDataArray[i].step = THREADS;
            ThreadArray[i] = pthread_create(&thrds[i], NULL, Execute, (void *) &pDataArray[i]);
            if(i == n){
                int policy;
                if(prior == "low") policy = 6;
                else if(prior == "normal")policy = 0;
                else policy = -20;
                pthread_setschedprio(thrds[i], policy);
            }
            pthread_join(thrds[i], NULL);
        }

        auto stop = high_resolution_clock::now();                                             
        duration <float> duration = stop - start;

        std::cout << "Max value is " << total_max << " with " << hash[total_max] << " occurs" << std::endl;
        
        std::cout << "Working time: " << duration.count() << " seconds" << std::endl;

        std::cout << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << std::endl;


        hash[total_max] = 0;
        total_max = 0;

        std::cout << "Continue(y/n): ";
        std::cin >> ans;
        if (ans == 'n') break;
    }
    
    return 0;
}