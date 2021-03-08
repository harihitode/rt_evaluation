#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

class RTEvaluator
{
public:
    RTEvaluator() : max_epoch_(1000), max_count_(5000000){}
    void run()
    {
        for (unsigned int i = 0; i < max_epoch_; ++i)
        {
            volatile unsigned int num = 0;
            std::chrono::system_clock::time_point start, end;
            start = std::chrono::system_clock::now();
            for (unsigned int j = 0; j < max_count_; ++j)
            {
                num = i * j;
            }
            end = std::chrono::system_clock::now();
            std::this_thread::sleep_for(std::chrono::milliseconds(100) - (end - start));
            v_exec_time_ms_.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
            // std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
            // end = std::chrono::system_clock::now();
            // std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
        }
    }
    ~RTEvaluator(){
        for(const auto exec_time_ms: v_exec_time_ms_){
            std::cout << exec_time_ms << std::endl;
        }
    }

private:
    unsigned int max_epoch_;
    unsigned int max_count_;
    std::vector<unsigned int> v_exec_time_ms_;
};

int
main()
{
    // originally, waiting 10s here for initialization
    // for(int count_down=10; 0<=count_down; --count_down){
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    //     std::cout << count_down << std::endl;
    // }
    std::cout << "start" << std::endl;
    RTEvaluator evaluator;
    evaluator.run();
    return 0;
}
