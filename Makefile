#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source & header files in this project (main.cpp is automatically assumed)

HEADERS += msg_decoder.hpp 
HEADERS += msg_listener.hpp 
HEADERS += msg_logger.hpp
HEADERS += pause_detector.hpp
HEADERS += pause_listener.hpp 

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
