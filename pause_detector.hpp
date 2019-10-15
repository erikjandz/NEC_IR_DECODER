#ifndef PAUSE_DETECTOR_HPP
#define PAUSE_DETECTOR_HPP

class pause_detector : public rtos::task<>{
private:
    pause_listener & listener;
    enum class states {idle, signal};
    states state;
public:
    pause_detector(pause_listener & listener):
        listener(listener)
        {}
    
    void main()override{
        int n = 0;
        state = states::idle;
        for(;;){
            switch(state){
                case idle:
                    wait_us(100);
                    if(IR.get()){
                        listener.pause_detected(n);
                        state = states::signal;
                    }else{
                        n += 100;
                    }
                    break;
                 case signal:
                    wait_us(100);
                    if(IR.get() == 0){
                        n = 0;
                        state = states::idle;
                    }
                    break;
            }
        }
    }
};

#endif