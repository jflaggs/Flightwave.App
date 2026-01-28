#include<flightwave.h>

int main() 
{
    MessageBus bus;

    std::thread producer([&bus]() 
    {
        for (int i = 0; i < 500; ++i) 
        {
            Message m 
            { 
                1, i, "msg " + std::to_string(i) 
            };

            bus.publish(m);

            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    });

    std::thread consumer([&bus]() 
    {
        for (int i = 0; i < 500; ++i) 
        {
            Message m = bus.get_by_topic_id(1);

            std::cout << "Got: seq=" << m.sequence_num
                << ", payload=" << m.payload << std::endl;
        }
    });

    producer.join();
    consumer.join();

    return 0;
}