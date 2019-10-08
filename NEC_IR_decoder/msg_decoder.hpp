#ifndef MSG_DECODER_HPP
#define MSG_DECODER_HPP

class msg_decoder : public pause_listener{
private:
    msg_listener & listener;
public:
    msg_decoder(msg_listener & listener):
        listener(listener)
        {}
};
#endif