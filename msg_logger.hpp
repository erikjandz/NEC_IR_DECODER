#ifndef MSG_LOGGER_HPP
#define MSG_LOGGER_HPP

class msg_logger : msg_listener, public rtos::task<>{
private:
    enum class states {idle, show_message}; 
    hwlib::window & display;
public:
    void main()override{
        state = states::idle;
        int n;
        int m;
        for(;;){
            switch(state){
                case idle:
                    display.clear();
                    if(//messaage){
                        state = states::show_message;
                    }
                    break;
                case show_message:
                    messages.read( m );
                    display.write( m );
                    wait_ms( 5000 );
                    if( timer ){
                        state = states::idle;
                    }
                    break;
        }
    }
};

#endif