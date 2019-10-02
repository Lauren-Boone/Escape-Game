
CXX = g++
CXXFLAGS = -std=c++0x
LDFLAGS = -lboost_date_time

OBJS = Main.o Game.o InputValidation.o Menu.o Space.o Player.o Kitchen.o Bedroom.o SharedRoom.o SpecialRoom.o
SRCS = Main.cpp Game.cpp Player.cpp Menu.cpp InputValidation.cpp Space.cpp Bedroom.cpp Kitchen.cpp SharedRoom.cpp SpecialRoom.cpp
Headers = Game.hpp Player.hpp Menu.hpp Space.hpp InputValidation.hpp Bedroom.hpp Kitchen.hpp SharedRoom.hpp SpecialRoom.hpp

game: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(HEADERS) -o $@

$(OBJ): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.o = .cpp)

clean:
	rm $(OBJS) game
