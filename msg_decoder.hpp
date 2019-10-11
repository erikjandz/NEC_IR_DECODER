#ifndef MSG_DECODER_HPP
#define MSG_DECODER_HPP

class msg_decoder : public pause_listener, public rtos::task<>{
private:
    msg_listener & listener;
    enum class states = {idle, message};
    rtos::channel<int, 10> pauses;
public:
    msg_decoder(msg_listener & listener):
        listener(listener)
        {}
        
    void main()override{
        state = states::idle;
        int n;
        int m;
        for(;;){
            switch(state){
                case idle:
                    auto p = pauses.read();
                    if(p > 4000 && p < 5000){
                        n = 0;
                        m = 0;
                        state = states::message;
                    }
                    break;
                 case message:
                    auto p = pauses.read();
                    if(p > 200 && p < 2000){
                        n++;
                        m = m << 1;
                        
                        state = states::idle;
                    }
                    break;
            }
        }
    }
};
#endif