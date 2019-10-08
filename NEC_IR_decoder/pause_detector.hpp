#ifndef PAUSE_DETECTOR_HPP
#define PAUSE_DETECTOR_HPP

class pause_detector{
private:
    pause_listener & listener;
public:
    pause_detector(pause_listener & listener):
        listener(listener)
        {}
};

#endif