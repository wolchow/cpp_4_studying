cmake_minimum_required(VERSION 3.5)

<<<<<<< HEAD
project(03.homework)

#add_executable(
#	check_value
#	check_value.cpp
#)

# add_executable(
# 	random_value
# 	random_value.cpp
# )

# add_executable(
# 	high_scores
# 	high_scores.cpp
# )

# add_executable(
# 	argument
# 	argument.cpp
# )

add_executable(
	simple_game
	simple_game.cpp
=======
project(01.hello_world)

add_executable(hello_world 
    hello_world.cpp
    #example.cpp
    #example.h
    move_me_out.cpp
    move_me_out.h
)

set_target_properties(hello_world PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
>>>>>>> ab50b21e89da08e2f2d9d755711c73c289423493
)